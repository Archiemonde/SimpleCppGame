#pragma once
#include<iostream>
using namespace std;
class Item {
public: 
	string name;
	string desc;
	int amount;
	Item(string="def", string="def", int=0);
};