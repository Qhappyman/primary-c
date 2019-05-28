#include<iostream>
using namespace std;
class Tdate {
public:
	Tdate();
	Tdate(int d);//注意与全省参数的区别，没有进行初始化值
	Tdate(int m, int d);
	Tdate(int m, int d, int y);//4个重载构造函数
	void display() {		cout << month << "/" << day << "/" << year << endl;	}
private:
	int month = 5;
	int day = 27;
	int year = 2019;};
Tdate::Tdate() { display(); }
Tdate::Tdate(int d) {	day = d;	display();}
Tdate::Tdate(int m, int d) {	month = m; day = d;	display();}
Tdate::Tdate(int m, int d, int y) {	month = m; day = d; year = y;	display();}
int main() {
	Tdate a;	Tdate b(29);	Tdate(6, 15);	Tdate(7, 19, 2018);}