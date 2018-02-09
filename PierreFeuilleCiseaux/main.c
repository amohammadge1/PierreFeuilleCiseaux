#include <stdio.h>
#include <stdlib.h>


// Code source du jeu Pierre, Feuille, Ciseaux
// Par Jeremy DEMANGE et Laetitia DIONISI

int main()
{

    // Les variables du projet
    char choixDuJoueur; // Il tapera soit P, F ou C.
    char choixDuRobot; // Il choissira un chiffre entre 1 (P) et 3 (C).
    int score =0, nombreAuHasard = 0, quitter = 1, robot = 0; // On initialise le score et le nombre d'essai a 0.

    // Choix du nombre au hasard
    srand(time(NULL)); // Initialisation de la fonction rand
    
    
    // Ici debute la boucle du jeu
    do {
    
    nombreAuHasard = (rand() % (3 - 1 + 1)) + 1; // On choisit un nombre entre 1 et 3

    // On interprete le choix du robot
    if (nombreAuHasard == 1)
    {
        choixDuRobot = 'P';
    }
    else if (nombreAuHasard == 2)
    {
        choixDuRobot = 'F';
    }
    else if (nombreAuHasard == 3)
    {
        choixDuRobot = 'C';
    }


    // Le jeu
    printf("Choissisez P, F, C pour Pierre, Feuille, Ciseaux (saisissez Q pour quitter) : ");
    fflush(stdin);
    scanf("%c",&choixDuJoueur);//le joueur rentre son choix
    fflush(stdin);
    if(choixDuJoueur == 'P' || choixDuJoueur =='p'|| choixDuJoueur == 'F' || choixDuJoueur =='f' || choixDuJoueur == 'C' || choixDuJoueur =='c')
    {
        printf("Vous avez choisi "); //on affiche le choix du joueur
        if (choixDuJoueur =='P' || choixDuJoueur =='p')
        {
            printf("\nPierre\n");
            choixDuJoueur = 'P';
        }
        else if (choixDuJoueur == 'F' || choixDuJoueur =='f')
        {
            printf("\nFeuille\n");
            choixDuJoueur = 'F';
        }
        else if (choixDuJoueur == 'C' || choixDuJoueur =='c')
        {
            printf("\nCiseaux\n");
            choixDuJoueur = 'C';
        }
    }
    else if (choixDuJoueur == 'Q' || choixDuJoueur == 'q') 
    {
        quitter = 0;
    }
    else
    {
        printf("Votre saisie n'est pas valable, veuillez reesayer avec P, F, ou C\n");     //message d'erreur si le mauvais caractère est rentré
    }



    //Interpretation du resultat
    // Egalite
    if (choixDuJoueur == choixDuRobot)
    {
        printf("%c contre %c : Egalite parfaite !\n", choixDuJoueur, choixDuRobot);
    }

    // Si joueur = pierre
    else if (choixDuJoueur == 'P' )
    {
        if (choixDuRobot == 'F')
        {
            printf("La feuille recouvre la pierre, vous perdez la manche\n");
            robot++;
        }
        else if (choixDuRobot == 'C')
        {
            score++;
            printf("La pierre casse le ciseaux, vous gagnez la manche\n");

        }
    }

    // Si joueur = feuille
    else if (choixDuJoueur == 'F' )
    {
        if (choixDuRobot == 'P')
        {
            score++;
            printf("La feuille recouvre la pierre, vous gagnez la manche\n");

        }
        else if (choixDuRobot == 'C')
        {
            printf("Le ciseaux coupe la feuille, vous perdez la manche\n");
            robot++;
        }
    }

    // Si joueur = ciseaux
    else if (choixDuJoueur == 'C' )
    {
        if (choixDuRobot == 'P')
        {
            printf("La pierre casse le ciseaux, vous perdez la manche\n");
            robot++;
        }
        else if (choixDuRobot == 'F')
        {
            score++;
            printf("Le ciseaux coupe la feuille, vous gagnez la manche\n");
        }
    }
    
    // On affiche le score
    printf("\nScore du robot : %d\nVotre score : %d\n\n", robot, score);
    
    // Ici s'arrete la boucle du jeu
    } while (quitter == 1);
    
    // On compare les resultats
    if (score > robot)
        {
        printf("Vous avez gagne la partie avec un score de %d contre un score de %d pour le robot\n\n",score,robot);
        }
    else if (score < robot)   
        {
        printf("Vous avez perdu la partie avec un score de %d contre un score de %d pour le robot\n\n",score,robot);
        }
    else 
        {
        printf("Vous terminez la partie sur une egalite\n\n");
        }
    

    // Fin du code
    return 0;
}
