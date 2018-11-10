int MOTOR_A_PWM = 2;
int MOTOR_A_DIR = 3;
int MOTOR_B_PWM = 4;
int MOTOR_B_DIR = 5;

long unsigned int pos = 0;    // variables to store the servo position 
long unsigned int secondPos = 0;
 
// the actual values for "fast" and "slow" depend on the motor
#define PWM_SLOW 50  // arbitrary slow speed PWM duty cycle
#define PWM_FAST 200 // arbitrary fast speed PWM duty cycle
#define DIR_DELAY 1000 // brief delay for abrupt motor changes

void setup() {
  // put your setup code here, to run once:
//  Serial.begin( 9600 );
  pinMode( MOTOR_A_DIR, OUTPUT );
  pinMode( MOTOR_A_PWM, OUTPUT );
  digitalWrite( MOTOR_A_DIR, LOW );
  digitalWrite( MOTOR_A_PWM, LOW );
    
  pinMode( MOTOR_B_DIR, OUTPUT );
  pinMode( MOTOR_B_PWM, OUTPUT );
  digitalWrite( MOTOR_B_DIR, LOW );
  digitalWrite( MOTOR_B_PWM, LOW );
}

void loop() {
  // put your main code here, to run repeatedly:
    pos = pulseIn(A0, HIGH);
    secondPos = pulseIn(A1,HIGH);
//    Serial.println(pos);
    if (pos > 1600){
      digitalWrite(MOTOR_A_DIR, HIGH);
      analogWrite(MOTOR_A_PWM, 255-PWM_FAST);
    }else{
      digitalWrite(MOTOR_A_DIR,LOW);
      analogWrite(MOTOR_A_PWM, 0);
    }
    
    if (secondPos > 1600){
      digitalWrite(MOTOR_B_DIR, HIGH);
      analogWrite(MOTOR_B_PWM, 255-PWM_FAST);
    }else{
      digitalWrite(MOTOR_B_DIR, LOW);
      analogWrite(MOTOR_B_PWM, 0);
    }
}
