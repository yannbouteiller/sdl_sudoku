//fonctions.c fonctions globales de SDL_Sudoku

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "constantes.h"

int verifierGrille(int grille[9][9]) //renvoie 1 en cas de victoire, 0 en l'absence.
{
   int victoire = 1;
   int c[9] = {0};
   int i = 0, j = 0, m = 0, n = 0;
   int k = 0;

   //v�rification par lignes

   for(j=0; j<9; j++)
   {
       c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0; c[4] = 0; c[5] = 0; c[6] = 0; c[7] = 0; c[8] = 0;
       for(i=0; i<9; i++)
       {
       switch(grille[i][j])
       {
           case 0 :
           victoire = 0;
           break;

           case 1 :
           c[0] = 1;
           break;

           case 11 :
           c[0] = 1;
           break;

           case 2 :
           c[1] = 1;
           break;

           case 12 :
           c[1] = 1;
           break;

           case 3 :
           c[2] = 1;
           break;

           case 13 :
           c[2] = 1;
           break;

           case 4 :
           c[3] = 1;
           break;

           case 14 :
           c[3] = 1;
           break;

           case 5 :
           c[4] = 1;
           break;

           case 15 :
           c[4] = 1;
           break;

           case 6 :
           c[5] = 1;
           break;

           case 16 :
           c[5] = 1;
           break;

           case 7 :
           c[6] = 1;
           break;

           case 17 :
           c[6] = 1;
           break;

           case 8 :
           c[7] = 1;
           break;

           case 18 :
           c[7] = 1;
           break;

           case 9 :
           c[8] = 1;
           break;

           case 19 :
           c[8] = 1;
           break;

        default:
        break;
       }
       }

        for(k=0; k<9; k++)
        {
            if(c[k] == 0)
            {
                victoire = 0;
            }
        }
   }

   //v�rification par colones

   for(i=0; i<9; i++)
   {
       c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0; c[4] = 0; c[5] = 0; c[6] = 0; c[7] = 0; c[8] = 0;
       for(j=0; j<9; j++)
       {
       switch(grille[i][j])
       {
           case 0 :
           victoire = 0;
           break;

           case 1 :
           c[0] = 1;
           break;

           case 11 :
           c[0] = 1;
           break;

           case 2 :
           c[1] = 1;
           break;

           case 12 :
           c[1] = 1;
           break;

           case 3 :
           c[2] = 1;
           break;

           case 13 :
           c[2] = 1;
           break;

           case 4 :
           c[3] = 1;
           break;

           case 14 :
           c[3] = 1;
           break;

           case 5 :
           c[4] = 1;
           break;

           case 15 :
           c[4] = 1;
           break;

           case 6 :
           c[5] = 1;
           break;

           case 16 :
           c[5] = 1;
           break;

           case 7 :
           c[6] = 1;
           break;

           case 17 :
           c[6] = 1;
           break;

           case 8 :
           c[7] = 1;
           break;

           case 18 :
           c[7] = 1;
           break;

           case 9 :
           c[8] = 1;
           break;

           case 19 :
           c[8] = 1;
           break;

        default:
        break;
       }
       }

        for(k=0; k<9; k++)
        {
            if(c[k] == 0)
            {
                victoire = 0;
            }
        }
   }

   //v�rification par carr�

   for(n=0; n<3; n++)
   {
       for(m=0; m<3; m++)
       {
           c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0; c[4] = 0; c[5] = 0; c[6] = 0; c[7] = 0; c[8] = 0;

           for(j=0; j<3; j++)
           {
               for(i=0; i<3; i++)
               {
            switch(grille[i+(3*n)][j+(3*n)])
            {
            case 0 :
            victoire = 0;
            break;

            case 1 :
            c[0] = 1;
            break;

            case 11 :
            c[0] = 1;
            break;

            case 2 :
            c[1] = 1;
            break;

            case 12 :
            c[1] = 1;
            break;

            case 3 :
            c[2] = 1;
            break;

            case 13 :
            c[2] = 1;
            break;

            case 4 :
            c[3] = 1;
            break;

            case 14 :
            c[3] = 1;
            break;

           case 5 :
           c[4] = 1;
           break;

           case 15 :
           c[4] = 1;
           break;

           case 6 :
           c[5] = 1;
           break;

           case 16 :
           c[5] = 1;
           break;

           case 7 :
           c[6] = 1;
           break;

           case 17 :
           c[6] = 1;
           break;

           case 8 :
           c[7] = 1;
           break;

           case 18 :
           c[7] = 1;
           break;

           case 9 :
           c[8] = 1;
           break;

           case 19 :
           c[8] = 1;
           break;

        default:
        break;
            }
            }
            }

        for(k=0; k<9; k++)
        {
            if(c[k] == 0)
            {
                victoire = 0;
            }
        }

        }
    }



   return victoire;
}

int analyserGrille(int grille[9][9], AnalyseGrille* Analyse) //remplit l'AnalyseGrille "Analyse", renvoie 1 si soluble, 0 si non.
{
    FILE* anatxt = NULL;
    anatxt = fopen("analyse.txt", "w+");

    int i = 0;
    int j = 0;
    int k = 0;
    int ii = 0;
    int jj = 0;
    int kk = 0;

    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    int a4 = 0;
    int a5 = 0;
    int a6 = 0;
    int a7 = 0;
    int a8 = 0;
    int a9 = 0;

    int v = 0; //valeur vive

    int n = 0; //nombre de passages de l'algorithme
    int acte = 1;

    int analyseCase[10];
    int analyseVive[10];

    int analyseAv[9]; // [positions]

    int esp[3][3];
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            esp[i][j] = 0;
        }
    }

    int espace[9][9][10]; //grille[i][j][positions valeurs restantes]

    for(j=0; j<9; j++) //initialisation � "possible" pour tout k � priori
    {
        for(i=0; i<9; i++)
        {
            for(k=1; k<10; k++)
            {
                espace[i][j][k] = 1;
            }
            espace[i][j][0] = 0; //non fix�
        }
    }



    for(j=0; j<9; j++) //copie de grille dans espace
    {
        for(i=0; i<9; i++)
        {
            if(grille[i][j] != 0)
            {
                if(grille[i][j] < 10)
                {
                    v = grille[i][j];
                }
                else
                {
                    v = grille[i][j] - 10;
                }

                for(k=1;k<10;k++)
                {
                    espace[i][j][k] = 0;
                }
                espace [i][j][v] = 1;
                espace [i][j][0] = 1; //valeur fix�e
            }
        }
    }


    while(acte) //boucle principale
    {
        acte = 0;
        n++;

        for(j=0;j<9;j++)
        {
            for(i=0;i<9;i++)
            {
                if(espace[i][j][0] == 0) //assure que la case en cours de modification n'est pas fix�e
                {
                for(k=1;k<10;k++)
                {
                    if(espace[i][j][k] == 1)
                    {
                        //reduction de k par d�duction lin�aire
                        for(jj=0;jj<9;jj++)
                        {
                            for(ii=0;ii<9;ii++)
                            {
                                if((ii != i)||(jj != j))
                                {
                                    //parcours ligne
                                    if(espace[ii][j][0] == 1)
                                    {
                                        if((espace[ii][j][k] == 1)&&(espace[i][j][k] == 1))
                                        {
                                            espace[i][j][k] = 0;
                                            acte = 1;
                                        }

                                    }
                                    //parcours colone
                                    if(espace[i][jj][0] == 1)
                                    {
                                        if((espace[i][jj][k] == 1)&&(espace[i][j][k] == 1))
                                        {
                                            espace[i][j][k] = 0;
                                            acte = 1;
                                        }
                                    }
                                    //parcours carr�
                                    if((espace[ii][jj][0] == 1)&&(ii/3 == i/3)&&(jj/3 == j/3))
                                    {
                                        if((espace[ii][jj][k] == 1)&&(espace[i][j][k] == 1))
                                        {
                                            espace[i][j][k] = 0;
                                            acte = 1;
                                        }
                                    }
                                }
                            }
                        }

                        //fixage si un seul k restant
                        v = 0;
                        for(kk=1;kk<10;kk++)
                        {
                            v = (v + espace[i][j][kk]);
                        }
                        if((v == 1)&&(espace[i][j][k] == 1)&&(espace[i][j][0] == 0))
                        {
                            for(kk=0;kk<10;kk++)
                            {
                                espace[i][j][kk] = 0;
                            }
                            espace[i][j][k] = 1;
                            espace[i][j][0] = 1;
                            acte = 1;
                            fprintf(anatxt, "Fixage de %d en %d/%d\t(case) \n", k, i+1, j+1);
                        }

                        //fixage par d�duction d'impossibilit�s

                        //parcours ligne
                        v = 0;
                        for(ii=0;ii<9;ii++)
                        {
                            v = v + espace[ii][j][k];
                        }
                        if((v == 1)&&(espace[i][j][k] == 1)&&(espace[i][j][0] == 0))
                        {
                            for(kk=0;kk<10;kk++)
                            {
                                espace[i][j][kk] = 0;
                            }
                            espace[i][j][k] = 1;
                            espace[i][j][0] = 1;
                            acte = 1;
                            fprintf(anatxt, "Fixage de %d en %d/%d\t(ligne) \n", k, i+1, j+1);
                        }

                        //parcours colone
                        v = 0;
                        for(jj=0;jj<9;jj++)
                        {
                            v = v + espace[i][jj][k];
                        }
                        if((v == 1)&&(espace[i][j][k] == 1)&&(espace[i][j][0] == 0))
                        {
                            for(kk=0;kk<10;kk++)
                            {
                                espace[i][j][kk] = 0;
                            }
                            espace[i][j][k] = 1;
                            espace[i][j][0] = 1;
                            acte = 1;
                            fprintf(anatxt, "Fixage de %d en %d/%d\t(colone) \n", k, i+1, j+1);
                        }

                        //parcours carr�
                        v = 0;
                        for(jj = ((j/3)*3);jj < (((j/3)*3)+3);jj++)
                        {
                            for(ii = ((i/3)*3);ii < (((i/3)*3)+3);ii++)
                            {
                                v = v + espace[ii][jj][k];
                            }
                        }
                        if((v == 1)&&(espace[i][j][k] == 1)&&(espace[i][j][0] == 0))
                        {
                            for(kk=0;kk<10;kk++)
                            {
                                espace[i][j][kk] = 0;
                            }
                            espace[i][j][k] = 1;
                            espace[i][j][0] = 1;
                            acte = 1;
                            fprintf(anatxt, "Fixage de %d en %d/%d\t(r�gion) \n", k, i+1, j+1);
                        }

                    }


                }
                }
            }
        }

        //Analyse avanc�e

        for(k=1;k<10;k++)
        {
            //verticale
        for(i=0;i<3;i++)
        {

            for(j=0;j<3;j++)
            {
                for(ii=0;ii<3;ii++)
                {
                    esp[ii][j] = 0;
                }
            }

            for(ii=0;ii<3;ii++)
            {
                for(j=0;j<3;j++)
                {
                    v = 0;
                    for(jj=0;jj<3;jj++)
                    {
                        if(espace[i*3 + ii][j*3 + jj][k] == 0)
                        {
                            v++;
                        }
                    }
                    if(v == 3)
                    {
                        esp[ii][j] = 1;
                    }
                }
            } //esp rempli pour la section "i"


            for(j=0;j<3;j++) //analyse verticale-horizontale
            {
                v = 0;
                for(ii=0;ii<3;ii++)
                {
                    if(esp[ii][j] == 1)
                    {
                        v++;
                    }
                }
                if(v == 2)
                {
                    for(ii=0;ii<3;ii++)
                    {
                        if(esp[ii][j] == 0)
                        {
                            for(jj=0;jj<3;jj++)
                            {
                                if(jj != j) //jj ordonn�e de esp != j
                                {
                                    for(kk=0;kk<3;kk++)
                                    {
                                        if(espace[i*3 + ii][jj*3 + kk][k] != 0)
                                        {
                                            espace[i*3 + ii][jj*3 + kk][k] = 0;
                                            acte = 1;
                                            fprintf(anatxt, "Elimination de %d en %d/%d\t(fourche) \n", k, (i*3)+ii+1, (jj*3)+kk+1);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            for(ii=0;ii<3;ii++) //analyse verticale-verticale
            {
                v = 0;
                for(j=0;j<3;j++)
                {
                    if(esp[ii][j] == 1)
                    {
                        v++;
                    }
                }
                if(v == 2)
                {
                    for(j=0;j<3;j++)
                    {
                        if(esp[ii][j] == 0)
                        {
                            for(jj=0;jj<3;jj++) // attention : jj abscisse de esp != ii !
                            {
                                if(jj != ii)
                                {
                                    for(kk=0;kk<3;kk++)
                                    {
                                        if(espace[i*3 + jj][j*3 + kk][k] != 0)
                                        {
                                            espace[i*3 + jj][j*3 + kk][k] = 0;
                                            acte = 1;
                                            fprintf(anatxt, "Elimination de %d en %d/%d\t(fourche) \n", k, (i*3)+jj+1, (j*3)+kk+1);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        //horizontale

        for(i=0;i<3;i++)
        {

            for(j=0;j<3;j++)
            {
                for(ii=0;ii<3;ii++)
                {
                    esp[ii][j] = 0;
                }
            }

            for(ii=0;ii<3;ii++)
            {
                for(j=0;j<3;j++)
                {
                    v = 0;
                    for(jj=0;jj<3;jj++)
                    {
                        if(espace[j*3 + jj][i*3 + ii][k] == 0)
                        {
                            v++;
                        }
                    }
                    if(v == 3)
                    {
                        esp[ii][j] = 1;
                    }
                }
            } //esp rempli pour la section "i"


            for(j=0;j<3;j++) //analyse horizontale-horizontale
            {
                v = 0;
                for(ii=0;ii<3;ii++)
                {
                    if(esp[ii][j] == 1)
                    {
                        v++;
                    }
                }
                if(v == 2)
                {
                    for(ii=0;ii<3;ii++)
                    {
                        if(esp[ii][j] == 0)
                        {
                            for(jj=0;jj<3;jj++)
                            {
                                if(jj != j) //jj ordonn�e de esp != j
                                {
                                    for(kk=0;kk<3;kk++)
                                    {
                                        if(espace[jj*3 + kk][i*3 + ii][k] != 0)
                                        {
                                            espace[jj*3 + kk][i*3 + ii][k] = 0;
                                            acte = 1;
                                            fprintf(anatxt, "Elimination de %d en %d/%d\t(fourche) \n", k, (jj*3)+kk+1, (i*3)+ii+1);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            for(ii=0;ii<3;ii++) //analyse horizontale-verticale
            {
                v = 0;
                for(j=0;j<3;j++)
                {
                    if(esp[ii][j] == 1)
                    {
                        v++;
                    }
                }
                if(v == 2)
                {
                    for(j=0;j<3;j++)
                    {
                        if(esp[ii][j] == 0)
                        {
                            for(jj=0;jj<3;jj++) // attention : jj abscisse de esp != ii !
                            {
                                if(jj != ii)
                                {
                                    for(kk=0;kk<3;kk++)
                                    {
                                        if(espace[j*3 + kk][i*3 + jj][k] != 0)
                                        {
                                            espace[j*3 + kk][i*3 + jj][k] = 0;
                                            acte = 1;
                                            fprintf(anatxt, "Elimination de %d en %d/%d\t(fourche) \n", k, (j*3)+kk+1, (i*3)+jj+1);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


        }

        //tests lourds en cas d'absence de r�sultat pour ce tour de boucle
        if(acte == 0)
        {
            //recherche des n-uplets : liste chiffre analys� (possibilit�s restantes) => cardinal,liste; liste vive => comparer (possibilit�s restantes doivent exactement correspondre); tableau n-uplets => analyser (cardinal doit correspondre au nombre d'emplacements trouv�s)

            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                {
                    for(kk=0;kk<10;kk++)
                    {
                        analyseCase[kk] = 0;
                    }

                    if(espace[i][j][0] != 1)
                    {
                        for(k=1;k<10;k++)
                        {
                            if(espace[i][j][k] == 1)
                            {
                                analyseCase[k] = 1;
                                analyseCase[0]++;
                            }
                        }
                    }

                    // par ligne

                        for(ii=0;ii<9;ii++)
                        {
                            analyseAv[ii] = 0;
                        }
                        analyseAv[i] = 1;


                    for(ii=0;ii<9;ii++)
                    {
                        if((espace[ii][j][0] != 1)&&(ii != i))
                        {
                            for(kk=0;kk<10;kk++)
                            {
                                analyseVive[kk] = 0;
                            }

                            for(k=1;k<10;k++)
                            {
                                if(espace[ii][j][k] == 1)
                                {
                                    analyseVive[k] = 1;
                                    analyseVive[0]++;
                                }
                            }
                            v = 0;

                            for(k=0;k<10;k++)
                            {
                                if(analyseCase[k] != analyseVive[k])
                                {
                                    v++;
                                }
                            }

                            if(v == 0) //m�mes possibilit�s exactement dans les deux cases
                            {
                                analyseAv[ii] = 1;
                            }
                        }
                    }
                    // analyse de analyseAv

                    v = 0;

                    for(ii=0;ii<9;ii++)
                    {
                        if(analyseAv[ii] == 1)
                        {
                            v++; // une case convenable
                        }
                    }

                    if((v == analyseCase[0])&&(v != 0)) // autant de cases convenables que de possibilit�s
                    {
                        //eliminations
                        for(ii=0;ii<9;ii++)
                        {
                            if((analyseAv[ii] == 0)&&(espace[ii][j][0] != 1))
                            {
                                for(k=1;k<10;k++)
                                {
                                    if((analyseCase[k] == 1)&&(espace[ii][j][k] != 0))
                                    {
                                        espace[ii][j][k] = 0;
                                        acte = 1;
                                        fprintf(anatxt, "Elimination de %d en %d/%d\t(ligne) \n", k, ii+1, j+1);
                                    }
                                }
                            }
                        }
                    }

                    // par colone

                        for(jj=0;jj<9;jj++)
                        {
                            analyseAv[jj] = 0;
                        }
                        analyseAv[j] = 1;


                    for(jj=0;jj<9;jj++)
                    {
                        if((espace[i][jj][0] != 1)&&(jj != j))
                        {
                            for(kk=0;kk<10;kk++)
                            {
                                analyseVive[kk] = 0;
                            }

                            for(k=1;k<10;k++)
                            {
                                if(espace[i][jj][k] == 1)
                                {
                                    analyseVive[k] = 1;
                                    analyseVive[0]++;
                                }
                            }
                            v = 0;

                            for(k=0;k<10;k++)
                            {
                                if(analyseCase[k] != analyseVive[k])
                                {
                                    v++;
                                }
                            }

                            if(v == 0) //m�mes possibilit�s exactement dans les deux cases
                            {
                                analyseAv[jj] = 1;
                            }
                        }
                    }
                    // analyse de analyseAv

                    v = 0;

                    for(jj=0;jj<9;jj++)
                    {
                        if(analyseAv[jj] == 1)
                        {
                            v++; // une case convenable
                        }
                    }

                    if((v == analyseCase[0])&&(v != 0)) // autant de cases convenables que de possibilit�s
                    {
                        //eliminations
                        for(jj=0;jj<9;jj++)
                        {
                            if((analyseAv[jj] == 0)&&(espace[i][jj][0] != 1))
                            {
                                for(k=1;k<10;k++)
                                {
                                    if((analyseCase[k] == 1)&&(espace[i][jj][k] != 0))
                                    {
                                        espace[i][jj][k] = 0;
                                        acte = 1;
                                        fprintf(anatxt, "Elimination de %d en %d/%d\t(colone) \n", k, i+1, jj+1);
                                    }
                                }
                            }
                        }
                    }

                    // par r�gion

                        for(ii=0;ii<9;ii++)
                        {
                            analyseAv[ii] = 0;
                        }
                        analyseAv[(i%3)+(3*(j%3))] = 1;


                    for(ii=0;ii<9;ii++)
                    {
                        if((espace[i-(i%3)+(ii%3)][j-(j%3)+(ii/3)][0] != 1)&&((ii%3 != i%3) || (ii/3 != j)))
                        {
                            for(kk=0;kk<10;kk++)
                            {
                                analyseVive[kk] = 0;
                            }

                            for(k=1;k<10;k++)
                            {
                                if(espace[i-(i%3)+(ii%3)][j-(j%3)+(ii/3)][k] == 1)
                                {
                                    analyseVive[k] = 1;
                                    analyseVive[0]++;
                                }
                            }
                            v = 0;

                            for(k=0;k<10;k++)
                            {
                                if(analyseCase[k] != analyseVive[k])
                                {
                                    v++;
                                }
                            }

                            if(v == 0) //m�mes possibilit�s exactement dans les deux cases
                            {
                                analyseAv[ii] = 1;
                            }
                        }
                    }
                    // analyse de analyseAv

                    v = 0;

                    for(ii=0;ii<9;ii++)
                    {
                        if(analyseAv[ii] == 1)
                        {
                            v++; // une case convenable
                        }
                    }

                    if((v == analyseCase[0])&&(v != 0)) // autant de cases convenables que de possibilit�s
                    {
                        //eliminations
                        for(ii=0;ii<9;ii++)
                        {
                            if((analyseAv[ii] == 0)&&(espace[i-(i%3)+(ii%3)][j-(j%3)+(ii/3)][0] != 1))
                            {
                                for(k=1;k<10;k++)
                                {
                                    if((analyseCase[k] == 1)&&(espace[i-(i%3)+(ii%3)][j-(j%3)+(ii/3)][k] != 0))
                                    {
                                        espace[i-(i%3)+(ii%3)][j-(j%3)+(ii/3)][k] = 0;
                                        acte = 1;
                                        fprintf(anatxt, "Elimination de %d en %d/%d\t(r�gion) \n", k, i-(i%3)+(ii%3)+1, j-(j%3)+(ii/3)+1);
                                    }
                                }
                            }
                        }
                    }

                }
            }

            // m�thode ultra-bourrin faute de mieux : on teste TOUS les groupes immaginables

            if(acte == 0)
            {
            for(a1=0;a1<=1;a1++)
            {
                for(a2=0;a2<=1;a2++)
                {
                    for(a3=0;a3<=1;a3++)
                    {
                        for(a4=0;a4<=1;a4++)
                        {
                            for(a5=0;a5<=1;a5++)
                            {
                                for(a6=0;a6<=1;a6++)
                                {
                                    for(a7=0;a7<=1;a7++)
                                    {
                                        for(a8=0;a8<=1;a8++)
                                        {
                                            for(a9=0;a9<=1;a9++)
                                            {
                                                analyseCase[0] = 0;
                                                analyseCase[1] = a1;
                                                analyseCase[2] = a2;
                                                analyseCase[3] = a3;
                                                analyseCase[4] = a4;
                                                analyseCase[5] = a5;
                                                analyseCase[6] = a6;
                                                analyseCase[7] = a7;
                                                analyseCase[8] = a8;
                                                analyseCase[9] = a9;

                                                for(k=1;k<10;k++) //cardinal de la famille
                                                {
                                                    analyseCase[0] = analyseCase[0] + analyseCase[k];
                                                }

                                                // par ligne

                                                for(j=0;j<9;j++)
                                                {
                                                    v = 0;
                                                    for(i=0;i<9;i++)
                                                    {
                                                        analyseAv[i] = 0;
                                                    }

                                                    for(i=0;i<9;i++)
                                                    {
                                                        ii = 1;
                                                        for(k=1;k<10;k++)
                                                        {
                                                            if((espace[i][j][k] == 1) && (analyseCase[k] == 0))
                                                            {
                                                                ii = 0;
                                                            }
                                                        }

                                                        if(ii == 1)
                                                        {
                                                            analyseAv[i] = 1; // cette case convient
                                                            v++;
                                                        }
                                                    }

                                                    if(analyseCase[0] == v) //�liminations
                                                    {
                                                        for(i=0;i<9;i++)
                                                        {
                                                            if(analyseAv[i] != 1) // case non convenable !
                                                            {
                                                                for(k=1;k<10;k++)
                                                                {
                                                                    if((espace[i][j][k] == 1)&&(analyseCase[k] == 1))
                                                                    {
                                                                        espace[i][j][k] = 0;
                                                                        acte = 1;
                                                                        fprintf(anatxt, "Elimination de %d en %d/%d\t(ligne)\t\t(groupe complexe) \n", k, i+1, j+1);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                // par colones

                                                for(i=0;i<9;i++)
                                                {
                                                    v = 0;
                                                    for(j=0;j<9;j++)
                                                    {
                                                        analyseAv[j] = 0;
                                                    }

                                                    for(j=0;j<9;j++)
                                                    {
                                                        ii = 1;
                                                        for(k=1;k<10;k++)
                                                        {
                                                            if((espace[i][j][k] == 1) && (analyseCase[k] == 0))
                                                            {
                                                                ii = 0;
                                                            }
                                                        }

                                                        if(ii == 1)
                                                        {
                                                            analyseAv[j] = 1; // cette case convient
                                                            v++;
                                                        }
                                                    }

                                                    if(analyseCase[0] == v) //�liminations
                                                    {
                                                        for(j=0;j<9;j++)
                                                        {
                                                            if(analyseAv[j] != 1) // case non convenable !
                                                            {
                                                                for(k=1;k<10;k++)
                                                                {
                                                                    if((espace[i][j][k] == 1)&&(analyseCase[k] == 1))
                                                                    {
                                                                        espace[i][j][k] = 0;
                                                                        acte = 1;
                                                                        fprintf(anatxt, "Elimination de %d en %d/%d\t(colone)\t(groupe complexe) \n", k, i+1, j+1);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                // par r�gions

                                                for(j=0;j<9;j++) // j repr�sente ici la r�gion analys�e
                                                {
                                                    v = 0;
                                                    for(i=0;i<9;i++)
                                                    {
                                                        analyseAv[i] = 0;
                                                    }

                                                    for(i=0;i<9;i++) // i est la case concern�e de la r�gion
                                                    {
                                                        ii = 1;
                                                        for(k=1;k<10;k++)
                                                        {
                                                            if((espace[((j%3)*3)+(i%3)][((j/3)*3)+(i/3)][k] == 1) && (analyseCase[k] == 0))
                                                            {
                                                                ii = 0;
                                                            }
                                                        }

                                                        if(ii == 1)
                                                        {
                                                            analyseAv[i] = 1; // cette case convient
                                                            v++;
                                                        }
                                                    }

                                                    if(analyseCase[0] == v) //�liminations
                                                    {
                                                        for(i=0;i<9;i++)
                                                        {
                                                            if(analyseAv[i] != 1) // case non convenable !
                                                            {
                                                                for(k=1;k<10;k++)
                                                                {
                                                                    if((espace[((j%3)*3)+(i%3)][((j/3)*3)+(i/3)][k] == 1)&&(analyseCase[k] == 1))
                                                                    {
                                                                        espace[((j%3)*3)+(i%3)][((j/3)*3)+(i/3)][k] = 0;
                                                                        acte = 1;
                                                                        fprintf(anatxt, "Elimination de %d en %d/%d\t(r�gion)\t(groupe complexe) \n", k, i+1, j+1);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            }
        }

    }
    Analyse->difficulte = n;

    //envoi de la solution � grilleSoute
    for(j=0;j<9;j++)
    {
        for(i=0;i<9;i++)
        {
            Analyse->grilleSoute[i][j] = grille[i][j];
        }
    }
    for(j=0;j<9;j++)
    {
        for(i=0;i<9;i++)
        {
            if(Analyse->grilleSoute[i][j] < 10)
            {
                for(k=1;k<10;k++)
                {
                    if((espace[i][j][0] == 1)&&(espace[i][j][k] == 1))
                    {
                        Analyse->grilleSoute[i][j] = k;
                    }
                }
            }
        }
    }

    fclose(anatxt);

    return verifierGrille(Analyse->grilleSoute);
}
