#include <iostream>
using namespace std;
class City{
public:
	City* pointer = NULL;
	bool need = 0, occupied = 0;
};
City* find_root(City* city){
	if (city->pointer == NULL)
		return city;
	else return find_root(city->pointer);
}
int main(){
	City city[1001];
	bool road[1001][1001] = {0};
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++){
		int x, y;
		cin >> x >> y;
		road[x-1][y-1] = 1;
	}
	for (int i = 0; i < K; i++){
		int x;
		cin >> x;
		city[x-1].need = 1;
	}
	for (int i = 0; i < N; i++){
		city[i].occupied = 1;
		for (int j = 0; j < N; j++){
			if (!city[j].occupied){
				for (int k = 0; k < N; k++){
					if (road[j][k] == 1&&!city[k].occupied){
						if (find_root(city + j) != find_root(city + k) && city[j].need == 1)
							find_root(city + k)->pointer = city + j;
						else if (find_root(city + j) != find_root(city + k) && city[k].need == 1)
							find_root(city + j)->pointer = city + k;
					}
				}
			}
		}
		int repair = 0;
		for (int j = 0; j < N; j++) {
			if (city[j].pointer == NULL&&city[j].need&&!city[j].occupied)
				repair++;
		}
		cout << repair-1 << endl;
		for (int j = 0; j < N; j++) city[j].pointer = NULL;
		city[i].occupied = 0;
	}
	system("pause");
}