#include <Servo.h>

#define SERVO 9
#define BUZZER 7
#define SW_520D 12
#define KEY 4

Servo servo;  // 객체 생성
int pos=0;    // 위치

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO);

  pinMode(SW_520D, INPUT);
  pinMode(KEY, INPUT);
  pinMode(BUZZER, OUTPUT);
}
static int buzzerOn=0;

void buzzer_on(){
  if(buzzerOn==0){
    for(int i=0; i<2; i++){
      digitalWrite(BUZZER, HIGH);
      delay(50);
      digitalWrite(BUZZER, LOW);
      delay(50);
    }
    buzzerOn=1;
  }
}
void loop() {
  int sw = digitalRead(SW_520D);
  Serial.print("기울기 : ");
  Serial.println(sw);

  if(sw==LOW){
    servo.write(30);
    buzzerOn=0;
  }
  else{
    servo.write(160);
    buzzer_on();    
  }
 
  delay(100);
    
}
