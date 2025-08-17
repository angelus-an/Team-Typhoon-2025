# Untitled - By: jaemi - Sun Aug 17 2025

import sensor
import time
import machine

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time=2000)

clock = time.clock()

while True:
    LED1 = machine.LED("LED_BLUE")#turn on green LED
    LED1.on()
    time.sleep(1)
    LED1.off()
    time.sleep(1)
