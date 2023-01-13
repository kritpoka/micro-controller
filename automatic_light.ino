const int TrigerPin = 8;
const int echoPin = 9;
const int relay = 6;

long duration;
int distance;
int n;

void setup() {
  pinMode(TrigerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  dis();
  if(distance < 50){
    n = 1;
    while (n == 1){
      on(distance);
      n = n+1;
      delay(1000);
      while (n == 2){
        distwo();
        off(distance);
        n = n-1;
      }
    }
  }
}


void on (int distance) {
 if(distance < 50){
  digitalWrite(relay,1);
 }
 }

void off (int distance) {
 if(distance < 50){
  digitalWrite(relay,0);
 }
 }

void dis (){
  digitalWrite(TrigerPin, LOW);
  delay(100);

  digitalWrite(TrigerPin, HIGH);
  delay(100);
  digitalWrite(TrigerPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
}

void distwo (){
  digitalWrite(TrigerPin, LOW);
  delay(100);

  digitalWrite(TrigerPin, HIGH);
  delay(100);
  digitalWrite(TrigerPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
}
  
