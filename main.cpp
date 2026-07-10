//10.05.2026
//Tic-tac-toe

#include <iostream>
#include "modul.h"
#include "confuncs.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int ix = 0, iy = 0, iz = 0;
	char cf[3][3]= {
		{'-','-','-'},
		{'-','-','-'},
		{'-','-','-'}
	};
	char cgame, cgame2;
	setConsoleTitle("Tic-Tac-Toe");
	bool bx = false, by = false;
		printf("This is the game Tic-Tac-Toe.The numbers left to right are the X-Coordinates, the numbers up to down are the Y-Coordinates\n");
		printf("You enter the X-Value first, press [Enter] and then enter the Y-Value!\n\n");
	do{
		printf("Do you want to play against the Computer or against a real life Player?\n");
		printf("Computer = C; Offline = O : ");
		scanf(" %c",&cgame);
		switch(cgame){
			case 'O':
			case 'o':
				offline(cf, iz, bx);
				setConsoleTitle("Offline");
				break;
			case 'C':
			case 'c':
					computer(cf, iz, bx);
					setConsoleTitle("Computer");
					break;
		}
		printf("Do you want to play another game?\n");
		printf("Y/n: ");
		scanf(" %c",&cgame2);
		switch(cgame2){
			case 'Y':
			case 'y':{	
				by = false;
				for(iy = 0; iy < 3; iy++){
					for(ix = 0; ix < 3; ix++){
						cf[ix][iy] = '-';
					}
				}
				ix = 0;
				iy = 0;
				break;
			}
			case 'N':
			case 'n':
				by = true;
				break;
			default:{
				printf("This is not an Option!!! The game is over!!\n");
				by = true;
				break;
			}
		}
	}while(by == false);	
	printf("\n");
	consolePause();
	return 0;
}
