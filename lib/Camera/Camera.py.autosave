# packet = [254, orange_x, orange_y]


import sensor, time, math, machine


# INITIALISATION
YELLOW = 1
BLUE = 1
ORANGE = 2 # goes up in powers of 2
FRAME_WIDTH = 240
FRAME_HEIGHT = 240

ATTACK_BLUE = True # change after each half ******

if ATTACK_BLUE:
    thresholds = [((20, 50, -21, -2, -18, -1)), (8, 42, 2, 50, 2, 50)] #Blue, Orange (comp: (46, 82, 24, 57, 8, 127))
else:
    thresholds = [((20, 50, -21, -2, -18, -1)), (46, 82, 24, 57, 8, 127)] #Yellow, Orange


#CALIBRATE THIS
draw = False # SET TO FALSE DURING A GAME
thresholds = [((20, 50, -21, -2, -18, -1)), (46, 82, 24, 57, 8, 127)] # Attack, ORANGE

sensor.reset()
LED1 = machine.LED("LED_BLUE")#turn on green LED
LED1.on()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False)
sensor.set_auto_whitebal(False)
#sensor.set_auto_exposure(False, exposure_us = )
sensor.set_windowing((FRAME_WIDTH, FRAME_HEIGHT))
clock = time.clock()
uart = machine.UART(1, 115200, timeout_char = 200)
LED1.off() # turn off green LED



# LOOP
while(True):
    uart.write("3")
    time.sleep(1)
    # data = [254, 254, 120, 120, 120, 120]
    # img = sensor.snapshot()
    # blobs = img.find_blobs(thresholds, merge=True)
    # yellow = None
    # blue = None
    # orange = None
    # # blob = max(blobs, key=lambda b: b.pixels())
    # blobs = sorted(blobs, key=lambda blob: -blob.area())
    # for blob in blobs:
    #     if ATTACK_BLUE:
    #         if data[2] == 120 and blob.code() == BLUE:
    #             data[2] = (blob.cx()) # distance_x
    #             data[3] = (blob.cy()) #distance_y
    #         if data[4] == 120 and blob.code() == ORANGE:
    #             data[4] = (blob.cx()) # distance_x
    #             data[5] = (blob.cy()) #distance_y
    #     else:
    #         if data[2] == 120 and data[2] == 120 and blob.code() == YELLOW:
    #             data[2] = (blob.cx()) # distance_x
    #             data[3] = (blob.cy()) #distance_y
    #         if data[4] == 120 and data[5] == 120 and blob.code() == ORANGE:
    #             data[4] = (blob.cx()) # distance_x
    #             data[5] = (blob.cy()) #distance_y
    #     uart.write(bytes(data))
    #     print(data)
    # if draw:
    #     img.draw_circle(120, 120, 116)
    #     img.draw_line(int(round(FRAME_WIDTH)/2 - 10), int(round(FRAME_HEIGHT / 2)), int(round(FRAME_WIDTH / 2) + 10), int(round(FRAME_HEIGHT / 2)))
    #     img.draw_line(int(round(FRAME_WIDTH)/2), int(round(FRAME_HEIGHT / 2) + 10), int(round(FRAME_WIDTH / 2)), int(round(FRAME_HEIGHT / 2) -10))
    #     img.draw_line(int(round(FRAME_WIDTH)/2), int(round(FRAME_HEIGHT / 2) + 10), int(round(FRAME_WIDTH / 2)), int(round(FRAME_HEIGHT / 2) -10))
    #     img.draw_line(120, 120,int(round(data[2])),int(round(data[3])))
    #     img.draw_line(120, 120,int(round(data[4])),int(round(data[5])))


