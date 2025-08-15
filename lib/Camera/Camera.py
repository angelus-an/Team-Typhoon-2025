# packet = [254, orange_x, orange_y]


import sensor, time, math, machine


# INITIALISATION
#YELLOW = 1
#BLUE = 2
#ORANGE = 0
FRAME_WIDTH = 240
FRAME_HEIGHT = 240

#CALIBRATE THIS
draw = True # SET TO FALSE DURING A GAME
thresholds = [(44, 72, 32, 127, 37, 127)] # ORANGE

sensor.reset()
LED1 = machine.LED("LED_GREEN")#turn on green LED
LED1.on()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False)
sensor.set_auto_whitebal(False)
#sensor.set_auto_exposure(False, exposure_us = )
sensor.set_windowing((FRAME_WIDTH, FRAME_HEIGHT))
clock = time.clock()
uart = machine.UART(0, 115200, timeout_char = 10)
LED1.off() # turn off green LED



# LOOP
while(True):
    data = [120, 120]
    img = sensor.snapshot()
    blobs = img.find_blobs(thresholds, merge=True)
    if blobs:
        blob = max(blobs, key=lambda b: b.pixels())
        data[0] = -(blob.cy() - FRAME_HEIGHT/2) # distance_x
        data[1] = (blob.cx() - FRAME_WIDTH/2) #distance_y
        uart.write(bytes([254, int(data[1]), int(data[0])]))  # optional offset for 0-255
    else:
        print("No orange values")_
    if draw:
        img.draw_circle(120, 120, 116)
        img.draw_line(int(round(FRAME_WIDTH)/2 - 10), int(round(FRAME_HEIGHT / 2)), int(round(FRAME_WIDTH / 2) + 10), int(round(FRAME_HEIGHT / 2)))
        img.draw_line(int(round(FRAME_WIDTH)/2), int(round(FRAME_HEIGHT / 2) + 10), int(round(FRAME_WIDTH / 2)), int(round(FRAME_HEIGHT / 2) -10))
        img.draw_line(int(round(FRAME_WIDTH)/2), int(round(FRAME_HEIGHT / 2) + 10), int(round(FRAME_WIDTH / 2)), int(round(FRAME_HEIGHT / 2) -10))
        img.draw_line(120, 120, 240 - int(round(data[0])), 240 - int(round(data[1])))


