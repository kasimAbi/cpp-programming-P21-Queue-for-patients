#pragma once
#pragma comment(lib, "FehlerAbfangen")
#include "fehler_abfangen.h"
#define anzahl_plaetze 20
// strukturen für geburtsdatum. muss über patientdaten sein weil patientdaten auf das zugreift.
struct GEBURTSDATUM
{
	int tag;
	int monat;
	int jahr;
};
struct PATIENTDATEN
{
	char vName[GROESSE];
	char nName[GROESSE];
	GEBURTSDATUM geburtsdatum;
};
// das ist sehr wichtig das es UNTER der struktur ist weil man erst auf struktur greifen muss dann auf header! sonst geht er erst zur klasse dann zur struktur.
#include "Queue.h"
// funktionsdeklarationen für einfügen und anzahl plätze einzugeben also wie viele patienten sein dürfen.
void daten_eingeben(PATIENTDATEN*);
int plaetze_reservieren(void);