#include<iostream>
using namespace std;
class Tdate {
public:
	Tdate();
	Tdate(int d);//ע����ȫʡ����������û�н��г�ʼ��ֵ
	Tdate(int m, int d);
	Tdate(int m, int d, int y);//4�����ع��캯��
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