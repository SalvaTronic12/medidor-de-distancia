#include <Adafruit_SH1106.h>
#include <SPI.h>

int echo = 8;
int trig = 9;

#define OLED_RESET 4

Adafruit_SH1106 display(OLED_RESET);


void setup() {
 Serial.begin(9600);
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);

 SPI.begin();
 display.begin(SH1106_SWITCHCAPVCC, 0x3C);
 
}

void loop() {
  long t;
  long d;

  
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);

 t = pulseIn(echo,HIGH);

 d = (t/2)/29;


display.clearDisplay();
display.setRotation(0);
display.setTextColor(WHITE);
display.setTextSize(2);
display.setCursor(5,5);
display.println("DISTANCIA:");
display.setCursor(35,30);
display.println(d);
display.setCursor(60,30);
display.println(" CM");
display.display();

delay(500);
}
