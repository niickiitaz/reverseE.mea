#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h> 


 // --------------------------------------------------------
// STRUCT svg
// --------------------------------------------------------
typedef struct svg
{
    char* svg;
    int height;
    int width;
    bool finalized;
} svg; 

// --------------------------------------------------------
// FUNCTION PROTOTYPES
// --------------------------------------------------------
svg* svg_create(int width, int height); //longueur et largeur de la page svg
void svg_finalize(svg* psvg); //pour ordonner et mettre en memoire
void svg_print(svg* psvg); //pour afficher le fichier svg
void svg_save(svg* psvg, char const * filepath); //pour creer
void svg_free(svg* psvg); //pour lbere lespace memoire
void svg_circle(svg* psvg, char const * stroke, int strokewidth, char const * fill, int r, int cx, int cy);
void svg_line(svg* psvg, char const * stroke, int strokewidth, int x1, int y1, int x2, int y2);
void svg_rectangle(svg* psvg, int width, int height, int x, int y, char const * fill, char const * stroke, int strokewidth, int radiusx, int radiusy);
void svg_fill(svg* psvg, char const * fill); //pour remplir(colorer) le fichier svg
void svg_text(svg* psvg, int x, int y, char const * fontfamily, int fontsize, char const * fill, char const * stroke, char const * text); //pour remplir (editer) le fichier svg
void svg_ellipse(svg* psvg, int cx, int cy, int rx, int ry, char const * fill, char const * stroke, int strokewidth); 

void createEntite(svg* psvg, char const *entity, int width,int height,int x,int y);

void createAttribute(svg* psvg, char const * attribut, int width,int height,int x,int y);

int exctractionXml(char const * monFichierXml, svg* psvg,int width, int height);