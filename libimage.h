#ifndef LIBIMAGE_H
#define LIBIMAGE_H

// ************************************************
// Définition des types

// Le type PixelRGB pour représenter les niveaux de (rouge, vert, bleu)
// Chaque quantité de couleur est comprise entre 0 et 255
// ce qui correspond au type unsigned char (un entier non signé sur un octet)
typedef struct pixelrgb {
    unsigned char r;
    unsigned char v;
    unsigned char b;
} PixelRGB;

// Le type ImP3 pour stocker une image de type P3 dans un tableau de pixels
typedef struct image3 {
    int hauteur;        // Hauteur en pixels
    int largeur;        // Largeur en pixels
    int maxval;         // Valeur maximal d'un pixel
    PixelRGB** tpix;       // Le tableau des pixels
} ImP3;


// Le type ImP2 pour stocker une image de type P2 dans un tableau rectangulaires d'octets 
// niveau de gris entre 0 net 255

typedef struct image2 {
    int hauteur;        // Hauteur en pixels
    int largeur;        // Largeur en pixels
    int maxval;         // Valeur maximal d'un pixel
    unsigned char** tpix;       // Le tableau des pixels gris
} ImP2;

// initImP3 : int x int x int -> ImP3
// Entrée : 3 entiers, hauteur , largeur et la valeur max de l'image (intensité de couleur)
// Sortie : une structure ImP3 initialisé avec les valeurs passee et le malloc de tpix déjà fait
extern ImP3 initImP3(int haut, int larg, int vmax);

// copieImP3 : ImP3 -> ImP3
// Entrée : une ImP3 a copié
// Sortie : une copie de la structure ImP3 entrée en paramètre
extern ImP3 copieImP3(ImP3 im);

// chargeImP3 : char* -> ImP3
// Entrée : un pointeur sur le nom du fichier à charger
// Sortie : une structure ImP3 avec les valeurs dictée par le fichier.
extern ImP3 chargeImP3(char* fichier);


// sauveImP3 : char* x ImP3 -> ImP3
// Entrée : le nom du fichier a copier et une image
// Sortie : Rien
//Crée un fichier image .ppm
extern void sauveImP3(char* nom, ImP3 im);

// initImP2 : int x int x int -> ImP2
// Entrée : 3 entiers, hauteur , largeur et la valeur max de l'image (intensité de couleur)
// Sortie : une structure ImP3 initialisé avec les valeurs passee et le malloc de tpix déjà fait
extern ImP2 initImP2(int haut, int larg, int vmax);

// copieImP2 : ImP2 -> ImP2
// Entrée : un ImP2 im
// Sortie : une copie de la structure ImP2 entrée en paramètre
extern ImP2 copieImP2(ImP2 im);

// chargeImP2 : char* -> ImP2
// Entrée : un pointeur sur le nom du fichier à charger
// Sortie : une structure ImP2 avec les valeurs dicté par le fichier.
extern ImP2 chargeImP2(char* fichier);


// chargeImP2 : char* x ImP2 -> ImP2
// Entrée : le nom du fichier a copier et une image
// Sortie : Rien
//Crée un fichier image .ppm
extern void sauveImP2(char* nom, ImP2 im);

#endif
