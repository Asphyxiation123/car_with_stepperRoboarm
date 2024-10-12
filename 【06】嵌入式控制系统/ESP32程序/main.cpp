/*
 * @Author: ChenJiaChen
 * @Date: 2023-12-05 15:07:51
 * @LastEditors: ChenJiaChen
 * @LastEditTime: 2024-02-21 20:42:57
 * @FilePath: \esp32_I2C2udp\src\main.cpp
 * @Description: ���ڽ��������ݷ�����UDP�ͻ���
 */

#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>
#include <stdio.h>

#define BufReceiveSize 40
#define BUFFER_SIZE 4 * sizeof(uint32_t) + 10

#define I2C_DEV_ADDR  0x01


static const uint8_t sda_pin = 4;
static const uint8_t scl_pin = 5;

const char *ssid = "CJC141";
const char *password = "12345678";
int i = 0;
uint32_t orderIndex; // UDP���յ���ָ��

WiFiUDP Udp;
IPAddress remote_IP(192, 168, 137, 1); // Զ�̼� IP ��ַ
unsigned int remoteUdpPort = 8080;     // Զ�̼����˿�pc�˿�

uint32_t ReceiveBuf[BufReceiveSize];
char Sendbuffer[BUFFER_SIZE];
char incomingPacket[8];
char SendtoPCbuffer[8];
// uint32_t I2CSendbuf[2] = {365,24};//����I2C����ָ��
uint8_t I2CReceiveBuf[8];
/*I2Cָ���

*/

uint8_t singalframe;
uint8_t Numframe = 40;
// uint16_t endframe;
uint32_t TmpCount = 0;

// void onRequest(){
//   Serial.println("onRequest");
// }

// void OnReceive(int count){
//   Serial.println("onReceive");
//   for(int i = 0; i < count; i++)
//   {
//     I2CReceiveBuf[i] = Wire.read();
//   }
// }



void setup()
{

  /*����0Ϊ���Դ��ڣ�����1Ϊ����ת������*/
  Serial.begin(230400);
  // Serial1.begin(115200);
  Serial.setDebugOutput(true);

  
  Serial1.begin(230400, SERIAL_8N1, /*rx =*/1, /*Tx =*/0);
  
  // /*I2C�ӻ���ʼ��*/
  // Wire.onReceive(OnReceive);
  // Wire.onRequest(onRequest);//������Ҫ��������ʱ�����жϻص�������slaveread

  /*I2C������ʼ��*/


  
  Serial.println("Init_I2c");
  
  while (!Wire.begin(sda_pin, scl_pin, 100000)){
    delay(100);
    Serial.println("I2C device loading...");
  }
  //                                sda,scl
  delay(100);
  // Wire.setClock(100000); // ����I2Cʱ��Ƶ��
  // Wire.begin(I2C_DEV_ADDR);
  
  

  /*WIFI��ʼ��*/
  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false); // �ر�STAģʽ��wifi���ߣ������Ӧ�ٶ�
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print(".");
  }
  Serial.print("Connected, IP Address: ");
  Serial.println(WiFi.localIP());
  // ��ӡWiFiUDP���ض˿���IP

  Udp.beginPacket(remote_IP, remoteUdpPort); // ����Զ��ip��ַ�Ͷ˿�
  Udp.print("nihao\n");
  Udp.endPacket(); // ��������

}

void loop()
{
  // Serial.println(Serial1.available());
  /*ÿ�δ��ڽ���40������������������һ������ת��*/
  if (Serial1.available() >= 0)
  {

    Serial1.readBytes((uint8_t *)&singalframe, sizeof(singalframe));
    Serial.print("frameis:");
    Serial.println(singalframe);
    // ����singalframe��ǰ16λ�Ƿ�Ϊ֡ͷ�ͺ�16λ�����֡����
    if (singalframe == 222) // ����ԭ������
    {
      // Serial1.readBytes((uint8_t *)&Numframe, sizeof(Numframe));
      Serial.println("��������");
      // Serial.println(Numframe);

      // Serial1.readBytesUntil(0xBBBB, (uint8_t *)ReceiveBuf, sizeof(ReceiveBuf));
      while (Serial1.available() >= sizeof(uint32_t) && TmpCount < Numframe )
      {
        Serial1.readBytes((uint8_t *)&ReceiveBuf[TmpCount], sizeof(uint32_t));
        TmpCount++;
      }
      
      Serial.println("��������2");
      
      // Wire.slaveWrite((uint8_t*)I2CSendbuf, sizeof(I2CSendbuf));
      
      TmpCount = 0;
      // Serial1.flush();

      // ��ӡ���յ�������
      Udp.beginPacket(remote_IP, remoteUdpPort); // ����Զ��ip��ַ�Ͷ˿�
      for (i = 0; i < Numframe/4; i++)
      {
        sprintf(Sendbuffer, "%d\n%d\n%d\n%d\n", (uint16_t)ReceiveBuf[i * 4], (uint16_t)ReceiveBuf[i * 4 + 1],
                (uint16_t)ReceiveBuf[i * 4 + 2], (uint16_t)ReceiveBuf[i * 4 + 3]);
        // Serial.print(Sendbuffer);
        Udp.print(Sendbuffer); // ������д�뷢�ͻ�����
        if(i == 4){
          Udp.endPacket(); // ��������
          Udp.beginPacket(remote_IP, remoteUdpPort); // ����Զ��ip��ַ�Ͷ˿�
        }
        // ���SendBuffer�����������
      }
      Udp.endPacket(); // ��������
      
    }

    else if(singalframe == 208){
      Serial.println("��������33333");
      sprintf(SendtoPCbuffer, "%d\n", 0x43);
      Udp.beginPacket(remote_IP, remoteUdpPort); // ����Զ��ip��ַ�Ͷ˿�
      Udp.print(SendtoPCbuffer);
      Udp.endPacket(); // ��������
    }
  }


  // if (Wire.available())
  // {
  //   //��ȡ8byte����
  //   for (int i = 0; i < 8; i++)
  //   {
  //     I2CReceiveBuf[i] = Wire.read();
  //   }
  //   Serial.println("�յ�i2c��������");
  // }

  

  //UDP���ݼ��
   Udp.beginPacket(remote_IP, remoteUdpPort); // ����Զ��ip��ַ�Ͷ˿�
  // UDP�����������ݲ�ʹ��UDP���ͻ�����
  if ( Udp.parsePacket() )                      //�����������ôData_length��Ϊ0��������Data_lengthΪ0
  {
    int len = Udp.read(incomingPacket, sizeof(incomingPacket));  //��ȡ���ݣ������ݱ���������incomingPacket��
    Serial.println("UDP���ݽ��ճɹ�");

    Wire.beginTransmission(12);  // ��ӻ���������
    Wire.write((uint8_t*)incomingPacket, sizeof(incomingPacket));
    Wire.endTransmission();  // ����IICͨѶ


    Serial1.print(incomingPacket);
    uint32_t data1,data2;
    // Serial.println(incomingPacket);
    //UDP���ͽ����ַ�
 
    /*UDP���յ���*/
    //data1ΪincomingPacketǰ4λ��϶��ɵ���
    data1 = ((uint32_t)incomingPacket[0] << 24) | ((uint32_t)incomingPacket[1] << 16) | ((uint32_t)incomingPacket[2] << 8) | (uint32_t)incomingPacket[3];
    //data2ΪincomingPacket��4λ��϶��ɵ���
    data2 = ((uint32_t)incomingPacket[4] << 24) | ((uint32_t)incomingPacket[5] << 16) | ((uint32_t)incomingPacket[6] << 8) | (uint32_t)incomingPacket[7];
    
    char UDPsendOutbuffer[20];
    sprintf(UDPsendOutbuffer,"data1:%d,data2:%d",data1,data2);
    Serial.println(UDPsendOutbuffer);
    
    



    Udp.print("receive:");

    // Udp.print(incomingPacket);                    // ������д�뷢�ͻ�����
    
    Udp.print(UDPsendOutbuffer);                    // ������д�뷢�ͻ�����
    // Udp.print("data1:");Udp.println(data1);
    
    
    // Udp.print("data2:");Udp.println(data2);

    Udp.endPacket(); // ��������
  }
  Udp.endPacket(); 
  // delay(500);
}