#include <Keypad.h>
#include <Password.h>
#include <AFMotor.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','U'},
  {'4','5','6','D'},
  {'7','8','9','F'},
  {'C','0','H','E'}
};
byte rowPins[ROWS] = {30, 32, 34, 36}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {38, 40, 42, 44}; //connect to the column pinouts of the keypad
Password password = Password( "26789" ); 
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


double passos_total = 512; //Numero de passos para 1 rotacao total
 
int porta_motor = 2; //1 para motor em M1/M2 e 2 para motor em M3/M4
int angulo = 90; //Angulo de rotacao do eixo
 
double numero_de_passos = 0; //Armazena o numero de passos que o motor vai girar
 
AF_Stepper arduino(passos_total, porta_motor); //Define os parametros do motor



#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


#define melodyPin 50
//Mario main theme melody
int melody[] = {
  NOTE_E7, NOTE_E7,
};
//Mario main them tempo
int tempo[] = {
  12, 12,
};

//

//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5,
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12,
};

  


void setup(){
  arduino.setSpeed(10);
  Serial.begin(9600);
  pinMode(50, OUTPUT);//buzzer
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey != NO_KEY){
    Serial.print("tecla ");
    Serial.println(customKey);
    delay(10);
    switch (customKey) {
            case 'E': checkPassword(); delay(1); break;    // Enter password
            case 'C': password.reset(); delay(1); break;   // Clear buffer
            default: password.append(customKey); delay(1);       // add key to password
    }
  }
}

void checkPassword() {  
    if (password.evaluate()) {                             // if password is right open box
        Serial.println("Accepted");
        delay(10);   
        password.reset(); delay(1);
        sing(1); 
        CMotores();
        
    } else {
        Serial.println("Denied");                          // if passwords wrong keep box locked
        delay(10);
        password.reset(); delay(1);
        sing(2);  
    }
}
void CMotores(){
  numero_de_passos = angulo / (360 / passos_total);
 
//Mostra no serial monitor o numero de passos calculados
Serial.println(numero_de_passos);
 
//Move o motor. Use FORWARD para sentido horario,
//BACKWARD para anti-horario
arduino.step(numero_de_passos, FORWARD, SINGLE);
arduino.release();
 
delay(2000);
}




int song = 0;

void sing(int s){      
   // iterate over the notes of the melody:
   song = s;
   if(song==2){
     Serial.println(" 'Underworld Theme'");
     int size = sizeof(underworld_melody) / sizeof(int);
     for (int thisNote = 0; thisNote < size; thisNote++) {

       // to calculate the note duration, take one second
       // divided by the note type.
       //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
       int noteDuration = 1000/underworld_tempo[thisNote];

       buzz(melodyPin, underworld_melody[thisNote],noteDuration);

       // to distinguish the notes, set a minimum time between them.
       // the note's duration + 30% seems to work well:
       int pauseBetweenNotes = noteDuration * 1.30;
       delay(pauseBetweenNotes);

       // stop the tone playing:
       buzz(melodyPin, 0,noteDuration);

    }

   }else{

     Serial.println(" 'Mario Theme'");
     int size = sizeof(melody) / sizeof(int);
     for (int thisNote = 0; thisNote < size; thisNote++) {

       // to calculate the note duration, take one second
       // divided by the note type.
       //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
       int noteDuration = 1000/tempo[thisNote];

       buzz(melodyPin, melody[thisNote],noteDuration);

       // to distinguish the notes, set a minimum time between them.
       // the note's duration + 30% seems to work well:
       int pauseBetweenNotes = noteDuration * 1.30;
       delay(pauseBetweenNotes);

       // stop the tone playing:
       buzz(melodyPin, 0,noteDuration);

    }
  }
}

void buzz(int targetPin, long frequency, long length) {
  long delayValue = 1000000/frequency/2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length/ 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to 
  //// get the total number of cycles to produce
  for (long i=0; i < numCycles; i++){ // for the calculated length of time...
    digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
}
