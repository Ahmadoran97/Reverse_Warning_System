const int trigPin = 10;
const int echoPin = 9;
const int Buzzer = 2;

float duration;
float Distance;

void setup() 
{
  pinMode(Buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  Distance = (duration*.0343)/2;

  Serial.print("The Distance is: ");
  Serial.print(Distance);
  Serial.println("cm");
  delay(100);
  
  if (Distance < 10)
    {
     digitalWrite(Buzzer, HIGH);
    }

  else
    { 
      digitalWrite(Buzzer, LOW);
    }    
}
