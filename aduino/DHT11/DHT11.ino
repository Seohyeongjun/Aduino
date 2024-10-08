
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7
DHT dht(DHTPIN, DHT11);

void setup(){
  Serial.begin(9600);
  dht.begin();

}


void loop(){
  delay(1000);
  float hum = dht.readHumidity(); //습도
  float temp = dht.readTemperature();

  Serial.print("습도 : ");
  Serial.print(hum);
  Serial.print("%,  ");
  Serial.print("온도 : ");
  Serial.print(temp);
  Serial.println("ºC  ");
}


// #define DHT11 7

// unsigned char dat[5];
// unsigned char readDHT(){
//   unsigned char data=0;

//   for(int i=0; i<8; i++){
//     if(digitalRead(DHT11) == LOW){
//       while(digitalRead(DHT11) == LOW);

//       delayMicroseconds(30);

//       if(digitalRead(DHT11) ==  HIGH)
//         data = data | (1<<(7-i));

//       while(digitalRead(DHT11) == HIGH);
//     }
//   }
//   return data;
// }
// void start_read(){
//   digitalWrite(DHT11, LOW); // 온, 습도 측정 시작
//   delay(20);

//   digitalWrite(DHT11, HIGH);
//   delayMicroseconds(40);

//   pinMode(DHT11, INPUT);
//   while(digitalRead(DHT11) == HIGH);
//   delayMicroseconds(80);
//   if(digitalRead(DHT11) == LOW);
//   delayMicroseconds(80);

//   // 온, 습도 읽기. 습도는 0, 1 인덱스에 저장, 온도는 2, 3 인덱스에 저장
//   // 4번인덱스에는 체크섬 값 넣어서 비교하는 용도로 활용해도 됨
//   // 체크섬값은 온도와 습도의 합이다. 측정한 온도와 습도의 값이 체크섬과 다르다면 오류
//   for(int i=0; i<4; i++){
//     dat[i] = readDHT();
//   }

//   pinMode(DHT11, OUTPUT);
//   digitalWrite(DHT11, HIGH);
// }

// void setup() {
//   Serial.begin(9600);
//   pinMode(DHT11, OUTPUT);
// }

// void loop() {
//   start_read();
//   Serial.print("습도 : ");
//   Serial.print(dat[0], DEC);
//   Serial.print(".");
//   Serial.print(dat[1], DEC);
//   Serial.print("%, ");

//   Serial.print("온도 : ");
//   Serial.print(dat[2], DEC);
//   Serial.print(".");
//   Serial.print(dat[3], DEC);
//   Serial.print("ºC, ");
//   Serial.println();
//   delay(1000);
  

// }

// DHT11과 통신을 시작해야 한다.
// 통신을 하기 위해서 디지털 핀을 LOW상태로 설정하고 18ms이상 유지
// LOW상태 유지를 하면 DHT11이 데이터 전송을 준비 한다.
// 디지털핀을 HIGT로 설정하고 20~40 정도 대기 한 뒤 입력 모드로 전환
// DHT11이 응답신호로 LOW와 HIGT를 보낸다.
// LOW오 HIGH 신호를 측정하여 온도와 습도를 구해야 한다.