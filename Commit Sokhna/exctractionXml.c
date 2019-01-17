#include <stdio.h>
#include<string.h>
#include <libxml/parser.h>
#include "conversionSvg.h"
int exctractionXml(char const * monFichierXml, svg* psvg,int width, int height)
{
    xmlDocPtr docxml;
    xmlNodePtr racine,NoeudFils, Entites, Attribut;

    const xmlChar * NoeudFils_T[100];
    const xmlChar * Entites_T[100];
    const xmlChar * Attribut_T[100];
  
    int i,j,k;
    i=0;
    j=0;
    k=0;

    docxml = xmlParseFile(monFichierXml);
    if (docxml == NULL) 
    {
        printf("Le document XML invalide\n");
        return 0;
    }
    else
    {
        printf("Le document XML valide\n");
        racine = xmlDocGetRootElement(docxml); 
        if (racine == NULL) 
        {
            printf("Le document XML vierge\n");
            xmlFreeDoc(docxml);
            return 0;
        }
        printf("La racine du document est : %s\n", racine->name);

        NoeudFils = racine->xmlChildrenNode; 
        while (NoeudFils != NULL ) 
        {   
            if (NoeudFils->type == XML_ELEMENT_NODE && (strcmp(NoeudFils->name,"Entites")==0))
            {
                NoeudFils_T[i]= NoeudFils->name;
                printf("%s:\n", NoeudFils_T[i]);
            }
            
            Entites= NoeudFils->xmlChildrenNode; 
            while (Entites != NULL) 
            {
                if (Entites->type == XML_ELEMENT_NODE)
                { 
            
                    Entites_T[j]= Entites->name; 
                    printf("\t%s ", Entites_T[j]);
                }
                Attribut= Entites->xmlChildrenNode;
                if (Attribut != NULL)
                {
                    printf(":");
                }
                while (Attribut != NULL)
                {
                    if (Attribut->type == XML_ELEMENT_NODE)
                    {
                        Attribut_T[k]=Attribut->name;
                        printf("\t%s", Attribut_T[k]);
                        createEntite(psvg,Entites_T[j],300,400,(400*j),(200+500*(k%2)));
                        if (j%2==1)
                        {
                            createAttribute(psvg, Attribut_T[k], 290,1000,(400*j),(1000+20*k));
                        }
                        if (j==2)
                        {
                            createAttribute(psvg, Attribut_T[k], 290,1000,(400*j),(20*k));
                        }
                        /*if (j==3)
                        {
                            createAttribute(psvg, Attribut_T[k], 290,1000,(400*j),(1000+20*k));
                        }*/
                    }
                    k=k+1;
                    Attribut=Attribut->next;
                }
                printf("\n");
                j=j+1;
                Entites = Entites->next;
            }
            printf("\n");
            NoeudFils = NoeudFils->next;
        }
        xmlFreeDoc(docxml);
        return 1;
    }
}