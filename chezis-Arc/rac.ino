
void TurnLeft90Deg() {
    while ( digitalRead(matTrai) != HIGH ) {
      analogWrite(IN1, 100);
      analogWrite(IN2, 0);
      analogWrite(IN3, 0);
      analogWrite(IN4, 100);
      delay(10);
    }
    stopMotors();
    return;
}

void TurnRight90Deg() {
    while ( digitalRead(matPhai) != HIGH ) {
      analogWrite(IN1, 0);
      analogWrite(IN2, 100);
      analogWrite(IN3, 100);
      analogWrite(IN4, 0);
      delay(10);
    }
    stopMotors();
    return;
}

void arc_Run() {
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

void lineTrackingOld() {
  while ( true ) {
    if ( digitalRead(matGiua) != HIGH && digitalRead(matTrai) != HIGH && digitalRead(matPhai) != HIGH ) {
      stopMotors();
      delay(5);
      runMotors("trai", 20, 125);
    } else if ( digitalRead(matGiua) == HIGH ) { // Mắt giữa
      runMotors("truoc", 120, 255);
    } else if ( digitalRead(matTrai) == HIGH ) { // Mắt trái
      runMotors("phai", 30, 125);
    } else if ( digitalRead(matPhai) == HIGH ) { // Mắt phải
      runMotors("trai", 30, 125);
    }  
  }
}

void lineTracking2() {
  while (true) {
    if (digitalRead(matGiua) == HIGH) {
      runMotors("truoc", 100, 150); 
    } else if (digitalRead(matTrai) == HIGH) {
      runMotors("trai", 50, 100); 
    }
    else if (digitalRead(matPhai) == HIGH) {
      runMotors("phai", 50, 100);
    } else {
      stopMotors();
    }
    delay(10);
  }
}