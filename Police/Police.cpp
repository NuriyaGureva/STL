// Police:
#include <iostream>
#include<fstream>
#include<string>
#include<map>
#include<unordered_map>
#include<list>
#include"Crime.h"
#include<Windows.h>
using std::cin;
using std::cout;
using std::endl;


std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return os << crimes.at(obj.get_id()) << ", " << obj.get_place();
}
std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj)
{

	ofs << obj.get_id() << " " << obj.get_place();
	return ofs;
}

void add(std::map<std::string, std::list<Crime>>& base);
void print(const std::map < std::string, std::list<Crime>>& base);
void save(const std::map < std::string, std::list<Crime>>& base, const std::string& filename);
void load(std::map < std::string, std::list<Crime>>& base, const std::string& filename);


int main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::map<std::string, std::list<Crime>> base/*  =
	{
		{"a777km",{Crime(1,"улица Ленина"),Crime(2,"ул.Фрунзе")}},
		{"a557a",{Crime(5,"ул.Космонавтов")}},
		{"a001a",{Crime(4,"перекресток Ленина и Октябрский")}}
	}*/;
	load(base, "base.text");
	print(base);

	//save(base, "base.text");
	//print(base);
	//add(base);
}

void add(std::map<std::string, std::list<Crime>>& base)
{
	std::string lincence_plate;
	int id;
	std::string place;
	cout << "Введите номер автомобиля:"; cin >> lincence_plate;
	cout << "Введите правонарушение(номер статьи):"; cin >> id;
	cout << "Введите место правонарушения:";
	cin.clear();
	cin.ignore();
	std::getline(cin, place);
	//base[lincence_plate].push_back(Crime(id, place));
	std::map < std::string, std::list<Crime>>::iterator it = base.find(lincence_plate);
	if (it != base.end())
	{
		it->second.push_back(Crime(id, place));
	}
	else
	{
		base.insert(std::pair < std::string, std::list<Crime>>(lincence_plate, { Crime(id,place) }));
	}

}
void print(const std::map < std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first + ":\n";
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << "\t" << *jt << "; \n";
		}
		cout << "\n--------------------------------------\n";
	}
}
void save(const std::map < std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename);
	for (std::pair<std::string, std::list<Crime>>i : base)
	{
		fout << i.first << ":\t";
		for (Crime j : i.second)
		{
			fout << j << " , ";
		}
		fout.seekp(-2, std::ios::cur);//сдвигаеь курсор на 2 позиции влево
		fout << ";\n";
	}
	fout.close();
	std::string command = std::string("start notepad ") + filename;
	system(command.c_str());


}
void load(std::map < std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string licence_plate;
			int id;
			std::string place;
			std::string crimes;
			std::getline(fin, licence_plate, ':');
			std::getline(fin, crimes);
			if (crimes.empty())continue;

			if (crimes.find(',') != std::string::npos)
			{
				for (int start = 0, end = crimes.find(','); end != std::string::npos; start = end)
				{
					end = crimes.find(',', start + 1);
					place = crimes.substr(start + 1, end);
					place.erase(0, place.find_first_not_of(' '));
					id = std::stoi(place.substr(0, crimes.find_first_of(' ')));
					place.erase(0, place.find_first_of(' ') + 1);
					base[licence_plate].push_back(Crime(id, place));
				}
			}
			else
			{
				id = std::stoi(crimes.substr(0, crimes.find_first_of(' ')));
				crimes.erase(0, crimes.find_first_of(' '));
				base[licence_plate].push_back(Crime(id, crimes));
			}
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error:file not found" << endl;
	}
}

