// main.cpp
#include "algorithm.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

// unit test
int main(int argc, const char** argv)
{
	vector<int> input;
	vector<int> output;

	// read the input data file
	ifstream ifs;

	if(argc<3)
		cout<<endl<<" Error: \n\tUsage: [program name] [random integer data filename] [sorted number output file name]"<<endl;

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

	time_t t_start, t_end;
	
	t_start = clock();

	// applying the algorithm
	quick_sort(input, output);

	t_end = clock();

	// get statics of the program running time
	cout<<endl<<"PROGRAM SCALE IS : "<<input.size()<<endl;

	int t_cost = (t_end-t_start)*1000/CLOCKS_PER_SEC;
	cout<<endl<<"QUICK SORT ALGORITHM COST TIME: ";
	cout<<t_cost;
	cout<<" MilliSecond(s)."<<endl;

	// output file stream
	ofstream ofs(argv[2]);

	// print output
	vector<int>::iterator iter = output.begin();
	
	while(iter!=output.end())
	{
		ofs<<'#'<<*iter;
		iter++;
	}
	ofs<<'$';
	ofs.close();

	cout<<" SORTED RESULT SAVED TO FILE ["<<argv[2]<<"]."<<endl;

	return 0;
}
