#pragma once
#include"Cexception.h"

using namespace std;

Cexception::Cexception()
{
	eErreur=0;
}

Cexception::Cexception(int arg)
{
	eErreur=arg;
}

int &Cexception::CEXLireErreur()
{
	return eErreur;
}

void Cexception:: CEXOuvreFile()
{
	cout<<"Erreur:Ne peut pas ouvrir:le chemin de fichier n'est pas correct"<<"\n";
}

void Cexception::CEXFileType()
{
	cout<<"Erreur:Le contenu de fichier est incorrect,verifiez votre fichier,SVP"<<"\n";
}

void Cexception::CEXErreurGeneral()
{
	cout<<"Erreur:Ne trouve pas le sommet"<<"\n";
}

void Cexception::CEXRepeter()
{
	cout<<"Erreur:D¨¦ja existe"<<"\n";
}