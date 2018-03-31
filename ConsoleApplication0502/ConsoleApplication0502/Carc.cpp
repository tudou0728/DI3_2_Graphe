#pragma once
#include "Carc.h"

using namespace std;

CArc::CArc()
{
	this->eARCDestination=0;
}

CArc::CArc(int eDest)
{
	this->eARCDestination=eDest;
}

CArc& CArc::ARCClone(CArc &arc)
{
	CArc *temp=new CArc(arc.eARCDestination);
	return *temp;
}

int& CArc::ARCLireElement()
{
	return this->eARCDestination;
}

void CArc::ARCSetElement(int eDest)
{
	this->eARCDestination=eDest;
}