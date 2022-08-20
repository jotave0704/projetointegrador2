//Projeto Integrador 2 - Engenharia Elétrica - 6ª Fase
//Alunos: Arthur Ferreira, João Victor de Souza e Juan Carlos
//Sistema pick to light

//Bibliotecas utilizadas

#include <Wire.h>                             // biblioteca wire 
#include <Arduino.h>                          // biblioteca arduino, para programar com VSCODE

//Definições

  //Definições endereços da comunicação I2C com o arduino
#define display_1 0x20                         // endereço do display 1
#define display_2 0x21                         // endereço do display 2
#define display_3 0x22                         // endereço do display 3
#define display_4 0x23                         // endereço do display 4
#define display_5 0x24                         // endereço do display 5
#define display_6 0x25                         // endereço do display 6
#define display_7 0x26                         // endereço do display 7
#define display_8 0x27                         // endereço do display 8

//Variavéis Globais
int endDisplay;                               // variável do endereço do display
int dadoDisplay;                              // variável do dado do display

void setup()
{  
  Serial.begin(9600);
  Wire.begin(); // inicializa a interface I2C   
}

void pcf8574Write(byte address, byte data )   // envia dado para PCF8574 - interface I2C
{
  Wire.beginTransmission(address);            // envia o endereço do PCF8574
  Wire.write(data);                           // envia o dado para o PCF8574
  Wire.endTransmission();                     // termina transmissão
}

char displayNumber (int dec)
{
  if (dec == 0)
  {
    return 0x81; // mostra número 0    
  }
  if (dec == 1)
  {
    return 0xCF; // mostra número 1   
  }
  if (dec == 2)
  {
    return 0x92;// mostra número 2   
  }
  if (dec == 3)
  {
    return 0x86; // mostra número 3   
  }
  if (dec == 4)
  {
    return 0xCC; // mostra número 4   
  }
  if (dec == 5)
  {
    return 0xA4; //mostra número 5    
  }
  if (dec == 6)
  {
    return 0xA0; //mostra número 6    
  }
  if (dec == 7)
  {
    return 0x8F; // mostra número 0    
  }
  if (dec == 8)
  {
    return 0x80; // mostra número 0    
  }
  if (dec == 9)
  {
    return 0x8C; // mostra número 0    
  }
  return 0;
}

void printDisplay ()                                 // mostra algarismos em 2 displays
{  
      pcf8574Write(0x21, displayNumber (6));  

}

void loop()
{ 

for(int x = 0;x < 10;x++){
pcf8574Write(0x20, displayNumber (x));
pcf8574Write(0x21, displayNumber (x+1));
delay(1000);
}
  
}
