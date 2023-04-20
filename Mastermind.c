#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAILLE 4

// Fonction qui génère la séquence de couleurs à deviner
void generer(int sequence[TAILLE]){
    for (int i = 0; i < TAILLE; i++) {
        sequence[i] = rand() % 6;
    }
}

//Fonction qui affiche le jeu
void affJeu(int correct[TAILLE], int present[TAILLE]){
    printf("Couleurs placées correctement: ");
    for (int i = 0; i < TAILLE; i++) {
        if (correct[i]) {
            printf("✓ ");
        } else {
            printf("X ");
        }
    }
    printf("\n");
    printf("Couleurs présentes, mais mal placées: ");
    for (int i = 0; i < TAILLE; i++) {
        if (present[i]) {
            printf("O ");
        } else {
            printf("_ ");
        }
    }
    printf("\n\n");
}

//Fonction qui vérifie la combinaison
void verification(int sequence[TAILLE], int guess[TAILLE], int correct[TAILLE], int present[TAILLE]){
    // Réinitialiser les tableaux
    for (int i = 0; i < TAILLE; i++) {
        correct[i] = 0;
        present[i] = 0;
    }
    
    for (int i = 0; i < TAILLE; i++) {
        if (guess[i] == sequence[i]) {
            correct[i] = 1;
        } else {
            for (int j = 0; j < TAILLE; j++) {
                if (!correct[j] && !present[j] && guess[i] == sequence[j] && i != j) {
                    present[j] = 1;
                    break;
                }
            }
        }
    }
}

//Fonction qui vérifie si un joueur a gagné
bool gagne(int correct[TAILLE]){
    for (int i = 0; i < TAILLE; i++) {
        if (!correct[i]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    //Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    
    //Variables
    int sequence[TAILLE];
    int guess[TAILLE];
    int correct[TAILLE];
    int present[TAILLE];
    int guesses = 0;

    generer(sequence);

    // Boucle de jeu
    while (guesses < 10) {
        printf("Entrez votre combinaison de 4 couleurs (0-5) *mettre des espaces*: ");
        for (int i = 0; i < TAILLE; i++) {
            scanf("%d", &guess[i]);
        }
        verification(sequence, guess, correct, present);
        affJeu(correct, present);

        if (gagne(correct)) {
            printf("Félicitations! Vous avez deviné la séquence en %d tours.\n\n", guesses + 1);
            return 0;
        }

        guesses++;
    }

    printf("Désolé, vous avez épuisé le nombre de tours autorisés sans deviner la séquence.\n\n");

    return 0;
}
