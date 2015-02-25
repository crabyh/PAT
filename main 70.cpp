//
//  main.cpp
//  PAT1018
//
//  Created by Myh on 10/27/14.
//  Copyright (c) 2014 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
struct S{
    int num=0;
    deque<int> from;
    bool known=0;
    int d=0;
};
struct S s[501];
int r[501][501]={};
int main(int argc, const char * argv[]) {
    int C, N, S, M;
    cin>>C>>N>>S>>M;
    for(int i=1;i<=N;i++)
        cin>>s[i].num;
    for(int i=0;i<M;i++){
        int x,y,d;
        cin>>x>>y>>d;
        r[x][y]=r[y][x]=d;
    }
    s[0].known=1;
    deque<int> q;
    q.push_back(0);  //the root node
    while(q.size()>0){  //depth first search
        int cur_s=q.front();
        s[cur_s].known=1;
        q.pop_front();  //pop node
        for(int j=1;j<500;j++){
            if(r[cur_s][j]!=0){ //has a road
                if(s[j].known==0){  //first time been found
                    s[j].known=1;
                    s[j].d=r[cur_s][j]+s[cur_s].d;
                    s[j].from.push_back(cur_s);
                    q.push_back(j);
                }
                else if(s[j].known==1){ //has been found
                    if(s[j].d>r[cur_s][j]+s[cur_s].d){  //found a shorter path
                        s[j].d=r[cur_s][j]+s[cur_s].d;
                        s[j].from.clear();  //delete all the previous node
                        s[j].from.push_back(cur_s);
                        q.push_back(j);
                    }
                    else if(s[j].d==r[cur_s][j]+s[cur_s].d){
                        s[j].from.push_back(cur_s); //add a previous node
                    }
                }
            }
        }
    }
    deque <deque<int>> p;
    deque<int> p1;
    p1.push_back(S);
    p.push_back(p1);
    int exit=1;
    while(exit){
        exit=0;
        for(int i=0;i<p.size();i++){
            if(p[i].back()!=0){
                exit=1;
                if(s[p[i].back()].from.size()==1){  //only one previous node
                    p[i].push_back(s[p[i].back()].from[0]);
                }
                else if(s[p[i].back()].from.size()>1){  //more one previous node
                    for(int j=1;j<s[p[i].back()].from.size();j++){
                        p.push_back(p[i]);
                        p.back().push_back(s[p[i].back()].from[j]);
                    }
                    p[i].push_back(s[p[i].back()].from[0]);
                }
            }
        }
    }
    int index=0;
    int minmin=-60000;
    int lleft=0;
    int min, left, total;
    for(int i=0;i<p.size();i++){
        min=left=total=0;
        for(int j=(int)p[i].size()-2;j>=0;j--){
//            cout<<p[i][j]<<" ";
            total+=s[p[i][j]].num-C/2;
            if(total<min)   min=total;
        }
        left=min<0?total-min:total;
        if(min>minmin){
            minmin=min;
            lleft=left;
            index=i;
        }
        else if(min==minmin&&left<lleft){
            lleft=left;
            index=i;
        }
    }
    cout<<-minmin<<" ";
    cout<<p[index].back();
    for(int j=(int)p[index].size()-2;j>=0;j--){
        cout<<"->"<<p[index][j];
    }
    cout<<" "<<lleft;
    // insert code here...
    return 0;
}
