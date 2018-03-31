#pragma once
#include "Csommet.h"

using namespace std;

CSommet::CSommet()
{
	this->eSOMNumero=0;
	this->eSOMArrivantNum=0;
	this->eSOMPartantNum=0;
	this->SOMArrivant=NULL;
	this->SOMPartant=NULL;
}

CSommet::~CSommet()
{
	int i=0;
	if(this->SOMArrivant != NULL && this->eSOMArrivantNum!=0)
	{
		while(i<this->eSOMArrivantNum)
		{
			if(this->SOMArrivant[i] != NULL)
			{
				delete this->SOMArrivant[i];
				this->SOMArrivant[i]=NULL;
			}
			i++;
		}
		delete this->SOMArrivant;
		this->SOMArrivant=NULL;
	}
	int j=0;
	if(this->SOMPartant != NULL && this->eSOMPartantNum!=0)
	{
		while(j<this->eSOMPartantNum)
		{
			if(this->SOMPartant[j] != NULL)
			{
				delete this->SOMPartant[j];
				this->SOMPartant[j]=NULL;
			}
			j++;
		}
		delete this->SOMPartant;
		this->SOMPartant=NULL;
	}
}


CSommet::CSommet(CSommet &sommet)
{
	this->eSOMNumero=sommet.eSOMNumero;
	this->eSOMArrivantNum=sommet.eSOMArrivantNum;
	this->eSOMPartantNum=sommet.eSOMPartantNum;
	if(sommet.SOMArrivant != NULL)
	{
		this->SOMArrivant=new CArc*[eSOMArrivantNum];
		for(int i=0;i<eSOMArrivantNum;i++)
		{
			SOMArrivant[i]=new CArc((sommet.SOMArrivant[i])->ARCLireElement());
		}
	}
	if(sommet.SOMPartant != NULL)
	{
		this->SOMPartant=new CArc*[eSOMPartantNum];
		for(int j=0;j<eSOMPartantNum;j++)
		{
			SOMPartant[j]=new CArc((sommet.SOMPartant[j])->ARCLireElement());
		}
	}
}

int CSommet::SOMLireSOMNumero()
{
	return this->eSOMNumero;
}

int CSommet::SOMLireSOMArrivantNum()
{
	return this->eSOMArrivantNum;
}

int CSommet::SOMLireSOMPartantNum()
{
	return this->eSOMPartantNum;
}

void CSommet::SOMSetSOMNumero(int eNum)
{
	this->eSOMNumero=eNum;
}

void CSommet::SOMSetSOMArrivantNum(int eNum)
{
	this->eSOMArrivantNum=eNum;
}

void CSommet::SOMSetSOMPartantNum(int eNum)
{
	this->eSOMPartantNum=eNum;
}

CArc& CSommet::SOMLireArrivantElement(int ePos)
{
	return *(this->SOMArrivant[ePos]);
}

CArc& CSommet::SOMLirePartantElement(int ePos)
{
	return *(this->SOMPartant[ePos]);
}

CArc** CSommet::SOMLireArrivant()
{
	return this->SOMArrivant;
}

CArc** CSommet::SOMLirePartant()
{
	return this->SOMPartant;
}

void CSommet::SOMInverserArcs()
{
	CArc **temp=this->SOMArrivant;
	this->SOMArrivant=this->SOMPartant;
	this->SOMPartant=temp;

	int eTemp=this->eSOMArrivantNum;
	this->eSOMArrivantNum=this->eSOMPartantNum;
	this->eSOMPartantNum=eTemp;
}

