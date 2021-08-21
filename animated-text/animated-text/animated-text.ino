//include the library:
#include <LiquidCrystal.h>

//initialize arduino pin number with lcd
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  //setup lcd
  lcd.begin(16, 2);

}

void delayClear() {
    delay(200);
    lcd.clear();   
}

void loop() {
    int i;
   
    // start animation //character visible one by one
    lcd.setCursor(0,0);
    lcd.print("U");
    delayClear();
    
    lcd.print("IU");
    delayClear();
     
    lcd.print("DIU");
    delayClear(); 
    
    // continue animation.
    for(i = 1; i < 16; i++) {
      lcd.setCursor(i,0);
      lcd.print("DIU");
      delay(200);
      lcd.clear();  
    }
}

