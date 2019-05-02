# Mini Project: Data Collecting From Sensor
  สวัสดีครับ ชิ้นงานนี้ได้มีแนวคิดริเริ่มมาจาก ถ้าเราอยากจะนับจำนวนคนโดยที่เราไม่ต้องมานับเอง จะใช้วิธีไหนได้บ้าง
จึงเกิดออกมาเป็นโปรเจคนี้ขึ้นมา โดยเราจะให้เซ็นเซอร์ของเราเป็นตัวนับให้ แล้วนำข้อมูลที่ได้จากเซ็นเซอร์นั้นเก็บไว้
ในgoogle sheet ได้ ซึ่งข้อมูลที่ได้เราก็สามารถนำไปประกอบการวิเคราะห์ในหลายๆอย่างได้อีก 
ลองเชิญชมคลิปตัวอย่างดูครับ

## Video Present สาธิตวิธีการใช้งาน

## Equipment อุปกรณ์ที่ใช้การจัดทำ

| Accessory | Description |
|------|-----|
| NodeMCU-ESP8266 | โมดูล wifi ภายในมีเฟิร์มแวร์ทํางานในลักษณะ Serial-to-WiFi ที่ช่วยให้อุปกรณ์อื่นๆ เช่น MCU สามารถต่อเข้ากับ internet ได้โดยใช้ port serialและใช้คําสั่ง AT ในการควบคุมการทํางาน ต่อมาผู้พัฒนาได้พัฒนาเฟิร์มแวร์ NodeMcu ให้เป็น platform และใช้ภาษา LUA ในการเขียนโปรแกรม ด้วยความที่เป็น platform ที่สะดวกต่อการใช้งาน ทางผู้พัฒนาจึงจับ NodeMcu(ESP8266) ใส่เป็นบอร์ดหนึ่งใน Arduino IDE|
| Mini PIR Motion Sensor Module | คือ อุปกรณ์ Sensor ชนิดหนึ่งที่ใช้ตรวจจับคลื่นรังสี Infrared ที่แพร่จาก มนุษย์ หรือ สัตว์ ที่มีการเคลื่อนไหว ทำให้มีการนำเอา PIR มาประยุคใช้งานกันเป็นอย่างมากใช้เพื่อตรวจจับการเคลื่อนไหวของสิ่งมีชีวิต หรือ ตรวจจับการบุกรุกในงานรักษาความปลอดภัย |
| DHT22 | เป็นเซ็นเซอร์สำหรับวัดอุณหภูมิและความชื้นที่มีความแม่นยำสูงในการวัด สามารถวัดได้ในย่านอุณหภูมิ ตั้งแต่ -40 องศาเซลเซียส ถึง +80 องศาเซลเซียส ความแม่นยำน้อยกว่า +-0.5เซลเซียส และวัดความชื้นสัมพัทธ์ได้ในย่าน 0-100%RH ความแม่นยำ +-2-5%RH |
|Breadboard MB-102     |บอร์ดที่ใช้เสียบสายไฟ เซ็นเซอร์ หลอดไฟ ตัวต้านทานในการทดลองนั่นเอง|
|Jumper Wires Male-Female                                           |สายไฟจัมเปอร์ ที่ใช้เชื่อมต่อส่งกระแสไฟต่างๆ ชนิดหัวผู้-เมีย 30 CM|
|Resistor|คือ ตัวต้านทานที่ต่ออยู่ในวงจรไฟฟ้าทำหน้าที่ในการต้านการไหลของกระแสไฟฟ้าไหลผ่าน ทำด้วยลวดต้านทานหรือถ่านคาร์บอน เป็นต้น ในกรณีที่ มีความต้านทานมากจะยอมให้กระแสไฟฟ้าไหลผ่านได้น้อยลง หากกลับกัน หากมีความต้านทานน้อยจะยอมให้กระแสไฟฟ้าไหลผ่านได้มาก|
|USB Cable|ใช้เป็นหลักในการเชื่อมต่ออุปกรณ์ USB เข้ากับNodeMCU ESP8266|

## Installation ขั้นตอนการติดตั้งสำหรับผู้ใช้งาน
กรณีที่ผู้ใช้งานต้องการจะติดตั้งตั้งค่าต่างๆเอง สำหรับการใช้งานนั้น ผู้ใช้จะต้องทำการโหลดโปรแกรม Arduino และ Library ต่างๆมาติดตั้งบนคอมพิวเตอร์ของคุณ
* วิธีการติดตั้งโปรแกรม Arduino [Click!](https://www.youtube.com/watch?v=dMujuIKpWdM)
* วิธีการติดตั้งไลบรารี่ต่างๆ [Click!](https://www.youtube.com/watch?v=tO4FLMQ0MHY)
### เมื่อทำการติดตั้ง Program เรียบร้อยแล้ว ก็ให้โหลด Library ตามนี้ เพื่อที่จะนำมาใช้ในโปรเจคนี้
* Adafruit Unified Sensor Driver [Click!](https://github.com/adafruit/Adafruit_Sensor)
* DHT Sensor [Click!](https://github.com/adafruit/DHT-sensor-library)
* Firebase Arduino [Click!](https://github.com/FirebaseExtended/firebase-arduino)
* ArduinoJson [Click!](https://github.com/bblanchon/ArduinoJson)

## Setting วิธีการตั้งค่าเพื่อเริ่มใช้ชิ้นงาน
1.ทำการสร้างโครงการฐานข้อมูลที่ Firebase ของ Google [Click!](https://console.firebase.google.com/u/0/) ตั้งชื่อโครงการ สามารถดูตัวอย่างได้ตามภาพ
![](https://raw.githubusercontent.com/RewiKaze/CollectingDataFromSensor-ComPro61/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/firebase%201.png)
2.เมื่อสร้างเสร็จแล้วจะเข้าไปที่หน้าโครงการ จากนั้นให้กด Database และสร้างฐานข้อมูลแบบ Realtime Database และเลือกเริ่มต้นในแบบทดสอบ![](https://raw.githubusercontent.com/RewiKaze/CollectingDataFromSensor-ComPro61/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/firebase2.png)
3.จากนั้นให้เปิดไฟล์ใน Github ของเรานั่นคือ Data_Collection.ino ภายในนั้นจะมีส่วนที่เป็น '#define' ไว้เราจะทำการแก้ไขมันในแต่ละส่วนดังนี้

`#define FIREBASE_HOST "<YOUR DATABASE>"` ในส่วนนี้ให้ได้ลิงค์ข้อมูลที่เราได้สร้างใน Firebase 
![](https://raw.githubusercontent.com/RewiKaze/CollectingDataFromSensor-ComPro61/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/firebase3.png)
`#define FIREBASE_AUTH "<YOUR SECRET TOKEN>"` ในส่วนนี้ได้จะได้จากที่เราไปเอาSecret Token ใน Firebase วิธีเอาตามรูปด้านล่างนี้
![](https://raw.githubusercontent.com/RewiKaze/CollectingDataFromSensor-ComPro61/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/firebase4.png)
![](https://raw.githubusercontent.com/RewiKaze/CollectingDataFromSensor-ComPro61/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/firebase5.png)
![](https://raw.githubusercontent.com/RewiKaze/CollectingDataFromSensor-ComPro61/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/firebase6.png)
จากนั้นนำส่วนตัวอักษรที่ได้จากช่องสี่เหลี่ยมตามภาพด้านบนนั้นมาใส่ในช่อง <YOUR SECRET TOKEN><br>
`#define WIFI_SSID` นั้นให้ใส่ชื่อ Wifi ที่จะให้ NodeMCU นั้นเชื่อมต่อผ่านอินเทอร์เน็ตได้<br>
`#define WIFI_PASSWORD` นั้นให้ใส่รหัส Wifi ที่จะให้ NodeMCU นั้นเชื่อมต่อผ่านอินเทอร์เน็ตได้<br><br>
4.จากนั้นให้เชื่อมต่อสายกับ NodeMCU และ Upload โค้ดเข้าไปใน NodeMCU จากนั้นตรวจสอบการทำงานว่าใน Firebase นั้นมีการอัพเดตหรือไม่
ในกรณีอ่านไม่เข้าใจสามารถทำความเข้าใจได้ภายในลิงค์คลิปนี้ [Click!](https://www.youtube.com/watch?v=jqKW_Qo0AUM) หรือข้อมูลเพิ่มเติมได้ในลิงค์นี้ [Click!](https://www.youtube.com/watch?v=jqKW_Qo0AUM)<br><br>
5.ทำการเชื่อมต่อ Firebase กับ Google Sheets วิธีการตามลิงค์นี้ [Click!](https://bit.ly/2Q9FcVF)
  


## Features ฟังก์ชั่นที่ตอบสนองต่อผู้ใช้งาน
* เช็คการเคลื่อนที่ของสิ่งมีชีวิต
* สามารถเก็บข้อมูลและส่งไปที่ Google Sheet โดยผ่าน Firebase ได้
* สามารถเช็คอุณหภูมิรอบๆชิ้นงานนี้ได้

โดยทุกฟังก์ชั่นที่กล่าวมานั้น เราแค่ทำการติดต่อตั้งแล้วเชื่อม WIFI ข้อมูลก็จะสามารถขึ้นที่หน้า Google Sheet ได้เลย

### ตัวอย่างหน้า Google Sheet เวลาที่เซนเซอร์และตัววัดอุณหภูมิวัดข้อมูลได้

![](https://github.com/RewiKaze/CollectingDataFromSensor-ComPro61/blob/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/ex2.png)

## Members
|         |Name|Github Username|StudentID|
|------|-----|------|------|
|       ![](https://github.com/RewiKaze/CollectingDataFromSensor-ComPro61/blob/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/%E0%B8%99%E0%B8%B4%E0%B8%A72.jpg)  |Tanawat Kemwatcharalert|  [@Zimbo333](https://github.com/Zimbo333)      |61070074|
|       ![](https://github.com/RewiKaze/CollectingDataFromSensor-ComPro61/blob/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/%E0%B8%9D%E0%B9%89%E0%B8%B2%E0%B8%A22.jpg)  |Phawinee Thongbor| [@faiifu](https://github.com/Faiifu)       |61070163|
|      ![]( https://github.com/RewiKaze/CollectingDataFromSensor-ComPro61/blob/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/%E0%B8%A3%E0%B8%B4%E0%B8%A72.jpg)   |Wasitpol Jongmanasjaroean|  [@RewiKaze](https://github.com/RewiKaze)      |61070204|
|     ![](https://github.com/RewiKaze/CollectingDataFromSensor-ComPro61/blob/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/%E0%B8%95%E0%B8%AD%E0%B8%872.jpg)    |Soipachara Mekalai| [@soipachara43](https://github.com/soipachara43)          |61070235|

## Assistant Teacher
|         |Name|Lastname|
|-------|------|-------|
|      ![](https://github.com/RewiKaze/CollectingDataFromSensor-ComPro61/blob/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/T.ong2.jpg)   |Asst. Prof. Dr.kitsuchart|pasupa| 
|       ![]( https://github.com/RewiKaze/CollectingDataFromSensor-ComPro61/blob/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B/T.panwit.jpg)  |Asst. Prof. Dr.Panwit|Tuwanut|



Readme.md และ Source codeนี้ เป็นส่วนหนึ่งของวิชา การสร้างโปรแกรมคอมพิวเตอร์ Computer Programming หลักสูตรวิทยาศาสตร์บัณฑิต สาขาวิชาเทคโนโลยีสารสนเทศ ภาคเรียนที่ 2 ปีการศึกษา 2561 คณะเทคโนโลยีสารสนเทศ IT (Faculty of Information Technology, KMITL) สถาบันเทคโนโลยีพระจอมเกล้าเจ้าคุณทหารลาดกระบัง



