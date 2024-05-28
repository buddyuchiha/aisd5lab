#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template <typename K, typename T>
class HashTable {
private:
	template <typename K, typename T>
	struct HashPair {
		K _key;
		T _value;
		HashPair* _next;
		bool _filled;
		HashPair(K key, T value) : _key(key), _value(value), _filled(true), _next(nullptr) {}
		HashPair() : _key(K()), _value(T()), _filled(false), _next(nullptr) {}
	};
	vector<HashPair<K, T>> _data;
	size_t _capacity;
	size_t hash_function(K key) {
		size_t a = 333333333333333;
		size_t w = sizeof(size_t) * 8;
		size_t l = log2(_capacity);
		size_t result = ((key * a) % static_cast<size_t>(pow(2, w))) >> (w - l);
		cout << "Capacity: " << _capacity << endl;
		return result;
	}
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
	_data.clear();
	_capacity = 0;
}

template<typename K, typename T>
HashTable<K, T>::HashTable(const HashTable& other) : _data(other._data), _capacity(other._capacity)
{

}

template<typename K, typename T>
void HashTable<K, T>::print()
{
	for (int i = 0; i < _data.size(); i++) {
		cout << "Bucket: " << i << endl;
		HashPair<K, T>* temp = &_data[i];
		while (temp) {
			cout << "{" << "Key: " << temp->_key << " Value: " << temp->_value << "}" << endl;
			temp = temp->_next;
		}
		cout << endl;
	}
	cout << "Capacity: " << _capacity << endl;
}

template<typename K, typename T>
void HashTable<K, T>::insert(K key, T value)
{
	size_t index = hash_function(key);
	HashPair<K, T>* temp = &_data[index];
	if (_data[index]._filled) {
		while (temp->_next) {
			temp = temp->_next;
		}
		temp->_next = new HashPair<K, T>(key, value);
	}
	else {
		_data[index] = HashPair<K, T>(key, value);
		_data[index]._filled = true;
	}
	_capacity++;
	cout << hash_function(key) << endl;

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
	size_t index = hash_function(key);
	if (!_data[index]._filled) {
		return nullptr;
	}
	else {
		HashPair<K, T>* temp = &_data[index];
		while (temp) {
			if (_data[index]._key == key) {
				return &_data[index]._value;
			}
			temp = temp->_next;
		}
		return nullptr;
	}
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

int main() {
	HashTable<int, string> table(5);

	table.insert(1, "one");
	table.insert(228, "two");
	table.insert(1000000, "three");
	table.insert(153216, "four");
	table.insert(550000, "five");
	table.insert(153215, "dont know");

	cout << "HashTable after insertions:" << endl;
	table.print();

	return 0;
}
