#pragma config(Sensor, in1,    armPoten,       sensorPotentiometer)
#pragma config(Sensor, in2,    liftPoten,      sensorPotentiometer)
#pragma config(Motor,  port2,           LUArm,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           LBLift,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           LFLift,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LDArm,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           RBLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           RFLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RDArm,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           RUArm,         tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//User Created Tasks
//task gripControl();
int liftPotenVal = 0;
int armPotenVal = 0;

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;
  slaveMotor ( LDArm, RUArm );
  slaveMotor ( LUArm, RUArm );
  slaveMotor ( RDArm, RUArm );
  slaveMotor ( RBLift, RFLift );
  slaveMotor ( LFLift, RFLift );
  slaveMotor ( LBLift, RFLift );
}

task autonomous()
{

}

task usercontrol()
{
	while (true)
	{
		motor[RUArm] = ( vexRT[Btn5U] - vexRT[Btn5D] ) * 127;
		motor[RFLift] = ( vexRT[Btn6U] - vexRT[Btn6D] ) * 127;
		liftPotenVal = SensorValue(liftPoten);
		armPotenVal = SensorValue(armPoten);
	}
}