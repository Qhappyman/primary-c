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
	B(int a = 2) { //ȫʡ���캯�����������ʱ�ɲ��ظ�ʵ��
		setAge(a);
	}
	//B() {}; //error,��ȫʡ���캯�������޲ι��캯����ͻ
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
	/* A a(3, 3);//Ĭ�Ϲ��캯��������ʾ���ã�ϵͳ�Զ�����,���ι��캯��������г�ʼ����ֵ
	A b(4, 4);
	A c(5, 5); */

	B son; //ȫʡ�Ķ���û��ǿ��Ҫ��ֵ��ʼ��
	son.getAge();

}