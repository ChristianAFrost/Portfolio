
// Relay pin is controlled with D8. The active wire is connected to Normally OPEN and common
int relayOne = 8;
int relayTwo = 7;
const int buttonOne = 2;
int buttonState = 0;
int pint = 13;



void setup() {
  // Pin for relay module set as output
  Serial.begin(9600);
  pinMode(relayOne, OUTPUT);
  pinMode(relayTwo, OUTPUT);
  pinMode(buttonOne, INPUT);
  digitalWrite(relayOne, HIGH);
  digitalWrite(relayTwo, HIGH);
  //Serial.print("Please enter a number");
  
}

void relayON() {

  //Serial.println("Relay ON");
  digitalWrite(relayOne, LOW);
  digitalWrite(relayTwo, LOW);
  delay(1000);
}

void relayOFF()
{
  //Serial.println("Relay OFF");
  digitalWrite(relayOne, HIGH);
  digitalWrite(relayTwo, HIGH);
  delay(1000);
}

void Test()
{
  buttonState = digitalRead(buttonOne);
  if (buttonState == HIGH)
  {
    relayON();
  }
  else
  {
    relayOFF();
  }
}

void AS()
{
  while(Serial.available() == 0){
  }
  int num = Serial.parseInt();
  switch(num)
  {
    case 1:
      Serial.print("ONEEEEEEE");
      relayON();
      break;

    case 2:
      Serial.print("ZEROOOOOOO");
      relayOFF();
      break;

    default:
      Serial.print("NOT WORKING");

  }
}

void ASt()
{
  int num = digitalRead(buttonState);
  if (num == 1)
  {
    digitalWrite(relayOne, num);
  }
  else
  {
    digitalWrite(relayTwo, num);
  }
  /*
  switch(num)
  {
    case 1:
      Serial.print("ONEEEEEEE");
      relayON();
      break;

    case 2:
      Serial.print("ZEROOOOOOO");
      relayOFF();
      break;

    default:
      Serial.print("NOT WORKING");

  }
  */
}

/*
 
  */

void ASth()
{
    //read the pushbutton value into a variable
  int sensorVal = digitalRead(buttonOne);
  //print out the value of the pushbutton
  Serial.println(sensorVal);

  // Keep in mind the pullup means the pushbutton's
  // logic is inverted. It goes HIGH when it's open,
  // and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:

  digitalWrite(pint, sensorVal);

  if (sensorVal == HIGH) {
    
    digitalWrite(relayOne, LOW);
    digitalWrite(relayTwo, LOW);
    Serial.print("ON");
  } 
  
  
  else {
    digitalWrite(relayOne, HIGH);
    digitalWrite(relayTwo, HIGH);
    Serial.print("OFF");
  }
}
  
void loop() {
  relayOFF();
  
  while (digitalRead(buttonOne) == 0);
  relayON();
  
  while (digitalRead(buttonOne) == 0);
}
  


