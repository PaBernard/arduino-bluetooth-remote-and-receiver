#include <Servo.h>

Servo pulsweite, pulsfrequenz, powerLinks, powerRechts;

int weite, frequenz, links, rechts, check;

void setup()
{
  Serial.begin(9600);
  pulsweite.attach(11);
  pulsfrequenz.attach(10);
  powerLinks.attach(9);
  powerRechts.attach(6);
}

void loop()
{
  while (Serial.available() > 0) {
    check = Serial.parseInt();
    weite = Serial.parseInt();
    frequenz = Serial.parseInt();
    links = Serial.parseInt();
    rechts = Serial.parseInt();

    //first val declares which element will be mapped
    //second and third declars the value of the potentiometer
    //fourth and fith, start and end of the servo
    weite = map(weite, 0, 1023, 0, 180);
    frequenz = map(frequenz, 0, 1023, 0, 180);
    links = map(links, 0, 1023, 0, 180);
    rechts = map(rechts, 0, 1023, 0, 180);
if(check == 486248){
    pulsweite.write(weite);
    pulsfrequenz.write(frequenz);
    powerLinks.write(links);
    powerRechts.write(rechts);

    delay(15);
    }
  }
}

