#include "container_atd.h"
#include "plant_atd.h"
#include <fstream>
using namespace std;
namespace plants {
	// Сигнатуры требуемых внешних функций
	plant* InPlant(ifstream& ifst);
	void Out(plant& s, ofstream& ofst);
	// Инициализация контейнера
	void Init(container& c) {
		c.head = NULL;
		c.tail = NULL;
		c.size = 0;
	}
	// Очистка контейнера от элементов
	// (освобождение памяти)
	void Clear(container& c) {
		while (c.size != 0) {
			elem* temp = c.head->next;
			delete c.head;
			c.head = temp;
			c.size--;
		}
	}
	// Ввод содержимого контейнера из указанного потока
	void In(container& c, ifstream& ifst) {
		while (!ifst.eof()) {
			c.size++;
			elem* temp = new elem;
			temp->data = InPlant(ifst);
			temp->next = c.head;
			if (c.head != NULL) {
				c.tail->next = temp;
				c.tail = temp;
			}
			else {
				c.head = c.tail = temp;
			};
		}
	}
	void Out(container& c, ofstream& ofst) {
		ofst << "Container contains " << c.size << " elements." << endl;
		elem* temp = c.head;
		for (int i = 0; i < c.size; i++) {
			ofst << i << ": ";
			Out(*(temp->data), ofst);
			temp = temp->next;
		}
	}
} // end plants namespace