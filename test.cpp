#include<iostream>
#include<string>
#include<map>
#include<list>
#include<vector>
using namespace std;

class Person {
protected:
	int age;
	string name, sex, protitle;
public:
	Person() {
	}
	Person(string n, int a, string s) {
		name = n;
		age = a;
		sex = s;
	}
	virtual void inputData() {
	}
	virtual void outData() {
	}
	string getProtitle() {
		return protitle;
	}
	void setProtitle(string p) {
		protitle = p;
	}
	void setName(string n) {
		name = n;
	}
	void setAge(int a) {
		age = a;
	}
	void setSex(string s) {
		sex = s;
	}
	string getName() {
		return name;
	}
	string getSex() {
		return sex;
	}
	int getAge() {
		return age;
	}
};
class Student :public Person {
private:
	double chinese, math, english;
	int classX;
	string id;
public:
	Student() {
		protitle = "ѧ��";
	}
	Student(string n, int a, string s) :Person(n, a, s) {

	}
	void inputData() {
		cout << "����������ѧ���������Ա����䣬ѧ�ţ��༶" << endl;
		cin >> name
			>> sex
			>> age
			>> id
			>> classX;
		cout << "����������ѧ�����ġ���ѧ��Ӣ��ɼ�" << endl;
		cin >> chinese >> math >> english;
	}
	void outData() {
		cout << "����:" << name << "\t�Ա�" << sex << "\t����:" << age << "\tѧ��:" << id << "\t�༶:" << classX
			<< "\t����:" << chinese << "\t��ѧ:" << math << "\tӢ��:" << english << endl;
	}
	void setScore(double c, double m, double e) {
		chinese = c;
		math = m;
		english = e;
	}
	double getMath() {
		return math;
	}
	double getChinese() {
		return chinese;
	}
	double getEnglish() {
		return english;
	}
	friend ostream& operator<<(ostream& os, Student& s);
};
ostream& operator<<(ostream& os, Student& s) {
	os << "����:" << s.name << "\t�Ա�" << s.sex << "\t����:" << s.age << "\tѧ��:" << s.id << "\t�༶:" << s.classX
		<< "\t����:" << s.chinese << "\t��ѧ:" << s.math << "\tӢ��:" << s.english << endl;
	return os;
}
class Teacher :public Person {
protected:
	string dept;
	double hourpice;
	int tid;
	double salary;
	int workhour;
public:
	Teacher() {
	}
	Teacher(string n, int a, string s) :Person(n, a, s) {
	}
	void inputData() {
		cout << "�����������ʦ����,�Ա�,����,���,ְ��,ϵ��" << endl;
		cin >> name
			>> sex
			>> age
			>> tid
			>> protitle
			>> dept;
		cout << "�����������:" << endl;
		cin >> salary;
		cout << "������½�ѧʱ����" << endl;
		cin >> workhour;
		cout << "����ÿСʱн��:" << endl;
		cin >> hourpice;
	}
	void outData() {
		cout << "����:" << name << "\t�Ա�" << sex << "\t����:" << age << "\t���:" << tid << "\tְ��:" << protitle
			<< "\tϵ��:" << dept << "\t������:" << getIncome() << endl;
	}
	void setHourprice(double h) {
		hourpice = h;
	}
	void setWorkhour(int w) {
		workhour = w;
	}
	virtual double getSalary() {
		return salary;
	}
	virtual void setSalary(double s) {
		salary = s;
	}
	virtual double getIncome() {
		return hourpice * workhour + salary;
	}
	friend ostream& operator<<(ostream& os, Teacher& s);
};
ostream& operator<<(ostream& os, Teacher& s) {
	os << "����:" << s.name << "\t�Ա�" << s.sex << "\t����:" << s.age << "\t���:" << s.tid << "\tְ��:" << s.protitle
		<< "\tϵ��:" << s.dept << "\t������:" << s.getIncome() << endl;
	return os;
}
class Dean :public Teacher {
private:
	double performance[12];
public:
	Dean() {
	}
	Dean(string n, int a, string s) {
	}
	void inputData();
	void outData() {
		cout << "����:" << name << "\t�Ա�" << sex << "\t����:" << age << "\t���:" << tid << "\tְ��:" << protitle
			<< "\tϵ��:" << dept << "\t������:" << getIncome() << endl;
	}
	void setPerformance(double* p) {
		for (int i = 0; i < 12; i++) {
			performance[i] = p[i];
		}
	}
	double* getPerformance() {
		return performance;
	}
	double getIncome();
	friend ostream& operator<<(ostream& os, Dean& s);
};
ostream& operator<<(ostream& os, Dean& s) {
	os << "����:" << s.name << "\t�Ա�" << s.sex << "\t����:" << s.age << "\t���:" << s.tid << "\tְ��:" << s.protitle
		<< "\tϵ��:" << s.dept << "\t������:" << s.getIncome() << endl;
	return os;
}
void Dean::inputData() {
	cout << "�����������ʦ����,�Ա�,����,���,ְ��,ϵ��" << endl;
	cin >> name
		>> sex
		>> age
		>> tid
		>> protitle
		>> dept;
	cout << "�����������:" << endl;
	cin >> salary;
	cout << "����������ϵ���ε�ÿ�¼�Ч:" << endl;
	for (int i = 0; i < 12; i++) {
		cout << "��" << i + 1 << "��:" << endl;
		cin >> performance[i];
	}
}
double Dean::getIncome() {
	double all = 0;
	for (int i = 0; i < 12; i++) {
		all = all + performance[i];
	}
	return all + salary * 12;
}

class Chancellor :public Teacher {
private:
	double yearsalary;
public:
	Chancellor() {

	}
	Chancellor(string n, int a, string s) {

	}
	void inputData() {
		cout << "�����������ʦ����,�Ա�,����,���,ְ��,ϵ��" << endl;
		cin >> name
			>> sex
			>> age
			>> tid
			>> protitle
			>> dept;
		cout << "������н��" << endl;
		cin >> salary;
		cout << "������н:" << endl;
		cin >> yearsalary;
	}
	void outData() {
		cout << "����:" << name << "\t�Ա�:" << sex << "\t����:" << age << "\t���:" << tid << "\tְ��:" << protitle
			<< "\tϵ��:" << dept << "\t������:" << getIncome() << endl;
	}
	double getSalary() {
		return salary;
	}
	void setSalary(double s) {
		salary = s;
	}
	void setYearsalary(double y) {
		yearsalary = y;
	}
	double getIncome() {
		return salary * 12 + yearsalary;
	}
	friend ostream& operator<<(ostream& os, Chancellor& s);
};
ostream& operator<<(ostream& os, Chancellor& s) {
	os << "����:" << s.name << "\t�Ա�" << s.sex << "\t����:" << s.age << "\t���:" << s.tid << "\tְ��:" << s.protitle
		<< "\tϵ��:" << s.dept << "\t������:" << s.getIncome() << endl;
	return os;
}
class Function {
private:
	list<Person*> person;
public:
	void setPerson(list<Person*> p) {
		person = p;
	}
	list<Person*> getPerson() {
		return person;
	}
	//����������ѯ��Ա��Ϣ
	Person* searchPerson(string name);
	//��������ɾ����Ա��Ϣ
	void removeByName(string name);
	//���������Ա��Ϣ
	void display();
	//��ӽ�ʦ
	void addTeacher(Person* p) {
		person.push_back(p);
	}
	//���ѧ��
	void addStudent(Person* p) {
		person.push_back(p);
	}
};
Person* Function::searchPerson(string name) {
	Person* p;
	bool flag = false;
	list<Person*>::iterator iter1;
	for (iter1 = person.begin(); iter1 != person.end(); iter1++) {
		if ((*iter1)->getName() == name) {
			p = *iter1;
			return p;
			flag = true;
			break;
		}
	}
	if (!flag) {
		p = new Person;
		p->setName("��");
		return p;
	}
}
void Function::removeByName(string name) {
	bool flag = false;
	list<Person*>::iterator iter1;
	for (iter1 = person.begin(); iter1 != person.end(); iter1++) {
		if ((*iter1)->getName() == name) {
			person.remove((*iter1));
			cout << "ɾ���ɹ�" << endl;
			flag = true;
		}
	}
	if (!flag) {
		cout << "δ�ҵ�������Ա";
	}
}
void Function::display() {
	list<Person*>::iterator iter1;
	for (iter1 = person.begin(); iter1 != person.end(); iter1++) {
		(*iter1)->outData();
	}
}

class Choose {
private:
	multimap<Person*, Person*> choice;
public:
	Choose() {

	}
	//��ʦѡ��ѧ��
	void chooseStudents(Person* t, Person* s);
	//ѧ��ѡ��ָ����ʦ
	void chooseTeacer(Person* s, Person* t);
	//��ѯָ��ѧ��
	vector<string> searchStudents(string name);
	string searchTeacher(string name);
	//�жϸ�ѧ���Ƿ��Ѿ���ָ����ʦ
	bool searchStudent(Person* p);
};
void Choose::chooseStudents(Person* t, Person* s) {
	choice.insert(make_pair(t, s));
}
void Choose::chooseTeacer(Person* s, Person* t) {
	choice.insert(make_pair(s, t));
}
vector<string> Choose::searchStudents(string name) {
	multimap<Person*, Person*>::iterator iter;
	vector<string> messege;
	for (iter = choice.begin(); iter != choice.end(); iter++) {
		if (name == iter->first->getName()) {
			messege.push_back(iter->second->getName());
		}
	}
	return messege;
}
string Choose::searchTeacher(string name) {
	multimap<Person*, Person*>::iterator iter;
	string n;
	for (iter = choice.begin(); iter != choice.end(); iter++) {
		if (name == iter->first->getName() || name == iter->second->getName()) {
			n = iter->second->getName();
		}
	}
	return n;
}
bool Choose::searchStudent(Person* p) {
	bool flag = true;
	multimap<Person*, Person*>::iterator iter;
	for (iter = choice.begin(); iter != choice.end(); iter++) {
		if (p->getName() == iter->first->getName()) {
			flag = false;
		}
	}
	return flag;
}
int main()
{
	Function in;
	Choose ch;
	cout << "*******************************************************" << endl;
	cout << "************Welcome To The Education System************" << endl;
	cout << "*******************************************************" << endl << endl;
	Person* p1, * p2, * p3;
	Chancellor c1;
	list<Person*> person;
	cout << "������Ժ��������:" << endl;
	p1 = &c1;
	p1->inputData();
	p1->outData();
	in.addTeacher(p1);
	cout << "����������ϵ���ε�����:" << endl;
	Dean d1, d2;
	p2 = &d1;
	p3 = &d2;
	cout << "ϵ���μ�:" << endl;
	p2->inputData();
	p2->outData();
	cout << "ϵ������:" << endl;
	p3->inputData();
	p3->outData();
	if (p2->getAge() > p3->getAge()) {
		in.addTeacher(p3);
		in.addTeacher(p2);
	}
	else
	{
		in.addTeacher(p2);
		in.addTeacher(p3);
	}
	const int max1 = 1024;
	const int max2 = 1024;
	Teacher t[max1];
	Student stu[max2];
	int n = 0;
	bool flag = true;
	while (flag) {
		cout << endl;
		cout << "��ϵͳ�ɽ��еĲ�������:" << endl;
		cout << "1.�����ʦ" << endl;
		cout << "2.���ѧ��" << endl;
		cout << "3.�������ֲ�ѯ��Ա��Ϣ" << endl;
		cout << "4.��������ɾ����Ӧ��Ա��Ϣ" << endl;
		cout << "5.��ӡ������Ա������Ϣ" << endl;
		cout << "6.ѡ��ʦ��ֻ��ѡ��һλ��" << endl;
		cout << "7.ѡ��ѧ��" << endl;
		cout << "8.��ѯָ����ѧ��" << endl;
		cout << "9.��ѯָ����ʦ" << endl;
		cout << "10.�˳�����" << endl;
		cout << "���������ֽ������Ӧ�Ĳ���:" << endl;
		int i;
		cin >> i;
		if (i == 1) {
			if (n < 1024) {
				Person* p;
				p = &t[n];
				p->inputData();
				p->outData();
				in.addTeacher(p);
				n++;
			}
			else
			{
				cout << "��ʦ���Ѵ�����" << endl;
			}

		}
		if (i == 2) {
			if (n < 1024) {
				Person* p = new Person;
				p = &stu[n];
				p->inputData();
				p->outData();
				in.addStudent(p);
				n++;
			}
			else
			{
				cout << "ѧ�����Ѵ�����" << endl;
			}
		}
		if (i == 3) {
			Person* p;
			cout << "����Ҫ��ѯ������:" << endl;
			string name;
			cin >> name;
			p = in.searchPerson(name);
			if ("��" == p->getName()) {
				cout << "δ��ѯ�������Ϣ" << endl;
			}
			else
			{
				cout << "��Ҫ��ѯ����Ϣ���£�" << endl;
				p->outData();
			}
		}
		if (i == 4) {
			cout << "����Ҫɾ������Ա��Ϣ:" << endl;
			string name;
			cin >> name;
			in.removeByName(name);
		}
		if (i == 5) {
			in.display();
		}
		if (i == 6) {
			bool flag;
			//����
			Person* p1;
			cout << "�����������:" << endl;
			string name;
			cin >> name;
			p1 = in.searchPerson(name);
			if ("��" == p1->getName() || p1->getProtitle() != "ѧ��") {
				cout << "δ��ѯ�������Ϣ" << endl;
			}
			else
			{
				flag = ch.searchStudent(p1);
				if (flag) {
					cout << "��" << p1->getName() << "ͬѧѡ��ʦ" << endl;
					cout << "���뵼ʦ����:";
					//��ʦ
					Person* p2;
					string name;
					cin >> name;
					p2 = in.searchPerson(name);
					if ("��" == p2->getName() || p2->getProtitle() == "ѧ��") {
						cout << "�õ�ʦ������" << endl;
					}
					else
					{
						ch.chooseTeacer(p1, p2);
						cout << "��ӳɹ�" << endl;
					}
				}
				else
				{
					cout << p1->getName() << "ͬѧ�Ѿ�ѡ��ָ����ʦ" << endl;
				}
			}
		}
		if (i == 7) {
			bool flag;
			Person* p1;
			cout << "�����������:" << endl;
			string name;
			cin >> name;
			p1 = in.searchPerson(name);
			if ("��" == p1->getName() || p1->getProtitle() == "ѧ��") {
				cout << "δ��ѯ�������Ϣ" << endl;
			}
			else
			{
				cout << "��" << p1->getName() << "��ʦѡ��ѧ������Ҫ����ѡ������exit��" << endl;
				cout << "����ѧ������:";
				//ѧ��
				Person* p2;
				while (true) {
					string name;
					cin >> name;
					if (name == "exit") {
						break;
					}
					else
					{
						p2 = in.searchPerson(name);
						if ("��" == p2->getName() || p2->getProtitle() != "ѧ��") {
							cout << "��ѧ��������" << endl;
						}
						else
						{
							flag = ch.searchStudent(p2);
							if (flag) {
								ch.chooseStudents(p1, p2);
								cout << "��ӳɹ������������" << endl;
							}
							else
							{
								cout << "��ѧ���Ѿ�ѡ��ʦ" << endl;
							}
						}
					}
				}
			}
		}
		if (i == 8) {
			vector<string> students;
			vector<string>::iterator iter;
			Person* p1;
			cout << "�����������:" << endl;
			string name;
			cin >> name;
			p1 = in.searchPerson(name);
			if ("��" == p1->getName() || p1->getProtitle() == "ѧ��") {
				cout << "δ��ѯ�������Ϣ" << endl;
			}
			else
			{
				students = ch.searchStudents(name);
				cout << "����ѧ������:" << endl;
				for (iter = students.begin(); iter != students.end(); iter++) {
					cout << *iter << "\t";
				}
				cout << endl;
			}
		}
		if (i == 9) {
			string te;
			Person* p1;
			cout << "�����������:" << endl;
			string name;
			cin >> name;
			p1 = in.searchPerson(name);
			if ("��" == p1->getName() || p1->getProtitle() != "ѧ��") {
				cout << "δ��ѯ�������Ϣ" << endl;
			}
			else
			{
				te = ch.searchTeacher(name);
				cout << "����ָ����ʦΪ:" << te << endl;
			}
		}
		if (i == 10) {
			flag = false;
		}
	}

}