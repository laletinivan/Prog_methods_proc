#include "container_atd.h"
#include "plant_atd.h"
#include <fstream>
using namespace std;
namespace plants {
	// ��������� ��������� ������� �������
	plant* InPlant(ifstream& ifst);
	void Out(plant& s, ofstream& ofst);
	bool Compare(plant& first, plant& second);
	// ������������� ����������
	void Init(container& c) {
		c.head = NULL;
		c.tail = NULL;
		c.size = 0;
	}
	// ������� ���������� �� ���������
	// (������������ ������)
	void Clear(container& c) {
		while (c.size != 0) {
			elem* temp = c.head->next;
			delete c.head;
			c.head = temp;
			c.size--;
		}
	}
	// ����� ������� �������� � ������
	void Push(container& c, elem* tmp) {
		c.size++;
		if (c.head != NULL) {
			c.tail->next = tmp;
			c.tail = tmp;
			c.tail->next = c.head;
		}
		else {
			c.head = c.tail = tmp;
			c.head->next = c.tail->next = tmp;
		};
	}
	// ���� ����������� ���������� �� ���������� ������
	void In(container& c, ifstream& ifst) {
		while (!ifst.eof()) {
			elem* temp = new elem;
			temp->data = InPlant(ifst);
			temp->next = c.head;
			Push(c, temp);
		}
	}
	//�������� 1 �������� ������
	void DeleteAt(container& c, int pos) {
		elem* tmp = c.head;
		pos = abs(pos);
		if (pos > c.size) {
			return;
		}
		if (pos == 0) {
			c.head = c.head->next;
			c.tail->next = c.head;
			c.size--;
			return;
		}
		for (int i = 0; i < c.size - 1; i++) {
			if (i + 1 == pos) {
				tmp->next = tmp->next->next;
				c.size--;
			}
			tmp = tmp->next;
		}
	}
	//����������
	void Sort(container& c) {
		container c_sort;
		Init(c_sort);
		int num;
		elem* i, *small;
		while (c.size != 0) {
			small = c.head;
			i = small->next;
			num = 0;
			if (c.size != 1) {
				for (int a = 1; a < c.size; a++) {
					if (Compare(*(i->data), *(small->data))) {
						num = a;
						small = i;
					}
					i = i->next;
				}
			}
			DeleteAt(c, num);
			Push(c_sort, small);
		}
		c = c_sort;
		c.head = c_sort.head;
		c.tail = c_sort.tail;
	}
	//����� ���������
	void Out(container& c, ofstream& ofst) {
		ofst << "Container contains " << c.size << " elements." << endl;
		elem* temp = c.head;
		for (int i = 0; i < c.size; i++) {
			ofst << i << ": ";
			Out(*(temp->data), ofst);
			temp = temp->next;
		}
	}
	//����� ������ ������
	void OutBush(container& c, ofstream& ofst) {
		ofst << "Only bushes." << endl;
		elem* temp = c.head;
		for (int i = 0; i < c.size; i++) {
			ofst << i << ": ";
			if (temp->data->k == plant::BUSH) {
				Out(*(temp->data), ofst);
			}
			else {
				ofst << endl;
			}
			temp = temp->next;
		}
	}
} // end plants namespace