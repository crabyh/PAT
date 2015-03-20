//
//  main.cpp
//  PAT1021
//
//  Created by Myh on 2/6/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
bool r[20000][20000]={};
using namespace std;
deque<int> result;
int maxmax=0;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin >> N;
    for(int i=1;i<N;i++){
        int x,y;
        cin>>x>>y;
        r[x][y]=r[y][x]=1;
    }
    
    for(int i=1;i<=1;i++){
        bool know[20000]={};
        int hight[20000]={};
        know[i]=1;
        deque<int> q;
        q.push_back(i);
        while(!q.empty()){
            int a=q.front();
            q.pop_front();
            for(int j=1;j<=N;j++){
                if(r[a][j]==1){
                    if(know[j]==0){
                        know[j]=1;
                        hight[j]=hight[a]+1;
                        q.push_back(j);
                    }
                }
            }
        }
        int compount=0;
        for(int k=1;k<=N;k++){
            if(hight[k]==0&&k!=i){
                compount++;
                know[k]=1;
                q.push_back(k);
                while(!q.empty()){
                    q.pop_front();
                    for(int j=1;j<=N;j++){
                        if(r[k][j]==1){
                            if(know[j]==0){
                                know[j]=1;
                                hight[j]=hight[k]+1;
                                q.push_back(j);
                            }
                        }
                    }
                }
            }
        }
        if(compount>0){
            cout<<"Error: "<<compount+1<<" components";
            return 0;
        }
    }
    int hight[20000]={};
    int max=0;
    int root=0;
    for(int i=1;i<=1;i++){
        bool know[20000]={};
        know[i]=1;
        deque<int> q;
        q.push_back(i);
        while(!q.empty()){
            int a=q.front();
            q.pop_front();
            for(int j=1;j<=N;j++){
                if(r[a][j]==1){
                    if(know[j]==0){
                        know[j]=1;
                        hight[j]=hight[a]+1;
                        if(hight[j]>max){
                            max=hight[j];
                            root=j;
                        }
                        q.push_back(j);
                    }
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(hight[i]==max)
            result.push_front(i);
        hight[i]=0;
    }
    for(int i=root;i<=root;i++){
        bool know[20000]={};
        know[i]=1;
        deque<int> q;
        q.push_back(i);
        while(!q.empty()){
            int a=q.front();
            q.pop_front();
            for(int j=1;j<=N;j++){
                if(r[a][j]==1){
                    if(know[j]==0){
                        know[j]=1;
                        hight[j]=hight[a]+1;
                        if(hight[j]>max){
                            max=hight[j];
                        }
                        q.push_back(j);
                    }
                }
            }
        }
    }
    for(int i=0;i<result.size();i++)
        hight[result[i]]=max;
    for(int i=1;i<=N;i++){
        if(hight[i]==max){
            cout<<i<<endl;
        }
    }
    return 0;
}

