const int trigPin = 14;
const int echoPin = 27;
int distance;
long duration;

#define ENA_PIN 33
#define ENB_PIN 32
#define MOTOR_LEFT_PIN1 25
#define MOTOR_LEFT_PIN2 26
#define MOTOR_RIGHT_PIN1 23
#define MOTOR_RIGHT_PIN2 22

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ENA_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_PIN1, OUTPUT);
  pinMode(MOTOR_LEFT_PIN2, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN1, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN2, OUTPUT);
}

// ---------------- BASIC MOTOR FUNCTIONS -----------------
void forward() {
  digitalWrite(MOTOR_LEFT_PIN1, HIGH);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);

  analogWrite(ENA_PIN, 180);
  analogWrite(ENB_PIN, 180);
}

void reverse() {
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, HIGH);

  analogWrite(ENA_PIN, 180);
  analogWrite(ENB_PIN, 180);
}

void left() {
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);

  analogWrite(ENA_PIN, 150);
  analogWrite(ENB_PIN, 150);
}

void right() {
  digitalWrite(MOTOR_LEFT_PIN1, HIGH);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);

  analogWrite(ENA_PIN, 150);
  analogWrite(ENB_PIN, 150);
}

void Stop() {
  analogWrite(ENA_PIN, 0);
  analogWrite(ENB_PIN, 0);
}

// // ---------------- SPIN FUNCTION -----------------
// void spin() {
//   left();
//   delay(1000);

//   forward();
//   delay(2000);

//   right();
//   delay(1000);

//   forward();
//   delay(2000);
// }

// ---------------- ZIG-ZAG FUNCTION -----------------
// void zigzag() {
//   left();
//   delay(100);

//   forward();
//   delay(800);

//   right();
//   delay(100);

//   forward();
//   delay(800);
// }
void zigzag() {
  
  // 1 - Move forward (long)
  forward();
  delay(3000);

  // 2 - Turn right
  right();
  delay(600);

  // 3 - Move small sideways
  forward();
  delay(600);

  // 4 - Turn right again
  right();
  delay(600);

  // 5 - Move forward (long)
  forward();
  delay(3000);

  // 6 - Turn left
  left();
  delay(600);

  // 7 - Move small sideways
  forward();
  delay(600);

  // 8 - Turn left again
  left();
  delay(600);
}

// ---------------- MAIN LOOP ------------------------
void loop() 
{
  // Trigger ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance >= 15) {
    // -------------------------
    // Run your zigzag + spin
    // -------------------------
    // spin();
    // delay(500);

    zigzag();
    delay(500);
  }
  else {
    // -------------------------
    // Obstacle detected
    // -------------------------
    Stop();
    delay(300);

    reverse();
    delay(2000);

    left();
    delay(1200);
  }
}