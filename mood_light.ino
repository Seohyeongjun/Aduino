#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Servo.h>

#define TRIG 2
#define ECHO 4

#define POTEN A0  // 가변저항

#define DHTPIN 8  // 온습도센서
#define SERVO 10  // RC서보모터

#define RED 5     // red led
#define GREEN 6   // green led
#define BLUE 3    // blue led

#define LED_R 7   // red for 초음파
#define LED_G 9   // green for 초음파

#define KEY_L 11  // cctv 좌 이동
#define KEY 12
#define KEY_R 13  // cctv 우 이동

DHT dht(DHTPIN, DHT11); // 온습도센서 셋팅
LiquidCrystal_I2C lcd(0x27, 16, 2); // text lcd 셋팅

// 모터 선
// 적색 : 전원
// 갈색 : GND
// 주황 : 신호선
Servo servo;  // 객체 생성  
int pos=0;    // 모터 위치

// text lcd 사용자 정의 문자
byte aa[8]={   // º(도)
  B01000,
  B10100,
  B01000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte a[8]={   // 도
  B00000,
  B11111,
  B10000,
  B10000,
  B11111,
  B00100,
  B11111,
  B00000
};

byte b[8]={   // 온
  B01110,
  B10001,
  B01110,
  B00100,
  B11111,
  B00000,
  B10000,
  B11111
};

byte c[8]={   // 습
  B00100,
  B01010,
  B10000,
  B11111,
  B10010,
  B11110,
  B10010,
  B11110
};

void setup() {
  lcd.init();       // lcd 초기화
  lcd.backlight();  // lcd 백라이트 초기화

  servo.attach(SERVO);  // 모터 초기화
  
  lcd.createChar(0, b);   // 온, 0 : 온의 번호, b : 사용자 정의 문자에서 온의 함수이름
  lcd.createChar(1, c);   // 습
  lcd.createChar(2, a);   // 도
  lcd.createChar(3, aa);  // º

  Serial.begin(9600);     // 시리얼통신 초기화(컴퓨터와 통신)
  dht.begin();            // 온습도 센서 초기화

  pinMode(RED, OUTPUT);   // red led 출력
  pinMode(GREEN, OUTPUT); // green led 출력
  pinMode(BLUE, OUTPUT);  // blue led 출력

  pinMode(KEY, INPUT);
  pinMode(KEY_L, INPUT);
  pinMode(KEY_R, INPUT);

  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pos=80;
}

static int swOk=0;
int key_flag=0;

void key_in(){   

  int key=0; 

  if(digitalRead(KEY)==LOW)     // key press down and count up for debouncing
    key_flag=1;

  else if(digitalRead(KEY_L)==LOW)  // key left
    key_flag=2;

  else if(digitalRead(KEY_R)==LOW)  //key right
    key_flag=3;

  else                           // key up
    key_flag=0;  

  delay(60);

  if(key_flag==1 && digitalRead(KEY)==LOW)
      swOk=1;
  else if(key_flag==2 && digitalRead(KEY_L)==LOW)
      swOk=2;  
  else if(key_flag==3 && digitalRead(KEY_R)==LOW)
      swOk=3;
  else
    swOk=0;   
  // if((digitalRead(KEY)==LOW) && (key_flag=1)){  
  //   key++;
  //   swOk++;

  //   if(swOk==3)
  //     swOk=1;

  //   key_flag=0;
  // } 



  // if(digitalRead(KEY)==LOW)     // key press down and count up for debouncing
  //   key_flag=1;

  // else                           // key up
  //   key_flag=0;  

  // delay(50);

  // if((digitalRead(KEY)==LOW) && (key_flag=1)){  
  //   key++;
  //   swOk++;

  //   if(swOk==3)
  //     swOk=1;

  //   key_flag=0;
  // } 
}

void loop() {
  float length, dist;
  key_in();

  digitalWrite(TRIG, HIGH); // 초음파센서에 신호전달 - 음파 발생
  delay(10);
  digitalWrite(TRIG, LOW);  // 신호 끄기

  length = pulseIn(ECHO, HIGH); // 시간 측정
  dist = (float)(340 * length)/10000/2; // m -> cm, 편도

  Serial.print("거리 : ");
  Serial.print(dist);

  Serial.print(", 모터각도 : ");
  Serial.print(pos);

  Serial.print(", swOk : ");
  Serial.println(swOk);


  lcd.setCursor(0, 0);  // 온도 위치
  lcd.print("dist : ");
  lcd.print(dist, 1);
  lcd.print("cm   ");

  lcd.setCursor(0, 1);  // 모터 이동각도
  lcd.print("motor : ");
  lcd.print(pos);
  lcd.write(3);
  lcd.print(" ");  

  if(dist<30){
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
  }
  else{
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
  }

  if(swOk==2){
    servo.write(pos+=20);
    if(pos>=180)
      pos=180;
  }
  else if(swOk==3){
    servo.write(pos-=20);
    if(pos<=0)
      pos=0;
  }

  delay(100);
  
  // lcd.setCursor(0, 1);  // 습도 위치
  // lcd.write(1);
  // lcd.write(2);
  // lcd.print(":");
  // lcd.print(hum,1);
  // lcd.print("%");

  // int val = analogRead(POTEN);        // 가변저항값 읽기
  // float hum = dht.readHumidity();     // 습도
  // float temp = dht.readTemperature(); // 온도

  // 시리얼 통신
  // Serial.print("가변저항 : ");
  // Serial.print(val);

  // Serial.print("온도 : ");
  // Serial.print(temp);
  // Serial.print("ºC  ");

  // Serial.print(", 습도 : ");
  // Serial.print(hum);
  // Serial.print("%,  ");

  // Serial.print("key : ");
  // Serial.print(swOk);

  // lcd.setCursor(0, 0);  // 온도 위치
  // lcd.write(0);         // 사용자 정의문자 0 출력(온)
  // lcd.write(2);         // 사용자 정의문자 2 출력(도)
  // lcd.print(":");
  // lcd.print(temp,1);    // 온도 출력. 1 : 소수점 이하 자리 수
  // lcd.write(3);         // 사용자 정의문자 2 출력(º)
  // lcd.print("C");

  // lcd.setCursor(0, 1);  // 습도 위치
  // lcd.write(1);
  // lcd.write(2);
  // lcd.print(":");
  // lcd.print(hum,1);
  // lcd.print("%");

//   // 온도에 따라 led 색 변화
//   if(temp<28){
//     analogWrite(RED, 0);
//     analogWrite(GREEN, 0);
//     analogWrite(BLUE, val*0.25);    // 각 색에 따라 밝기 조절(가변저항 값)
//   }
//   else if(temp>=28 && temp<31){
//     analogWrite(RED, 0);
//     analogWrite(GREEN,  val*0.25);
//     analogWrite(BLUE, 0);
//   }
//   else if(temp>=31){
//     analogWrite(RED, val*0.25);
//     analogWrite(GREEN, 0);
//     analogWrite(BLUE,  0);
//   }

//   // 습도에 따라 모터 동작
//   if(hum<60 && swOk!=2){                     // 습도가 60% 미만일 때 모터 동작
//     servo.write(pos++);           // 0 ~ 180도    

//     if(pos>=180)                  // 모터가 최대 180도까지 동작하므로 0으로 초기화
//       pos=0;
    
//  //   key_flag=0;
//   }
//   else if(hum>60 || swOk==2){                           // 습도가 60% 이상일 때 모터 멈춤
//     pos=0;
//     servo.write(pos);

//  //   swOk=0;
//  //   key_flag=0;
//   }

//  delay(50);

}
