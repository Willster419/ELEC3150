#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
template <class T>
class Base
{
private:
	T variables[4];
public:
	Base()
	{
		cout << "base created\n";
	}
	~Base()
	{
		cout << "base rekt\n";
	}
	void printArray()
	{
		for (int i = 0; i < 4; i++)
		{
			cout << "index " << i << " has value " << variables[i] << "\n";
		}
	}
	void setArray(T t0, T t1, T t2, T t3)
	{
		variables[0] = t0;
		variables[1] = t1;
		variables[2] = t2;
		variables[3] = t3;
	}
	T getAvg()
	{
		T temp = 0;
		for (int i = 0; i < 4; i++)
		{
			temp += variables[i];
		}
		return (T)temp/4;
	}
	T getMax()
	{
		T temp = 0;
		for (int i = 0; i < 4; i++)
		{
			if (variables[i] > temp)
			{
				temp = variables[i];
			}
		}
		return (T)temp;
	}
	T getMin()
	{
		T temp = variables[0];
		for (int i = 0; i < 4; i++)
		{
			if (variables[i] < temp)
			{
				temp= variables[i];
			}
		}
		return (T)temp;
	}
};

