/* mastermind head file and this class will handle the playing of the gam
*/
#pragma once
#include "code.h"
#include "response.h"
#ifndef MASTERMIND_H
#define	MASTERMIND_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include<ctime>

using namespace std;
class mastermind
{ 
public:
	mastermind(); //constructor
	mastermind(int n, int m); //constructor
	void printSecret(); //print out secret code 
	code humanGuess(); //user input numbers and return it as a code class obj
	Response getResponse(code guess1); //get the responce from a code and return it as a responce class obk
	bool isSolved(Response r); //give the function a response class and check if it is solved
	bool playGame(); //start the game
	bool playGame(int leng, int rang); //start the game with user define length and range

	
private:
	
	code guess;


};

#endif