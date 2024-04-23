#pragma once
// header includen
#include "fehler_abfangen.h"
#include "header.h"
// die klasse
class QUEUE
{
private:
	// private variablen deklarationen
	int max_plaetze, belegung, anfang, naechste;
	// für array
	PATIENTDATEN *patienten;
public:
	// konstruktor
	QUEUE(int);
	// einfügen funktion
	void enqueue(PATIENTDATEN);
	// wegnehmen funktion
	int dequeue(PATIENTDATEN*);
	// um variablen aus private die werte zu bekommen.
	int get_max_plaetze(void);
	int get_belegung(void);
	void leeren(void);
};