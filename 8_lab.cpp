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
							property.push_back(new Apartment(worth, square));
							owners[ind - 1].setProperties(property);
							system("cls");
							cout << "Квартира добавлена." << endl;
							system("pause");
							break;
						}
						case add_car: {
							size_t worth;
							double horsepower;
							cout << "Введите стоимость машины: ";
							cin >> worth;
							cout << "Введите количество лошадиных сил: ";
							cin >> horsepower;
							property.push_back(new Car(worth, horsepower));
							owners[ind - 1].setProperties(property);
							system("cls");
							cout << "Машина добавлена." << endl;
							system("pause");
							break;
						}
						case add_house: {
							size_t worth;
							size_t distanceFromCity;
							cout << "Введите стоимость дома: ";
							cin >> worth;
							cout << "Введите расстяние от города до дома: ";
							cin >> distanceFromCity;
							property.push_back(new CountryHouse(worth, distanceFromCity));
							owners[ind - 1].setProperties(property);
							system("cls");
							cout << "Загородный дом добавлен." << endl;
							system("pause");
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
				case del_prop: {
					int index;
					system("cls");
					for (int i = 0; i < owners.size();i++) {
						if (ind == 1 + i) cout << "Выбранный собственник с номером " << ind << ":" << endl << owners[i] << endl << endl;
					}
					if (owners[ind - 1].getProperties().size() == 0) {
						system("cls");
						cout << "Собственник не имеет имущества." << endl;
						system("pause");
						break;
					}
					cout << "Введите номер имущества, которое нужно отобрать: ";
					while (!(cin >> index) || index > owners[ind - 1].getProperties().size() || index < 0) {
						system("cls");
						print_owners();
						cout << "Такого имущества нет. Введите заново: ";
					}

					owners[ind - 1].removeProperty(index - 1);
					system("cls");
					cout << "Собственность удалена." << endl;
					system("pause");
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