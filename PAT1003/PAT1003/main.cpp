#include <iostream>
#include <deque>
#define SIZE 501
using namespace std;

int main(){
	deque<int> Q;
	int clost_dis[SIZE];
	int short_num[SIZE];
	for (int i = 0; i < SIZE; i++){
		clost_dis[i] = -1;
		short_num[i] = 1;
	}
	int cities, roads, city_in, city_to;
	cin >> cities >> roads >> city_in >> city_to;
	int saver[SIZE];		//initialize saver&dis
	for (int i = 0; i < SIZE; i++){
		saver[i] = 0;
	}
	for (int i = 0; i < cities; i++){
		cin >> saver[i];
	}
	int dis[SIZE][SIZE];			//track the path 1 present path from i to j
	int saver_got[SIZE];
	for (int i = 0; i < SIZE; i++){
		saver_got[i] = saver[i];
	}
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			dis[i][j] = -1;
		}
	}

	for (int i = 0; i < roads; i++){		//initialize roads
		int city1, city2;
		cin >> city1 >> city2;
		cin >> dis[city1][city2];
		dis[city2][city1] = dis[city1][city2];
	}
	int know[SIZE];				//initialize know
	for (int i = 0; i < cities; i++){
		know[i] = 0;
	}
	for (int i = cities; i < SIZE; i++){
		know[i] = 1;
	}


	know[city_in] = 1;
	Q.push_back(city_in);
	clost_dis[city_in] = 0;
	while(Q.size()>0){  //involve other city
		int min = 0;
		for (int c = 1; c < Q.size(); c++){
			int a = Q[c]; int b = Q[min];
			if (a != -1 && b != -1){
				if (clost_dis[a]<clost_dis[b])
					min = c;
			}
		}
		int city = Q[min];
		Q[min] = Q[0];
		Q.pop_front();
			for (int j = 0 ; j < cities; j++){
				if (dis[city][j] != -1){
					if (clost_dis[j] == -1){
						clost_dis[j] = clost_dis[city] + dis[city][j];
						saver_got[j] = saver_got[city] + saver[j];
						short_num[j] = short_num[city];
						int flag = 0;
						for (unsigned int k = 0; k < Q.size(); k++){
							if (Q[k] == j){
								flag = 1;
								break;
							}
						}
						if (flag == 0)
							Q.push_back(j);
					}
					else if (clost_dis[j]>clost_dis[city] + dis[city][j]){
						clost_dis[j] = clost_dis[city] + dis[city][j];
						saver_got[j] = saver_got[city] + saver[j];
						short_num[j] = short_num[city];
						int flag = 0;
						for (unsigned int k = 0; k < Q.size(); k++){
							if (Q[k] == j){
								flag = 1;
								break;
							}
						}
						if (flag == 0)
							Q.push_back(j);
					}
					else if (clost_dis[j] == clost_dis[city] + dis[city][j]){

							short_num[j] += short_num[city];

						if (saver_got[j] < saver_got[city] + saver[j])
							saver_got[j] = saver_got[city] + saver[j];
						int flag = 0;
						for (unsigned int k = 0; k < Q.size(); k++){
							if (Q[k] == j){
								flag = 1;
								break;
							}
						}
						if (flag == 0){
							Q.push_back(j);
						}
					}
					
				}
			}

		know[city] = 1;
	}
	cout << short_num[city_to] << " " << saver_got[city_to] << endl;
	//system("pause");
	return 0;
}

