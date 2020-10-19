#include "ToDoList.hpp"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

ToDoList::ToDoList()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        list[i] = Todo();
    }
    position = 0;
}

ToDoList::ToDoList(const ToDoList &original)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        list[i] = original.list[i];
    }
    position = original.position;
}

void ToDoList::addItem()
{
    list[position] = Todo();
    list[position].fillInfo();
    position++;
}

void ToDoList::editItem(int itemID)
{
    int selection;
    std::string newString;
    int newPriority;
    int day;
    int month;
    int year;

    std::cout << "What would you like to edit? Enter a number: \n";
    std::cout << "1. Title\n";
    std::cout << "2. Description\n";
    std::cout << "3. Type\n";
    std::cout << "4. Priority\n";
    std::cout << "5. Status\n";
    std::cout << "6. Due date\n";
    std::cout << "Enter 0 to exit\n";
    std::cin >> selection;

    switch (selection)
    {
    case 1:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getID() == itemID)
            {
                std::cout << "Enter a new title: ";
                std::cin >> newString;
                list[i].setTitle(newString);
                list[i].setLastModified();
            }
        }

        break;

    case 2:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getID() == itemID)
            {
                std::cout << "Enter a new description: ";
                std::getline(std::cin, newString);
                list[i].setDescription(newString);
                list[i].setLastModified();
            }
        }

    case 3:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getID() == itemID)
            {
                std::cout << "Enter a new type: ";
                std::cin >> newString;
                list[i].setType(newString);
                list[i].setLastModified();
            }
        }
        break;

    case 4:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getID() == itemID)
            {

                std::cout << "Enter a new priority: ";
                std::cin >> newPriority;
                list[i].setPriority(newPriority);
                list[i].setLastModified();
            }
        }
        break;

    case 5:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getID() == itemID)
            {

                std::cout << "Enter a new status: ";
                std::cin >> newPriority;
                list[i].setStatus(newString);
                list[i].setLastModified();
            }
        }

    case 6:

        for (int i = 0; i < position; i++)
        {
            if (list[i].getID() == itemID)
            {
                std::cout << "Enter a new due date: \n";
                std::cout << "Day: ";
                std::cin >> day;
                std::cout << "\n";
                std::cout << "Enter a month: ";
                std::cin >> month;
                std::cout << "\n";
                std::cout << "Enter a year: ";
                std::cin >> year;
                list[i].setDueDate(day, month, year);
                list[i].setLastModified();
            }
        }

    default:
        break;
    }
}

void ToDoList::deleteItem(int itemID)
{
    for (int i = 0; i < position; i++)
    {
        if (list[i].getID() == itemID)
        {
            list[i] = Todo();
        }
    }
}

void ToDoList::deleteByType()
{
    int selection;
    std::cout << "Select the type to delete: \n";
    std::cout << "1. Shopping \n";
    std::cout << "2. Housing \n";
    std::cout << "3. Work \n";
    std::cin >> selection;

    switch (selection)
    {
    case 1:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getType() == "shopping")
            {
                list[i] = Todo();
            }
        }
        break;

    case 2:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getType() == "housing")
            {
                list[i] = Todo();
            }
        }
        break;

    case 3:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getType() == "work")
            {
                list[i] = Todo();
            }
        }
        break;

    default:
        break;
    }
}

void ToDoList::deleteByStatus()
{
    int selection;
    std::cout << "Select the status to delete: \n";
    std::cout << "1. Done\n";
    std::cout << "2. In progress\n";
    std::cout << "3. Hold\n";
    std::cin >> selection;

    switch (selection)
    {
    case 1:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getStatus() == "done")
            {
                list[i] = Todo();
            }
        }
        break;

    case 2:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getStatus() == "inprogress")
            {
                list[i] = Todo();
            }
        }
        break;

    case 3:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getStatus() == "hold")
            {
                list[i] = Todo();
            }
        }
        break;

    default:
        break;
    }
}

void ToDoList::writeList()
{
    std::ofstream listFileOut;
    listFileOut.open("list.txt");
    int i = 0;
    for (i = 0; i < position; i++)
    {
        if (list[i].getPriority() == 0)
        {
        }
        else
        {
            listFileOut << printObject(list[i]) << std::endl;
        }
    }
}

void ToDoList::readList()
{
    std::ifstream readFile;
    readFile.open("list.txt");
    std::string line;
    std::string s;
    int month;
    int day;
    int year;
    std::string getDate;
    int infoNum = 1;
    int numLines = 0;
    int i = 0;

    std::string typeIn;
    std::string priorityIn;
    std::string titleIn;
    std::string desIn;
    std::string statusIn;
    std::string createIn;
    std::string dueIn;
    std::string lastIn;

    while (!readFile.eof())
    {

        getline(readFile, priorityIn, ',');
        getline(readFile, titleIn, ',');
        getline(readFile, desIn, ',');
        getline(readFile, typeIn, ',');
        getline(readFile, statusIn, ',');
        getline(readFile, createIn, ',');
        getline(readFile, dueIn, ',');
        getline(readFile, lastIn, ',');

        list[i].setPriority(stoi(priorityIn));
        list[i].setTitle(titleIn);
        list[i].setDescription(desIn);
        list[i].setType(typeIn);
        list[i].setStatus(statusIn);

        day = stoi(createIn.substr(0, 2));
        month = stoi(createIn.substr(3, 2));
        year = stoi(createIn.substr(6, 10));
        list[i].setCreateDateNum(day, month, year);

        day = stoi(dueIn.substr(0, 2));
        month = stoi(dueIn.substr(3, 2));
        year = stoi(dueIn.substr(6, 10));
        list[i].setDueDate(day, month, year);
        list[i].setLastModified();
        position++;
    }
}

void ToDoList::sortByPriority()
{
    int selection;
    std::cout << "Sort by priority: \n";
    std::cout << "1. High to low\n";
    std::cout << "2. Low to high\n";
    std::cin >> selection;
    int i;
    Todo key;
    int j;
    int n = sizeof(list) / sizeof(list[0]);

    switch (selection)
    {
    case 1:
        for (i = 1; i < n; i++)
        {
            key = list[i];
            j = i - 1;

            while (j >= 0 && list[j].getPriority() > key.getPriority())
            {
                list[j + 1] = list[j];
                j = j - 1;
            }
            list[j + 1] = key;
        }
        break;

    case 2:
        for (i = 1; i < n; i++)
        {
            key = list[i];
            j = i - 1;

            while (j >= 0 && list[j].getPriority() < key.getPriority())
            {
                list[j + 1] = list[j];
                j = j - 1;
            }
            list[j + 1] = key;
        }

        break;
    }
}

void ToDoList::sortByDueDate()
{
    int i;
    Todo key;
    int j;
    int n = sizeof(list) / sizeof(list[0]);
    for (i = 1; i < n; i++)
    {
        key = list[i];
        j = i - 1;

        while (j >= 0 && list[j].getDueDateY() > key.getDueDateY())
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }

    Todo key2;
    for (i = 1; i < n; i++)
    {
        key2 = list[i];
        j = i - 1;

        while (j >= 0 && list[j].getDueDateY() == key2.getDueDateY() && list[j].getDueDateM() > key2.getDueDateM())
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key2;
    }

    Todo key3;
    for (i = 1; i < n; i++)
    {
        key3 = list[i];
        j = i - 1;

        while (j >= 0 && list[j].getDueDateY() == key3.getDueDateY() && list[j].getDueDateM() == key3.getDueDateM() && list[j].getDueDateD() > key3.getDueDateD())
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key3;
    }
}

void ToDoList::sortByCreateDate()
{
    int i;
    Todo key;
    int j;
    int n = sizeof(list) / sizeof(list[0]);
    for (i = 1; i < n; i++)
    {
        key = list[i];
        j = i - 1;

        while (j >= 0 && list[j].getCreateDateY() > key.getCreateDateY())
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }

    Todo key2;
    for (i = 1; i < n; i++)
    {
        key2 = list[i];
        j = i - 1;

        while (j >= 0 && list[j].getCreateDateY() == key2.getCreateDateY() && list[j].getCreateDateM() > key2.getCreateDateM())
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key2;
    }

    Todo key3;
    for (i = 1; i < n; i++)
    {
        key3 = list[i];
        j = i - 1;

        while (j >= 0 && list[j].getCreateDateY() == key3.getCreateDateY() && list[j].getCreateDateM() == key3.getCreateDateM() && list[j].getCreateDateD() > key3.getCreateDateD())
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key3;
    }
}

void ToDoList::sortByType()
{
    int selection;
    std::cout << "Select inner sort: \n";
    std::cout << "1. Priority \n";
    std::cout << "2. Due Date \n";
    std::cin >> selection;

    int i;
    Todo key;
    int j;
    int n = sizeof(list) / sizeof(list[0]);

    for (i = 1; i < n; i++)
    {
        key = list[i];
        j = i - 1;

        while (j >= 0 && list[j].getType().length() > key.getType().length())
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }

    switch (selection)
    {
    case 1:
        sortByDueDate();
        break;

    case 2:
        sortByPriority();
        break;

    default:
        break;
    }
}

void ToDoList::printAllItems()
{
    for (int i = 0; i < position; i++)
    {
        if (list[i].getPriority() == 0)
        {
        }
        else
        {
            std::cout << printObject(list[i]) + "\n";
        }
    }
}

void ToDoList::printByType()
{
    int selection;
    std::cout << "Select a type to print: \n";
    std::cout << "1. Shopping \n";
    std::cout << "2. Work \n";
    std::cout << "3. Housing \n";
    std::cin >> selection;

    switch (selection)
    {
    case 1:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getType() == "shopping")
            {
                std::cout << printObject(list[i]) + "\n";
            }
            else
            {
            }
        }
        break;

    case 2:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getType() == "work")
            {
                std::cout << printObject(list[i]) + "\n";
            }
            else
            {
            }
        }
        break;

    case 3:
        for (int i = 0; i < position; i++)
        {
            if (list[i].getType() == "housing")
            {
                std::cout << printObject(list[i]) + "\n";
            }
            else
            {
            }
        }
        break;

    default:
        break;
    }
}

void ToDoList::printByPriority()
{
    int selection;
    std::cout << "Select priority to print (1-5): \n";
    std::cin >> selection;
    std::cout << "\n";

    for (int i = 0; i < position; i++)
    {
        if (list[i].getPriority() == selection)
        {
            std::cout << printObject(list[i]) + "\n";
        }
        else
        {
        }
    }
}

void ToDoList::printByID()
{
    int selection;
    std::cout << "Enter ID to print: \n";
    std::cin >> selection;
    std::cout << "\n";

    for (int i = 0; i < position; i++)
    {
        if (list[i].getID() == selection)
        {
            std::cout << printObject(list[i]) + "\n";
        }
        else
        {
        }
    }
}

std::string ToDoList::printObject(Todo todoObject)
{
    std::string priority = std::to_string(todoObject.getPriority());
    std::string title = todoObject.getTitle();
    std::string description = todoObject.getDescription();
    std::string type = todoObject.getType();
    std::string status = todoObject.getStatus();
    std::string dateCreated = todoObject.getCreateDate();
    std::string dueDate = todoObject.getDueDate();
    std::string lastMod = todoObject.getLastModified();
    char comma = ',';
    std::string newline = "\n";

    std::string objectLine = priority + comma + title + comma + description + comma + type + comma + status + comma + dateCreated + comma + dueDate + comma + lastMod + newline;
    return objectLine;
}

void ToDoList::mergeList(const ToDoList &merger)
{
    int j;
    int totalSize = position + sizeof(merger) + 1;
    for (int i = position + 1; i < totalSize; i++)
    {
        list[i] = merger.list[j];
        list[i].setID(position + 1);
        position++;
    }
}

void ToDoList::clone(const ToDoList &cloner)
{
    for (int i = 0; i < position; i++)
    {
        list[i] = cloner.list[i];
    }
}
