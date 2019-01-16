#include<math.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#include"../headers/JSON_checker.h" //Validation de la syntaxe du fichier JSON 
#include"../headers/cJSON.h" //Parsing et parcours du fichier JSON
#include"../headers/formesSvg.h" //gération d'un fichier SVG (contenant les formes)
#include"../headers/fonctions_JSON.h" //CRéation et génération du fichier SVG

 int main(int argc, char const *argv[])
 {

 	FILE * fichierJson=fopen(argv[1], "r");
 	if(fichierJson!=NULL)
 	{
 		//printf("RETOUR DE LA FONCTION validationJson: %d\n", validationJson(fichierJson));
 		if(validationJson(fichierJson)==1)
	 	{
	 		fichierJson=fopen(argv[1], "r");

	 		//Création du pointeur cJSON et récupération des entités et attributs
			cJSON *ptrJson = extractionJson(fichierJson);
			if (ptrJson!=NULL)
			{
				//Création du fichier svg
				svg* fichierSVG;
		    	fichierSVG = svg_create(1012, 1512);
		    	if(fichierSVG == NULL) puts("LE FICHIER SVG N'A PAS ÉTÉ CRÉÉ.\n");
			    else svg_rectangle(fichierSVG, 1012, 1512, 0, 0, "white", "white", 0, 0, 0);

			    int i=0;
				recuperationEntite(ptrJson->child, fichierSVG, i);
				printf("FIN\n");

				//Fin et enregistrement du fichier généré
				svg_finalize(fichierSVG);
				svg_save(fichierSVG, "SchemaSVG.svg");
				svg_free(fichierSVG);
			}
			else printf("Le pointeur cJSON est null\n");
 		}

 		fclose(fichierJson);
 	}
 	else printf("ERREUR D'OUVERTURE DU FICHIER\n\n");
 	return 0;
 	
 }