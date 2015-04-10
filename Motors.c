/*
 * Motros.c
 *
 *  Created on: Apr 6, 2015
 *      Author: Dan
 */

#include Motors.h

void Motors::drive(float units, int pwmsp){// Drive Function

  int steps = units*UNITENSTP;
  M1ENCNT = 0;
  //M2ENCNT = 0;

  while(M1ENCNT < steps){
    //Serial.println(M1ENCNT);
    analogWrite(MD1PWM, pwmsp);
    //analogWrite(MD2PWM, MD2Speed);
    digitalWrite(MD1EN, HIGH);
    digitalWrite(MD1SL, HIGH);
    //digitalWrite(MD2EN, HIGH);
  }
  //return 0;
  digitalWrite(MD1EN, LOW);
  digitalWrite(MD1SL, LOW);
}

void Motors::turn(int rcmd ,int rspeed ){// Turn Function
  int UNITENSTP = 0;
  M1ENCNT = 0;
  M2ENCNT = 0;
  spacesfenc = (spacesf*100);

  while(M1ENCNT < UNITENSTP){
  analogWrite(MD1PWM, MD1Speed);
  analogWrite(MD2PWM, MD2Speed);
  digitalWrite(MD1EN, HIGH);
  digitalWrite(MD2EN, HIGH);
  }

}

void Motors::setupMotors(){
	Wire.begin(4); // Star I2C on Adress 4
	Wire.onReceive(receiveEvent); // Setup I2C as Slave
	Serial.begin(9600);// Not used for final code

	pinMode(SDA,INPUT_PULLUP); //Set Pullup for I2C
	pinMode(SCL, INPUT_PULLUP); //Set Pullup for I2C

	pinMode(MD1PWM,OUTPUT);
	pinMode(MD2PWM, OUTPUT);
	pinMode(MD1EN,OUTPUT);
	pinMode(MD2EN, OUTPUT);
	pinMode(MD1SL,OUTPUT);
	pinMode(MD2SL, OUTPUT);
	pinMode(M1ENC1,INPUT);
	pinMode(M1ENC2, INPUT);
	pinMode(M2ENC1, INPUT);
	pinMode(M2ENC2, INPUT);


	attachInterrupt(M1ENC1, counten1, CHANGE);// Set up Iterupt for Encoder 1
	attachInterrupt(M2ENC2, counten2, CHANGE);// Set up interupt for Encoder 2

}

void Motors::counten1(){
  M1ENCNT++;
}
void Motors::counten2(){
  M2ENCNT++;
}

void Motors::receiveEvent(int howMany)
{
  //while(1 < Wire.available()) // loop through all but the last
  //{
  //char c = Wire.read(); // receive byte as a character
  //Serial.print(c);         // print the character
  //}
  command = Wire.read();    // receive byte as an integer
  //Serial.println(x);         // print the integer
}

