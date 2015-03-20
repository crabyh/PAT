//
//  main.cpp
//  PAT1008
//
//  Created by Myh on 10/1/14.
//  Copyright (c) 2014 myh. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int next_level, N, cost=0, last_level=0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> next_level;
        if(next_level>last_level)
            cost+=5+6*(next_level-last_level);
        else
            cost+=5+4*(last_level-next_level);
        last_level=next_level;
    }
    // insert code here...
    std::cout << cost;
    return 0;
}

