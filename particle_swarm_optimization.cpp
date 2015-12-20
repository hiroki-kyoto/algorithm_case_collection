// particle_swarm_optimizatiom.cpp
// PSO Algorithm Implementation in C++
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// some program fixed parameters
const double inertia = 0.5;
const double pacc = 0.001; // particle acceleration
const double gacc = 0.002; // global acceleration
const double vmin = -0.1;
const double vmax = 0.1;
const double xmin = -2;
const double xmax = 5;
const double BASE = 10000;
const int SCALE = 1000;
const double MAX_GAP = 0.0001;
const int STOP_MACHINE_MAX_TICK = 100000;

// function declaration
inline double f(double x)
{
	double x2 = x*x;
	double x3 = x2*x;
	return x3 - 5*x2 - 2*x + 3;
}

inline int f_max(double * x)
{
	double max = x[0];
	int id = 0;
	for(int i=1; i<SCALE; i++)
	{
		if(x[i] > max)
		{
			max = x[i];
			id = i;
		}
	}
	return id;
}

inline int f_min(double * x)
{
	int id = 0;
	double min = x[0];
	for(int i=1; i<SCALE; i++)
	{
		if(x[i] < min)
		{
			id = i;
			min = x[i];
		}
	}
	return id;
}

inline double prand()
{
	return rand()%((int)BASE)/BASE;
}

double solve_max()
{
	// initilize a group of particles
	double v[SCALE];
	double x[SCALE];
	double fit[SCALE];
	double gbestf;
	double gbestx;
	double pbestf[SCALE];
	double pbestx[SCALE];
	double gbestf_last;
	// randomly given values
	for(int i=0; i<SCALE; i++)
	{
		x[i] = prand()*(xmax-xmin)+xmin;
		v[i] = prand()*(vmax-vmin)+vmin;
		// caculate its fitness
		fit[i] = f(x[i]);
		pbestf[i] = fit[i];
		pbestx[i] = x[i];
	}
	
	// update  global state of swarm
	int bestid = f_max(fit);
	gbestf = fit[bestid];
	gbestx = x[bestid];
	gbestf_last = gbestf;
	
	int tick = STOP_MACHINE_MAX_TICK;
	while(tick--)
	{
		// begin to change volecity of particles
		// and its position
		for(int i=0; i<SCALE; i++)
		{
			v[i] = inertia*v[i] 
				+ prand()*pacc*(pbestx[i]-x[i])
				+ prand()*gacc*(gbestx-x[i]);

			if(v[i]<vmin)
				v[i] = vmin;
			else if(v[i]>vmax)
				v[i] = vmax;
			
			x[i] += v[i];

			if(x[i]<xmin)
				x[i] = xmin;
			else if(x[i]>xmax)
				x[i] = xmax;

			// update fitness and particle best position
			fit[i] = f(x[i]);
			if(pbestf[i]<fit[i])
			{
				pbestf[i] = fit[i];
				pbestx[i] = x[i];
			}
		}

// why seperate?
// because local update can be parallel
// but global update cannot 
		// update  global state of swarm
		int bestid = f_max(fit);
		if(fit[bestid]>gbestf)
		{
			gbestf = fit[bestid];
			gbestx = x[bestid];
		}

		// check if it reaches stop condition
		if(gbestf-gbestf_last<=MAX_GAP)
			break;
		else
			gbestf_last = gbestf;
	}

	return gbestx;
}

double solve_min()
{
	// initilize a group of particles
	double v[SCALE];
	double x[SCALE];
	double fit[SCALE];
	double gbestf;
	double gbestx;
	double pbestf[SCALE];
	double pbestx[SCALE];
	double gbestf_last;
	// randomly given values
	for(int i=0; i<SCALE; i++)
	{
		x[i] = prand()*(xmax-xmin)+xmin;
		v[i] = prand()*(vmax-vmin)+vmin;
		// caculate its fitness
		fit[i] = f(x[i]);
		pbestf[i] = fit[i];
		pbestx[i] = x[i];
	}
	
	// update  global state of swarm
	int bestid = f_min(fit);
	gbestf = fit[bestid];
	gbestx = x[bestid];
	gbestf_last = gbestf;
	
	int tick = STOP_MACHINE_MAX_TICK;
	while(tick--)
	{
		// begin to change volecity of particles
		// and its position
		for(int i=0; i<SCALE; i++)
		{
			v[i] = inertia*v[i] 
				+ prand()*pacc*(pbestx[i]-x[i])
				+ prand()*gacc*(gbestx-x[i]);

			if(v[i]<vmin)
				v[i] = vmin;
			else if(v[i]>vmax)
				v[i] = vmax;
			
			x[i] += v[i];

			if(x[i]<xmin)
				x[i] = xmin;
			else if(x[i]>xmax)
				x[i] = xmax;

			// update fitness and particle best position
			fit[i] = f(x[i]);
			if(pbestf[i]>fit[i])
			{
				pbestf[i] = fit[i];
				pbestx[i] = x[i];
			}
		}

// why seperate?
// because local update can be parallel
// but global update cannot 
		// update  global state of swarm
		int bestid = f_min(fit);
		if(fit[bestid]<gbestf)
		{
			gbestf = fit[bestid];
			gbestx = x[bestid];
		}

		// check if it reaches stop condition
		if(gbestf_last-gbestf<=MAX_GAP)
			break;
		else
			gbestf_last = gbestf;
	}

	return gbestx;
}

int main()
{
	srand((unsigned)time(0));
	cout<<rand()%(int)(BASE)/BASE<<endl;
	double x_on_max;
	double x_on_min;
	x_on_max = solve_max();  
	x_on_min = solve_min();
	cout<<"WHEN X= "<<x_on_max;
	cout<<"F(X) REACHES ITS MAX = "<<f(x_on_max)<<endl;
	cout<<"WHEN X= "<<x_on_min;
	cout<<"F(X_ REACHES ITS MIN = "<<f(x_on_min)<<endl;

	return 0;
}
