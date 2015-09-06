#ifndef RAND_NUM_GENERATOR_CPP
#define RAND_NUM_GENERATOR_CPP

// Generator of random integers
// rand_num_generator.cpp
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, const char **argv)
{
	// check input
	if(argc<3)
	{
		cout<<endl<<"Error: \n\tUsage: [program name] [randome number output file name] [random number count]"<<endl;
		return -1;
	}

	stringstream ss;
	ss.clear();
	ss.str(argv[2]);

	// seed of random sequence
	srand((unsigned) time(0));

	// how about to generator 100 integers?
	int rand_count;
	ss>>rand_count;

	// output filestream
	ofstream ofs(argv[1]);

	for(int i=0; i<rand_count; i++)
		ofs<<'#'<<(rand()%rand_count);

	// the last char is the mark to tell reader that this file is over
	ofs<<'$';

	ofs.close();

	return 0;
	
}

#endif
