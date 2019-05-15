#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <float.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
// Define node 
typedef struct node{
	struct node *next;
	int it;  // interarrival time
	int at;  // arrival time
	int duration;  // duration time
    int priority;
} node;

// Define queue
typedef struct queue{
	node *head;
	node *tail;
	int size;
    double t;
} queue;

node *node_new(double it, double st);	// Create a new node
queue *q_new(); 						// Create a new queue
bool q_insert(queue *q, node *n);		// Insert node into queue
node *q_pop(queue *q);					// Pop a node out 

int rand_exp(double mean);			// Generate exponential RV with lambda rate
double rand_normal(double std, double mean);

