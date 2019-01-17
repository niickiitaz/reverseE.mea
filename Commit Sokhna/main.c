#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include "testValiditeCommande.h"
#include "validationFichierXml.h"
#include "conversionSvg.h"

int main (int argc, char const *argv[], char const * monFichierXml, svg* psvg,int width, int height)
{
	char const *Fichier;
	if (argc==7)
		Fichier = argv[4];
	if (argc==8)
		Fichier = argv[5];
	svg* FichierSvg;
	FichierSvg = svg_create (2500,1300);
	{
		if(testValiditeCommande(argc,argv)==1)
			validationFichierXml (Fichier);
		else
			return 0;
	}

	{
		if(validationFichierXml (Fichier)==1)
			exctractionXml(Fichier, FichierSvg, 2500, 1300);

		else
		{	
			printf("Veuiiler verifier votre Input\n");
			return 0;
		}
	}
	svg_finalize(FichierSvg); //pour ordonner et mettre en memoire
	svg_save(FichierSvg,"FichierSvg.svg"); //pour creer
	svg_free(FichierSvg); //pour lbere lespace memoire
	
}