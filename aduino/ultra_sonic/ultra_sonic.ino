#define TRIG 11
#define ECHO 12

#define BUZZER 9
#define key 7
#define LED 8

#define RGB_R 3
#define RGB_G 5
#define RGB_B 6

int crash[3][3] = {{30, 2000,'B'}, {20, 900, 'G'}, {10, 200,'R'}};

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(key, INPUT);
  pinMode(LED, OUTPUT);

  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_G, OUTPUT);
  pinMode(RGB_B, OUTPUT);
}
void RGB(char color){
  if(color=='R'){
    digitalWrite(RGB_R, HIGH);
    digitalWrite(RGB_G, LOW);
    digitalWrite(RGB_B, LOW);

//    Serial.println("RED");
  }
  else if(color=='G'){
    digitalWrite(RGB_R, LOW);
    digitalWrite(RGB_G, HIGH);
    digitalWrite(RGB_B, LOW);

//    Serial.println("GREEN");
  }
  else if(color=='B'){
    digitalWrite(RGB_R, LOW);
    digitalWrite(RGB_G, LOW);
    digitalWrite(RGB_B, HIGH);

//    Serial.println("BLUE");
  }
}


static int swOk=0;
char key_flag=0;
int key_on=0;

void key_input(){
  int sw=0;    

if(key_on==0){
  while(1){                         // 키 입력, 디바운싱기능 추가    
    if(digitalRead(key) == LOW){   // key press down and count up for debouncing
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
      swOk^=1;
      key_on=1;
      break;
    }
  }
}
}

void loop() {
  float length, dist;
  
  Serial.print(swOk);
  Serial.println(key_on);
  
// if(swOk==0){
    key_input();
//    Serial.println(swOk);
//  }

  if(swOk==1){
    digitalWrite(TRIG, HIGH); // 초음파센서에 신호전달 - 음파 발생
    delay(10);
    digitalWrite(TRIG, LOW);  // 신호 끄기

    length = pulseIn(ECHO, HIGH); // 시간 측정
    dist = (float)(340 * length)/10000/2; // m -> cm, 편도

    if(dist < crash[2][0]){ // 거리가 10cm보다 작다면
      digitalWrite(BUZZER, HIGH);
      RGB(crash[2][2]);
      delay(crash[2][1]);
      digitalWrite(BUZZER, LOW);
      delay(crash[2][1]);
    }
    else if(dist < crash[1][0]){
      digitalWrite(BUZZER, HIGH);
      RGB(crash[1][2]);
      delay(crash[1][1]);
      digitalWrite(BUZZER, LOW);
      delay(crash[1][1]);   
    }
    else if(dist < crash[0][0]){
      digitalWrite(BUZZER, HIGH);
      RGB(crash[0][2]);
      delay(crash[0][1]);
      digitalWrite(BUZZER, LOW);
      delay(crash[0][1]);   
    }
    else{
      delay(500);

      digitalWrite(RGB_R, LOW);
      digitalWrite(RGB_G, LOW);
      digitalWrite(RGB_B, LOW);
    }
    // analogWrite(BUZZER, dist*1000);
    // delay(100);
    Serial.print(dist);
    Serial.println("cm");

    digitalWrite(LED, HIGH);    
  }

  else{
    digitalWrite(LED, LOW);

    digitalWrite(RGB_R, LOW);
    digitalWrite(RGB_G, LOW);
    digitalWrite(RGB_B, LOW);
  }
  
}
