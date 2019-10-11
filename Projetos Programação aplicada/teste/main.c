#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
    struct timeval inicio, fim;
    double teste = 0.0, media=0.0;
    int i, soma=0, contador=0;

        gettimeofday(&inicio, NULL);

            for (i=0;i<100;i++)

        gettimeofday(&fim, NULL);
        teste=(fim.tv_usec-inicio.tv_usec)/1000.0;
        printf("TIME >>> %f\n", teste);

    return 0;
}
