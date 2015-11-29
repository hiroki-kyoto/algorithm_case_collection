#include <iostream>

using namespace std;

struct node
{
	int data;
	node *parent;
	int chn;	// number of children
	node **chd;	// children list
	int pos;	// current child position
};

void n_create(node *n)
{
	n->parent = NULL;
	n->chn = 0;
	n->chd = NULL;
	n->pos = -1;
}

void n_destroy(node *n)
{
	delete[] (node**)(n->chd);
	delete (node*)n;
}

// double linked tree
struct tree
{
	node *root;	// root of tree
	int depth;	// depth of tree
	node *flag;	// pointer of current node
	int level;	// current search level
	int count;	// number of nodes in tree
};

// double linked queue
struct queue
{
	node *head;	// head of queue
	node *flag;	// current pointer
	node *tail;	// tail of queue
	int count;	// length of nodes in queue
};

// queue creation
void q_create(queue *q)
{
	q->head = new node;
	n_create(q->head);
	q->flag = q->tail = q->head;
	q->count = 0;
}

void q_destroy(queue *q)
{
	while(q->count>0)
	{
		q->flag = q->tail->parent;
		n_destroy(q->tail);
		q->tail = q->flag;
		q->count --;
	}
	// remove the head
	n_destroy(q->head);
	delete (queue*)q;
}

void t_create(tree *t)
{
	t->root = new node;
	n_create(t->root);
	t->depth = 0;
	t->flag = t->root;
	t->level = 0;
	t->count = 0;
}

// add new nodes to tree, at the position of where flag is.
// put node to be one of the son of what pointer flag referring to.
void t_add(tree *t, node **chd, int chn)
{
	t->flag->chd = chd;
	t->flag->chn = chn;
	t->flag->pos ++;
	t->flag = t->flag->chd[t->flag->pos];
	t->depth ++;
	t->level ++;
	t->count += chn;
}

bool t_up(tree *t)
{
	if(t->flag==t->root)
		return false;
	t->flag = t->flag->parent;
	t->level --;
	return true;
}

bool t_down(tree *t)
{
	if(t->flag->pos+1==t->flag->chn) // include situation that satisfy [chn=0]
		return false;
	t->flag->pos ++;
	t->flag = t->flag->chd[t->flag->pos];
	t->level ++;
	return true;
}

// queue add
void q_add(queue *q, node *e)
{
	q->tail->chd = new (node*)[1];
	q->tail->chd[0] = e;
	e->parent = q->tail;
	q->tail = e;
	q->count ++;
}

// queue pop
node* q_pop(queue *q)
{
	if(q->count<=0)
		return NULL;
	q->flag = q->head->chd[0];
	q->head->chd[0] = q->head->chd[0]->chd[0];
	q->head->chd[0]->parent = q->head;
	q->count --;
	return q->flag;
}

void t_destroy(tree *t)
{
	queue *q = new queue;
	q_create(q);
	// add root node to queue
	q_add(t->root);	
	while(count>0)
	{
		node *n = q_pop(q);
		for(int i=0; i<n->chn;i++)
			q_add(q, n->chd[i]);
		n_destroy(n);
		count --;
	}
	q_destroy(q);
	delete (tree*)t;
}

// define priority-queue tree search
// d : distance of each two point
// s : solution to return with
// n : dimension of s
int priority_queue_tree_search(const int **d, int *s, int n)
{
	// push a root node
	int cost = 0;
	tree *t = new tree;
	queue *q = new queue;
	t_create(t);
	q_create(q);
	// create tree
	t->depth = 5; // 6-1
	
	

	// finalizing
	t_destroy(t);
	q_destroy(q);
	delete[] (tree*)t;
	delete[] (queue*)q;

	return cost;
}


int main()
{
	int dist[5][5];	
	// dialog line
	dist[0][0] = -1; // means pretty big
	dist[1][1] = -1;
	dist[2][2] = -1;
	dist[3][3] = -1;
	dist[4][4] = -1;

	dist[0][1] = 20;
	dist[0][2] = 30;
	dist[0][3] = 10;
	dist[0][4] = 11;
	
	dist[1][2] = 16;
	dist[1][3] = 4;
	dist[1][4] = 2;
	
	dist[2][3] = 6;
	dist[2][4] = 7;
	
	dist[3][4] = 12;

	// the search result
	int solution[5];

	// now search the route to get the shortest path of loop
	int result = priority_queue__tree_search(dist, solution, 5);

	// print out answer
	cout<<"the shortest path is : ";
	for(int i=0; i<5; i++)
		cout<<solution[i]<<"-";
	cout<<endl;
	cout<<"the shortest path distance : "<<result<<endl;
	cout<<"done"<<endl;

	return 0;
}
