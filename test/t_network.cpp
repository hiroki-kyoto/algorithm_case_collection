#include "../network.h"

using namespace tpl;

int main(int argc, const char ** argv)
{
	net mynet;
	// data in double type
	#define _DATA_DIM_ 5
	double data[_DATA_DIM_];
	p_node nodes[_DATA_DIM_];
	for(int i=0; i<_DATA_DIM_; i++)
	{
		data[i] = 1.0*i;
		nodes[i] = mynet.addNode(data+i);
	}

	mynet.addConn(nodes[0], nodes[1]);
	mynet.addConn(nodes[0], nodes[3]);
	mynet.addConn(nodes[1], nodes[4]);
	mynet.addConn(nodes[2], nodes[2]);
	mynet.addConn(nodes[2], nodes[3]);
	mynet.addConn(nodes[3], nodes[2]);

	return 0;
}
