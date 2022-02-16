#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <list>
#include <vector>
using std::string;
using std::list;
using std::vector;
using std::pair;


struct Book {
	string m_title;
	string m_author;
	int m_pages;
};

template <typename T, typename U>
class HashTable {
public:
	HashTable(); // default constructor
	HashTable(const HashTable<T,U>& copy); // copy constructor
	HashTable(HashTable<T, U>&& copy); // move constructor
	HashTable& operator =(const HashTable<T, U>& rhs); // copy assignment
	HashTable& operator =(HashTable<T, U>&& rhs); // move assignment
private:
	static const int buckets;
	list<pair<T, U>> table[buckets];
};






#endif
