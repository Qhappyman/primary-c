#include<iostream>
#include<string>
using namespace std;
class A {
public:
	void display();
	inline void play();
	int age(int, double);
	/*int getAge()const {
		Age = 10;//const常量成员函数无法修改数据值
		return Age;
	}*/
private:
	int a;
	double c;
	int Age = 5;
};
inline void A::display() {
	cout << "inline function";//first
}
void A::play() {
	cout << "second inline"; //内联函数俩种定义方式
}
int A::age(int i, double m) {//类外定义成员函数必须补全形参名
	return 0;
}
class B {
public:

private:
	//B a; 不可以是自身的对象
};
int main() {
	/* int my()const{//本地函数不允许为常量函数
		return 520;
	}; */
}