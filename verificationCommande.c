#include <stdio.h>
#include <string.h>
#include "../headers/verificationCommande.h"
//Fonction pour vérifier si les paramètre des arguments sont valides
int verifierOptions(int taille, char const *argument[])
{
	if (taille==7)
	{
		if (strcmp(argument[1],"-i")!=0) 
		{
			printf("VOUS AVEZ OUBLIEZ D'INCLURE L'OPTION -i.\n\n");
			return 0;
		}

		else if (strcmp(argument[3],"-f")!=0 && strcmp(argument[3],"-h")!=0)
		{
			printf("VOUS AVEZ OUBLIEZ D'INCLURE L'OPTION -h ou -f.\n\n");
			return 0;

		}

		else if (strcmp(argument[5],"-o")!=0)
		{
			printf("VOUS AVEZ OUBLIEZ D'INCLURE L'OPTION -o.\n\n");
			return 0;
		}

		else return 1;
	}
	
	else if (taille==8)
	{
		if (strcmp(argument[1],"-i")!=0) 
		{
			printf("VOUS AVEZ OUBLIEZ  D'INCLURE L'OPTION -i.\n\n");
			return 0;
		}

		if (strcmp(argument[3],"-t")!=0) 
		{
			printf("VOUS AVEZ OUBLIEZ  D'INCLURE L'OPTION -t.\n\n");
			return 0;
		}


		else if (strcmp(argument[5],"-f")!=0 && strcmp(argument[5],"-h")!=0)
		{
			printf("VOUS AVEZ OUBLIEZ  D'INCLURE L'OPTION -h ou -f.\n\n");
			return 0;

		}

		else if (strcmp(argument[7],"-o")!=0)
		{
			printf("VOUS AVEZ OUBLIEZ  D'INCLURE L'OPTION -o.\n\n");
			return 0;
		}

		else return 1;

	}

	else {printf("ERREUR SYNTAXE: nombre d'arguments incomplets ou en surplus ou \n"); return 0;}
}

//Fonction vérifiant les types de fichier d'entrée et de sortie
int verifierType(int taille, char const  *argument[])
{
	int tailleNomEntre;
	int tailleNomSortie;
	if (taille==7)
	{
		tailleNomEntre= strlen(argument[4])-1; //pour avoir l'indice maximal du nom du fichier d'entrée
		tailleNomSortie= strlen(argument[6])-1; //pour avoir l'indice max du nom du fichier de sortie
		if (strcmp(argument[2], "xml")!=0 && strcmp(argument[2], "json")!=0) 
		{
			printf("L'OPTION -i EST SUIVI DE xml OU json.\n \n");
			return 0;	
		}

		else if (strcmp(argument[2], "xml")==0 && argument[4][tailleNomEntre-3]=='.')
		{
			if (argument[4][tailleNomEntre-2]!='x' || argument[4][tailleNomEntre-1]!='m' || argument[4][tailleNomEntre]!='l') 
			{
				printf("LE FICHIER D'ENTRÉE DOIT ÊTRE DE TYPE xml\n\n");
				return 0;
			}
		}
		
		else if (strcmp(argument[2], "xml")==0 && argument[4][tailleNomEntre-3]!='.')
		{
			printf("FICHIER D'ENTRÉE SANS EXTENSION OU EXTENSION NON CORRECTE. L'EXTENSION DOIT ÊTRE DE TYPE xml.\n\n");
			return 0;
		} 
		
		else if (strcmp(argument[2], "json")==0 && argument[4][tailleNomEntre-4]=='.')
		{	
			if (argument[4][tailleNomEntre-3]!='j' || argument[4][tailleNomEntre-2]!='s' || argument[4][tailleNomEntre-1]!='o' || argument[4][tailleNomEntre]!='n') 
			{
				printf("LE FICHIER D'ENTRÉE DOIT ÊTRE DE TYPE json\n\n");
				return 0;
			}	
		}

		else if (strcmp(argument[2], "json")==0 && argument[4][tailleNomEntre-4]!='.')
		{ 
			printf("FICHIER D'ENTRÉE SANS EXTENSION OU EXTENSION NON CORRECTE. L'EXTENSION DOIT ÊTRE DE TYPE json.\n\n");
			return 0;
		} 

		else if  (argument[6][tailleNomSortie-3]=='.')
		{
			if (argument[6][tailleNomSortie-2]!='s' || argument[6][tailleNomSortie-1]!='v' || argument[6][tailleNomSortie]!='g')
			{
					printf("LE FICHIER DE SORTIE DOIT ÊTRE DE TYPE svg\n\n");
					return 0;
			}
			
		else if (argument[6][tailleNomSortie-3]!='.')
			{
				printf("FICHIER DE SORTIE SANS EXTENSION OU EXTENSION NON CORRECTE. L'EXTENSION DOIT ÊTRE DE TYPE svg.\n\n");
				return 0;
			} 
		}

		else return 1;
	}

	else if (taille==8)
	{
		tailleNomEntre= strlen(argument[5])-1; //pour avoir l'indice maximal du nom du fichier d'entrée
		tailleNomSortie= strlen(argument[7])-1; //pour avoir l'indice max du nom du fichier de sortie
		if (strcmp(argument[2], "xml")!=0 && strcmp(argument[2], "json")!=0) 
		{
			printf("L'OPTION -i EST SUIVI DE xml OU json.\n \n");
			return 0;	
		}

		else if (strcmp(argument[2], "xml")==0 && argument[5][tailleNomEntre-3]=='.')
		{
			if (argument[5][tailleNomEntre-2]!='x' || argument[5][tailleNomEntre-1]!='m' || argument[5][tailleNomEntre]!='l') 
			{
				printf("LE FICHIER D'ENTRÉE DOIT ÊTRE DE TYPE xml\n\n");
				return 0;
			}
		}
		
		else if (strcmp(argument[2], "xml")==0 && argument[5][tailleNomEntre-3]!='.')
		{
			printf("FICHIER D'ENTRÉE SANS EXTENSION OU EXTENSION NON CORRECTE. L'EXTENSION DOIT ÊTRE DE TYPE xml.\n\n");
			return 0;
		} 
		
		else if (strcmp(argument[2], "json")==0 && argument[5][tailleNomEntre-4]=='.')
		{	
			if (argument[5][tailleNomEntre-3]!='j' || argument[5][tailleNomEntre-2]!='s' || argument[5][tailleNomEntre-1]!='o' || argument[5][tailleNomEntre]!='n') 
			{
				printf("LE FICHIER D'ENTRÉE DOIT ÊTRE DE TYPE json\n\n");
				return 0;
			}	
		}

		else if (strcmp(argument[2], "json")==0 && argument[5][tailleNomEntre-4]!='.')
		{ 
			printf("FICHIER D'ENTRÉE SANS EXTENSION OU EXTENSION NON CORRECTE. L'EXTENSION DOIT ÊTRE DE TYPE json.\n\n");
			return 0;
		} 

		else if  (argument[7][tailleNomSortie-3]=='.')
		{
			if (argument[7][tailleNomSortie-2]!='s' || argument[7][tailleNomSortie-1]!='v' || argument[7][tailleNomSortie]!='g')
			{
					printf("LE FICHIER DE SORTIE DOIT ÊTRE DE TYPE svg\n\n");
					return 0;
			}
			
		else if (argument[7][tailleNomSortie-3]!='.')
			{
				printf("FICHIER DE SORTIE SANS EXTENSION OU EXTENSION NON CORRECTE. L'EXTENSION DOIT ÊTRE DE TYPE svg.\n\n");
				return 0;
			} 
		}

		else return 1;

	}

	else {printf("ERREUR DE SYNTAXE: nombre d'arguments incomplets ou en surplus\n\n"); return 0;}
}
