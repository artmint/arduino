#include <AFMotor.h>
#include <LiquidCrystal.h>
//motor
double passos_total = 512; 
int porta_motor = 2; 
int angulo = 90; 
double numero_de_passos = 0; 
AF_Stepper arduino(passos_total, porta_motor);
//motor
//LDR
#define I8 A8
const int analogInPin = I8;
int sensorValue = 0;
int outputValue = 0;
//LDR
//Display
const int numRows = 2;
const int numCols = 16;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int l=0;
int p=0;
//Display


void setup(){
  arduino.setSpeed(10);
  Serial.begin(9600);
  lcd.begin(numCols,numRows);
}
  
void loop(){
  lcd.setCursor(numCols - 16,numRows - 1);
  lcd.write("Latas: "+ l);
  lcd.setCursor(numCols - 16,numRows);
  lcd.write("PET:   "+ p);
  if(SensorLuz() > 20 && SensorLuz() < 100){
    l = l + 1;
    lcd.setCursor(numCols - 16,numRows - 1);
    lcd.write("Latas: "+ l);
    CMotoresI();
  }
  if(SensorLuz() > 200 && SensorLuz() < 400){
    p = p + 1;
    lcd.setCursor(numCols - 16,numRows);
    lcd.write("PET:   "+ p);
    CMotoresD();
  }
}

int SensorLuz(){
  sensorValue = analogRead(analogInPin); 
  outputValue = map(sensorValue, 0, 1023, 0, 255); 
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\toutput = ");
  Serial.println(outputValue);
  return sensorValue;
}

void CMotoresI(){
  numero_de_passos = angulo / (360 / passos_total);
  Serial.println(numero_de_passos);
  //Move o motor. Use FORWARD para sentido horario,
  //BACKWARD para anti-horario
  arduino.step(numero_de_passos, FORWARD, SINGLE);
  arduino.release();
  delay(100);
}

void CMotoresD(){
  numero_de_passos = angulo / (360 / passos_total);
  Serial.println(numero_de_passos);
  //Move o motor. Use FORWARD para sentido horario,
  //BACKWARD para anti-horario
  arduino.step(numero_de_passos, BACKWARD, SINGLE);
  arduino.release();
  delay(100);
}


