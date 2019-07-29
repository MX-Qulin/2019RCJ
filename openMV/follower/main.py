# AprilTags Example
#
# This example shows the power of the OpenMV Cam to detect April Tags
# on the OpenMV Cam M7. The M4 versions cannot detect April Tags.

#库导入
import sensor, image, time, math
import json
from pyb import Servo
from pyb import UART
uart = UART(3, 9600) #串口输出设置
#相机初始化
s1 = Servo(1) # P7 Servo
s2 = Servo(2) # P8 Servo
ss1=90
ss2=90
sensor.reset()
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_framesize(sensor.HQVGA) # we run out of memory if the resolution is much bigger...
sensor.skip_frames(30)
sensor.set_auto_gain(True)  # must turn this off to prevent image washout...
sensor.set_auto_whitebal(False)  # must turn this off to prevent image washout...
clock = time.clock()
#相机分辨率矫正
f_x = (2.8 / 3.984) * 160 # 默认值
f_y = (2.8 / 2.952) * 120 # 默认值
c_x = 240 * 0.5 # 默认值(image.w * 0.5)
c_y = 160 * 0.5 # 默认值(image.h * 0.5)
def degrees(radians):
    return (180 * radians) / math.pi
while(True): #主循环
    clock.tick()
    img = sensor.snapshot() #获取图像
    #img.binary([(250, 255)], invert=False) #二值化
    #寻找AprilTag
    for tag in img.find_apriltags(fx=f_x, fy=f_y, cx=c_x, cy=c_y):
        img.draw_rectangle(tag.rect(), color = (255, 0, 0))
        img.draw_cross(tag.cx(), tag.cy(), color = (0, 255, 0))
        print_args = (tag.x_translation(), tag.y_translation(), tag.z_translation(), \
            degrees(tag.x_rotation()), degrees(tag.y_rotation()), degrees(tag.z_rotation()))
        #usb串口输出
        print("Tx: %f, Ty %f, Tz %f, Rx %f, Ry %f, Rz %f" % print_args)
        #USART3输出
        x=tag.x_translation()
        y=tag.y_translation()
        z=tag.z_translation()
        if(x>0) s1.angle(ss1+1)
        if(x<0) s1.angle(ss1-1)
        if(y>0) s2.angle(ss2+1)
        if(y<=) s2.angle(ss2-1)
        output_str="[%d,%d,%d]" % (tag.x_translation(), tag.y_translation(), tag.z_translation())
        print('you send:',output_str)
        uart.write(output_str+'\n')
    print(clock.fps())
