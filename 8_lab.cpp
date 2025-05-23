#include "Owner.h"
#include "Property.h"

void print_owners();

vector<Owner> owners;

int main() {
	setlocale(LC_ALL, "Rus");
	bool flag = true;
	int vote;
	while (flag) {
		system("cls");
		cout << "Список собственников: ";
		if (owners.size() == 0) {
			cout << endl << "   Список собственников пуст." << endl << endl;
		}
		else {
			cout << endl;
			print_owners();
		}
		cout << "1. Добавить нового собственника." << endl;
		cout << "2. Ликвидировать собственника." << endl;
		cout << "3. Выбрать собственника для управления его имуществом." << endl;
		enum{ leave, add, remove, control};
		cin >> vote;
		switch(vote) {
		case add: {
			string name, inn;
			system("cls");
			cout << "Введите ФИО собственника: ";
			cin.clear();
			cin.ignore();
			getline(cin, name);
			cout << "Введите ИНН собственника: ";
			cin >> inn;
			Owner new_owner(name, inn);
			owners.push_back(new_owner);
			break;
		}
		case remove: {
			int ind;
			system("cls");
			if (owners.size() == 0) {
				cout << "Уничтожать некого." << endl;
				system("pause");
				break;
			}
			print_owners();
			cout << "Выберите какого собственника дезинтегрирует (0 - выйти): ";
			while (!(cin >> ind) || ind > owners.size() || ind < 0) {
				system("cls");
				print_owners();
				cout << "Такого сотрудника нет. Введите цель заново: ";
			}
			if (ind == 0) {
				break;
			}
			owners.erase(owners.begin() + ind - 1);
			break;
		}
		case control: {
			int ind, vibor;
			bool flagi = true;
			system("cls");
			if (owners.size() == 0) {
				cout << "Управлять собственностью не у кого." << endl;
				system("pause");
				break;
			}
			print_owners();
			cout << "Выберите собственника для управления (0 - выйти): ";
			while (!(cin >> ind) || ind > owners.size() || ind < 0) {
				system("cls");
				print_owners();
				cout << "Такого сотрудника нет. Введите заново: ";
			}
			if (ind == 0) {
				break;
			}
			while (flagi) {
				system("cls");
				bool flagi2 = true;
				for (int i = 0; i < owners.size();i++) {
					if (ind == 1 + i) cout << "Выбранный собственник с номером " << ind << ":" << endl << owners[i] << endl << endl;
				}
				cout << "1. Добавить имущество." << endl;
				cout << "2. Удалить имущество бедолаги." << endl;
				cout << "0. Выйти." << endl;
				cout << "Ваш выбор: ";
				cin >> vibor;
				enum { leave_prop, add_prop, del_prop };
				switch (vibor) {
				case add_prop: {
					while (flagi2) {
						system("cls");
						int vibor2;
						vector<Property*> property = owners[ind - 1].getProperties();
						for (int i = 0; i < owners.size();i++) {
							if (ind == 1 + i) cout << "Выбранный собственник с номером " << ind << ":" << endl << owners[i] << endl << endl;
						}
						cout << "1. Добавить квартиру." << endl;
						cout << "2. Добавить машину." << endl;
						cout << "3. Добавить загородный дом." << endl;
						cout << "0. Выход." << endl;
						cout << "Ваш выбор: ";
						cin >> vibor2;
						enum {leave_props, add_apps, add_car, add_house};
						system("cls");
						switch (vibor2) {
						case add_apps: {
							size_t worth;
							double square;
							cout << "Введите стоимость квартиры: ";
							cin >> worth;
							cout << "Введите площадь: ";
							cin >> square;
							property.push_back(new Apartment(square, worth));
							owners[ind - 1].setProperties(property);
							system("cls");
							cout << "Квартира добавлена.";
							break;
						}
						case leave_props: {
							flagi2 = false;
							break;
						}
						}
					}
					break;
				}
				case leave_prop: {
					flagi = false;
					break;
				}
				}
			}
			break;
		}
		case leave:
			flag = false;
			break;
		}
	}

}

void print_owners() {
	for (int i = 0; i < owners.size();i++) {
		cout << i + 1 << "." << owners[i] << endl << endl;
	}
}