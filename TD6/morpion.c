
#include <stdio.h>
#include <stdlib.h>

//structure d'un joueur
typedef struct{
	int age;
	char prenom[30];
	char symbole;
}joueur;

//Procédures qui affiche le tableau//
void afftableau(char tab[3][3]){
	for (int j=0; j<3; j++){
		for (int i=0; i<3; i++) {
			printf("|%c",tab[j][i]);
								
		}
		printf("|\n");
	}
		
}

//Procédures qui modifie le tableau en fonction choix du joueur
void modiftab(char tab[3][3],joueur joueur1,int a,int b,joueur joueur2,int tour){
    if( tour%2==0){
	    tab[a][b]=joueur1.symbole;}
	else{
	    tab[a][b]=joueur2.symbole;
	}
}

//Fonction qui vérifie et renvoi le gagnant //
char verifgagnant(char tab[3][3],joueur joueur1,joueur joueur2){
    	//colone et ligne
	for(int i=0; i<3; i++){
		if(tab[i][0]==joueur1.symbole && tab[i][1]==joueur1.symbole && tab[i][2]==joueur1.symbole){
			return joueur1.symbole;
		}
		if(tab[0][i]==joueur1.symbole && tab[1][i]==joueur1.symbole && tab[2][i]==joueur1.symbole){
			return joueur1.symbole;
		}
	}
	for(int i=0; i<3; i++){
		if(tab[i][0]==joueur2.symbole && tab[i][1]==joueur2.symbole && tab[i][2]==joueur2.symbole){
			return joueur2.symbole;
		}
		if(tab[0][i]==joueur2.symbole && tab[1][i]==joueur2.symbole && tab[2][i]==joueur2.symbole){
			return joueur2.symbole;
		}
	}
    
    
    //Verifie la diagonale//
    
    if(tab[1][1]==joueur1.symbole){
    	if(tab[0][0]==joueur1.symbole && tab[2][2]==joueur1.symbole){
    		return joueur1.symbole;
    	}
    	if(tab[2][0]==joueur1.symbole && tab[0][2]==joueur1.symbole){
    		return joueur1.symbole;
    	}
    }else{
        if(tab[1][1]==joueur2.symbole){
        	if(tab[0][0]==joueur2.symbole && tab[2][2]==joueur2.symbole){
        		return joueur2.symbole;
        	}
        	if(tab[2][0]==joueur2.symbole && tab[0][2]==joueur2.symbole){
        		return joueur2.symbole;
        	    
        	}
        }
    }
    return 0;

}
/

int main(int argc, char** argv){
	int a,b;
	int tour;
	char whowin;
	joueur joueur1;/*pointeur pour la variable structurée */
	joueur joueur2;
	tour=1;
	joueur2.symbole='O';
	joueur1.symbole='X';
	printf("Entrez age du joueur1 \n");
	scanf("%d" ,&joueur1.age);
	printf("Entre age du joueur2 \n");
	scanf("%d" ,&joueur2.age);

	char tab[3][3]={{'_','_','_'},{'_','_','_'},{'_','_','_'}};
    do{
        do{
            do{
                printf("Choisir votre ligne ( entre 1 et 3). \n");
                scanf("%d", &a);
                if(a>3 ||a<1){
                    printf("Le nombre saisie n'est pas entre 1 et 3. \n");
                }
            }while(a>3 ||a<1);
            do{
                printf("Choisir votre colonne (entre 1 et 3). \n");
                scanf("%d",&b);
                if(b>3 ||b<1){
                    printf("Le nombre saisie n'est pas entre 1 et 3. \n");
                }
            }while (b>3 || b<1);
            a= a-1;
            b= b-1;
            if ((tab[a][b]=='X') || (tab[a][b]=='O')){
                printf("La case saisie est déja compléter \n");
            }
        }while((tab[a][b]=='X') || (tab[a][b]=='O'));
        modiftab(tab,joueur1, a,b,joueur2,tour);
    	afftableau(tab);
    	whowin =verifgagnant(tab,joueur1,joueur2);
    	tour++;
    }while(tour<10 && whowin!='X' && whowin!='O');
    if (whowin==0){
        printf("Match nul \n");
    }else{
        printf("Le gagnant est %c \n",whowin);
    }
return 0;	
}


