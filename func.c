//function implementation file
#include "func.h"
char c1;//first decision menu
char c2;//decision of sensor set menu
char c3;//traffic light
float currSpeed=125;
float roomTemp=22;
float engTemp=25;
float currRoomTemp,currEngTemp;
state engineState=on;
state AC=on;
state tempController=on;//special case 1 flag
bool special1,special2=False;//special case 2 flag
void display(void){
	printf("\na/Turn on the vehicle engine\nb/Turn off the vehicle engine\nc/Quit the system\n");
	scanf(" %c",&c1);
}
void checkDecision(void){
	switch (c1) {
	case 'a':
	case 'A':
		printf("Turn on the vehicle engine\n");//case 1
		engineState=on;
		displaySensorSetMenu();
		checkSensorSetMenu();
		break;
	case 'b':
	case 'B':
		printf("Turn off the vehicle engine\n");//case2
		engineState=off;
		display();
		checkDecision();
		break;
	case 'c':
	case 'C':
		printf("Quit the system\n");//case 3
		exit(0);
	default:
		break;
	}
}
//display sensor menu
void displaySensorSetMenu(void){
	printf("\na/Turn off the engine\nb/Set the traffic light color\nc/ Set the room temperature (Temperature Sensor)\n");
#if(WITH_ENGINE_temperature_CONTROLLER)//bonus
		printf("d/Set the engine temperature (Engine Temperature Sensor)\n");
#endif
	scanf(" %c",&c2);
}
//check choice c2 from menu
void checkSensorSetMenu(void){
	switch (c2) {
	case 'a':   //case1
	case 'A':
		display();
		checkDecision();
		break;
	case 'b'://case2
	case 'B':
		setTrafficLight();
		displaySensorSetMenu();
		checkSensorSetMenu();
		break;
	case 'c'://case3
	case 'C':
		setRoomTemp();
		displaySensorSetMenu();
		checkSensorSetMenu();
		break;
#if(WITH_ENGINE_temperature_CONTROLLER)//bonus
	case 'd'://case4
	case 'D':
		setEngineTemp();
		displaySensorSetMenu();
		checkSensorSetMenu();
		break;
#endif
	default:
		displaySensorSetMenu();
		checkSensorSetMenu();
		break;
	}

}
void setTrafficLight(void){
	printf("Enter the required color: \n");
	scanf(" %c",&c3);
	switch (c3) {
		case 'g':
		case 'G':
			currSpeed=100;
			printCarState();
			break;
		case 'o':
		case 'O':
			currSpeed=30;
			printCarState();
			break;
		case 'r':
		case 'R':
			currSpeed=0;
			printCarState();
			break;
		default:
			printf("enter valid value for traffic light O,R,G");
			displaySensorSetMenu();
			checkSensorSetMenu();
			break;
	}
}
void printEngineState(void){
	if(engineState==on){
		printf("Engine is ON\n");
	}else{
		printf("Engine is OFF\n");
	}
}
void printACState(void){
	if(AC==on){
		printf("AC is ON\n");
	}else{
		printf("AC is OFF\n");
	}
}
void printTempControllerState(void){
	if(tempController==on){
		printf("Engine Temp Controller is ON\n");
	}else{
		printf("Engine Temp Controller is OFF\n");
	}
}
void printCarState(void){
	printEngineState();
	printACState();
	printf("Vehicle Speed: %.2f Km/Hr\n",currSpeed);
	printf("Room Temperature: %.2f C\n",roomTemp);
#if(WITH_ENGINE_temperature_CONTROLLER)
		printTempControllerState();
		printf("Engine Temperature: %.2f C\n",engTemp);
#endif
	checkSpecialCase();
}
void setRoomTemp(void){
	printf("Enter the required room temp:\n");
	scanf("%f",&roomTemp);
	if(roomTemp<10){
		AC=on;
		roomTemp=20;
	}else if(roomTemp>30){
		AC=on;
		roomTemp=20;
	}else{
		AC=off;
	}
	printCarState();
}
void setEngineTemp(void){
	printf("Enter the required engine temp:\n");
	scanf("%f",&engTemp);
	if(engTemp<100){
		tempController=on;
		engTemp=125;
	}else if(engTemp>150){
		tempController=on;
		engTemp=125;
	}else{
		tempController=off;
	}
	printCarState();
}
void checkSpecialCase(void){
	if(currSpeed==30){
			if(AC==off){
				printf("special case please enter current room temperature \n");
				scanf("%f",&currRoomTemp);
				special1=True;
				AC=on;
				roomTemp=(currRoomTemp*5/4)+1.00;
			}else{
				special1=False;
			}
			if(tempController==off){
				printf("special case please enter current engine temperature\n");
				scanf("%f",&currEngTemp);
				tempController=on;
				engTemp=(currEngTemp*5/4)+1.00;
				special2=True;
			}else{
				special2=False;
			}
		}
	  if(special1 || special2 ){
		  printCarState();
	  }
}
