// main.cpp
#include "algorithm.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// unit test
int main(int argc, const char** argv)
{
	vector<int> input;
	vector<int> output;
	// in order to convert str to int, convert str to stream is required
	stringstream strm;
	int number;
	
	for(int i=1; i<argc; i++)
	{
		strm.clear();
		strm.str(argv[i]);
		strm>>number;
		input.push_back(number);
	}
	
	quick_sort(input, output);
	// print output
	vector<int>::iterator iter = output.begin();
	
	cout<<endl<<"############ OUTPUT ##############"<<endl;
	while(iter!=output.end())
	{
		cout<<*iter<<"\t";
		iter++;
	}
	cout<<endl;

	return 0;
}

