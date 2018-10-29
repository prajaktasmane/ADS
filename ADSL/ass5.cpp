/*
 * assign5.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: student
 */
#include<iostream>

using namespace std;

class graph {
	int num, **m, *v;
	string *city;
public:
	graph() {
		num = 0;
	}
	void create();
	void disp();
	void prims();
	void kruskal();
	bool circuit(int, int);
	bool visited();
	bool possible();
};

int main() {
	graph ob;
	char ch;
	do {
		ob.create();
		cout << "Graph in Matrix form:" << endl;
		ob.disp();
		cout << endl;
		if (ob.possible()) {
			cout << "PRIMS:" << endl;
			ob.prims();
			cout << endl;
			cout << "KRUSKAL:" << endl;
			ob.kruskal();
			cout << endl;
		}
		else
		{
			cout<<"Cannot find Minimum Spanning Tree!"<<endl;
		}
		cout << "Again?(y/n): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << "EXITING...";
}

void graph::create() {
	bool temp = false;
	char ch;
	int val;
	int flag1 = -1, flag2 = -1;
	string start, end;
	cout << "Enter number of cities: ";
	cin >> num;
	m = new int*[num];
	v = new int[num];
	city = new string[num];
	for (int i = 0; i < num; i++) {
		cout << "Enter city name: ";
		cin >> city[i];
		v[i] = 0;
		m[i] = new int[num];
	}
	do {
		cout << "Enter start, destination, cost: ";
		cin >> start >> end >> val;
		for (int i = 0; i < num; i++) {
			if (start == city[i]) {
				flag1 = i;
			}
			if (end == city[i]) {
				flag2 = i;
			}
		}
		if (flag1 != -1 && flag2 != -1) {
			m[flag1][flag2] = val;
			m[flag2][flag1] = val;
			cout << "Add more?(y/n): ";
			cin >> ch;
			if (ch == 'y') {
				temp = true;
			} else {
				temp = false;
			}
		} 
		else {
			if (flag1 == -1) {
				cout << "Start city not found!" << endl;
			} else {
				cout << "Destination city not found!" << endl;
			}
			temp = false;
		}
	} while (temp);
}

void graph::disp() {
	cout << "  ";
	for (int i = 0; i < num; i++) {
		cout << city[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < num; i++) {
		cout << city[i] << " ";
		for (int j = 0; j < num; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void graph::prims() {
	int prim[num][num], min = m[0][0], k;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			prim[i][j] = 0;
			v[j] = 0;
		}
	}
	for (int i = 0; i < num; i++) {
		min = 0;
		for (int j = 0; j < num; j++) {
			if (min > m[i][j] || min == 0) {
				if (m[i][j] != 0) {
					min = m[i][j];
					k = j;
				}
			}
		}
		v[i] = 1;
		v[k] = 1;
		prim[i][k] = min;
		prim[k][i] = min;
	}
	cout << "  ";
	for (int i = 0; i < num; i++) {
		cout << city[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < num; i++) {
		cout << city[i] << " ";
		for (int j = 0; j < num; j++) {
			cout << prim[i][j] << " ";
		}
		cout << endl;
	}
}

void graph::kruskal() {
	int kruskal[num][num], min = m[0][0], k, l, cost = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			kruskal[i][j] = 0;
			v[j] = 0;
		}
	}
	while (!visited()) {
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if ((min > m[i][j] || min == 0) && (v[i] != 1 || v[j] != 1)) {
					if (m[i][j] != 0) {
						min = m[i][j];
						k = j;
						l = i;
					}
				}
			}
		}
		if (!circuit(v[l], v[k])) {
			v[l] = 1;
			v[k] = 1;
			kruskal[l][k] = min;
			kruskal[k][l] = min;
		}
		min = 0;
	}
	cout << "  ";
	for (int i = 0; i < num; i++) {
		cout << city[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < num; i++) {
		cout << city[i] << " ";
		for (int j = 0; j < num; j++) 
	{
			cout << kruskal[i][j] << " ";
		}
		cout << endl;
	}

	cout << "PATH IS:" << endl;
	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {
			if (kruskal[i][j] != 0) {
				cout << city[i] << " -> " << city[j] << endl;
				cost += kruskal[i][j];
			}
		}
	}
	cout << "Weight of Minimal Spanning Tree: " << cost << endl;
}

bool graph::circuit(int x, int y) {
	if (x == 1 && y == 1) {
		return true;
	} else {
		return false;
	}
}

bool graph::visited() {
	for (int i = 0; i < num; i++) {
		if (!v[i]) {
			return false;
		}
	}
	return true;
}

bool graph::possible()
{
	int flag = 0;
	for(int i=0;i<num;i++)
	{
		flag = 0;
		for(int j=0;j<num;j++)
		{
			if(m[i][j]==0)
			{
				flag++;
			}
		}
		if(flag==num)
		{
			return false;
		}
	}
	return true;
}
