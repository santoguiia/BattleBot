#include "BluetoothSerial.h"
#define pin1 27   //Roxo
#define pin2 13   //Cinza
#define pin3 25   //Verde
#define pin4 26   //Amarelo

BluetoothSerial SerialBT;
char comando = '0';
float velocidade = 125;

void acionaMotor(float pwmPin1,float pwmPin2,float pwmPin3,float pwmPin4)
{
  analogWrite(pin1, pwmPin1);
  analogWrite(pin2, pwmPin2);
  analogWrite(pin3, pwmPin3);
  analogWrite(pin4, pwmPin4);
}

void setup() 
{
  //Serial.begin(9600);
  //btSerial.begin(9600);
  SerialBT.begin("Combate");
  
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  
  //Serial.println("Fim Setup");
  delay(2000); 
 }
 
void loop() 
{
  if (SerialBT.available()) 
  {
    comando = SerialBT.read();
  }
  //Serial.println(comando);
  switch (comando)
  {
    case 'F': 
    { 
      //move para frente
      acionaMotor(velocidade,0,velocidade,0);
      //Serial.println("Frente");   //Debug
      break;
    }
    case 'B': 
    { 
      //move para tras
      acionaMotor(0,velocidade,0,velocidade);
      //Serial.println("Tras");   //Debug
      break;
    }
    case 'L':
    { 
      //move esquerda
      acionaMotor(velocidade,0,0,0);
      //Serial.println("Esquerda");   //Debug
      break;
    }
    case 'R': 
    { 
      //move direita
      acionaMotor(0,0,velocidade,0);
      //Serial.println("Direita");   //Debug
      break;
    }
    case 'G':
    { 
      //move esquerda + frente
      acionaMotor(velocidade,0,velocidade/2,0);
      //Serial.println("Esquerda + Frente");   //Debug
      break;
    }
    case 'I': 
    { 
      //move direita + frente
      acionaMotor(velocidade/2,0,velocidade,0);
      //Serial.println("Direita + Frente");   //Debug
      break;
    }
    case 'H':
    { 
      //move esquerda + tras
      acionaMotor(0,velocidade,0,velocidade/2);
      //Serial.println("Esquerda");   //Debug
      break;
    }
    case 'J': 
    { 
      //move direita + tras
      acionaMotor(0,velocidade/2,0,velocidade);
      //Serial.println("Direita");   //Debug
      break;
    }
    case 'S':
    {
      acionaMotor(0,0,0,0);
      //Serial.println("STOP");   //Debug
      break;
    }
    case '1':
    {
      velocidade = 25;
      break;
    }
    case '2':
    {
      velocidade = 50;
      break;
    }
    case '3':
    {
      velocidade = 75;
      break;
    }
    case '4':
    {
      velocidade = 100;
      break;
    }
    case '5':
    {
      velocidade = 125;
      break;
    }
    case '6':
    {
      velocidade = 150;
      break;
    }
    case '7':
    {
      velocidade = 175;
      break;
    }
    case '8':
    {
      velocidade = 200;
      break;
    }
    case '9':
    {
      velocidade = 225;
      break;
    }
    case 'q':
    {
      velocidade = 255;
      break;
    }
    
    default:
    {
      acionaMotor(0,0,0,0);
      //Serial.println("erro");   //Debug
      break;
    }
  }
  
  delay(10);
}
