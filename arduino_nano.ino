#define trigPin 2
#define echoPin 3
#define buzzerPin 5
#define redLedPin 12
#define yellowLedPin 9
#define greenLedPin 6

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.println("Jarak: " + String(distance) + " cm");

  if (distance <= 2) {
    // Nyala Hijau, Kuning, Merah
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

  } else if (distance <= 4) {
    // Nyala Hijau, Kuning, Merah Kedip
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    blinkRed(redLedPin);
    blinkRed(buzzerPin);

  } else if (distance <= 6) {
    // Nyala Hijau, Kuning
    digitalWrite(greenLedPin, HIGH);
    Yellow(yellowLedPin);
    Yellow(buzzerPin);
    digitalWrite(redLedPin, LOW);  

  } else if (distance <= 8) {
    // Nyala Hijau, Kuning Kedip
    digitalWrite(greenLedPin, HIGH);
    blinkYellow(yellowLedPin);
    blinkYellow(buzzerPin);
    digitalWrite(redLedPin, LOW);  

  } else if (distance <= 10) {
    // Nyala Hijau
    Green(greenLedPin);
    Green(buzzerPin);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);

  } else if (distance <= 12) {
    // Kedip Hijau
    blinkGreen(greenLedPin);
    blinkGreen(buzzerPin);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    
  } else if (distance >= 12) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  }
  delay(150);
}

void blinkRed(int pin) {
  digitalWrite(pin, HIGH);
  delay(100);
  digitalWrite(pin, LOW);
  delay(100);
}

void Yellow(int pin) {
  digitalWrite(pin, HIGH);
  delay(200);
  digitalWrite(pin, LOW);
  delay(200);
}

void blinkYellow(int pin) {
  digitalWrite(pin, HIGH);
  delay(300);
  digitalWrite(pin, LOW);
  delay(300);
}

void Green(int pin) {
  digitalWrite(pin, HIGH);
  delay(400);
  digitalWrite(pin, LOW);
  delay(400);
}

void blinkGreen(int pin) {
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);
}
