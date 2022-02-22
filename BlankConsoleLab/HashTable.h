#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <iterator>
using std::string;
using std::list;
using std::pair;

struct Book {
	string m_title;
	string m_author;
	int m_pages;
};

template <typename K, typename V>
class HashTable {
public:
	HashTable(int value);
	HashTable(const HashTable<K, V>& copy); // copy constructor
	HashTable(HashTable<K, V>&& copy); // move constructor
	HashTable& operator =(const HashTable<K, V>& rhs); // copy assignment
	HashTable& operator =(HashTable<K, V>&& rhs); // move assignment
	~HashTable(); // destructor

	int setHash(K key); // returns the element where the list item will be inserted
	void Insert(K key, V value); // inserts the object into the bucket
	V operator [](K key); // returns the value depending on the key (operator array index)
	void Delete(K key); // deletes the list given a key
	void Traverse(V value);
	void PrintHashTable(); // prints the entire hash table
private:
	list <pair<K, V> > *bucketlist;
	int BUCKETSIZE;
	int nxt_incr;
	int capacity;
	void reHash();
};

template<typename K, typename V>
inline HashTable<K, V>::HashTable(int value) 
{
	nxt_incr = 0;
	capacity = 0;
	this->BUCKETSIZE = value;
	bucketlist = new list <pair<K, V>>[BUCKETSIZE];
}

template<typename K, typename V>
inline HashTable<K, V>::~HashTable()
{
	delete[] bucketlist;
	
	bucketlist = nullptr;
	BUCKETSIZE = 0;
}

template<typename K, typename V>
inline int HashTable<K, V>::setHash(K key)
{
	int hash = 0; 
	int index;

	index = key.length();

	for (int i = 0; i < key.length(); i++)
		hash = hash + (int)key[i];

	index = hash % BUCKETSIZE;
	
	return index;
}

template<typename K, typename V>
inline void HashTable<K, V>::Insert(K key, V value)
{
	int index = setHash(key);

	pair<K, V> str_object_pair = make_pair(key, value);
	
	bucketlist[index].push_back(str_object_pair);

	reHash();
}

template<typename K, typename V>
inline V HashTable<K, V>::operator[](K key)
{
	int index = setHash(key);
	for (int i = 0; i < BUCKETSIZE; i++) {
		auto begin = bucketlist[i].begin();
		auto nxt = std::next(begin, 0);

		if (bucketlist[i].size() > 1 && index == i)
		{
			nxt = std::next(begin, nxt_incr);
			++nxt_incr;
			if (nxt_incr == bucketlist[i].size())
				nxt_incr = 0;
			return (*nxt).second;
		}
		else if (index == i) 
		{
			return (*nxt).second;
		}
	}
}

template<typename K, typename V>
inline void HashTable<K, V>::Delete(K key)
{
	int index = setHash(key);
	for (int i = 0; i < BUCKETSIZE; i++) 
	{
		if (index == i) {
			std::cout << "Deleting Element: " << i;
			for (auto list : bucketlist[i]) {
				std::cout << " --> " << list.first << ", " << list.second.m_title;
				--capacity;
			}
			bucketlist[i].clear();
		}
	}
	std::cout << std::endl;
}

template<typename K, typename V>
inline void HashTable<K, V>::PrintHashTable()
{
	if (BUCKETSIZE > 0) {
		std::cout << "\nHash Table:\n";
		std::cout << "------------------------------------\n";
		for (int i = 0; i < BUCKETSIZE; i++) {
			std::cout << i;
			for (auto list : bucketlist[i])
				std::cout << " --> " << list.first << ", " << list.second.m_title;
			std::cout << std::endl;
		}
		std::cout << "------------------------------------\n\n";
	}
	else
		std::cout << "Hash Table is empty.\n";
}

template<typename K, typename V>
inline void HashTable<K, V>::reHash()
{
	int index = 0;
	capacity = 0;
	double load_factor;

	for (int i = 0; i < BUCKETSIZE; i++) 
	{
		for (auto list : bucketlist[i]) {
			++capacity;
		}
	}
	
	load_factor = (double)capacity / (double)BUCKETSIZE;

	if (load_factor > 0.5) 
	{
		list <pair<K, V> >* temp_bkt_list;
		temp_bkt_list = new list <pair<K, V>>[BUCKETSIZE * 2];
		
		for (int i = 0; i < BUCKETSIZE; i++)
		{
			for (auto list : bucketlist[i]) {
				index = setHash(list.first);
				pair<K, V> str_object_pair = make_pair(list.first, list.second);
				temp_bkt_list[index].push_back(str_object_pair);
			}
		}
		delete[] bucketlist;
		bucketlist = temp_bkt_list;
		BUCKETSIZE = BUCKETSIZE * 2;

		std::cout << "Load Factor is above 0.5. Table size is now: " << BUCKETSIZE << std::endl;
	}
}

#endif
