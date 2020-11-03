/* cpp file for response head file and write detailed functions and construtors
*/
#include "Response.h"
#include <iostream>


Response::Response() //constructor
{
	correct = 0;
	incorrect = 0;
}

Response::Response(int cor, int incor) //constructor with two input values
{
	correct = cor;
	incorrect = incor;
}

void Response::setCor(int cor) //set correct number
{
	correct = cor;
}

void Response::setIncor(int incor) //set incorrect number
{
	incorrect = incor;
}

int Response::getCor() //get correct number
{
	return correct;
}

int Response::getIncor() //get incorrect number
{
	return incorrect;
}

bool operator==(const Response& lhs, const Response& rhs) //verload operator compare responses
{
	if (lhs.correct == rhs.correct && lhs.incorrect == rhs.incorrect)
		return true;
	else return false;
}

ostream& operator<<(ostream& cstr, Response& r) //overload operator prints a response
{
	cstr << "number of correct guesses are "<< r.getCor()<< "number of incorrect guesses are "<<r.getIncor();
	return cstr;
}