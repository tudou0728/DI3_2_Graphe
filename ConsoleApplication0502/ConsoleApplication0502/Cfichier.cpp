#pragma once
#include "Cfichier.h"

CGrapheOperation& CFichier:: FICLireFichier(char* pcFileNom)
{
		CGrapheOperation *graphe=new CGrapheOperation();
		int eLigne=1;
		if(!this->FICDeterminerFichierType(this->FICLireAttribut(pcFileNom,eLigne,'='),"NBSommets",this->FICTaileDeAttribut("NBSommets")))
		{ 
			Cexception a(2);
		    throw a;
		}
		graphe->GRASetNumero(this->FICLireValeur(pcFileNom,eLigne,'\n'));
		graphe->GRASetsommet(graphe->GRALireNumero());
		eLigne++;//2

		//路线个数
		int eArcsNumero=0;
		if(!this->FICDeterminerFichierType(this->FICLireAttribut(pcFileNom,eLigne,'\n'),"NBArcs",this->FICTaileDeAttribut("NBArcs")))
		{ 
			Cexception a(2);
		    throw a;
		}
		eArcsNumero=this->FICLireValeur(pcFileNom,eLigne,'\n');
		eLigne++;//3

		if(!this->FICDeterminerFichierType(this->FICLireAttribut(pcFileNom,eLigne,'\n'),"Sommets",this->FICTaileDeAttribut("Sommets")))
		{ 
			Cexception a(2);
		    throw a;
		}
		int s=0;
		eLigne++;//4
		char cTemp=*(this->FICLireAttribut(pcFileNom,eLigne,'\n'));
		while((this->FICLireAttribut(pcFileNom,eLigne,'\n'))[0] != ']' && s<graphe->GRALireNumero())
		{			
			if(!this->FICDeterminerFichierType(this->FICLireAttribut(pcFileNom,eLigne,'\n'),"Numero",this->FICTaileDeAttribut("Numero")))
			{ 
				Cexception a(2);
				throw a;
			}
			int eSommetNumero=0;
			eSommetNumero=this->FICLireValeur(pcFileNom,eLigne,'\n');
			(graphe->GRALireSommet(s)).SOMSetSOMNumero(eSommetNumero);
			s++;
			for(int h=0;h<s-1;h++)
			{
				if(graphe->GRALireSommet(h).SOMLireSOMNumero() == eSommetNumero)
				{
					Cexception a(4);
					throw a;
				}
			}
			eLigne++;
		}
		if(s != graphe->GRALireNumero() || (this->FICLireAttribut(pcFileNom,eLigne,'\n'))[0] != ']')
		{
			Cexception a(2);
			throw a;
		}
		//读矩阵
		eLigne++;
		if(!this->FICDeterminerFichierType(this->FICLireAttribut(pcFileNom,eLigne,'\n'),"Arcs",this->FICTaileDeAttribut("Arcs")))
		{ 
			Cexception a(2);
			throw a;
		}
		eLigne++;
		int t=0;
		int eTLigne=0;
		while((this->FICLireAttribut(pcFileNom,eLigne,'\n'))[0] != ']')
		{
			int eDebut=0;
			eDebut=this->FICLireValeur(pcFileNom,eLigne,'\n');
			int eFin=0;
			eFin=this->FICLireValeur(pcFileNom,eLigne,',','\n');
			int z=0;
			for(z=0;z<graphe->GRALireNumero();z++)
			{
				if(eDebut == graphe->GRALireSommet(z).SOMLireSOMNumero())
				{
					z=graphe->GRALireNumero()+1;
				}
			}
			if(z == graphe->GRALireNumero())
			{
				Cexception a(3);
				throw a;
			}
			for(z=0;z<graphe->GRALireNumero();z++)
			{
				if(eFin == graphe->GRALireSommet(z).SOMLireSOMNumero())
				{
					z=graphe->GRALireNumero()+1;
				}
			}
			if(z == graphe->GRALireNumero())
			{
				Cexception a(3);
				throw a;
			}
			CArc debut=CArc(eDebut);
			CArc fin=CArc(eFin);
			int x=0;
			while((graphe->GRALireSommet(x)).SOMLireSOMNumero() != eDebut)
			{
				x++;
			}
			(graphe->GRALireSommet(x)).SOMAjouterAFinArrivant(fin);
			int y=0;
			while((graphe->GRALireSommet(y)).SOMLireSOMNumero() != eFin)
			{
				y++;
			}
			(graphe->GRALireSommet(y)).SOMAjouterAFinPartant(debut);
			eLigne++;
			eTLigne++;
		}
		if(eTLigne != eArcsNumero)
		{
			Cexception a(2);
			throw a;
		}
		return *(graphe);
}

bool CFichier::FICDeterminerFichierType(char*str1, char*str2,int eLength)
{
	if(str1==NULL||str2==NULL)
	 {
		 cout<<"ne peut pas utiliser cette function"<<"\n";
	 }
	 else
	 {
		int i=0;
		while(str1[i]!='\0' && str2[i]!='\0' &&  i<=eLength-1)
        {
            if(str1[i] != str2[i])
			{
				return false;
				break;
			}
			i++;
        }
		return true;
	 }
}
		
int CFichier::FICTaileDeAttribut(char* str)
{
	int eCount=0;
	int i=0;
	while(str[i] != '\0')
	{
		eCount++;
		i++;
	}
	return eCount;
}


int CFichier::FICLireValeur(char* pcFileNom,int eLigne,char cCaractere)
{
	fstream file(pcFileNom,ios::in|ios::out);
	if (!file.is_open())
	{ 
		Cexception a(1);
		throw a;
	} 
	else
	{
		char cTemp[100]={'a'};
		for(int i=0;i<eLigne;i++)
		{
			file.getline(cTemp,90,cCaractere);
		}
		char str[100]={'a'};
		int p=0;
		while(cTemp[p] != '=')
		{
			p++;
		}
		p++;
		int q=0;
		while(int(cTemp[p]-48)>=0 && int(cTemp[p]-48)<=9)
		{
			str[q]=cTemp[p];
			q++;
			p++;
		}
		str[q+1]='\0';
		int eCount=0;
		for(int i=0;str[i]!= '\0';i++)
		{
			eCount++;
		}
		int eValeur=0;
		for(int j=0;j<eCount;j++)
		{
			eValeur=eValeur+(int(str[j])-48)*pow(10,eCount-1-j);
		}
		file.close();
		return eValeur;
	}
}

char* CFichier::FICLireAttribut(char* pcFileNom,int eLigne,char cCaractere)
{
	fstream file(pcFileNom,ios::in|ios::out);
	if (!file.is_open())
	{ 
		Cexception a(1);
		throw a;
	} 
	else
	{
		char cTemp[100]={'a'};
		file.seekg(0,ios::beg);
		for(int i=0;i<eLigne;i++)
		{
			file.getline(cTemp,90,cCaractere);
		}
		file.close();
		return cTemp;
	}
}

int CFichier::FICLireValeur(char* pcFileNom,int eLigne,char cCaractere1,char cCaractere2)//有问题没写完
{
	fstream file(pcFileNom,ios::in|ios::out);
	if (!file.is_open())
	{ 
		Cexception a(1);
		throw a;
	} 
	else
	{
		char cTemp[100]={'a'};
		for(int i=0;i<eLigne;i++)
		{
			file.getline(cTemp,90,cCaractere2);
		}
		char str[100]={'a'};
		int p=0;
		while(cTemp[p] != cCaractere1)
		{
			p++;
		}
		p++;
		int q=0;
		while(cTemp[p] != '\0')
		{
			cTemp[q]=cTemp[p];
			q++;
			p++;
		}
		int s=0;
		int l=0;
		while(l<q)
		{
			if(int(cTemp[l]-48)>=0 && int(cTemp[l]-48)<=9 )
			{
				str[s]=cTemp[l];
				s++;
				l++;
			}
			else
			{
				l++;
			}
		}
		str[s+1]='\0';
		int eCount=0;
		for(int i=0;str[i]!= '\0';i++)
		{
			eCount++;
		}
		int eValeur=0;
		for(int j=0;j<eCount;j++)
		{
			eValeur=eValeur+(int(str[j])-48)*pow(10,eCount-1-j);
		}
		file.close();
		return eValeur;
	}
}