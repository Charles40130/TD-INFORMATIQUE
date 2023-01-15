#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* TRUC A FAIRE DANS LE PROGRAMME 
    
    -FAIRE UNE FONCTION POUR VERIFIER QUE LA SAISIE DE L'UTILSATEUR EST VALIDE , exemple: 1000= valide , 6756= invalide , 12445= invalide 76432 = invalide
        paramC(tre C  prendre en compte : il faut que le nb comporte 4 chiffres compris entre 0 et 5 sinon nb= invalide




*/



typedef enum
{ JAUNE, BLEU, ROUGE, VERT, ORANGE, VIOLET } couleur;

typedef enum
{ VIDE, BLANC, NOIR } placement;

//Procédures qui génère les valeurs du tableau correspondant au couleur C à déterminer//
void
generate_secret (int secret[4])
{
  //boucle pour génèrer 4 chiffres aléatoires compris entre 0 et 5//
  srand (time (NULL));
  for (int i = 0; i < 4; i++)
    {
      secret[i] = rand () % 6;	// 6 couleurs disponibles
    }



  //Boucle pour afficher le code secret gC)nC)rC)//
  printf ("CODE SECRET:\n");
  for (int j = 0; j < 4; j++)
    {
      printf ("%d", secret[j]);
    }
  printf ("\n");
  //////////////////////////////////////////
}

//ProcC)dures pour afficher visuellement le tableau du mastermind ( en fonction des valeurs du tableau)//
void
afftableau (char tab[12][6])
{
  printf ("TABLEAU MASTERMIND \n");
  printf ("\n");
  printf ("________________\n");
  printf ("            N B\n");
  for (int j = 0; j < 12; j++)
    {
      for (int i = 0; i < 6; i++)
	{

	  printf ("|%c", tab[j][i]);
	  if (i == 3)
	    {
	      printf ("|  ");
	    }
	}
      printf ("|\n");
    }
}

//Fonction qui demande et renvoi le nombre saisie par l'utilisateur//
int
saisie ()
{
  int nb;
  int bool;
  printf ("Code couleur :\n");
  printf ("Jaune=0 , Bleu=1, Rouge= 2, Vert= 3 , Orange = 4 , Violet= 5 \n");

  do
    {
      printf
	("Entrez un nombre composé de 4 chiffres( compris entre 0 et 6 ): ");
      scanf ("%d", &nb);
      bool = 1;
      for (int i = 0; i < 4; i++)
	{
	  int chiffre = nb % 10;	// extrait le chiffre en position i
	  if (chiffre < 0 || chiffre > 6)
	    {			// vérifie que le chiffre est compris entre 0 et 6
	      printf
		("ERREUR !! Le nombre doit être composC) de chiffres compris entre 0 et 6\n");
	      bool = 0;
	      // return 0; // on quitte le programme
	      break;		// on arrête la boucle
	    }
	  nb /= 10;		// on enlève le chiffre traité du nombre
	}
    }
  while (!bool);
  return nb;
}

void
decode (int retour, char tab[12][6], int ligne, int secret[4])
{
  int tabsaisie[4];
  //boucle pour afin de transformer l'entier saisie par l'utilisateur en tableau de chiffres de taille 4//
  for (int i = 3; i > -1; i--)
    {
      tabsaisie[i] = retour % 10;
      retour = retour / 10;
    }
  ////////////////////////////////////////////////////////////////////


  //boucle for pour afficher le tableau pour vérifier que tout marche//
  /*for (int j = 0; j < 4; j++){
     printf("%d\n",tabsaisie[j]);
     } */
  /////////////////////////////////////////////////////////////////////


  //boucle pour modifier le tableau du mastermind(ie met les lettres correspondant au couleurs dans le tableau) en fonction du tableau de chiffres de l'utilisateur//
  for (int h = 0; h < 4; h++)
    {
      switch (tabsaisie[h])
	{
	case 0:
	  tab[ligne][h] = 'Y';
	  break;
	case 1:
	  tab[ligne][h] = 'B';
	  break;
	case 2:
	  tab[ligne][h] = 'R';
	  break;
	case 3:
	  tab[ligne][h] = 'G';
	  break;
	case 4:
	  tab[ligne][h] = 'O';
	  break;
	case 5:
	  tab[ligne][h] = 'P';
	  break;
	default:
	  tab[ligne][h] = '_';
	}
    }
  //////////////////////////////////////////////////////////////////////////////////////////////
  int N = 0;
  int B = 0;

  for (int k = 0; k < 4; k++)
    {
      for (int m = 0; m < 4; m++)
	{
	  if (tabsaisie[k] == secret[m])
	    {
	      if (k == m)
		{
		  N++;
		}
	      else
		{
		  B++;

		}
	    }

	}
    }
  printf ("Il y a %d billes noires et %d billes blanches \n", N, B);

  switch (N)
    {

    case 1:
      tab[ligne][5] = '1';
      break;
    case 2:
      tab[ligne][5] = '2';
      break;
    case 3:
      tab[ligne][5] = '3';
      break;
    case 4:
      tab[ligne][5] = '4';
      break;
    default:
      tab[ligne][5] = '0';
    }
  switch (B)
    {

    case 1:
      tab[ligne][4] = '1';
      break;
    case 2:
      tab[ligne][4] = '2';
      break;
    case 3:
      tab[ligne][4] = '3';
      break;
    case 4:
      tab[ligne][4] = '4';
      break;
    default:
      tab[ligne][4] = '0';
    }
}



int
main ()
{

  char tab[12][6] =
    { {'_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_'}, {'_',
								       '_',
								       '_',
								       '_',
								       '_',
								       '_'},
    {'_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_'}, {'_', '_',
								     '_', '_',
								     '_',
								     '_'},
    {'_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_'}, {'_', '_',
								     '_', '_',
								     '_',
								     '_'},
    {'_', '_', '_', '_', '_', '_'}, {'_', '_', '_', '_', '_', '_'}, {'_', '_',
								     '_', '_',
								     '_',
								     '_'} };
  int secret[4];
  int retour;
  int ligne;
  ligne = 11;
  generate_secret (secret);
  afftableau (tab);
  do
    {
      retour = saisie ();
      decode (retour, tab, ligne, secret);
      afftableau (tab);
      ligne--;
    }
  while ((ligne > -1) && (tab[ligne + 1][5] != '4'));
  if (tab[ligne + 1][5] == '4')
    {
      printf ("C'est gagné)!");
    }
  else
    {
      printf ("Tu as perdu!");
    }
  return 0;
}
