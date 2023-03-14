
#include"AI.h"
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include"helper.h"
using namespace std;

//takes the task of checking the spielfeld vector horzontal and causes the setting stones via 
//pointer *x, *y, can be used offensiv or defensiv, uses global xx and yy from AI.ccp!
void counting_horizontal(int* x, int* y, vector<vector<string>>& spielfeld,
	string stone_to_check, bool* stein_gesetzt) {

	int number_friendly = 0,
		yy = 0, xx = 0;
	for (yy = 1; yy < 4 && *stein_gesetzt == false; ++yy) {
		number_friendly = 0;
		for (xx = 1; xx < 4 && *stein_gesetzt == false; ++xx)
		{
			if (spielfeld[yy][xx] == stone_to_check) {
				number_friendly++;
			}
		}

		if (number_friendly == 2)
		{
			for (xx = 1; xx < 4 && *stein_gesetzt == false; ++xx) {
				if (spielfeld[yy][xx] == "   ")
				{
					*x = xx, * y = yy, * stein_gesetzt = true;
				}
			}
		}
	}

}

//takes the task of checking the spielfeld vector vertical and causes the setting stones via 
//pointer *x, *y, uses global xx and yy from AI.ccp!
void counting_vertical(int* x, int* y, vector<vector<string>>& spielfeld,
	string stone_to_check, bool* stein_gesetzt) {

	int number_friendly = 0,
		yy = 0, xx = 0;
	for (xx = 1; xx < 4 && *stein_gesetzt == false; ++xx) {
		number_friendly = 0;
		for (yy = 1; yy < 4 && *stein_gesetzt == false; ++yy)
		{
			if (spielfeld[yy][xx] == stone_to_check) {
				number_friendly++;
			}
		}
		if (number_friendly == 2)
		{
			for (yy = 1; yy < 4 && *stein_gesetzt == false; ++yy) {
				if (spielfeld[yy][xx] == "   ")
				{
					*x = xx, * y = yy, * stein_gesetzt = true;
				}
			}
		}
	}
}

//takes the task of checking the spielfeld vector diagonal from top left to bottom right
//  and causes the setting stones via pointer *x, *y, uses global xx and yy from AI.ccp!
void counting_diagonal_top_left(int* x, int* y, vector<vector<string>>& spielfeld,
	string stone_to_check, bool* stein_gesetzt) {
	int number = 0,
		yy = 0, xx = 0;

	for (xx = 1; xx < 4 && *stein_gesetzt == false; ++xx) {
		if (spielfeld[xx][xx] == stone_to_check) {
			number++;
		}
		if (number == 2) {
			for (xx = 1; xx < 4 && *stein_gesetzt == false; ++xx) {
				if (spielfeld[xx][xx] == "   ")
				{
					*x = xx, * y = xx, * stein_gesetzt = true;
				}
			}
		}
	}
}

//takes the task of checking the spielfeld vector diagonal from top left to bottom right
//  and causes the setting stones via pointer *x, *y, uses global xx and yy from AI.ccp!
void counting_diagonal_top_right(int* x, int* y, vector<vector<string>>& spielfeld,
	string stone_to_check, bool* stein_gesetzt) {
	int number = 0,
		yy = 0, xx = 0;
	for (xx = 1, yy = 3; xx < 4 && *stein_gesetzt == false; xx++, yy--) {
		if (spielfeld[yy][xx] == stone_to_check) {
			number++;
		}
		if (number == 2)
		{
			for (xx = 1, yy = 3; xx < 4 && *stein_gesetzt == false; xx++, yy--) {
				if (spielfeld[yy][xx] == "   ")
				{
					*x = xx, * y = yy, * stein_gesetzt = true;
				}
			}
		}
	}
}


int abfrage_ob_AI() {

	char input[2] = {};
	bool input_fail = true;
	bool eingabe_zu_lang = false;
	string spielmodus;
	bool chars_are_same = false;
	cout << "Wollen Sie gegen eine AI oder eine menschlichen Gegner Spielen?\n";
	cout << "Geben Sie 1 ein fuer 1vs.1, 2 fuer KI vs. Benutzer, 3 fuer Benutzer vs. KI\n ";
	cout << "4 um das Spiel zu beenden:\n";



	while (chars_are_same == false || eingabe_zu_lang == true) {
		// make input
		if (fgets(input, 2, stdin) != 0) {}
		eingabe_zu_lang = true;
		//Wenn 2. Zeihen ungleich \n  war die eingabe zu lang
		if (input[1] == '\n' || input[0] != '\n') { eingabe_zu_lang = false; }
		if (input[0] == '1') { return EINS_GEGEN_EINS; }
		if (input[0] == '2') { return KI_GEGEN_BENUTZER; }
		if (input[0] == '3') { return BENUTZER_GEGEN_KI; }
		if (input[0] == '4') { return SPIEL_BEENDEN; }
		


		if (chars_are_same == false || eingabe_zu_lang == true) {
			cout << "Bitte Eingabe wiederholen\n";
			int c;
			while ((c = getchar()) != '\n' /* && c != EOF*/) {}
		}
	}

}

void AI_steine_setzen(int* x, int* y, vector<vector<string>>& spielfeld,
	string enemy, string friendly)
{

	int xx = 0, yy = 0;
	bool stein_gesetzt = false;
	cout << "AI macht seine Eingabe\n";
	int number_enemy = 0;
	int number_friendly = 0;

	// at first the ki will check if it cann instant winn 
	//horizontal orientation
	counting_horizontal(x, y, spielfeld, friendly, &stein_gesetzt);

	// at first the ki will check if it cann instant winn 
	//vertical orientation
	counting_vertical(x, y, spielfeld, friendly, &stein_gesetzt);

	// at first the ki will check if it cann instant winn 
	//diagonal orientation, left top to right bottom
	counting_diagonal_top_left(x, y, spielfeld, friendly, &stein_gesetzt);

	//diagonal orientation, right top to left bottom
	// at first the ki will check if it cann instant winn 
	counting_diagonal_top_right(x, y, spielfeld, friendly, &stein_gesetzt);

	//has the enemy two stones horizontal?
	// horizontale anordnung, is there a enemy stone at 1.1 and 1.2? at 1.2 and 1.3? etc. 
	counting_horizontal(x, y, spielfeld, enemy, &stein_gesetzt);

	//vertikale anordnung?
	counting_vertical(x, y, spielfeld, enemy, &stein_gesetzt);

	//checking if enemy or friend has 2 stones diagonal?
	// diagonal from top left to bottom right
	counting_diagonal_top_left(x, y, spielfeld, enemy, &stein_gesetzt);

	//cheking if enemy or friend has 2 stones diagonal from top right to bottom left?
	counting_diagonal_top_right(x, y, spielfeld, enemy, &stein_gesetzt);

	//the KI has to know if its the first or the second
	//number_enemy_1 is for global counting, number_enemy is for counting 
	// in funktions
	int number_enemy_1 = 0;
	int number_friendly_1 = 0;
	yy = 0, xx = 0;
	for (yy = 1; yy < 4; ++yy) {
		for (xx = 1; xx < 4; ++xx)
		{
			if (spielfeld[yy][xx] == enemy) {
				number_enemy_1++;
			}
			if (spielfeld[yy][xx] == friendly) {
				number_friendly_1++;
			}
		}
	}

	//defensive play
	//occupy the middle if KI is second, first we have to know if we are second and middle is free
	if (number_enemy_1 == number_friendly_1 + 1) {
		number_enemy = 0;
		number_friendly = 0;
		yy = 0, xx = 0;
		for (yy = 1; yy < 4; ++yy) {
			for (xx = 1; xx < 4; ++xx)
			{
				if (spielfeld[yy][xx] == enemy) {
					number_enemy++;
				}
				if (spielfeld[yy][xx] == friendly) {
					number_friendly++;
				}
			}
		}

		if (spielfeld[2][2] == "   " && stein_gesetzt == false &&
			number_enemy == 1 && number_friendly == 0) {
			number_enemy = 0,
				yy = 0, xx = 0;
			for (yy = 1; yy < 4; ++yy) {
				for (xx = 1; xx < 4; ++xx)
				{
					if (spielfeld[yy][xx] == enemy) {
						number_enemy++;
					}
				}
			}
			if (number_enemy == 1) {

				*x = 2, * y = 2;
				stein_gesetzt = true;
			}
		}
		//KI is the second player
		//the middle is occupied by the enemy
		if ((number_enemy_1 == number_friendly_1 + 1 == 1) && stein_gesetzt == false
			&& spielfeld[2][2] == enemy && spielfeld[1][1]=="   ") {
			*x = 1, * y = 1;
			stein_gesetzt = true;
		}
		if ((number_enemy_1 == number_friendly_1 + 1 == 1) && stein_gesetzt == false
			&& spielfeld[2][2] == enemy && spielfeld[2][1] == "   ") {
			*x = 2, * y = 1;
			stein_gesetzt = true;
		}

	}

	//offensiv gameplay
	// if we are first 
	
	number_enemy = 0;
	number_friendly = 0;
	yy = 0, xx = 0;
	for (yy = 1; yy < 4; ++yy) {
		for (xx = 1; xx < 4; ++xx)
		{
			if (spielfeld[yy][xx] == enemy) {
				number_enemy++;
			}
			if (spielfeld[yy][xx] == friendly) {
				number_friendly++;
			}
		}
	}

	//if KI is first in the second mov and opponent sets stone in corner
	//, it sets the stone in the opposite corner than the first3.3
	if (/*number_friendly == 0 && number_enemy == 0*/ spielfeld[1][1]=="   " && stein_gesetzt == false) {
		*x = 1, * y = 1, stein_gesetzt = true;
	}
	//second move
	if (/*number_friendly == 1 && number_enemy == 1 &&*/ stein_gesetzt == false) {
		if (spielfeld[3][3] == "   ") {
			*y = 3, * x = 3, stein_gesetzt = true;
		}
		if (spielfeld[3][3] == enemy && stein_gesetzt == false && spielfeld[2][2] == "   ") {
			*y = 2, * x = 2, stein_gesetzt = true;
		}
	}
	//third move, no need for programmingy in some cases
	if (number_friendly == 2 && number_enemy == 2 && stein_gesetzt == false) {
		if (spielfeld[3][3] == enemy && spielfeld[2][1] == "   ") {

			*y = 2, * x = 1, stein_gesetzt = true;
		}
		if (spielfeld[3][3] == enemy && spielfeld[1][2] == "   " && stein_gesetzt == false) {

			*y = 1, * x = 2, stein_gesetzt = true;
		}

	}
	// if nothing works we pick the first free field
	if (stein_gesetzt == false) {
		yy = 0, xx = 0;
		for (yy = 1; yy < 4; ++yy) {
			for (xx = 1; xx < 4; ++xx)
			{
				if (spielfeld[yy][xx] == "   ") {
					*y = yy, * x = xx;
					stein_gesetzt = true;
				}
			}
		}
	}

}

		



