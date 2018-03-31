#pragma once
#include <iostream>

class Cexception
{
   private:
	   int eErreur;

   public:
	   Cexception();
	   Cexception(int arg);
	   
	   int &CEXLireErreur();
	   void CEXOuvreFile(); 
	   void CEXFileType(); 
	   void CEXErreurGeneral(); 
	   void CEXRepeter();
};
