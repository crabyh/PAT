//
//  main.cpp
//  PAT1047
//
//  Created by Myh on 2/13/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> cour[2600];
int main(int argc, const char * argv[]) {
    // insert code here...
    int N,K;
    scanf("%d %d", &N, &K);
    char name[5];
    int no;
    for(int i=0;i<N;++i){
        short course;
        scanf("%s",name);
        no=name[3]-'0'+(name[2]-'A')*10+(name[1]-'A')*260+(name[0]-'A')*260*26;
        short n;
        scanf("%hd",&n);
        for(int i=0;i<n;i++){
            scanf("%hd",&course);
            cour[course].push_back(no);
        }
    }
    for(int i=1;i<=K;i++){
        sort(cour[i].begin(),cour[i].end());
        printf("%d %lu\n",i,cour[i].size());
        for(int j=0;j<cour[i].size();j++){
            name[0]=cour[i][j]/260/26+'A';
            name[1]=cour[i][j]%6760/260+'A';
            name[2]=cour[i][j]%260/10+'A';
            name[3]=cour[i][j]%10+'0';
            name[4]='\0';
            printf("%s\n",name);
        }
    }
    
    return 0;
}
