#include "network.h"

namespace tpl
{

class tree:public net
{
private:
	p_node root;
	vector<p_node> nodes;
	vector<p_conn> conns;
public:
	void setRoot(p_node root);
	p_node getRoot();
	void appendChild(p_node parent, p_node child);
	void removeChild(p_node parent, p_node child);
	void getChildren(p_node parent, vector<p_node> &children);
	p_node getParent(p_node child);
	void getBrothers(p_node child, vector<p_node> &brothers);
	bool isLeaf(p_node leaf);
};

// implementation of these APIs.
void tree::setRoot(p_node root)
{
	this->root = root;
}

p_node tree::getRoot()
{
	return root;
}

void tree::appendChild(p_node parent, p_node child)
{
	// append child to parent
	addConn(parent, child);
}

void tree::removeChild(p_node parent, p_node child)
{
	// remove child of parent
	delConn(parent, child);
}

void tree::getChildren(p_node parent, vector<p_node> &children)
{
	// list all children under parent node
	vector<p_conn>::iterator itr;
	for(itr=conns.begin(); itr!=conns.end(); itr++)
	{
		if((*itr)->head==parent)
			children.push_back((*itr)->tail);
	}
}

p_node tree::getParent(p_node child)
{
	// search in connection list
	vector<p_conn>::iterator itr;
	itr = conns.begin();
	for(; itr!=conns.end(); itr++)
		if((*itr)->tail==child)
			return (*itr)->head;
	return NULL;
}

void tree::getBrothers(p_node child, vector<p_node> &brothers)
{
	// find its father and then find its brothers
	p_node parent = getParent(child);
	vector<p_conn>::iterator itr;
	itr = conns.begin();
	for(; itr!=conns.end(); itr++)
		if((*itr)->head==parent)
			if((*itr)->tail!=child)
				brothers.push_back((*itr)->tail);
}

bool tree::isLeaf(p_node leaf)
{
	vector<p_conn>::iterator itr;
	itr = conns.begin();
	for(; itr!=conns.end(); ++itr)
		if((*itr)->head==leaf)
			return false;
	return true;
}

}
