#include <stdio.h>
#include <stdlib.h>
#define WITH_ENGINE_temperature_CONTROLLER 1
/////////////////////////////
typedef enum{//define new type state for Engine,tempcontroller,AC
	off,
	on
}state;
typedef enum{//define new data type boolean
	False=0,
	True=1
}bool;
/////////////////////////////
void display(void);//show first decision menu
void checkDecision(void);// check which decision was chosen
void displaySensorSetMenu(void);//to display set sensor menu
void checkSensorSetMenu(void);//to check which choice you choose from sensor menu
void setTrafficLight(void);//to handle required 7-a for traffic lights
void setRoomTemp(void);//to handle required 7-b for room temperature
void setEngineTemp(void); //to handle required 7-c for engine temperature
void checkSpecialCase(void);//to handle required 7-d which contained to special cases
void printCarState(void);//to print car state and included 3 functions for AC,ENGINE and tempControll state
void printEngineState(void);
void printACState(void);
void printTempControllerState(void);
