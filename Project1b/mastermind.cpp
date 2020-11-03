#include "mastermind.h"
#include "code.h"
#include "response.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include<ctime>
#include<vector>

mastermind::mastermind() //constructor
{
	guess = code();
}
mastermind::mastermind(int n, int m) //constructor with user defined length and range
{
	guess = code(n, m);
}
void mastermind::printSecret() //print secret code
{
	guess.printCode();
}
code mastermind::humanGuess() //let user input guess code
{
	guess.userinput();	  
	return  guess;
}
Response mastermind::getResponse(code guess1) //input a code class into this function and it will return a responce class result
{
	Response r(guess.checkCorrect(guess1),guess.checkIncorrect(guess1));
	return r;

}
bool mastermind::isSolved(Response r) // check whether this response is solve by comparing the number of correct to size of vector
{
	if (guess.getl() == r.getCor())
		return true;
	else
		return false;
}
bool mastermind::playGame() //start the game
{
	code guess1=code(); //create new code to store user input
	bool status = false;
	int count = 10;//count for rounds
	Response r;
	guess.RandInit(); //generate random code
	guess.printCode(); //print out code
	while (status == false && count > 0)
	{
		guess1.userinput(); //user input
		r = getResponse(guess1); //get correct and incorrect numbers
		cout << "You have " << r.getCor() << " numbers in right position" << " You have " << r.getIncor()<<" numbers in wrong posistion";
			status = isSolved(r);
			count--;
		cout << "You now have " << count << " times left " << endl;
		guess1.erase(); //erase the vector that stores the code
	}
	if (count == 0)
		return false;
	else 
		return true;
}
bool mastermind::playGame(int leng, int rang) //start the game all other are same as the function above it but this has a user defined code
{
	code guess1=code(leng,rang); //user defined code 
	bool status = false;
	int count = 10;
	Response r;
	guess.RandInit();
	guess.printCode();
	while (status == false && count > 0)
	{
		guess1.userinput();
		r = getResponse(guess1);
		cout << "You have " << r.getCor() << " numbers in right position" << " You have " << r.getIncor() << " numbers in wrong posistion";
		status = isSolved(r);
		count--;
		cout << "You now have " << count << " times left " << endl;
		guess1.erase();
	}
	if (count == 0)
		return false;
	else
		return true;
}


