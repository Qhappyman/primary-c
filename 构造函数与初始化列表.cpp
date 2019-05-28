#include<iostream>
using namespace std;
class A {
public:
	A(int m) :Age(5) {
		Age = m;
	}
	inline A() {
		p = new char;
	}
	inline ~A() {
		delete p;//在构造函数中动态分配了内存，就必须显式析构函数来回收内存
	}
private:
	int Age;
	char* p;
};
int main() {
	A a(15);//15,说明先进行了初始化列表，然后进行了函数体的的执行
}
//委托构造函数
//A():A(15){
//}   //且不允许为其他数据成员进行初始化列表
//析构函数：没有重载，用于释放空间