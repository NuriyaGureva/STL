#include<iostream> 
#include<set>
#include<map>
#include<list>
#include<deque>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"


//# define STL_SET
//#define STL_MAP
#define STL_MAP_LIST


void main()
{
	setlocale(LC_ALL, "");

#ifdef  STL_SET

	std::set <int> myset = { 50,25,75,16,32,64,80 };
	//for (int i = 0; i < myset.size(); i++)
	//{
	//	cout << myset[i] << tab;
	//}

	for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	int value;
	cout << "Введите добавляемое значение:"; cin >> value;
	myset.insert(value);
	for (int i : myset)cout << i << tab; cout << endl;

	cout << "Введите удаляемое значение:"; cin >> value;
	myset.erase(value);
	for (int i : myset)cout << i << tab; cout << endl;
	for (std::set<int>::iterator it = myset.lower_bound(25); it != myset.upper_bound(75); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::set<int>::iterator it = myset.find(25); it != myset.find(75); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;


#endif //STL_SET

#ifdef  STL_MAP

	std::map<int, std::string> week
	{
		std::pair<int,std::string>(0, "Sunday"),
		std::pair<int,std::string>(1, "Monday"),
		std::pair<int,std::string>(2, "Tuesday"),
		std::pair<int,std::string>(3, "Wednesday"),
		std::pair<int,std::string>(4, "Thrusdae"),
		std::pair<int,std::string>(5, "Friday"),
		std::pair<int,std::string>(6, "Saturday"),
		//{6, "Saturday" },упращенная запись
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
#endif // STL_MAP

#ifdef STL_MAP_LIST
	std::map<std::string, std::list<std::string>>dictionary
	{
		std::pair<std::string,std::list<std::string>>("splase",{"сваривание","сращивание","свадьба"}),

		{"reconnaissance",{"разведка","зондирование"}},
		{"spase" ,{"космос","пространство","пробел"}},
		{"pencil",{"карандаш"}},
		{"desk",{"рабочий стол","доска"}},
		{"prohibit",{"запрещать"}},
		{"appreciate",{"быть признательным","ценить","быть благодарным"}}

	};
	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout.width();
		cout << std:: left;
		cout << it->first + " : " ;
		for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt << ",";
		}
		cout << endl;
	}
	cout << "\n----------------------------------\n";
	for (std::pair<std::string, std::list<std::string>> i : dictionary)
	{
		cout.width(14);
		cout << std::left;
		cout << i.first + ",";
		for (std::string j : i.second) cout << j << ",";
		cout << "\b\b;\n";
	}
#endif // STL_MAP_LIST

	


}