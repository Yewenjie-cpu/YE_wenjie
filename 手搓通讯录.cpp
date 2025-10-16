#include<iostream>
#include<string>
#include<map>
using namespace std;

class student {
private:
	string name;
	int age;
	int id;
public:
	student(string a,int b,int c) :name(a), age(b), id(c) {};
	void output() const {
		cout << "姓名"<<name << endl;
		cout <<"年龄"<< age << endl;
		cout << "学号" << id << endl;
	}

};



int main() {
	map<int, student>wyu;
	while (true) {
		cout << "录入学生信息请输入1" << endl;
		cout << "查找信息请按2" << endl;
		cout << "退出系统请按3" << endl;
		int a;
		cin >> a;
		switch (a) {
		case 1: {
			string name; int age;  int id;
			cout << "请输入姓名,年龄，学号（使用空格隔开）：" << endl;
			cin >> name >> age >> id;
			if (wyu.find(id) == wyu.end()) {
				wyu.insert({ id, student(name, age, id) });
				break;
			}
			else {
				cout << "请重新输入！" << endl;
				break;
			}
		}
		case 2: {
			cout << "请输入查询学生的学号" << endl;
			int id_;
			cin >> id_;
			auto it = wyu.find(id_);  // 你的风格
			if (it != wyu.end()) {
				it->second.output();   // 你的output方法
				break;
			}
			else {
				cout << "查无此人" << endl;
				break;
			}
		}
		case 3: {
			cout << "是否退出" <<"确认请输入3,否则按任意键取消" << endl;
			int i; cin >> i;
			bool out = (i == 3);
			if (out) {
				return 0;
			}
			else {
				break;
			}
		}
		}


	}
}