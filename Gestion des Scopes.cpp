#include <stdio.h>

#define MAX_PRODUCTS 100

void ajouterProduit(int codes[], int quantites[], int numProduits) {
    int code, quantite;

    printf("Entrez le code du produit : ");
    scanf("%d", &code);

    printf("Entrez la quantite a ajouter : ");
    scanf("%d", &quantite);

    for (int i = 0; i < numProduits; i++) {
        if (codes[i] == code) {
            quantites[i] += quantite;
            printf("Quantite ajoutee avec succes.\n");
            return;
        }
    }

    codes[numProduits] = code;
    quantites[numProduits] = quantite;
    printf("Produit ajoute avec succes.\n");
}

void retirerProduit(int codes[], int quantites[], int numProduits) {
    int code, quantite;

    printf("Entrez le code du produit : ");
    scanf("%d", &code);

    for (int i = 0; i < numProduits; i++) {
        if (codes[i] == code) {
            printf("Entrez la quantité à retirer : ");
            scanf("%d", &quantite);

            if (quantite > quantites[i]) {
                printf("La quantite a retirer depasse le stock disponible.\n");
            } else {
                quantites[i] -= quantite;
                printf("Quantite retiree avec succes.\n");
            }
            return;
        }
    }

    printf("Produit non trouve\n");
}

void afficherStock(int codes[], int quantites[], int numProduits) {
    printf("Stock total :\n");

    for (int i = 0; i < numProduits; i++) {
        if (quantites[i] > 0) {
        	printf("\n===============================================\n");
            printf("Code du produit : %d | Quantite en stock : %d\n", codes[i], quantites[i]);
            printf("===============================================\n");
        }
    }
}

int main() {
    int codesProduit[MAX_PRODUCTS];
    int quantitesProduit[MAX_PRODUCTS];
    int numProduits = 0;
    char choix;

    do {
        printf("\n========== Menu ========== :\n");
        printf("1. Ajouter un produit au stock\n");
        printf("2. Retirer un produit du stock\n");
        printf("3. Afficher le stock total\n");
        printf("4. Quitter\n");

        printf("Choisissez une operation : ");
        scanf(" %c", &choix);

        switch (choix) {
            case '1':
                ajouterProduit(codesProduit, quantitesProduit, numProduits);
                numProduits++;
                break;
            case '2':
                retirerProduit(codesProduit, quantitesProduit, numProduits);
                break;
            case '3':
                afficherStock(codesProduit, quantitesProduit, numProduits);
                break;
            case '4':
                printf("Programme termine.\n");
                break;
            default:
                printf("Choix invalide. Veuillez choisir une operation valide.\n");
        }
    } while (choix != '4');

    return 0;
}

