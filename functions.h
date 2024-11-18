#define maxP 5
#define maxC 30

float storage(float *max);
int data(char name[maxP][maxC], float time[maxP], float rec[maxP], int *numP);
int search(char id[maxC], char name[maxP][maxC], int numP);
void info(char name[maxP][maxC], float time[maxP], float rec[maxP], int numP);
void fact(char name[maxP][maxC], float time[maxP], float rec[maxP], float *max, int numP);
void edition(char name[maxP][maxC], float time[maxP], float rec[maxP], int numP);
void deletion(char name[maxP][maxC], float time[maxP], float rec[maxP], int *numP);
void wholeData(int *numP, float *max, char name[maxP][maxC], float time[maxP], float rec[maxP]);
int productoPlus(char name [maxP][maxC], float time [maxP], float rec[maxP], int *numP);