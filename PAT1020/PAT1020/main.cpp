//
//  main.cpp
//  PAT1020
//
//  Created by Myh on 2/6/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
struct N{
    int l=-1;
    int r=-1;
    int post_order=-1;
    int in_order=-1;
    int level_order=-1;
};
struct N n[10000];
int a[2][10000];
int N;

void link(int node, int min=0){
    if (node==-1) return;
//    int l=n[node].in_order-1;
//    while(n[a[1][l]].post_order>=n[node].post_order&&l>min) l--;
//    if (l>min){
//        for(int i=min+1;i<n[node].in_order;i++){
//            if(n[a[1][i]].post_order>n[a[1][l]].post_order&&n[a[1][i]].post_order<n[node].post_order)
//                l=i;
//        }
//        if(n[a[1][l]].post_order<n[node].post_order)
//            n[node].l=a[1][l];
//    }
//    int r=n[node].in_order+1;
//    while(n[a[1][r]].post_order>=n[node].post_order&&r<=N) r++;
//    if(r<=N){
//        for(int i=r+1;i<=N;i++){
//            if(n[a[1][i]].post_order>n[a[1][r]].post_order&&n[a[1][i]].post_order<n[node].post_order)
//                r=i;
//        }
//        if(n[a[1][r]].post_order<n[node].post_order)
//            n[node].r=a[1][r];
//    }
    int p_post=n[node].post_order;
    int p_in=n[node].in_order;
    for (int i=p_post;i>0;i--){
        if (n[a[0][i]].in_order<p_in&&n[a[0][i]].in_order>min) {
            n[node].l=a[0][i];
            break;
        }
    }
    for (int i=p_post;i>0;i--){
        if (n[a[0][i]].in_order>p_in&&n[a[0][i]].in_order>min) {
            n[node].r=a[0][i];
            break;
        }
    }
    link(n[node].l,min);
    link(n[node].r,n[node].in_order);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> a[0][i];
        n[a[0][i]].post_order=i;
    }
    for(int i=1;i<=N;i++){
        cin >> a[1][i];
        n[a[1][i]].in_order=i;
    }
    link(a[0][N]);
    
    deque<int> q;
    q.push_back(a[0][N]);
    cout << q.front();
    while(!q.empty()){
        if(n[q.front()].l!=-1){
            cout << " " << n[q.front()].l;
            q.push_back(n[q.front()].l);
        }
        if(n[q.front()].r!=-1){
            cout << " " << n[q.front()].r;
            q.push_back(n[q.front()].r);
        }
        q.pop_front();
    }
        
    return 0;
}
