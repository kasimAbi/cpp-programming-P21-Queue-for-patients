#include "fehler_abfangen.h"
#include "header.h"
#include "Queue.h"

// Konstruktor
QUEUE::QUEUE(int anzahl)
{
	QUEUE::max_plaetze = anzahl;
	patienten = new PATIENTDATEN[max_plaetze];
	QUEUE::anfang = 0;
	QUEUE::naechste = 0;
	QUEUE::belegung = 0;
}
// gibt maximale plaetze zurück
int QUEUE::get_max_plaetze(void)
{
	return max_plaetze;
}
// gibt zurück, wieviele patienten schon drinne sind.
int QUEUE::get_belegung(void)
{
	return belegung;
}
// person in patienten array in klasse speichern
void QUEUE::enqueue(PATIENTDATEN person)
{
	// nächsten patienten einfügen
	patienten[naechste++] = person;
	// die anzahl der belegung erhöhen
	belegung++;
	// prüfen ob nächste die maximale plätze besetzt.
	if (naechste >= max_plaetze)
	{
		// wenn ja auf 0 setzen damit der von vorne wieder die patienten einfügen kann
		naechste = 0;
	}
}
// personen werte ändern damit man sie in der main benutzen kann
int QUEUE::dequeue(PATIENTDATEN *person)
{
	int ok = 0;
	// prüfen ob jemand im wartezimmer ist
	if (belegung <= 0)
	{
		ok = 0;
	}
	else
	{
		// ok = 1 machen für ein ja
		ok = 1;
		// erste für erste patient. und nach reihenfolge also first in first out (fifo prinzip)
		*person = patienten[anfang++];
		// belegung-- weil ein patient wartezimmer verlässt.
		belegung--;
		// wenn anfang maximale plaetze erreicht dann wieder zurücksetzen damit man danach weiterhin nach reihenfolge patienten zurufen kann.
		if (anfang >= max_plaetze)
		{
			anfang = 0;
		}
	}
	return ok;
}

void QUEUE::leeren(void)
{
	free(patienten);
}