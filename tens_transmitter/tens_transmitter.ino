const int powerLinks = A5;
const int powerRechts = A4;
const int pulsweite = A3;
const int pulsfrequenz = A2;

int pulsweiteValue = 0;
int pulsfrequenzValue = 0;
int powerLinksValue = 0;
int powerRechtsValue = 0;

void setup()
{

  Serial.begin(9600);

  // send a byte to establish contact until receiver responds
  establishContact();
}

void loop()
{
  if (Serial.available() > 0) {

  pulsweiteValue = analogRead(pulsweite);
  pulsfrequenzValue = analogRead(pulsfrequenz);
  powerLinksValue = analogRead(powerLinks);
  powerRechtsValue = analogRead(powerRechts);


  Serial.print(pulsweiteValue);
  Serial.print(",");
  Serial.print(pulsfrequenzValue);
  Serial.print(",");
  Serial.print(powerLinksValue);
  Serial.print(",");
  Serial.print(powerRechtsValue);
  Serial.print(",");

}
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("0,0,0");   // send an initial string
    delay(300);
  }
}

