#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 6

//Procédures pour convertir notre chaine de caractères dans une tableau//
void conversiontab(char chaine[36],char tab[6][6]){
    int h;
    h=0;

    for (int i=0 ;i<6; i++){
      for (int j=0 ; j<6 ; j++){
        if (chaine[h]=='\n'){
        break;
      }
        tab[i][j]=chaine[h];
        h++;
      }
    }
}

//Procédures pour afficher le tableau//
void afftableau(char tab[6][6])
{

  printf ("\n");

  for (int i = 0; i < 6; i++)
    {
      for (int j = 0; j < 6; j++)
	{

	  printf ("|%c", tab[i][j]);

  }
      printf ("|\n");
    }
}

//Procédures pour initialiser le tableau//
void initab (char tab[6][6]){
  for (int i = 0; i< 6; i++){
      for (int j = 0; j < 6; j++){
      tab[i][j]=' ';
      }
  }
}

void cryptage(char tab[6][6]){
  for (int i=0 ;i<6; i++){
    for (int j=0 ; j<6 ; j++){
      printf("%c",tab[j][i]);
    }
  }
}

int main(int argc, char** argv){
  char chaine[36];

  char tab[6][6];
  printf("Veuillez saisir une chaîne \n");
  fgets(chaine, sizeof chaine, stdin); //Attention fgets prend aussi la touche entrée ( une fois que l'utilisateur a fini sa saisie) correspondant à un retour à la ligne ainsi cela correspond à un \n dont il faut se débarassé.
  printf("%s",chaine);
  initab(tab);
  conversiontab(chaine,tab);
  afftableau(tab);
  cryptage(tab);




}
