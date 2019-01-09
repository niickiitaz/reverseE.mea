#include<stdio.h>
#include<string.h>
#include"testValiditeCommande.h"
#include"validationFichierXml.h"
#include <libxml/parser.h>
#include"exctractionXml.h"

int main (int argc, char const *argv[])
{
	char const *Fichier;
	if (argc==7)
		Fichier = argv[4];
	if (argc==8)
		Fichier = argv[5];
	{
		if(testValiditeCommande(argc,argv)==1)
			validationFichierXml (Fichier);
		else
			return 0;
	}

	{
		if(validationFichierXml (Fichier)==1)
			exctractionXml(Fichier);
		else
		{	
			printf("Veuiiler verifier votre Input\n");
			return 0;
		}
	}

}