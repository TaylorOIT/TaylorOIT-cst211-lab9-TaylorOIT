// BlankConsoleLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include "HashTable.h"
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	HashTable<string, Book> t(10);

	Book temp = { "C++: Learn by Doing", "Todd Breedlove, Troy Scevers, et. al.", 635 };
	Book temp1 = { "Rodeo for Dummies", "Calvin Caldwell", 1 };
	Book temp2 = { "And That n There 2", "Ralph Carestia", 1 };
	Book temp3 = { "And That n There", "Ralph Carestia", 1 };
	t.Insert("0763757233", temp);
	t.Insert("0763757233", temp1);
	t.Insert("0763757234", temp3);
	t.Insert("0763757234", temp2);
	t.Insert("0763757235", temp2);

	HashTable<string, Book> q(t);



	q.PrintHashTable();
	t.PrintHashTable();

	return 0;
}

