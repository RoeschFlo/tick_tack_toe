/*This ccp file contains usefull help funktions for example for comparing 
strings*/
#include"helper.h"
#include<iostream>
using namespace std;

//Eingabe von Strings 


bool compare_2_strings(int length_1,int length_2, char* string_1, char* string_2) {

	//fist check if both strings are really the same length to avoid
	//accses in memory that doesent belong to th string[]
	if (length_1 != length_2){ 
		return false;
	}
	int i =0;
	while (i < (length_1) - 1) {

		if (string_1[i] != string_2[i]) {
			return false;
		}
		i++;
	}
	//cout << "OK";
	return true;
}
