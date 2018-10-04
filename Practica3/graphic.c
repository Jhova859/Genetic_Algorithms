#include <math.h>
#include <stdio.h>
#include "dislin.h"
#include "graphic.h"

void graphicResults(float minR[], float maxR[], int ngen){
    /*
    float xray[] = {0,1,2,3,4};
    float y1ray[] = {0.1,0.2,0.3,0.4,0.5};
    float y2ray[] = {0.5,0.4,0.3,0.2,0.1};
    */
    float xray[ngen];
    for(int i=0;i<ngen;i++) xray[i] = i;

    int ic;

    metafl ("cons");
    scrmod ("revers");
    disini ();
    pagera ();
    complx ();
    axspos (450, 1300);
    axslen (1500, 800);

    name   ("Generaciones", "x");
    name   ("Y-axis", "y");

    labdig (4, "y");
    labdig (-1,"x");
    ticks  (1, "x");
    ticks  (20, "y");

    titlin ("Algoritmo Genetico Simple", 1);
    titlin ("con 36 Generaciones", 3);

    ic =   intrgb (0.95,0.95,0.95);
    axsbgd (ic);

    graf   (0.0, 10, 0.0, 1, 0, 0.1, 0, 0.01);
    setrgb (0.7, 0.7, 0.7);
    grid   (1, 1);

    color  ("fore");
    height (50);
    title  ();

    color  ("red");
    curve  (xray, minR, ngen);
    color  ("green");
    curve  (xray, maxR, ngen);
    disfin ();
}