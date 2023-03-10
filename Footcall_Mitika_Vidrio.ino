#include <NewPing.h>

//#define TRIGGER_PIN1  6     //Sensor del medio, para cuando es solo una direccion
//#define ECHO_PIN1     7     
#define TRIGGER_PIN2  5   //Sensor de subida, cercano al arduino
#define ECHO_PIN2     4  
#define TRIGGER_PIN3  8  //Sensor de bajada, alejado del arduino
#define ECHO_PIN3     9
#define RELAYS        3 
#define RELAYB        2
#define MAX_DISTANCE 200
#define LED           10

//NewPing sonar1(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE);

int contador1 = 0;
int contador2 = 0;
int contador3 = 0;
float dist_set = 50;

void setup() {
  
  Serial.begin(115200);
  pinMode(RELAYS,OUTPUT);
  pinMode(RELAYB,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(2,OUTPUT);
  digitalWrite(RELAYS,LOW);
  digitalWrite(RELAYB,LOW);
  digitalWrite(10,LOW);

SetDistance();

}

void(* resetFunc) (void) = 0; //declare reset function @ address 0

 void SetDistance(){
  float dist = (0.034027/2)*sonar3.ping_median(10);
  Serial.print("El footcall esta a esta distancia: ");
  Serial.println(dist);
 // dist_set = dist - 1;
  Serial.print("y se activa a esta: ");
  Serial.println(dist_set);
  digitalWrite(10,HIGH);
  delay(100);
  digitalWrite(10,LOW);
  delay(100);
  digitalWrite(10,HIGH);
  delay(100);
  digitalWrite(10,LOW);
  delay(100);
  digitalWrite(10,HIGH);
  delay(100);
  digitalWrite(10,LOW);
}

void loop() {
  delay(50);
//float distancia1 = (0.034027/2)*sonar1.ping_median(10);
float distancia2 = (0.034027/2)*sonar2.ping_median(10);
float distancia3 = (0.034027/2)*sonar3.ping_median(10);

  //Serial.print("Distancia 1: ");
  //Serial.println(distancia1);
  Serial.print("Distancia 2: ");
  Serial.println(distancia2);
  Serial.print("Distancia 3: ");
  Serial.println(distancia3);
  
//Sensor del medio
/*
 if ( distancia1 == 0 || distancia1 > 15){
    digitalWrite(RELAYS,LOW);
    digitalWrite(RELAYB,LOW);
    digitalWrite(10,LOW);
    Serial.println("NADA"); 
    contador1 = 0;
  }

  if ( distancia1 > 0 && distancia1 < 15 && contador1 < 50){
    digitalWrite(RELAYS,HIGH);
    digitalWrite(RELAYB,HIGH);
    digitalWrite(10,HIGH);
   // Serial.println("SUBE");
    contador1++;
    Serial.println("contador1");
    Serial.println(contador1); 
  }  

//Verificar si el boton leva mas de 30 segundos activado

  if (  distancia1 > 0 && distancia1 < 15 && contador1 >= 50){
    Serial.println("Boton trabado");
    //resetFunc();  //call reset
    digitalWrite(RELAYS,LOW);
    digitalWrite(RELAYB,LOW);
    digitalWrite(10,LOW);
    contador1++;
    
  }

// Si lleva mas de 1 minuto, se resetea el modulo
  if ( contador1 > 150 ){
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW);
    delay(500);
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW);
    Serial.println("Reseteando");
    delay(2000);
    resetFunc();  //call reset
  }  */

//si no se oprime ninguno de los dos botones

    if ( distancia2 == 0 || distancia2 > dist_set && distancia3 == 0 || distancia3 > dist_set){
    digitalWrite(RELAYS,LOW);
    digitalWrite(RELAYB,LOW);
    digitalWrite(10,LOW);
    Serial.println("NADA"); 
    contador2 = 0;
    contador3 = 0;
  }

  
  //Sensor subiendo cercaNO AL ARDUINO

//  if ( distancia2 == 0 || distancia2 > dist_set ){
//    digitalWrite(RELAYS,LOW);
//    digitalWrite(RELAYB,LOW);
//    digitalWrite(10,LOW);
//    Serial.println("NADA"); 
//    contador2 = 0;
//  }
//  
    if ( distancia2 > 0 && distancia2 < dist_set && contador2 < 50){
      Serial.println("Sensor 1 activo");
    digitalWrite(RELAYS,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(2,HIGH);
    contador2++;
    Serial.println("contador-2");
    Serial.println(contador2);
  }

//Verificar si el boton leva mas de 30 segundos activado

//  if (  distancia2 > 0 && distancia2 < dist_set && contador2 >= 50){
//    Serial.println("Boton trabado");
//    //resetFunc();  //call reset
//    digitalWrite(RELAYS,LOW);
//    digitalWrite(10,LOW);
//    digitalWrite(2,LOW);
//    contador2++;
//  }

// Si lleva mas de 1 minuto, se resetea el modulo
  if ( contador2 > 150 ){
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW);
    delay(500);
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW);
    Serial.println("Reseteando");
    delay(2000);
    resetFunc();  //call reset
  }  



  //Sensor Bajando

//    if ( distancia3 == 0 || distancia3 > 15){
//    digitalWrite(RELAYB,LOW);
//    digitalWrite(10,LOW);
//    Serial.println("NADA"); 
//    contador3 = 0;
//  }
  
    if ( distancia3 > 0 && distancia3 < dist_set && contador3 < 50){
      Serial.println("Sensor 2 activo");
    digitalWrite(RELAYS                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(2,HIGH);
   // Serial.println("SUBE");
       contador3++;
    Serial.println("contador3");
    Serial.println(contador3);
  }

//Verificar si el boton leva mas de 30 segundos activado

//  if (  distancia3 > 0 && distancia3 < dist_set && contador3 >= 50){
//    Serial.println("Boton trabado");
//    //resetFunc();  //call reset
//    digitalWrite(RELAYB,LOW);
//    digitalWrite(10,LOW);
//    digitalWrite(2,LOW);
//    contador3++;
//  }

// Si lleva mas de 1 minuto, se resetea el modulo
  if ( contador3 > 150 ){
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW);
    delay(500);
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW);
    Serial.println("Reseteando");
    delay(2000);
    resetFunc();  //call reset
  }  
}
