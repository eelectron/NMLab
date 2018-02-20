/*Take real num  from user and store it in m x n matrix.*/
void scanMatrix(double **a, int m, int n ){
        for(int i=0; i<m; i++)
                for(int j=0; j<n; j++){
                        scanf("%lf", &a[i][j]);
                }
}

/*Print a m x n matrix on screen.*/
void printMatrix(double **a, int m, int n ){
        for(int i=0; i<m; i++){
                for(int j=0; j<n; j++)
                        printf("%+.2f ",a[i][j]);
                printf("\n");
        }
}