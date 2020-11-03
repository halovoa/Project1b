/* this is a head file for responce. it has a constructor a set and get function that sets and gets the correct and incorrect number
*/
#pragma once
#include "code.h"
#ifndef RESPONSE_H
#define	RESPONSE_H
#include<iostream>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <string>
using namespace std;
class Response
{
public:
	Response(); //constructor
	Response(int cor, int incor); //constructor with two inputs
	void setCor(int cor);  //set the correct number
	void setIncor(int incor); //set incorrect number
	int getCor(); //get correct number
	int getIncor(); //get incorrect number
	friend bool operator==(const Response& lhs, const Response& rhs); //overload operator compare responses
	friend ostream& operator<<(ostream& cstr, Response& r); //overload operator prints a response

private:
	int correct;
	int incorrect;
}; 

#endif
