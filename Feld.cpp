#include"AI.h"
#include"Feld.h"
#include <vector>
#include <string>
using namespace std;



void Feld::ausgabe()const {
    int spalte = 0;
    for (int zeile = 0; zeile < 4; ++zeile) {
        for (spalte = 0; spalte < 4; ++spalte) {
            cout << spielfeld[zeile][spalte] << "|";
        }
        cout << endl;
    }
}
//Eingabe, bekommt als Parameter ob Sie ein Kreuz oder Kreis Spielstein setzen soll
void Feld:: schreibe_eingabe_auf_spielfeld(string Spielstein) {
    if (spielfeld[y][x] == "   "){
        spielfeld[y][x] = " " + Spielstein + " ";
    }
    else {
        cout << "Fehler\n";
    }
}
void Feld:: check_win(string spielstein) {
    int x = 0, y = 0;


   //Hier wird geprüft ob 3 Steine in horizontaler Ausrichtung vorhanden sind
    for (x = 1; x < 4; ++x) {
        if (spielfeld[1][x] == spielstein
            && spielfeld[2][x] == spielstein
            && spielfeld[3][x] == spielstein) {
            if (spielstein == " X ") {
                winner_state = static_cast<int>(winner::SPIELER_1);
            }
            else
            {
                winner_state = static_cast<int>(winner::SPIELER_2);
            }
        }
    }
    //hier wird geprüft ob 3 Steine in vertikaler Ausrichtung vorhanden sind
    for (y = 1; y < 4; ++y) {
        if (spielfeld[y][1] == spielstein
            && spielfeld[y][2] == spielstein
            && spielfeld[y][3] == spielstein) {
            if (spielstein == " X ") {
                winner_state = static_cast<int>(winner::SPIELER_1);
            }
            else
            {
                winner_state = static_cast<int>(winner::SPIELER_2);
            }
        }
    }
    //hier wird geprüft ob 3 Steine diagonal vorhanden sind
    if ((spielfeld[1][1] == spielstein
        && spielfeld[2][2] == spielstein
        && spielfeld[3][3] == spielstein) ||
        (spielfeld[3][1] == spielstein
            && spielfeld[2][2] == spielstein
            && spielfeld[1][3] == spielstein)) {
        if (spielstein == " X ") {
            winner_state = static_cast<int>(winner::SPIELER_1);
        }
        else
        {
            winner_state = static_cast<int>(winner::SPIELER_2);
        }
    }

    // Benarchrichtigung des Siegers und Beenden des Game Loops 
    if (winner_state == static_cast<int>(winner::SPIELER_1)) { cout << "Spieler 1 hat gewonnen Wegen mieser Tricks die hinterhältig voreingestellt wurden!\n"; }
    if (winner_state == static_cast<int>(winner::SPIELER_2)) { cout << "Spieler 2 hat gewonnen!\n"; }
    if (winner_state != static_cast<int>(winner::KEIN_SIEGER)) { spiel_beendet = true; }
    //Wenn alle Felder voll, sind kann nicht mehr gewonnen werden
    bool alle_felder_voll = true;
    if (winner_state == static_cast<int>(winner::KEIN_SIEGER)) {

        for (y = 1; y < 4; ++y) {
            for (x = 1; x < 4; ++x)
            {
                if (spielfeld[y][x] == "   ") {
                    alle_felder_voll = false;

                }
            }
        }
        if (alle_felder_voll == true) {
            cout << "Es kann kein Sieger mehr geben!\n";
            spiel_beendet = true;
        }
    }
}
