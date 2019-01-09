#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include "exctractionXml.h"
 int exctractionXml(char const * monFichierXml)
 {
    xmlDocPtr docxml;
    xmlNodePtr racine; 
    xmlNodePtr NoeudFils, Entite, Attribut;

    const xmlChar * NoeudFils_T[100];
    const xmlChar * Entite_T[100];
    const xmlChar * Attribut_T[100];
    xmlChar * key;
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
        while (NoeudFils != NULL) 
        {   
            if (NoeudFils->type == XML_ELEMENT_NODE)
            {
                NoeudFils_T[i]= NoeudFils->name;
                printf("NoeudFils %d: %s\n",i, NoeudFils_T[i]);
            }
            
            Entite= NoeudFils->xmlChildrenNode; 
            if (Entite != NULL)
            {
                printf("\tEntite(s) :");
            }
            while (Entite != NULL) 
            {
                if (Entite->type == XML_ELEMENT_NODE)
                { 
            
                    Entite_T[j]= Entite->name; 
                    printf("\t\t%s", Entite_T[j]);
                }
                Attribut= Entite->xmlChildrenNode;
                if (Attribut != NULL)
                {
                    printf(" Attribut(s) :");
                }
                while (Attribut != NULL)
                {
                    if (Attribut->type == XML_ELEMENT_NODE)
                    {
                        Attribut_T[k]=Attribut->name;
                        printf("\t%s", Attribut_T[k]);
                    }
                    k=k+1;
                    Attribut=Attribut->next;
                }
                printf("\n");
                j=j+1;
                Entite = Entite->next;
            }
            printf("\n");
            i=i+1;
            NoeudFils = NoeudFils->next;
        }
        xmlFreeDoc(docxml);
        return 1;
    }
}