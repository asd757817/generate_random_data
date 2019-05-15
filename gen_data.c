#include "data.h"
#include <string.h>

void gen(char *s, int x, double occur_rate, double duration);
int main(){
    srand((unsigned)time(NULL));
    gen("data_4.txt", 10000, 2, 1);
    /* gen("data_2.txt", 1000, 1, 2);  */
    /* gen("data_3.txt",1000,1,4);    */
    return 0;
}

void gen(char *s, int x, double occur_rate, double duration){
    int samples = x;
    FILE *fp = fopen(s, "w");
    queue *q_system = q_new();

    const gsl_rng_type * T;
    gsl_rng * r;
    gsl_rng_env_setup();    // 讀取系統中與 gsl 相關的設定
    T = gsl_rng_default;    // 取得隨機變數產生器的型態（名稱）
    r = gsl_rng_alloc (T);  // 回傳一個指標，指向新建立的 gsl 隨機變數產生器

    for(int i=0;i<samples;i++){
        unsigned int X = gsl_ran_poisson (r, occur_rate);
        unsigned int Y = 1 + gsl_ran_poisson (r, duration);
        if(q_insert(q_system, node_new(X, Y)))
            continue;
        else
            printf("Inset node failed !\n");
    }
    node *tmp = q_system->head;


    int count = 1;
    while(tmp){
        /* fprintf(fp, "P%d %d %d %d\n", count, tmp->priority, tmp->duration, tmp->at); */
        fprintf(fp, "P%d %d %d %d\n", count, tmp->priority, tmp->duration, count);
        count++;
        tmp = tmp->next;
    }


}
