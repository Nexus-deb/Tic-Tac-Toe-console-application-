#include <iostream>
#include "confuncs.h"
#include "modul.h"

void feld(char cf[3][3]){
	int ix = 0, iy = 0;
	for(iy=0; iy<3; iy++){
			setConsoleColor(TEXTFARBE_GRUEN);
			printf("\t%i", iy);
			setConsoleColor(TEXTFARBE_WEISS);
		}
		printf("\n");
		for(iy=0; iy<3; iy++){
			setConsoleColor(TEXTFARBE_ROT);
			printf("%i", iy);
			setConsoleColor(TEXTFARBE_WEISS);
			for(ix=0; ix<3; ix++){
				printf("\t%c", cf[ix][iy]);
			}
			printf("\n");
		}
}

void offline(char cf[3][3], int iz, bool bx){
	int ix = 0, iy = 0, itest = 0;
	do{
		consoleClr();
		iz++;
		feld(cf);
		if(iz % 2 == 1){
			printf("\nPlayer X:\n");
		}
		else{
			printf("\nPlayer O:\n");
		}
		
		ix = inputX();
		iy = inputY();
		
		if(cf[ix][iy] != '-'){
			printf("\nYou can't go there! Try another square!!\n");
			iz = iz - 1;
			consolePause();
		}
		else{	
			if(iz % 2 == 1){
				cf[ix][iy] = 'X';
			}
			else{
				cf[ix][iy] = 'O';
			}
		}
		itest = test2(cf);
		if(itest == 1){
			feld(cf);
			printf("Player X won the game!!!!\n");
		}
		if(itest == 2){
			feld(cf);
			printf("Player O won the game!!!!\n");
		}	
	}while(itest == 0 && iz<9);
		
		if(itest == 0 && iz == 9){
			feld(cf);
			printf("It's a tie!!!'\n");
		}
}
	
void computer(char cf[3][3], int iz, bool bx){
	int ix = 0, iy = 0, iz1 = 0, itest = 0;
	consoleClr();
	feld(cf);
	ix = inputX();
	iy = inputY();
	cf[ix][iy] = 'X';
	consoleClr();
	feld(cf);
	consolePause();
	if(ix == 1 && iy == 1){
		cf[2][2] = 'O';
	}
	else{
		cf[1][1] = 'O';
	}
	consoleClr();
	iz1 = 2;
	do{
		consoleClr();
		feld(cf);
		ix = inputX();
		iy = inputY();
		if(cf[ix][iy] != '-'){
			printf("That space is already occupied! You can't go there!\n");
			consolePause();
		}
		else{
			cf[ix][iy] = 'X';
			consoleClr();
			iz1++;
			feld(cf);
			itest = test2(cf);
			if(itest == 1){
				printf("The Player won the game!!!!\n");
				break;
			}
			consolePause();
			if(iz1 == 9){
				break;
			}
			test(cf);
			consoleClr();
			itest = test2(cf);
			if(itest == 2){
				feld(cf);
				printf("The Computer won the game!!!!\n");
				break;
			}
			iz1++;
		}
	}while(iz1 <= 9 && itest == 0);
	if(iz1 == 9 && itest == 0){
		consoleClr();
		feld(cf);
		printf("It's a tie!!!\n");
		consolePause();
		consoleClr();
	}
}

void test(char cf[3][3]){
	int ix = 0, iy = 0, iz = 0;
	bool bz = false;
	for(iz = 0; iz < 2; iz++){	
		//Computer moves
		//rows
		if(cf[1][1] == 'O' && cf[2][1] == 'O' && cf[0][1] == '-'){
			cf[0][1] = 'O';
			break;
		}
		if(cf[1][0] == 'O' && cf[2][0] == 'O' && cf[0][0] == '-'){
			cf[0][0] = 'O';
			break;
		}
		if(cf[1][2] == 'O' && cf[2][2] == 'O' && cf[0][2] == '-'){
			cf[0][2] = 'O';
			break;
		}
		
		if(cf[1][1] == 'O' && cf[0][1] == 'O' && cf[2][1] == '-'){
			cf[2][1] = 'O';
			break;
		}
		if(cf[1][0] == 'O' && cf[0][0] == 'O' && cf[2][0] == '-'){
			cf[2][0] = 'O';
			break;
		}
		if(cf[1][2] == 'O' && cf[0][2] == 'O' && cf[2][2] == '-'){
			cf[2][2] = 'O';
			break;
		}
		

		if(cf[0][0] == 'O' && cf[2][0] == 'O' && cf[1][0] == '-'){
			cf[1][0] = 'O';
			break;
		}
		if(cf[0][2] == 'O' && cf[2][2] == 'O' && cf[1][2] == '-'){
			cf[1][2] = 'O';
			break;
		}
		//collumns
		if(cf[0][0] == 'O' && cf[0][1] == 'O' && cf[0][2] == '-'){
			cf[0][2] = 'O';
			break;
		}
		if(cf[1][0]  == 'O'&& cf[1][1] == 'O' && cf[1][2] == '-'){
			cf[1][2] = 'O';
			break;
		}
		if(cf[0][2] == 'O' && cf[1][2] == 'O' && cf[2][2] == '-'){
			cf[2][2] = 'O';
			break;
		}
		
		if(cf[0][1] == 'O' && cf[0][2] == 'O' && cf[0][0] == '-'){
			cf[0][0] = 'O';
			break;
		}
		if(cf[1][1] == 'O' && cf[1][2] == 'O' && cf[1][0] == '-'){
			cf[1][0] = 'O';
			break;
		}
		if(cf[2][1] == 'O' && cf[2][2] == 'O' && cf[2][0] == '-'){
			cf[2][0] = 'O';
			break;
		}
		
		if(cf[0][0] == 'O' && cf[0][2] == 'O' && cf[0][1] == '-'){
			cf[0][1] = 'O';
			break;
		}
		if(cf[2][0] == 'O' && cf[2][2] == 'O' && cf[2][1] == '-'){
			cf[2][1] = 'O';
			break;
		}
		//diagonals
		if(cf[0][2] == 'O' && cf[1][1] == 'O' && cf[2][0] == '-'){
			cf[2][0] = 'O';
			break;
		}
		if(cf[1][1] == 'O' && cf[2][0] == 'O' && cf[0][2] == '-'){
			cf[0][2] = 'O';
			break;
		}
		
		//Human countermoves
		//rows
		if(cf[1][1] == 'X' && cf[2][1] == 'X' && cf[0][1] == '-'){
			cf[0][1] = 'O';
			break;
		}
		if(cf[1][0] == 'X' && cf[2][0] == 'X' && cf[0][0] == '-'){
			cf[0][0] = 'O';
			break;
		}
		if(cf[1][2] == 'X' && cf[2][2] == 'X' && cf[0][2] == '-'){
			cf[0][2] = 'O';
			break;
		}
		
		if(cf[1][1] == 'X' && cf[0][1] == 'X' && cf[2][1] == '-'){
			cf[2][1] = 'O';
			break;
		}
		if(cf[1][0] == 'X' && cf[0][0] == 'X' && cf[2][0] == '-'){
			cf[2][0] = 'O';
			break;
		}
		if(cf[1][2] == 'X' && cf[0][2] == 'X' && cf[2][2] == '-'){
			cf[2][2] = 'O';
			break;
		}
		

		if(cf[0][0] == 'X' && cf[2][0] == 'X' && cf[1][0] == '-'){
			cf[1][0] = 'O';
			break;
		}
		if(cf[0][2] == 'X' && cf[2][2] == 'X' && cf[1][2] == '-'){
			cf[1][2] = 'O';
			break;
		}
		//collumns
		if(cf[0][0] == 'X' && cf[0][1] == 'X' && cf[0][2] == '-'){
			cf[0][2] = 'O';
			break;
		}
		if(cf[1][0]  == 'X'&& cf[1][1] == 'X' && cf[1][2] == '-'){
			cf[1][2] = 'O';
			break;
		}
		if(cf[2][0] == 'X' && cf[2][1] == 'X' && cf[2][2] == '-'){
			cf[2][2] = 'O';
			break;
		}
		
		if(cf[0][1] == 'X' && cf[0][2] == 'X' && cf[0][0] == '-'){
			cf[0][0] = 'O';
			break;
		}
		if(cf[1][1] == 'X' && cf[1][2] == 'X' && cf[1][0] == '-'){
			cf[1][0] = 'O';
			break;
		}
		if(cf[2][1] == 'X' && cf[2][2] == 'X' && cf[2][0] == '-'){
			cf[2][0] = 'O';
			break;
		}
		
		if(cf[0][0] == 'X' && cf[0][2] == 'X' && cf[0][1] == '-'){
			cf[0][1] = 'O';
			break;
		}
		if(cf[2][0] == 'X' && cf[2][2] == 'X' && cf[2][1] == '-'){
			cf[2][1] = 'O';
			break;
		}
		//diagonals
		if(cf[0][2] == 'X' && cf[1][1] == 'X' && cf[2][0] == '-'){
			cf[2][0] = 'O';
			break;
		}
		if(cf[1][1] == 'X' && cf[2][0] == 'X' && cf[0][2] == '-'){
			cf[0][2] = 'O';
			break;
		}
		if(cf[0][0] == 'X' && cf[1][1] == 'X' && cf[2][2] == 'O' && cf[0][2] == '-'){
			cf[0][2] = 'O';
			break;
		}
		//other
		if(cf[0][0] == 'X' && cf[0][2] == 'X' && cf[2][1] == 'X' && cf[1][0] == '-'){
			cf[1][0] = 'O';
			break;
		}
		
		if(cf[2][0] == 'X' && cf[2][2] == 'X' && cf[0][1] == 'X' && cf[1][0] == '-'){
			cf[1][0] = 'O';
			break;
		}
		if(cf[0][0] == 'X' && cf[2][0] == 'X' && cf[1][2] == 'X' && cf[0][2] == '-'){
			cf[0][2] = 'O';
			break;
		}
		if(cf[0][2] == 'X' && cf[2][2] == 'X' && cf[1][0] == 'X' && cf[0][1] == '-'){
			cf[0][1] = 'O';
			break;
		}
		if(cf[0][0] == 'O' && cf[1][1] == 'O' && cf[2][2] == 'X' && cf[0][2] == '-'){
			cf[0][2] = 'O';
			break;
		}
		
		//dumb moves by players + computer countermoves
		if(cf[0][0] == 'X' && cf[2][2] == 'X' && cf[1][1] == 'O' && cf[0][1] == '-'){
			cf[0][1] = 'O';
			break;
		}
		if(cf[0][2] == 'X' && cf[2][0] == 'X' && cf[1][1] == 'O' && cf[0][1] == '-'){
			cf[0][1] = 'O';
			break;
		}
		
		
		if(cf[0][0] == 'X' && cf[1][2] == 'X' && cf[1][1] == 'O' && cf[0][2] == '-'){
			cf[0][2] = 'O';
			break;
		}
		if(cf[0][0] == 'X' && cf[2][1] == 'X' && cf[1][1] == 'O' && cf[1][2] == '-'){
			cf[1][2] = 'O';
			break;
		}
		
		if(cf[0][2] == 'X' && cf[1][0] == 'X' && cf[1][1] == 'O' && cf[0][1] == '-'){
			cf[0][1] = 'O';
			break;
		}
		if(cf[0][2] == 'X' && cf[2][1] == 'X' && cf[1][1] == 'O' && cf[2][2] == '-'){
			cf[2][2] = 'O';
			break;
		}
		
		if(cf[2][2] == 'X' && cf[1][0] == 'X' && cf[1][1] == 'O' && cf[2][1] == '-'){
			cf[2][1] = 'O';
			break;
		}
		if(cf[2][2] == 'X' && cf[0][1] == 'X' && cf[1][1] == 'O' && cf[0][2] == '-'){
			cf[0][2] = 'O';
			break;
		}
		
		if(cf[2][0] == 'X' && cf[0][1] == 'X' && cf[1][1] == 'O' && cf[0][0] == '-'){
			cf[0][0] = 'O';
			break;
		}
		if(cf[2][0] == 'X' && cf[1][2] == 'X' && cf[1][1] == 'O' && cf[0][1] == '-'){
			cf[0][1] = 'O';
			break;
		}
			
		for(iy = 0; iy < 3; iy++){
			for(ix = 0; ix < 3; ix++){
				if(cf[ix][iy] == '-'){
					cf[ix][iy] = 'O';
					bz = true;
					break;
				}
			}
			if(bz == true){
				break;
			}
		}
	}
}

int inputX(){
	int ix;	
	bool bx;
	do{
		bx = false;
		printf("Please enter the ");
		setConsoleColor(TEXTFARBE_GRUEN);
		printf("X-Coordinate: ");
		scanf(" %i", &ix);
		setConsoleColor(TEXTFARBE_WEISS);
		if(ix < 0 || ix > 2){
			printf("You can't go there! Try again!\n");
			bx = true;
		}
	}while(bx == true);
	return ix;
}

int inputY(){
	int iy;
	bool bx;
	do{
		bx = false;
		printf("Please enter the ");
		setConsoleColor(TEXTFARBE_ROT);
		printf("Y-Coordinate: ");
		scanf(" %i", &iy);
		setConsoleColor(TEXTFARBE_WEISS);
		if(iy < 0 || iy > 2){
			printf("You can't go there! Try again!\n");
			bx = true;
		}
	}while(bx == true);
	
	return iy;
}

int test2(char cf[3][3]){
	int iy = 0;
	if(iy == 0){
		//player
		if(cf[0][0] == 'X' && cf[1][0] == 'X' && cf[2][0] == 'X'){
			iy = 1;
		}
		if(cf[0][1] == 'X' && cf[1][1] == 'X' && cf[2][1] == 'X'){
			iy = 1;
		}
		if(cf[0][2] == 'X' && cf[1][2] == 'X' && cf[2][2] == 'X'){
			iy = 1;
		}
		if(cf[0][0] == 'X' && cf[0][1] == 'X' && cf[0][2] == 'X'){
			iy = 1;
		}
		if(cf[1][0] == 'X' && cf[1][1] == 'X' && cf[1][2] == 'X'){
			iy = 1;
		}
		if(cf[2][0] == 'X' && cf[2][1] == 'X' && cf[2][2] == 'X'){
			iy = 1;
		}
		if(cf[0][0] == 'X' && cf[1][1] == 'X' && cf[2][2] == 'X'){
			iy = 1;
		}
		if(cf[2][0] == 'X' && cf[1][1] == 'X' && cf[0][2] == 'X'){
			iy = 1;
		}
		//computer
		if(cf[0][0] == 'O' && cf[1][0] == 'O' && cf[2][0] == 'O'){
			iy = 2;
		}
		if(cf[0][1] == 'O' && cf[1][1] == 'O' && cf[2][1] == 'O'){
			iy = 2;
		}
		if(cf[0][2] == 'O' && cf[1][2] == 'O' && cf[2][2] == 'O'){
			iy = 2;
		}
		if(cf[0][0] == 'O' && cf[0][1] == 'O' && cf[0][2] == 'O'){
			iy = 2;
		}
		if(cf[1][0] == 'O' && cf[1][1] == 'O' && cf[1][2] == 'O'){
			iy = 2;
		}
		if(cf[2][0] == 'O' && cf[2][1] == 'O' && cf[2][2] == 'O'){
			iy = 2;
		}
		if(cf[0][0] == 'O' && cf[1][1] == 'O' && cf[2][2] == 'O'){
			iy = 2;
		}
		if(cf[2][0] == 'O' && cf[1][1] == 'O' && cf[0][2] == 'O'){
			iy = 2;
		}
	}
	else{
		iy = 0;
	}
	return iy;
}
