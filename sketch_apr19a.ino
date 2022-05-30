void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float val1=analogRead(A1);
  float val2=analogRead(A2);
  float x =(val1/1023)*5;
  float y =(val2/1023)*5;
  int per1=(x/5)*100;
  int per2=(y/5)*100;
  Serial.println(per1);
  Serial.println(per2);
  delay(1000);
  Checking(per1,per2);
  //delay(1000);
  Charging(per1,per2);
  //delay(1000);
}

void Checking(int per1,int per2)
{
if(per1<per2)
{
  digitalWrite(2,LOW);
  digitalWrite(4,HIGH); 
  digitalWrite(7,LOW);
}
else if(per2<per1)
{
  digitalWrite(4,LOW);
  digitalWrite(2,HIGH); 
  digitalWrite(7,HIGH);
}
else if(per1=per2)
{
  digitalWrite(4,LOW);
  digitalWrite(2,HIGH); 
  digitalWrite(7,HIGH);
}
}  
/*if(per1<per2)
{
  digitalWrite(2,LOW);
  digitalWrite(4,HIGH); 
}
else if(per2<per1)
{
  digitalWrite(4,LOW);
  digitalWrite(2,HIGH); 
}
else if(per1=per2)
{
  digitalWrite(4,LOW);
  digitalWrite(2,HIGH); 
}*/

void Charging(int per1,int per2)
{
  /*if(per1 <= per2)
  {
    if(digitalRead(2)==LOW)
    {
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
    }
    else
    {
      digitalWrite(12,LOW);
      digitalWrite(13,HIGH);
    v c 
    }
  }
    else
    {
      digitalWrite(12,LOW);
      digitalWrite(13,HIGH);
    }*/
if(digitalRead(2)==LOW && digitalRead(4)==HIGH)
{
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
}
else if(digitalRead(4)==LOW && digitalRead(2)==HIGH)
{
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
}   
else
{
  Serial.println("NOT WORKING");
}
}
