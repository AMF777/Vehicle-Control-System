/*
 ============================================================================
 Name        : main.c
 Author      : Ahmed Magdy
 Version     :
 Copyright   : Your copyright notice
 Description :  Vehicle Control system in C, Ansi-style
 ============================================================================
 */
//main file
#include "func.h"

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	display();
	checkDecision();
}
