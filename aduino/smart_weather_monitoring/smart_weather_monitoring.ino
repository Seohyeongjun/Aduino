#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7

#define RED 3
#define GREEN 5
#define BLUE 6

#define BUZZER 8

DHT dht(DHTPIN, DHT11);

void setup(){
  Serial.begin(9600);
  dht.begin();

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  pinMode(BUZZER, OUTPUT);
}

void buzzer(){
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
}

void loop(){
  delay(500);
  float hum = dht.readHumidity(); //습도
  float temp = dht.readTemperature();

  Serial.print("온도 : ");
  Serial.print(temp);
  Serial.print("ºC  ");
  Serial.print("습도 : ");
  Serial.print(hum);
  Serial.println("%,  ");

  if((temp>10 && temp<30) &&(hum>40 && hum<60)){
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
  }
  
  else if(temp>30 || hum<40){
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    buzzer();
  }

  else if(temp<10 || hum>60){
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
    buzzer();
  }
}

// 스마트날씨 모니터링 시스템
// 
// 기능 :
// 온습도계로 실내의 온도와 습도를 모니터링하고, 특정 범위를 벗어날 경우 RGB LED 색상 변경
// 온도와 습도가 높거나 낮으면 부저 경고
//
// RGB LED : 
// 녹색 - 정상범위(온도 : 10~30, 습도 : 40~60)
// 빨강 - 온도가 높거나 습도가 낮은 경우
// 파랑 - 온도가 낮거나 습도가 높은경우
// 능동부저로 빨강과 파랑 변경시 경고음 출력
