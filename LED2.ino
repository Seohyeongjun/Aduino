#define LED_all_off LED_ALL_OFF()

#define red_1 2
#define red_2 5
#define red_3 8

#define yellow_1 3
#define yellow_2 6
#define yellow_3 9

#define green_1 4
#define green_2 7
#define green_3 10

#define sw_1 11

int led_R[3]={red_1, red_2, red_3};
int led_Y[3]={yellow_1, yellow_2, yellow_3};
int led_G[3]={green_1, green_2, green_3};

void led_all_off(){
  for(int i=0; i<3; i++){
    digitalWrite(*(led_R+i), LOW);
    digitalWrite(*(led_Y+i), LOW);
    digitalWrite(*(led_G+i), LOW);
  }
}

void led_Yellow(){

  led_all_off();

 // for(int i=0; i<3; i++){
    for(int j=0; j<3; j++)
      digitalWrite(*(led_Y+j), HIGH);
 //   delay(500);

  //   for(int j=0; j<3; j++)
  //     digitalWrite(led_Y[j], LOW);  
  //   delay(500);
  // }
  delay(2000);
}

void setup() {
  for(int i=0; i<3; i++){
    pinMode(*(led_R+i), OUTPUT);
    pinMode(*(led_Y+i), OUTPUT);
    pinMode(*(led_G+i), OUTPUT);
    pinMode(sw_1, INPUT);
  }
}

static int swOk=0;

void loop() {  
  int sw=0;  
  
  if(digitalRead(sw_1) == 0){
    for(int i=0; i<50; i++){
      if(digitalRead(sw_1) == 0)
        sw++;
      else
        sw=0;

      delay(1);
    }
  }

  if(sw>=30)
    swOk = 1;

  if(swOk==1){
  for(int i=0; i<3; i++){
    led_all_off();

    digitalWrite(*(led_G+i), HIGH);

    for(int j=0; j<3; j++){
      if(i!=j)
        digitalWrite(*(led_R+j), HIGH);
    }

    if(i==0)
      delay(5000);
    else
      delay(7000);

    led_Yellow();    
  }
  }
  
}
