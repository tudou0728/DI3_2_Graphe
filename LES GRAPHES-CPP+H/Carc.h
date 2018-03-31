#pragma once
#include "stdio.h"
#include <stdlib.h>
using namespace std;

class CArc
{
	private:
		int eARCDestination;
	
	public:

		CArc();
		CArc(int eDest);
		CArc& ARCClone(CArc &arc);
		int &ARCLireElement();
		void ARCSetElement(int eDest);
};