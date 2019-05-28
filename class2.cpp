#include<iostream>
using namespace std;
class A {
public:
	A(int i,int m ) {
		cout << "A constructor"<<"\n";
		cout << i << "\n"<<m;
	}
	~A()
	{
		cout << "A destructor"<<"\n";
	}
};
class B {
public:
	B(int a = 2) { //全省构造函数，定义对象时可不必赋实参
		setAge(a);
	}
	//B() {}; //error,有全省构造函数会与无参构造函数冲突
	void setAge(int age) {
		Age = age;
	};
	void getAge() {
		cout << Age;
	}
private:
	int Age;
};
int main() {
	/* A a(3, 3);//默认构造函数不能显示调用，系统自动调用,含参构造函数必须进行初始化赋值
	A b(4, 4);
	A c(5, 5); */

	B son; //全省的对象，没有强制要赋值初始化
	son.getAge();

}