#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  const int KM_NORM_MIN = 10;
  const int KM_NORM_MAX = 15;
  const int KMVOYAGE = 300;
  const int KM_RAP_MIN = 20;
  const int KM_RAP_MAX = 25;
  const int AVANTAGEVOYAGEUR = 30;
  const int GOURDE_PLEINE = 12;
  const int MORT_SOIF = 10;
  const int MORT_FATIGUE = 15;
  const int DIF_AIDE = 3;
  const int AVANCE_NATIFS = 4;

  bool nextGame = true;
  int nbPartie = 0;

  while (nextGame == true) {
    nbPartie++;

    printf("\n\n");
    printf("\t\tBONJOUR DANS LE JEU DU CHAMEAU !! \n\n");

    int km_voyageur = 0;
    int km_natifs = km_voyageur - AVANTAGEVOYAGEUR;
    int gourde = GOURDE_PLEINE / 2;
    double soif = 0;
    double fatigue = 0;
    int groude_fill = 5;

    double soifProgress = 0;
    double fatigueProgress = 0;

    bool chosingDif = false;
    int difficulty = 0;
    bool isplayerAlive = true;

    int nbGourdBu = 0;
    int nbAide = 0;
    int nbRepos = 0;
    int nbAvanc = 0;
    int nbAvancRapide = 0;
    int nbAideSucses = 0;

    while (chosingDif == false) {
      printf("\n============================\n");
      printf("  CHOISISSEZ LA DIFFICULTÉ\n");
      printf("============================\n");

      printf("1 - Facile   (faible fatigue & soif)\n");
      printf("2 - Normal   (équilibré)\n");
      printf("3 - Difficile (fatigue & soif rapides)\n");
      printf("Votre choix : ");

      scanf("%d", &difficulty);

      switch (difficulty) {
      case 1:
        soifProgress = 0.25;
        fatigueProgress = 0.25;
        printf("Mode Facile sélectionné !\n");
        chosingDif = true;
        break;

      case 2:
        soifProgress = 0.5;
        fatigueProgress = 0.5;
        printf("Mode Normal sélectionné !\n");
        chosingDif = true;
        break;

      case 3:
        soifProgress = 1.0;
        fatigueProgress = 1.0;
        printf("Mode Difficile sélectionné !\n");
        chosingDif = true;
        break;

      default:

        printf("OPSIE ! %d n'est pas une option valide.\n", difficulty);
      }
    }

    printf("\n");
    printf("LE JEU DU CHAMEAU \n\n");
    printf("|------------------------------------------------------------------"
           "-------|\n");
    printf("| Vous avez vole un chameau pour traverser le grand desert. Les "
           "natifs    |\n");
    printf("| veulent le recuperer. Votre objectif est de survivre `a la "
           "traversee de |\n");
    printf("| 300 km sans etre attrape(e).                                     "
           "       |\n");
    printf("|------------------------------------------------------------------"
           "-------|\n");

    bool isplaying = true;
    bool isnextTurn = false;

    while (isplaying == true && isplayerAlive == true) {

      char choice;
      printf("\n\n\n");
      printf("OPTIONS :\n");
      printf("1. Boire\n");
      printf("2. Avancer normalement\n");
      printf("3. Avancer a toute vitesse\n");
      printf("4. Repos\n");
      printf("5. Esperer de l aide\n");
      printf("T. Terminer la partie \n");
      printf("\n\n");
      printf("Qu allez-vous faire ? ");

      scanf(" %c", &choice); // c skips spaces and white lines

      switch (choice) {
      case '1': // boire
        if (gourde == 0) {
          printf("\nLa gourde est vide !\n");
        } else if (soif <= 0) {
          printf("Pas de soif, pas de boisson !\n");
        } else {
          printf("\nVous avez bu une gorgée\n");
          soif = 0;
          gourde--;
          isnextTurn = true;
          nbGourdBu++;
        }
        break;

      case '2': // normal
        km_voyageur += rand() % (KM_NORM_MAX - KM_NORM_MIN + 1) + KM_NORM_MIN;
        fatigue += fatigueProgress;
        nbAvanc++;
        isnextTurn = true;
        break;

      case '3': // rapide
        km_voyageur += rand() % (KM_RAP_MAX - KM_RAP_MIN + 1) + KM_RAP_MIN;
        fatigue += fatigueProgress * 1.5;
        soif += 0.5;
        nbAvancRapide++;
        isnextTurn = true;
        break;

      case '4': // repos
        printf("Votre chameau s'est bien repose\n");
        fatigue = 0;
        isnextTurn = true;
        nbRepos++;
        break;

      case '5': // help
        if (gourde >= GOURDE_PLEINE) {
          printf("La gourde est deja pleine !\n");
        } else {
          printf("Vous espérez de l'aide...\n");
          nbAide++;
          int tmp = rand() % DIF_AIDE;
          if (tmp == 0) {
            printf("Vous avez trouvé de l'aide !!\n");
            nbAideSucses++;
            gourde += groude_fill;

            if (gourde > GOURDE_PLEINE) {
              gourde = GOURDE_PLEINE;
            }
          } else {
            printf("Vous n'avez pas trouvé d'aide...\n");
          }
        }

        isnextTurn = true;
        break;

      case 'T':
      case 't':
        printf("Vous terminez la partie.\n");
        isplaying = false;
        break;

      default:
        printf("OPSIE ! '%c' n'est pas une option valide.\n", choice);
        break;
      }

      if (isnextTurn == true && isplayerAlive == true) {
        int distanceRest = KMVOYAGE - km_voyageur;
        printf("\n=========================\n");
        printf("       PROGRESSION       \n");
        printf("=========================\n");

        printf("Vous avez parcouru : %d km sur %d.\n", km_voyageur, KMVOYAGE);

        printf("La distance restant est : %d km.\n", distanceRest);
        printf("État actuel : Soif %.1f | Fatigue %.1f | Gourde %d/%d\n", soif,
               fatigue, gourde, GOURDE_PLEINE);

        soif += soifProgress;
        isnextTurn = false;

        km_natifs += AVANCE_NATIFS;

        int distanceNatifs = km_voyageur - km_natifs;

        if (distanceNatifs > 50) {
          printf("Les natifs sont très loin derrière vous... pour l instant. "
                 "Rattrapage imminent dans %d km\n",
                 distanceNatifs);
        } else if (distanceNatifs > 20) {
          printf("Les natifs se rapprochent, vous devez rester vigilant ! "
                 "Rattrapage imminent dans %d km\n",
                 distanceNatifs);
        } else if (distanceNatifs > 0) {
          printf("Les natifs sont tout près ! Vous entendez presque leurs pas "
                 ". Rattrapage imminent dans %d km\n",
                 distanceNatifs);
        } else {
          printf("Les natifs vous ont rattrapé ! Fin de la partie...\n");
          isplayerAlive = false;
        }
      }

      if ((soif >= MORT_SOIF || fatigue >= MORT_FATIGUE) && isplayerAlive) {
        isplayerAlive = false;

        printf("\n========================\n");
        printf("        GAME OVER         \n");
        printf("=========================\n");

        if (soif >= MORT_SOIF) {
          printf("Vous avez succombé à une soif insupportable...\n");
        } else {
          printf("Votre corps n'a pas supporté l'épuisement...\n");
        }

        printf("The desert claims another victim.\n");
      }
      if (km_voyageur >= KMVOYAGE && isplayerAlive == true) {

        printf("\n\n \tCONGRATIOLATION YOU HAVE WON \n\n");

        isplayerAlive = false;
      }
    }

    if (isplayerAlive == false) {

      int P = 0;
      printf("Voulez-vous jouer une nouvelle partie ? \n");
      printf("1. Oui\n");
      printf("2. Non\n");
      printf("Qu allez-vous faire ? ");
      scanf("%d", &P);

      switch (P) {
      case 1:

        nextGame = true;
        isplayerAlive = true;
        break;

      case 2:

        nextGame = false;
        printf("\n=================================\n");
        printf("           VOUS AVEZ GAGNÉ        \n");
        printf("=================================\n");
        printf("Merci d'avoir joué, j'espère que vous avez apprécié !\n\n");
        printf("Vos statistiques :\n");
        printf("  • Nombre de parties jouées     : %d\n", nbPartie);
        printf("  • Gourdes bues                 : %d\n", nbGourdBu);
        printf("  • Avancées effectuées          : %d\n", nbAvanc);
        printf("  • Avancées rapides effectuées  : %d\n", nbAvancRapide);
        printf("  • Aides réussies               : %d / %d\n", nbAideSucses,
               nbAide);
        printf("  • Nombre des repos effectuer   : %d\n", nbRepos);

        break;

      default:

        printf("OPSIE ! '%c' n'est pas une option valide.\n", P);
        break;
      }
    }
  }

  return 0;
}
