#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    

    if(argc != 3)
    {
        printf("Please check input format");
        exit(0);
    }

    //intialize variables
    double start_time, end_time;
    int N = atoi(argv[1]);
    int T = atoi(argv[2]);
    int i, j, current, next;
	current = 0;
	next = 1;

    //create 3D array with alternating flag

    double h[N][N][2];
    double g[N][N][2];


    //initialize the 3D array

    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            h[i][j][0] = 0;
            h[i][j][1] = 0;
            g[i][j][0] = 0;
            g[i][j][1] = 0;
        }
    }


    //initialize wall temperatures as 20 degrees

    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            h[0][i][0] = 20.0;
			h[i][0][0] = 20.0;
			h[N - 1][i][0] = 20.0;
			h[i][N - 1][0] = 20.0;
			h[i][j][0] = 20.0;
			g[0][i][0] = 20.0;
			g[0][i][0] = 20.0;
			g[N - 1][i][0] = 20.0;
			g[i][N - 1][0] = 20.0;
			g[i][j][0] = 20.0;
        }
    }

    //initialize fireplace

    double fireplace_start, fireplace_end;
    fireplace_start = 0.3 * N;
    fireplace_end = 0.7 * N;


    //initialize temperature of fireplace
	for (i = fireplace_start; i < fireplace_end; i++) {
		h[0][i][0] = 100.0;
		g[0][i][0] = 100.0;
	}

    //starting temperatures
    for (i = 0; i < N; i += N/8) {
		for (j = 0; j < N; j += N/8) {
			printf("%-.2f\t", h[i][j][current]);
		}
		printf("\n");
	}



    //sequential heat equations for number of iterations provided 

    start_time = omp_get_wtime();
    
    for (int iterations=0; iterations < T; iterations++){
        for (i=0; i<N-1; i++){
            for (j=1; j < N-1; j++){
                h[i][j][next] = 0.25 * (h[i - 1][j][current] + h[i + 1][j][current] + h[i][j - 1][current] + h[i][j + 1][current]  );
            }
        }
        current = next;
        next = 1 - current;
    }

    end_time = omp_get_wtime();
    
    printf("\nFinal temperatures\n");
    for (i = 0; i < N; i += N/8) {
		for (j = 0; j < N; j += N/8) {
			printf("%-.2f\t", h[i][j][current]);
		}
		printf("\n");
	}

    printf("\nTime taken for sequential output %f \n", end_time-start_time);

    return 0;

} 
