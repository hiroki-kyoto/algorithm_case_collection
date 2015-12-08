#include <iostream>
#include <vector>

namespace tpl
{
using namespace std;
// you can redefine these types to change precision
// or extends its topological scale
typedef void * t_data;
enum t_flag
{
	FLAG_DEFAULT = 0,
	FLAG_ACTIVE = 1,
	FLAG_DEAD = 2,
};

// node data structure
struct node
{
	t_data data; // data
	t_flag state; // flag
};

typedef node * p_node;
typedef double t_weit;

// connection data structure
struct conn
{
	p_node head; // head node
	p_node tail; // tail node
	t_weit weit; // weight between head and tail
};

typedef conn * p_conn;

/**************************************************
 * Connection based definition of tree.
 * Everything is based on connection.
 * Tree is a specialized network topo.
 * APIs:
 * p_node addNode(t_data, t_flag=FLAG_DEFAULT);
 * void delNode(p_node);
 * p_conn addConn(p_node, p_node, t_weit=0);
 * p_conn getConn(p_node, p_node);
 * void delConn(p_conn);
**************************************************/
class net
{
private:
	vector<pnode> nodes;
	vector<pconn> conns;
public:
	net();
	~net();
	p_node addNode(t_data data, t_flag flag=FLAG_DEFAULT);
	void delNode(p_node node_ptr);
	p_conn addConn(p_node head, p_node tail, t_weit weit=0);
	p_conn getConn(p_node head, p_node tail);
	void delConn(p_conn conn_ptr);
};


// the implementation
net::net()
{
	// print progress information for debugging
	cout<<"constructing net !"<<endl;
}

net::~net()
{
	// print information
	cout<<"destroying net !"<<endl;
	// finalizing
	vector<p_node>::iterator itr;
	itr =  nodes.begin();
	while(itr!=nodes.end())
	{
		delete (p_node)(*itr);
		cout<<"free node "<<(int)(*itr)<<endl;
		itr ++;
	}
	// free connections
	vector<p_conn>::iterator conn_itr;
	conn_itr = conn.begin();
	while(conn_itr!=conns.end())
	{
		delete (p_conn)(*conn_itr);
		cout<<"free connection "<<(int)(*conn_itr)<<endl;
		conn_itr ++;
	}
	// job done
	cout<<"job done !"<<endl;
}


p_node net::addNode(t_data data, t_flag flag)
{
	p_node node_ptr;
	node_ptr = new node(data, flag);
	return node_ptr;
}


};
