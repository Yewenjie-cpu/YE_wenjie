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
		cout << "����"<<name << endl;
		cout <<"����"<< age << endl;
		cout << "ѧ��" << id << endl;
	}

};



int main() {
	map<int, student>wyu;
	while (true) {
		cout << "¼��ѧ����Ϣ������1" << endl;
		cout << "������Ϣ�밴2" << endl;
		cout << "�˳�ϵͳ�밴3" << endl;
		int a;
		cin >> a;
		switch (a) {
		case 1: {
			string name; int age;  int id;
			cout << "����������,���䣬ѧ�ţ�ʹ�ÿո��������" << endl;
			cin >> name >> age >> id;
			if (wyu.find(id) == wyu.end()) {
				wyu.insert({ id, student(name, age, id) });
				break;
			}
			else {
				cout << "���������룡" << endl;
				break;
			}
		}
		case 2: {
			cout << "�������ѯѧ����ѧ��" << endl;
			int id_;
			cin >> id_;
			auto it = wyu.find(id_);  // ��ķ��
			if (it != wyu.end()) {
				it->second.output();   // ���output����
				break;
			}
			else {
				cout << "���޴���" << endl;
				break;
			}
		}
		case 3: {
			cout << "�Ƿ��˳�" <<"ȷ��������3,���������ȡ��" << endl;
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