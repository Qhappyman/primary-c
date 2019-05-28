#include<iostream>
using namespace std;
class A {
public:
	void init(int d, int m, int year = 2019) {
		day = d; month = m; classyear = year;
	}
	void init(int d, int year = 2019) {
		day = d; classyear = year;
	}
	void init(int year = 2019) {
		classyear = year;
	}
	void display() {
		cout << "day:" << day << "month:" << month << "year:" << classyear<<"\n";
	}
private:
	int day = 6, month = 20, classyear = 20119;
};
int main() {
	A a;
	a.init();
	a.display();
	a.init(27, 5,3);
	a.display();
	a.display();
	A* pa;//不同对象互不影响，独立
	pa = new A;
	pa->init();//对象指针访问成员必须使用->，不可用 .
	pa->display();
	cout << "\n";

	A a1, a2, * b1, * b2;
	b1 = new A;
	b2 = new A;
	b1->init(3, 4, 54);
	b1->display();
	b2 = b1;
	b2->display();//对象赋值本质上是赋值内存地址
	cout << b1 << "\n" << b2 << "\n";
	a1.init(6, 7, 8);
	a1.display();
	a2 = a1;
	a2.display();
	a1.init(9, 10, 11);
	a1.display();
	a2.display();//对象直接的直接赋值不是赋值地址，赋值之后各自操作互不影响	
}