/*
       < ARDUINO PRO MICRO >
             
            |TX0   RAW| Batteries +
            |RX1   GND| Batteries -
            |GND   RST|
            |GND   VCC| 5V
       IN1  |2     #A3| 
       IN2  |3~    #A2| 
       IN3  |4#    #A1| 
       IN4  |5~    #A0| 
            |6~#    15|
            |7      14| 
            |8#     16| 
            |9~#  #~10| 
~ PWM
# Analog
*/

byte paso[8] = {B00100000, B00110000, B00010000, B00011000, B00001000, B00001100, B00000100, B00100100};
byte i = 0;

void setup()
{
  DDRD = DDRD|B00111100;
}

void loop()
{
  PORTD = paso[i/32];
  i += 32;
  delay(100);
}
  
  
  
