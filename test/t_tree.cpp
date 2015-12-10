#include "../tree.h"
using namespace tpl;

int main()
{
	tree mytree;
	#define _SIZE_ 7
	int data[_SIZE_];
	p_node nodes[_SIZE_];
	for(int i=0; i<_SIZE_; ++i)
	{
		data[i] = i;
		nodes[i] = mytree.addNode(data+i);
	}
	mytree.setRoot(nodes[0]);
	mytree.appendChild(nodes[0], nodes[1]);
	mytree.appendChild(nodes[0], nodes[2]);
	mytree.appendChild(nodes[1], nodes[3]);
	mytree.appendChild(nodes[1], nodes[4]);
	mytree.appendChild(nodes[2], nodes[5]);
	mytree.appendChild(nodes[2], nodes[6]);
	cout<<mytree.getParent(nodes[0])<<endl;
	cout<<mytree.getParent(nodes[1])<<endl;
	cout<<mytree.getParent(nodes[4])<<endl;
	cout<<mytree.isLeaf(nodes[1])<<endl;
	cout<<mytree.isLeaf(nodes[4])<<endl;
	vector<p_node> children;
	mytree.getChildren(nodes[0], children);
	vector<p_node>::iterator itr;
	itr = children.begin();
	for(; itr!=children.end(); itr++)
		cout<<*(int*)(*itr)->data<<"\t";
	return 0;
}
