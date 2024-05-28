#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include<random>

using namespace std;


namespace algorithm {
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
		int _count = 0;
		size_t _size;
		size_t hash_function(K key) {
			size_t a = 333333333;
			size_t w = static_cast<size_t>(sizeof(int)) * 8;
			size_t l = log2(_data.size());
			size_t result = ((key * 333333333) % static_cast<size_t>(pow(2, w))) >> (w - l);
			return result;
		}
		int random(int a, int b) {
			random_device random_device;
			mt19937 generator(random_device());
			uniform_int_distribution<> distribution(a, b);
			return distribution(generator);
		}
	public:
		HashTable(int size);
		~HashTable();
		HashTable(const HashTable& other);
		HashTable(int size, int min_key, int max_key, int min_value, int max_value);
		void print();
		void insert(K key, T value);
		void insert_or_assign(K key, T value);
		bool contains(T value);
		T* search(K key);
		bool erase(K key);
		int count(K key);
		HashTable<K, T>& operator=(const HashTable<K, T>& other);
		int get_count();
		int get_size();
	};

	template<typename K, typename T>
	HashTable<K, T>::HashTable(int size) : _size(size)
	{
		_data.resize(_size);
	}

	template<typename K, typename T>
	HashTable<K, T>::~HashTable()
	{
		_data.clear();
		_count = 0;
		_size = 0;
	}

	template<typename K, typename T>
	HashTable<K, T>::HashTable(const HashTable& other) : _data(other._data), _size(other._size), _count(other._count)
	{
	}

	template<typename K, typename T>
	HashTable<K, T>::HashTable(int size, int min_key, int max_key, int min_value, int max_value) : _size(size)
	{
		_data.resize(_size);
		for (int i = 0; i < _size; ++i) {
			int num_elements = random(1, 10);
			for (int j = 0; j < num_elements; ++j) {
				K key = random(min_key, max_key);
				T value = random(min_value, max_value);
				insert(key, value);
			}
		}
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
		cout << "Kolizii: " << _count << endl;
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
			_count++;
		}
		else {
			_data[index] = HashPair<K, T>(key, value);
			_data[index]._filled = true;
		}

	}

	template<typename K, typename T>
	void HashTable<K, T>::insert_or_assign(K key, T value) {
		size_t index = hash_function(key);
		HashPair<K, T>* temp = &_data[index];
		while (temp) {
			if (temp->_key == key) {
				temp->_value = value;
				return;
			}
			temp = temp->_next;
		}
		insert(key, value);
	}


	template<typename K, typename T>
	bool HashTable<K, T>::contains(T value) {
		for (const auto& pair : _data) {
			HashPair<K, T>* temp = &pair;
			while (temp) {
				if (temp->_value == value) {
					return true;
				}
				temp = temp->_next;
			}
		}
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
				if (temp->_key == key) {
					return &temp->_value;
				}
				temp = temp->_next;
			}
			return nullptr;
		}
	}

	template<typename K, typename T>
	bool HashTable<K, T>::erase(K key) {
		size_t index = hash_function(key);
		HashPair<K, T>* current = &_data[index];
		HashPair<K, T>* prev = nullptr;
		while (current) {
			if (current->_key == key) {
				if (prev) {
					prev->_next = current->_next;
					delete current;
				}
				else {
					if (current->_next) {
						_data[index] = *current->_next;
						delete current->_next;
					}
					else {
						_data[index] = HashPair<K, T>();
					}
				}
				return true;
			}
			prev = current;
			current = current->_next;
		}
		return false;
	}


	template<typename K, typename T>
	int HashTable<K, T>::count(K key) {
		size_t index = hash_function(key);
		int count = 0;
		HashPair<K, T>* current = &_data[index];
		while (current) {
			if (current->_key == key) {
				count++;
			}
			current = current->_next;
		}
		return count;
	}

	template<typename K, typename T>
	HashTable<K, T>& HashTable<K, T>::operator=(const HashTable<K, T>& other) {
		if (this == &other) {
			return *this;
		}
		_data.clear();
		_count = other._count;
		_data = other._data;
		return *this;
	}

	template<typename K, typename T>
	int HashTable<K, T>::get_count()
	{
		return _count;
	}

	template<typename K, typename T>
	int HashTable<K, T>::get_size()
	{
		return _data.size();
	}
}


