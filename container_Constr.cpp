#include "container_atd.h"
#include "plant_atd.h"
namespace plants {
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
			elem *temp = c.head->next;
			delete c.head;                           
			c.head = temp;                           
			c.size--;
		}
	}
} // end plants namespace