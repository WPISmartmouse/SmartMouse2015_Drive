/*
 * Motors.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Dan
 */

#ifndef MOTORS_H_
#define MOTORS_H_

#define MD1PWM 39	// Motor 1 PWM CNTRL
#define MD2PWM 2	// Motor 2 PWM CNTRL

#define MD1EN 38	// Motor 1 Direction
#define MD2EN 10	// Motor 2 Direction
#define MD1SL 37	// Motor 1 Direction
#define MD2SL 4		// Motor 2 Direction

#define M1ENC1 36	// Motor 1 Encoder Input 1
#define M1ENC2 6	// Motor 1 Encoder Input 2
#define M2ENC1 7	// Motor 2 Encoder Input 1
#define M2ENC2 8	// Motor 2 Encoder Input 2

#define SDA 21		// I2C SDA
#define SCL 20		// I2C SCL

#define wheelRadius = 10.0f //wheel radius in mm
#define countPerRotation 30 // number of encoder counts per one rotation
#define UNITENSTP 3133		// units per step

class Motros{
public:
	void drive(float units, int pwmsp);
	void turn(int rcmd ,int rspeed );
	void receiveEvent(int howMany)
private:
	setupMotors();
	counten1();
	counten2();
};

#endif /* MOTORS_H_ */
