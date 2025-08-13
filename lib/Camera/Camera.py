# packet = [254, yellow_x, yellow_y, blue_x, blue_y, orange_x, orange_y]


import sensor, image, time
import pyb
import math

ROBOT_A = True
YELLOW = 1
BLUE = 2
ORANGE = 0
FRAME_WIDTH = 240
FRAME_HEIGHT = 240
draw = True #set this to false in game -> this draws the circles around the blobs

# Individual
if ROBOT_A:
    thresholds = [(48, 76, -18, 5, 14, 63),(65, 80, -24, 0, -60, -18),(0, 0, 0, 0, 0, 0)] # Yellow, Blue, Orange
else:
    thresholds = [(62, 100, -21, 5, 35, 127),(50, 68, -10, 11, -128, -43),(0, 0, 0, 0, 0, 0)] # Yellow, Blue, Orange

# Superteam
#if ROBOT_A:
    #thresholds = [((39, 57, 5, 40, 8, 57),), ((17, 26, -2, 41, -59, -14),)] # Yellow  is first
#else:
    #thresholds = [((38, 61, 4, 43, 7, 64),), ((16, 21, -1, 23, -35, -16),)] # Yellow  is first

sensor.reset()
LED1 = pyb.LED(2)
LED1.on()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False)
sensor.set_auto_whitebal(True)
sensor.set_brightness(2)
sensor.set_contrast(0)
sensor.set_saturation(1)
sensor.set_windowing((FRAME_WIDTH, FRAME_HEIGHT))
clock = time.clock()
uart = pyb.UART(3, 115200, timeout_char = 10)
LED1.off()

while(True):
    data = [120, 120, 120, 120, 120, 120] #
    clock.tick()
    img = sensor.snapshot()
    blobs = img.find_blobs(thresholds, x_stride=2, y_stride = 2, area_threshold = 0, pixel_threshold = 200, merge = False, margin = 23)
    blobs = sorted(blobs, key=lambda blob: -blob.area())
    yellow = None
    blue = None
    orange = None
    for blob in blobs:
        if math.sqrt((blob.cx()-120)**2 + (blob.cy()-120)**2) < 116:
            if data[0] == 120 and data[1] == 120 and blob.code() == YELLOW:
                data[0] = FRAME_WIDTH - blob.cx()
                data[1] = FRAME_HEIGHT - blob.cy()
            if data[2] == 120 and data[3] == 120 and blob.code() == BLUE:
                data[2] = FRAME_WIDTH - blob.cx()
                data[3] = FRAME_HEIGHT - blob.cy()
            if data[4] == 120 and data[5] == 120 and blob.code() == ORANGE:
                data[4] = FRAME_WIDTH - blob.cx()
                data[5 ] = FRAME_HEIGHT - blob.cy()
    uart.writechar(254)
    print(data[0], data[1])
    for byte in data:
        uart.writechar(byte)
        if draw:
            img.draw_circle(120, 120, 116)
            img.draw_line(int(round(FRAME_WIDTH)/2 - 10), int(round(FRAME_HEIGHT / 2)), int(round(FRAME_WIDTH / 2) + 10), int(round(FRAME_HEIGHT / 2)))
            img.draw_line(int(round(FRAME_WIDTH)/2), int(round(FRAME_HEIGHT / 2) + 10), int(round(FRAME_WIDTH / 2)), int(round(FRAME_HEIGHT / 2) -10))
            img.draw_line(int(round(FRAME_WIDTH)/2), int(round(FRAME_HEIGHT / 2) + 10), int(round(FRAME_WIDTH / 2)), int(round(FRAME_HEIGHT / 2) -10))
            img.draw_line(round(FRAME_WIDTH / 2), round(FRAME_HEIGHT / 2), 240 - data[2], 240 - data[3])
            img.draw_line(round(FRAME_WIDTH / 2), round(FRAME_HEIGHT / 2), 240 - data[0], 240 - data[1])
            # Can add another for the ball
            # Can add another for the furthest point
