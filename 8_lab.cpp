#include "Property.h"
#include "Owner.h"
#include "fstream"

void print_owners();
void fromJson(nlohmann::json json);
void From_json();
nlohmann::json toJson();
void To_json();
string check_filename();

vector<Owner> owners;

int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	bool flag = true;
	int vote;
	Owner own1("Сунцов Роман Сергеевич", "123456789123");
	Owner own2("Марков Михаил Сергеевич", "345678913456");
	Owner own3("Караваев Данил Владимирович", "754566352478");
	owners.push_back(own1);
	owners.push_back(own2);
	owners.push_back(own3);
	vector<Property*> property1 = owners[0].getProperties();
	property1.push_back(new Apartment(100000, 60));
	owners[0].setProperties(property1);
	vector<Property*> property2 = owners[1].getProperties();
	property2.push_back(new Apartment(10000, 42));
	property2.push_back(new CountryHouse(100000, 111));
	owners[1].setProperties(property2);
	vector<Property*> property3 = owners[2].getProperties();
	property3.push_back(new Apartment(100, 5));
	property3.push_back(new Car(10000, 100));
	owners[2].setProperties(property3);
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
		cout << "4. Получить данные из JSON-файла." << endl;
		cout << "5. Вывести данные в JSON-файл." << endl;
		cout << "0. Выход." << endl;
		cout << "Ваш выбор: ";
		cin >> vote;
		while (cin.fail() || vote < 0 || vote > 5) {
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cin >> vote;
		}
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		enum{ leave, add, remove, control, from_json, to_json};
		switch(vote) {
		case add: {
			string name, inn;
			system("cls");
			cout << "Введите ФИО собственника: ";
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
			cin >> ind;
			while (cin.fail() || ind < 0 || ind > owners.size()) {
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				system("cls");
				print_owners();
				cout << "Такого собственника нет, введите цель заново(0 - выход): ";
				cin >> ind;
			}
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
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
			cin >> ind;
			while (cin.fail() || ind < 0 || ind > owners.size()) {
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				system("cls");
				print_owners();
				cout << "Такого собственника нет, введите заново(0 - выход): ";
				cin >> ind;
			}
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
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
				while (cin.fail() || vibor < 0 || vibor > 2) {
					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
					cin >> vibor;
				}
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
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
						while (cin.fail() || vibor2 < 0 || vibor2 > 3) {
							cin.clear();
							cin.ignore((numeric_limits<streamsize>::max)(), '\n');
							cin >> vibor2;
						}
						cin.clear();
						cin.ignore((numeric_limits<streamsize>::max)(), '\n');
						enum {leave_props, add_apps, add_car, add_house};
						system("cls");
						switch (vibor2) {
						case add_apps: {
							size_t worth;
							double square;
							cout << "Введите стоимость квартиры: ";
							cin.clear();
							cin >> worth;
							while (cin.fail()) {
								cin.clear();
								cin.ignore((numeric_limits<streamsize>::max)(), '\n');
								cin >> worth;
							}
							cin.clear();
							cin.ignore((numeric_limits<streamsize>::max)(), '\n');
							cout << "Введите площадь: ";
							cin >> square;
							while (cin.fail() || square < 0) {
								cin.clear();
								cin.ignore((numeric_limits<streamsize>::max)(), '\n');
								cin >> square;
							}
							cin.clear();
							cin.ignore((numeric_limits<streamsize>::max)(), '\n');
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
							while (cin.fail()) {
								cin.clear();
								cin.ignore((numeric_limits<streamsize>::max)(), '\n');
								cin >> worth;
							}
							cin.clear();
							cin.ignore((numeric_limits<streamsize>::max)(), '\n');
							cout << "Введите количество лошадиных сил: ";
							cin >> horsepower;
							while (cin.fail() || horsepower < 0) {
								cin.clear();
								cin.ignore((numeric_limits<streamsize>::max)(), '\n');
								cin >> horsepower;
							}
							cin.clear();
							cin.ignore((numeric_limits<streamsize>::max)(), '\n');
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
							while (cin.fail()) {
								cin.clear();
								cin.ignore((numeric_limits<streamsize>::max)(), '\n');
								cin >> worth;
							}
							cin.clear();
							cin.ignore((numeric_limits<streamsize>::max)(), '\n');
							cout << "Введите расстяние от города до дома: ";
							cin >> distanceFromCity;
							while (cin.fail() || distanceFromCity < 0) {
								cin.clear();
								cin.ignore((numeric_limits<streamsize>::max)(), '\n');
								cin >> distanceFromCity;
							}
							cin.clear();
							cin.ignore((numeric_limits<streamsize>::max)(), '\n');
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
					cout << "Введите номер имущества, которое нужно отобрать(0 - выход): ";
					cin >> index;
					while (cin.fail() || index > owners[ind - 1].getProperties().size() || index < 0) {
						cin.clear();
						cin.ignore((numeric_limits<streamsize>::max)(), '\n');
						system("cls");
						print_owners();
						cout << "Такого имущества нет, введите заново(0 - выход): ";
						cin >> index;
					}
					if (index == 0) {
						break;
					}
					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
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
		case from_json: {
			From_json();
			break;
		}
		case to_json: {
			To_json();
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

void fromJson(nlohmann::json json) {
	vector<Owner> result;
	try
	{
		for (auto ownJson : json["Owners"])
		{
			Owner own("", "123456789123");
			own.fromJson(ownJson);
			result.push_back(own);
		}
	}
	catch (nlohmann::json::type_error err)
	{
		throw invalid_argument("error in json format");
	}
	owners = result;
}

void From_json() {
	string filename;
	bool lever = false;
	while (!lever)
	{
		system("cls");
		cout << "Введите имя Json-файла для открытия: ";
		filename = check_filename();
		ifstream file(filename);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл, возможно он не существует" << endl;
			system("pause");
		}
		lever = file.is_open();
		if (lever)
		{
			nlohmann::json json = nlohmann::json::parse(file);
			try
			{
				fromJson(json);
			}
			catch (exception ex)
			{
				system("cls");
				cout << ex.what();
				lever = false;
			}
		}
	}
}

nlohmann::json toJson() {
	nlohmann::json json;
	json["Owners"] = nlohmann::json::array();
	for (Owner i : owners) json["Owners"].push_back(i.toJson());
	return json;
}

void To_json() {
	string filename;
	system("cls");
	cout << "Введите имя Json-файла, в который нужно сохранить данные о налогах: ";
	filename = check_filename();
	ofstream file(filename);
	file << toJson().dump(4);
	file.close();
	cout << "Вывод успешен." << endl;
	system("pause");
}

string check_filename() {
	string filename;
	string word = ".json";
	bool flag = true;
	cin >> filename;
	while (filename == word) {
		cout << "Вы ввели только расширение .json" << endl;
		system("pause");
		system("cls");
		cout << "Введите имя файла заново: ";
		cin.clear();
		cin >> filename;
	}
	if (filename.size() > 5) {
		for (int i = filename.size() - 5; i < filename.size(); i++) {
			if (filename[i] != word[i - (filename.size() - 5)]) {
				flag = false;
				break;
			}
		}
	}
	else flag = false;
	if (flag) return filename;
	return filename + word;
}