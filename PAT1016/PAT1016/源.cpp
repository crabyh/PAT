#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

//需要修改录入记录的顺序&&配对电话的方法&&计算价格&&输出格式
class Record{
public:
	string name;
	int month, day, hour, minute;
	bool state;
	int used = 0;
};
class Customer{
public:
	string name; 
	deque<Record *> record;
	float total_charge=0;
	bool printed=false;
};

int time(int d, int h, int m, int dd, int hh, int mm){
	return (dd - d) * 24 * 60 + (hh - h) * 60 + mm - m;
}
float cost(int d, int h, int m, int dd, int hh, int mm,int toll[]){
	float sum=0;
	for (int hour = h+1; hour < (dd - d)*24+hh; hour++){
		sum += toll[hour%24]*.6;
	}
	sum += toll[h] * (60 - m) / 100.0 + toll[hh] * mm/100.0;
	if (d == dd&&h == hh)
		sum = (mm - m) * toll[h] * .01;
	return sum;
}
bool mysort(Record* i, Record *j){
	int sumi, sumj;
	sumi = i->day * 24 * 60 + i->hour * 60 + i->minute;
	sumj = j->day * 24 * 60 + j->hour * 60 + j->minute;
	return sumi < sumj;
}
bool sort_by_name(Customer *i, Customer*j){
	return i->name < j->name;
}
//main function
int main(int argc, char *argv[]){
	int toll[24] = {};
	for (int i = 0; i < 24; i++){
		cin >> toll[i];
	}
	int N;
	cin >> N;
	deque<Customer *> customer;
	deque<Record *>record;
	string name, state;
	char colon;
	int month, day, hour, minute;
	
	//input all records
	for (int c_count = 0; c_count < N; c_count++){
		cin >> name >> month >> colon >> day >> colon >> hour >> colon >> minute >> state;
		Record * r_ptr;
		r_ptr = new Record;
		r_ptr->day = day; r_ptr->hour = hour; r_ptr->minute = minute; r_ptr->month = month; r_ptr->name = name;
		if (state == "on-line") r_ptr->state = true;
		else  r_ptr->state = false;
		record.push_back(r_ptr);
	}
	sort(record.begin(), record.end(), mysort);

	while (!record.empty()){
		Record * r_ptr = record.front();
		Customer * c_ptr = NULL;
		for (int i = 0; i < customer.size(); i++){
			if (customer[i]->name == r_ptr->name){
				c_ptr = customer[i];
				break;
			}
		}
		if (c_ptr == NULL){
			c_ptr = new Customer;
			c_ptr->name = r_ptr->name;
			customer.push_back(c_ptr);
		}
		c_ptr->record.push_back(r_ptr);
		record.pop_front();
	}

	//calculate total charge&print out the results
	sort(customer.begin(), customer.end(), sort_by_name);
	for (int c_count = 0; c_count < customer.size(); c_count++){
		Customer * c_ptr = customer[c_count];
		
		for (int r_count = 0; r_count < c_ptr->record.size(); r_count++){
			Record * r_ptr = c_ptr->record[r_count];
			if (r_ptr->state == true){
				
				//while (c_ptr->record[r]->state != true && r != 0 && c_ptr->record[r]->used != true)r--;
				for (int r = r_count; r<c_ptr->record.size(); r++){
					if (r != -1 && c_ptr->record[r]->used == false && c_ptr->record[r]->state == false&&r==r_count+1){
						if (c_ptr->printed == 0){
							cout << c_ptr->name << " " << setw(2) << setfill('0') << c_ptr->record[0]->month << endl;
							c_ptr->printed = 1;
						}
						c_ptr->record[r]->used = true;
						r_ptr->used = true;
						cout << setw(2) << setfill('0') << r_ptr->day << ":" << setw(2) << setfill('0') << r_ptr->hour << ":" << setw(2) << setfill('0') << r_ptr->minute << " ";
						cout << setw(2) << setfill('0') << c_ptr->record[r]->day << ":" << setw(2) << setfill('0') << c_ptr->record[r]->hour << ":" << setw(2) << setfill('0') << c_ptr->record[r]->minute << " ";
						cout << setiosflags(ios::fixed) << setprecision(2) << time(r_ptr->day, r_ptr->hour, r_ptr->minute, c_ptr->record[r]->day, c_ptr->record[r]->hour, c_ptr->record[r]->minute) << " ";
						cout << setiosflags(ios::fixed) << setprecision(2) << "$" << cost(r_ptr->day, r_ptr->hour, r_ptr->minute, c_ptr->record[r]->day, c_ptr->record[r]->hour, c_ptr->record[r]->minute, toll) << endl;
						c_ptr->total_charge += cost(r_ptr->day, r_ptr->hour, r_ptr->minute, c_ptr->record[r]->day, c_ptr->record[r]->hour, c_ptr->record[r]->minute, toll);
					}
				}
			}
		}
		if (c_ptr->printed == 1){
			cout << "Total amount: $" << c_ptr->total_charge << endl;
			c_ptr->printed = 2;
		}
	}

	return 0;
}