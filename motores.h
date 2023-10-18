// nombramos los pines
int motor_A1 = 14; // pin motor A1
int motor_A2 = 12; // pin motor A2
int pin_vel_A = 15; // pin control de velocidad motor A

int motor_B1 = 4; // pin motor B1
int motor_B2 = 5; // pin motor B2
int pin_vel_B = 13; // pin control de velocidad motor A

int SPEED_A = 80; //velocidades
int SPEED_B = 80;

  
/** motors setup
 * @brief Función que configura inificalmente los motores
 */
void motors_setup()
{
  // configuramos el motor A como salida (OUTPUT)
  pinMode(motor_A1, OUTPUT); // motor A1
  pinMode(motor_A2, OUTPUT); // motor A2
  pinMode(pin_vel_A, OUTPUT); // control velocidad A
  
  // configuramos el motor B como salida (OUTPUT)
  pinMode(motor_B1, OUTPUT); // motor B1
  pinMode(motor_B2, OUTPUT); // motor B2
  pinMode(pin_vel_B, OUTPUT); // control velocidad B
  
  // partimos con el motor A apagado (LOW)
  digitalWrite(motor_A1, LOW); // motor A1
  digitalWrite(motor_A2, LOW); // motor A2

  // partimos con el motor B apagado (LOW)
  digitalWrite(motor_B1, LOW); // motor A1
  digitalWrite(motor_B2, LOW); // motor A2
}

/** motor Foward Backward
 * @brief Función controla el movimiento hacia adelante o hacia atrás de los motores.
 * @param dir1 es un valor de verdad (true o false) que permite elegir una dirección
 */
void motor_FWBW(bool dir1)
{ 
    
  if (dir1) {
    digitalWrite(motor_A1, LOW);
    digitalWrite(motor_A2, HIGH);
    analogWrite(pin_vel_A, SPEED_A);
    digitalWrite(motor_B1, LOW);
    digitalWrite(motor_B2, HIGH);
    analogWrite(pin_vel_B, SPEED_B);
  }
  else {
    digitalWrite(motor_A1, !LOW);
    digitalWrite(motor_A2, !HIGH);
    analogWrite(pin_vel_A, SPEED_A);
    digitalWrite(motor_B1, !LOW);
    digitalWrite(motor_B2, !HIGH);
    analogWrite(pin_vel_B, SPEED_B);
  }

}
/** motor Left Right 
 * @brief Función controla el giro hacia la derecha o izquierda de los motores.
 * @param dir2 es un valor de verdad (true o false) que permite elegir una dirección
 */
void motor_LR(bool dir2) {
  if (dir2) {
    digitalWrite(motor_A1, !LOW);
    digitalWrite(motor_A2, !HIGH);
    analogWrite(pin_vel_A, SPEED_A);
    digitalWrite(motor_B1, LOW);
    digitalWrite(motor_B2, HIGH);
    analogWrite(pin_vel_B, SPEED_B);
  }
  else {
    digitalWrite(motor_A1, LOW);
    digitalWrite(motor_A2, HIGH);
    analogWrite(pin_vel_A, SPEED_A);
    digitalWrite(motor_B1, !LOW);
    digitalWrite(motor_B2, !HIGH);
    analogWrite(pin_vel_B, SPEED_B);
  }
}

/** Motor Stop
 * @brief Función que detiene los motores
 */
void motor_stop(void)
{
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, LOW);
  analogWrite(pin_vel_A, 0);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, LOW);
  analogWrite(pin_vel_B, 0);
}

// Motor Forward Right
void motor_FR(void) {

  digitalWrite(motor_A1, HIGH);
  digitalWrite(motor_A2, LOW);
  analogWrite(pin_vel_A, 150);
  digitalWrite(motor_B1, HIGH);
  digitalWrite(motor_B2, LOW);
  analogWrite(pin_vel_B, 255);
}

// Motor Forward Left
void motor_FL(void) {

  digitalWrite(motor_A1, HIGH);
  digitalWrite(motor_A2, LOW);
  analogWrite(pin_vel_A, 255);
  digitalWrite(motor_B1, HIGH);
  digitalWrite(motor_B2, LOW);
  analogWrite(pin_vel_B, 150);
}

// Motor Backward Right
void motor_BR(void) {

  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, HIGH);
  analogWrite(pin_vel_A, 150);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, HIGH);
  analogWrite(pin_vel_B, 255);
}

// Motor Backward Left
void motor_BL(void) {

  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, HIGH);
  analogWrite(pin_vel_A, 255);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, HIGH);
  analogWrite(pin_vel_B, 150);
}