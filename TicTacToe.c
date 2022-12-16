#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

/*********************************************************************************************************************/
/*************************************| welcome in morpoion game |***************************************************/

void affiche_logo()
{
	printf("\n\n");
	printf("\t\t\t***********************************************************\n");
	printf("\t\t\t*                                                         *\n");
	printf("\t\t\t*               WELCOM IN MORPION GAME                    *\n");
	printf("\t\t\t*                      ENJOY :)                           *\n");
	printf("\t\t\t*                                                         *\n");
	printf("\t\t\t***********************************************************\n");
	printf("\n\n");	
}
/*********************************************************************************************************************/


/*********************************************************************************************************************/
/****************************| structe for introduce playres data |***************************************************/

struct joueurs
{
	char nom[20];
	short age;
	short nombre_des_victoires;
	short nombre_de_patiesjouee;
	char style; // X or O
};
typedef struct joueurs joueur;

/*********************************************************************************************************************/
 
 
/*********************************************************************************************************************/
/*****************************| functions for input  playres data |***************************************************/ 
 
void* saissir_joueur(joueur *j)
{
    printf("---le joueur de style  ' O ' entrer votre nome  : \n ");
    scanf("%s",j->nom);	
}

void* saissir_joueur2(joueur *j2)
{
    printf("\n\n---le joueur de style  ' X ' entrer votre nome  : \n ");
    scanf("%s",j2->nom);
}

/*********************************************************************************************************************/


/*********************************************************************************************************************/
/*******************************| struct for introduce game data |***************************************************/

struct jeux
{
joueur J1,J2;	
short nemuro_de_jeu;
	
};
typedef struct jeux jeux;

/*********************************************************************************************************************/


/*********************************************************************************************************************/
/****************************| function for creat & initialise the matrix of game  |**********************************/
 

char** initialise_le_jeu()
{
	int i;
	char **matrice;
	matrice=(char**)malloc(3*sizeof(char*));
	for(i=0;i<3;i++)	matrice[i]=(char*)malloc(3*sizeof(char));
	
       matrice[0][0]='1';
       matrice[0][1]='2';
       matrice[0][2]='3';
       matrice[1][0]='4';
       matrice[1][1]='5';
       matrice[1][2]='6';
       matrice[2][0]='7';
       matrice[2][1]='8';
       matrice[2][2]='9';
    return matrice;
}
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/****************************| function for input X or O & test if the choise not wrong|******************************/


void** changing(char **T,char st,int choix ,jeux J)
{
int n;
    if(choix<=3)   /*si le choix est : 1,2,3  */ 
	{
	  if(T[0][choix-1] == 'X')      /* l'etat de case n'est pas vide */
	  {
	           printf("\n\tEREUR !! \n ----la case est deja plane \a\n\n\n"); free(T);   T=initialise_le_jeu(); 	
		       printf("----tapez 1 to replay the game  : \n");
		       printf("----tapez another key to cancel : \n");
		       scanf("%d",&n);
		       goto_fonctoin(n,J,T);  
	  }
	    else if(T[0][choix-1] == 'O')     
		{
		       printf("\n\tEREUR !! \n ----la case est deja plane \a\n\n\n"); free(T);   T=initialise_le_jeu(); 	
		       printf("----tapez 1 to replay the game  : \n");
		       printf("----tapez another key to cancel : \n");
		       scanf("%d",&n);
		       goto_fonctoin(n,J,T);
		}
	      else    T[0][choix-1]=st;    
	}
    if(choix<=6)   
	{
	  if(T[1][choix-4] == 'X')      
        {
		       printf("\n\tEREUR !! \n ----la case est deja plane \a\n\n\n"); free(T);   T=initialise_le_jeu(); 	
		       printf("----tapez 1 to replay the game  : \n");
		       printf("----tapez another key to cancel : \n");
		       scanf("%d",&n);
		       goto_fonctoin(n,J,T);
		}
	    else if(T[1][choix-4] == 'O')     
		  {
		       printf("\n\tEREUR !! \n ----la case est deja plane \a\n\n\n"); free(T);   T=initialise_le_jeu(); 	
		       printf("----tapez 1 to replay the game  : \n");
		       printf("----tapez another key to cancel : \n");
		       scanf("%d",&n);
		       goto_fonctoin(n,J,T);
		  }
	      else    T[1][choix-4]=st;   
	}
    if(choix<=9)    
	{
	  if(T[2][choix-7] == 'X')      
	  {
	           printf("\n\tEREUR !! \n ----la case est deja plane \a\n\n\n"); free(T);   T=initialise_le_jeu(); 	
		       printf("----tapez 1 to replay the game  : \n");
		       printf("----tapez another key to cancel : \n");
		       scanf("%d",&n);
		       goto_fonctoin(n,J,T);
	  }
	    else if(T[2][choix-7] == 'O')     
		{      
		       printf("\n\tEREUR !! \n ----la case est deja plane \a\n\n\n"); free(T);   T=initialise_le_jeu(); 	
		       printf("----tapez 1 to replay the game  : \n");
		       printf("----tapez another key to cancel : \n");
		       scanf("%d",&n);
		       goto_fonctoin(n,J,T);
		}
	      else    T[2][choix-7]=st;  
	}   
}


/*********************************************************************************************************************/
/********************************************| function for display the table of game |******************************/

 void** afficher_tableau (char **T)
{
	int i,j;
 	printf("\n\n");
 	for(i=0;i<3;i++)
     {
     	j=0;
      printf("\t\t\t*******************\n");
      
      printf("\t\t\t|  %c  |  %c  |  %c  |\n",T[i][j],T[i][j+1],T[i][j+2]);
     	
     }
      printf("\t\t\t********************\n");
	        }
	
/*********************************************************************************************************************/


/*********************************************************************************************************************/
/***************************************************| function for search for a winner|******************************/

void** win(char **T, jeux J,int d)
{
	int n;
		if((T[0][0]==T[0][1])&&(T[0][1]==T[0][2]))      
		{
		       printf("\n\t\t\t\t----player %d is win---- \n\n ",d);  free(T);     T=initialise_le_jeu(); 
		       printf("----tapez 1 to replay the game  : \n");
		       printf("----tapez another key to cancel : \n");
		       scanf("%d",&n);
		       goto_fonctoin(n,J,T);
		}
		if((T[1][0]==T[1][1])&&(T[1][1]==T[1][2]))    
		{
		       printf("\n\t\t\t\t----player %d is win---- \n\n ",d);  free(T);   T=initialise_le_jeu(); 	
		       printf("----tapez 1 to replay the game  : \n");
		       printf("----tapez another key to cancel : \n");
		       scanf("%d",&n);
		       goto_fonctoin(n,J,T);}
		if((T[2][0]==T[2][1])&&(T[2][1]==T[2][2]))    
		{
		       printf("\n\t\t\t\t----player %d is win---- \n\n ",d);  free(T);    T=initialise_le_jeu(); 	
			   printf("----tapez 1 to replay the game  : \n");
		       printf("----tapez another key to cancel : \n");
		       scanf("%d",&n);
		       goto_fonctoin(n,J,T);
		}
		if((T[0][0]==T[1][0])&&(T[1][0]==T[2][0]))  
		{
		       printf("\n\t\t\t\t----player %d is win---- \n\n ",d);  free(T);  T=initialise_le_jeu(); 	
			   printf("----tapez 1 to replay the game  : \n");
		       printf("----tapez another key to cancel : \n");
		       scanf("%d",&n);
		       goto_fonctoin(n,J,T);
		}
		if((T[0][1]==T[1][1])&&(T[1][1]==T[2][1]))    
		{
		        printf("\n\t\t\t\t----player %d is win---- \n\n ",d);  free(T);  T=initialise_le_jeu(); 	
				printf("----tapez 1 to replay the game  : \n");
		        printf("----tapez another key to cancel : \n");
		        scanf("%d",&n);
		        goto_fonctoin(n,J,T);}
		if((T[0][2]==T[1][2])&&(T[1][2]==T[2][2]))    
		{
		        printf("\n\t\t\t\t\t\t\t----player %d is win---- \n\n ",d);  free(T);   T=initialise_le_jeu(); 	
				printf("----tapez 1 to replay the game  : \n");
		        printf("----tapez another key to cancel : \n");
		        scanf("%d",&n);
		        goto_fonctoin(n,J,T);}
		if((T[0][0]==T[1][1])&&(T[1][1]==T[2][2]))    
		{
		        printf("\n\t\t\t\t\t\t\t----player %d is win---- \n\n ",d);  free(T);   T=initialise_le_jeu(); 	
				printf("----tapez 1 to replay the game  : \n");
		        printf("----tapez another key to cancel : \n");
		        scanf("%d",&n);
		        goto_fonctoin(n,J,T);}
	    if((T[0][2]==T[1][1])&&(T[1][1]==T[2][0]))   
		{
		        printf("\n\t\t\t\t\t\t\t----player %d is win---- \n\n ",d);  free(T);    T=initialise_le_jeu(); 	
				printf("----tapez 1 to replay the game  : \n");
		        printf("----tapez another key to cancel : \n");
		        scanf("%d",&n);
		        goto_fonctoin(n,J,T);}
}                                                                                    

/*********************************************************************************************************************/
/****************************| functions for switch turns between the two players |***********************************/

void le_jeu(jeux J, char **matrice)
{
	int choix,i;
		for(i=0;i<9;i++)
	{
		system("cls");
			printf("----le style de %s est  : %c  \n",J.J1.nom,J.J1.style);
	        printf("----le style de %s est  : %c  \n",J.J2.nom,J.J2.style);
    afficher_tableau(matrice);
     if( i%2 == 0)   
	  {	
	    printf("\n * %s * entrer votre nombre : ",J.J1.nom);
	 	scanf("%d",&choix);
	    changing(matrice,J.J1.style,choix,J);
	    win(matrice,J,1);
	 
	  }
	 if( i%2 != 0) 
	  {
	 	printf(" \n * %s * entrer votre nombre : ",J.J2.nom);
	 	scanf("%d",&choix);
        changing(matrice,J.J2.style,choix,J);
		win(matrice,J,2);
	
	  }
    }  
}

void le_jeu_2(jeux J, char** matrice)
{
	int n;
	while(J.nemuro_de_jeu != 0)
      {
		le_jeu(J,matrice);
		system("cls");
		free(matrice);
	    matrice=initialise_le_jeu();
		printf("----tapez 1 to replay the game  : \n");
		printf("----tapez another key to cancel : \n");
		scanf("%d",&n);
		if(n == 1)   J.nemuro_de_jeu++;
		else if(n != 1) J.nemuro_de_jeu = 0;
	  }	
}

/*********************************************************************************************************************/

/*********************************************************************************************************************/
/****************************| function for replay game if you want to |*********************************************/

goto_fonctoin(int n,jeux J, char** matrice)
{
	if(n == 1)
	 goto fonctoin;
	 exit(0);
	 fonctoin: 
	   le_jeu_2(J,matrice); 
}
/*********************************************************************************************************************/


/********************************************************************************************************************************************/
/***************************************le programe prancipale :  **************************************************************************/ 
/*******************************************************************************************************************************************/
int main(int argc, char *argv[]) 
{
	system("COLOR 02");
	char **matrice; 
	jeux J;
	affiche_logo();
	saissir_joueur(&(J.J1));
	saissir_joueur2(&(J.J2));
	 if(J.J1.style='X')    J.J2.style='O';
     if(J.J1.style='O')    J.J2.style='X';
	matrice=initialise_le_jeu();
    le_jeu_2(J,matrice);
    system("PAUSE");
	return 0;
}
