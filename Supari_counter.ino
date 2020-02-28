#include <LiquidCrystal.h>
#include <DFR_LCD_Keypad.h>

// this is factory config shield initialisation
LiquidCrystal lcd(8,9,4,5,6,7); 

int L1=3, L2=4, Ldr1 = A1, Ldr2 = A2;
int v1 = 0, v2 =0;
int counted = 0,previous=0,Delay=1000;
bool countable=false;
void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
  pinMode(Ldr1,INPUT);
  pinMode(Ldr2,INPUT);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ready to Count");
}

void loop() {
  // put your main code here, to run repeatedly:
  v1 = analogRead(Ldr1);
  v2 = analogRead(Ldr2);
//  Serial.println(v2);
  if (v1 <80 || v2 <80){
    countable=true;
    Delay = 500;
  }
  if (v1>=175 || v2>=170 ){
    if (countable){
      ++counted;
      countable = false;
      Delay = 100;
    }
  }
  if (previous != counted){
    previous = counted;
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Counted : ");
    lcd.setCursor(10,0);
    lcd.print(counted);
//    Serial.print("Object counted : ");
//    Serial.println(counted);
  }
//  Serial.println(v2);
  delayMicroseconds(Delay);
}
