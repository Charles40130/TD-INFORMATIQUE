#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 2


int decallage(){
    int nb;
    printf("De combien voulez-vous le décallage\n");
    scanf("%d",&nb);
    return nb;
}
void cryptage(char chaine[36],int nb_decallage){

    for (int h=0 ; h<36 ; h++){
        if (chaine[h]=='\n'){
        break;
      }
        char c = chaine[h];
        int asciiCode = (int) c;
        asciiCode= asciiCode + nb_decallage;
        printf("%c", asciiCode);
    }
}
//Procédures qui permet de vider le tampon ( important car fgets l.41 prend la touche entrée du scanf l.12)
void emptyBuffer() {
  char c;
  while (((c = getchar()) != '\n') && (c != EOF));
}


int main(int argc, char** argv){
  char chaine[36];
    int nb_decallage;
    nb_decallage= decallage();
    emptyBuffer();

  printf("Veuillez saisir une chaîne \n");
  fgets(chaine, sizeof chaine, stdin); //Attention fgets prend aussi la touche entrée ( une fois que l'utilisateur a fini sa saisie) correspondant à un retour à la ligne ainsi cela correspond à un \n dont il faut se débarassé.
  printf("%s",chaine);
    cryptage(chaine,nb_decallage);

}
