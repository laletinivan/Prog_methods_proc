#include "container_atd.h"
#include "plant_atd.h"
#include <fstream>
using namespace std;
namespace plants {
	// Сигнатуры требуемых внешних функций
	plant* in_plant(ifstream& ifst);
	void out(plant& s, ofstream& ofst);
	bool compare(plant& first, plant& second);
	// Инициализация контейнера
	void init(container& c) {
		c.head = NULL;
		c.tail = NULL;
		c.size = 0;
	}
	// Очистка контейнера от элементов
	// (освобождение памяти)
	void clear(container& c) {
		while (c.size != 0) {
			elem* temp = c.head->next;
			delete c.head;
			c.head = temp;
			c.size--;
		}
	}
	// Новый элемент добавить в список
	void push(container& c, elem* tmp) {
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
	// Ввод содержимого контейнера из указанного потока
	void in(container& c, ifstream& ifst) {
		while (!ifst.eof()) {
			elem* temp = new elem;
			temp->data = in_plant(ifst);
			temp->next = c.head;
			push(c, temp);
		}
	}
	//Удаление 1 элемента списка
	void delete_at(container& c, int pos) {
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
		if (pos == c.size - 1) {
			int count = 0;
			while (count != c.size - 2) {
				tmp = tmp->next;
			}
			c.tail = tmp;
		}
		for (int i = 0; i < c.size - 1; i++) {
			if (i + 1 == pos) {
				tmp->next = tmp->next->next;
				c.size--;
			}
			tmp = tmp->next;
		}
	}
	//Сортировка
	void sort(container& c) {
		container c_sort;
		init(c_sort);
		int num;
		elem* i, *small;
		while (c.size != 0) {
			small = c.head;
			i = small->next;
			num = 0;
			if (c.size != 1) {
				for (int a = 1; a < c.size; a++) {
					if (compare(*(i->data), *(small->data))) {
						num = a;
						small = i;
					}
					i = i->next;
				}
			}
			delete_at(c, num);
			push(c_sort, small);
		}
		c = c_sort;
		c.head = c_sort.head;
		c.tail = c_sort.tail;
	}
	//Вывод элементов
	void out(container& c, ofstream& ofst) {
		ofst << "Container contains " << c.size << " elements." << endl;
		elem* temp = c.head;
		for (int i = 0; i < c.size; i++) {
			ofst << i << ": ";
			out(*(temp->data), ofst);
			temp = temp->next;
		}
	}
	//Вывод только кустов
	void out_bush(container& c, ofstream& ofst) {
		ofst << "Only bushes." << endl;
		elem* temp = c.head;
		for (int i = 0; i < c.size; i++) {
			ofst << i << ": ";
			if (temp->data->k == plant::BUSH) {
				out(*(temp->data), ofst);
			}
			else {
				ofst << endl;
			}
			temp = temp->next;
		}
	}
} // end plants namespace