import sensor, image, time

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time=2000)
sensor.set_auto_gain(False)
sensor.set_auto_whitebal(False)

while True:
    img = sensor.snapshot()
    px = img.get_pixel(120, 120)  # center pixel
    print("Center RGB:", px)
