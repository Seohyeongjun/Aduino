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

#define sw_1 8

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
  delay(200);
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
char key_flag=0;

void key_input(){
  int sw=0;  
  
  while(1){   // 키 입력, 디바운싱기능 추가
    if(digitalRead(sw_1) == LOW){   // key press down and count up for debouncing
      key_flag=1;
      sw++;
    }

    else{                           // key up
      key_flag=0;
      
      if(sw<50)                     // when key up and the counts of sw is under 50 then all counts be cleared
        sw=0;
    }

    delay(1);

    if(sw>50 && key_flag==0){     // key debouncing for 50ms
      swOk++;
      break;
    }
  }
}

void loop() {  

  key_input();
  //  swOk++;
//  }
  // else
  //   digitalWrite(led_R[1], HIGH);
  // if(digitalRead(sw_1) == LOW){
  //   for(int i=0; i<50; i++){
  //     if(digitalRead(sw_1) == 0)
  //       sw++;
  //     else
  //       sw=0;
  //   }

  //   if(sw>=30)
  //     swOk++;

  // }

  

  if(swOk==1){
    led_all_off();
    digitalWrite(*(led_R), HIGH);
    digitalWrite(*(led_Y), HIGH);
    digitalWrite(*(led_G), HIGH);
  // //    for(int i=0; i<3; i++){   
  //       digitalWrite(*(led_G+swOk-1), HIGH);

  //       for(int j=0; j<3; j++){
  //         if(i!=j)
  //           digitalWrite(*(led_R+j), HIGH);
  //       }

  //       if(i==0)
  //         delay(500);
  //       else
  //         delay(700);

  //       led_Yellow(); 
  //       led_all_off();   
 //     }      
    }    

    else if(swOk==2){
      led_all_off();
      digitalWrite(*(led_R+1), HIGH);
      digitalWrite(*(led_Y+1), HIGH);
      digitalWrite(*(led_G+1), HIGH);
    }

    else if(swOk==3){
      led_all_off();
      digitalWrite(*(led_R+2), HIGH);
      delay(1000);
      digitalWrite(*(led_R+2), LOW);
      digitalWrite(*(led_Y+2), HIGH);
      delay(1000);
      digitalWrite(*(led_R+2), LOW);
      digitalWrite(*(led_Y+2), LOW);
      digitalWrite(*(led_G+2), HIGH);
      delay(1000);
    }

    else{
      led_all_off();
      swOk=0;
    }

//    swOk=0;

}
