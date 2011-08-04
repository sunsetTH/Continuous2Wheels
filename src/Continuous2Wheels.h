/*
 UNIVERSIDADE ESTADUAL DO PIAUÍ - UESPI

 AJ Alves.

 aj.alves@live.com;
 aj.zerokol@gmail.com;

 zerokol.com
 */

#ifndef Continuous2Wheels
#define Continuous2Wheels

#include <inttypes.h>

/********************************************************************
 * CONSTANTS
 ********************************************************************/

#define STOPED 90
#define PI 3.14159265
#define RAD 0.017453292
#define RIGTHWHEEL 1
#define LEFTWHEEL 2
#define IDLE 0
#define FORWARD 1
#define BACKWARD 2

/********************************************************************
 * DECLARATIONS
 ********************************************************************/

class Continuous2Wheels {
public:
	int _speed;
	int _direction;

	Continuous2Wheels(int rigthWhreelPin, int leftWhreelPin, double wheellRadius, double bendRadius);
	void stop();
	void forward(int speed);
	void backward(int speed);
	void forward(int speed, int distance);
	void backward(int speed, int distance);
	void rigthBend(int degree);
	void leftBend(int degree);
	void spin(int degree);
	void spin(int degree, int speed);

private:
	Servo* _rightWheel;
	Servo* _leftWheel;
	double _wheelRadius;
	double _bendRadius;

	int getSpeed(int speed, int wheel);
	double degreeToRadian(int degree);
	double getDesplacement(double radians, double radius);
	unsigned long getWaitValue(double desplacement, int speed);
};

#endif