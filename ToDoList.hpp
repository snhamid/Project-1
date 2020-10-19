#ifndef TodoList_hpp
#define TodoList_hpp

#include <stdio.h>
#include "Todo.cpp"

#define MAX_SIZE 100

class ToDoList
{
private:
	Todo list[MAX_SIZE];

public:
	ToDoList();
	ToDoList(const ToDoList &original);
	int position;

	//Editing list
	void addItem();
	void editItem(int itemID);
	void deleteItem(int itemID);
	void deleteByType();
	void deleteByStatus();

	void writeList();
	void readList();

	//Sorting
	void sortByPriority();
	void sortByDueDate();
	void sortByCreateDate();
	void sortByType();

	//Printing
	void printAllItems();
	void printByType();
	void printByPriority();
	void printByID();
	std::string printObject(Todo todoObject);

	void mergeList(const ToDoList &merger);
	void clone(const ToDoList &cloner);
};

std::string **twoDimensionList(ToDoList &oneList);
std::string ***threeDimensionList(ToDoList &oneList);

#endif
