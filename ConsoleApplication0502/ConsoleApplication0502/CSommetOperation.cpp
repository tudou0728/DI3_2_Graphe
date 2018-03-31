#include "CSommetOperation.h"

void CSommetOperation::SOMModifierArrivant(CArc &arc,int ePos)
{
	this->SOMLireArrivantElement(ePos).ARCSetElement(arc.ARCLireElement());
}

void CSommetOperation::SOMModifierPartant(CArc &arc,int ePos)
{
	this->SOMLirePartantElement(ePos).ARCSetElement(arc.ARCLireElement());
}

void CSommetOperation::SOMSupprimerArrivant(int ePos)
{
	int eNumero=this->SOMLireSOMArrivantNum();
	if(ePos == eNumero-1)
	{
		SOMArrivant=(CArc**)realloc(SOMArrivant,(eNumero-1)*sizeof(CArc*));
		this->SOMSetSOMArrivantNum(eNumero-1);
	}
	else if(ePos < eNumero-1 && ePos>=0)
	{
		for(int i=ePos;i<eNumero-1;i++)
		{
			this->SOMLireArrivantElement(i).ARCSetElement(this->SOMLireArrivantElement(i+1).ARCLireElement());
		}
		SOMArrivant=(CArc**)realloc(SOMArrivant,(eNumero-1)*sizeof(CArc*));
		this->SOMSetSOMArrivantNum(eNumero-1);
	}
}

void CSommetOperation::SOMSupprimerPartant(int ePos)
{
	if(ePos == eSOMPartantNum-1)
	{
		SOMPartant=(CArc**)realloc(SOMPartant,(eSOMPartantNum-1)*sizeof(CArc*));
		eSOMPartantNum--;
	}
	if(ePos < eSOMPartantNum-1 && ePos>=0)
	{
		for(int i=ePos;i<eSOMPartantNum-1;i++)
		{
			SOMPartant[i]->ARCSetElement(SOMPartant[i+1]->ARCLireElement());
		}
		SOMPartant=(CArc**)realloc(SOMPartant,(eSOMPartantNum-1)*sizeof(CArc*));
		eSOMPartantNum--;
	}
}

void CSommetOperation::SOMAjouterAFinArrivant(CArc &arc)
{
	int i=0;
	while(i<this->eSOMArrivantNum)
	{
		if(this->SOMArrivant[i]->ARCLireElement() == arc.ARCLireElement())
		{
			Cexception a(4);//已经存在了
			throw a;
		}
		i++;
	}
	if(eSOMArrivantNum != 0)
	{
		SOMArrivant=(CArc**)realloc(SOMArrivant,(eSOMArrivantNum+1)*sizeof(CArc*));
	}
	else
	{
		SOMArrivant=new CArc*[1];
	}
	SOMArrivant[eSOMArrivantNum]=new CArc(arc.ARCLireElement());
	eSOMArrivantNum=eSOMArrivantNum+1;
	
}

void CSommetOperation::SOMAjouterAFinPartant(CArc &arc)
{
	int i=0;
	while(i<this->eSOMPartantNum)
	{
		if(this->SOMPartant[i]->ARCLireElement() == arc.ARCLireElement())
		{
			Cexception a(4);//已经存在了
			throw a;
		}
		i++;
	}
	if(eSOMPartantNum != 0)
	{
		SOMPartant=(CArc**)realloc(SOMPartant,(eSOMPartantNum+1)*sizeof(CArc*));
	}
	else
	{
		SOMPartant=new CArc*[1];
	}
	SOMPartant[eSOMPartantNum]=new CArc(arc.ARCLireElement());
	eSOMPartantNum=eSOMPartantNum+1;
}

void  CSommetOperation::SOMSupprimerElementArrivant(int eElement)
{
	int ePos=0;
	while(ePos<this->eSOMArrivantNum && this->SOMArrivant[ePos]->ARCLireElement() != eElement)
	{
		ePos++;
	}
	if(ePos>=this->eSOMArrivantNum)
	{
		Cexception a(3);//没找到
		throw a;
	}
	this->SOMSupprimerArrivant(ePos);
}

void  CSommetOperation::SOMSupprimerElementPartant(int eElement)
{
	int ePos=0;
	while(ePos<this->eSOMPartantNum && this->SOMPartant[ePos]->ARCLireElement() != eElement)
	{
		ePos++;
	}
	if(ePos>=this->eSOMPartantNum)
	{
		Cexception a(3);//没找到
		throw a;
	}
	this->SOMSupprimerPartant(ePos);
}