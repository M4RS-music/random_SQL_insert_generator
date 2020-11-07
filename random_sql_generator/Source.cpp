#include <iostream>
#include <string>
#include <random>

using namespace std;

string random_string() {
	string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	random_device rd;
	mt19937 generator(rd());

	shuffle(str.begin(), str.end(), generator);

	return str.substr(0, 12);     
};

int main() {
	int len_arr_in;

	cout << "Please input the number of attributes: ";
	cin >> len_arr_in;

	int len_arr = len_arr_in; 
	int* data_types = new int[len_arr];
	int i;

	for (i = 0; i < len_arr; i++) {
		cout << "Please input data type (0 = int, 1 = str) for attibute " << i + 1 << ": ";
		cin >> data_types[i];
	};

	string table_name;
	int instances_tbg;

	cout << "Please input the number of instances to be generated: ";
	cin >> instances_tbg;
	cout << "Please input the name of the table: ";
	cin >> table_name;

	int itr = instances_tbg;
	int g;

	for (i = 0; i < itr; i++) {
		cout << "INSERT INTO " << table_name << " VALUES (";
		for (g = 0; g < len_arr; g++) {
			if (data_types[g] == 1) {
				cout << "'" << random_string() << "', ";
			};
			if (data_types[g] == 0) {
				cout << rand() << ", ";
			}
		};
		cout << ");" << endl;
	};
	string end;

	cout << "Type 'x' and press enter to exit..." << endl;
	cin >> end;

	return 0;
}