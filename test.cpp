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
		protitle = "学生";
	}
	Student(string n, int a, string s) :Person(n, a, s) {

	}
	void inputData() {
		cout << "请依次输入学生姓名，性别，年龄，学号，班级" << endl;
		cin >> name
			>> sex
			>> age
			>> id
			>> classX;
		cout << "请依次输入学生语文、数学、英语成绩" << endl;
		cin >> chinese >> math >> english;
	}
	void outData() {
		cout << "姓名:" << name << "\t性别：" << sex << "\t年龄:" << age << "\t学号:" << id << "\t班级:" << classX
			<< "\t语文:" << chinese << "\t数学:" << math << "\t英语:" << english << endl;
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
	os << "姓名:" << s.name << "\t性别：" << s.sex << "\t年龄:" << s.age << "\t学号:" << s.id << "\t班级:" << s.classX
		<< "\t语文:" << s.chinese << "\t数学:" << s.math << "\t英语:" << s.english << endl;
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
		cout << "请依次输入教师姓名,性别,年龄,编号,职称,系别" << endl;
		cin >> name
			>> sex
			>> age
			>> tid
			>> protitle
			>> dept;
		cout << "输入基本工资:" << endl;
		cin >> salary;
		cout << "输入该月教学时长：" << endl;
		cin >> workhour;
		cout << "输入每小时薪酬:" << endl;
		cin >> hourpice;
	}
	void outData() {
		cout << "姓名:" << name << "\t性别：" << sex << "\t年龄:" << age << "\t编号:" << tid << "\t职称:" << protitle
			<< "\t系别:" << dept << "\t月收入:" << getIncome() << endl;
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
	os << "姓名:" << s.name << "\t性别：" << s.sex << "\t年龄:" << s.age << "\t编号:" << s.tid << "\t职称:" << s.protitle
		<< "\t系别:" << s.dept << "\t年收入:" << s.getIncome() << endl;
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
		cout << "姓名:" << name << "\t性别：" << sex << "\t年龄:" << age << "\t编号:" << tid << "\t职称:" << protitle
			<< "\t系别:" << dept << "\t年收入:" << getIncome() << endl;
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
	os << "姓名:" << s.name << "\t性别：" << s.sex << "\t年龄:" << s.age << "\t编号:" << s.tid << "\t职称:" << s.protitle
		<< "\t系别:" << s.dept << "\t年收入:" << s.getIncome() << endl;
	return os;
}
void Dean::inputData() {
	cout << "请依次输入教师姓名,性别,年龄,编号,职称,系别" << endl;
	cin >> name
		>> sex
		>> age
		>> tid
		>> protitle
		>> dept;
	cout << "输入基本工资:" << endl;
	cin >> salary;
	cout << "请依次输入系主任的每月绩效:" << endl;
	for (int i = 0; i < 12; i++) {
		cout << "第" << i + 1 << "月:" << endl;
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
		cout << "请依次输入教师姓名,性别,年龄,编号,职称,系别" << endl;
		cin >> name
			>> sex
			>> age
			>> tid
			>> protitle
			>> dept;
		cout << "输入月薪：" << endl;
		cin >> salary;
		cout << "输入年薪:" << endl;
		cin >> yearsalary;
	}
	void outData() {
		cout << "姓名:" << name << "\t性别:" << sex << "\t年龄:" << age << "\t编号:" << tid << "\t职称:" << protitle
			<< "\t系别:" << dept << "\t年收入:" << getIncome() << endl;
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
	os << "姓名:" << s.name << "\t性别：" << s.sex << "\t年龄:" << s.age << "\t编号:" << s.tid << "\t职称:" << s.protitle
		<< "\t系别:" << s.dept << "\t年收入:" << s.getIncome() << endl;
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
	//按照姓名查询人员信息
	Person* searchPerson(string name);
	//按照姓名删除人员信息
	void removeByName(string name);
	//输出所有人员信息
	void display();
	//添加教师
	void addTeacher(Person* p) {
		person.push_back(p);
	}
	//添加学生
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
		p->setName("无");
		return p;
	}
}
void Function::removeByName(string name) {
	bool flag = false;
	list<Person*>::iterator iter1;
	for (iter1 = person.begin(); iter1 != person.end(); iter1++) {
		if ((*iter1)->getName() == name) {
			person.remove((*iter1));
			cout << "删除成功" << endl;
			flag = true;
		}
	}
	if (!flag) {
		cout << "未找到符合人员";
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
	//教师选择学生
	void chooseStudents(Person* t, Person* s);
	//学生选择指导老师
	void chooseTeacer(Person* s, Person* t);
	//查询指导学生
	vector<string> searchStudents(string name);
	string searchTeacher(string name);
	//判断该学生是否已经有指导老师
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
	cout << "请输入院长的数据:" << endl;
	p1 = &c1;
	p1->inputData();
	p1->outData();
	in.addTeacher(p1);
	cout << "请输入两名系主任的数据:" << endl;
	Dean d1, d2;
	p2 = &d1;
	p3 = &d2;
	cout << "系主任甲:" << endl;
	p2->inputData();
	p2->outData();
	cout << "系主任乙:" << endl;
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
		cout << "本系统可进行的操作如下:" << endl;
		cout << "1.添加老师" << endl;
		cout << "2.添加学生" << endl;
		cout << "3.按照名字查询人员信息" << endl;
		cout << "4.按照名字删除对应人员信息" << endl;
		cout << "5.打印所有人员基本信息" << endl;
		cout << "6.选择导师（只能选择一位）" << endl;
		cout << "7.选择学生" << endl;
		cout << "8.查询指导的学生" << endl;
		cout << "9.查询指导老师" << endl;
		cout << "10.退出操作" << endl;
		cout << "请输入数字进行相对应的操作:" << endl;
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
				cout << "教师数已达上限" << endl;
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
				cout << "学生数已达上限" << endl;
			}
		}
		if (i == 3) {
			Person* p;
			cout << "输入要查询的姓名:" << endl;
			string name;
			cin >> name;
			p = in.searchPerson(name);
			if ("无" == p->getName()) {
				cout << "未查询到相关信息" << endl;
			}
			else
			{
				cout << "您要查询的信息如下：" << endl;
				p->outData();
			}
		}
		if (i == 4) {
			cout << "输入要删除的人员信息:" << endl;
			string name;
			cin >> name;
			in.removeByName(name);
		}
		if (i == 5) {
			in.display();
		}
		if (i == 6) {
			bool flag;
			//本人
			Person* p1;
			cout << "输入你的姓名:" << endl;
			string name;
			cin >> name;
			p1 = in.searchPerson(name);
			if ("无" == p1->getName() || p1->getProtitle() != "学生") {
				cout << "未查询到相关信息" << endl;
			}
			else
			{
				flag = ch.searchStudent(p1);
				if (flag) {
					cout << "请" << p1->getName() << "同学选择导师" << endl;
					cout << "输入导师姓名:";
					//导师
					Person* p2;
					string name;
					cin >> name;
					p2 = in.searchPerson(name);
					if ("无" == p2->getName() || p2->getProtitle() == "学生") {
						cout << "该导师不存在" << endl;
					}
					else
					{
						ch.chooseTeacer(p1, p2);
						cout << "添加成功" << endl;
					}
				}
				else
				{
					cout << p1->getName() << "同学已经选择指导教师" << endl;
				}
			}
		}
		if (i == 7) {
			bool flag;
			Person* p1;
			cout << "输入你的姓名:" << endl;
			string name;
			cin >> name;
			p1 = in.searchPerson(name);
			if ("无" == p1->getName() || p1->getProtitle() == "学生") {
				cout << "未查询到相关信息" << endl;
			}
			else
			{
				cout << "请" << p1->getName() << "老师选择学生（如要结束选择，输入exit）" << endl;
				cout << "输入学生姓名:";
				//学生
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
						if ("无" == p2->getName() || p2->getProtitle() != "学生") {
							cout << "该学生不存在" << endl;
						}
						else
						{
							flag = ch.searchStudent(p2);
							if (flag) {
								ch.chooseStudents(p1, p2);
								cout << "添加成功，请继续输入" << endl;
							}
							else
							{
								cout << "该学生已经选择导师" << endl;
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
			cout << "输入你的姓名:" << endl;
			string name;
			cin >> name;
			p1 = in.searchPerson(name);
			if ("无" == p1->getName() || p1->getProtitle() == "学生") {
				cout << "未查询到相关信息" << endl;
			}
			else
			{
				students = ch.searchStudents(name);
				cout << "您的学生如下:" << endl;
				for (iter = students.begin(); iter != students.end(); iter++) {
					cout << *iter << "\t";
				}
				cout << endl;
			}
		}
		if (i == 9) {
			string te;
			Person* p1;
			cout << "输入你的姓名:" << endl;
			string name;
			cin >> name;
			p1 = in.searchPerson(name);
			if ("无" == p1->getName() || p1->getProtitle() != "学生") {
				cout << "未查询到相关信息" << endl;
			}
			else
			{
				te = ch.searchTeacher(name);
				cout << "您的指导老师为:" << te << endl;
			}
		}
		if (i == 10) {
			flag = false;
		}
	}

}