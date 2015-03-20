//
//  main.cpp
//  PAT1030
//
//  Created by Myh on 2/10/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
class C{
public:
    bool know=0;
    int dis=0;
    deque<int> from;
};
C city[500];
int dis[500][500]={};
int cos[500][500]={};
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,M,S,D;
    cin>>N>>M>>S>>D;
    for(int i=0;i<M;i++){
        int x,y,d,c;
        cin>>x>>y>>d>>c;
        dis[x][y]=d;
        dis[y][x]=d;
        cos[x][y]=c;
        cos[y][x]=c;
    }
    deque<int>q;
    q.push_back(S);
    city[S].know=1;
    while(!q.empty()){
        int cur_city=q.front();
        q.pop_front();
        for(int i=0;i<N;i++){
            if(dis[cur_city][i]!=0){
                if(city[i].know==0){
                    city[i].know=1;
                    city[i].dis=city[cur_city].dis+dis[cur_city][i];
                    city[i].from.push_back(cur_city);
                    q.push_back(i);
                }
                else if(city[cur_city].dis+dis[cur_city][i]<city[i].dis){
                    city[i].dis=city[cur_city].dis+dis[cur_city][i];
                    city[i].from.clear();
                    city[i].from.push_back(cur_city);
                    q.push_back(i);
                }
                else if(city[cur_city].dis+dis[cur_city][i]==city[i].dis){
                    city[i].from.push_back(cur_city);
                    q.push_back(i);
                }
            }
        }
    }
    deque<int> c;
    deque<deque<int>> cc;
    c.push_back(D);
    cc.push_back(c);
    int flag=1;
    while(flag){
        flag=0;
        for(int i=0;i<cc.size();i++){
            if(cc[i].front()!=S){
                flag=1;
//                if(city[cc[i].back()].from.size()>1){
                    for(int j=1;j<city[cc[i].front()].from.size();j++){
                        cc.push_back(cc[i]);
                        cc.back().push_front(city[cc[i].front()].from[j]);
                    }
                    cc[i].push_front(city[cc[i].front()].from[0]);
//                }
            }
        }
    }
    int index=0, min=250000;
    for(int i=0;i<cc.size();i++){
        int cost=0;
        for(int j=0;j<cc[i].size()-1;j++){
//            cout<<"cc[i][j] "<<cc[i][j]<<" cc[i][j+1] "<<cc[i][j+1]<<" cos "<<cos[cc[i][j]][cc[i][j+1]]<<endl;
            cost+=cos[cc[i][j]][cc[i][j+1]];
        }
        if(cost<min){
            min=cost;
            index=i;
        }
    }
    cout<<cc[index][0];
    for(int i=1;i<cc[index].size();i++){
        cout<<" "<<cc[index][i];
    }
    cout<<" "<<city[D].dis;
    cout<<" "<<min;
    return 0;
}












