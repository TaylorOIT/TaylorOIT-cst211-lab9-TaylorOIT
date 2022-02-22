// BlankConsoleLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
typedef bool(*FunctionPointer)();

#include <iostream>
#include "HashTable.h"
#include <crtdbg.h>

using std::cout;
using std::cin;
using std::endl;


HashTable<string, Book> ReturnHashTable()
{
	HashTable<string, Book> temptable(10);
	
	Book temp = { "C++: Learn by Doing", "Todd Breedlove, Troy Scevers, et. al.", 635 };
	Book temp1 = { "Rodeo for Dummies", "Calvin Caldwell", 1 };
	Book temp2 = { "And That n There", "Ralph Carestia", 1 };

	temptable.Insert("0763757233", temp);
	temptable.Insert("0763757234", temp1);
	temptable.Insert("0763757235", temp2);

	return temptable;
}

bool test_default_ctor();
bool test_one_param_ctor();
bool test_copy_ctor();
bool test_move_ctor();
bool test_op_equal();
bool test_move_op_equal();

FunctionPointer test_functions[] = { test_default_ctor, test_one_param_ctor, test_copy_ctor };

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    // Run the test functions
    for (FunctionPointer func : test_functions)
    {
        if (func())
        {
            cout << "passed\n";
        }
        else
        {
            cout << "***** failed *****\n";
        }
    }

    cout << "\nPress Any Key to Exit";
    cin.get();
}

bool test_default_ctor()
{
    bool pass = true;
    HashTable<string, Book> object;


    if (object.GetBucketSize() != 5)
        pass = false;

    if (object.GetCapacity() != 0)
        pass = false;

    if (object.GetNxtIncr() != 0)
        pass = false;

    cout << "Default Ctor Test ";
    return pass;
}

bool test_one_param_ctor()
{
    bool pass = true;
    HashTable<string, Book> object(50);


    if (object.GetBucketSize() != 50)
        pass = false;

    if (object.GetCapacity() != 0)
        pass = false;

    if (object.GetNxtIncr() != 0)
        pass = false;

    cout << "One Parameter Ctor Test ";
    return pass;
}

bool test_copy_ctor()
{
    bool pass = true;
    HashTable<string, Book> object(10);

    Book temp = { "C++: Learn by Doing", "Todd Breedlove, Troy Scevers, et. al.", 635 };

    object.Insert("0763757233", temp);

    
    HashTable<string, Book> object2(object);

    if (object["0763757233"].m_title != object2["0763757233"].m_title)
        pass = false;

    if (object["0763757233"].m_author != object2["0763757233"].m_author)
        pass = false;

    if (object["0763757233"].m_pages != object2["0763757233"].m_pages)
        pass = false;

    cout << "Copy Ctor Test ";
    return pass;
}


