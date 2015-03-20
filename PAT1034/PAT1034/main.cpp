//
//  main.cpp
//  PAT1034
//
//  Created by Myh on 2/11/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool connect[2001][2001]={0};
int node_weight[2001]={0};
bool know[2001]={0};
map<string,int> name;
map<int,string> no;
class C{
public:
    int head;
    int mem;
};
int compare(C x, C y){
    return no[x.head]<no[y.head];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,K;
    cin>>N>>K;
    int node=0;
    for(int i=0;i<N;i++){
        string s1,s2;
        int w;
        cin>>s1>>s2>>w;
        if(!name.count(s1)){
            name[s1]=node;
            no[node]=s1;
            node++;
        }
        if(!name.count(s2)){
            name[s2]=node;
            no[node]=s2;
            node++;
        }
//        cout<<name[s1]<<" "<<name[s2]<<endl;
        connect[name[s1]][name[s2]]=connect[name[s2]][name[s1]]=1;
        node_weight[name[s1]]+=w;
        node_weight[name[s2]]+=w;
    }
    deque<int> q;
    deque<C> res;
    for(int i=0;i<no.size();i++){
        if(know[i]==0){
            int index=i;
            int member=1;
            int total_weight=node_weight[i];
            know[i]=1;
            q.push_back(i);
            while(!q.empty()){
                int k=q.front();
                q.pop_front();
                for(int j=0;j<no.size();j++){
                    if(connect[k][j]==1){
                        if(know[j]==0){
                            member++;
                            q.push_back(j);
                            know[j]=1;
                            total_weight+=node_weight[j];
                            if(node_weight[j]>node_weight[index]){
                                index=j;
                            }
                            else if(node_weight[j]==node_weight[index]){
                                if(no[j]<no[index])
                                    index=j;
                            }
                        }
                    }
                }
            }
            if(total_weight/2>K&&member>2){
                C c;
                c.head=index;
                c.mem=member;
                res.push_back(c);
            }
        }
    }
    sort(res.begin(),res.end(),compare);
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++){
        cout<<no[res[i].head]<<" "<<res[i].mem<<endl;
    }
    
    return 0;
}
