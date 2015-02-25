//
//  main.cpp
//  PAT1044
//
//  Created by Myh on 2/12/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
class R{
public:
    int front;
    int back;
};
int D[100010]={};
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    long long M;
    cin>>N>>M;
    deque<R> res;
    for(int i=1;i<=N;++i){
        scanf("%d",&D[i]);
    }
    int front=1, back=1;
    long long total=D[1];
    long long clost=100000000;
    while(back<=N){
        if(total<M){
            back++;
            total+=D[back];
        }
        else if(total>=M){
            if(total<clost){
                clost=total;
                res.clear();
                R r;
                r.front=front;
                r.back=back;
                res.push_back(r);
            }
            else if(total==clost){
                R r;
                r.front=front;
                r.back=back;
                res.push_back(r);
            }
            total-=D[front];
            front++;
        }
    }
    for(int i=0;i<res.size();++i){
        printf("%d-%d\n",res[i].front,res[i].back);
//        cout<<res[i].front<<"-"<<res[i].back<<endl;
    }
    
    
    
    return 0;
}
