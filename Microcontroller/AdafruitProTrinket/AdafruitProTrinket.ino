/*
Renaissance Project 2: CATch 22
Author: Sergio Corrales Zamora
First version: 23/11/2016
Build 1.0 - 23/11/2016
 */

#define debug 9   //FOR DEBUGGING PURPOSES
#define led 10
#define valve 11
#define echoPin 12
#define trigPin 13
#include <TimerOne.h>

bool detected = false;
long duration;
int i = 0;
volatile byte state = LOW;   //FOR DEBUGGING PURPOSES

void setup() {
  interrupts();
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(valve, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(debug, OUTPUT);   //FOR DEBUGGING PURPOSES

  digitalWrite(valve,LOW);
  digitalWrite(led,LOW);

  Timer1.initialize(500000);
  Timer1.attachInterrupt(ultrasonicProbe);
}

void closeValve(){
  if (i == 2){
    digitalWrite(valve,LOW);
    digitalWrite(led,LOW);

    Timer1.attachInterrupt(ultrasonicProbe,500000);
    Timer1.restart();
    i = 0;
  }
  else {
    i++;
  }
}

void ultrasonicProbe(){
  state = !state;   //FOR DEBUGGING PURPOSES
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 10000);
  if (duration > 0) {
    digitalWrite(valve,HIGH);
    digitalWrite(led,HIGH);

    Timer1.attachInterrupt(closeValve,8000000);
    Timer1.restart();
  }
}

void loop() {
  digitalWrite(debug, state);   //FOR DEBUGGING PURPOSES
}
