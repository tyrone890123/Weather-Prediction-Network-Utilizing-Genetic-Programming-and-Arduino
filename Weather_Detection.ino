#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
#define buttonPin1 2
#define buttonPin2 3
#define ledPin 8
#define clk 5
#define dat 6
#define rst 7

LiquidCrystal_I2C lcd(0x27, 16, 2);  
virtuabotixRTC myRTC(clk, dat, rst);
DHT dht(DHTPIN, DHTTYPE);
int buttonState1 = 0;         
int buttonState2 = 0;
int screen = 1;
int ctr=0;
int tick = 0;
int start = 0;

void setup()
{
  dht.begin();     
  lcd.init();      
  lcd.backlight();
  myRTC.setDS1302Time(00, 5, 12, 5, 7, 4, 2022);
 
  TIMSK2|=(1<<OCIE2A); 
  TCCR2B|=(1<<CS22);
  sei(); 
  OCR2A=0x0F9; 

  pinMode(A0, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{

  int potVal;
  potVal = analogRead(A0);
  potVal = map(potVal, 0, 1023, 0, 5);
 
  float humi  = dht.readHumidity();    
  float tempC = dht.readTemperature();
 
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
 
  if(buttonState1 == HIGH){
    screen = 1;
  }else if(buttonState2 == HIGH){
    screen = 2;
  }

  if(humi>=81+potVal){
    if(start==0){
      tick=0;
      ctr=0;
      start=1;
    }
  }

  if(start==1){
    if(ctr<10){
      if(tick>=1000){
        if(ctr%2==0){
          digitalWrite(ledPin, HIGH);  
        }else{
          digitalWrite(ledPin, LOW);
        }
        ctr++;
      }
    }else{
      start=0;
      digitalWrite(ledPin, LOW);
    }
  }

  if(screen==1){
    lcd.clear();
    // check if any reads failed
    lcd.setCursor(0, 0);  
    lcd.print("T: ");
    lcd.print(tempC);    
    lcd.print("C");
    lcd.print("  S: ");
    lcd.print(potVal);

    lcd.setCursor(0, 1);  
    lcd.print("H: ");
    lcd.print(humi);      
    lcd.print("%");

    delay(2000);
  }else if(screen==2){
     lcd.clear();
     myRTC.updateTime();
     lcd.setCursor(0,0);
     lcd.print("Date: ");
     lcd.print(myRTC.dayofmonth);
     lcd.print("/");
     lcd.print(myRTC.month);
     lcd.print("/");
     lcd.print(myRTC.year);
     lcd.setCursor(0,1);
     lcd.print("Time: ");
     lcd.print(myRTC.hours);
     lcd.print(":");
     lcd.print(myRTC.minutes);
     lcd.print(":");
     lcd.print(myRTC.seconds);
     delay(1000);
  }
}

ISR(TIMER2_COMPA_vect){    
  tick++;
}
