# Mini Project: Data Collecting From Sensor


  สวัสดีครับ ชิ้นงานนี้ได้มีแนวคิดริเริ่มมาจาก ถ้าเราอยากจะนับจำนวนคนโดยที่เราไม่ต้องมานับเอง จะใช้วิธีไหนได้บ้าง
จึงเกิดออกมาเป็นโปรเจคนี้ขึ้นมา โดยเราจะให้เซ็นเซอร์ของเราเป็นตัวนับให้ แล้วนำข้อมูลที่ได้จากเซ็นเซอร์นั้นเก็บไว้
ในgoogle sheet ได้ ซึ่งข้อมูลที่ได้เราก็สามารถนำไปประกอบการวิเคราะห์ในหลายๆอย่างได้อีก 
ลองเชิญชมคลิปตัวอย่างดูครับ

# ขั้นตอนการตั้งค่าเพื่อเริ่มต้นใช้การ 

<p>1.ให้ท่านโหลดโปรแกรม "Arduino" สามารถดาวน์โหลดได้ที่ www.arduino.cc</p><br>
<p>2.เปิดโปรแกรมและก็ติดตั้งตัว Board NodeMCU โดยให้ไปที่ File -> Preference และใส่ ข้อความนี้ "http://arduino.esp8266.com/stable/package_esp8266com_index.json" ในช่อง Additional Boards Manager URLs ดังภาพตัวอย่างนี้ แล้วกด OK
<center><a href="https://imgur.com/OAPeS2N"><img src="https://i.imgur.com/OAPeS2N.png" title="source: imgur.com" /></a><center></p><br>
<p>3.จากนั้นให้ไปที่Tools -> Boards -> Boards Manager จากนั้นให้พิมพ์ในช่องค้นหาว่า esp8266 แล้วก็กดปุ่ม Install จากนั้นออกมาหน้าแรกและตั้งค่าบอร์ดที่ Tools->Boards->แล้วเลือกบอร์ด NodeMCU 1.0(ESP-12E Module)</p>

