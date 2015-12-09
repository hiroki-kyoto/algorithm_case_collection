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

// dump method for this type
void dump_flag(t_flag flag)
{
	switch(flag)
	{
		case FLAG_DEFAULT:
		cout<<"FLAG_DEFAULT";
		break;
		case FLAG_ACTIVE:
		cout<<"FLAG_ACTIVE";
		break;
		case FLAG_DEAD:
		cout<<"FLAG_DEAD";
		break;
		default:
		cout<<"UNKNOWN FLAG!";
		break;
	}
}

// node data structure
struct node
{
	t_data data; // data
	t_flag flag; // flag
};

typedef node * p_node;
typedef double t_weit;

// dump node method
void dump_node(p_node node_ptr)
{
	cout<<"node:";
	cout<<"\n\tdata=";
	cout<<node_ptr->data;
	cout<<"\n\tflag=";
	dump_flag(node_ptr->flag);
}

// connection data structure
struct conn
{
	p_node head; // head node
	p_node tail; // tail node
	t_weit weit; // weight between head and tail
};

typedef conn * p_conn;

// dump method for connection
void dump_conn(p_conn conn_ptr)
{
	cout<<"conn: ";
	cout<<"\n\thead=";
	dump_node(conn_ptr->head);
	cout<<"\n\ttail=";
	dump_node(conn_ptr->tail);
	cout<<"\n\tweit="<<conn_ptr->weit;
}

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
	vector<p_node> nodes;
	vector<p_conn> conns;
public:
	net();
	~net();
	p_node addNode(t_data data, t_flag flag=FLAG_DEFAULT);
	void delNode(p_node node_ptr);
	p_conn addConn(p_node head, p_node tail, t_weit weit=0);
	p_conn getConn(p_node head, p_node tail);
	void delConn(p_node head, p_node tail);
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
	// free connections
	vector<p_conn>::iterator conn_itr;
	conn_itr = conns.begin();
	while(conn_itr!=conns.end())
	{
		cout<<"free connection: ";
		dump_conn(*conn_itr);
		cout<<endl;
		delete (p_conn)(*conn_itr);
		conn_itr ++;
	}
	// free nodes
	vector<p_node>::iterator itr;
	itr =  nodes.begin();
	while(itr!=nodes.end())
	{
		cout<<"free node: ";
		dump_node(*itr);
		cout<<endl;
		delete (p_node) (*itr);
		itr ++;
	}
	// job done
	cout<<"job done !"<<endl;
}


p_node net::addNode(t_data data, t_flag flag)
{
	p_node node_ptr;
	node_ptr = new node;
	node_ptr->data = data;
	node_ptr->flag = flag;
	nodes.push_back(node_ptr);
	return node_ptr;
}

void net::delNode(p_node node_ptr)
{
	vector<p_node>::iterator itr;
	itr = nodes.begin();
	while(itr!=nodes.end())
	{
		if(*itr==node_ptr)
		{
			nodes.erase(itr);
			break;
		}
		itr++;
	}
	delete node_ptr;
}

p_conn net::addConn(
	p_node head, 
	p_node tail, 
	t_weit weit)
{
	p_conn conn_ptr;
	conn_ptr = new conn;
	conn_ptr->head = head;
	conn_ptr->tail = tail;
	conn_ptr->weit = weit;
	conns.push_back(conn_ptr);
	return conn_ptr;
}

p_conn net::getConn(p_node head, p_node tail)
{
	// search by linear method
	vector<p_conn>::iterator itr;
	for(itr=conns.begin(); itr!=conns.end(); itr++)
	{
		if((*itr)->head==head&&(*itr)->tail==tail)
		{
			return *itr;
		}
	}
	// not found
	return NULL;
}

void net::delConn(p_node head, p_node tail)
{
	vector<p_conn>::iterator itr;
	p_conn conn_ptr;
	for(itr=conns.begin(); itr!=conns.end(); ++itr)
	{
		if((*itr)->head==head && (*itr)->tail==tail)
		{
			conn_ptr = *itr;
			conns.erase(itr);
			break;
		}
	}
	// delete connection physically
	delete (p_conn) conn_ptr;
}

};
