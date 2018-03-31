#include "CGrapheOperation.h"

void CGrapheOperation::GRAAjouterSommet(CSommetOperation &sommet,int ePos)
{
	int j=0;
	while(j<this->eGRANumero)
	{
		if(this->pGRAsommet[j]->SOMLireSOMNumero() == sommet.SOMLireSOMNumero())
		{
			Cexception a(4);//�Ѿ�������
			throw a;
		}
		j++;
	}
	pGRAsommet=(CSommetOperation**)realloc(pGRAsommet,sizeof(CSommetOperation*)*(eGRANumero+1));
	pGRAsommet[eGRANumero]=new CSommetOperation();
	for(int i=eGRANumero;i>ePos;i--)
	{
		pGRAsommet[i]=pGRAsommet[i-1];
	}
	delete pGRAsommet[ePos];
	pGRAsommet[ePos]=new CSommetOperation(sommet);
	this->eGRANumero=this->eGRANumero+1;
}


void CGrapheOperation::GRAModifierSommet(CSommetOperation &sommet,int ePos)
{
	delete pGRAsommet[ePos];
	pGRAsommet[ePos]=&(sommet);
}

void CGrapheOperation::GRAModifierSommetNumero(int eSommet,int eMSommet)
{
	int i=0;
	while(i<this->eGRANumero)
	{
		if(this->pGRAsommet[i]->SOMLireSOMNumero() == eMSommet)
		{
			Cexception a(4);//�Ѿ�����
			throw a;
		}
		if(this->pGRAsommet[i]->SOMLireSOMNumero() == eSommet)
		{
			this->pGRAsommet[i]->SOMSetSOMNumero(eMSommet);
			break;
		}
		i++;
	}
	if(i == this->eGRANumero)
	{
		Cexception a(3);//û�ҵ�
		throw a;
	}
	int m=0;
	while(m<this->eGRANumero)
	{
		int n=0;
		while(n<this->pGRAsommet[m]->SOMLireSOMArrivantNum())
		{
			if(this->pGRAsommet[m]->SOMLireArrivantElement(n).ARCLireElement() ==eSommet)
			{
				this->pGRAsommet[m]->SOMLireArrivantElement(n).ARCSetElement(eMSommet);
			}
			n++;
		}
		int q=0;
		while(q<this->pGRAsommet[m]->SOMLireSOMPartantNum())
		{
			if(this->pGRAsommet[m]->SOMLirePartantElement(q).ARCLireElement() ==eSommet)
			{
				this->pGRAsommet[m]->SOMLirePartantElement(q).ARCSetElement(eMSommet);
			}
			q++;
		}
		m++;
	}
}

void CGrapheOperation::GRASupprimerSommet(int eElement)
{
	int q=0;
	while(q<this->eGRANumero)
	{
		if(this->pGRAsommet[q]->SOMLireSOMNumero() == eElement)
		{
			break;
		}
		q++;
	}
	if(q>=this->eGRANumero)
	{
		Cexception a(3);//û�ҵ�
		throw a;
	}
	int m=0;
	while(m<this->eGRANumero)
	{
		for(int n=0;n<this->pGRAsommet[m]->SOMLireSOMArrivantNum();n++)
		{
			if(this->pGRAsommet[m]->SOMLireArrivantElement(n).ARCLireElement() ==eElement)
			{
				this->pGRAsommet[m]->SOMSupprimerArrivant(n);
			}
		}
		for(int n=0;n<this->pGRAsommet[m]->SOMLireSOMPartantNum();n++)
		{
			if(this->pGRAsommet[m]->SOMLirePartantElement(n).ARCLireElement() ==eElement)
			{
				this->pGRAsommet[m]->SOMSupprimerPartant(n);
			}
		}
		m++;
	}

	int ePos=0;
	while(ePos<this->eGRANumero)
	{
		if(this->pGRAsommet[ePos]->SOMLireSOMNumero() == eElement)
		{
			break;
		}
		ePos++;
	}
	for(int i=ePos;i<eGRANumero;i++)
	{
		pGRAsommet[i]=pGRAsommet[i+1];
	}
	pGRAsommet=(CSommetOperation**)realloc(pGRAsommet,sizeof(CSommetOperation*)*(eGRANumero-1));
	eGRANumero--;
}


void CGrapheOperation::GRASupprimerArc(int ePart,int eArri)
{
	int ePartPos=0;
	int eArriPos=0;
	while(this->pGRAsommet[ePartPos]->SOMLireSOMNumero() != ePart)
	{
		ePartPos++;
	}
	if(ePartPos >= this->eGRANumero)
	{
		Cexception a(3);//û�ҵ�
		throw a;
	}
	while(this->pGRAsommet[eArriPos]->SOMLireSOMNumero() != eArri)
	{
		eArriPos++;
	}
	if(eArriPos >= this->eGRANumero)
	{
		Cexception a(3);//û�ҵ�
		throw a;
	}
	this->GRALireSommet(ePartPos).SOMSupprimerElementArrivant(eArri);
	this->GRALireSommet(eArriPos).SOMSupprimerElementPartant(ePart);	
}

void CGrapheOperation::GRAModifierArc(int ePart,int eArri,int eMArri)
{
	int m=0;
	int eMArriverPos=0;
	while(m<this->eGRANumero)
	{
		if(this->pGRAsommet[m]->SOMLireSOMNumero() == eMArri)
		{
			eMArriverPos=m;
			m=this->eGRANumero+1;
		}
		m++;
	}
	if(m == this->eGRANumero)
	{
		Cexception a(3);//û�ҵ�
		throw a;
	}
	int i=0;
	while(i<this->eGRANumero)
	{
		if(this->pGRAsommet[i]->SOMLireSOMNumero() == ePart)//�����
		{
			int j=0;
			while(j<this->pGRAsommet[i]->SOMLireSOMArrivantNum())
			{
				if(this->pGRAsommet[i]->SOMLireArrivantElement(j).ARCLireElement() == eArri)//���յ�
				{
					this->pGRAsommet[i]->SOMLireArrivantElement(j).ARCSetElement(eMArri);//���յ�
					break;
				}
				j++;
			}
			break;
		}
		i++;
	}
	if(i==this->eGRANumero)
	{
		Cexception a(3);//û�ҵ����
		throw a;
	}
	CArc arc=CArc(ePart);
	this->pGRAsommet[eMArriverPos]->SOMAjouterAFinPartant(arc);//�����
	int eArriverPos=0;
	while(eArriverPos<this->eGRANumero)
	{
		if(this->pGRAsommet[eArriverPos]->SOMLireSOMNumero() == eArri)//ɾ���
		{
			this->pGRAsommet[eArriverPos]->SOMSupprimerElementPartant(ePart);
			break;
		}
		eArriverPos++;
	}
	if(eArriverPos==this->eGRANumero)
	{
		Cexception a(3);//û�ҵ�
		throw a;
	}
}

void CGrapheOperation::GRAAjouterArc(int ePart,int eArri)
{
	int j=0;
	CArc partArc=CArc();
	CArc arriArc=CArc();
	CSommetOperation psommet=CSommetOperation();
	CSommetOperation asommet=CSommetOperation();
	partArc.ARCSetElement(ePart);
	arriArc.ARCSetElement(eArri);
	while(j<this->eGRANumero)
	{
		if(ePart == this->pGRAsommet[j]->SOMLireSOMNumero())//�����
		{			
			int c=0;
			while(c<this->eGRANumero)
			{
				if( this->pGRAsommet[c]->SOMLireSOMNumero()== eArri)//���յ� ����ҵ���
				{					
					this->pGRAsommet[c]->SOMAjouterAFinPartant(partArc);///�յ�����
					this->pGRAsommet[j]->SOMAjouterAFinArrivant(arriArc);//�����յ�
					c=this->eGRANumero+1;//����ѭ��
					j=this->eGRANumero+1;//����ѭ��
				}
				c++;
			}
			if(c == this->eGRANumero)//û�ҵ��յ�
			{
				this->pGRAsommet[j]->SOMAjouterAFinArrivant(arriArc);//�����յ�
				asommet.SOMSetSOMNumero(eArri);
				asommet.SOMAjouterAFinPartant(partArc);
				this->GRAAjouterSommet(asommet,this->eGRANumero);//������һ��sommet
				j=this->eGRANumero+1;
			}
		}
		j++;
	}
    if(j == this->eGRANumero)//û�ҵ����
	{
		int d=0;
		while(d<this->eGRANumero)
		{
			if(eArri == this->pGRAsommet[d]->SOMLireSOMNumero())//�ҵ��յ�
			{
				this->pGRAsommet[d]->SOMAjouterAFinPartant(partArc);
				psommet.SOMSetSOMNumero(ePart);
				psommet.SOMAjouterAFinArrivant(arriArc);
				this->GRAAjouterSommet(psommet,this->eGRANumero);
				d=this->eGRANumero+1;
			}
			d++;
		}
		if(d == this->eGRANumero)//û�ҵ��յ�
		{
			psommet.SOMSetSOMNumero(ePart);
			psommet.SOMAjouterAFinArrivant(arriArc);
			asommet.SOMSetSOMNumero(eArri);
			asommet.SOMAjouterAFinPartant(partArc);
			this->GRAAjouterSommet(psommet,this->eGRANumero);
			this->GRAAjouterSommet(asommet,this->eGRANumero);
		}
	}
}