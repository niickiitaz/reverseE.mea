#include<stdio.h>
#include<string.h>
#include"testValiditeCommande.h"
int testValiditeCommande(int argc, char const *argv[])
{
	if(strcmp(argv[1],"-i")==0)
	{
		if((strcmp(argv[2],"xml")==0) || (strcmp(argv[2],"json")==0))
		{
			if (strcmp(argv[3],"-t")==0)
			{
				if (argc ==8)
				{
			 		if((strcmp(argv[4],"-h")==0) || (strcmp(argv[4],"-f")==0))
			 		{
			 			int n= strlen(argv[5]);
			 			if(((strcmp(argv[2],"xml")==0) && ((argv[5][n-4])=='.' && (argv[5][n-3])=='x' && (argv[5][n-2])=='m' && (argv[5][n-1])=='l')) || ((strcmp(argv[2],"json")==0) && ((argv[5][n-5])=='.' && (argv[5][n-4])=='j' && (argv[5][n-3])=='s' && (argv[5][n-2])=='o' && (argv[5][n-1])=='n')))
			 			{
			 				if (strcmp(argv[6],"-o")==0)
			 				{
								int x = strlen (argv[7]);
								if((argv[7][x-4]=='.') && (argv[7][x-3]=='s' && argv[7][x-2]=='v' && argv[7][x-1]=='g'))
			 						return 1;				
			 					else
			 					{
			 						printf("Le fichier de sortie n'est pas au bon format\n");
			 						return 0;
			 					}
			 				}
			 				else
			 				{
			 					printf("Saisir l'option -o\n");
			 					return 0;
			 				}
			 			}
			 			else
			 			{
			 				printf("L'input n'est pas au bon format\n");
			 				return 0;
			 			}
			 		}
			 		else
			 		{
			 			printf("Veuiller specifier le mode d'importation soit -f ou -h\n");
			 			return 0;
			 		}
			 	}
			 	else
			 		printf("Nombre d'arguments saisis incorrect: avec l'option -t le nombre d'arguments doit etre egal a 8\n");
			 }
		 	else
		 	{
		 		if (argc==7)
			 	{
					if((strcmp(argv[3],"-h")==0) || (strcmp(argv[3],"-f")==0))
			 		{
			 			int k= strlen(argv[4]);
			 			if(((strcmp(argv[2],"xml")==0) && ((argv[4][k-4])=='.' && (argv[4][k-3])=='x' && (argv[4][k-2])=='m' && (argv[4][k-1])=='l')) || ((strcmp(argv[2],"json")==0) && ((argv[4][k-5])=='.' && (argv[4][k-4])=='j' && (argv[4][k-3])=='s' && (argv[4][k-2])=='o' && (argv[4][k-1])=='n')))
			 			{
			 				if (strcmp(argv[5],"-o")==0)
			 				{
								int z = strlen (argv[6]);
								if((argv[6][z-4]=='.') && (argv[6][z-3]=='s' && argv[6][z-2]=='v' && argv[6][z-1]=='g'))
			 						return 1;
			 					else
			 					{
			 						printf("Le fichier de sortie n'est pas au bon format\n");
			 						return 0;
			 					}
			 				}
			 				else
			 				{
			 					printf("Saisir l'option -o\n");
			 					return 0;
			 				}
			 			}
			 			else
			 			{
			 				printf("L'input n'est pas au bon format\n");
			 				return 0;
			 			}
			 		}
					else
					{
			 			printf("Veuiller specifier le mode d'importation soit -f ou -h\n");
			 			return 0;
					}
			 	}
			 	else
			 		printf("Nombre d'arguments saisis incorrect: sans l'option -t le nombre d'arguments doit etre egal a 7\n");
			 }
		}
		 else
		{
		 	printf("L'input doit etre soit xml soit json\n");
		 	return 0;
		}
	}
	else
		printf("Veuiller saisir l'option -i\n");
}