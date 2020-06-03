import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)


GPIO.setup(11, GPIO.OUT)
GPIO.setup(13, GPIO.IN)
GPIO.output(11, False)

while True:
    time.sleep(1)
    GPIO.output(11, GPIO.HIGH)
    time.sleep(0.00015)
    GPIO.output(11, GPIO.LOW)
    t1 = time.time()
    while GPIO.input(13) == False:
        pass
    while GPIO.input(13) == True:
        pass
    t2 = time.time()
    t3 = t2 - t1
    print(str(t3*34000/2) + "cm")
    