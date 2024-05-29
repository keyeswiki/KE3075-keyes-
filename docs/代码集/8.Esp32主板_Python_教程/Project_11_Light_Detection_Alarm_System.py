# 导入 Pin，ADC 和 time 库.
from machine import ADC, Pin
import time

# 定义光敏传感器，led和有源蜂鸣器的引脚. 
sensor_photosensor = ADC(Pin(36))
sensor_photosensor.atten(ADC.ATTN_11DB)
sensor_photosensor.width(ADC.WIDTH_12BIT)
led = Pin(2, Pin.OUT)
buzzer = Pin(0, Pin.OUT)  
 
while True: 
      adcvalue = sensor_photosensor.read()
      if adcvalue > 3000:
          print(adcvalue, "Buzzer sounds and led blinking!")
          buzzer.value(1)
          led.value(1)
          time.sleep(0.5)
          buzzer.value(0) 
          led.value(0)
          time.sleep(0.5)         
      else:
          print(adcvalue, "Buzzer won't sound and led off!")
          buzzer.value(0)
          led.value(0)
          time.sleep(0.5)