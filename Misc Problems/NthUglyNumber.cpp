#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int getNthUglyNumber(int n){
    int uglyNumbers[n];
    int i2=0,i3=0,i5=0;
    int next_mult_2=2, next_mult_3=3, next_mult_5=5, next_ugly_no=1;
    uglyNumbers[0] = 1;
    next_mult_2 = uglyNumbers[i2]*2;
    next_mult_3 = uglyNumbers[i3]*3;
    next_mult_5 = uglyNumbers[i5]*5;
    
    for(int i=1;i<n;i++){
        next_ugly_no = min(next_mult_2,min(next_mult_3, next_mult_5));
        
        uglyNumbers[i] = next_ugly_no;
        if(next_ugly_no == next_mult_2){
            i2+=1;
            next_mult_2 = uglyNumbers[i2]*2;
        }
        if(next_ugly_no == next_mult_3){
            i3+=1;
            next_mult_3 = uglyNumbers[i3]*3;
        }
        if(next_ugly_no == next_mult_5){
            i5+=1;
            next_mult_5 = uglyNumbers[i5]*5;
        }
    }
    return next_ugly_no;
}

int main()
{
    int ugly = getNthUglyNumber(150);
    cout<< ugly;

    return 0;
}
