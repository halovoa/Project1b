#pragma once
/*
Headfile for code it will creat code class and declare both public and private class
*/



#ifndef CODE_H
#define	CODE_H
#include<ctime>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<stdlib.h>

using namespace std;
class code {
public:
	code();
	code(int n, int m);// constructor for code with length n range of m
	void RandInit(); //initiate random code
	int checkCorrect(code guess1); //function that checkcorrect
	int checkIncorrect(code guess1); //function that checkincorrect
	void printCode(); //print computer generated code
	void userinput(); //ask user to input guesscode
	int getl(); //get length
	int getr(); //get range
	void erase(); //erase temp stored vector
	vector<int> readcode(); 
private:
	vector <int> newCode; //it stores users input of new code
	//vector <int> guessCode; //it stores computer generated code
	int length;
	int range;
};


#endif

