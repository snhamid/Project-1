#ifndef Todo_hpp
#define Todo_hpp

#include <stdio.h>
#include <string>

class Todo
{

private:
	int id;
	int priority;
	std::string title;
	std::string description;

	enum Type
	{
		shopping,
		housing,
		work,
		noType
	};
	enum Status
	{
		done,
		inprogress,
		hold,
		noStatus
	};

	struct date
	{
		int day;
		int month;
		int year;
	};

	date createDate;
	date dueDate;
	date lastModified;
	Type type;
	Status status;

public:
	//Constructors
	Todo();
	Todo(std::string strTitle, std::string strDesc, std::string strType);
	Todo(std::string strTitle, std::string strType, int numPriority);
	Todo(std::string strTitle, std::string strType, int numPriority, int d, int m, int y);

	//Setter methods
	void setID(int numID);
	void setTitle(std::string strTitle);
	void setDescription(std::string strDescription);
	void setType(std::string strType);
	void setPriority(int numPriority);
	void setStatus(std::string strStatus);
	void setCreateDate();
	void setCreateDateNum(int d, int m, int y);
	void setDueDate(int d, int m, int y);
	void setLastModified();

	//Gettier methods
	int getID();
	std::string getTitle();
	std::string getDescription();
	std::string getType();
	int getPriority();
	std::string getStatus();
	std::string getCreateDate();
	std::string getDueDate();
	std::string getLastModified();
	int getCreateDateM();
	int getCreateDateD();
	int getCreateDateY();
	int getDueDateM();
	int getDueDateD();
	int getDueDateY();

	//Tostring methods
	std::string createDateToString();
	std::string dueDateToString();
	std::string lastModDateToString();
	std::string typeToString();
	std::string statusToString();

	void fillInfo();
};

#endif
