#pragma once
#include "CSommetOperation.h"
#include "stdio.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class CGraphe
{
	protected:
		int eGRANumero;
		CSommetOperation **pGRAsommet;
	
	public:
		CGraphe();
		~CGraphe();
		CGraphe(CGraphe& graphe);
		
		int &GRALireNumero();
		CSommetOperation &GRALireSommet(int ePos);

		void GRASetNumero(int eNumero);
		void GRASetsommet(int eNumero);

		void GRAAffichier();
		CGraphe& GRAInverserArcs();
};