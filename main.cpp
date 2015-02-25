//
//  main.cpp
//  PAT1074
//
//  Created by Myh on 2/25/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
#include <map>
using namespace std;
class Node{
public:
    int before;
    int value;
    int next;
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int start,N,K;
    cin>>start>>N>>K;
    map<int,Node> m;
    int before=start;
    for(int i=0;i<N;++i){
        Node n;
        int ptr;
        cin>>ptr>>n.value>>n.next;
        m[ptr]=n;
    }
    int ptr=start;
    while(ptr!=-1){
        m[ptr].before=before;
        before=ptr;
        ptr=m[ptr].next;
    }
    int ptr_e=start;
    int ptr_s=start;
    int count=1;
//    ptr=start;
//    while(m[ptr].next!=-1){
//        printf("%05d %d %05d\n",ptr,m[ptr].value,m[ptr].next);
//        ptr=m[ptr].next;
//    }
//    printf("%05d %d %d\n",ptr,m[ptr].value,m[ptr].next);
    

    while(ptr_e!=-1){
        ptr_e=m[ptr_e].next;
        count++;
        if(ptr_e==-1){
            break;
        }
        int tmp_s=ptr_s;
        if(count==K){
            while(m[ptr_s].next!=ptr_e&&ptr_e!=ptr_s){
                if(ptr_s==start){
                    start=ptr_e;
                }
                else{
                    m[m[ptr_s].before].next=ptr_e;
                }
                m[m[ptr_s].next].before=ptr_e;
                m[m[ptr_e].before].next=ptr_s;
                int tmp=m[ptr_s].next;
                m[ptr_s].next=m[ptr_e].next;
                m[ptr_e].next=tmp;
                ptr_e=m[ptr_e].before;
                ptr_s=tmp;
            }
//            cout<<m[ptr_s].value<<" "<<m[ptr_e].value<<endl;
            if(m[ptr_s].next==ptr_e){
                if(ptr_s==start){
                    start=ptr_e;
                }
                else{
                    m[m[ptr_s].before].next=ptr_e;
                }
                m[ptr_s].next=m[ptr_e].next;
                m[ptr_e].next=ptr_s;
            }
            if(m[tmp_s].next!=-1){
                m[m[tmp_s].next].before=tmp_s;
            }
            else{
                break;
            }
            ptr_e=m[tmp_s].next;
            ptr_s=ptr_e;
//            cout<<tmp_s<<" "<<ptr_s<<" "<<ptr_e<<endl;
            count=1;
        }
    }
    ptr=start;
    while(m[ptr].next!=-1){
        printf("%05d %d %05d\n",ptr,m[ptr].value,m[ptr].next);
        ptr=m[ptr].next;
    }
    printf("%05d %d %d\n",ptr,m[ptr].value,m[ptr].next);
    
    return 0;
}
