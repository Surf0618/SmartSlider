void runMotor(int enablePin, int ln1Pin, int ln2Pin, boolean foward, boolean on);
 int enablePin = 9;
 int ln1Pin = 6;
 int ln2Pin = 3;
  
void setup() 
{
  // put your setup code here, to run once:

  pinMode(enablePin, OUTPUT);
  pinMode(ln1Pin, OUTPUT);
  pinMode(ln2Pin, OUTPUT);
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
  runMotor(enablePin, ln1Pin, ln2Pin, true, true);  
  delay(2000);
  runMotor(enablePin, ln1Pin, ln2Pin, false, true);  
  delay(2000);

}

void runMotor(int enablePin, int ln1Pin, int ln2Pin, boolean foward, boolean on)
{ 
  if( on == true)
  {
    digitalWrite(enablePin, HIGH);
        if( foward == true)
        {
            digitalWrite(ln1Pin, LOW);
            digitalWrite(ln2Pin, HIGH);
        }
        else
        {
             digitalWrite(ln1Pin, HIGH);
             digitalWrite(ln2Pin, LOW);
        }
  }
  else
  {
    digitalWrite(enablePin, LOW);
    digitalWrite(ln1Pin, LOW);
    digitalWrite(ln2Pin, LOW);
  }
    
}

