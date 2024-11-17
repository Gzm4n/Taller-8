#define maxP 5
#define maxC 30

float storage(float *max);
void data(char name[maxP][maxC], float time[maxP], float rec[maxP]);
int search(char id[maxC], char name[maxP][maxC]);
void info(char name[maxP][maxC], float time[maxP], float rec[maxP]);
void fact(char name[maxP][maxC], float time[maxP], float rec[maxP], float *max);
void edition(char name[maxP][maxC], float time[maxP], float rec[maxP]);
void deletion(char name[maxP][maxC], float time[maxP], float rec[maxP]);