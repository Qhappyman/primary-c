#include<iostream>
#include<string>
using namespace std;
class A {
public:
	void display();
	inline void play();
	int age(int, double);
	/*int getAge()const {
		Age = 10;//const������Ա�����޷��޸�����ֵ
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
	cout << "second inline"; //�����������ֶ��巽ʽ
}
int A::age(int i, double m) {//���ⶨ���Ա�������벹ȫ�β���
	return 0;
}
class B {
public:

private:
	//B a; ������������Ķ���
};
int main() {
	/* int my()const{//���غ���������Ϊ��������
		return 520;
	}; */
}