#include "fehler_abfangen.h"
#include "header.h"
#include "Queue.h"

// main
void main()
{
	// Initialisierung/ Deklaration
	int wahl = 0, plaetze = 0, reihe = 0, ok = 0;
	char eingabe[GROESSE];
	PATIENTDATEN person;

	// um der Klasse die zahl weiterzugeben.
	plaetze = plaetze_reservieren();
	// erstellt Klasse.
	QUEUE patienten(plaetze);
	// endlosschleife
	system("cls");
	while (wahl != 4)
	{
		// menue
		cout << "waehlen sie:\n (1) Ankunft eines neuen Patienten.\n (2) Der naechste Patient aus dem Wartezimmer wird aufgerufen.\n (3) Aktuelle Belegung des Wartezimmers.\n (4) Programm beenden.\n\nihre Wahl:  ";
		cin >> eingabe;
		wahl = pruefen_gueltig_integer(eingabe);
		if (wahl != 0)
		{
			wahl = wandeln_integer(eingabe);
			switch (wahl)
			{
			case 1:
				system("cls");
				// soll rausfinden, wieviele leute im wartezimmer sind. also ob es noch plätze gibt.
				reihe = patienten.get_belegung();
				if (reihe >= plaetze)
				{
					// fehlermeldung das wenn array voll ist. also keine plätze mehr vorhanden sind.
					cout << "Das Wartezimmer ist voll.\n\n";
				}
				else
				{
					// daten von dieser person eingeben.
					daten_eingeben(&person);
					// eine person kommt ins wartezimmer. wird hier eingetragen. und an die nächste stelle des arrays gegangen
					patienten.enqueue(person);
					system("cls");
					cout << "Nehmen Sie bitte noch einen Moment im Wartezimmer Platz.\n\n";
				}
				break;
			case 2:
				// patient aufrufen und array zum nächsten patienten springen. ok ist ob wartezimmer leer ist oder nicht.
				ok = patienten.dequeue(&person);
				if (ok != 1)
				{
					system("cls");
					cout << "Das Wartezimmer ist leer!\n" << endl;
				}
				else
				{
					system("cls");
					// bei funktionsaufruf wird person als pointer mitgegeben und da werden die werte entsprechend gleichgesetzt.
					cout << "Patient " << person.nName << " " << person.vName << " muss zum Behandlungsraum.\n" << endl;
				}
				break;
			case 3:
				// anzahl der personen die im wartezimemr sind ausgeben.
				cout << patienten.get_belegung() << " von " << patienten.get_max_plaetze() << " Patienten sind da." << endl;
				break;
			case 4:
				system("cls");
				// beenden
				// array freigeben.
				patienten.leeren();
				cout << "Programm wird beendet.\n";
				break;
			default:
				system("cls");
				// fehlermeldung für menü auswahl
				cout << "Nicht im gueltigen Bereich!\n\n";
			}
		}
		else
		{
			system("cls");
			// fehlermeldung für ungültige zahl
			cout << "Keine Zahl!\n\n";
		}
	}
}