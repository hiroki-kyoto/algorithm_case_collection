// main.cpp
#include "algorithm.h"
#include <iostream>
#include <fstream>

using namespace std;

// unit test
int main(int argc, const char** argv)
{
	vector<int> input;
	vector<int> output;

	// read the input data file
	ifstream ifs;

	if(argc<2)
		cout<<endl<<" Error: \n\tUsage: [program name] [random integer data filename]"<<endl;

	ifs.open(argv[1]);
	
	int number;
	input.clear();

	char chr;
	ifs.get(chr);

	while(chr!='$')
	{
		ifs>>number;
		input.push_back(number);
		ifs.get(chr);
	}

	ifs.close();

	// applying the algorithm
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

