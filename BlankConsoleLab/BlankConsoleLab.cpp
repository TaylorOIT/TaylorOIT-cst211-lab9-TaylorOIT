// BlankConsoleLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "HashTable.h"

int main()
{
	HashTable<string, Book> t(10);

	Book temp = { "C++: Learn by Doing", "Todd Breedlove, Troy Scevers, et. al.", 635 };
	Book temp1 = { "Rodeo for Dummies", "Calvin Caldwell", 1 };
	Book temp2 = { "And That n There 2", "Ralph Carestia", 1 };
	Book temp3 = { "And That n There", "Ralph Carestia", 1 };
	t.Insert("0763757233", temp);
	t.Insert("0763757233", temp1);
	t.Insert("0763757234", temp3);
	t.Insert("0763757234", temp2);

	std::cout << t["7063757233"].m_title << std::endl;
	std::cout << t["7063757233"].m_title << std::endl;
	std::cout << t["7063757234"].m_title << std::endl;
	std::cout << t["7063757234"].m_title << std::endl;

	t.PrintHashTable();
	t.Delete("7063757234");
	t.PrintHashTable();
}

