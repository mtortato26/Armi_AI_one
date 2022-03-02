//#include <LiquidCrystal_I2C.h> Modulo I2c
#include <LiquidCrystal.h>

int rs = 12, en = 11, db4 = 5, db5 = 4, db6 = 3, db7 = 2;
LiquidCrystal lcd{rs,en,db4,db5,db6,db7};
int i,poten,button;
boolean valuePage = 0, menu = 0, subMenu1 = 0;
int nobugtime = 500;


byte arrowIcon[8] = {
  B10000,
  B11000,
  B11100,
  B11110,
  B11110,
  B11100,
  B11000,
  B10000,
};

void setup(){
  lcd.begin(20,4);
  pinMode(A1, INPUT);
  pinMode(8, INPUT_PULLUP);//button
  lcd.createChar(6, arrowIcon);
  lcd.write(6);
  Serial.begin(9600);
}

void arrowPosition(){
  switch(poten){
    case 0:
      lcd.setCursor(0, 1);
      lcd.print(" ");
      lcd.setCursor(0, 0); 
      lcd.write(6);  
    break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.print(" ");//Clear up 
      lcd.setCursor(0, 1);
      lcd.write(6);//print   
      lcd.setCursor(0, 2);
      lcd.print(" ");//Clear Down  
    break;

    case 2:
      lcd.setCursor(0, 1);
      lcd.print(" ");//Clear up 
      lcd.setCursor(0, 2); 
      lcd.write(6);//print
      lcd.setCursor(0, 3);
      lcd.print(" ");//Clear Down 
    break;

    case 3:
      lcd.setCursor(0, 2);
      lcd.print(" ");//Clear up 
      lcd.setCursor(0, 3); 
      lcd.write(6);//print  
    break;
    
  }
  
}

void subRequisito(){
  if(!menu){
    lcd.setCursor(1,0);
    lcd.print("1-Menu          ");
    lcd.setCursor(1,1);
    lcd.print("2-Menu          ");
    
  }//imprime menu principal || menu == 0 aparece

  if(subMenu1 == 1){
    lcd.setCursor(1,0);
    lcd.print("Menu-1          ");
    lcd.setCursor(1,1);
    lcd.print("Exit          ");
    
  }//imprime sub menu || subMenu1 == 0 aparece
  
}

void loop(){
  poten = map(analogRead(A1),0,1023,0,10);
  int button = digitalRead(8);
  arrowPosition();
  subRequisito();

    if(poten == 0 && button == 1 && menu == 0){
      delay(nobugtime);
      menu = !menu;//menu == 1 
      subMenu1 = 1;
      
      }//solicita sub menu

    if(poten == 1 && button == 1 && subMenu1 == 1){
      delay(nobugtime);
      menu = 0;//menu == 0
      subMenu1 = 0;
      
    }//solicita menu principal dentro do sub menu
    
}//Space|          |
