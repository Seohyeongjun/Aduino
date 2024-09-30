
#define pin8  8
#define pin7  7
#define pin6  6
#define pin5  5
#define pin4  4
#define pin3  3
#define pin2  2
#define pin1  1
#define pin0  0

int led[9]={pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8};

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<10; i++)
    pinMode(led[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  for(int i=0; i<10; i++){
//  digitalWrite(led[i], HIGH);
//  }
  digitalWrite(0, HIGH);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(500);

  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(500);

  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(500);


 

}
