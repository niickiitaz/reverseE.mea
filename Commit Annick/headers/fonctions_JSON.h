#ifndef _FONCTION_JSON_H_
#define _FONCTION_JSON_H_

int validationJson (FILE * fichierJson);
char* stringJson (FILE * fichierJson);
cJSON* extractionJson (FILE * fichierJson);
void createAttribute(svg* psvg, char* attribut, int width,int height,int x,int y);
void createEntite(svg* psvg, char *entity, int width,int height,int x,int y);
void recuperationAttributs(cJSON* element, svg * fichierSVG, int i);
void recuperationEntite(cJSON* element, svg * fichierSVG, int i);

#endif