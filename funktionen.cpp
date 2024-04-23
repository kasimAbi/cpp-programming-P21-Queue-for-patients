#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include "Queue.h"
#include "fehler_abfangen.h"
// plaetze reservieren (anfang des programms)
int plaetze_reservieren(void)
{
	// initialisierungen/ deklarationen
	int ok = 0, plaetze;
	char eingabe[GROESSE];
	while (ok != 1)
	{
		cout << "Geben sie die Anzahl der Patienten ein:  ";
		cin >> eingabe;
		// prüfen ob zahl
		ok = pruefen_gueltig_integer(eingabe);
		if (ok == 1)
		{
			// wandeln in zahl und prüfen ob im gültigen bereich (20)
			plaetze = wandeln_integer(eingabe);
			if (plaetze != 0 && plaetze <= anzahl_plaetze)
			{
				// damit die while schleife verlassen werden kann
				ok = 1;
			}
			else
			{
				system("cls");
				// fehlermeldung
				cout << "Es dürfen nur maximal 20 Plaetze reserviert werden,\nund der Wert darf nicht 0 betragen.\n\n";
			}
		}
		else
		{
			system("cls");
			// fehlermeldung
			cout << "Sie haben keine Zahl eingegeben.\n\n";
		}
	}
	// anzahl der plaetze zurückgeben
	return plaetze;
}
// die daten eingeben
void daten_eingeben(PATIENTDATEN* person)
{
	// initialisierungen/ deklarationen
	char eingabe[GROESSE];
	int ok = 0, index = 0;
	int tag = 0, monat = 0, jahr = 0;
	// die char werte eingeben (also alle zeichenvariablen)
	cout << "Bitte geben sie den Vornamen ein:  ";
	cin >> eingabe;
	strcpy(person->vName, eingabe);
	cout << "Bitte geben sie den Nachname ein:  ";
	cin >> eingabe;
	strcpy(person->nName, eingabe);
	cout << "Bitte geben sie den Geburtstag ein.\n";
	while (ok != 1)
	{
		// geburtstag eingeben
		cout << "Tag:  ";
		cin >> eingabe;
		ok = pruefen_gueltig_integer(eingabe);
		if (ok == 1)
		{
			tag = wandeln_integer(eingabe);
			// prüfen ob maximaltag überschreitet oder minimaltag unterschritten wird
			if (tag <= 31 && tag >= 1)
			{
				person->geburtsdatum.tag = tag;
				ok = 0;
				while (ok != 1)
				{
					cout << "Monat:  ";
					cin >> eingabe;
					ok = pruefen_gueltig_integer(eingabe);
					if (ok == 1)
					{
						monat = wandeln_integer(eingabe);
						// prüfen ob monat gültig ist
						if (monat <= 12 && monat >= 1)
						{
							person->geburtsdatum.monat = monat;
							ok = 0;
							cout << "Jahr:  ";
							cin >> eingabe;
							ok = pruefen_gueltig_integer(eingabe);
							// es können nur positive werte sein weil prüfen ob integer nur bei positiven zahlen eine 1 zurückgibt.
							if (ok == 1)
							{
								jahr = wandeln_integer(eingabe);
								// jahr speichern
								person->geburtsdatum.jahr = jahr;
							}
							else
							{
								// ok = 0 damit die while schleife weiter geht bis man einen gültigen wert hat.
								ok = 0;
								system("cls");
								// fehlermeldung
								cout << "Fehleingabe.\n";
							}
						}
						else
						{
							// ok = 0 damit die while schleife weiter geht bis man einen gültigen wert hat.
							ok = 0;
							system("cls");
							// fehlermeldung
							cout << "Fehleingabe.\n";
						}
					}
					else
					{
						// ok = 0 damit die while schleife weiter geht bis man einen gültigen wert hat.
						ok = 0;
						system("cls");
						// fehlermeldung
						cout << "Fehleingabe.\n";
					}
				}
			}
			else
			{
				// ok = 0 damit die while schleife weiter geht bis man einen gültigen wert hat.
				ok = 0;
				system("cls");
				// fehlermeldung
				cout << "Fehleingabe.\n";
			}
		}
		else
		{
			// ok = 0 damit die while schleife weiter geht bis man einen gültigen wert hat.
			ok = 0;
			system("cls");
			// fehlermeldung
			cout << "Fehleingabe.\n";
		}
	}
}