//
//  main.cpp
//  PAT 1029
//
//  Created by Myh on 2/10/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <deque>
#include <stdio.h>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    long N;
    cin>>N;
    deque<long> q1,q2;
    for(int i=0;i<N;i++){
        long x;
        scanf("%ld",&x);
        q1.push_back(x);
    }
    cin>>N;
    for(int i=0;i<N;i++){
        long x;
        scanf("%ld",&x);
        q2.push_back(x);
    }
    long res=0;
    int p1=0,p2=0;
    int pos=(int)(q1.size()+q2.size()-1)/2;
    int last=0;
    while(p1+p2<=pos){
        if(p1==q1.size()){
            ++p2;
            last=2;
        }
        else if(p2==q2.size()){
            ++p1;
            last=1;
        }
        else{
            if(q1[p1]<=q2[p2]){
                ++p1;
                last=1;
            }
            else{
                ++p2;
                last=2;
            }
        }
    }
    if(last==1)
        res=q1[p1-1];
    else
        res=q2[p2-1];
    printf("%ld",res);
    return 0;
}


//
//  main.cpp
//  PAT 1029
//
//  Created by Myh on 2/10/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//
//
//#include <iostream>
//#include <algorithm>
//#include <deque>
//#include <stdio.h>
//using namespace std;
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    long N;
//    cin>>N;
//    deque<long> q;
//    for(int i=0;i<N;i++){
//        long x;
//        scanf("%ld",&x);
//        q.push_back(x);
//    }
//    cin>>N;
//    for(int i=0;i<N;i++){
//        long x;
//        scanf("%ld",&x);
//        q.push_back(x);
//    }
//    sort(q.begin(),q.end());
//    printf("%ld",q[(q.size()-1)/2]);
//    return 0;
//}

