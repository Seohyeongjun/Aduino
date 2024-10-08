#define Cds A0
#define PWM_LED 9

void setup() {
  Serial.begin(9600);
  pinMode(Cds, INPUT);
  pinMode(PWM_LED, OUTPUT);

}

void loop() {
  char led;
  int value = analogRead(Cds);
  Serial.println(value);
  Serial.println(value);

  if(value>1000)
    led=value/4;
  else if(value>980 && value<=1000)
    led=value/7;  
  else if(value>950 && value<=980)
    led=value/10;   
  else if(value>930 && value<=950)
    led=value/10;  
  else if(value>900 && value<=930)
    led=value/13;
  else if(value>870 && value<=900)
    led=value/16;   
  else if(value>850 && value<=870)
    led=value/19;
  else if(value>830 && value<=850)
    led=value/22; 
  else if(value>800 && value<=830)
    led=value/25;   
  else if(value>780 && value<=800)
    led=value/28;
  else if(value>750 && value<=780)
    led=value/31;    
  else if(value>730 && value<=750)
    led=value/34;
  else
    led=value/40;  




  analogWrite(PWM_LED, led);

  delay(500);  
}
