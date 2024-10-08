#define c 261 // 도 - 4옥타브
#define d 293 // 레
#define e 329 // 미
#define f 349 // 파
#define g 391 // 솔
#define a 440 // 라
#define b 493 // 시
#define c5 523  // 도 - 5옥타브

#define buzzer 8
#define speaker 7

#define sw 12

int music[]={g, g, a, a, g, g, e, 0, g, g, e, e, d, 0, 0, g, g, a, a, g, g, e, 0, g, e, d, e, c};  // 학교종이 땡댕댕

void setup() {
  Serial.begin(9600);
//  pinMode(buzzer, OUTPUT);
//  pinMode(sw, INPUT);
  pinMode(speaker, OUTPUT);
}

int key_flag=0;
int swOk=0;

void key_input(){
  int key=0;  

  while(1){   // 키 입력, 디바운싱기능 추가
    if(digitalRead(sw)==LOW){     // key press down and count up for debouncing
      key_flag=1;
      key++;
    }

    else{                           // key up
      key_flag=0;
      
      if(key<50)                   // when key up and the counts of sw is under 50 then all counts be cleared
        key=0;          
    }

    delay(1);   // to 50ms for debouncing

    if(key>50 && key_flag==0){       // key debouncing for 50ms
      swOk=1;
      break;
    }
  }
}

void loop() {
  int value;
//  key_input();

  // int value = digitalRead(swOk);
  // Serial.println(value);

  // if(swOk==1){
  //   digitalWrite(buzzer, HIGH);
  //   delay(500);
  //   digitalWrite(buzzer, LOW);
  //   swOk=0;
  // }
  for(int i=0; i<28; i++){
    tone(speaker, music[i], 500);
//    value = digitalRead(speaker);
    Serial.println(music[i]);

    delay(500);
  }
  delay(2000);
}
