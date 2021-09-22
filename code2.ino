const int encoderPinA1 = 19;
const int encoderPinB1 = 18;

const int encoderPinA2 = 20;
const int encoderPinB2 = 21;

volatile long right_currentPosition = 0;
volatile long left_currentPosition = 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode (encoderPinA1, INPUT);
   pinMode (encoderPinB1, INPUT);
   attachInterrupt (digitalPinToInterrupt (encoderPinA1), readEncoderA1, CHANGE);
   attachInterrupt (digitalPinToInterrupt (encoderPinB1), readEncoderB1, CHANGE);

   pinMode (encoderPinA2, INPUT);
   pinMode (encoderPinB2, INPUT);
   attachInterrupt (digitalPinToInterrupt (encoderPinA2), readEncoderA2, CHANGE);
   attachInterrupt (digitalPinToInterrupt (encoderPinB2), readEncoderB2, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.print("RIGHT = ");
 //  Serial.println((long)right_currentPosition);

   Serial.print("LEFT = ");
   Serial.println((long)left_currentPosition);
   delay(10);
}
void readEncoderA1()
{
  if (digitalRead(encoderPinA1) != digitalRead(encoderPinB1))
  {
    right_currentPosition++;
  }
  else
  {
    right_currentPosition--;
  }
}
void readEncoderB1()
{
  if (digitalRead(encoderPinA1) == digitalRead(encoderPinB1))
  {
    right_currentPosition++;
  }
  else
  {
    right_currentPosition--;
  }
}
void readEncoderA2()
{
  if (digitalRead(encoderPinA2) != digitalRead(encoderPinB2))
  {
    left_currentPosition--;
  }
  else
  {
    left_currentPosition++;
  }
}
void readEncoderB2()
{
  if (digitalRead(encoderPinA2) == digitalRead(encoderPinB2))
  {
    left_currentPosition--;
  }
  else
  {
    left_currentPosition++;
  }
}
