//
//  main.cpp
//  PAT1039
//
//  Created by Myh on 2/12/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<short> stu[180000];
vector<int> cour[2600];
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,K;
    scanf("%d %d", &N, &K);
    char name[5];
    int no;
    for(int i=0;i<K;++i){
        short course,n;
        cin>>course>>n;
        for(int j=0;j<n;j++){
            scanf("%s",name);
            no=name[3]-'0'+(name[2]-'A')*10+(name[1]-'A')*260+(name[0]-'A')*260*26;
            cour[course].push_back(no);
        }
    }
    for(int i=1;i<=K;i++){
        for(int j=0;j<cour[i].size();j++){
            stu[cour[i][j]].push_back(i);
        }
    }
    for(int j=0;j<N;j++){
        scanf("%s",name);
        no=name[3]-'0'+(name[2]-'A')*10+(name[1]-'A')*260+(name[0]-'A')*260*26;
        printf("%s %lu", name, stu[no].size());
        for(int i=0;i<stu[no].size();++i){
            printf(" %d",stu[no][i]);
        }
        cout<<endl;
    }
    return 0;
}
