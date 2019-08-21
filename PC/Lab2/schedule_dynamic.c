#include <omp.h>
#include <stdio.h>
int main(){
    int i;
    
    int n=100000;
    int a[n];

   // for(i=0;i<n;i++)
   //  a[i]=i;
    //int b[n];
    double start_time = omp_get_wtime();
    #pragma omp parallel 
    {
        #pragma omp for nowait schedule(dynamic,100)
        for(i=0; i<n;i++)
        {
            a[i]+=1;
        }
     }
        
    printf("dynamic scheduling time = %lfs\n",omp_get_wtime()-start_time);
}

