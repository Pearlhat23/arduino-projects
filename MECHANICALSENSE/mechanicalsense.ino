int echoPin = 10;
int vibratorPin = 13;
int triggerPin = 9;

int maxDistance = 10000;

void setup(){
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(vibratorPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(triggerPin, HIGH);
  digitalWrite(triggerPin, LOW);
  int pulseWidth = pulseIn(echoPin, HIGH, maxDistance);
  Serial.println(pulseWidth);
  if((pulseWidth <= 300) || pulseWidth >= maxDistance){
    pulseWidth = maxDistance;
  }
  pulseWidth = map(pulseWidth, 300, 10000, 200, 100);
  analogWrite(vibratorPin, pulseWidth);
}

