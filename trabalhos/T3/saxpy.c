
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void saxpy(const float alpha,
        float* const x, 
        float* const y,
        const int size)
{
	for( int i = 0; i < size; i++ ) {
		y[i] = alpha * x[i] + y[i];
	}
}

void random_init(float* const data, const int size)
{
    for (int i = 0; i < size; ++i)
        data[i] = rand() / (float)RAND_MAX;
}

int main(void)
{
    const int N = 1000000;
    float *x, *y;
    float alpha = 2.0;
    struct timeval t0, t1;
    double elapsed_time;

    y = (float*)malloc(N*sizeof(float));
    x = (float*)malloc(N*sizeof(float));
    random_init(x, N);
    random_init(y, N);

    gettimeofday(&t0, NULL);
    saxpy( alpha, x, y, N );
    gettimeofday(&t1, NULL);

    elapsed_time = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_usec - t0.tv_usec)) / 1000000;
    printf( "saxpy N=%d time %.4f\n", N, elapsed_time );

    free(x);
    free(y);

    return 0;
}