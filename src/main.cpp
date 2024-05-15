#include <iostream>
#include <vector>
using namespace std;

template <typename K, typename T>
class HashTable {
private:
	template <typename K, typename T>
	struct HashPair {
		K _key;
		T _value;
		bool _filled;
		HashPair(K key, T value) : _key(key), _value(value), _filled(false) {}
		HashPair(): _key(K()), _value(T()), _filled(false){}
	};
	vector<HashPair<K, T>> _data;
	int _capacity;
public:
	HashTable(int capacity);
	~HashTable();
	HashTable(const HashTable& other);
	void print();
	void insert(K key, T value);
	void insert_or_assign(K key, T value);
	bool contains(T value);
	T* search(K key);
	bool erase(K key);
	int count(K key);
};

template<typename K, typename T>
HashTable<K, T>::HashTable(int capacity) : _capacity(capacity)
{
	_data.resize(_capacity);
}

template<typename K, typename T>
HashTable<K, T>::~HashTable()
{
}

template<typename K, typename T>
HashTable<K, T>::HashTable(const HashTable& other)
{
}

template<typename K, typename T>
void HashTable<K, T>::print()
{
}

template<typename K, typename T>
void HashTable<K, T>::insert(K key, T value)
{
}

template<typename K, typename T>
void HashTable<K, T>::insert_or_assign(K key, T value)
{
}

template<typename K, typename T>
bool HashTable<K, T>::contains(T value)
{
	return false;
}

template<typename K, typename T>
T* HashTable<K, T>::search(K key)
{
	return nullptr;
}

template<typename K, typename T>
bool HashTable<K, T>::erase(K key)
{
	return false;
}

template<typename K, typename T>
int HashTable<K, T>::count(K key)
{
	return 0;
}

int main() {}
