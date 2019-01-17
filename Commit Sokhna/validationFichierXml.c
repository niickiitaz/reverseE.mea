#include <stdio.h>
#include <libxml/parser.h>
#include"validationFichierXml.h"
int validationFichierXml (char const * monFichierXml)
{
	xmlDocPtr docxml;
	docxml = xmlParseFile(monFichierXml);
	if(docxml==NULL)
	{
		printf("Le fichier xml est invalide\n");
		return 0;
	}
	xmlFreeDoc(docxml);
	return 1;
}
