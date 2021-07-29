#include <iostream>
#include <climits>

using namespace std;

int maxSum(int numbers[],int size){
    int max_till_now = INT_MIN;
    int max_ending_here = 0;
    for(int i=0;i<size;i++){
        max_ending_here+=numbers[i];
        if(max_till_now<max_ending_here){
            max_till_now = max_ending_here;
        }
        if(max_ending_here<0){
            max_ending_here = 0;
        }
        
    }
    return max_till_now;
    
}

int main()
{
    int num[] = {1,2,-3,4,9,-8,5};
    int length = sizeof(num)/sizeof(num[0]);
    int sum = maxSum(num,length);
    cout<<sum;
    
}
