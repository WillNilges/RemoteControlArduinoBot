// wired connections
#define HG7811_A_IA 2 // D2 --> Motor A Input A --> MOTOR A +
#define HG7881_A_IB 3 // D3 --> Motor A Input A --> MOTOR A -

#define HG7881_B_IA 4 // D10 --> Motor B Input A --> MOTOR B +
#define HG7881_B_IB 5 // D11 --> Motor B Input B --> MOTOR B -
 
// functional connections

#define MOTOR_A_PWM HG7881_A_IA // Motor A PWM Speed
#define MOTOR_A_DIR HG7881_A_IB // Motor A Direction

#define MOTOR_B_PWM HG7881_B_IA // Motor B PWM Speed
#define MOTOR_B_DIR HG7881_B_IB // Motor B Direction
 
// the actual values for "fast" and "slow" depend on the motor
#define PWM_SLOW 50  // arbitrary slow speed PWM duty cycle
#define PWM_FAST 200 // arbitrary fast speed PWM duty cycle
#define DIR_DELAY 1000 // brief delay for abrupt motor changes

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600 );
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
  pos=pulseIn(A0, HIGH);
    secondPos=pulseIn(A1,HIGH);
//    Serial.println(pos);
    if (pos > 1400){
      digitalWrite(MOTOR_A_DIR, HIGH)
      analogWrite(MOTOR_A_PWM, 255-PWM_FAST);
    }else{
      analogWrite(MOTOR_A_PWM, 0);
    }
    
    if (pos < 1200){
      digitalWrite(MOTOR_B_DIR, HIGH)
      analogWrite(MOTOR_B_PWM, 255-PWM_FAST);
    }else{
      analogWrite(MOTOR_B_PWM, 0);
    }
}
