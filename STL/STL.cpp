// STL.cpp :

#include<array>
#include <iostream>
#include<vector>
#include<list>
#include<forward_list>

using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "\n---------------------\n"


//#define STL_ARRAY
//#define STL_VECTOR
#define STL_LIST
//#define STL_FORWARD_LIST

int main()
{
	setlocale(LC_ALL, "");

	int pos = 0;
	int value = 0;

#ifdef STL_ARRAY
	std::array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY
#ifdef STL_VECTOR

	std::vector<int>vec = { 0,1,1,2,3,5,8,13,21,34 };

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	cout << "Size:    " << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << delimiter << endl;
	vec.push_back(55);
	vec.pop_back();
	vec.pop_back();
	cout << "Size:    " << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << delimiter << endl;

	//vec.shrink_to_fit();
	//vec.reserve(10);
	vec.resize(5);
	vec.empty();

	cout << "Size:    " << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << delimiter << endl;
	try
	{
		//throw "My exaption";
		throw 4;
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << tab;
		 cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const char* e)
	{
		std::cerr << e << endl;
	}
	catch(int e)
	{
		std::cerr << "Error# " << e << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	//EHa
	catch (...)
	{
		std::cerr << "Someething happend " << endl;
	}
#endif //STL_VECTOR

#ifdef	STL_LIST
	
	std::list<int>mylist{ 1,2,3,4,5,6,7 };
	std::list<int>::iterator it = mylist.begin();

	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	cout << "Добавьте индекс элемента:"; cin >> pos;
	advance(it, pos);
	cout << endl;
	cout << "Добавьте  число элемента:"; cin >> value;
	mylist.insert(it, value);
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
	{
		cout << *it << tab;
	}

#endif // STL_LIST

#ifdef STL_FORWARD_LIST

	forward_list<int>list = { 11, 22,33,44,55,66 };
	forward_list <int>::iterator it;
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << "Добавьте индекс элемента:"; cin >> pos;
	cout << "Добавьте  число элемента:"; cin >> value;

	forward_list <int>::iterator new it = list.begin();
	for (int i = 0; i < pos - 1; ++i)
	{
		++new it;
	}
	it = list.insert_after(new it, value);
	cout << endl;
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		cout << *it << tab;
	}
#endif // STL_FORWARD_LIST



}
