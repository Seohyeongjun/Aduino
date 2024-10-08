#include <Servo.h>

#define SERVO 9
#define Cds A0

Servo servo;  // 객체 생성
int pos=0;    // 위치
int limit=100; // 빛 기준
void setup() {
  Serial.begin(9600);
  servo.attach(SERVO);
}

void loop() {
  int Cds_in;//=analogRead(Cds);
  Cds_in=analogRead(Cds);
  for( ; (pos<=180) && (Cds_in<limit); pos++){
    servo.write(pos); // 1도씩 이동
    delay(10);
    
    if(pos%20==0){
      Serial.print("pos : ");
      Serial.print(pos);

      Cds_in=analogRead(Cds);
      Serial.print(",   Cds : ");
      Serial.println(Cds_in);
    }
  }
  for( ; (pos>=0) && (Cds_in>limit); pos--){
    servo.write(pos); // 1도씩 이동
    delay(10);

    if(pos%20==0){
      Serial.print("pos : ");
      Serial.print(pos);

      Cds_in=analogRead(Cds);
      Serial.print(",   Cds : ");
      Serial.println(Cds_in);
    }
  }

}
