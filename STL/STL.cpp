// STL.cpp :
#include <iostream>
#include<array>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "\n---------------------\n"


//#define STL_ARRAY
#define STL_VECTOR
//#define STL_DEGUE

int main()
{
	setlocale(LC_ALL, "");

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


#ifdef	STL_DEGUE

#endif // STL_DEGUE


}
