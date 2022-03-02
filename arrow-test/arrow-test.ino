//OPITION TEST

//CODIGO DE TESTE PARA O AR100 
//INCLUI: SELECAO TOTAL DE MENU

//ULTIMA MODIFICAÇÃO EM: 02/03/2022 03:35
//CODIGO FEITO POR: MARCOS PAULO TORTATO

//#include <LiquidCrystal_I2C.h> Modulo I2c
#include <LiquidCrystal.h>

int rs = 12, en = 11, db4 = 5, db5 = 4, db6 = 3, db7 = 2;
LiquidCrystal lcd{rs,en,db4,db5,db6,db7};
int i,poten,button;
boolean menu = 0, subMenu1 = 0, subMenu2 = 0, subMenu3 = 0, subMenu4 = 0;
int nobugtime = 100;


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
      lcd.setCursor(18, 0);
      lcd.print(" ");//Clear Down
      lcd.setCursor(0, 2);
      lcd.print(" ");//Clear up 
      lcd.setCursor(0, 3); 
      lcd.write(6);//print  
    break;

    case 4:
      lcd.setCursor(18, 0); 
      lcd.write(6);//print 
      lcd.setCursor(0, 3);
      lcd.print(" ");//Clear up  
    break;
    
  }
  
}

void subRequisito(){
  if(!menu){
    lcd.setCursor(1,0);
    lcd.print("1-Rpm               ");
    lcd.setCursor(1,1);
    lcd.print("2-Temp. Motor       ");
    lcd.setCursor(1,2);
    lcd.print("3-Vol. Bat          ");
    //clear
    lcd.setCursor(1,3);
    lcd.print("4-All info          ");
    
  }//Menu principal

  if(subMenu1 == 1){
    lcd.setCursor(1,0);
    lcd.print("Menu-1          ");
    lcd.setCursor(19,0);
    lcd.print("X");
    //clear
    lcd.setCursor(1,1);
    lcd.print("                    ");
    lcd.setCursor(1,2);
    lcd.print("                    ");
    lcd.setCursor(1,3);
    lcd.print("                    ");
    
  }//Sub menu 1

  if(subMenu2 == 1){
    lcd.setCursor(1,0);
    lcd.print("Menu-2              ");
    lcd.setCursor(19,0);
    lcd.print("X");
    //clear
    lcd.setCursor(1,1);
    lcd.print("                    ");
    lcd.setCursor(1,2);
    lcd.print("                    ");
    lcd.setCursor(1,3);
    lcd.print("                    ");
    
  }//Sub menu 2

  if(subMenu3 == 1){
    lcd.setCursor(1,0);
    lcd.print("Menu-3              ");
    lcd.setCursor(19,0);
    lcd.print("X");
    //clear
    lcd.setCursor(1,1);
    lcd.print("                    ");
    lcd.setCursor(1,2);
    lcd.print("                    ");
    lcd.setCursor(1,3);
    lcd.print("                    ");
    
  }//Sub menu 3

  if(subMenu4 == 1){
    lcd.setCursor(1,0);
    lcd.print("Menu-4              ");
    lcd.setCursor(19,0);
    lcd.print("X");
    //clear
    lcd.setCursor(1,1);
    lcd.print("                    ");
    lcd.setCursor(1,2);
    lcd.print("                    ");
    lcd.setCursor(1,3);
    lcd.print("                    ");
    
  }//Sub menu 4
  
}

void loop(){
  poten = map(analogRead(A1),0,1023,0,15);
  button = digitalRead(8);
  arrowPosition();
  subRequisito();


// SOLICITAÇOES ----------


    //Sub 1 ----------
    if(poten == 0 && button == 1 && menu == 0){
      delay(nobugtime);
      menu = !menu;//menu == 1 
      subMenu1 = 1;
      
      }//solicita sub menu 1

    if(poten >= 4 && button == 1 && subMenu1 == 1){
      delay(nobugtime);
      menu = 0;
      subMenu1 = 0;
      subMenu2 = 0;
      subMenu3 = 0;
      subMenu4 = 0;
      
    }//voltar menu principal

    //Sub 2 ----------
    if(poten == 1 && button == 1 && menu == 0){
      delay(nobugtime);
      menu = !menu;//menu == 1 
      subMenu2 = 1;
      
      }//solicita sub menu 2

    if(poten >= 4 && button == 1 && subMenu2 == 1){
      delay(nobugtime);
      menu = 0;
      subMenu1 = 0;
      subMenu2 = 0;
      subMenu3 = 0;
      subMenu4 = 0;
      
    }//voltar menu principal

    //Sub 3 ----------
    if(poten == 2 && button == 1 && menu == 0){
      delay(nobugtime);
      menu = !menu;//menu == 1 
      subMenu3 = 1;
      
      }//solicita sub menu 2

    if(poten >= 4 && button == 1 && subMenu3 == 1){
      delay(nobugtime);
      menu = 0;
      subMenu1 = 0;
      subMenu2 = 0;
      subMenu3 = 0;
      subMenu4 = 0;
      
    }//voltar menu principal
    
    //Sub 4 ----------
    if(poten == 3 && button == 1 && menu == 0){
      delay(nobugtime);
      menu = !menu;//menu == 1 
      subMenu4 = 1;
      
      }//solicita sub menu 2

    if(poten >= 4 && button == 1 && subMenu4 == 1){
      delay(nobugtime);
      menu = 0;
      subMenu1 = 0;
      subMenu2 = 0;
      subMenu3 = 0;
      subMenu4 = 0;
      
    }//voltar menu principal
    
    
}//Space|          |
