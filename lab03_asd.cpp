#include "myString.cpp"
#include "iostream"
using namespace std;
int main()
{
	try
	{
		int m1[4] = { 0,1,2,3 };
		int m2[4] = { 4,5,6,8 };
		bool l[4] = { true,true,true,false };
		myString <char> s("myString", 4);
		myString <char> s1("age", 3);		
		s1 = s + s1;
		cout << "Sum: " << s1 << endl;
		s = s * 2;
		cout << "Mull: " << s << endl;
		s = s(1, 2);
		cout << "Sub: " << s << endl;
		myString <int> i(m1, 4);
		myString <int> i1(m2, 4);
		i = i + i1;
		cout << "i==i1:";
		cout << (i1 == i) << endl;
		cout << "Sum: " << i << endl;
		i = i1 * 2;
		cout << "Mull: " << i << endl;
		i = i1(1, 3);
		cout << "Sub: " << i << endl;
		i = i1(1);
		cout << "Sub: " << i << endl;
		myString <bool> b(l, 4);
		cout << b << endl;
		
	}
	catch (const char* err)
	{
		cerr << "Error: " << err << endl;
	}
}
