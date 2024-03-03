
#include<iostream>
#include <string>
#include <windows.h>
using namespace std;
 
const int size_apartments = 40;
int apartment_id[size_apartments] = {};
int size_apartment[size_apartments] = {};
bool status_apartment[size_apartments] = {};
string owner_apartment[size_apartments] = {};
int current_of_apartment = 0;

static void firstScrean() {
	system("color 1f");
	cout << "  ##       ###       ##  ######   ##       @@@@     @@@@        ###        ###      ######" << endl;
	cout << "  ##      ## ##      ##  ##       ##      @@      @@    @@     ## ##      ## ##     ##    " << endl;
	cout << "   ##     ##  ##    ##   ##       ##     @@      @@      @@   ##   ##     ##  ##    ##    " << endl;
	cout << "    ##   ##   ##   ##    ######   ##     @@      @@      @@   ##    ##   ##    ##   ######" << endl;
	cout << "     ## ##     ## ##     ##       ##      @@      @@    @@   ##      ## ##     ##   ##    " << endl;
	cout << "      ##        ###      ######   ######   @@@@     @@@@     ##       ###       ##  ######" << endl;
}

// system menu 
void system_menu() 
{
	system("color 1f");
	cout << "		===============================\n";
	cout << "		WELCOME TO GRAND TRUST COMPANY\n";
	cout << "		===============================\n\n";
	cout << "			LIST OF CHOICES\n";
	cout << "		==============================\n\n";
	cout << "1 - ABOUT THE COMAPANY			2 - ADD DATA OF APARTMENT\n";
	cout << "3 - BUY AN APARTMENT			4 - TOTAL APARTMENTS\n";
	cout << "5 - EXIT SYSTEM \n\n";
	cout << "ENTER YOUR CHOOSEING\n";
}

//searsh by id 
int searsh_id(int id) {
	for (int i = 0; i < current_of_apartment; i++) {
		if (id == apartment_id[i]) {
			return i;
		}
	}
	return -1;

}

//diplay info apartment 
void display_info(int id) {
	if (searsh_id(id) == - 1 ) {
		cout << "this id not found \n";
		return;
	}
	cout << "========================== \n";
	cout << "id apartment : " << apartment_id[id - 1] << endl;
	cout << "size apartment : " << size_apartment[id - 1] << endl;
	cout << "statuse apartment :" << (status_apartment[id - 1] ? "available" : "unavailable") << endl;
	cout << "owner apartment :" << owner_apartment[id - 1] << endl;
	cout << "========================== \n";
}

// 1- about of company 
void about_the_company() {
	cout << "WELCOME MY DEAR :-\n";
	cout << "WE ARE GRAND TRUST COMPANY\nWE WORK IN REAL ESTATE INVESTMENT\n\n";
}

// 2 - add data 
void add_data_of_apartment(int size) {
	apartment_id[current_of_apartment] = current_of_apartment + 1;
	size_apartment[current_of_apartment] = size;
	status_apartment[current_of_apartment] = true;
	//owner_apartment[current_of_apartment] = owner;
	current_of_apartment++;
	cout << "thit add successfully\n";
}

// 3 - buy apartment 
void buy_apartment(int id ) {
	if (searsh_id(id) == -1) {
		cout << "this apartment is sold out \n";
		return;
	}
		if (status_apartment[id - 1] == true) {
			status_apartment[id - 1] = false;
			string newowner;
			cout << "enter name owner apartment \n";
			cin >> newowner;
			owner_apartment[id - 1] = newowner;
		}
	cout << "THE SALE WIS COMPLETED SUCCESSFULLY \n";
}

// 4 - total apartment  
void total_apartment() {

	for (int i = 0; i < current_of_apartment; i++) {
		display_info (apartment_id [i]);
	}
}

int main() {

	int id;
	int size_apartment;
	string owner;
	bool flag = true;
	firstScrean();
	system("pause");
	system("cls");

	while (flag) {

		system_menu();

		int choices; cin >> choices;
		switch (choices) {
		case 1: // about company
			system("cls");
			about_the_company();
			break;
		case 2: // add data of apartmints
			system("cls");
			cout << "enter size apartment \n";
			cin >> size_apartment;
			add_data_of_apartment(size_apartment);
			break;
		case 3:// buy apartment
			system("cls");
			cout << "enter number apartment do you want buy \n";
			cin >> id;
			buy_apartment(id);
			break;
		case 4:// total apartments 
			system("cls");
			total_apartment();
			break;
		case 5: // exit system 
			flag = false;
			cout << "THANK YOU FOR USED GRAND TRUST SYSTEM \n";
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}

