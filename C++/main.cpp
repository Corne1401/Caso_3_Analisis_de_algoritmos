#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int a[100000], n, i, j, position, swap;

    cout << "Enter number of elements" << endl;
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        a[i] = (unsigned)rand();
    }

    clock_t tStart;
    tStart = clock();

    
    for(i = 0; i < n - 1; i++){
        position=i;
        for(j = i + 1; j < n; j++){
            if(a[position] > a[j]){
                position=j;
            }
        }
        if(position != i){
                swap=a[i];
                a[i]=a[position];
                a[position]=swap;
            }
    }
    
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    // cout << "Sorted Array: " << endl;
    // for(i = 0; i < n; i++){
    //     cout << a[i] << endl;
    // }
    
    return 0;
}