//Primero declaramos dos puertos de cuatro pines, uno para cada dígito

int arrayOne [] = {2,3,4,5};
int arrayTwo [] = {6,7,8,9};

const int buttonPin1 = 10;
const int buttonPin2 = 11;
const int buttonPin3 = 12;

//Después indicamos que esos pines son SALIDAS usando un bucle for
int a=0;
int b=0;
int sw=0;

void setup()
{
for (int pin = 0; pin < 4; pin++)
  {
  pinMode(arrayOne[pin], OUTPUT);
  pinMode(arrayTwo[pin], OUTPUT);
  }
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}
void loop()
{
  if(digitalRead(buttonPin1)==  HIGH){
    sw=1;
  }else{
    if(digitalRead(buttonPin2)==  HIGH){
    sw=0;
  }else{
    if(digitalRead(buttonPin3)==  HIGH){
    a=0;
    b=0;
    displayBinary(a);
    displayBinary1(b);
    delay(500);
    sw=0;
  }
  }
  }
  
  if(sw){
    if(a==9){
       a=0;
       if(b==9){
         b=0;
       }
       else{
         b=b+1;
       }
     }
     else{
       a=a+1;
     }
     displayBinary(a);
     displayBinary1(b);
     delay(500);
  }
}

//displayBinary es la función que representa los números binarios
//Se tendrá que repetir la función una vez por cada dígito que tengamos
//Cambiando lo que fuera necesario en cada caso

void displayBinary(byte numToShow)
{
  for (int i = 0; i < 4; i++)
  {
    if (bitRead(numToShow, i)==1)
    {
      digitalWrite(arrayOne[i], HIGH);
    }
    else
    {
      digitalWrite(arrayOne[i], LOW);
    }
  }
}

void displayBinary1(byte numToShow1)
{
  for (int x = 0; x <4; x++)  {
    if (bitRead(numToShow1, x)==1)
    {
      digitalWrite(arrayTwo[x], HIGH);
    }
    else
    {
      digitalWrite(arrayTwo[x], LOW);
    }
  }
} 
