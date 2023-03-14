// tick_tack_toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include"AI.h"
#include <iostream>
#include"Feld.h"
#include <vector>
#include <string>
#include <time.h>

using namespace std;

//einzelne Funktionen
//prüft ob Eingabe erlaubt war
void eingabe_spielstein_(int* x, int* y, vector<vector<string>>& spielfeld)
{
	bool eingabe_ok = false;
	char point;
	string eingabe;
	int xx = 0, yy = 0;

	while (!eingabe_ok)
	{
		cout << "Bitte machen Sie ihre Eingabe in Form von zb. 1.2\n" <<
			"das heisst 1.Spalte, 2.Zeile: ";

		if ((scanf_s("%d%c%d", &xx, &point, 1, &yy) != 0)
			&& point == '.'
			&& xx > 0 && yy > 0
			&& xx < 4 && yy < 4) {


			// Feld muss frei sein, muss noch geprüft werden, kann nicht vorher gemacht werden, weil sonst auf vector bereiche
			//zugegriffe wird die es nicht gibt
			if (spielfeld[yy][xx] == "   ") {
				eingabe_ok = true;
				cout << "passt\n";
			}
			else { cout << "falsche Eingabe\n"; }
		}
		else { cout << "falsche Eingabe\n"; }
		while (getchar() != '\n');

	};

	*x = xx;
	*y = yy;
}



int main()
{
	//srand(time(NULL));
	time_t t;
	srand((unsigned)time(&t));
	int spielmodus = EINS_GEGEN_EINS;

	while (spielmodus != SPIEL_BEENDEN)
	{


		spielmodus = abfrage_ob_AI();
		Feld spielfeld;
		spielfeld.ausgabe();

		//Game Loop 1vs.1 
		if (spielmodus == EINS_GEGEN_EINS) {
			cout << "Hallo Sie spielen tick tack Toe 1vs.1\n";


			while (!spielfeld.spiel_beendet) {
				// Spieler 1
				cout << "Spieler_1\n";

				eingabe_spielstein_(&spielfeld.x, &spielfeld.y, spielfeld.spielfeld);
				

				spielfeld.schreibe_eingabe_auf_spielfeld("X");

				spielfeld.ausgabe();
				spielfeld.check_win(" X ");

				//Wenn jetzt schon ein Sieger feststeht wird der Game Loop beendet
				if (spielfeld.spiel_beendet) { break; }

				cout << "Spieler_2\n";
				// Spieler 2 
				eingabe_spielstein_(&spielfeld.x, &spielfeld.y, spielfeld.spielfeld);
			
				spielfeld.schreibe_eingabe_auf_spielfeld("O");

				spielfeld.ausgabe();
				spielfeld.check_win(" O "); // its  big o not zero !
				if (spielfeld.spiel_beendet) { break; }

			}
		}

		//Game Loop KI gegen Nutzer 
		if (spielmodus == KI_GEGEN_BENUTZER) {
			cout << "Hallo Sie spielen tick tack Toe KI gegen Nutzer\n";


			while (!spielfeld.spiel_beendet) {
				// Spieler 1
				cout << "Spieler_1\n";

				
				AI_steine_setzen(&spielfeld.x, &spielfeld.y, spielfeld.spielfeld,
					" O ", " X ");

				spielfeld.schreibe_eingabe_auf_spielfeld("X");

				spielfeld.ausgabe();
				spielfeld.check_win(" X ");

				//Wenn jetzt schon ein Sieger feststeht wird der Game Loop beendet
				if (spielfeld.spiel_beendet) { break; }

				cout << "Spieler_2\n";
				// spieler 2
				eingabe_spielstein_(&spielfeld.x, &spielfeld.y, spielfeld.spielfeld);
			
				spielfeld.schreibe_eingabe_auf_spielfeld("O");

				spielfeld.ausgabe();
				spielfeld.check_win(" O "); // its  big o not zero !
				if (spielfeld.spiel_beendet) { break; }

			}
		}
		//Game Loop Nutzer gegen KI 
		if (spielmodus == BENUTZER_GEGEN_KI) {
			cout << "Hallo Sie spielen tick tack Toe Nuzter gegen KI\n";


			while (!spielfeld.spiel_beendet) {
				// Spieler 1
				cout << "Spieler_1\n";

				eingabe_spielstein_(&spielfeld.x, &spielfeld.y, spielfeld.spielfeld);
				spielfeld.schreibe_eingabe_auf_spielfeld("X");

				spielfeld.ausgabe();
				spielfeld.check_win(" X ");

				//Wenn jetzt schon ein Sieger feststeht wird der Game Loop beendet
				if (spielfeld.spiel_beendet) { break; }

				cout << "Spieler_2\n";
				// KI s
				
				AI_steine_setzen(&spielfeld.x, &spielfeld.y, spielfeld.spielfeld,
					" X "," O ");

				spielfeld.schreibe_eingabe_auf_spielfeld("O");

				spielfeld.ausgabe();
				spielfeld.check_win(" O "); // its  big o not zero !
				if (spielfeld.spiel_beendet) { break; }

			}
			if (spielmodus == SPIEL_BEENDEN) {
				return 0;
			}
		}
	}
	//Game Loop 1 vs. 1
	//*/
		char c;
		while ((c = getchar()) != '\n' && c != EOF) {}

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
