#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main (void)
{
    int n = 10000;
    double lambda_1 = 1.0;
    double lambda_2 = 4.0;
    /* 設立 gsl 所需要的環境 */
    const gsl_rng_type * T;
    gsl_rng * r;
    gsl_rng_env_setup();    // 讀取系統中與 gsl 相關的設定
    T = gsl_rng_default;    // 取得隨機變數產生器的型態（名稱）
    r = gsl_rng_alloc (T);  // 回傳一個指標，指向新建立的 gsl 隨機變數產生器

    FILE *fp = fopen("p.txt", "w");     // 紀錄隨機變數產生的結果
    /* 產生 n 個隨機變數 */
    for (int i = 0; i < n; i++) 
    {
        unsigned int X = gsl_ran_poisson (r, lambda_1);     // 以 mean=1 產生隨機變數
        unsigned int Y = gsl_ran_poisson (r, lambda_2);     // 以 mean=4 產生隨機變數
        unsigned int Z = gsl_ran_poisson (r, lambda_1+lambda_2); // 以 mean = 5 產生隨機變數
        fprintf (fp, "%u %u %u %u \n", X, Y, X+Y, Z); // 顯示 X、Y、X+Y、Z
    }
    /* 使用公式計算 P（X=k） */
    FILE *fp_2 = fopen("px.txt", "w");
    for (int k = 0; k < 16; k++) {
        double px = exp(-lambda_1)*pow(lambda_1, k);
        double py = exp(-lambda_2)*pow(lambda_2, k);
        double pz = exp(-(lambda_1+lambda_2))*pow((lambda_1+lambda_2), k);
        for(int i = 1; i <= k; i++){
            px /= i;
            py /= i;
            pz /= i;
        }
        fprintf(fp_2, "%lf %lf %lf\n", px, py, pz);
    }
    gsl_rng_free (r);
    return 0;
}
