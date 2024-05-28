#include <iostream>
#include "..\algorithm\algorithm.h"

using namespace std;
using namespace algorithm;

int task(int elements, int experiments, int size) {
	int sum = 0;
	for (int i = 0; i < experiments; i++) {
		HashTable <int, int> task_table(size, 1, elements, 1, 1000);
	/*	cout << "Size " << task_table.get_size() << "Kolizii "<< task_table.get_count() << endl;*/
		float result = (static_cast<float>(task_table.get_count()) / task_table.get_size());
		sum += result;
	}
	return sum;
}

int main() {
	
	
	for (int i = 25; i <= 475; i += 50) {
		cout << "Size: " << i << endl;
		cout << "Medium range: " << static_cast<float>(task(26, 100, i)) / 100 << endl;;
		cout << endl;
	}
	/*HashTable<int, int> table(10);

	table.insert(1, 1337);
	table.insert(2, 1337);
	table.insert(3, 1337);
	table.insert(4, 1337);
	table.insert(5, 1337);
	table.insert(6, 1337);
	table.insert(7, 1337);
	table.insert(8, 1337);
	table.insert(9, 1337);
	table.insert(10, 1337);
	table.insert(11, 1337);
	table.insert(12, 1337);
	table.insert(13, 1337);
	table.insert(14, 1337);
	table.insert(15, 1337);
	table.insert(16, 1337);
	table.insert(17, 1337);
	table.insert(1000, 1337);*/

	/*cout << "HashTable after insertions:" << endl;
	table.print();
	table.erase(2);
	table.print();
	if (table.search(10)) { cout << "Yes" << endl; }
	else { cout << "No" << endl; }

	HashTable<int, int>table2(table);
	table2.print();*/

	/*HashTable<int, int> table2(6);
	table2 = table;
	table2.print();*/
	
	//HashTable<int, int> table(10, 1, 100, 1000, 9999);
	//cout << "HashTable after random insertions:" << endl;
	//table.print();

}
