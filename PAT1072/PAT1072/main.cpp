//
//  main.cpp
//  PAT1072
//
//  Created by Myh on 2/25/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int dis[1100][1100]={};
class C{
public:
    int no;
    int known=0;
    int dis=0;
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,M,K,DS;
    cin>>N>>M>>K>>DS;
    for(int i=0;i<K;++i){
        string s1, s2;
        int x,y;
        cin>>s1>>s2;
        if(s1[0]!='G'){
            x=atoi(s1.c_str())-1;
        }
        else{
            x=atoi(s1.substr(1).c_str())+N-1;
        }
        if(s2[0]!='G'){
            y=atoi(s2.c_str())-1;
        }
        else{
            y=atoi(s2.substr(1).c_str())+N-1;
        }
        cin>>dis[x][y];
        dis[y][x]=dis[x][y];
    }
    int minmin=0;
    double minavg=DS;
    int res=0;
    for(int ri=0;ri<M;++ri){
        vector<C> v;
        for(int i=0;i<N+M;i++){
            C c;
            c.no=i;
            v.push_back(c);
        }
        deque<C> q;
        q.push_back(v[ri+N]);
        v[ri+N].known=1;
        while (!q.empty()) {
            C c=q.front();
            q.pop_front();
            for(int i=0;i<N+M;++i){
                if(dis[c.no][i]!=0){
                    if(v[i].known==0){
                        v[i].known=1;
                        v[i].dis=dis[c.no][i]+c.dis;
                        q.push_back(v[i]);
                    }
                    else if(dis[c.no][i]+c.dis<v[i].dis){
                        v[i].dis=dis[c.no][i]+c.dis;
                        q.push_back(v[i]);
                    }
                }
            }
        }
        int flag=1;
        int min=DS, sum=0;
        for(int i=0;i<N;++i){
            if(v[i].dis>DS){
                flag=0;
                break;
            }
            if(v[i].dis<min){
                min=v[i].dis;
            }
            sum+=v[i].dis;
        }
        double avg=sum/(double)N;
        if(flag==1){
            if(min>minmin){
                res=ri;
                minmin=min;
                minavg=avg;
            }
            else if(min==minmin&&avg<minavg){
                res=ri;
                minmin=min;
                minavg=avg;
            }
        }
    }
    if(minmin==0&&minavg==DS){
        cout<<"No Solution";
    }
    else{
        cout<<"G"<<res+1<<endl;
        printf("%1.1lf %1.1lf",minmin+0.0,minavg);
    }
    return 0;
}
