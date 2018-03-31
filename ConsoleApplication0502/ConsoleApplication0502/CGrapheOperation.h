#include "Cgraphe.h"

class CGrapheOperation: public CGraphe
{
	public:
		void GRAAjouterSommet(CSommetOperation &sommet,int ePos);
		void GRAAjouterArc(int ePart,int eArri);
		
		void GRAModifierSommetNumero(int eSommet,int eMSommet);
		void GRAModifierSommet(CSommetOperation &sommet,int ePos);
		void GRAModifierArc(int ePart,int eArri,int eMArri);

		void GRASupprimerSommet(int eElement);
		void GRASupprimerArc(int ePart,int eArri);	
};