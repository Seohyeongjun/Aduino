
#define green_3  10
#define yellow_3  9
#define red_3  8

#define green_2  7
#define yellow_2  6
#define red_2  5

#define green_1  4
#define yellow_1  3
#define red_1  2

#define red_1_on RED_1_on()
#define red_2_on RED_2_on()
#define red_3_on RED_3_on()

#define yellow_1_on YELLOW_1_on()
#define yellow_2_on YELLOW_2_on()
#define yellow_3_on YELLOW_3_on()

#define green_1_on GREEN_1_on()
#define green_2_on GREEN_2_on()
#define green_3_on GREEN_3_on()

#define LED_all_off LED_ALL_OFF()

int led[9]={red_1, yellow_1, green_1, red_2, yellow_2, green_2, red_3, yellow_3, green_3};

void LED_ALL_OFF(){
  for(int i=0; i<10; i++){
    digitalWrite(led[i], LOW);
  }
}

void RED_1_on(){
  for(int i=0; i<10; i++){
    digitalWrite(led[i], LOW);
  }

  digitalWrite(red_1, HIGH);
}

void RED_2_on(){
  for(int i=0; i<10; i++){
    digitalWrite(led[i], LOW);
  }

  digitalWrite(red_2, HIGH);
}

void RED_3_on(){
  for(int i=0; i<10; i++){
    digitalWrite(led[i], LOW);
  }

  digitalWrite(red_3, HIGH);
}

void YELLOW_1_on(){
  for(int i=0; i<10; i++){
    digitalWrite(led[i], LOW);
  }

  digitalWrite(yellow_1, HIGH);
}

void YELLOW_2_on(){
  for(int i=0; i<10; i++){
    digitalWrite(led[i], LOW);
  }

  digitalWrite(yellow_2, HIGH);
}

void YELLOW_3_on(){
  for(int i=0; i<10; i++){
    digitalWrite(led[i], LOW);
  }

  digitalWrite(yellow_3, HIGH);
}

void GREEN_1_on(){
  for(int i=0; i<10; i++){
    digitalWrite(led[i], LOW);
  }

  digitalWrite(green_1, HIGH);
}

void GREEN_2_on(){
  for(int i=0; i<10; i++){
    digitalWrite(led[i], LOW);
  }

  digitalWrite(green_2, HIGH);
}

void GREEN_3_on(){
  for(int i=0; i<10; i++){
    digitalWrite(led[i], LOW);
  }

  digitalWrite(green_3, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<10; i++)
    pinMode(led[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for(int i=0; i<3; i++){



  }

  red_1_on;
  delay(500);
  yellow_1_on;
  delay(500);
  green_1_on;
  delay(500);

  red_2_on;
  delay(500);
  yellow_2_on;
  delay(500);
  green_2_on;
  delay(500);

  red_3_on;
  delay(500);
  yellow_3_on;
  delay(500);
  green_3_on;
  delay(500);
}
