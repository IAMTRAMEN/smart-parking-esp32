#include <HCSR04.h>
#include <ESP32Servo.h>



/* Créer un objet Servo pour contrôler le servomoteur */
Servo monServomoteur;
Servo monServomoteur1;
const int servoPin=16;
const int servoPin1=14;
const int trig1Pin = 27;
const int echo1Pin = 26;
const int trig2Pin = 17;
const int echo2Pin = 15;
int position = 180;
#define A 21
#define B 22
#define C 2
#define D 4
#define E 5
#define F 19
#define G 18
#define DP 15

// initialisation du 1er capteur avec les broches utilisees.
UltraSonicDistanceSensor distanceSensor1(trig1Pin, echo1Pin);
// initialisation du 2eme capteur avec les broches utilisees.
UltraSonicDistanceSensor distanceSensor2(trig2Pin, echo2Pin);

 
void setup(){
  Serial.begin(115200);
monServomoteur.attach(servoPin);
monServomoteur1.attach(servoPin1);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

}
void zero() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void un() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

}

void deux() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);

}

void trois() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);

}

void quatre() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

}

void cinq() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

}

void six() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

}

void sept() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

}

void huit() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

}

void neuf() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

}
 int cars=0;

void loop(){
if(((((distanceSensor1.measureDistanceCm()+1)<6)&&(distanceSensor1.measureDistanceCm()+1)>0))) {// Si l'un des deux capteurs HC-SR04 détecte un véhicule
monServomoteur.write(90); // la barrière s'ouvre
cars=cars+1;
// La LED s'allume en vert
delay(3000);
} else if (((distanceSensor2.measureDistanceCm()+1<6)&&(distanceSensor2.measureDistanceCm()+1)>0)){
 cars=cars-1;
 monServomoteur1.write(90); 
 // La LED s'allume en vert
delay(3000);
}else
{
monServomoteur.write(180);
monServomoteur1.write(180);
 // la barrière se ferme
}

if (cars==0){
  zero();
}
if (cars==1){
  un();
}
if (cars==2){
  deux();
}
if (cars==3){
  trois();
}
if (cars==4){
  quatre();
}
if (cars==5){
  cinq();
}
if (cars==6){
  six();
}
if (cars==7){
  sept();
}
if (cars==8){
  huit();
}
if (cars==9){
  neuf();
}
delay(100);
 Serial.println(cars);

}
