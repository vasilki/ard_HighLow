#include <math.h>
int led = 8;
int pin_sin= 13;
int gl_grad = 0;
#define COEFF (float)255.0/180.0

float grad_to_rad(float par_grad)
{
  return par_grad*3.1415/180.0;
}

void setup()

{

pinMode(led, OUTPUT);
Serial.begin(9600);

}


void HighLow()
{
  static int value;
  static unsigned int loc_takt = 0;
  if((loc_takt % 2) == 0)
  {
    value = 100;
  }
  else
  {
    value = 0;
  }
  //Serial.println(value);
  analogWrite(pin_sin,100);
  //delay(3);
  delayMicroseconds(100);
  loc_takt++;
  return;  
}

void send_discrete_1(float par_delay)
{
  static bool value = false;
  value = !value;
  Serial.println((int)value);
  delay(par_delay);
  digitalWrite(led, value);
  return;
}

void send_discrete_2(bool par_bool, float par_delay)
{
  Serial.println((int)par_bool);
  delay(par_delay);
  digitalWrite(led, par_bool);
  return;
}

void send_discrete_3(bool par_bool, float par_delay)
{
  int loc_value;
  Serial.println((int)par_bool);
  delay(par_delay);
  if(par_bool == false)
  {
    loc_value = 0;
  }
  else
  {
    loc_value = 250;
  }
  analogWrite(pin_sin, loc_value);
  return;
}

void loop()

{
  /*
  int data;
  static bool loc_bool=false;
  if(Serial.available() > 0)
  {
    data = Serial.read();
    loc_bool = (bool)((data%2)!=0);
    send_discrete_3(loc_bool,0.0);
  }
*/
  HighLow();

}
