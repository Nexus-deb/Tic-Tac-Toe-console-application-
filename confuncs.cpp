#include "confuncs.h"
#include <windows.h>
#include <time.h>


void setConsoleColor(const WORD attribs) {  // Farbe der Konsolenausgabe
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attribs);
}

#ifdef SetConsoleTitle
#undef SetConsoleTitle
#endif

void setConsoleTitle(const char *name) { // Programmname des Konsolenfensters
  SetConsoleTitleA(name);    
}

bool consoleMoveTo(short x, short y) {  // Positionieren des Cursors an einer bestimmten Stelle
  COORD cords;
  cords.X = x;
  cords.Y = y;
  return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cords);    
}

void consoleClr() {  // Bildschirm löschen
  system("cls");
}

void consolePause() { // Anhalten der Ausgabe, alternativ zu getch()
  system("pause");
}

void randomize2() {    // Initialisiert den Zufallszahlengenerator, damit es neue Zahlen gibt
  srand(time(NULL));
}

int random2(int to) {  // Erzeugt eine Zufallszahl zwischen 0 und to-1
  return rand() % (to);
}

int randomvonbis(int from, int to) {
  // Zufallszahl von from bis to
  int intervall;
  int iergebnis;
  intervall = to - from;
  iergebnis = random2(intervall);
  return iergebnis + from + 1;
}


void cursorOff()  { // Blendet den Cursor aus
    CONSOLE_CURSOR_INFO cursorInfo;   
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 

    GetConsoleCursorInfo( hStdout, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo( hStdout, &cursorInfo);
}
void cursorOn() {   // Blendet den Cursor wieder ein
    CONSOLE_CURSOR_INFO cursorInfo;   
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 

    GetConsoleCursorInfo( hStdout, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo( hStdout, &cursorInfo);
}
