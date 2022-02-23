#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET 4
#define PAUSE 1000

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);//I2C
  display.fillScreen(BLACK);
  display.display();

  //Animacao de start
  closeFace();
  delay(1000);
  display.clearDisplay();

}

void padraoFace(){
  display.fillRoundRect(20, 7, 30, 15, 4, 1);
  display.fillRoundRect(78, 7, 30, 15, 4, 1);
  display.display();

}

void rightFace(){
  display.fillRoundRect(30, 7, 30, 15, 4, 1);
  display.fillRoundRect(88, 7, 30, 15, 4, 1);
  display.display();

}

void leftFace(){
  display.fillRoundRect(10, 7, 30, 15, 4, 1);
  display.fillRoundRect(68, 7, 30, 15, 4, 1);
  display.display();

}

void closeFace(){
  display.fillRoundRect(20, 15, 30, 2, 0, 1);
  display.fillRoundRect(78, 15, 30, 2, 0, 1);//15 para descer ao centro 
  display.display();

}

void animate(){
  padraoFace();
  delay(1000);
  display.clearDisplay();
  closeFace();
  delay(100);
  display.clearDisplay();
  leftFace();
  delay(500);
  display.clearDisplay();
  closeFace();
  delay(100);
  display.clearDisplay();
  padraoFace();
  delay(1000);
  display.clearDisplay();
  closeFace();
  delay(100);
  display.clearDisplay();
  rightFace();
  delay(500);
  display.clearDisplay();
  closeFace();
  delay(100);
  display.clearDisplay();
  
}

void loop() {
  animate();

}
