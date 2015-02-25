//
//  main.cpp
//  PAT1014
//
//  Created by Myh on 10/14/14.
//  Copyright (c) 2014 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
void print_time(int minutes){
    if(minutes==-1){
        cout<<"Sorry\n";
        return;
    }
    int hours=8;
    hours+=minutes/60;
    minutes%=60;
    if(hours<10) cout<<"0";
    cout<<hours<<":";
    if(minutes<10) cout<<"0";
    cout<<minutes<<endl;

}
class Customer{
public:
    int No;
    int time;
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int finish[1001]={};
    int N, M, K, Q;
    deque<Customer *> customer;
    cin>>N>>M>>K>>Q;
    for(int i=0;i<K;i++){
        int x;
        cin>>x;
        Customer *c=new Customer;
        c->No=i;
        c->time=x;
        customer.push_back(c);
    }
    int time=0;
    int this_time=0;
    deque<Customer *> window[21];

    while(!customer.empty()){
        //黄线前站满人
        bool full=0;
        while(full==0){
            full=1;
            for(int i=0;i<N;i++){
                int min=0;
                for(int j=0;j<N;j++){
                    if(window[i].size()<window[min].size())
                        min=i;
                }
                if(window[min].size()<M&&!customer.empty()){
                    window[min].push_back(customer.front());
                    customer.pop_front();
                    full=0;
                    
                }
            }
        }
        int min=-1;
        while(window[++min].empty());
        for(int i=0;i<N;i++){
            if(window[i].empty()){
                continue;
            }
            if(window[i][0]->time<window[min][0]->time)
                min=i;
        }
        this_time=window[min][0]->time;
        time+=this_time;
        if(time>=540){
            for(int j=0;j<customer.size();j++)
                finish[customer[j]->No]=-1;
            for(int j=0;j<N;j++)
                if(window[j].size()>1)
                    for(int k=1;k<window[j].size();k++)
                        finish[window[j][k]->No]=-1;
        }
        if(finish[window[min][0]->No]!=-1)
            finish[window[min][0]->No]=time;
        else
            finish[window[min][0]->No]=-1;
        for(int i=0;i<N;i++)
            if(!window[i].empty())  window[i][0]->time-=this_time;
        delete window[min].front();
        window[min].pop_front();
        
    }
    
    //完成黄线前的人
    bool flag=1;
    while(flag){
        flag=0;
        for(int i=0;i<N;i++){
            if(!window[i].empty()){
                flag=1;
                break;
            }
        }
        if(flag==0) break;
        int min=-1;
        while(window[++min].empty());
        for(int i=0;i<N;i++){
            if(window[i].empty()){
                continue;
            }
            if(window[i][0]->time<window[min][0]->time)
                min=i;
        }
        this_time=window[min][0]->time;
        time+=this_time;
        if(time>=540){
            for(int j=0;j<N;j++)
                if(window[j].size()>1)
                    for(int k=1;k<window[j].size();k++)
                        finish[window[j][k]->No]=-1;
        }
        if(finish[window[min][0]->No]!=-1)
            finish[window[min][0]->No]=time;
        else
            finish[window[min][0]->No]=-1;
        for(int i=0;i<N;i++)
            if(!window[i].empty())  window[i][0]->time-=this_time;
        delete window[min].front();
        window[min].pop_front();
    }
    for(int i=0;i<Q;i++){
        int x;
        cin>>x;
        print_time(finish[x-1]);
    }
    return 0;
}
