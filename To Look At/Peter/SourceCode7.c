#pragma config(Sensor, S4,     sonarSensor,         sensorSONAR)
#pragma config(Motor,  motorA,          motorA,        tmotorNormal, PIDControl, encoder)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*--------------------------------------------------------------------------------------------------------*\
|*                                                                                                        *|
|*                                   - Obstacle Detection with Sonar -                                    *|
|*                                            ROBOTC on NXT                                               *|
|*                                                                                                        *|
|*  This program runs your robot forward until it detects and obstacle, at which point it turns.          *|
|*                                                                                                        *|
|*                                        ROBOT CONFIGURATION                                             *|
|*    NOTES:                                                                                              *|
|*    1)  The Sonar Sensor should be somewhere on the FRONT of the robot, facing FORWARD.                 *|
|*                                                                                                        *|
|*    MOTORS & SENSORS:                                                                                   *|
|*    [I/O Port]              [Name]              [Type]              [Description]                       *|
|*    Port B                  motorB              NXT                 Right motor                         *|
|*    Port C                  motorC              NXT                 Left motor                          *|
|*    Port 4                  sonarSensor         Sonar Sensor        Front mounted, front facing         *|
\*---------------------------------------------------------------------------------------------------4246-*/

void turnRight() //function to be called to turn right
{

	nMotorEncoder[motorC] = 0;
	while(nMotorEncoder[motorC] < 180)
	{
		motor[motorC] = 50;
		motor[motorB] = -50;
	}

	motor[motorC] = 0;
	motor[motorB] = 0;

}


task main()
{
  int distance_in_cm = 35;   // Create variable 'distance_in_cm' and initialize it to 35(cm).
  while(true)
   {
   while(SensorValue[sonarSensor] > distance_in_cm)   /* While the Sonar Sensor readings are less than
   {                                                  the specified, 'distance_in_cm':*/
            motor[motorB] = 100;                     // Motor B is run at a 75 power level
      motor[motorC] = 100;               // Motor C is run at a 75 power level

   }/*this code is run when the robot encounters an object,
    and tells the motors to stall for a moment to
    reset then calls turnRight to avoid the object */
   motor[motorC] = 0;
   wait1Msec(50);
  turnRight();
}