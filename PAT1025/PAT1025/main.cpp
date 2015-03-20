//
//  main.cpp
//  PAT1025
//
//  Created by Myh on 2/8/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <map>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int compare(string x, string y){
    return x<y;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    map<string,int> location_number, local_rank;
    deque<string> q[101],q1[101];
    int N,K;
    cin>>N;
    int sum=0;
    for(int i=1;i<=N;i++){
        cin>>K;
        sum+=K;
        for(int j=1;j<=K;j++){
            string ID;
            int score;
            cin>>ID>>score;
            location_number[ID]=i;
            q[score].push_front(ID);
            q1[score].push_front(ID);
        }
        int rank=1;
        for(int j=100;j>=0;j--){
            int flag=0;
            for(int k=0;k<q1[j].size();k++){
                local_rank[q1[j][k]]=rank;
                flag++;
            }
            rank+=flag;
        }
        for(int j=0;j<=100;j++)
            q1[j].clear();
    }
    cout<<sum<<endl;
    int rank=1;
    for(int j=100;j>=0;j--){
        sort(q[j].begin(), q[j].end(), compare);
        int flag=0;
        for(int k=0;k<q[j].size();k++){
            cout<<q[j][k]<<" "<<rank<<" "<<location_number[q[j][k]]<<" "<<local_rank[q[j][k]]<<endl;
            flag++;
        }
        rank+=flag;
    }
    return 0;
}
