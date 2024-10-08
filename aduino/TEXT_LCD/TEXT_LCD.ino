#include <LiquidCrystal_I2C.h>

//#define DHT 7

//DHT dht11(DHT);
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte a[8]={   // 도
  B00000,
  B11111,
  B10000,
  B10000,
  B11111,
  B00100,
  B00100,
  B11111
};

byte b[8]={   // 온
  B01110,
  B10001,
  B01110,
  B00100,
  B11111,
  B00000,
  B10000,
  B11111
};

byte c[8]={   // 습
  B00100,
  B01010,
  B10001,
  B11111,
  B10001,
  B11111,
  B10001,
  B11111
};

byte s_1[8]={
  B00000,
  B00000,
  B00000,
  B00100,
  B00100,
  B01100,
  B01010,
  B11001
};

byte s_2[8]={
  B00000,
  B00100,
  B00010,
  B00010,
  B00010,
  B00010,
  B11110,
  B00010
};

byte s_3[8]={
  B10001,
  B10001,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte s_4[8]={
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00000,
  B00000
};

byte h_1[8]={
  B00000,
  B01000,
  B00100,
  B11111,
  B00000,
  B01110,
  B10001,
  B10001,
};

byte h_2[8]={
  B00000,
  B00100,
  B00010,
  B00010,
  B00010,
  B11110,
  B00010,
  B11110
};

byte h_3[8]={
  B01110,
  B00000,
  B00000,
  B00011,
  B00100,
  B00100,
  B00011,
  B00000
};

byte h_4[8]={
  B00010,
  B00010,
  B00000,
  B10000,
  B01000,
  B01000,
  B10000,
  B00000
};

byte j_1[8]={
  B00000,
  B00000,
  B01111,
  B00001,
  B00010,
  B00100,
  B01000,
  B00000,
};

byte j_2[8]={
  B00000,
  B00000,
  B11100,
  B10000,
  B01000,
  B00100,
  B00000,
  B00000
};

byte j_3[8]={
  B11111,
  B00001,
  B00001,
  B00001,
  B01000,
  B01000,
  B00111,
  B00000
};

byte j_4[8]={
  B11110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11100,
  B00000
};

void setup() {
  lcd.init();
  lcd.backlight();
  
  // lcd.createChar(0, b);   // 온
  // lcd.createChar(1, c);   // 습
  // lcd.createChar(2, a);   // 도

  // lcd.createChar(3, s_1);
  // lcd.createChar(4, s_2);
  // lcd.createChar(5, s_3);
  // lcd.createChar(6, s_4);

  lcd.createChar(7, h_1);
  lcd.createChar(8, h_2);
  lcd.createChar(9, h_3);
  lcd.createChar(10, h_4);
  
  lcd.createChar(11, j_1);
  lcd.createChar(12, j_2);
  lcd.createChar(13, j_3);
  lcd.createChar(14, j_4);
}
static int i=0;

void loop() {
  // lcd.setCursor(0, 0);
  // lcd.print("I am    ");
  // lcd.setCursor(0, 1);
  // lcd.print("hj");
  
  lcd.setCursor(0, 0);
//  lcd.write(3);
//  lcd.write(4);

  lcd.write(7);
  lcd.write(8);

  lcd.write(11);
  lcd.write(12);

  lcd.setCursor(0, 1);
//  lcd.write(5);
//  lcd.write(6);

  lcd.write(9);
  lcd.write(10);

  lcd.write(13);
  lcd.write(14);
  

  // if(i!=0){
  //   for(;i>0; i--){
  //     lcd.scrollDisplayLeft();
  //     delay(600);
  //   }
  // }

  delay(2000);
//  }

  // lcd.clear();
  // lcd.print("hahaha");
  // for(; i<16; i++){
  //   lcd.scrollDisplayRight();
  //   delay(600);

}

/*
  lcs_i2c 함수

  init() : lcd 초기화 함수 - setup에서 사용
  backlight() : lcd 백라이트 켜기
  nobacklight() : lcd 백라이트 끄기
  clear() : lcd화면 지우기 - 모든 텍스트 사라지고 첫번째 줄, 첫번째 칸에 커서 위치
  home() : 커서의 위치를 맨 앞으로(첫번째 줄)
  setCursor(열, 행) : lcd 커서를 지정 위치로 이동
  print(출력내용) : lcd에 문자열, 숫자, 변수의 값 추력
  cursor() : lcd에 커서 표시, 커서가 깜빡임
  noCursor() : lcd에 커서 표시 제거
  blink() : 커서가 깜빡임
  noBlink() : 커서의 깜빡임 해제
  scrollDisplayLeft() : lcd 화면 전체를 왼쪽으로 스크롤
  scrollDisplayRight() : lcd 화면 전체를 오른쪽으로 스크롤
  autoscroll() : 텍스트 입력시 자동으로 화면 스크롤
  noAutoscroll() : 자동스크롤 해제
  createChar(위치, 픽셀크기) : 사용자 정의 문자 만들기
  write(값) : 아스키코드나 사용자정의 문자 lcd 출력

*/