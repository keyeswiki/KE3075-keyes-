# Esp32主板_C_教程

## 1. Esp32主板：

![图片不存在](./media/074ca02db99706884ece5ca5c9adece4.png)

---

1. 简介:

在我们开始学习keyes 光线检测套件之前，首先介绍keyes ESP32 主控板，它是所有项目的核心。

keyes ESP32 主控板是基于ESP-WROOM-32模块所设计的的迷你开发板。该开发板引出大部分I/O至两侧的2.54mm间距的排针，开发者可以根据自己的需求连接外设。使用开发板进行开发和调试时，两侧的标准排针可以让你的操作更加简洁方便。

ESP-WROOM-32模块是业内集成度领先的 WiFi + 蓝牙解决方案，外部元器件少于 10 个，它集成了天线开关、射频 balun、功率放大器、低噪放大器、过滤器和电源管理模块。同时，它也集成了天采用 TSMC 低功耗 40nm 技术，功耗性能和射频性能，安全可靠，易于扩展至各种应用。

---

2. 规格参数:

微控制器: ESP-WROOM-32模块

USB转串口芯片: CP2102-GMR

工作电压:	DC 5V

工作电流：80mA（平均）

供电电流：500mA（最小）

工作温度范围: -40°C ~ +85°C 

WiFi模式：Station/SoftAP/SoftAP+Station/P2P

WiFi协议：802.11 b/g/n/e/i（802.11n，速度高达 150 Mbps

WiFi频率范围：2.4 GHz ~ 2.5 GHz

蓝牙协议：符合蓝牙 v4.2 BR/EDR 和 BLE 标准

尺寸：55x26x13mm

重量：9.8g

---

3. 各个接口和主要元件说明:

![图片不存在](./media/ec36a4b63483949c59cd8a3a30ee0cdd.png)

![图片不存在](./media/57bce4ccdc02d4abfaa94c4cf702796d.png)

---

4. 各个接口详细说明:

- IO23: VSPI MOSI/SPI MOSI
- IO22: Wire SCL
- TXD0: IO1/Serial TX
- RXD0: IO3/Serial RX
- IO21: Wire SDA
- IO19: VSPI MISO/SPI MISO
- IO18: VSPI SCK/SPI SCK
- IO5: VSPI SS/SPI SS
- IO4: ADC10/TOUCH0
- IO0: ADC11/TOUCH1
- IO2: ADC12/TOUCH2
- IO15: HSPI SS/ADC13/TOUCH3/TDO
- SD1: IO8/FLASH D1
- SD0: IO7/FLASH D0
- CLK: IO6/FLASH SCK
- CMD: IO11/FLASH CMD
- SD3: IO10/FLASH D3
- SD2: IO9/FLASH D2
- IO13: HSPI MOSI/ADC14/TOUCH4/TCK
- IO12: HSPI MISO/ADC15/TOUCH5/TDI
- IO14: HSPI SCK/ADC16/TOUCH6/TMS
- IO27: ADC17/TOUCH7
- IO26: ADC19/DAC2
- IO25: ADC18/DAC1
- IO33: ADC5/TOUCH8
- IO32: ADC4/TOUCH9
- IO35: ADC7
- IO34: ADC6
- SENSOR VN: IO39/ADC3
- SENSOR VP: IO36/ADC0
- EN 按钮: 复位键

---

## 2. Arduino IDE 的下载、安装和使用方法

参考链接：[http://wikikeyes-arduino.readthedocs.io/](http://wikikeyes-arduino.readthedocs.io/)

<span style="color: rgb(255, 76, 65);">注意：</span><span style="background:#ff0;color:#000">Esp32主板_C_教程里所有课程使用的Arduino IDE版本：2.1.1 。</span>

---

## 3. 课程

---

项目01 Hello World

1. 项目介绍：

对于ESP32的初学者，先从一些简单的开始学习吧！在这个项目中，你只需要一个ESP32主板，MicroUSB线和计算机就可以完成“Hello World!”项目。它不仅是ESP32主板和计算机的通信测试，也是ESP32的初级项目。这也是一个入门实验，让你进入计算机的编程世界。

2. 项目元件：

| ![图片不存在](./media/074ca02db99706884ece5ca5c9adece4.png)| ![图片不存在](./media/a6ff46e05db89a18ffe62f2f6c66c701.png) |
| :--: | :--: |
|ESP32主板*1 | MicroUSB线*1 |

3. 项目接线：

![图片不存在](./media/46cf3a8a1c79e456ac0f02da5ef38aec.png)

4. 项目代码：

将使用一个简单的If()语句编程控制结构。Arduino IDE使用串行监视器来显示打印语句、传感器数据等信息。这是一个非常强大的工具，用于调试长代码。现在是你的第一个代码：

```C
//*************************************************************************************
/*
 * 名称   : Hello World
 * 功能   : 输入字母R，串口显示“Hello World”。
 * 作者   : http://www.keyes-robot.com/
*/
char val;//定义变量val.

void setup(){
Serial.begin(115200);// 设置波特率为115200. 
}

void loop(){
  if (Serial.available() > 0) {
    val=Serial.read();// 读取指令或字符从PC到Arduino，并赋值给val.
    if(val=='R') {  // 确定接收的指令或字符是否为“R”.    
     Serial.println("Hello World!");// 显示“Hello World !”字符串.
    }
  }
}
//*************************************************************************************
```

5. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)上传代码。上传成功后，利用MicroUSB线连接到计算机上电，单击![图片不存在](./media/fc48ba39f09aa4c8ca72174a6d8765e3.png)图标进入串行监视器，设置波特率为 **115200** ，在文本框输入字母“R”，按下回车键(Enter 键)，这样串口监视器打印“Hello World!”。

![图片不存在](./media/4c12e0dc9a7b4f2ff0b08b3411178eb1.png)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![图片不存在](./media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![图片不存在](./media/930e7f2e5285e7c53fd1c8f993ab8b32.png)

![图片不存在](./media/0fdadbed575d5f54ae1ca9405c3647cb.png)

6. 代码说明

| 代码                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| char val            | 定义一个变量val                                              |
| Serial.begin(115200)  | 设置串口波特率为115200                                             |
| Serial.available( ) | 获取串口上可读取的数据的字节数，该数据已经到达并存储在接收缓存（共有64字节）中。Serial.available() > 0表示串口接收到了数据，可以读取。 |
| Serial.read( )      | 读取写入的串行数据。                                         |
| if( ){ }            | 如果“（ ）”里的条件满足，则执行“{ }”里的程序。               |
| Serial.println( )   | 换行输出数据。从串行端口输出数据，跟随一个回车和一个换行符。 |

---

项目02 点亮LED

1. 项目介绍：

在这个项目中，我们将向你展示点亮LED。我们是使用ESP32主板的数字引脚来打开LED，使LED被点亮。

2. 项目元件：

|![图片不存在](./media/074ca02db99706884ece5ca5c9adece4.png)|![图片不存在](./media/3eb806e0acb028c1b242da3b85c44e58.png)|![图片不存在](./media/28c28e6163de71f861c1f8f9bf621ee2.png)|
| :--: | :--: | :--: |
|ESP32主板*1|面包板*1|红色LED*1|
|![图片不存在](./media/11f324f82f890b0691f134e1ea7a3765.png)| ![图片不存在](./media/8d920d12138bd3b4e62f02cecc2c63a3.png)|![图片不存在](./media/a6ff46e05db89a18ffe62f2f6c66c701.png)|
|220Ω电阻*1|面包板连接线*2|MicroUSB线*1|

3. 元件知识：

**（1）LED**

![图片不存在](./media/28c28e6163de71f861c1f8f9bf621ee2.png)

LED是一种被称为“发光二极管”的半导体，是一种由半导体材料(硅、硒、锗等)制成的电子器件。它有正极和负极。短腿为负极，接GND，长腿为正极，接3.3V或5V。

![图片不存在](./media/cbb16ef4d8cb62a4001d1a05ae3ac615.png)

**（2）五色环电阻**

电阻是电路中限制或调节电流流动的电子元件。左边是电阻器的外观，右边是电阻在电路中表示的符号。电阻(R)的单位为欧姆(Ω)，1 mΩ= 1000 kΩ，1kΩ= 1000Ω。

![图片不存在](./media/11d4977d31c6f63993b5f3ac97b4cfb7.png)

我们可以使用电阻来保护敏感组件，如LED。电阻的强度（以Ω为单位）用小色环标记在电阻器的主体上。每种颜色代表一个数字，你可以用电阻对照卡查找。

![图片不存在](./media/e60472f717ced1cc0bd94f4972ef0cd0.png)

在这个套件中，我们提供了2个具有不同电阻值的五色环电阻。这里以2个五色环电阻为例：

220Ω电阻×10

![图片不存在](./media/951ce7d7778b34bf8fbdb3de1b8c3116.png)

1KΩ电阻×10

![图片不存在](./media/931d1535563f6d817300f97c0946a01c.png)

在相同的电压下，会有更小的电流和更大的电阻。电流、电压、电阻之间的联系可以用公式表示：I=U/R。在下图中，目前通过R1的电流: I = U / R = 3 V / 10 KΩ= 0.0003A= 0.3mA。

![图片不存在](./media/8556c6c4feade95fb231c98da873b43c.png)

不要把电阻值很低的电阻直接连接在电源两极，这样会使电流过高而损坏电子元件。电阻是没有正负极之分。

**（3）面包板**

面包板是实验室中用于搭接电路的重要工具。面包板上有许多孔，可以插入集成电路和电阻等电路元件。熟练掌握面包板的使用方法是提高实验效率，减少实验故障出现几率的重要基础之一。下面就面包板的结构和使用方法做简单介绍。一个典型的面包板如下所示：

![图片不存在](./media/2cfd6bc0dc00ad7d5958cd17d3356cba.png)

面包板的外观和内部结构如上图所示，常见的最小单元面包板分上、中、下三部分，上面和下面部分一般是由一行或两行的插孔构成的窄条，中间部分是由中间一条隔离凹槽和上下各5 行的插孔构成的条。

![图片不存在](./media/2cfd6bc0dc00ad7d5958cd17d3356cba.png)

在面包板的两个窄条分别有两行插孔，两行之间是不连通的，一般是作为电源引入的通路。上方第一行标有“+”的一行有10组插孔（内部都是连通），均为正极；上方第二行标有“-”的一行有10组插孔，（内部都是连通），均为接地。面包板下方的第一行与第二行结构同上。如需用到整个面包板，通常将“+”与“+”用导线连接起来，“-”与“-”用导线连接起来。

中间部分宽条是由中间一条隔离凹槽和上下各5 行的插孔构成。在同一列中的5 个插孔是互相连通的，列和列之间以及凹槽上下部分则是不连通的。外观及结构如下图：

![图片不存在](./media/3f03942b842afb3b2c7407c8f712d6cd.png)

中间部分宽条的连接孔分为上下两部分，是面包板的主工作区，用来插接原件和面包板连接线。在同一列中的5个插孔（即a-b-c-d-e，f-g-h-i-j）是互相连通的；列和列之间以及凹槽上下部分是不连通的。在做实验的时候，通常是使用两窄一宽组成的小单元，在宽条部分搭接电路的主体部分，上面的窄条取一行做电源，下面的窄条取一行做接地。中间宽条用于连接电路，由于凹槽上下是不连通的，所以集成块一般跨插在凹槽上。

**(4)电源**

ESP32主板需要3.3V-5V电源，在本项目中，我们通过用MicroUSB线将ESP32主板和电脑连起来。

![图片不存在](./media/46cf3a8a1c79e456ac0f02da5ef38aec.png)

4. 项目接线图：

![图片不存在](./media/e54c1dc69e5953a8dcf475a1eac70fc2.png)

5. 项目代码：

```C
//*************************************************************************************
/*
 * 名称   : Turn_On_LED
 * 功能   : 点亮 LED
 * 作者   : http://www.keyes-robot.com/
*/
#define PIN_LED 15  // 定义LED的引脚为GPIO15.

void setup() {
  pinMode(PIN_LED, OUTPUT);  // 设置led引脚为输出模式.
}

void loop() {
  digitalWrite(PIN_LED, HIGH); //  点亮LED.
}
//*************************************************************************************
```

6. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：LED被点亮。

![图片不存在](./media/96672306fbbac2d8b33a55315d0d8fc5.png)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![图片不存在](./media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![图片不存在](./media/930e7f2e5285e7c53fd1c8f993ab8b32.png)

![图片不存在](./media/0fdadbed575d5f54ae1ca9405c3647cb.png)

7. 代码说明:

| 代码                       | 说明                                                       |
| -------------------------- | ---------------------------------------------------------- |
| pinMode(PIN_LED, OUTPUT)    | 设置引脚的模式。OUTPUT为输出模式；INPUT为输入模式          |
| digitalWrite(PIN_LED, HIGH) | 设置引脚的输出电压为高\低电平。HIGH为高电平，LOW为低电平。 |

---


项目03 LED闪烁

1. 项目介绍：

在这个项目中，我们将向你展示LED闪烁效果。我们是使用ESP32主板的数字引脚来打开LED，让它闪烁。

2. 项目元件：

|![图片不存在](./media/074ca02db99706884ece5ca5c9adece4.png)|![图片不存在](./media/3eb806e0acb028c1b242da3b85c44e58.png)|![图片不存在](./media/28c28e6163de71f861c1f8f9bf621ee2.png)|
| :--: | :--: | :--: |
|ESP32主板*1|面包板*1|红色LED*1|
|![图片不存在](./media/11f324f82f890b0691f134e1ea7a3765.png)| ![图片不存在](./media/8d920d12138bd3b4e62f02cecc2c63a3.png)|![图片不存在](./media/a6ff46e05db89a18ffe62f2f6c66c701.png)|
|220Ω电阻*1|面包板连接线*2|MicroUSB线*1|

3. 项目接线图：

![图片不存在](./media/e54c1dc69e5953a8dcf475a1eac70fc2.png)

4. 项目代码：

```C
//*************************************************************************************
/*
 * 名称   : LED_Blinking
 * 功能   : LED 闪烁1秒
 * 作者   : http://www.keyes-robot.com/
*/
#define PIN_LED 15  // 定义LED的引脚为GPIO15.

void setup(){
  pinMode(PIN_LED, OUTPUT);// 设置led引脚为输出模式.
}

void loop(){
  digitalWrite(PIN_LED, HIGH); // 点亮LED.
  delay(1000); // 等待1秒.
  digitalWrite(PIN_LED, LOW); // 熄灭LED.
  delay(1000); // 等待1秒
}
//*************************************************************************************
```

5. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：可以看到电路中的LED会反复闪烁。

![图片不存在](./media/bbd161f32b47a175d78773391bd7b0c1.png)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![图片不存在](./media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![图片不存在](./media/930e7f2e5285e7c53fd1c8f993ab8b32.png)

![图片不存在](./media/0fdadbed575d5f54ae1ca9405c3647cb.png)

6. 代码说明:

| 代码                       | 说明                                                       |
| -------------------------- | ---------------------------------------------------------- |
| pinMode(PIN_LED, OUTPUT)    | 设置引脚的模式。OUTPUT为输出模式；INPUT为输入模式          |
| digitalWrite(PIN_LED, HIGH) | 设置引脚的输出电压为高\低电平。HIGH为高电平，LOW为低电平。 |
| delay(1000)                | 将程序的执行暂停一段时间,也就是延时。单位是毫秒。          | 

---

项目04 交通灯

1. 项目介绍：

交通灯在我们的日常生活中很普遍。根据一定的时间规律，交通灯是由红、黄、绿三种颜色组成的。每个人都应该遵守交通规则，这可以避免许多交通事故。在这个项目中，我们将使用ESP32主板和一些led(红，黄，绿)来模拟交通灯。

2. 项目元件：

|![图片不存在](./media/074ca02db99706884ece5ca5c9adece4.png)|![图片不存在](./media/3eb806e0acb028c1b242da3b85c44e58.png)|![图片不存在](./media/28c28e6163de71f861c1f8f9bf621ee2.png)|![图片不存在](./media/538628fed136c06e104ae01b69774d34.png)|
| :--: | :--: | :--: |:--: |
|ESP32主板*1|面包板*1|红色LED*1|黄色LED*1|
|![图片不存在](./media/cede9aadb081f8efbe1aa2884452296f.png)|![图片不存在](./media/11f324f82f890b0691f134e1ea7a3765.png)| ![图片不存在](./media/8d920d12138bd3b4e62f02cecc2c63a3.png)|![图片不存在](./media/a6ff46e05db89a18ffe62f2f6c66c701.png)|
|绿色LED*1|220Ω电阻*3|面包板连接线若干|MicroUSB线*1|

3. 项目接线图： 

![图片不存在](./media/1036d040ed516c3e54d1b78a54426318.png)

4. 项目代码：

```C
//*********************************************************************************
/*
 * 名称   : Traffic_Lights
 * 功能   : 模拟交通灯
 * 作者   : http://www.keyes-robot.com/ 
*/
#define PIN_LED_RED   0   //定义红色LED的引脚为GPIO0
#define PIN_LED_YELLOW   2   //定义黄色LED的引脚为GPIO2
#define PIN_LED_GREEN  15   //定义绿色LED的引脚为GPIO15

void setup() {
  pinMode(PIN_LED_RED, OUTPUT);  // 将红色LED引脚设置为输出模式
  pinMode(PIN_LED_YELLOW, OUTPUT);  // 将黄色LED引脚设置为输出模式
  pinMode(PIN_LED_GREEN, OUTPUT);  // 将绿色LED的引脚设置为输出模式
}

void loop(){
  digitalWrite(PIN_LED_GREEN, HIGH); // 点亮绿色LED
  delay(5000); // 延时5秒
  digitalWrite(PIN_LED_GREEN, LOW); // 熄灭绿色LED
  for(int i=0;i<3;i++){// 闪烁3次
    digitalWrite(PIN_LED_YELLOW, HIGH); //点亮黄色LED
    delay(500); // 延时0.5秒
    digitalWrite(PIN_LED_YELLOW, LOW); // 熄灭黄色LED
    delay(500); // 延时0.5秒
  } 
  digitalWrite(PIN_LED_RED, HIGH); // 点亮红色LED
  delay(5000); // 延时5秒
  digitalWrite(PIN_LED_RED, LOW); // 熄灭红色LED
}
//*********************************************************************************
```

5. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：1.首先，绿灯会亮5秒，然后熄灭；2.其次，黄灯会闪烁3次，然后熄灭；3.然后，红灯会亮5秒，然后熄灭；4.继续运行上述1-3个步骤。

![图片不存在](./media/3aa2d0e1d22c0da572e75937a4c01a8f.jpg)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![图片不存在](./media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![图片不存在](./media/930e7f2e5285e7c53fd1c8f993ab8b32.png)

![图片不存在](./media/0fdadbed575d5f54ae1ca9405c3647cb.png)

6. 代码说明:

可以参照项目03和项目05的代码说明，这里就不多做介绍了。

---

项目05 呼吸灯

1. 项目介绍：

在之前的研究中，我们知道LED有亮/灭状态，那么如何进入中间状态呢?如何输出一个中间状态让LED“半亮”?这就是我们将要学习的。呼吸灯，即LED由灭到亮，再由亮到灭，就像“呼吸”一样。那么，如何控制LED的亮度呢? 我们将使用ESP32主板的PWM来实现这个目标。

2. 项目元件：

|![图片不存在](./media/074ca02db99706884ece5ca5c9adece4.png)|![图片不存在](./media/3eb806e0acb028c1b242da3b85c44e58.png)|![图片不存在](./media/28c28e6163de71f861c1f8f9bf621ee2.png)|
| :--: | :--: | :--: |
|ESP32主板*1|面包板*1|红色LED*1|
|![图片不存在](./media/11f324f82f890b0691f134e1ea7a3765.png)| ![图片不存在](./media/8d920d12138bd3b4e62f02cecc2c63a3.png)|![图片不存在](./media/a6ff46e05db89a18ffe62f2f6c66c701.png)|
|220Ω电阻*1|面包板连接线*2|MicroUSB线*1|

3. 元件知识：

![图片不存在](./media/e739a6e4a95fa8bbbefb26ef955dc465.png)

**模拟信号 & 数字信号** 

模拟信号在时间和数值上都是连续的信号。相反，数字信号或离散时间信号是由一系列数字组成的时间序列。生活中的大多数信号都是模拟信号，一个熟悉的模拟信号的例子是：全天的温度是连续不断变化的，而不是突然从0到10的瞬间变化。然而，数字信号的值可以瞬间改变。这个变化用数字表示为1和0(二进制代码的基础)。如下图所示，我们可以更容易地看出它们的差异。

![图片不存在](./media/550c1d587189ce5ac3678f44b08ac888.png)

在实际应用中，我们经常使用二进制作为数字信号，即一系列的0和1。由于二进制信号只有两个值(0或1)，因此具有很大的稳定性和可靠性。最后，可以将模拟信号和数字信号相互转换。

**PWM：**

脉宽调制(PWM)是一种利用数字信号控制模拟电路的有效方法。普通处理器不能直接输出模拟信号。PWM技术使这种转换(将数字信号转换为模拟信号)非常方便。PWM技术利用数字引脚发送一定频率的方波，即高电平和低电平的输出，交替持续一段时间。每一组高电平和低电平的总时间一般是固定的，称为周期(注:周期的倒数是频率)。高电平输出的时间通常称为脉宽，占空比是脉宽(PW)与波形总周期(T)之比的百分比。高电平输出持续时间越长，占空比越长，模拟信号中相应的电压也就越高。下图显示了对应于脉冲宽度0%-100%的模拟信号电压在0V-3.3V(高电平为3.3V)之间的变化情况.

![图片不存在](./media/0c29da4ca7a2fee2f5a0078eacc9e88a.png)

PWM占空比越长，输出功率越高。既然我们了解了这种关系，我们就可以用PWM来控制LED的亮度或直流电机的速度等等。从上面可以看出，PWM并不是真实的模拟信号，电压的有效值等于相应的模拟信号。因此，我们可以控制LED和其他输出模块的输出功率，以达到不同的效果。

4. 项目接线图： 

![图片不存在](./media/e54c1dc69e5953a8dcf475a1eac70fc2.png)

5. 项目代码：

```C
//**********************************************************************************
/*
 * 名称   : Breathing_LED
 * 功能   : 使用PWM让led灯像呼吸一样忽明忽暗。
 * 作者   : http://www.keyes-robot.com/
*/
#define PIN_LED   15   //定义LED的引脚为GPIO15
#define CHN       0   //定义PWM通道
#define FRQ       1000  //定义PWM频率
#define PWM_BIT   8     //定义PWM精确度
void setup() {
  ledcSetup(CHN, FRQ, PWM_BIT); //初始化PWM通道
  ledcAttachPin(PIN_LED, CHN);  //将led引脚连接到pwm通道
}

void loop() {
  for (int i = 0; i < 255; i++) { //使光线逐渐变亮
    ledcWrite(CHN, i);
    delay(10);
  }
  for (int i = 255; i > -1; i--) {  //使光线逐渐变暗
    ledcWrite(CHN, i);
    delay(10);
  }
}      
//**********************************************************************************
```

6. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：电路中的LED从暗逐渐变亮，再从亮逐渐变暗，就像呼吸一样。

![图片不存在](./media/7a0d2717b48056cbef36f880212d8e07.png)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![图片不存在](./media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![图片不存在](./media/930e7f2e5285e7c53fd1c8f993ab8b32.png)

![图片不存在](./media/0fdadbed575d5f54ae1ca9405c3647cb.png)

7. 代码说明:

| 代码                       | 说明                    |
| -------------------------- | ------------------------------------------------------------ |
|for (int i = 0; i < 255; i++)|i的取值范围就是0～255， 超过255后又会回到0。所以当你的i从0逐渐增加到255后，再执行i++，i的值不是256，而是回到了0，这仍然符合i<=255的要求，所以循环继续。当你改成i<=254时，i循环到254后，再执行i++是255，让i<=254的条件为假，从而结束循环。|
| ledcSetup(CHN,FRQ, WM_BIT) | ledcSetup这个函数是用来设置pwm通道的。用法是ledcSetup（通道号，频率，计数位数）。通道号，取值0 ~ 15。计数位数，取值0 ~ 20（该值决定ledcWrite函数中占空比的最大值，如该值写10，则占空比最大可写2^10-1=1023。 |
| ledcWrite(CHN, i)          | ledcWrite这个函数用来指定通道输出一定占空比的波形。用法是：ledcWrite(通道, 占空比)。 |

---

项目06 流水灯

1. 项目介绍：

在日常生活中，我们可以看到许多由不同颜色的led组成的广告牌。他们不断地改变灯光(像流水一样)来吸引顾客的注意。在这个项目中，我们将使用ESP32主板控制3个LED灯实现流水的效果。

2. 项目元件：

|![图片不存在](./media/074ca02db99706884ece5ca5c9adece4.png)|![图片不存在](./media/3eb806e0acb028c1b242da3b85c44e58.png)|![图片不存在](./media/28c28e6163de71f861c1f8f9bf621ee2.png)|
| :--: | :--: | :--: |
|ESP32主板*1|面包板*1|红色LED*3|
|![图片不存在](./media/11f324f82f890b0691f134e1ea7a3765.png)| ![图片不存在](./media/8d920d12138bd3b4e62f02cecc2c63a3.png)|![图片不存在](./media/a6ff46e05db89a18ffe62f2f6c66c701.png)|
|220Ω电阻*3|面包板连接线若干|MicroUSB线*1|

3. 项目接线图:

![图片不存在](./media/6e7343f94c261236ac361a44b96bcc1c.png)

4. 项目代码：

```C
//**********************************************************************************
/*
 * 名称   : Flowing_Water_Light
 * 功能   : 流水灯
 * 作者   : http://www.keyes-robot.com/ 
*/
byte ledPins[] = {0, 2, 15}; // LED的I/O引脚
int ledCounts; // LED 数量

void setup(){
   ledCounts = sizeof(ledPins);
   for (int i = 0; i < ledCounts; i++) {
     pinMode(ledPins[i], OUTPUT);   // 设置I/O引脚为输出模式
   }
}
void loop(){
   for (int i = 0; i < ledCounts; i++) {
     digitalWrite(ledPins[i], HIGH); // 设置I/O引脚为高，依次点亮led灯
     delay(100); // 延时0.1秒
     digitalWrite(ledPins[i], LOW);  // 设置I/O引脚为低，依次熄灭led灯
   }
   for (int i = ledCounts - 1; i > -1; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
   }  
}
//**********************************************************************************
```

5. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：电路中的3个LED会逐渐亮起来，然后逐渐熄灭，就像电池充电一样。

![图片不存在](./media/455a58658cda6b1a22e8b6799976fbce.jpg)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![图片不存在](./media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![图片不存在](./media/930e7f2e5285e7c53fd1c8f993ab8b32.png)

![图片不存在](./media/0fdadbed575d5f54ae1ca9405c3647cb.png)

6. 代码说明:

可以参照项目03和项目05的代码说明，这里就不多做介绍了。

---

项目07 有源蜂鸣器

1. 项目介绍：

有源蜂鸣器模块上有一个发声元件----有源蜂鸣器。它被广泛用作电脑、打印机、报警器、电子玩具、电话、计时器等的发声元件。它有一个内在的振动源，需连接3.3V~5V电源，即可持续发出嗡嗡声。在这个项目中，我们将使用ESP32主板控制有源蜂鸣器发出“滴滴”声。

2. 项目元件：

|![图片不存在](./media/074ca02db99706884ece5ca5c9adece4.png)|![图片不存在](./media/3eb806e0acb028c1b242da3b85c44e58.png)|![图片不存在](./media/08cac8e036b616593db2d11a13d7922d.png)|![图片不存在](./media/dda94299cc2abaff2c9cb8ff7ce365ff.jpg)|![图片不存在](./media/a6ff46e05db89a18ffe62f2f6c66c701.png)|
| :--: | :--: | :--: | :--: | :--: |
|ESP32主板*1|面包板*1|有源蜂鸣器模块*1|公对母杜邦线若干|MicroUSB线*1|

3. 元件知识：

<span style="color: rgb(255, 76, 65);">注意：本教程使用的是有源蜂鸣器。</span>

![图片不存在](./media/08cac8e036b616593db2d11a13d7922d.png)

有源蜂鸣器和无源蜂鸣器的“源”不是指电源，而是指震荡源。

**有源蜂鸣器**：内部自带震荡源，所以一触发就能发声，发声频率固定。有源蜂鸣器的优点是程序控制方便，声压高。有源自激型蜂鸣器工作发声原理如下：直流电源输入经过振荡系统的放大和取样电路在谐振装置作用下产生声音信号。

**模块参数：**

工作电压: DC 3.3 ~ 5V 

工作温度：-10°C ~ +50°C

控制信号：数字信号

尺寸：32 mm x 23.8 mm x 12.3 mm

定位孔大小：直径为 4.8 mm

**无源蜂鸣器**: 内部不带震荡源，如果直接通直流电信号无源蜂鸣器是没有声音的，因为磁路恒定，振动膜片一直处在吸附状态，不能振动发音。根据不同需求，一般我们通过方波去驱动，然后通过更换方波的频率来实现不同音效。

**总结：有源蜂鸣器内部带震荡源，发声频率固定。无源内部不带震荡源，通过方波去驱动，发音频率可改变。**


4. 项目接线图：

![图片不存在](./media/0e715c3cc23550b1d6983cdd2dc53724.png)

5. 项目代码：

```C
//**********************************************************************************
/*
 * 名称   : Active buzzer
 * 功能   : 有源蜂鸣器产生声音
 * 作者   : http://www.keyes-robot.com/
*/
#define buzzerPin  15   //定义蜂鸣器的引脚为GPIO15

void setup () {
  pinMode (buzzerPin, OUTPUT);  //设置蜂鸣器引脚为输出模式
}

void loop () {
  digitalWrite (buzzerPin, HIGH); //发声
  delay (500); //延时0.5秒
  digitalWrite (buzzerPin, LOW);  //停止发声
  delay (500); //延时0.5秒
}
//**********************************************************************************
```

6. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：有源蜂鸣器发出“滴滴”声。

![图片不存在](./media/b1cc7406ca2ebadab478d040964306ae.jpg)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![图片不存在](./media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![图片不存在](./media/930e7f2e5285e7c53fd1c8f993ab8b32.png)

![图片不存在](./media/0fdadbed575d5f54ae1ca9405c3647cb.png)

7. 代码说明:

可以参照项目03的代码说明，这里就不多做介绍了。

---

项目08 继电器控制LED

1. 项目介绍：

在日常生活中，我们一般使用交流来驱动电气设备，有时我们会用开关来控制电器。如果将开关直接连接到交流电路上，一旦发生漏电，人就有危险。从安全的角度考虑，我们特别设计了这款具有NO(常开)端和NC(常闭)端的继电器模块。在这节课我们将学习一个比较特殊、好用的开关，就是继电器模块，使用继电器模块控制LED灯亮灭。

2. 项目元件：

|![图片不存在](./media/074ca02db99706884ece5ca5c9adece4.png)|![图片不存在](./media/3eb806e0acb028c1b242da3b85c44e58.png)|![图片不存在](./media/1677c94f2390adeb3df19bfabd6ced88.png)|![图片不存在](./media/28c28e6163de71f861c1f8f9bf621ee2.png)|![图片不存在](./media/5a0d069fdb6c0f5901be9f9e2bd07e7d.png)|
| :--: | :--: | :--: |:--: |:--: |
|ESP32主板*1|面包板*1|继电器模块*1|红色LED*1|一字螺丝刀*1|
|![图片不存在](./media/dda94299cc2abaff2c9cb8ff7ce365ff.jpg)|![图片不存在](./media/a6ff46e05db89a18ffe62f2f6c66c701.png)|![图片不存在](./media/11f324f82f890b0691f134e1ea7a3765.png)| ![图片不存在](./media/8d920d12138bd3b4e62f02cecc2c63a3.png)| |
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干| |

3. 元件知识：

![图片不存在](./media/1677c94f2390adeb3df19bfabd6ced88.png)

**继电器：** 继电器能兼容多种单片机控制板，是用小电流去控制大电流运作的一种“自动开关”。它可以让单片机控制板驱动3A以下负载，如LED灯带、直流马达、微型水泵、电磁阀可插拔式接口设计，方便使用。继电器有3个接线柱用于外接电路，分别为NO、COM和NC端（背后丝印）。

![图片不存在](./media/66a8a3f7f871c513156c68de0153722a.png)

**模块参数:**

工作电压: DC 5V 

工作电流: 50 mA

最大功率: 0.25 W

控制信号: 数字信号

触电电流: 小于 3 A

工作温度：-10°C ~ +50°C

尺寸：47.6mm x 23.8mm x 19mm

定位孔大小：直径为4.8mm

**模块原理图:**

![图片不存在](./media/70636a25eed32cf351f7855180697f6e.png)

一个继电器拥有一个动触点以及两个静触点A和B。

当开关K断开时，继电器线路无电流通过，此时动触点与静触点B相接触，上半部分的电路导通。静触点B被称为常闭触点（NC）。常闭——NC（normal close）通常情况下是关合状态，即线圈未得电的情况下闭合的。

当开关K闭合时，继电器电路通过电流产生磁力，此时动触点与静触点A相接触，下半部分电路导通。静触点A被称为常开触点（NO）。常开——NO（normal open）通常情况下是断开状态，即线圈未得电的情况下断开的。

而动触点也被称为公共触点（COM）。

继电器简单来说就是一个开关，VCC表示电源正极、GND表示电源负极、IN表示信号输入脚，COM表示公共端，NC（normal close）表示常闭端，NO(normal open)表示常开端。

![图片不存在](./media/cf1d69e712f4408b762672579c12d57c.png)

4. 项目接线图：

<br>
<span style="color: rgb(61, 167, 66);"> **特别注意：** 接线前，需要用一字螺丝刀将继电器模块的NO端口和COM端口处的螺丝扭松，将面包板连接线的一端插入NO端口和COM端口处；接好线后，再用一字螺丝刀将NO端口和COM端口处的螺丝扭紧。</span>
<br>

![图片不存在](./media/ef6e165440f65f4d6522a88cc6f954df.png)

5. 项目代码：

```C
//**********************************************************************************
/*
 * 名称   : Relay_Control_LED
 * 功能   : 继电器控制LED亮与灭
 * 作者   : http://www.keyes-robot.com/ 
*/
#define  Relay 15  //定义继电器的引脚为GPIO15

void setup() {
  pinMode(Relay, OUTPUT); //设置继电器的引脚为输出模式
}

void loop() {
  digitalWrite(Relay, HIGH); //打开继电器
  delay(1000); //延时1秒
  digitalWrite(Relay, LOW); //关闭继电器
  delay(1000); //延时1秒
}
//**********************************************************************************
```
6. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：继电器将循环开与关，开启1秒LED点亮1秒，关闭1秒LED熄灭1秒。同时可以听到继电器开与关的声音，还可以看到继电器上的指示灯指示状态的变化。

![图片不存在](./media/60e6d8bdb7d3bc5a5d7e1b28979dc283.jpg)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![图片不存在](./media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![图片不存在](./media/930e7f2e5285e7c53fd1c8f993ab8b32.png)

![图片不存在](./media/0fdadbed575d5f54ae1ca9405c3647cb.png)

7. 代码说明:

可以参照项目03的代码说明，这里就不多做介绍了。

---

项目09 光敏传感器

1. 项目介绍：

光敏传感器模块有个信号输出端，可以输出光照强度的模拟信号。在本项目中，我们将读取传感器的ADC值，DAC值和电压值，并将测试结果在串口监视器上打印显示出来。

2. 项目元件：

|![图片不存在](./media/074ca02db99706884ece5ca5c9adece4.png)|![图片不存在](./media/3eb806e0acb028c1b242da3b85c44e58.png)|![图片不存在](./media/64f4a9e4d9b86ff8b0ef8b66afabffe0.png)|![图片不存在](./media/dda94299cc2abaff2c9cb8ff7ce365ff.jpg)|![图片不存在](./media/a6ff46e05db89a18ffe62f2f6c66c701.png)|
| :--: | :--: | :--: |:--: |:--: |
|ESP32主板*1|面包板*1|光敏传感器模块*1|公对母杜邦线若干|MicroUSB线*1|

3. 元件知识：

![图片不存在](./media/64f4a9e4d9b86ff8b0ef8b66afabffe0.png)

**光敏传感器:** 是一个常用的光敏电阻传感器，它主要由一个光敏电阻元件组成。光敏电阻元件的阻值随着光照强度的变化而变化，此传感器就是利用光敏电阻元件这一特性，设计电路将阻值变化转换为电压变化。光敏电阻传感器可以模拟人对环境光线的强度的判断，方便做出与人友好互动的应用。

**模块参数:**

工作电压: DC 3.3 ~ 5V 

工作电流: 0.2MA

最大功率: 0.001W

光谱峰值: 540nm

亮电阻: 5~10千欧

暗电阻: 0.5兆欧

工作温度：-10°C ~ +50°C

输出信号: 模拟信号

尺寸：32 mm x 23.8 mm x 7.4 mm

定位孔大小：直径为 4.8 mm

**模块原理图:**

![图片不存在](media/0a804f6b1ccb475325301d7c9c94f38d.png)

当没有光照射时，电阻大小为0.2 MΩ，光敏电阻的信号端（2脚）检测的电压接近0。随着光照强度增大，光敏传感器的电阻值越来越小，所以信号端能检测到的电压越来越大，模拟值也越来越大。

4. 项目接线图：

![图片不存在](./media/1faa34640b5910e372b2e4b44467e74c.png)

5. 项目代码：

```C
//**********************************************************************************
/*
 * 名称   : Photosensor
 * 功能   : 将光敏电阻的阻值转换成ADC,DAC和电压值
 * 作者   : http://www.keyes-robot.com/  
*/
#define PIN_ANALOG_IN 36   //光敏传感器的模拟引脚定义为GPIO36

void setup() {
  Serial.begin(115200);   //波特率设置为115200
  pinMode(PIN_ANALOG_IN, INPUT);    //将传感器的引脚设置为输入模式
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);    //使用analogRead()函数获取ADC值
  int dacVal = map(adcVal, 0, 4095, 0, 255);   //使用map()函数将ADC值转换为DAC值
  double voltage = adcVal / 4095.0 * 3.3;  //输出电压
  Serial.print("ADC Val: "); //打印字符串ADC Val:
  Serial.print(adcVal); //打印ADC值, DAC值和电压值
  Serial.print("  DAC Val: ");  //打印字符串DAC Val:
  Serial.print(dacVal);  //打印DAC值
  Serial.print("  Voltage: ");  //打印字符串Voltage:
  Serial.print(voltage);  //打印电压值
  Serial.println(" V");  //打印字符串V
  delay(200); 
}
//**********************************************************************************
```

6. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，点击![图片不存在](./media/fc48ba39f09aa4c8ca72174a6d8765e3.png)打开串口监视器，设置波特率为**115200**，串口监视器打印出光敏传感器读取的ADC值、DAC值和电压值。光照越强，可以看到ADC值，DAC值和电压值越大。

![图片不存在](./media/77825cae15f327160af32e27d8c004d9.jpg)

![图片不存在](./media/f14eccce84a6bdc5a1c9154dadf18265.png)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![图片不存在](./media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![图片不存在](./media/930e7f2e5285e7c53fd1c8f993ab8b32.png)

![图片不存在](./media/0fdadbed575d5f54ae1ca9405c3647cb.png)

7. 代码说明:

| 代码                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| pinMode(PIN_ANALOG_IN, INPUT); | 由“ int PIN_ANALOG_IN = 36; ”知道，定义光敏传感器模块的模拟管脚为GPIO36，“INPUT”设置为输入模式。 |
| analogRead(PIN_ANALOG_IN)                 | 为了兼容性，默认analogRead()分辨率为 10 位。详细了解请参考链接：https://vimsky.com/examples/usage/arduino-language-functions-analog-io-analogread-ar.html 。这个函数是从指定的模拟引脚PIN_ANALOG_IN读取光敏传感器的模拟信号。ESP32板包含一个多通道、12位模数转换器。 这意味着它会将 0 和工作电压（5V 或 3.3V，我们这里是3.3V）之间的输入电压映射为0和4095之间的整数值。这会产生以下分辨率：3.3V/4096单位即每单位 0.0008V。 |
| int dacVal = map(adcVal, 0, 4095, 0, 255) | 将adcVal读到的值从 0 ~ 4095 映射到 0 ~ 255，也就是转换为占空比对应的值。 |
| double voltage = adcVal / 4095.0 * 3.3    | 以double（双精度）浮点型输出电压值。                         |
| Serial.begin(115200)     | 初始化串口通信，并设置波特率为115200。                         |
| Serial.print( )   | 未换行输出数据。从串行端口输出数据，跟随一个回车和一个未换行符。 |
| Serial.println( )   | 换行输出数据。从串行端口输出数据，跟随一个回车和一个换行符。 |

---

项目10 光敏传感器控制LED

1. 项目介绍：

上一项目中我们已经学习了光敏传感器的工作原理，这一项目中我们将光敏传感器和LED灯组合实验，实现光敏传感器检测到光照强度模拟值大于一定值时LED快速闪烁的效果。

2. 项目元件：

|![图片不存在](./media/074ca02db99706884ece5ca5c9adece4.png)|![图片不存在](./media/3eb806e0acb028c1b242da3b85c44e58.png)|![图片不存在](./media/64f4a9e4d9b86ff8b0ef8b66afabffe0.png)|![图片不存在](./media/28c28e6163de71f861c1f8f9bf621ee2.png)|
| :--: | :--: | :--: |:--: |
|ESP32主板*1|面包板*1|光敏传感器模块*1|红色LED*1|
|![图片不存在](./media/dda94299cc2abaff2c9cb8ff7ce365ff.jpg)|![图片不存在](./media/a6ff46e05db89a18ffe62f2f6c66c701.png)|![图片不存在](./media/11f324f82f890b0691f134e1ea7a3765.png)| ![图片不存在](./media/8d920d12138bd3b4e62f02cecc2c63a3.png)|
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干|

3. 项目接线图：

![图片不存在](./media/03d1e8e8f235867b1ee8d18631512fe9.png)

4. 项目代码：

<span style="color: rgb(255, 76, 65);">注意：</span>代码中的阈值3000可以根据环境中实际的光照强度更改。

```C
//**********************************************************************************
/*  
 * 名称   : Photosensor_Control_LED
 * 功能   : 光敏传感器控制LED
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;
void setup() {
  Serial.begin(115200); //设置串口波特率为115200
  pinMode(36, INPUT);    //将光敏传感器连接到GPIO36上，并设置为输入模式
  pinMode(2, OUTPUT);  //将LED连接到GPIO2上，并设置为输出模式
}

void loop() {
  item = analogRead(36);   //光敏传感器读取光照强度，将读取到模拟值赋予变量Item
  Serial.println(item);  //串口打印光敏传感器输出的模拟信号
  if (item > 3000) {  //模拟值大于3000
    digitalWrite(2, HIGH);  //打开LED
    delay(500);  //延迟 500ms
    digitalWrite(2, LOW);  //关闭LED
    delay(500);  //延迟 500ms
  } else {  //否则，模拟值不大于3000
    digitalWrite(2, LOW);  //关闭LED
  }
}
//**********************************************************************************
```

5. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：你会看到的现象是：使用手机的照明灯对着光敏传感器模块上的光敏电阻照射，当光敏传感器检测到光照强度的模拟值大于3000时，外接LED灯快速闪烁。

![图片不存在](./media/7aa39affb5fa1f243b9494c02460d1a6.jpg)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![图片不存在](./media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![图片不存在](./media/930e7f2e5285e7c53fd1c8f993ab8b32.png)

![图片不存在](./media/0fdadbed575d5f54ae1ca9405c3647cb.png)

6. 代码说明:

| 代码                   | 说明                                     |
| ---------------------- | ---------------------------------------- |
| item = analogRead(36); | 将光敏传感器连接到GPIO36上，读取光敏传感器检测到的光照强度模拟值。 |
| item > 3000              | 光照强度检测，检测到光照强度的模拟值大于3000。|
| if( ){ } else{ }       | 如果（ ）里的表达式为真，则执行 if { }块内的代码。如果（ ）里表达式为假 ，则执行 else { }块内的代码。 |
| digitalWrite(2, HIGH)  | LED灯点亮。                      |
| digitalWrite(2, LOW)  | LED灯熄灭。                      |

---

项目11 光线检测报警系统

1. 项目介绍：

前面的项目中我们已经学习了光敏传感器的工作原理和光敏传感器控制LED灯快速闪烁的效果。那么，在本项目中，我们将结合光敏传感器、有源蜂鸣器和LED灯来模拟光线检测报警系统。

2. 项目元件：

|![图片不存在](./media/074ca02db99706884ece5ca5c9adece4.png)|![图片不存在](./media/3eb806e0acb028c1b242da3b85c44e58.png)|![图片不存在](./media/64f4a9e4d9b86ff8b0ef8b66afabffe0.png)|![图片不存在](./media/08cac8e036b616593db2d11a13d7922d.png)|![图片不存在](./media/28c28e6163de71f861c1f8f9bf621ee2.png)|
| :--: | :--: | :--: |:--: |:--: |
|ESP32*1|面包板*1|光敏传感器模块*1|有源蜂鸣器*1|红色LED*1|
|![图片不存在](./media/dda94299cc2abaff2c9cb8ff7ce365ff.jpg)|![图片不存在](./media/a6ff46e05db89a18ffe62f2f6c66c701.png)|![图片不存在](./media/11f324f82f890b0691f134e1ea7a3765.png)| ![图片不存在](./media/8d920d12138bd3b4e62f02cecc2c63a3.png)| |
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干| |

3. 项目接线图：

![图片不存在](./media/b541cf5deabe6e7c6e5eb6e1e6f263b3.png)

4. 项目代码：

<span style="color: rgb(255, 76, 65);">注意：</span>代码中的阈值3000可以根据环境中实际的光照强度更改。

```C
//**********************************************************************************
/*  
 * 名称   : Light_Detection_Alarm_System
 * 功能   : 光敏传感器控制LED和蜂鸣器
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;
void setup() {
  Serial.begin(115200); //设置串口波特率为115200
  pinMode(36, INPUT);    //将光敏传感器连接到GPIO36上，并设置为输入模式
  pinMode(2, OUTPUT);  //将LED连接到GPIO2上，并设置为输出模式
  pinMode(0, OUTPUT); //将有源蜂鸣器连接到GPIO0上，并设置为输出模式
}

void loop() {
  item = analogRead(36);   //光敏传感器读取光照强度，将读取到模拟值赋予变量Item
  Serial.println(item);  //串口打印光敏传感器输出的模拟信号
  if (item > 3000) {  //模拟值大于3000
    digitalWrite(0, HIGH); //打开蜂鸣器
    digitalWrite(2, HIGH);  //打开LED
    delay(500);  //延迟 500ms
    digitalWrite(0, LOW);  //关闭蜂鸣器
    digitalWrite(2, LOW);  //关闭LED
    delay(500);  //延迟 500ms
  } else {  //否则，模拟值不大于3000
    digitalWrite(0, LOW); //关闭蜂鸣器
    digitalWrite(2, LOW);  //关闭LED
  }
}
//**********************************************************************************
```

5. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：使用手机的照明灯对着光敏传感器模块上的光敏电阻照射，当光敏传感器检测到光照强度的模拟值大于3000时，有源蜂鸣器发出警报，外接LED灯快速闪烁。

![图片不存在](./media/c233cdd7ebc46f7b0341c204c22306ee.jpg)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![图片不存在](./media/0a3f2b8ad82b2f500b42c73e661993f7.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![图片不存在](./media/a3ce49fbd6f40f09869aa7e1d9f902f8.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![图片不存在](./media/930e7f2e5285e7c53fd1c8f993ab8b32.png)

![图片不存在](./media/0fdadbed575d5f54ae1ca9405c3647cb.png)

6. 代码说明:

可以参照项目10的代码说明，这里就不多做介绍了。

---







