char data = 1;
int led = 9;           // the PWM pin the LED is attached to
int brightness = 30;    // how bright the LED is
int fadeAmount = 2;    // how many points to fade the LED by

void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(6, OUTPUT);        //Sets digital pin 13 as output pin
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}
void loop()
{
  if (Serial.available() > 0) {
    data = Serial.read();
  }
  
  if(data == '1') {
    light();
  } else if(data == '2') {
    clear();
  }
}

void light()
{
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);

  analogWrite(9, brightness);
  
  brightness = brightness + fadeAmount;
Serial.println(brightness);
  if (brightness == 30 || brightness == 240) {
    fadeAmount = -fadeAmount;
    delay (250);
  }

  delay(20);
}

void clear()
{
  analogWrite(9, 0);
  digitalWrite(6, LOW);  //If value is 1 then LED turns ON
  digitalWrite(7, LOW);  //If value is 1 then LED turns ON
  digitalWrite(8, LOW);  //If value is 1 then LED turns ON
}
