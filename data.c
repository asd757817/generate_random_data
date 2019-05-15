#include "data.h"

// Create a queue
queue *q_new(){
    queue *q = malloc(sizeof(queue));
    if(q){
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;
        q->t = 0;
        return q;
    }
    else
        return NULL;
}

// Create a node
node *node_new(double it, double duration){
    node *tmp = malloc(sizeof(node));
    if(tmp){
        tmp->it = it;
        tmp->duration = duration;
        tmp->priority = rand()%10+1;
        tmp->at = 0;			// initialize
        tmp->next = NULL;
        return tmp;
    }
    else
        return NULL;
}


// Add node to queue tail
bool q_insert(queue *q, node *n){
    if(!q | !n){
        return false;
    }
    else{
        n->at = q->t + n->it;
        q->t = n->at;
        if(q->head && q->tail){
            q->tail->next = n;
            q->tail = n;
        }
        else{
            q->head = n;
            q->tail = n;
        }		
        q->size += 1;
        return true;
    }
}

node *q_pop(queue *q){
    node *tmp = q->head;
    if(q->size == 1){
        q->head = NULL;
        q->tail = NULL;
    }
    else{
        q->head = q->head->next;
    }
    q->size -= 1;
    return tmp;
}
int rand_exp(double mean){
    const gsl_rng_type * T;
    gsl_rng * r;
    gsl_rng_env_setup();    // 讀取系統中與 gsl 相關的設定
    T = gsl_rng_default;    // 取得隨機變數產生器的型態（名稱）
    r = gsl_rng_alloc (T);  // 回傳一個指標，指向新建立的 gsl 隨機變數產生器
	unsigned int X = gsl_ran_poisson (r, mean); 

    return X;
}

double rand_normal(double std, double mean){
    double u = rand() / (double)RAND_MAX;
    double v = rand() / (double)RAND_MAX;
    double w = sqrt(-2 * log(u)) * cos(2 * M_PI * v);
    double x ;
    /* Condurationrain the value interval */
    return w;
}

