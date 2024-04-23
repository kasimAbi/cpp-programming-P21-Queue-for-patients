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
// gibt maximale plaetze zur�ck
int QUEUE::get_max_plaetze(void)
{
	return max_plaetze;
}
// gibt zur�ck, wieviele patienten schon drinne sind.
int QUEUE::get_belegung(void)
{
	return belegung;
}
// person in patienten array in klasse speichern
void QUEUE::enqueue(PATIENTDATEN person)
{
	// n�chsten patienten einf�gen
	patienten[naechste++] = person;
	// die anzahl der belegung erh�hen
	belegung++;
	// pr�fen ob n�chste die maximale pl�tze besetzt.
	if (naechste >= max_plaetze)
	{
		// wenn ja auf 0 setzen damit der von vorne wieder die patienten einf�gen kann
		naechste = 0;
	}
}
// personen werte �ndern damit man sie in der main benutzen kann
int QUEUE::dequeue(PATIENTDATEN *person)
{
	int ok = 0;
	// pr�fen ob jemand im wartezimmer ist
	if (belegung <= 0)
	{
		ok = 0;
	}
	else
	{
		// ok = 1 machen f�r ein ja
		ok = 1;
		// erste f�r erste patient. und nach reihenfolge also first in first out (fifo prinzip)
		*person = patienten[anfang++];
		// belegung-- weil ein patient wartezimmer verl�sst.
		belegung--;
		// wenn anfang maximale plaetze erreicht dann wieder zur�cksetzen damit man danach weiterhin nach reihenfolge patienten zurufen kann.
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