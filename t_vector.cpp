#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char** argv)
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	
	vector<int>::iterator itr;
	itr = vec.begin();
	while(itr!=vec.end())
	{
		if(*itr==2)
		{
			vec.erase(itr);
			break;
		}
		itr ++;
	}

	itr = vec.begin();
	while(itr!=vec.end())
	{
		cout<<*itr<<endl;
		itr ++;
	}

	return 0;
}
