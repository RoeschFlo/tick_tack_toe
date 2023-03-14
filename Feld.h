#ifndef FELD_H
#define Feld_H	
#include<vector>
#include<string>
#include <iostream>
using namespace std;

class Feld {
public:
    int x =0, y=0 ;
    enum class winner : int { KEIN_SIEGER, SPIELER_1, SPIELER_2 }; // hier Enum verwenden!!
    int winner_state = static_cast<int>(winner::KEIN_SIEGER);// 
    bool spiel_beendet = false;

    vector < vector<string>> spielfeld{
      {"   "," 1 "," 2 "," 3 "},
      {" 1 ","   ","   ","   "},
      {" 2 ","   ","   ","   "},
      {" 3 ","   ","   ","   "}
    };

    //spez. Konstruktor gibt es keinen

    //Memberfunktionen
    //Ausgabe gibt spielfeld aus und schreibt nichts
    void ausgabe()const; 
    //Eingabe, bekommt als Parameter ob Sie ein Kreuz oder Kreis Spielstein setzen soll
    void schreibe_eingabe_auf_spielfeld(string Spielstein);
    //Überprüft ob jemand gewonnnen hat, Spielstein muss mit Leerzeichen eingegeben werden
    void check_win(string spielstein);  
};
#endif
