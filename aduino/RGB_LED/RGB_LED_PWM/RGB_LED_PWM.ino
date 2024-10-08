#define LED_all_off LED_ALL_OFF()

#define red_1 2
#define red_2 5
#define red_3 9

#define yellow_1 3
#define yellow_2 6
#define yellow_3 10

#define green_1 4
#define green_2 7
#define green_3 11

#define sw_1 12
#define sw_2 8
#define sw_3 13

int led_R[3]={red_1, red_2, red_3};
int led_Y[3]={yellow_1, yellow_2, yellow_3};
int led_G[3]={green_1, green_2, green_3};

int key[3]={sw_1, sw_2, sw_3};

void led_all_off(){
  for(int i=0; i<3; i++){
    digitalWrite(*(led_R+i), LOW);
    digitalWrite(*(led_Y+i), LOW);
    digitalWrite(*(led_G+i), LOW);
  }
}

void setup() {
  Serial.begin(9600);
  for(int i=0; i<3; i++){
    pinMode(*(led_R+i), OUTPUT);
    pinMode(*(led_Y+i), OUTPUT);
    pinMode(*(led_G+i), OUTPUT);

    pinMode(key[i], INPUT);
  }
}

static int swOk=0;
char key_flag_1=0, key_flag_2=0, key_flag_3=0;

void key_input(){
  int key_1=0, key_2=0, key_3=0;  

  while(1){   // 키 입력, 디바운싱기능 추가
    if(digitalRead(key[0])==0){     // key press down and count up for debouncing
      key_flag_1=1;
      key_1++;
    }
    
    else if(digitalRead(key[1])==0){     // key press down and count up for debouncing
      key_flag_2=1;
      key_2++;
    }

    else if(digitalRead(key[2])==0){     // key press down and count up for debouncing
      key_flag_3=1;
      key_3++;
    }

    else{                           // key up
      key_flag_1=0;
      key_flag_2=0;
      key_flag_3=0;
      
      if(key_1<50)                   // when key up and the counts of sw is under 50 then all counts be cleared
        key_1=0;
      else if(key_2<50)  
        key_2=0;
      else if(key_3<50)   
        key_3=0;      
    }

    delay(1);   // to 50ms for debouncing

    if(key_1>50 && key_flag_1==0){       // key debouncing for 50ms
      swOk=1;
      break;
    }

    else if(key_2>50 && key_flag_2==0){       // key debouncing for 50ms
      swOk=2;
      break;
    }

    else if(key_3>50 && key_flag_3==0){       // key debouncing for 50ms
      swOk=3;
      break;
    }
  }
}
unsigned char r=255;
unsigned char g=255;
unsigned char b=255;

static int button_1=0;

void loop() {  

  key_input();

  if(swOk==1){    // select
    led_all_off();

    if(button_1==0){
      digitalWrite(*(led_R), HIGH);
      digitalWrite(*(led_R+1), HIGH);

      analogWrite(*(led_R+2), r);      
    }

    else if(button_1==1){
      digitalWrite(*(led_Y), HIGH);
      digitalWrite(*(led_Y+1), HIGH);

      analogWrite(*(led_Y+2), r);
    }

    else if(button_1==2){
      digitalWrite(*(led_G), HIGH);
      digitalWrite(*(led_G+1), HIGH);

      analogWrite(*(led_G+2), b);
    }

    button_1++;

    if(button_1==3)
      button_1=0;
    swOk=0;     
  }    

  else if(swOk==2){   // up

    if(button_1==1){ // red
      r+=10;
      
      if(r>=255)
        r=0;
      
      analogWrite(*(led_R+2), r);
    }
    else if(button_1==2){    // green
      g+=10;
      
      if(g>=255)
        g=0;
      
      analogWrite(*(led_Y+2), g);
    }
    else{    // blue
      b+=10;
      
      if(b>=255)
        b=0;

      analogWrite(*(led_G+2), b);
    }

    swOk=0;
  }

  else if(swOk==3){   // down

    if(button_1==1){ // red
      r-=10;

      if(r<=0)
        r=255;

      analogWrite(*(led_R+2), r);
    }
    else if(button_1==2){    // green
      g-=10;
      
      if(g<=0)
        g=255;

      analogWrite(*(led_Y+2), g);
    }
    else{    // blue
      b-=10;
      
      if(b<=0)
        b=255;

      analogWrite(*(led_G+2), b);
    }
  
    swOk=0;
  }
}
