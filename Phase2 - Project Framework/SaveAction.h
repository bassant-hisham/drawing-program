#ifndef SAVE_ACTION_H
#define SAVE_ACTION_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Actions/Action.h"

//Add Rectangle Action class
class SaveAction : public Action
{
private:
	string filename;
public:
	SaveAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	ofstream Outfile;



};

#endif