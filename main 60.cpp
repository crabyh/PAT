//
//  main.cpp
//  PAT1007
//
//  Created by Myh on 9/29/14.
//  Copyright (c) 2014 myh. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    int a[11000]={0};
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    int sum=0, i_m=0, j_m=N-1, sum_m=-1;
    for(int i=0;i<N;i++){
        sum=0;
        for(int j=i;j<N;j++){
            sum+=a[j];
            if(sum>sum_m){
                i_m=i;j_m=j;
                sum_m=sum;
            }
        }
    }
    
    if(sum_m==-1)
        sum_m=0;

    // insert code here...
    std::cout << sum_m << " " << a[i_m] << " " << a[j_m] << endl;
    return 0;
}

