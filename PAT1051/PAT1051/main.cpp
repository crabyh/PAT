//
//  main.cpp
//  PAT1051
//
//  Created by Myh on 2/13/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int M,N,K;
    cin>>M>>N>>K;
    vector<int> stack;
    for(int i=0;i<K;i++){
        int min=1;
        int flag=1;
        for(int j=0;j<N;j++){
            int x;
            cin>>x;
            if(x>=min){
                for(int k=min;k<=x;k++){
                    stack.push_back(k);
                    if(stack.size()>M){
                        flag=0;
                    }
                }
                min=x+1;
            }
            if(x==stack.back()){
                stack.pop_back();
            }
            else if(x<stack.back()){
                flag=0;
            }
        }
        if(flag==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        stack.clear();
    }
    
    return 0;
}
