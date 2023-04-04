#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 4
#define NUM_COLORS 6

int main(void) {
    
    //Variables
    bool won;
    int sequence[LENGTH];
    int guesses = 0;
    int guess[LENGTH];
    bool correct[LENGTH] = {false};
    bool present[LENGTH] = {false};

    // Génération de la séquence de couleurs à deviner
    for (int i = 0; i < LENGTH; i++) {
        sequence[i] = rand() % NUM_COLORS;
    }

    // Boucle de jeu
    while (guesses < 10) {
        printf("Entrez votre combinaison de couleurs: "); // Demande de la combinaison de couleurs au joueur
        for (int i = 0; i < LENGTH; i++) {
            scanf("%d", &guess[i]);
        }

        // Vérification de la combinaison
        for (int i = 0; i < LENGTH; i++) {
            if (guess[i] == sequence[i]) {
                correct[i] = true;
            } else {
                for (int j = 0; j < LENGTH; j++) {
                    if (!correct[j] && guess[i] == sequence[j]) {
                        present[j] = true;
                    }
                }
            }
        }

        // Affichage du résultat
        printf("Couleurs placées correctement: ");
        for (int i = 0; i < LENGTH; i++) {
            if (correct[i]) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
        printf("Couleurs présentes, mais mal placées: ");
        for (int i = 0; i < LENGTH; i++) {
            if (present[i]) {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        // Vérification de la fin de la partie
        for (int i = 0; i < LENGTH; i++) {
            if (!correct[i]) {
                won = false;
                break;
            }
        }
        if (won) {
            printf("Félicitations! Vous avez deviné la séquence en %d tours.\n", guesses + 1);
            break;
        }

        guesses++;
    }
    if (!won) {
        printf("Désolé, vous avez épuisé le nombre de tours autorisés sans deviner la séquence.\n");
    }

    return 0;
}