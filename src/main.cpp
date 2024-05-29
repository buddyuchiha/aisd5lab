#include <iostream>
#include "..\algorithm\algorithm.h"

using namespace std;
using namespace algorithm;


int task(int experiments, int size) {
	int sum = 0;
	for (int i = 0; i < experiments; i++) {
		HashTable <int, int> task_table(size, 1, 100, 1, 1000);
		sum += task_table.get_count();
	}
	return sum;
}

int main() {

	
	
	//// ������� ������ ���-������� � �������� ��������
	//HashTable<int, int> table(10);

	//// �������� ������ insert
	//table.insert(1, 1337);
	//table.insert(2, 1338);
	//table.insert(3, 1339);

	//// �������� ������ print
	//cout << "HashTable after insertions:" << endl;
	//table.print();

	//// �������� ������ erase
	//table.erase(2);
	//cout << "HashTable after erasing key 2:" << endl;
	//table.print();

	//// �������� ������ search
	//int* value_ptr = table.search(1);
	//if (value_ptr) {
	//	cout << "Value for key 1: " << *value_ptr << endl;
	//}
	//else {
	//	cout << "Key 1 not found" << endl;
	//}

	//// �������� ������ contains
	//if (table.contains(1339)) {
	//	cout << "HashTable contains value 1339" << endl;
	//}
	//else {
	//	cout << "HashTable does not contain value 1339" << endl;
	//}

	//// �������� ������ count
	//cout << "Number of elements with key 1: " << table.count(1) << endl;

	//// �������� ������ insert_or_assign
	//table.insert_or_assign(3, 9999);
	//cout << "HashTable after inserting or assigning key 3 with value 9999:" << endl;
	//table.print();


	for (int i = 25; i <= 475; i += 50) {
		cout << "Size: " << i << endl;
		cout << "Number of col: " << task(100, i) / 100.0 << endl;;
		cout << endl;
	}
	
}
