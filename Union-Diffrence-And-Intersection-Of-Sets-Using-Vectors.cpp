#include <iostream>
using namespace std;
#include <vector>

template <class T>
class SET
{
private:
	vector<T>v1;

public:

	SET()
	{

	}

	SET(int sizev1)//parametric constructor to take input;
	{
		T inp;

		for (int g = 0; g < sizev1; g++)
		{
			cin >> inp;

			if (check(v1, inp) == false)
			{
				cout << "can't enter same value,enter again" << endl;
				T inpagain;
				cin >> inpagain;
				while (check(v1, inpagain) != true)
				{
					system("cls");
					cin >> inpagain;
				}
				v1.push_back(inpagain);
			}
			else if (check(v1, inp) == true)
			{
				v1.push_back(inp);
			}

		}

	}





	void set(vector<T>vg1)//setting one vector to other
	{
		v1 = vg1;
	}

	bool check(vector<T>checkvect, T input)//for checking if element repeats
	{
		bool condi = true;

		for (int x = 0; x < checkvect.size(); x++)
		{
			if (checkvect[x] == input)
			{
				condi = false;
			}
		}
		return condi;

	}

	void setinput(int sizev1)//for taking input
	{

		T inp;

		for (int g = 0; g < sizev1; g++)
		{
			cin >> inp;

			if (check(v1, inp) == false)
			{
				cout << "can't enter same value,enter again" << endl;
				T inpagain;
				cin >> inpagain;
				while (check(v1, inpagain) != true)
				{
					system("cls");
					cin >> inpagain;
				}
				v1.push_back(inpagain);
			}
			else if (check(v1, inp) == true)
			{
				v1.push_back(inp);
			}

		}

	}
	vector<T> getset()//gives the set
	{
		return v1;
	}
	SET Union(SET set2)//finds union between two sets
	{
		vector<T>set2temp = set2.getset();

		vector<T>unionedvector;

		for (int x = 0; x < v1.size(); x++)
		{
			unionedvector.push_back(v1[x]);

		}
		for (int x = 0; x<set2temp.size(); x++)
		{
			bool condi = true;
			for (int j = 0; j<v1.size(); j++)
			{
				if (unionedvector[j] == set2temp[x])
				{
					condi = false;
				}
			}
			if (condi == true)
			{
				unionedvector.push_back(set2temp[x]);
			}
			else
			{
				continue;
			}
		}
		SET newset3;
		newset3.set(unionedvector);

		return newset3;
	}

	SET intersection(SET set2)//finds intersection between two sets
	{
		vector<T>set2again = set2.getset();
		vector<T>intervector;

		if (v1.size() >= set2again.size())
		{
			for (int g = 0; g < v1.size(); g++)
			{
				for (int j = 0; j < set2again.size(); j++)
				{
					if (v1[g] == set2again[j])
					{
						intervector.push_back(v1[g]);
					}
				}
			}
		}

		else if (v1.size() < set2again.size())
		{
			for (int g = 0; g < set2again.size(); g++)
			{
				for (int j = 0; j < v1.size(); j++)
				{
					if (set2again[g] == v1[j])
					{
						intervector.push_back(set2again[g]);
					}
				}
			}
		}

		SET newset1;
		newset1.set(intervector);

		return newset1;

	}

	SET diffrence(SET set2)//finds diffrence b/w two sets
	{
		vector<T>set2new = set2.getset();
		vector<T>diffrenceset;

		for (int j = 0; j < v1.size(); j++)
		{
			bool condi = true;
			for (int g = 0; g < set2new.size(); g++)
			{
				if (v1[j] == set2new[g])
				{
					condi = false;
				}
			}
			if (condi == true)
			{
				diffrenceset.push_back(v1[j]);
			}
			else if (condi == false)
			{
				continue;
			}
		}
		SET newset;
		newset.set(diffrenceset);

		return newset;
	}



	void printset()
	{
		for (int x = 0; x < v1.size(); x++)
		{
			cout << v1[x] << endl;
		}
	}



};

int main()//main for testing functions
{
	SET<char> a;

	a.setinput(4);
	cout << endl;
	SET<char> b(8);
	cout << endl;

	SET<char> unioned = a.Union(b);

	SET<char> intersec = a.intersection(b);

	SET<char> differ = b.diffrence(a);


	cout << "Diffrence between sets:" << endl;
	differ.printset();
	cout << "The union of two sets:" << endl;
	unioned.printset();
	cout << "Intersection between two sets:" << endl;
	intersec.printset();

	system("pause");
}
