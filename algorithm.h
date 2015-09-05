// quick_sort.h
// The implementation of quick sort algorithm
// To use this module, please include this header file to your program page
// author : Arron
// Date : Aug 29, 2015
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <queue>

// define constans
#define SAMPLE_SIZE 8

using namespace std;

// declaration
template <class T> 
T get_middle(const vector<T>& input);
template <class T> 
void quick_sort(const vector<T>& input, vector<T>& output);




// implementation
template <class T> 
T get_middle(const vector<T>& input)
{
	long n = input.size();
	T middle = NULL;

	if(n>SAMPLE_SIZE)
	{
		srand((unsigned) time(0));

		for(int i=0;i<SAMPLE_SIZE;i++)
			middle += input[rand()%n];
	}
	else
	{
		for(int i=0;i<n;i++)
			middle += input[i];
	}

	return middle/n;
}	
;

template <class T> 
void quick_sort(const vector<T>& input, vector<T>& output)
{
	int size = input.size();
	
	cout<<endl<<"####### INPUT  ########"<<endl;

	for(int i=0; i<size; i++)
		cout<<input[i]<<"\t";

	// using queue to replace callback stack
	queue< vector<T> > q;
	
	vector<T> lt;
	vector<T> rt;
	vector<T> ct;
	vector<T> head;
	vector<T> empty;
	empty.clear();
	
	//put input data into queue
	q.push(input);
	q.push(empty);

	// process queue
	bool over = false; // if all object has size of 1 within a loop, then set true
	int meet_size_more_than_1 = 0;
	int middle = 0;

	while(!over)
	{
		head = q.front();
		q.pop();
		// check if we go back to endnode
		if(head.size()==0)
		{
			if(meet_size_more_than_1==0)
				over = true;
			else
			{
				meet_size_more_than_1 = 0;
				q.push(head);
			}
			continue;
		}

		// check if the size
		if(head.size()>1)
			meet_size_more_than_1 ++;

		T middle = get_middle(head);
		int h_size = head.size();
		
		lt.clear();
		rt.clear();
		ct.clear();
		
		for(int i=0; i<h_size; i++)
		{
			T t = head[i];

			if(t>middle)
				lt.push_back(t);
			else if(t<middle)
				rt.push_back(t);
			else
				ct.push_back(t);
		}

		// add new pair node to back
		if(lt.size()>0)
			q.push(lt);
		if(ct.size()>0)
		{
			int ct_size = ct.size();
			for(int i=0; i<ct_size; i++)
			{
				vector<T> ct_v;
				ct_v.clear();
				ct_v.push_back(ct[i]);
				q.push(ct_v);
			}
		}
		if(rt.size()>0)
			q.push(rt);
	}

	// add to output
	output.clear();
	
	while(q.size()>0)
	{
		vector<T> v = q.front();
		output.push_back(v[0]);
		q.pop();
	}
	
	cout<<endl;

}

#endif
