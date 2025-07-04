#define IN1 8
#define IN2 9
#define ENA 12

#define IN3 10
#define IN4 11
#define ENB 5

#define P 13

#define matGiua 44  // Mắt giữa
#define matPhai 46  // Mắt phải
#define matTrai 45  // Mắt trái

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(P, OUTPUT);

  digitalWrite(ENA, HIGH);  // Bật ENA
  digitalWrite(ENB, HIGH);  // Bật ENB

  pinMode(matGiua, INPUT);  // Thiết lập chân tín hiệu là input
  pinMode(matTrai, INPUT);  // Thiết lập chân tín hiệu là input
  pinMode(matPhai, INPUT);  // Thiết lập chân tín hiệu là input
  Serial.begin(9600);       // Khởi động Serial để in kết quả
}

void loop() {
  digitalWrite(P, HIGH);
  delay(1000);
  blinkTimes(3);

  // Force Default Color
  runMotors("phai", 120, 150);
  delay(100);
  runMotors("truoc", 1000, 255);

  // Chạy tới khi mắt giữa thấy line đen
  while (digitalRead(matGiua) != HIGH) {
    runMotors("truoc", 10, 100);
  }

  // Force nhích
  runMotors("truoc", 550, 100);

  // Xoay phải till track được line
  while (digitalRead(matPhai) != HIGH) {
    runMotors("phai", 10, 100);
  }

  vaoNgaTu();

  while (true);
}

void vaoNgaTu() {
  while ( true ) {
    if ( digitalRead(matGiua) == HIGH && digitalRead(matTrai) == HIGH || 
    digitalRead(matGiua) == HIGH && digitalRead(matPhai) == HIGH || 
    digitalRead(matGiua) == HIGH && digitalRead(matTrai) == HIGH && digitalRead(matPhai) == HIGH ) {
      stopMotors();
      break;
    }
    runMotors("truoc", 20, 125);
  }
  
  //Force Nhích để vào ngã 4
  runMotors("truoc", 365, 125);
  delay(100);
  // blinkTimes(4);
  queo("trai");

}

void blinkTimes(int in) {
  for (int i = 0; i < in; i++) {
    digitalWrite(P, LOW);
    delay(100);
    digitalWrite(P, HIGH);
    delay(100);
  }
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void queo(String s) {
  if ( s.equalsIgnoreCase("trai") ) {
    analogWrite(IN1, 175);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, 175);
    delay(370);
    stopMotors();
    return;
  }
  if ( s.equalsIgnoreCase("phai") ) {
    analogWrite(IN1, 175);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, 175);
    delay(370);
    stopMotors();
    return;
  }
}

void runMotors(String s, int time, int speed) {

  if (s.equalsIgnoreCase("sau")) {
    analogWrite(IN1, speed);
    digitalWrite(IN2, LOW);
    analogWrite(IN3, speed);
    digitalWrite(IN4, LOW);
    delay(time);
    stopMotors();
    return;
  }

  if (s.equalsIgnoreCase("truoc")) {
    digitalWrite(IN1, LOW);
    analogWrite(IN2, speed);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, speed);
    delay(time);
    stopMotors();
    return;
  }

  if (s.equalsIgnoreCase("trai")) {
    analogWrite(IN1, speed);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, speed);
    delay(time);
    stopMotors();
    return;
  }

  if (s.equalsIgnoreCase("phai")) {
    digitalWrite(IN1, LOW);
    analogWrite(IN2, speed);
    analogWrite(IN3, speed);
    digitalWrite(IN4, LOW);
    delay(time);
    stopMotors();
    return;
  }
}
