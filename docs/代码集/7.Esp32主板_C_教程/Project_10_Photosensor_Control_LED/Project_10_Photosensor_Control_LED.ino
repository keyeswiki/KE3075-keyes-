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