
#include <cassert>
#include <ctime>
#include <iostream>
#include "Todo.hpp"
#include <sstream>
#include <vector>
#include <fstream>

Todo::Todo()
{
    id = -1;
    priority = 0;
    title = "N/A";
    description = "N/A";
    setType("noType");
    setStatus("noStatus");
    setCreateDate();
}

Todo::Todo(std::string strTitle, std::string strDesc, std::string strType)
{
    title = strTitle;
    description = strDesc;
    setType(strType);
}

//Set methods
void Todo::setID(int numID)
{
    id = numID;
}

void Todo::setTitle(std::string strTitle)
{
    title = strTitle;
}

void Todo::setDescription(std::string strDescription)
{
    description = strDescription;
}

void Todo::setType(std::string strType)
{
    if (strType == "shopping")
    {
        type = shopping;
    }

    if (strType == "housing")
    {
        type = housing;
    }

    if (strType == "work")
    {
        type = work;
    }

    if (strType == "noType")
    {
        type = noType;
    }
    else
    {
    }
}

void Todo::setPriority(int numPriority)
{
    priority = numPriority;
}

void Todo::setStatus(std::string strStatus)
{
    if (strStatus == "done")
    {
        status = done;
    }

    if (strStatus == "inprogress")
    {
        status = inprogress;
    }

    if (strStatus == "hold")
    {
        status = hold;
    }

    if (strStatus == "noStatus")
    {
        status = noStatus;
    }
    else
    {
    }
}

void Todo::setCreateDate()
{
    time_t t = time(NULL);
    tm *timeStamp = localtime(&t);
    createDate.day = timeStamp->tm_mday;
    createDate.month = timeStamp->tm_mon + 1;
    createDate.year = timeStamp->tm_year + 1900;
}

void Todo::setCreateDateNum(int d, int m, int y)
{
    createDate.day = d;
    createDate.month = m;
    createDate.year = y;
}

void Todo::setDueDate(int d, int m, int y)
{
    dueDate.day = d;
    dueDate.month = m;
    dueDate.year = y;
}

void Todo::setLastModified()
{
    time_t t = time(NULL);
    tm *timeStamp = localtime(&t);
    lastModified.day = timeStamp->tm_mday;
    lastModified.month = timeStamp->tm_mon + 1;
    lastModified.year = timeStamp->tm_year + 1900;
}

//Getter methods
int Todo::getID()
{
    return id;
}

std::string Todo::getTitle()
{
    return title;
}

std::string Todo::getDescription()
{
    return description;
}

std::string Todo::getType()
{
    return typeToString();
}

int Todo::getPriority()
{
    return priority;
}

std::string Todo::getStatus()
{
    return statusToString();
}

std::string Todo::getCreateDate()
{
    return createDateToString();
}

std::string Todo::getDueDate()
{
    return dueDateToString();
}

std::string Todo::getLastModified()
{
    return lastModDateToString();
}

//Tostring methods
std::string Todo::createDateToString()
{
    std::string day = std::to_string(createDate.day);
    std::string month = std::to_string(createDate.month);
    std::string year = std::to_string(createDate.year);
    return day + "/" + month + "/" + year;
}

std::string Todo::dueDateToString()
{
    std::string day = std::to_string(dueDate.day);
    std::string month = std::to_string(dueDate.month);
    std::string year = std::to_string(dueDate.year);
    return day + "/" + month + "/" + year;
}

std::string Todo::lastModDateToString()
{
    std::string day = std::to_string(lastModified.day);
    std::string month = std::to_string(lastModified.month);
    std::string year = std::to_string(lastModified.year);
    return day + "/" + month + "/" + year;
}

std::string Todo::typeToString()
{
    if (type == shopping)
        return "shopping";

    if (type == work)
        return "work";

    if (type == housing)
        return "house";

    return "";
}

std::string Todo::statusToString()
{
    if (status == done)
        return "Done";

    if (status == inprogress)
        return "In progress";

    if (status == hold)
        return "Hold";

    return "";
}
void Todo::fillInfo()
{
    std::string userEntry;
    std::string userType;
    std::string userDes;

    int numEntry;
    int day;
    int month;
    int year;
    int newID;

    std::cout << "Enter an ID: \n";
    std::cin >> newID;
    setID(newID);

    std::cout << "Enter a title:\n";
    std::cin >> userEntry;
    setTitle(userEntry);

    std::cout << "Enter a description: \n";
    std::cin >> userDes;
    setDescription(userDes);

    std::cout << "Enter a type: \n";
    std::cin >> userType;
    setType(userType);

    std::cout << "Enter a status:\n";
    std::cin >> userEntry;
    setStatus(userEntry);

    std::cout << "Enter a priority:\n";
    std::cin >> numEntry;
    setPriority(numEntry);

    setCreateDate();

    std::cout << "Enter a due date:\n";
    std::cout << "Day: ";
    std::cin >> day;
    std::cout << "\n";
    std::cout << "Enter a month: ";
    std::cin >> month;
    std::cout << "\n";
    std::cout << "Enter a year: ";
    std::cin >> year;
    setDueDate(day, month, year);
    setLastModified();
}

int Todo::getCreateDateM()
{
    return createDate.month;
}

int Todo::getCreateDateD()
{
    return createDate.day;
}

int Todo::getCreateDateY()
{
    return createDate.year;
}

int Todo::getDueDateM()
{
    return dueDate.month;
}

int Todo::getDueDateD()
{
    return dueDate.day;
}

int Todo::getDueDateY()
{
    return dueDate.year;
}