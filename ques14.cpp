#include<iostream>
#include<thread>
using namespace std;

int global_sum = 0;

void calculate_sum(int *arr, int n, int half){
    int local_sum = 0;
    if (half == 1){
        // sum of first half
        for (int i = 0; i < n/2; i++){
            local_sum+=arr[i];
        }
    }
    else{
        // sum of second half
        for (int i = n/2; i < n; i++){
            local_sum+=arr[i];
        }
    }
    global_sum += local_sum;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    thread t1(calculate_sum, arr, 20, 1);
    thread t2(calculate_sum, arr, 20, 2);
    t1.join();
    t2.join();
    cout << "sum is : " << global_sum<<endl;
    return 0;
}
