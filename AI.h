#ifndef AI_H
#define AI_H

#include <vector>
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

void counting_horizontal(int* x, int* y, vector<vector<string>>& spielfeld,
	string stone_to_check, bool* stein_gesetzt);
int  irand();
int abfrage_ob_AI();
void AI_steine_setzen(int* x, int* y, vector<vector<string>>& spielfeld,
	string enemy, string friendly);

enum Spielmodus { EINS_GEGEN_EINS = 1, KI_GEGEN_BENUTZER = 2 ,BENUTZER_GEGEN_KI = 3, SPIEL_BEENDEN=4 };

#endif
/*
xxx
xxx
xxx
*/