#include <iostream>
#include "list.h"

DataType GCD(DataType a, DataType b) {
	return (b == 0 ? a : GCD(b, a % b));
}

DataType LCM(List list) {
	
	if (list.isEmptyList()) {
		return 1;
	}

	int lcm = LCM(list.subList());

	return (list.getHead() * lcm) / GCD(list.getHead(), lcm);
}

List REPLACE(List list, DataType old_elem, DataType new_elem) {
	if (list.isEmptyList()) {
		return list;
	}

	List res(REPLACE(list.subList(), old_elem, new_elem));

	if(list.getHead() == old_elem) {
		res.push_front(new_elem);
	} else {
		res.push_front(list.getHead());
	}

	return res;
}
int main() {
	int n;
	List list;

	std::cout << "Number of elements: ";
	std::cin >> n;

	for(int i = 1; i <= n; i++) {
		int data;

		std::cout << "Element #" << i <<": ";
		std::cin >> data;

		list.push_back(data);
	}

	while(true) {
		std::cout << "Press 0 to exit\n"
					<< "Press 1 to get the LCM of the list\n"
					<< "Press 2 to replace all occurences of a given element\n"
					<< "Your command: ";

		int command;
		std::cin >> command;

		if (command == 0) {
			break;
		}

		if (command == 1)  {
			std::cout << "LCM of the given list is " << LCM(list) << '\n';
		}

		if (command == 2) {
			std::cout << "Element to be replaced: ";
			int old_elem;
			std::cin >> old_elem;

			std::cout << "New element: ";
			int new_elem;
			std::cin >> new_elem;

			REPLACE(list, old_elem, new_elem).printList();
		}
	}

	return 0;
}