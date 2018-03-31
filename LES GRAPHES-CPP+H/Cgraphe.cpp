#pragma once
#include "Cgraphe.h"
#include <iomanip>
using namespace std;


CGraphe::CGraphe()
{
	eGRANumero=0;
	pGRAsommet=NULL;
}

CGraphe::~CGraphe()
{
	for(int i=0;i<this->eGRANumero;i++)
	{
		if(this->pGRAsommet[i] != NULL)
		{
			delete this->pGRAsommet[i];
		}	
		i++;
	}
	delete this->pGRAsommet;
}

CGraphe::CGraphe(CGraphe& graphe)
{
	eGRANumero=graphe.eGRANumero;
	pGRAsommet=new CSommetOperation*[eGRANumero];
	for(int i=0;i<eGRANumero;i++)
	{
		pGRAsommet[i]=new CSommetOperation(*(graphe.pGRAsommet[i]));
	}
}

void CGraphe::GRASetNumero(int eNumero)
{
	this->eGRANumero=eNumero;
}

void CGraphe::GRASetsommet(int eNumero)
{
	this->pGRAsommet=new CSommetOperation*[eNumero];
	for(int i=0;i<eNumero;i++)
	{
		pGRAsommet[i]=new CSommetOperation();
	}
}

CSommetOperation &CGraphe::GRALireSommet(int ePos)
{
	return *(this->pGRAsommet[ePos]);
}

int &CGraphe::GRALireNumero()
{
	return this->eGRANumero;
}

void CGraphe::GRAAffichier()
{
	cout<<"NBSommets="<<this->eGRANumero<<"\n";
	int eArcCount=0;
	int **peTemp; 
    int eLig = eGRANumero+1;
    int eCol = eGRANumero+1;
    peTemp = new int*[eLig];
	for (int i=0; i<eLig; i++)
	{
		peTemp[i] = new int[eCol];
	}
 
	for (int i=0; i<eLig; i++)
	{
		for (int j=0; j<eCol; j++)
		{
			peTemp[i][j] = 0;    
		}
	}
	for(int i=0;i<eGRANumero;i++)
	{
		peTemp[0][i+1]=pGRAsommet[i]->SOMLireSOMNumero();
		peTemp[i+1][0]=pGRAsommet[i]->SOMLireSOMNumero();
	}
	for(int m=0;m<eGRANumero;m++)
	{
		int a=0;
		int b=0;
		if(pGRAsommet[m]->SOMLireSOMArrivantNum() != 0)
		{
			while(a < pGRAsommet[m]->SOMLireSOMArrivantNum())
			{
				int eFin=pGRAsommet[m]->SOMLireArrivantElement(a).ARCLireElement();
				int ePos=0;
				while(pGRAsommet[ePos]->SOMLireSOMNumero() != eFin)
				{
					ePos++;
				}
				peTemp[m+1][ePos+1]=1;
				a++;
			}
		}
		if(pGRAsommet[m]->SOMLireSOMPartantNum() != 0)
		{
			while(b < pGRAsommet[m]->SOMLireSOMPartantNum())
			{
				int eDebut=pGRAsommet[m]->SOMLirePartantElement(b).ARCLireElement();
				int ePos=0;
				while(pGRAsommet[ePos]->SOMLireSOMNumero() != eDebut)
				{
					ePos++;
				}
				peTemp[ePos+1][m+1]=1;
				eArcCount++;
				b++;
			}
		}
	}
	cout<<"NBArcs="<<eArcCount<<"\n";
	cout<<"colonne <=> d¨¦but ligne <=> destination  "<<"\n";
	for(int c=0;c<=eGRANumero;c++)
	{
		for(int d=0;d<=eGRANumero;d++)
		{
			cout<<peTemp[c][d]<<"\t";
		}
		cout<<"\n";
	}

	for (int i=0; i<eLig; i++)
	{
		delete[] peTemp[i];
	}
	delete[] peTemp;
}

CGraphe& CGraphe::GRAInverserArcs()
{
	CGraphe *graphe=new CGraphe(*this);
	for(int i=0;i<graphe->eGRANumero;i++)
	{
		graphe->pGRAsommet[i]->SOMInverserArcs();
	}
	return *graphe;
}

