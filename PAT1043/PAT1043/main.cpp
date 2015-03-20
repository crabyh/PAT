//
//  main.cpp
//  PAT1043
//
//  Created by Myh on 2/12/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
deque<int> pre, post;
int res=1;
void tree(int node,int end,int flag){
    if(node==end){
        post.push_back(node);
        return;
    }
    int i=node+1;
    for(;i<=end;i++){
        if(flag==0){
            if(pre[i]>=pre[node])
                break;
        }
        else{
            if(pre[i]<pre[node])
                break;
        }
    }
    i--;
    for(int j=i+1;j<=end;j++){
        if(flag==0){
            if(pre[j]<pre[node]){
                res=0;
                return;
            }
        }
        else{
            if(pre[j]>=pre[node]){
                res=0;
                return;
            }
        }
    }
    if(i>=node+1)
        tree(node+1,i,flag);
    if(i+1<=end)
        tree(i+1,end,flag);
    post.push_back(node);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        pre.push_back(x);
    }
    int flag=0;
    if(pre[1]>=pre[0]) flag=1;
    tree(0,N-1,flag);
    if(res==1){
        cout<<"YES"<<endl<<pre[post[0]];
        for(int i=1;i<post.size();i++){
            cout<<" "<<pre[post[i]];
        }
    }
    else cout<<"NO";
    return 0;
}
