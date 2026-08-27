#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL)); //semente relacionada com o tempo do computador
    double N = 10000000;
    double dentro = 0;

    for(int i = 0; i < N; i++)
    {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        if (x * x + y * y <= 1)
        {
            dentro++;
        }
    }

    double pi = 4.0 * (double)dentro / (double)N;

    printf("Estimativa: %f\n", pi);
    return 0;
}
