const int encoderPinA = 19;
const int encoderPinB = 20;
volatile int64_t currentPosition = 0;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode (encoderPinA, INPUT);
  pinMode (encoderPinB, INPUT);
  attachInterrupt (digitalPinToInterrupt (encoderPinA), readEncoderA, CHANGE);
  attachInterrupt (digitalPinToInterrupt (encoderPinB), readEncoderB, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.println((long)currentPosition);
   delay(10);
}
void readEncoderA()
{
  if (digitalRead(encoderPinA) != digitalRead(encoderPinB))
  {
    currentPosition++;
  }
  else
  {
    currentPosition--;
  }
}
void readEncoderB()
{
  if (digitalRead(encoderPinA) == digitalRead(encoderPinB))
  {
    currentPosition++;
  }
  else
  {
    currentPosition--;
  }
}
