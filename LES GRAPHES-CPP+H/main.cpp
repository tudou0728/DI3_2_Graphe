#pragma once
#include"Cfichier.h"
#include<Windows.h>

using namespace std;

int main(int argc, char *argv[])
{
	try
	{
		for(int i=1;i<argc;i++)
		{
			//lire fichier
			cout<<"1-lire fichier:"<<"\n";
			CGrapheOperation *graphe =new CGrapheOperation();
			CFichier fichier=CFichier();
			graphe=&(fichier.FICLireFichier(argv[i]));
			cout<<"le r¨¦sultat est:"<<"\n";
			//affichier le graphe
			graphe->GRAAffichier();
			cout<<"*************cette operation est fini********************"<<"\n";
			cout<<"\n";
			//inverser le graphe
			CGraphe *grapheInverse=&(graphe->GRAInverserArcs());
			cout<<"2-inverser un graphe:"<<"\n";
			cout<<"le r¨¦sultat est:"<<"\n";
			//affichier le nouveau graphe
			grapheInverse->GRAAffichier();
			cout<<"*************cette op¨¦ration est fini********************"<<"\n";
			cout<<"\n";
			delete graphe;
			delete grapheInverse;	
			cout<<"------------------ce projet est fini-----------------------"<<"\n";
		}
	}
	catch(Cexception a)
	{
		if(a.CEXLireErreur() == 1)
		{ a.CEXOuvreFile();}
		if(a.CEXLireErreur() == 2)
		{ a.CEXFileType();}
		if(a.CEXLireErreur() == 3)
		{ a.CEXErreurGeneral();}
		if(a.CEXLireErreur() == 4)
		{ a.CEXRepeter();}
		Sleep(5000);
	}
	exit(1);
}

