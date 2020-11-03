#include <cstdlib>
#include<iostream>
#include<vector>
#include "mastermind.h"
#include<ctime>
#include<stdlib.h>
using namespace std;
int main()
{	
	int leng;
	int range;
	cout << "Master guessing game has begin, please input the length first and then the range of guess code"<<endl<<"if you put both 0 the game will have defult setting with length of 5 range of 10 " << endl;
	cout << "please input length" << endl;
	cin >> leng;
	cout << "please input range" << endl;
	cin >> range;
	if (leng == 0 && range == 0)
	{
		mastermind game = mastermind();
		game.playGame();
	}
	else
	{
		if (leng > 0 && range > 0)
		{
			mastermind game = mastermind(leng,range);
			game.playGame(leng,range);
		}
		else
		{
			cout << "Invalid input, please restart game";
			return 0;
		}
	}




}