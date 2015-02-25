//
//  main.cpp
//  PAT1046
//
//  Created by Myh on 2/13/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int dis[110000]={};
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    int total=0;
    for(int i=0;i<N;++i){
        int x;
        scanf("%d",&x);
        total+=x;
        dis[i+1]=total;
    }
    int M;
    cin>>M;
    for(int i=0;i<M;++i){
        int start, end;
        scanf("%d %d",&start,&end);
        if(start==end){
            cout<<0<<endl;
            continue;
        }
        start-=1;
        end-=1;
        if(end==0) end=N;
        int res1=start<end?dis[end]-dis[start]:total-dis[end]+dis[start];
        int res2=start>end?dis[start]-dis[end]:total-dis[end]+dis[start];
        
        printf("%d\n",min(res1,res2));
    }
    
    return 0;
}
