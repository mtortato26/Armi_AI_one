int bot = 2;
int botvar;

void setup()
{
  pinMode(bot, INPUT);
  Serial.begin(9600);
}

void loop()
{
  botvar = digitalRead(bot);
  Serial.println(botvar);
  
}
