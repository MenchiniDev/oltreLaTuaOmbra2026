//questo codice muove le ali di trilly, attivando due MG995 con un PCA
//sfruttando un ciclo hardcoded

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

const int servoChannels[7] = {0, 1, 2, 3, 4, 5, 6};

const int SERVOMINSX = 450; 
const int SERVOMAXSX = 150;

//CANALE 0 -> SERVO DESTRO
const int SERVOMINDX = 200;
const int SERVOMAXDX = 450; //SERVO DESTRA TARATO!


void setup() {
  Serial.begin(9600);
  Serial.println("Avvio del sistema...");

  Wire.begin();  // Inizializza il bus I2C
  pwm.begin();   // Inizializza il driver PCA9685
  pwm.setPWMFreq(50);  // Frequenza per il controllo dei servo (in Hz)

  delay(100);
  Serial.println("Driver PCA9685 inizializzato.");
}



void loop() {
  // Porta il servo a 0 gradi
  Serial.println("Muovo i servo a 0 gradi...");
  for (int i = 0; i < 2; i++) {
    if(i == 0){
      pwm.setPWM(servoChannels[i], 0, SERVOMINDX);
    }
    if(i == 1){
      pwm.setPWM(servoChannels[i], 0, SERVOMINSX);
    }

    Serial.print("Servo ");
    Serial.print(i);
    Serial.println(" a 0 gradi.");
  }

  delay(200); 

  for (int i = 0; i < 2; i++) {
    if(i == 0){
      pwm.setPWM(servoChannels[i], 0, SERVOMAXDX);
    }
    if(i == 1){
      pwm.setPWM(servoChannels[i], 0, SERVOMAXSX);
    }
    Serial.print("Servo ");
    Serial.print(i);
    Serial.println(" a 180 gradi.");
  }

}