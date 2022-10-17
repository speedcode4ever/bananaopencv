from picamera.array import PiRGBArray
from picamera import PiCamera
import time
import cv2
import serial
    
if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.reset_input_buffer()    
        
banana_cascade= cv2.CascadeClassifier('leafcascadev4.xml')

width,height=320,240
camera = PiCamera()
camera.resolution = (width,height)
camera.framerate = 30
rawCapture = PiRGBArray(camera, size=(width,height))
time.sleep(1)

for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
    image = frame.array
    frame=cv2.flip(image,1)
    gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)    
    
    #detect face coordinates x,y,w,h
    bananas=banana_cascade.detectMultiScale(gray,1.3,5)
    c=0
     
    if len(bananas) == 0:
        print("found nothing")
        ser.write(b"found nothing\n") 
    
    for(x,y,w,h) in bananas:
        c+=1
        if(c>1):
            break  
        #centre of face
        face_centre_x=x+w/2
        face_centre_y=y+h/2
        #pixels to move 
        error_x=160-face_centre_x
        error_y=120-face_centre_y
        
        if (error_x < 20 and error_x > -20) and (error_y < 6 and error_y > -6):
                print("On target")
                ser.write(b"On target\n")
        
        elif error_y < 6 and error_y > -6:
                print("Stop y")
                ser.write(b"Stop y\n")
                
        elif error_x < 20 and error_x > -20:
                print("Stop x")
                ser.write(b"Stop x\n")
        
        if error_x >= 20:
                print("move right")
                ser.write(b"move right\n")
        
        if error_x <= -20:
                print("move left")
                ser.write(b"move left\n")
        
        if error_y >= 6:
                print("move up")
                ser.write(b"move up\n")
        
        if error_y <= -6:
                print("move down")
                ser.write(b"move down\n")
                
        if(c==1):
            frame=cv2.rectangle(frame,(x,y),(x+w,y+h),(255,0,0),2)  
    
    cv2.imshow('frame',frame) #display image
    
    key = cv2.waitKey(1) & 0xFF
    rawCapture.truncate(0)
    if key == ord("q"):
        break

cv2.destroyAllWindows()