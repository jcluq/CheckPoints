/*
  Analog Input
  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED)  connected to digital pin 13.
  The amount of time the LED will be on and off depends on
  the value obtained by analogRead().

  The circuit:
   Potentiometer attached to analog input 0
   center pin of the potentiometer to the analog pin
   one side pin (either one) to ground
   the other side pin to +5V
   LED anode (long leg) attached to digital output 13
   LED cathode (short leg) attached to ground

   Note: because most Arduinos have a built-in LED attached
  to pin 13 on the board, the LED is optional.


  Created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput

*/

int sensorValue;
int ledBlanco = 2;
int ledRosa = 3;
int ledRojo = 4;
int ledAmarillo = 5;
int ledVerde = 7;
int ledAzul = 6;
int actual;
bool banderas[6];
boolean llevado = true;
boolean seleccionado = true;
boolean activador0 = true;
boolean activador1 = true;
boolean activador2 = true;
boolean activador3 = true;
boolean activador4 = true;
boolean activador5 = true;
boolean activadorBase = true;
boolean celebracion =true;
int dato=0;
int tipoJuego = 0;
boolean aBase=false;
boolean celeb0=false;
boolean celeb1=false;
boolean celeb2=false;
boolean celeb3=false;
boolean celeb4=false;
boolean celeb5=false;
boolean comienzo = true;
boolean activadorComienzo =true;

#include <SPI.h>
/* Include the RFID library */
#include <RFID.h>

/* Define the DIO used for the SDA (SS) and RST (reset) pins. */
#define SDA_DIO 10
#define RESET_DIO 9
/* Create an instance of the RFID library */
RFID RC522(SDA_DIO, RESET_DIO);


void setup() {
  // declare the ledPin as an OUTPUT:
  // pinMode(ledBlanco,OUTPUT);
  //pinMode(ledRosa,OUTPUT);
  //pinMode(ledRojo,OUTPUT);
  //pinMode(ledAmarillo,OUTPUT);
  //pinMode(ledVerde,OUTPUT);
  //pinMode(ledBlanco,OUTPUT);
 pinMode(8,INPUT);
  Serial.begin(9600);
  

  for (int i = 0; i < 5; i++) {
    banderas[i] = false;
    // actual = (int(random(0,5)));
  }
  SPI.begin(); 
  /* Initialise the RFID reader */
  RC522.init();
    randomSeed(millis());
  randomSeed(random(0,1000));
  delay(random(0,1000));
 tipoJuego = digitalRead(8);


}

void loop() {
 Serial.println("ya");
  if(tipoJuego ==0){
    if(comienzo==true){
     while(activadorComienzo == true){
      digitalWrite(ledRojo,HIGH);
      delay(50);
      digitalWrite(ledRojo,LOW);
      digitalWrite(ledAmarillo,HIGH);
      delay(50);
      digitalWrite(ledAmarillo,LOW);
      digitalWrite(ledAzul,HIGH);
      delay(50);
      digitalWrite(ledAzul,LOW);
      digitalWrite(ledVerde,HIGH);
      delay(50);
      digitalWrite(ledVerde,LOW);
      digitalWrite(ledBlanco,HIGH);
      delay(50);
      digitalWrite(ledBlanco,LOW);
      digitalWrite(ledRosa,HIGH);
      delay(50);
      digitalWrite(ledRosa,LOW);
      
      
      detectar();
       if(dato== 223){
        activadorComienzo = false;
       comienzo ==false;
      
    }
  }
 }
 
}
 if(tipoJuego ==1){
    if(comienzo==true){
     while(activadorComienzo == true){
      digitalWrite(ledRosa,HIGH);
      delay(50);
      digitalWrite(ledRosa,LOW);
      digitalWrite(ledBlanco,HIGH);
      delay(50);
      digitalWrite(ledBlanco,LOW);
      digitalWrite(ledVerde,HIGH);
      delay(50);
      digitalWrite(ledVerde,LOW);
      digitalWrite(ledAzul,HIGH);
      delay(50);
      digitalWrite(ledAzul,LOW);
      digitalWrite(ledAmarillo,HIGH);
      delay(50);
      digitalWrite(ledAmarillo,LOW);
      digitalWrite(ledRojo,HIGH);
      delay(50);
      digitalWrite(ledRojo,LOW);
      
      
      
      detectar();
       if(dato== 223){
        activadorComienzo = false;
       comienzo ==false;
      
    }
  }
 }
 
}
  
  randomSeed(millis());
  
  actual = (int(random(0, 20)));
 int valp = Serial.println(digitalRead(8));
 Serial.println(valp);




  Serial.println("inicio");

  if (actual == 0) {
    if (banderas[0] == false) {
      while (activador0 == true) {
        digitalWrite(ledRosa, HIGH);
        delay(100);
        digitalWrite(ledRosa, LOW);
        delay(100);
        detectar();
        
      
        if (dato == 244) {
          Serial.println("s");
          activador0 = false;
        }
      }
    }
    banderas[0] = true;
    digitalWrite(ledRosa, HIGH);
    aBase = true;
    celeb0=true;

  }

  if (actual == 1) {
    if (banderas[1] == false) {
      while (activador1 == true) {
        digitalWrite(ledRojo, HIGH);
        delay(50);
        digitalWrite(ledRojo, LOW);
        delay(50);
        
        detectar();
        
      
        if (dato == 122) {
          Serial.println("s");
          activador1 = false;
        }
      }
    }
    banderas[1] = true;
    digitalWrite(ledRojo, HIGH);
    aBase = true;
    celeb1=true;



}

if (actual == 2) {
    if (banderas[2] == false) {
      while (activador2 == true) {
        digitalWrite(ledAmarillo, HIGH);
        delay(50);
        digitalWrite(ledAmarillo, LOW);
        delay(50);
        
          detectar();
        Serial.println(dato);
        if (dato ==207) {
          Serial.println("s");
          activador2 = false;
        }
      }
    }
    banderas[2] = true;
    digitalWrite(ledAmarillo, HIGH);
    aBase = true;
    celeb2=true;

}

if (actual == 3) {
    if (banderas[3] == false) {
      while (activador3 == true) {
        digitalWrite(ledBlanco, HIGH);
        delay(50);
        digitalWrite(ledBlanco, LOW);
        delay(50);
          detectar();
       
        if (dato == 4) {
          Serial.println("s");
          activador3 = false;
        }
      }
    }
    banderas[3] = true;
    digitalWrite(ledBlanco, HIGH);
    aBase = true;
    celeb3=true;
}

if (actual == 4) {
    if (banderas[4] == false) {
      while (activador4 == true) {
        digitalWrite(ledVerde, HIGH);
        delay(50);
        digitalWrite(ledVerde, LOW);
        delay(50);
          detectar();
        if (dato == 83) {
          Serial.println("s");
          activador4 = false;
        }
      }
    }
    banderas[4] = true;
    digitalWrite(ledVerde, HIGH);
    aBase = true;
    celeb4=true;
}

if (actual == 5) {
    if (banderas[5] == false) {
      while (activador5 == true) {
        digitalWrite(ledAzul, HIGH);
        delay(50);
        digitalWrite(ledAzul, LOW);
        delay(50);
          detectar();
        if (dato == 35) {
          Serial.println("s");
          activador5 = false;
        }
      }
    }
    banderas[5] = true;
    digitalWrite(ledAzul, HIGH);
    aBase = true;
    celeb5=true;
}

 if(tipoJuego ==1){
    if(aBase==true){
     while(activadorBase == true){
      detectar();
       if(dato== 223){
        activadorBase = false;
        aBase==false;
      
    }
  }
 }
 activadorBase=true;
}

if(celeb0==true && celeb1==true && celeb2==true  && celeb3==true && celeb4==true && celeb5==true){
  while(celebracion==true){
    digitalWrite(ledBlanco,HIGH);
    digitalWrite(ledAmarillo,HIGH);
    digitalWrite(ledAzul,HIGH);
    digitalWrite(ledRojo,HIGH);
    digitalWrite(ledVerde,HIGH);
    digitalWrite(ledRosa,HIGH);
    delay(100);
    digitalWrite(ledBlanco,LOW);
    digitalWrite(ledAmarillo,LOW);
    digitalWrite(ledAzul,LOW);
    digitalWrite(ledRojo,LOW);
    digitalWrite(ledVerde,LOW);
    digitalWrite(ledRosa,LOW);
    delay(100);
    
    
  }
}
}
void detectar()
{
  /* Has a card been detected? */
  if (RC522.isCard())
  {
    /* If so then get its serial number */
    RC522.readCardSerial();
    Serial.println("Card detected:");
    
    Serial.println(RC522.serNum[4],DEC);
    dato = RC522.serNum[4],DEC;
  
    //Serial.print(RC522.serNum[i],HEX); //to print card detail in Hexa Decimal format
    
    
    
   // Serial.println("este" + dato);
    Serial.println();
  }
  //delay(1000);
}
