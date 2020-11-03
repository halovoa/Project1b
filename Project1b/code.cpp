/* code file which writes detailed info about code class's constructor and functions
*/

#include<ctime>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include "code.h"
using namespace std;

code::code() //code constructor without 
{
	length = 5;
	range = 10;
}
code::code(int n, int m) //code cnstructor
{
	length = n;
	range = m;
	
}
void code::userinput()
{
	int tem; //temporate code for store input
	for (int i = 0; i < length; i++) // a for loop asks user to input the code that they want to guess
	{
		cout << "please input number " << i + 1 << " integer";
		cin >> tem;
		newCode.push_back(tem);
	}

}
void code::RandInit() //generate random code by using time function
{
	int remain;
	//srand(time(0));//initialize time for rand()
	for (int i = 0; i < length; i++) // a for loop ceates random code
	{
		remain = rand() % range;
		newCode.push_back(remain);
	}
}
int code::checkCorrect(code guess1) //check the correct number of codes that are in the right place 
{
	int counter = 0;
	vector <int> guesstem = guess1.readcode();
	for (unsigned int i = 0; i < newCode.size(); i++)//use for loop to compare the input  with the computer generated code
	{	
		if (guesstem[i] == newCode[i])
		{
			counter++;
		}
	}
	return counter;
}
int code::checkIncorrect(code guess1) //check the number of codes that are same of guesscode but in wrong position
{
	int incorrect = 0;
	vector<int> rep = newCode; //create a rep for secret code
	//vector<int> rep2 = guess1.newCode;
	vector <int> guesstem = guess1.readcode(); //rep for user input
	for (unsigned int i = 0; i < guesstem.size(); i++) //compare the number are in correct position and change the number so it will not count
	{
		if (rep[i] == guesstem[i])
		{
			rep[i] = -1;
			guesstem[i] = -5;
		}
	}
	for (unsigned int i = 0; i < rep.size(); i++) //use a for loop to compare two codes and change the code after counting so there will be no recounting
	{
		for (unsigned int j = 0; j < guesstem.size(); j++)
		{
			if (rep[i] == guesstem[j])
			{
				incorrect++;
				rep[i] = -1;
				guesstem[j] = -5;
			}
		}
	}
	return incorrect;
}
void code::printCode()
{
	for (unsigned int i = 0; i < newCode.size(); i++)  //print guess code for comparison
	{
		cout << newCode.at(i) << " ";
	}
	cout << endl;
}
int code::getl()
{
	return length;
}
int code::getr()
{
	return range;
}
vector<int> code::readcode() 
{
	return newCode; //returns the code vector stored 
}
void code::erase() //erase the user input vector since it will be used in a loop
{
	for (int i = 0; i < length; i++)
	{
		newCode.pop_back();
	}
}