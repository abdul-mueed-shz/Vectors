#include <iostream>
using namespace std;
#include <vector>
bool vectequal(vector<int>,vector<int>);

int main()
{
	vector<int>v1;
	
	vector<int>v2;



	for (int i = 0; i < 5; i++)
		{
		v1.push_back(i);
}


	for (int i = 0; i < 4; i++)
		{
		v2.push_back(i);
}


	if(vectequal(v1,v2)==true)
	{
		cout<<"Vectors are equal."<<endl;
	}
	else if(vectequal(v1,v2)==false)
	{
		cout<<"Vectors are not equal."<<endl;
	}
	system("pause");

}
bool vectequal(vector<int>v1,vector<int>v2)
{
	if(v1.size()==v2.size())
	{
		bool check=true;
		int temp=0;
		for(int y=0;y<v1.size();y++)
		{
			if(v1[y]==v2[y])
			{
				temp++;
			}
			else if(v1[y]!=v2[y])
			{
				check=false;
				break;
			}	
		}
		return check;
	}
	else if(v1.empty()==true&&v2.empty()==true)
	{
		return true;
	}
	else if(v1.size()!=v2.size())
	{
		return false;
	}
	
}

