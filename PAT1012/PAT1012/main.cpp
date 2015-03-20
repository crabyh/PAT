//
//  main.cpp
//  PAT1012
//
//  Created by Myh on 10/5/14.
//  Copyright (c) 2014 myh. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
class S{
public:
    int No;
    int ID;
    int grade_C, grade_M, grade_E, grade_A;
    int rank_C, rank_M, rank_E, rank_A;
    int best_rank;
    char best_sub;
};

bool sort_C(S stu1,S stu2){
    return (stu1.grade_C>stu2.grade_C);
}

bool sort_M(S stu1,S stu2){
    return (stu1.grade_M>stu2.grade_M);
}

bool sort_E(S stu1,S stu2){
    return (stu1.grade_E>stu2.grade_E);
}

bool sort_A(S stu1,S stu2){
    return (stu1.grade_A>stu2.grade_A);
}

bool sort_No(S stu1,S stu2){
    return (stu1.No<stu2.No);
}


int main(int argc, const char * argv[])
{
    int N, M;
    cin >> N >> M;
    S stu[4001];
    for(int i=0;i<N;i++){
        cin >> stu[i].ID >> stu[i].grade_C >> stu[i].grade_M >> stu[i].grade_E;
        stu[i].grade_A=(stu[i].grade_C+stu[i].grade_M+stu[i].grade_E)/3;
        stu[i].No=i;
    }
    
    sort(stu,stu+N,sort_C);
    stu[0].rank_C=1;
    for(int i=1;i<N;i++){
        stu[i].rank_C=i+1;
        if(stu[i].grade_C==stu[i-1].grade_C)
            stu[i].rank_C=stu[i-1].rank_C;
    }
    
    sort(stu,stu+N,sort_M);
    stu[0].rank_M=1;
    for(int i=1;i<N;i++){
        stu[i].rank_M=i+1;
        if(stu[i].grade_M==stu[i-1].grade_M)
            stu[i].rank_M=stu[i-1].rank_M;
    }
    
    sort(stu,stu+N,sort_E);
    stu[0].rank_E=1;
    for(int i=1;i<N;i++){
        stu[i].rank_E=i+1;
        if(stu[i].grade_E==stu[i-1].grade_E)
            stu[i].rank_E=stu[i-1].rank_E;
    }
    
    sort(stu,stu+N,sort_A);
    stu[0].rank_A=1;
    for(int i=1;i<N;i++){
        stu[i].rank_A=i+1;
        if(stu[i].grade_A==stu[i-1].grade_A)
            stu[i].rank_A=stu[i-1].rank_A;
    }
    sort(stu,stu+N,sort_No);
    for(int i=0;i<N;i++){
        if(stu[i].rank_A<=stu[i].rank_C&&stu[i].rank_A<=stu[i].rank_M&&stu[i].rank_A<=stu[i].rank_E){
            stu[i].best_rank=stu[i].rank_A;
            stu[i].best_sub='A';
        }
        else if(stu[i].rank_C<=stu[i].rank_A&&stu[i].rank_C<=stu[i].rank_M&&stu[i].rank_C<=stu[i].rank_E){
            stu[i].best_rank=stu[i].rank_C;
            stu[i].best_sub='C';
        }
        else if(stu[i].rank_M<=stu[i].rank_C&&stu[i].rank_M<=stu[i].rank_A&&stu[i].rank_M<=stu[i].rank_E){
            stu[i].best_rank=stu[i].rank_M;
            stu[i].best_sub='M';
        }
        else{
            stu[i].best_rank=stu[i].rank_E;
            stu[i].best_sub='E';
        }
    }
    for(int i=N;i<N+M;i++){
        cin >> stu[i].ID;
    }
    for(int i=N;i<N+M;i++){
        int flag=0;
        for(int j=0;j<N;j++){
            if(stu[i].ID==stu[j].ID){
                cout << stu[j].best_rank << " " << stu[j].best_sub << endl;
                flag=1;
            }
        }
        if(flag==0)
            cout << "N/A" <<endl;
    }
    return 0;
}

