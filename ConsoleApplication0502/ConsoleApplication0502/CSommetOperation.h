#include "Csommet.h"

class CSommetOperation: public CSommet 
{
	public:
		void SOMAjouterAFinArrivant(CArc &arc);
		void SOMAjouterAFinPartant(CArc &arc);

		void SOMModifierArrivant(CArc &arc,int ePos);
		void SOMModifierPartant(CArc &arc,int ePos);

		void SOMSupprimerArrivant(int ePos);
		void SOMSupprimerPartant(int ePos);
		void SOMSupprimerElementArrivant(int eElement);
		void SOMSupprimerElementPartant(int eElement);
};