#include "SnakeList.h"

Node::Node(int _x, int _y) 
	: x(_x), y(_y), prev(nullptr), next(nullptr) {};
SnakeList::SnakeList() : head(nullptr), tail(nullptr) {};
void SnakeList::push_front(int x, int y) {
	auto newNode = std::make_unique<Node>(x, y);
	if (!head) {
		head = move(newNode);
		tail = head.get();
	}
	else {
		newNode->next = move(head);
		newNode->next->prev = newNode.get();
		head = move(newNode);
	}

}

//Debug method
void SnakeList:: printList() {
	Node* temp = head.get();
	std::cout << "Snake (head->tail): " << std::endl;
	while (temp != nullptr) {
		std::cout << "[" << temp->x << "," << temp->y << "] ";
		temp=temp->next.get();
	}
	std::cout << "\n";
}
void SnakeList::pop_back() {
	if (!head) {
		return;
	}
	if (head.get() == tail) {
		head.reset();
		tail = nullptr;
	}
	else {
		Node* newTail = tail->prev;
		newTail->next.reset();
		tail = newTail;
	}

}
bool SnakeList::isSnakeAt(int x, int y) {
	Node* temp = head.get();
	while (temp) {
		if (temp->x == x && temp->y == y) {
			return true;
		}
		temp = temp->next.get();
	}
	return false;
}

//Deep copy
SnakeList::SnakeList(const SnakeList& other) : head(nullptr), tail(nullptr) {
	if (!other.tail) return;
	Node* temp = other.tail;
	while (temp) {
		this->push_front(temp->x, temp->y);
		temp = temp->prev;
	}
}

//Move Constructor
SnakeList::SnakeList(SnakeList&& other) noexcept : head(std::move(other.head)), tail(other.tail) {
	other.tail = nullptr;
}

//Copy operator
SnakeList& SnakeList::operator=(const SnakeList& other) {
	if (this != &other) {
		head.reset();
		tail = nullptr;


		if (other.tail) {
			Node* temp = other.tail;
			while (temp) {
				this->push_front(temp->x, temp->y);
				temp = temp->prev;
			}
		}
	}
	return *this;
}

//Move operator
SnakeList& SnakeList::operator=(SnakeList&& other) noexcept {
	if (this != &other) {
		head.reset();
		head = std::move(other.head);
		tail = other.tail;
		other.tail = nullptr;
	}
	return *this;
}
