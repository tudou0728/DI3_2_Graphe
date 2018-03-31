#pragma once
#include "Carc.h"
#include "Cexception.h"

using namespace std;

class CSommet
{
	protected:
		int eSOMNumero;

		CArc** SOMArrivant;
		int eSOMArrivantNum;

		CArc** SOMPartant;
		int eSOMPartantNum;
	
	public:
		CSommet();
		~CSommet();
		CSommet(CSommet &sommet);

		void SOMSetSOMNumero(int eNum);
		void SOMSetSOMArrivantNum(int eNum);
		void SOMSetSOMPartantNum(int eNum);
	
		int SOMLireSOMNumero();
		int SOMLireSOMArrivantNum();
		int SOMLireSOMPartantNum();

		CArc** SOMLireArrivant();
		CArc** SOMLirePartant();
		CArc& SOMLireArrivantElement(int ePos);
		CArc& SOMLirePartantElement(int ePos);

		void SOMInverserArcs();

};