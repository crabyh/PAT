//
//  main.cpp
//  PAT1013
//
//  Created by Myh on 10/13/14.
//  Copyright (c) 2014 Myh. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
class City{
public:
    City* pointer = NULL;
    bool occupied = 0;
};
class Road{
public:
    int x = 0;
    int y = 0;
    Road(int a,int b):x(a), y(b){}
};
deque<Road *> R;
City* find_root(City* city){
    if (city->pointer == NULL)
        return city;
    else{
        return find_root(city->pointer);
    }
}
int main(){
    City city[1001];
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        Road* road=new Road(x-1,y-1);
        R.push_back(road);
    }
    for (int i = 0; i < K; i++){
        int x;
        cin >> x;
        city[x-1].occupied = 1;
        for(int n=0;n<R.size();n++){
            int k=R[n]->x;
            int j=R[n]->y;
            if (!city[k].occupied&&!city[j].occupied){
                if (find_root(city + j) != find_root(city + k)){
                    find_root(city + k)->pointer = find_root(city + j);
                }
            }
            if(i%10==0){
                for(int j=0;j<i;j++)
                    city[j].pointer=find_root(city+j);
            }
        }
        int repair = 0;
        for (int j = 0; j < N; j++) {
            if (city[j].pointer == NULL&&!city[j].occupied)
                repair++;
        }
        cout << repair-1 << endl;
        for (int j = 0; j < N; j++) city[j].pointer = NULL;
        city[x-1].occupied = 0;
    }
}
