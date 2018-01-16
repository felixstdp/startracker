/*
       < ARDUINO PRO MICRO >
             
            |TX0   RAW| Batteries +
            |RX1   GND| Batteries -
            |GND   RST|
            |GND   VCC| 5V
            |2     #A3| IN1
            |3~    #A2| IN2
            |4#    #A1| IN3
            |5~    #A0| IN4
            |6~#    15|
            |7      14| 
            |8#     16| 
            |9~#  #~10| 
~ PWM
# Analog
*/

// una rotación = 86163581 milisegundos

const int dientes = 60;
const int gap = 86163581000 / 64 / 4 / dientes;
byte paso[4] = {B1100, B0110, B0011, B1001};
byte i = 0;
unsigned long now=micros();

void setup()
{
  DDRF = DDRF|B00001111;
}

void loop()
{
  if (micros()-now >= gap)
  {
    now = micros();
    PORTF = paso[i>>6];
    i += 64;
  }  
} 
  
