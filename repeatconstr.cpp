#include<iostream>

class Tdate {
public:
	Tdate();
	Tdate(int d);//ע����ȫʡ����������û�н��г�ʼ��ֵ
	Tdate(int m, int d);
	Tdate(int m, int d, int y);//4�����ع��캯��
	void display() {

	int month = 5;
	int day = 27;
	int year = 2019;
Tdate::Tdate() { display(); }
Tdate::Tdate(int d) {

Tdate::Tdate(int m, int d, int y) {
int main() {
	Tdate a;