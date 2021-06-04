#include <Servo.h>
#include <math.h>

Servo testbenchServo; //Define an object  

// Define Excitation Cycles
// Level defines the mean height
// Exication defines the stroke which surrounds the mean height

double levelA = 5;
double excitationA = 1;
int repetitionA = 20;

double levelB = 23;
double excitationB = 1;
int repetitionB = 5;

double levelC = -5;
double excitationC = 1;
int repetitionC = 10;

double levelD = -23;
double excitationD = 1; 
int repetitionD = 20;

// Define frequence

double frequence = 10;
double dlay = (1/frequence)* 1000;

// Define the stroke from the servo

int radius = 24; //mm


double getAngle(double height){ //mm -> deg
  double ratio = height/radius;
  double angle = acos(ratio) * 180 / M_PI;
  return angle;
}


void setup() {
  Serial.begin(9600); // Use serial monitor for troubleshooting
  delay(100);
  while (!Serial) {
    ;
  }
  
  testbenchServo.attach(9); // Signal on Arduino pin 9
}

void loop() {

  // Check if the level and excitation is in bounce - Due to 180° limits of servos
  if (  
    levelA - excitationA < -24 || levelA + excitationA > 24 ||
    levelB - excitationB < -24 || levelB + excitationB > 24 ||
    levelC - excitationC < -24 || levelC + excitationC > 24 ||
    levelD - excitationD < -24 || levelD + excitationD > 24
    ){while(1){}}
  
  for(int i = 0; i < repetitionA; i ++){
    testbenchServo.write(getAngle(levelA + excitationA));
    delay(100);    
    testbenchServo.write(getAngle(levelA - excitationA));
    delay(100);         
  }  
  
  for(int i = 0; i < repetitionB; i ++){
    testbenchServo.write(getAngle(levelB + excitationB));
    delay(dlay);    
    testbenchServo.write(getAngle(levelB - excitationB));
    delay(dlay);         
  }
  
  for(int i = 0; i < repetitionC; i ++){
    testbenchServo.write(getAngle(levelC + excitationC));
    delay(dlay);    
    testbenchServo.write(getAngle(levelC - excitationC));
    delay(dlay);         
  }
  
  for(int i = 0; i < repetitionD; i ++){
    testbenchServo.write(getAngle(levelD + excitationD));
    delay(dlay);    
    testbenchServo.write(getAngle(levelD - excitationD));
    delay(dlay);         
  }  
}
