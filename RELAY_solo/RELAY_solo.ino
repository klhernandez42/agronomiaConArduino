const int control = 3 ;

void setup()
{
  pinMode(control,  OUTPUT) ;
}
void loop()
{
  digitalWrite(control, HIGH);
  delay(1000);
  digitalWrite(control, LOW);
  delay(1000);
}
