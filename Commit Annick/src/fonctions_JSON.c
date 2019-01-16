#include<math.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#include"../headers/JSON_checker.h" //Validation de la syntaxe du fichier JSON 
#include"../headers/cJSON.h" //Parsing et parcours du fichier JSON
#include"../headers/formesSvg.h" //gération d'un fichier SVG (contenant les formes)
#include"../headers/fonctions_JSON.h"


//Fonction permettant de vérifier la validité syntaxique d'un fichier JSON
int validationJson (FILE * fichierJson)
{
    int c;
    JSON_checker jc = new_JSON_checker(30);
    if(fichierJson!=NULL)
    {
        while (1)
        {
            c= fgetc(fichierJson);
            if(feof(fichierJson)) break;

            if (c<= 0) break;
            if (!JSON_checker_char(jc, c)) 
            {
                fprintf(stderr, "JSON_checker_char: ERREUR SYNTAXIQUE \n");
                return 0;
            }
        }

        if (!JSON_checker_done(jc)) 
        {
            fprintf(stderr, "JSON_checker_end: ERREUR SYNTAXIQUE \n");
            return 0;
        }
        
        else { fclose(fichierJson); return 1; }
    }

    else {printf("FICHIER NON OUVERT\n"); return 0;}

}

//Fonction permettant de de récupérer le contenu d'un fichier JSON dans une chaine de caractère
char* stringJson (FILE * fichierJson)
{
    char *contenu;
    if (fichierJson!=NULL)
    {
        contenu = malloc(sizeof(char)*2000); //allocation dynamique d'espace
        char ligne[2000];
        while(getc(fichierJson)!=EOF)
        {
            fscanf(fichierJson,"%s",ligne);//récupération d'une ligne du fichier JSON
            strcat(contenu,ligne); //concaténation de la ligne lu avec la chaine du contenu du fichier
        }
       
    }
    else printf("POINTEUR SUR FICHIER JSON NULL FICHIER\n"); 

     return contenu;
    
}

//Fonction permettant de parser le contenu du fichier récupéré en un pointeur sur objet cJSON 
cJSON* extractionJson (FILE * fichierJson)
{
    char *contenu;
    contenu = malloc(sizeof(char)*2000);
    contenu = stringJson(fichierJson);
    cJSON *ptrJson = cJSON_Parse(contenu);
    return ptrJson;
}

//Fonction  permettant de dessiner le rectangle des entités
void createEntite(svg* fichierSVG, char *entity, int width,int height,int x,int y)
{
    svg_rectangle(fichierSVG,width,height,x,y, "#00FFFF", "#000000", 2, 8, 8);
    svg_line(fichierSVG, "#000000", 2, x, y+80, x+width, y+80);
    svg_text(fichierSVG, x+10, y+40, "#FF0000", 25, "#FF0000", "#000000", entity);
}

void createAttribute(svg* fichierSVG, char* attribut, int width,int height,int x,int y)
{
    svg_text(fichierSVG, x+10, y+110, "#FF0000", 25, "#FF0000", "#000000", attribut);
}



void recuperationAttributs(cJSON* element, svg * fichierSVG, int i)
{
    if (element!=NULL)
    {       
        int k=0;
        while(element!=NULL)    
        {
            if(cJSON_IsObject(element)|| cJSON_IsArray(element)) { recuperationEntite(element, fichierSVG, i); return;}
            else
            {
                k++;

                if(i%2==1) {createAttribute(fichierSVG, element->string, 256, 300, 58, k*40 +58 +  550*((i-1)/2));}
                else {createAttribute(fichierSVG, element->string, 256, 300, 700, k*40 + 58 + 550*((i-1)/2));}

                printf("L'ATTRIBUT k=%d EST %s\n", k, element->string);
                element = element->next;
            }
            
        }   
    }
}

void recuperationEntite(cJSON* element, svg * fichierSVG, int i)
{
    //int i=1;
    while(element!=NULL)
    {
        i++;
        if (cJSON_IsObject(element))
        {
            printf("L'ENTITÉ JSON i=%d EST: %s\n", i, element->string );

            if(i%2==1) {createEntite(fichierSVG, element->string, 256, 300, 58, 58 + 550*((i-1)/2));}
            else {createEntite(fichierSVG, element->string, 256, 300, 700, 58 + 550*((i-1)/2));}

            cJSON * fils=element->child;
            if(fils!=NULL) recuperationAttributs(fils, fichierSVG, i);
            element= element->next;

        }

        else if (cJSON_IsArray(element))

        {
            printf("L'ENTITÉ JSON i=%d EST: %s\n", i, element->string );

            if(i%2==1) {createEntite(fichierSVG, element->string, 256, 300, 58, 58 + 550*((i-1)/2));}
            else {createEntite(fichierSVG, element->string, 256, 300, 700, 58 + 550*((i-1)/2));}

            cJSON * fils=cJSON_GetArrayItem(element, 0)->child;//puisque les autres éléments auronts les mêmes attributs
            if (fils!=NULL) recuperationAttributs(fils, fichierSVG, i);
            element= element->next; 
        }
    }

}