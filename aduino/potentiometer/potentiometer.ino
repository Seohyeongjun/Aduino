#define POTEN A0
#define Cds A3

#define LED_ON 400

#define RED 3
#define GREEN 5
#define BLUE 6

#define sw 2
#define buzzer 8

void setup() {
  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(sw, INPUT);
}

static int swOk=0;
int key_flag=0;

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
      swOk++;
      break;
    }
  }
}

void beep(){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
}

void loop() {
  
  int val = analogRead(POTEN);
  int Cds_R = analogRead(Cds);
    Serial.println(swOk);

  key_input();

  if(Cds_R>LED_ON){
    if(swOk==1){
      analogWrite(RED, val/4);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
//      beep();
    }

    else if(swOk==2){
      analogWrite(RED, 0);
      analogWrite(GREEN, val/4);
      analogWrite(BLUE, 0);
//      beep();
    }

    else if(swOk==3){
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, val/4);
//      beep();
    }

    else{
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
 //     beep();
      swOk=0;
    }
  }

  else{
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
  }
}
