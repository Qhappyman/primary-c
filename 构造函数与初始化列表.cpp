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
		delete p;//�ڹ��캯���ж�̬�������ڴ棬�ͱ�����ʽ���������������ڴ�
	}
private:
	int Age;
	char* p;
};
int main() {
	A a(15);//15,˵���Ƚ����˳�ʼ���б�Ȼ������˺�����ĵ�ִ��
}
//ί�й��캯��
//A():A(15){
//}   //�Ҳ�����Ϊ�������ݳ�Ա���г�ʼ���б�
//����������û�����أ������ͷſռ�