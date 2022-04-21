#ifndef LOAD_ACTION_H
#define LOAD_ACTION_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Actions/Action.h"

//Add Rectangle Action class
class LoadAction : public Action
{
private:
	string filename;
public:
	LoadAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	ifstream Infile;
};

#endif
