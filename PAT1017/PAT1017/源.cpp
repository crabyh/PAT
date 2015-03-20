#include <iostream>
#include <deque>
#include <iomanip>
#include <algorithm>
using namespace std;
class Customer{
public:
	int arrive_time;
	int op_time;
	int original_op_time;
	int wait_time = 0;
	bool processed = false;
};
bool sort_op(Customer *i, Customer *j){
	return i->op_time < j->op_time;
}
bool sort_arrive(Customer *i, Customer *j){
	return i->arrive_time < j->arrive_time;
}
int main(int argc, char argv[]){
	//input all
	int N, K;
	cin >> N >> K;
	deque<Customer *>customer, processing;
	for (int i = 0; i < N; i++){
		int hh, mm, ss, op_time;
		char ch;
		cin >> hh >> ch >> mm >> ch >> ss >> op_time;
		if (op_time>60) op_time = 60; //???
		Customer * cptr = new Customer;
		cptr->arrive_time = hh * 3600 + mm * 60 + ss;
		cptr->op_time = cptr->original_op_time = op_time * 60;
		customer.push_back(cptr);
	}
	//calculating
	sort(customer.begin(), customer.end(), sort_arrive);
	int time = 8 * 3600;
	int No=0;
	while (No < min(K, (int)customer.size()) && customer[No]->arrive_time < 3600 * 8){
		processing.push_back(customer[No++]);
	}
	while (No < customer.size()&&customer[No]->arrive_time<=17*3600){
		if (processing.empty()){
			time = customer[No]->arrive_time;
			processing.push_back(customer[No++]);
			continue;
		}
		sort(processing.begin(), processing.end(), sort_op);
		//if (processing[0]->arrive_time>17 * 3600) break;
		if (processing[0]->op_time + time>=customer[No]->arrive_time&& processing.size() < K){
			for (int j = 0; j < processing.size(); j++){
				processing[j]->op_time -= customer[No]->arrive_time - time;
			}
			time = customer[No]->arrive_time;
			processing.push_back(customer[No++]);
			sort(processing.begin(), processing.end(), sort_op);
			continue;
		}
		time += processing[0]->op_time;
		processing[0]->wait_time = time - processing[0]->arrive_time - processing[0]->original_op_time;
		int curtime = processing[0]->op_time;
		for (int j = 0; j < processing.size(); j++){
			processing[j]->op_time -= curtime;
		}
		processing[0]->processed = true;
		processing.pop_front();
		while (No < customer.size() && time >= customer[No]->arrive_time && processing.size()<K)
			processing.push_back(customer[No++]);
	}
	while (!processing.empty()){
		sort(processing.begin(), processing.end(), sort_op);
		time += processing[0]->op_time;
		processing[0]->wait_time = time - processing[0]->arrive_time - processing[0]->original_op_time;
		int curtime = processing[0]->op_time;
		for (int j = 0; j < processing.size(); j++){
			processing[j]->op_time -= curtime;
		}
		processing[0]->processed = true;
		processing.pop_front();
	}
	int processed_num = 0;
	int total_wait = 0;
	for (int i = 0; i < customer.size(); i++){
		if (customer[i]->processed == true){
			processed_num++;
			total_wait += customer[i]->wait_time;
		}
	}
	float average_wait = (float)total_wait / processed_num / 60.0;
	cout << setiosflags(ios::fixed) << setprecision(1) << average_wait << endl;
	return 0;

}