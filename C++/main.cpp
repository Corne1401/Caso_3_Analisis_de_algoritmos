#include <iostream>
#include <time.h>
#include <vector>
#include <chrono>
#include <windows.h>
#include <psapi.h>
using namespace std;


int main(){
    int n, i, j, position, swap;
    vector<unsigned int> a;

    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
    SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;
    SIZE_T physMemUsedByMe = pmc.WorkingSetSize;


    cout << "Enter number of elements" << endl;
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        a.push_back((unsigned)rand());
    }

    auto start = chrono::high_resolution_clock::now();

    
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

    auto elapsed = chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    cout << "Time elapsed: " << microseconds << " microseconds" << endl;
    cout << virtualMemUsedByMe << " | " << physMemUsedByMe << endl;
    // cout << "Sorted Array: " << endl;
    // for(i = 0; i < n; i++){
    //     cout << a[i] << endl;
    // }
    
    return 0;
}