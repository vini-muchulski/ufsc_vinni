#include <Servo.h>

Servo meuServo;
int angulo;

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial a 9600 bps
  meuServo.attach(9);  // Anexa o servo ao pino 9
 // meuServo.write(90);  // Inicializa o servo no ângulo de 90 graus
}

void loop() {
  if (Serial.available() > 0) {
    angulo = Serial.parseInt();  // Lê o valor enviado pela serial
    if (angulo >= 0 && angulo <= 180) {  // Verifica se o valor está entre 0 e 180 graus
      meuServo.write(angulo); 
      delay(2000); 
    }
  }
}
