//
//  main.cpp
//  PAT1026
//
//  Created by Myh on 2/8/15.
//  Copyright (c) 2015 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

struct C{
    int arrive_time;
    int playing_time;
    int serve_time=-1;
    bool tag=0;
};
struct T{
    int no;
    int time;
    int num=0;
    bool tag=0;
};

int compare(struct C x,struct C y){
    return x.arrive_time<y.arrive_time;
}
int compare1(struct T* x,struct T* y){
    if(x->time==y->time)
        return x->no<y->no;
    return x->time<y->time;
}
int compare2(struct T* x,struct T* y){
    return x->no<y->no;
}
int compare3(struct C x,struct C y){
    return x.serve_time<y.serve_time;
}

struct C customer[10001];
struct T table[101];
string format(int x){
    string ret="";
    int hh,mm,ss;
    hh=x/3600;
    if(hh<10)
        ret+="0";
    ret+=to_string(hh);
    ret+=":";
    mm=x/60%60;
    if(mm<10)
        ret+="0";
    ret+=to_string(mm);
    ret+=":";
    ss=x%60;
    if(ss<10)
        ret+="0";
    ret+=to_string(ss);
    return ret;
}

int main(int argc, const char * argv[]) {
    
    int N,K,M;
    cin>>N;
    for(int i=0;i<N;i++){
        char ch;
        int hh,mm,ss;
        cin>>hh>>ch>>mm>>ch>>ss;
        customer[i].arrive_time=hh*3600+mm*60+ss;
        int play;
        cin>>play;
        if(play>120)
            play=120;
        customer[i].playing_time=play*60;
        cin>>customer[i].tag;
    }
    cin>>K>>M;
    for(int i=0;i<K;i++){
        table[i].no=i+1;
    }
    for(int i=0;i<M;i++){
        int m;
        cin>>m;
        table[m-1].tag=true;
    }
    // insert code here...
    sort(customer,customer+N,compare);
    int time=8*3600;
    int position=0;
    int vip_position=0;
    deque<struct T*> busy,free;
    for(int i=0;i<K;i++){
        free.push_back(table+i);
    }
    sort(free.begin(),free.end(),compare2);
    while(time<21*3600){
        for(int i=position;i<N;i++){
            if(customer[i].arrive_time<=time&&customer[i].serve_time==-1){
                if(customer[i].tag==1){
                    for(int j=0;j<free.size();j++){
                        if(free[j]->tag==1){
                            free.push_front(free[j]);
                            free.erase(free.begin()+j+1);
                            break;
                        }
                    }
                }
                break;
            }
        }
        
        if(free[0]->tag==1){
            for(int i=vip_position;i<N;i++){
                if(customer[i].arrive_time<=time&&customer[i].serve_time==-1&&customer[i].tag==1){
                    free[0]->time=customer[i].playing_time;
                    free[0]->num++;
                    customer[i].serve_time=time;
                    vip_position=i;
                    busy.push_back(free.front());
                    free.pop_front();
                    break;
                }
                if(customer[i].arrive_time>time)
                    break;
            }
        }
        if(!free.empty()&&free[0]->time==0){
            for(int i=position;i<N;i++){
                if(customer[i].arrive_time<=time&&customer[i].serve_time==-1){
                    free[0]->time=customer[i].playing_time;
                    free[0]->num++;
                    customer[i].serve_time=time;
                    busy.push_back(free.front());
                    free.pop_front();
                    position=i;
                    break;
                }
                if(customer[i].arrive_time>time)
                    break;
            }
        }
        sort(busy.begin(),busy.end(),compare1);
        int period=0;
        int flag=0;
        for(int i=position;i<N;i++){
            if(customer[i].serve_time==-1){
                period=customer[i].arrive_time-time;
                flag=1;
                break;
            }
        }
        if(flag==0) break;
        if(!free.empty()&&period<0)
            continue;
        if(busy.empty()){
            time+=period;
        }
        else if(free.empty()){
            period=busy[0]->time;
            for(int i=0;i<busy.size();i++){
                busy[i]->time-=period;
            }
            while(!busy.empty()&&busy[0]->time==0){
                free.push_back(busy.front());
                busy.pop_front();
            }
            sort(free.begin(),free.end(),compare2);
            time+=period;

        }
        else{
            if(busy[0]->time<period){
                period=busy[0]->time;
            }
            for(int i=0;i<busy.size();i++){
                busy[i]->time-=period;
            }
            int flag=0;
            while(!busy.empty()&&busy[0]->time==0){
                free.push_back(busy.front());
                busy.pop_front();
                flag=1;
            }
            if(flag==1)
                sort(free.begin(),free.end(),compare2);
            time+=period;
        }
    }
    
//        if(table[K-1].time==0){
//            for(int i=position;i<N;i++){
//                if(customer[i].serve_time==-1){
//                    time=customer[i].arrive_time;
//                    flag=1;
//                    break;
//                }
//            }
//            if(flag==0)
//                break;
//        }
//        int period=free[0]->time;
//        time+=period;
//        for(int i=0;i<K;i++){
//            table[i].time-=period;
//        }
//        if(flag==1)
//            flag=0;
//        else{
//            for(int i=position;i<N;i++){
//                if(customer[i].serve_time==-1){
//                    period=customer[i].arrive_time-time;
//                    for(int j=0;j<K;j++){
//                        if(table[j].time!=0&&table[j].time<period){
//                            period=table[j].time;
//                            break;
//                        }
//                    }
//                    time+=period;
//                    for(int j=0;j<K;j++){
//                        if(table[j].time!=0)
//                            table[j].time-=period;
//                    }
//                    break;
//                }
//            }
//        }
//    }
    
    sort(customer,customer+N,compare3);
    for(int i=0;i<N;i++){
        if(customer[i].serve_time!=-1){
            cout<<format(customer[i].arrive_time)<<" "<<format(customer[i].serve_time)<<" "<<(customer[i].serve_time-customer[i].arrive_time+30)/60<<endl;
        }
    }
    cout<<table[0].num;
    for(int i=1;i<K;i++){
        cout<<" "<<table[i].num;
    }
    return 0;
}
