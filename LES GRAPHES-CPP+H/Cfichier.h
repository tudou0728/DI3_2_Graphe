#pragma once

#include <fstream>
#include "CGrapheOperation.h"
using namespace std;


class CFichier
{
	public:
		CGrapheOperation &FICLireFichier(char* pcFileNom);
		int FICLireValeur(char* pcFileNom,int eLigne,char cCaractere);
		int FICLireValeur(char* pcFileNom,int eLigne,char cCaractere1,char cCaractere2);
		char* FICLireAttribut(char* pcFileNom,int eLigne,char cCaractere);
		bool FICDeterminerFichierType(char*str1, char*str2,int eLength);
		int FICTaileDeAttribut(char* str);
};

