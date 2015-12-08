#include <iostream>

namespace tpl
{
using namespace std;
// you can redefine these types to change precision
// or extends its topological scale
typedef unsigned long t_id;
typedef double t_wt;
typedef void * t_dt;
typedef unsigned char t_st;

// connection data structure
struct conn
{
	t_id f; // forward
	t_id b; // backward 
	t_wt w; // weight 
};

struct node
{
	t_dt d; // data type
	t_st s; // state of node
};

/**************************************
 * Connection based definition of tree.
 * Everything is based on connection.
 * Tree is a specialized network topo.
 * APIs:
 * void addElement(t_id);
 * void removeElement(t_id);
 * void 
**************************************/
class tree
{
private:
	
public:
	
};


};
