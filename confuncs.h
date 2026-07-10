// Prototypen zu Konsolenfunktionen
#include <windows.h>
#include <time.h>

#ifndef CONFUNCS
#define CONFUNCS

// Farbdeklarationen
#define TEXTFARBE_BLAU   1
#define TEXTFARBE_GRUEN   2
#define TEXTFARBE_ROT   4
#define TEXTFARBE_WEISS TEXTFARBE_BLAU | TEXTFARBE_GRUEN | TEXTFARBE_ROT | TEXTFARBE_STAERKE
#define TEXTFARBE_BLAU_HELL TEXTFARBE_BLAU | TEXTFARBE_STAERKE
#define TEXTFARBE_GRUEN_HELL TEXTFARBE_GRUEN | TEXTFARBE_STAERKE
#define TEXTFARBE_ROT_HELL TEXTFARBE_ROT | TEXTFARBE_STAERKE
#define TEXTFARBE_STAERKE  8
#define HINTERGRUND_BLAU   16
#define HINTERGRUND_GRUEN   32
#define HINTERGRUND_ROT   64
#define HINTERGRUND_STAERKE   128
#define HINTERGRUND_WEISS HINTERGRUND_BLAU | HINTERGRUND_GRUEN | HINTERGRUND_ROT | HINTERGRUND_STAERKE
#define HINTERGRUND_BLAU_HELL HINTERGRUND_BLAU | HINTERGRUND_STAERKE
#define HINTERGRUND_GRUEN_HELL HINTERGRUND_GRUEN | HINTERGRUND_STAERKE
#define HINTERGRUND_ROT_HELL HINTERGRUND_ROT | HINTERGRUND_STAERKE


void setConsoleColor(const WORD attribs);
void setConsoleTitle(const char *name);
bool consoleMoveTo(short x, short y);
void consoleClr();
void consolePause();
void randomize2();
int random2(int to);
int randomvonbis(int from, int to);
void cursorOff();
void cursorOn();
#endif
