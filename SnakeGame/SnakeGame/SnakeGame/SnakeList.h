#pragma once
#include <memory>
#include <iostream>
#include <conio.h>
#include <Windows.h>

//segment wê¿a 
struct Node {
	int x, y;
	std::unique_ptr<Node> next;
	Node* prev;
	Node(int _x, int _y);
};
class SnakeList {
	std::unique_ptr<Node> head;
	Node* tail;
public:
	SnakeList();

	void push_front(int x, int y);

	void printList();
	
	void pop_back();
	bool isSnakeAt(int x, int y);
};

