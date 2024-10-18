#define camBienPin A2  
#define IN1 7  
#define IN2 6  
#define IN3 5  
#define IN4 8  

unsigned long rePhaiThoiGian; 
bool dangRePhai = false;       

void setup() {
  pinMode(camBienPin, INPUT); 
  pinMode(IN1, OUTPUT);         
  pinMode(IN2, OUTPUT);         
  pinMode(IN3, OUTPUT);         
  pinMode(IN4, OUTPUT);         
  Serial.begin(9600);           
}

void loop() {
  int camBien = digitalRead(camBienPin); 

  Serial.print("Cảm biến: "); 
  Serial.println(camBien);  

  if (camBien == 0 && !dangRePhai) { 
    rePhai();                        
    rePhaiThoiGian = millis();      
    dangRePhai = true;               
  }
  if (dangRePhai) {
    if (millis() - rePhaiThoiGian >= 1000) {
      dungLai(); 
      while (true);
    }
  } else {
    diThang();
  }

  delay(100); 
}

void diThang() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
}

void rePhai() {
  digitalWrite(IN1, HIGH);  
  digitalWrite(IN2, LOW);   
  digitalWrite(IN3, LOW);   
  digitalWrite(IN4, HIGH);  
}

void dungLai() {
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
