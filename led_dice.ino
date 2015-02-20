int pinLeds1 = 10;
int pinLeds2 = 9;
int pinLeds3 = 7;
int pinLed4 = 8;
int buttonPin = 6;
int buttonState;
long ran;

int myDelay = 10;
int i;
int j;

void setup()
{
  for (i = pinLeds3; i < pinLeds1 + 1; i++)
    pinMode(i, OUTPUT);
  pinMode(buttonPin, INPUT);
  randomSeed(analogRead(A0));
}

void loop()
{
  buttpmState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    // emulate the rolling of the die
    myDelay = 50;
    for (i = 0; i < 30; i++)
    {
      ran = random(1, 7);
      // turn off all the pips of the die
      for (i = pinLeds3; i < pinLeds1 + 1; i++)
        digitalWrite(j, LOW);
      printDie();
      delay(myDelay);
      myDelay += 5;
    }
    // create the final result
    ran = random(1, 7);
    // again, clear the die of pips
    for (j = 6; j < 11; j++)
      digitalWrite(j, LOW);
    printDie();
  }
}

void printDie()
{
  switch (ran)
  {
      case 1:
        digitalWrite(pinLed4, HIGH);
        break;
      case 2:
        digitalWrite(pinLeds1, HIGH);
        break;
      case 3:
        digitalWrite(pinLeds3, HIGH);
        digitalWrite(pinLed4, HIGH);
        break;
      case 4:
        digitalWrite(pinLeds1, HIGH);
        digitalWrite(pinLeds3, HIGH);
        break;
      case 5:
        digitalWrite(pinLeds1, HIGH);
        digitalWrite(pinLeds3, HIGH);
        digitalWrite(pinLed4, HIGH);
        break;
      case 6:
        digitalWrite(pinLeds1, HIGH);
        digitalWrite(pinLeds2, HIGH);
        digitalWrite(pinLeds3, HIGH);
        break;
  }
}
