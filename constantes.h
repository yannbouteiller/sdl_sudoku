//contantes.h définit les constantes communes au programme.

#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

#define TAILLE_CASE 30
#define TAILLE_BLOC 27
#define TAILLE_GRILLE 9 * TAILLE_CASE

#define LARGEUR_ECRAN 269
#define HAUTEUR_ECRAN 269

typedef struct AnalyseGrille AnalyseGrille;
struct AnalyseGrille
{
    int difficulte;
    int probGrille[9][9];
    int grilleSoute[9][9];
};

#endif
