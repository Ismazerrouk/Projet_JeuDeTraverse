#include <stdio.h>
#include <stdlib.h>
#define M 10
#define N 10
int tableau[M][N];
int ligne;
int colonne;

 // Initialisation d'une grille de réels de taille [M][N]
/*void initGrille() {
    for (int i=0; i<1; i++) {
        int h = 0;
        int f = 0;
        for (int j=0; j<5; j++) { //ON crée les 4 premiers pions du J1
            tableau[i][j] = 0+h;
            h++;
        }
        for(int j = 5; j<N; j++){ //On crée les 4 autres pions du J1
            tableau [i][j]= 4-f;
            f++;
        }
    }
    for (int i = 1; i<M-1 ;i++){
        for (int j = 0; j<N; j++){
            tableau[i][j] = 0;
        }
    }
    for (int i = M-1; i<M ; i++){
        int k =0;
        int l = 0;
        for(int j=0; j<5 ; j++){
            tableau[i][j] = 0+k;
            k++;
        }
        for(int j = 5; j<N ; j++){
            tableau[i][j]= 4-l;
            l++;
        }
    }

}*/

 // Initialisation d'une grille de réels de taille [M][N]
void initGrille() {
    for (int i=0; i<1; i++) {
        int h = 0;
        int f = 0;
        for (int j=0; j<5; j++) { //ON crée les 4 premiers pions du J1
            tableau[i][j] = 0+h;
            h++;
        }
        for(int j = 5; j<N; j++){ //On crée les 4 autres pions du J1
            tableau [i][j]= 4-f;
            f++;
        }
    }
    for (int i = 1; i<M-1 ;i++){
        for (int j = 0; j<N; j++){
            tableau[i][j] = 0;
        }
    }
    for (int i = M-1; i<M ; i++){
        int k = 0;
        int l = 0;
        for(int j=1; j<9 ; j++){
            tableau[i][j] = 5+k;
            k++;
        }
        for(int j = 5; j<N-1 ; j++){
            tableau[i][j]= 8-l;
            l++;
        }
    }

}

// Affichage d'un tableau à 2 dimensions
/*void afficheGrille() {
    printf("Affichage d'un tableau 2D de taille %d,%d : \n",M,N);
    for (int i=0; i<M; i++) {
        printf("|");
        for (int j=0; j<N; j++) {
            printf("|%d|",tableau[i][j]);
        }
        printf("| \n");
    }
}*/

/*void afficheGrille() {
    printf("Affichage d'un tableau 2D de taille %d,%d : \n",M,N);
    for (int i=0; i<M; i++) {
        printf("|");
        for (int j=0; j<N; j++) {
                if(tableau[i][j]==0){            printf("| |",tableau[i][j]);}

         else{   printf("|%d|",tableau[i][j]);}
        }
        printf("| \n");
    }
}*/
void afficheGrille() {
    printf("Affichage d'un tableau 2D de taille %d,%d : \n",M,N);
    for (int i=0; i<M; i++) {
        printf("|");
        for (int j=0; j<N; j++) {
            switch (tableau[i][j])
            {
            case 1:
            printf("| c |");
            break;
            case 2:
            printf("| t |");
            break;
            case 3:
            printf("| l |");
            break;
            case 4:
            printf("| o |");
            break;
            case 5:
            printf("| C |");
            break;
            case 6:
            printf("| T |");
            break;
            case 7:
            printf("| L |");
            break;
            case 8:
            printf("| O |");
            break;
            default:
                        printf("|   |");
                        break;
}

        }
        printf("| \n");
    }
}

void coupparcoupJ1(){
    int z;
    printf("Vous etes le joueur 1.\n Choisissez un pion a jouer :\n 1.Carre\n 2.Triangle\n 3.Losange\n 4.Rond\n");
    scanf("%d",&z);
    switch(z){
        case 1:
                printf("Saisissez la ligne de votre carre\n");
                scanf("%d",&ligne);
                printf("Saisissez la colonne de votre carre\n");
                scanf("%d",&colonne);
                CarreJ1(ligne, colonne);
        break;
        case 2: TriangleJ1();
        break;
        case 3: LosangeJ1();
        break;
        case 4: RondJ1();
        break;
        }
}

void CarreJ1(){
    int e;
    printf("Ou voulez vous jouer votre carre (1) ?\n 1.Tout droit\n 2.A votre gauche\n 3.A votre droite\n 4.En arriere\n");
    scanf("%d",&e);
    switch(e){

    case 1:
            CarretoutdroitJ1(ligne,colonne);
    break;

    case 2 : CarreaGaucheJ1(ligne,colonne);
    break;

    case 3 : CarreaDroiteJ1();
    break;

    case 4 : CarreArriereJ1();
    break;


    }
}


void CarretoutdroitJ1(ligne,colonne){
    int compteur = 1;
    //int colonne;
    /*printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);*/
    if (tableau[ligne + 1][colonne] == 0 && tableau[ligne][colonne] == 1)
        {
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne] = 1;
        }

    else if(tableau[ligne + 1][colonne] == 1 || tableau[ligne + 1][colonne] == 2 ||
             tableau[ligne + 1][colonne] == 3 || tableau[ligne + 1][colonne] == 4 || tableau[ligne + 1][colonne] == 5 ||
             tableau[ligne + 1][colonne] == 6 || tableau[ligne + 1][colonne] == 6 || tableau[ligne + 1][colonne] == 7
             || tableau[ligne + 1][colonne] == 8)
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne] == 1 || tableau[ligne + compteur][colonne] == 2 || tableau[ligne + compteur][colonne] == 3 || tableau[ligne + compteur][colonne] == 4 || tableau[ligne + compteur][colonne] == 5 ||
             tableau[ligne + compteur][colonne] == 6  || tableau[ligne + compteur][colonne] == 7
             || tableau[ligne + compteur][colonne] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne] = 1;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        CarretoutdroitJ1();
    }

}

void CarreaGaucheJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);

    if (tableau[ligne][colonne - 1] == 0 && tableau[ligne][colonne] == 1 )
        {
        tableau[ligne][colonne] = 0;
        tableau[ligne][colonne - 1] = 1;
        }
    /*else if (tableau[ligne + 1][colonne] != 0)
        {
        tableau[ligne][colonne] = 0;
        while (tableau[ligne + compteur][colonne] != 0)

            compteur = compteur + 1;
            tableau[ligne + compteur][colonne] = 1;
        }
    }*/
    else if(tableau[ligne][colonne - 1] == 1 || tableau[ligne][colonne -  1] == 2 || tableau[ligne][colonne - 1] == 3 || tableau[ligne ][colonne - 1] == 4 || tableau[ligne][colonne - 1] == 5 ||
             tableau[ligne ][colonne - 1] == 6 || tableau[ligne ][colonne-1] == 7
             || tableau[ligne ][colonne-1] == 8)
        {
        tableau[ligne][colonne] = 0;

        while(tableau[ligne][colonne - compteur] == 1 ||tableau[ligne][colonne - compteur] == 2 || tableau[ligne][colonne - compteur] == 3 || tableau[ligne][colonne - compteur] == 4 || tableau[ligne][colonne - compteur] == 5 ||
             tableau[ligne ][colonne - compteur] == 6 || tableau[ligne][colonne-compteur] == 6 || tableau[ligne ][colonne-compteur] == 7
             || tableau[ligne ][colonne-compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne][colonne - compteur] = 1;
    }

    else
    {
        printf("Vous ne pouvez pas jouer ici !");
        CarreaGaucheJ1();

    }
}


void CarreaDroiteJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);
    if (tableau[ligne][colonne + 1] == 0 && tableau[ligne][colonne] == 1){
        tableau[ligne][colonne] = 0;
        tableau[ligne][colonne + 1] = 1;
    }
    else if(tableau[ligne][colonne + 1] == 1 || tableau[ligne][colonne +  1] == 2 || tableau[ligne][colonne + 1] == 3 || tableau[ligne ][colonne + 1] == 4 || tableau[ligne][colonne + 1] == 5 ||
             tableau[ligne ][colonne + 1] == 6  || tableau[ligne ][colonne+1] == 7
             || tableau[ligne ][colonne+1] == 8)
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne][colonne + compteur] == 1 ||tableau[ligne][colonne + compteur] == 2 || tableau[ligne][colonne + compteur] == 3 || tableau[ligne][colonne + compteur] == 4 || tableau[ligne][colonne + compteur] == 5 ||
             tableau[ligne ][colonne + compteur] == 6 || tableau[ligne ][colonne+compteur] == 7
             || tableau[ligne ][colonne+compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne][colonne + compteur] = 1;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici !");
        coupparcoupJ1();
    }
}

void CarreArriereJ1(ligne, colonne){
    int compteur = 1;
    /*int ligne;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);*/
    if (tableau[ligne - 1][colonne] == 0 && tableau[ligne][colonne] == 1 ){
        tableau[ligne][colonne] = 0;
        tableau[ligne -1][colonne] = 1;
    }
    else if(tableau[ligne - 1][colonne] == 1 || tableau[ligne - 1][colonne] == 2 || tableau[ligne - 1][colonne] == 3 || tableau[ligne - 1][colonne] == 4 || tableau[ligne -1][colonne ] == 5 ||
             tableau[ligne-1 ][colonne] == 6 || tableau[ligne-1][colonne] == 6 || tableau[ligne - 1 ][colonne] == 7
             || tableau[ligne-1][colonne] == 8)
        {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne] == 1 || tableau[ligne - compteur][colonne] == 2 || tableau[ligne - compteur][colonne] == 3 || tableau[ligne - compteur][colonne] == 4 || tableau[ligne - compteur][colonne] == 5 ||
             tableau[ligne - compteur][colonne] == 6 || tableau[ligne - compteur][colonne] == 6 || tableau[ligne - compteur][colonne] == 7
             || tableau[ligne - compteur][colonne] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne] = 1;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ1();
    }

}

void TriangleJ1(){

    int f;
    printf("Ou voulez vous jouer votre triangle (2) ?\n 1.Tout droit en arriere\n 2.Sur votre diagonale a droite\n 3.Sur votre diagonale a gauche\n");
    scanf("%d",&f);
    switch(f){

    case 1: TriangletoutdroitArriereJ1();
    break;

    case 2 : TriangleDiagonaleDroiteJ1();
    break;

    case 3 : TriangleDiagonaleGaucheJ1();
    break;

    }
}

void TriangletoutdroitArriereJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre triangle\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre triangle\n");
    scanf("%d",&colonne);
    if (tableau[ligne - 1][colonne] == 0 && tableau[ligne][colonne] == 2 ){
        tableau[ligne][colonne] = 0;
        tableau[ligne -1][colonne] = 1;
    }
    else if(tableau[ligne - 1][colonne] == 1 || tableau[ligne - 1][colonne] == 2 || tableau[ligne - 1][colonne] == 3 || tableau[ligne - 1][colonne] == 4 || tableau[ligne -1][colonne ] == 5 ||
             tableau[ligne-1 ][colonne] == 6 || tableau[ligne - 1 ][colonne] == 7
             || tableau[ligne-1][colonne] == 8 )
        {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne] == 1 || tableau[ligne - compteur][colonne] == 2 || tableau[ligne - compteur][colonne] == 3 || tableau[ligne - compteur][colonne] == 4 || tableau[ligne - compteur][colonne] == 5 ||
             tableau[ligne - compteur][colonne] == 6 || tableau[ligne - compteur][colonne] == 6 || tableau[ligne - compteur][colonne] == 7
             || tableau[ligne - compteur][colonne] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne] = 1;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ1();
    }
}

void TriangleDiagonaleDroiteJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre triangle\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre triangle\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne + 1] == 0  && tableau[ligne][colonne] == 2){
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne + 1] = 2 ;
    }
    else if(tableau[ligne + 1][colonne + 1] == 1 || tableau[ligne + 1][colonne + 1] == 2 || tableau[ligne + 1][colonne + 1] == 3 || tableau[ligne + 1][colonne + 1] == 4 || tableau[ligne + 1][colonne+1] == 5 ||
             tableau[ligne + 1][colonne + 1] == 6 || tableau[ligne + 1][colonne + 1] == 7
             || tableau[ligne + 1][colonne + 1] == 8)
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne + compteur] == 1 || tableau[ligne + compteur][colonne + compteur] == 2 || tableau[ligne + compteur][colonne + compteur] == 3 || tableau[ligne + compteur][colonne + compteur] == 4|| tableau[ligne + compteur][colonne + compteur] == 5 ||
             tableau[ligne + compteur][colonne + compteur] == 6 || tableau[ligne + compteur][colonne + compteur] == 7
             || tableau[ligne + compteur][colonne + compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne + compteur] = 2;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ1();
    }
}

void TriangleDiagonaleGaucheJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre triangle\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre triangle\n");
    scanf("%d",&colonne);
    if( tableau[ligne + 1][colonne - 1] == 0 && tableau[ligne][colonne] == 2)
        {
            tableau[ligne][colonne] = 0;
            tableau[ligne + 1][colonne - 1] = 2;
        }
        else if(tableau[ligne + 1][colonne - 1] == 1 || tableau[ligne + 1][colonne - 1] == 2 || tableau[ligne + 1][colonne - 1] == 3 || tableau[ligne + 1][colonne - 1] == 4 || tableau[ligne + 1][colonne-1] == 5 ||
             tableau[ligne + 1][colonne - 1] == 6  || tableau[ligne + 1][colonne - 1] == 7
             || tableau[ligne + 1][colonne - 1] == 8)
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne - compteur] == 1 || tableau[ligne + compteur][colonne - compteur] == 2 || tableau[ligne + compteur][colonne - compteur] == 3
               || tableau[ligne + compteur][colonne - compteur] == 4|| tableau[ligne + compteur][colonne-compteur] == 5 ||
             tableau[ligne + compteur][colonne - compteur] == 6  || tableau[ligne + compteur][colonne - compteur] == 7
             || tableau[ligne + compteur][colonne - compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne - compteur] = 2;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ1();
    }
}

void LosangeJ1(){

    int g;
    printf("Ou voulez vous jouer votre losange (3) ?\n 1.Sur la diagonale droite en avant\n 2.Sur la diagonale gauche en avant\n 3.Sur la diagonale droite en arriere\n 4.Sur la diagonale gauche en arriere\n");
    scanf("%d",&g);
    switch(g){

    case 1: LosangeDiagonaleDroiteAvantJ1();
    break;

    case 2 : LosangeDiagonaleGaucheAvantJ1();
    break;

    case 3 : LosangeDiagonaleDroiteArriereJ1();
    break;

    case 4 : LosangeDiagonaleGaucheArriereJ1();
    break;

    }
}

void LosangeDiagonaleDroiteAvantJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne + 1] == 0 && tableau[ligne][colonne] == 3){
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne + 1] = 3;
    }
    else if(tableau[ligne + 1][colonne + 1] == 1 || tableau[ligne + 1][colonne + 1] == 2 || tableau[ligne + 1][colonne + 1] == 3 || tableau[ligne + 1][colonne + 1] == 4 || tableau[ligne + 1][colonne+1] == 5 ||
             tableau[ligne + 1][colonne + 1] == 6 || tableau[ligne + 1][colonne + 1] == 7
             || tableau[ligne + 1][colonne + 1] == 8)
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne + compteur] == 1 || tableau[ligne + compteur][colonne + compteur] == 2 || tableau[ligne + compteur][colonne + compteur] == 3
               || tableau[ligne + compteur][colonne + compteur] == 4 || tableau[ligne + compteur][colonne + compteur] == 5 ||
             tableau[ligne + compteur][colonne + compteur] == 6 || tableau[ligne + compteur][colonne + compteur] == 7
             || tableau[ligne + compteur][colonne + compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne + compteur] = 3;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        LosangeDiagonaleDroiteAvantJ1();

}
}

void LosangeDiagonaleGaucheAvantJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne - 1] == 0  && tableau[ligne][colonne] == 3){
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne - 1] = 3;
    }
    else if(tableau[ligne + 1][colonne - 1] == 1 || tableau[ligne + 1][colonne - 1] == 2 || tableau[ligne + 1][colonne - 1] == 3 || tableau[ligne + 1][colonne - 1] == 4 || tableau[ligne + 1][colonne-1] == 5 ||
             tableau[ligne + 1][colonne - 1] == 6  || tableau[ligne + 1][colonne - 1] == 7
             || tableau[ligne + 1][colonne - 1] == 8)
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne - compteur] == 1 || tableau[ligne + compteur][colonne - compteur] == 2 || tableau[ligne + compteur][colonne - compteur] == 3 || tableau[ligne + compteur][colonne - compteur] == 4|| tableau[ligne + compteur][colonne-compteur] == 5 ||
             tableau[ligne + compteur][colonne - compteur] == 6  || tableau[ligne + compteur][colonne - compteur] == 7
             || tableau[ligne + compteur][colonne - compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne - compteur] = 3;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ1();
    }

}


void LosangeDiagonaleDroiteArriereJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if (tableau[ligne - 1][colonne + 1] == 0 && tableau[ligne][colonne] == 3){
        tableau[ligne][colonne] = 0;
        tableau[ligne - 1][colonne + 1] = 3;
    }
    else if(tableau[ligne - 1][colonne + 1] == 1 || tableau[ligne - 1][colonne + 1] == 2 || tableau[ligne - 1][colonne + 1] == 3 || tableau[ligne - 1][colonne + 1] == 4
            || tableau[ligne - 1][colonne + 1] == 5 ||
             tableau[ligne - 1][colonne + 1] == 6 || tableau[ligne - 1][colonne + 1] == 7
             || tableau[ligne - 1][colonne + 1] == 8)
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne + compteur] == 1 || tableau[ligne - compteur][colonne + compteur] == 2 || tableau[ligne - compteur][colonne + compteur] == 3 || tableau[ligne - compteur][colonne + compteur] == 4
              || tableau[ligne-compteur][colonne + compteur] == 5|| tableau[ligne-compteur][colonne + compteur] == 6|| tableau[ligne-compteur][colonne + compteur] == 7|| tableau[ligne-compteur][colonne + compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne + compteur] = 3;
    }
    else {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ1();
    }
}

void LosangeDiagonaleGaucheArriereJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if(tableau[ligne - 1][colonne - 1] == 0 && tableau[ligne][colonne] == 3){
        tableau[ligne][colonne] = 0;
        tableau[ligne - 1][colonne - 1] = 3;
    }
    else if(tableau[ligne - 1][colonne - 1] == 1 || tableau[ligne - 1][colonne - 1] == 2 || tableau[ligne - 1][colonne - 1] == 3 || tableau[ligne - 1][colonne - 1] == 4
            || tableau[ligne - 1][colonne - 1] == 5 ||
             tableau[ligne - 1][colonne - 1] == 6 || tableau[ligne - 1][colonne - 1] == 7
             || tableau[ligne - 1][colonne - 1] == 8 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne - compteur] == 1 || tableau[ligne - compteur][colonne - compteur] == 2 || tableau[ligne - compteur][colonne - compteur] == 3
              || tableau[ligne - compteur][colonne - compteur] == 4|| tableau[ligne - compteur][colonne - compteur] == 5 ||
             tableau[ligne - compteur][colonne - compteur] == 6 || tableau[ligne - compteur][colonne - compteur] == 7
             || tableau[ligne - compteur][colonne - compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne - compteur] = 3;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ1();
    }
}


void RondJ1(){

    int g;
    printf("Ou voulez vous jouer votre rond (4) ?\n 1.Tout droit en avant \n 2.Tout droit en arriere \n 3.a droite \n 4.a gauche\n 5.Sur la diagonale droite en avant \n  6.Sur la diagonale gauche en avant\n 7.Sur la diagonale droite en arriere \n 8.Sur la diagonale gauche en arriere \n");
    scanf("%d",&g);
    switch(g){

    case 1: RondToutDroitJ1();
    break;

    case 2 : RondToutDroitArriereJ1();
    break;

    case 3 : RondaDroiteJ1();
    break;

    case 4 : RondaGaucheJ1();
    break;

    case 5 : RondDiagonaleDroiteAvantJ1();
    break;

    case 6 : RondDiagonaleGaucheAvantJ1();
    break;

    case 7 : RondDiagonaleDroiteArriereJ1();
    break;

    case 8 : RondDiagonaleGaucheArriereJ1();
    break;

    }
}

void RondToutDroitJ1(){

    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre rond\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre rond\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne] == 0 && tableau[ligne][colonne] == 4)
        {
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne] = 4;
        }

    else if(tableau[ligne + 1][colonne] == 1 || tableau[ligne + 1][colonne] == 2 || tableau[ligne + 1][colonne] == 3 || tableau[ligne + 1][colonne] == 4 || tableau[ligne + 1][colonne] == 5 ||
             tableau[ligne + 1][colonne] == 6 || tableau[ligne + 1][colonne] == 6 || tableau[ligne + 1][colonne] == 7
             || tableau[ligne + 1][colonne] == 8 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne] == 1 || tableau[ligne + compteur][colonne] == 2 || tableau[ligne + compteur][colonne] == 3 || tableau[ligne + compteur][colonne] == 4 || tableau[ligne + compteur][colonne] == 5 ||
             tableau[ligne + compteur][colonne] == 6  || tableau[ligne + compteur][colonne] == 7
             || tableau[ligne + compteur][colonne] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne] = 4;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ1();
    }
}

void RondToutDroitArriereJ1(){

    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre rond\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre rond\n");
    scanf("%d",&colonne);
    if (tableau[ligne - 1][colonne] == 0 && tableau[ligne][colonne] == 4){
        tableau[ligne][colonne] = 0;
        tableau[ligne -1][colonne] = 4;
    }
    else if(tableau[ligne - 1][colonne] == 1 || tableau[ligne - 1][colonne] == 2 || tableau[ligne - 1][colonne] == 3 || tableau[ligne - 1][colonne] == 4 || tableau[ligne -1][colonne ] == 5 ||
             tableau[ligne-1 ][colonne] == 6 || tableau[ligne - 1 ][colonne] == 7
             || tableau[ligne-1][colonne] == 8)
        {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne] == 1 || tableau[ligne - compteur][colonne] == 2 || tableau[ligne - compteur][colonne] == 3 || tableau[ligne - compteur][colonne] == 4|| tableau[ligne - compteur][colonne] == 5 ||
             tableau[ligne - compteur][colonne] == 6 || tableau[ligne - compteur][colonne] == 7
             || tableau[ligne - compteur][colonne] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne] = 4;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ1();
    }

}

void RondaDroiteJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);
    if (tableau[ligne][colonne + 1] == 0 && tableau[ligne][colonne] == 4){
        tableau[ligne][colonne] = 0;
        tableau[ligne][colonne + 1] = 4;
    }
    else if(tableau[ligne][colonne + 1] == 1 || tableau[ligne][colonne +  1] == 2 || tableau[ligne][colonne + 1] == 3 || tableau[ligne ][colonne + 1] == 4 || tableau[ligne][colonne + 1] == 5 ||
             tableau[ligne ][colonne + 1] == 6  || tableau[ligne ][colonne+1] == 7
             || tableau[ligne ][colonne+1] == 8 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne][colonne + compteur] == 1 ||tableau[ligne][colonne + compteur] == 2 || tableau[ligne][colonne + compteur] == 3 || tableau[ligne][colonne + compteur] == 4 || tableau[ligne][colonne + compteur] == 5 ||
             tableau[ligne ][colonne + compteur] == 6 || tableau[ligne ][colonne+compteur] == 7
             || tableau[ligne ][colonne+compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne][colonne + compteur] = 4;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici !");
        coupparcoupJ1();
    }
}
void RondaGaucheJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);

    if (tableau[ligne][colonne - 1] == 0 && tableau[ligne][colonne] == 4 )
        {
        tableau[ligne][colonne] = 0;
        tableau[ligne][colonne - 1] = 4;
        }
    else if(tableau[ligne][colonne - 1] == 1 || tableau[ligne][colonne -  1] == 2 || tableau[ligne][colonne - 1] == 3 || tableau[ligne ][colonne - 1] == 4 || tableau[ligne][colonne - 1] == 5 ||
             tableau[ligne ][colonne - 1] == 6 || tableau[ligne ][colonne-1] == 7
             || tableau[ligne ][colonne-1] == 8)
        {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne][colonne - compteur] == 1 ||tableau[ligne][colonne - compteur] == 2 || tableau[ligne][colonne - compteur] == 3 || tableau[ligne][colonne - compteur] == 4 || tableau[ligne][colonne - compteur] == 5 ||
             tableau[ligne ][colonne - compteur] == 6 || tableau[ligne ][colonne-compteur] == 7
             || tableau[ligne ][colonne-compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne][colonne - compteur] = 4;
    }

    else
    {
        printf("Vous ne pouvez pas jouer ici !");
        coupparcoupJ1();

    }
}

void RondDiagonaleDroiteAvantJ1(){

    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre rond\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre rond\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne + 1] == 0  && tableau[ligne][colonne] == 4){
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne + 1] = 4 ;
    }
    else if(tableau[ligne + 1][colonne + 1] == 1 || tableau[ligne + 1][colonne + 1] == 2 || tableau[ligne + 1][colonne + 1] == 3 || tableau[ligne + 1][colonne + 1] == 4 || tableau[ligne + 1][colonne+1] == 5 ||
             tableau[ligne + 1][colonne + 1] == 6 || tableau[ligne + 1][colonne + 1] == 7
             || tableau[ligne + 1][colonne + 1] == 8)
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne + compteur] == 1 || tableau[ligne + compteur][colonne + compteur] == 2 || tableau[ligne + compteur][colonne + compteur] == 3 || tableau[ligne + compteur][colonne + compteur] == 4 || tableau[ligne + compteur][colonne + compteur] == 5 ||
             tableau[ligne + compteur][colonne + compteur] == 6 || tableau[ligne + compteur][colonne + compteur] == 7
             || tableau[ligne + compteur][colonne + compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne + compteur] = 4;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ1();
    }
}

void RondDiagonaleGaucheAvantJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre rond\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre rond\n");
    scanf("%d",&colonne);
    if( tableau[ligne + 1][colonne - 1] == 0 && tableau[ligne][colonne] == 4)
        {
            tableau[ligne][colonne] = 0;
            tableau[ligne + 1][colonne - 1] = 4;
        }
        else if(tableau[ligne + 1][colonne - 1] == 1 || tableau[ligne + 1][colonne - 1] == 2 || tableau[ligne + 1][colonne - 1] == 3 || tableau[ligne + 1][colonne - 1] == 4 || tableau[ligne + 1][colonne-1] == 5 ||
             tableau[ligne + 1][colonne - 1] == 6  || tableau[ligne + 1][colonne - 1] == 7
             || tableau[ligne + 1][colonne - 1] == 8)
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne - compteur] == 1 || tableau[ligne + compteur][colonne - compteur] == 2 || tableau[ligne + compteur][colonne - compteur] == 3 || tableau[ligne + compteur][colonne - compteur] == 4 || tableau[ligne + compteur][colonne-compteur] == 5 ||
             tableau[ligne + compteur][colonne - compteur] == 6  || tableau[ligne + compteur][colonne - compteur] == 7
             || tableau[ligne + compteur][colonne - compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne - compteur] = 4;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ1();
    }
}

void RondDiagonaleDroiteArriereJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre rond\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre rond\n");
    scanf("%d",&colonne);
    if (tableau[ligne - 1][colonne + 1] == 0 && tableau[ligne][colonne] == 4){
        tableau[ligne][colonne] = 0;
        tableau[ligne - 1][colonne + 1] = 4;
    }
    else if(tableau[ligne - 1][colonne + 1] == 1 || tableau[ligne - 1][colonne + 1] == 2 || tableau[ligne - 1][colonne + 1] == 3 || tableau[ligne - 1][colonne + 1] == 4 || tableau[ligne - 1][colonne + 1] == 5 ||
             tableau[ligne - 1][colonne + 1] == 6 || tableau[ligne - 1][colonne + 1] == 7
             || tableau[ligne - 1][colonne + 1] == 8 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne + compteur] == 1 || tableau[ligne - compteur][colonne + compteur] == 2 || tableau[ligne - compteur][colonne + compteur] == 3 || tableau[ligne - compteur][colonne + compteur] == 4
              || tableau[ligne-compteur][colonne + compteur] == 5|| tableau[ligne-compteur][colonne + compteur] == 6|| tableau[ligne-compteur][colonne + compteur] == 7|| tableau[ligne-compteur][colonne + compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne + compteur] = 4;
    }
    else {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ1();
    }
}

void RondDiagonaleGaucheArriereJ1(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre rond\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre rond\n");
    scanf("%d",&colonne);
    if(tableau[ligne - 1][colonne - 1] == 0 && tableau[ligne][colonne] == 4){
        tableau[ligne][colonne] = 0;
        tableau[ligne - 1][colonne - 1] = 4;
    }
    else if(tableau[ligne - 1][colonne - 1] == 1 || tableau[ligne - 1][colonne - 1] == 2 || tableau[ligne - 1][colonne - 1] == 3 || tableau[ligne - 1][colonne - 1] == 4  || tableau[ligne - 1][colonne - 1] == 5 ||
             tableau[ligne - 1][colonne - 1] == 6 || tableau[ligne - 1][colonne - 1] == 7
             || tableau[ligne - 1][colonne - 1] == 8)
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne - compteur] == 1 || tableau[ligne - compteur][colonne - compteur] == 2 || tableau[ligne - compteur][colonne - compteur] == 3 ||
               tableau[ligne - compteur][colonne - compteur] == 4 || tableau[ligne - compteur][colonne - compteur] == 5 ||
             tableau[ligne - compteur][colonne - compteur] == 6 || tableau[ligne - compteur][colonne - compteur] == 7
             || tableau[ligne - compteur][colonne - compteur] == 8)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne - compteur] = 4;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        LosangeDiagonaleGaucheArriereJ1();
    }
}

void coupparcoupJ2(){
    int z;
    printf("Vous etes le Joueur 2. \n Choisissez un pion a jouer :\n 1.Carre\n 2.Triangle\n 3.Losange\n 4.Rond\n");
    scanf("%d",&z);
    switch(z){
        case 1: CarreJ2();
        break;
        case 2: TriangleJ2();
        break;
        case 3: LosangeJ2();
        break;
        case 4: RondJ2();
        break;
        }
}

void CarreJ2(){

    int e;
    printf("Ou voulez vous jouer votre carre (1) ?\n 1.Tout droit\n 2.A votre gauche\n 3.A votre droite\n 4.En arriere\n");
    scanf("%d",&e);
    switch(e){

    case 1: CarretoutdroitJ2();
    break;

    case 2 : CarreaGaucheJ2();
    break;

    case 3 : CarreaDroiteJ1();
    break;

    case 4 : CarreArriereJ2();
    break;


    }
}

void CarretoutdroitJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);
    if (tableau[ligne - 1][colonne] == 0 && tableau[ligne][colonne] == 5 ){
        tableau[ligne][colonne] = 0;
        tableau[ligne -1][colonne] = 5;
    }
    else if(tableau[ligne - 1][colonne] == 1 || tableau[ligne - 1][colonne] == 2 || tableau[ligne - 1][colonne] == 3 || tableau[ligne - 1][colonne] == 4 )
        {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne] == 1 || tableau[ligne - compteur][colonne] == 2 || tableau[ligne - compteur][colonne] == 3 || tableau[ligne - compteur][colonne] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne] = 5;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();
    }

}

void CarreaGaucheJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);

    if (tableau[ligne][colonne - 1] == 0 && tableau[ligne][colonne] == 5)
        {
        tableau[ligne][colonne] = 0;
        tableau[ligne][colonne - 1] = 5;
        }
    else if(tableau[ligne][colonne - 1] == 1 || tableau[ligne][colonne -  1] == 2 || tableau[ligne][colonne - 1] == 3 || tableau[ligne ][colonne - 1] == 4 )
        {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne][colonne - compteur] == 1 ||tableau[ligne][colonne - compteur] == 2 || tableau[ligne][colonne - compteur] == 3 || tableau[ligne][colonne - compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne][colonne - compteur] = 5;
    }

    else
    {
        printf("Vous ne pouvez pas jouer ici !");
        coupparcoupJ2();

    }
}
void CarreaDroiteJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);
    if (tableau[ligne][colonne + 1] == 0 && tableau[ligne][colonne] == 5){
        tableau[ligne][colonne] = 0;
        tableau[ligne][colonne + 1] = 5;
    }
    else if(tableau[ligne][colonne + 1] == 1 || tableau[ligne][colonne +  1] == 2 || tableau[ligne][colonne + 1] == 3 || tableau[ligne ][colonne + 1] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne][colonne + compteur] == 1 ||tableau[ligne][colonne + compteur] == 2 || tableau[ligne][colonne + compteur] == 3 || tableau[ligne][colonne + compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne][colonne + compteur] = 5;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici !");
        coupparcoupJ2();
    }
}
void CarreArriereJ2(){
    int compteur = 1;;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne] == 0 && tableau[ligne][colonne] == 5)
        {
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne] = 5;
        }
    else if(tableau[ligne + 1][colonne] == 1 || tableau[ligne + 1][colonne] == 2 || tableau[ligne + 1][colonne] == 3 || tableau[ligne + 1][colonne] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne] == 1 || tableau[ligne + compteur][colonne] == 2 || tableau[ligne + compteur][colonne] == 3 || tableau[ligne + compteur][colonne] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne] = 5;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        CarreArriereJ2();
    }
}
void TriangleJ2(){
    int f;
    printf("Ou voulez vous jouer votre triangle (2) ?\n 1.Tout droit en arriere\n 2.Sur votre diagonale a droite\n 3.Sur votre diagonale a gauche\n");
    scanf("%d",&f);
    switch(f){

    case 1: TriangletoutdroitArriereJ2();
    break;

    case 2 : TriangleDiagonaleDroiteJ2();
    break;

    case 3 : LosangeDiagonaleGaucheArriereJ1();
    break;

    }
}

void TriangletoutdroitArriereJ2(){
    int compteur = 1;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne] == 0 && tableau[ligne][colonne] == 6)
        {
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne] = 6;
        }
    else if(tableau[ligne + 1][colonne] == 1 || tableau[ligne + 1][colonne] == 2 || tableau[ligne + 1][colonne] == 3 || tableau[ligne + 1][colonne] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne] == 1 || tableau[ligne + compteur][colonne] == 2 || tableau[ligne + compteur][colonne] == 3 || tableau[ligne + compteur][colonne] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne] = 6;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();
    }
}

void TriangleDiagonaleDroiteJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if (tableau[ligne - 1][colonne + 1] == 0 && tableau[ligne][colonne] == 6){
        tableau[ligne][colonne] = 0;
        tableau[ligne - 1][colonne + 1] = 6;
    }
    else if(tableau[ligne - 1][colonne + 1] == 1 || tableau[ligne - 1][colonne + 1] == 2 || tableau[ligne - 1][colonne + 1] == 3 || tableau[ligne - 1][colonne + 1] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne + compteur] == 1 || tableau[ligne - compteur][colonne + compteur] == 2 || tableau[ligne - compteur][colonne + compteur] == 3 || tableau[ligne - compteur][colonne + compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne + compteur] = 6;
    }
    else {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();
    }
}

void TriangleDiagonaleGaucheJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne - 1] == 0  && tableau[ligne][colonne] == 6){
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne - 1] = 6;
    }
    else if(tableau[ligne + 1][colonne - 1] == 1 || tableau[ligne + 1][colonne - 1] == 2 || tableau[ligne + 1][colonne - 1] == 3 || tableau[ligne + 1][colonne - 1] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne - compteur] == 1 || tableau[ligne + compteur][colonne - compteur] == 2 || tableau[ligne + compteur][colonne - compteur] == 3 || tableau[ligne + compteur][colonne - compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne - compteur] = 6;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();
    }

}



void LosangeJ2(){
    int g;
    printf("Ou voulez vous jouer votre losange (3) ?\n 1.Sur la diagonale droite en avant\n 2.Sur la diagonale gauche en avant\n 3.Sur la diagonale droite en arriere\n 4.Sur la diagonale gauche en arriere\n");
    scanf("%d",&g);
    switch(g){

    case 1: LosangeDiagonaleDroiteAvantJ2();
    break;

    case 2 : LosangeDiagonaleGaucheAvantJ2();
    break;

    case 3 : LosangeDiagonaleDroiteArriereJ2();
    break;

    case 4 : LosangeDiagonaleGaucheArriereJ2();
    break;

    }
}
void LosangeDiagonaleDroiteAvantJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if (tableau[ligne - 1][colonne + 1] == 0 && tableau[ligne][colonne] == 7){
        tableau[ligne][colonne] = 0;
        tableau[ligne - 1][colonne + 1] = 7;
    }
    else if(tableau[ligne - 1][colonne + 1] == 1 || tableau[ligne - 1][colonne + 1] == 2 || tableau[ligne - 1][colonne + 1] == 3 || tableau[ligne - 1][colonne + 1] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne + compteur] == 1 || tableau[ligne - compteur][colonne + compteur] == 2 || tableau[ligne - compteur][colonne + compteur] == 3 || tableau[ligne - compteur][colonne + compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne + compteur] = 7;
    }
    else {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();
    }
}
void LosangeDiagonaleGaucheAvantJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if(tableau[ligne - 1][colonne - 1] == 0 && tableau[ligne][colonne] == 7){
        tableau[ligne][colonne] = 0;
        tableau[ligne - 1][colonne - 1] = 7;
    }
    else if(tableau[ligne - 1][colonne - 1] == 1 || tableau[ligne - 1][colonne - 1] == 2 || tableau[ligne - 1][colonne - 1] == 3 || tableau[ligne - 1][colonne - 1] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne - compteur] == 1 || tableau[ligne - compteur][colonne - compteur] == 2 || tableau[ligne - compteur][colonne - compteur] == 3 || tableau[ligne - compteur][colonne - compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne - compteur] = 7;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();
    }
}
void LosangeDiagonaleDroiteArriereJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne + 1] == 0 && tableau[ligne][colonne] == 7){
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne + 1] = 7;
    }
    else if(tableau[ligne + 1][colonne + 1] == 1 || tableau[ligne + 1][colonne + 1] == 2 || tableau[ligne + 1][colonne + 1] == 3 || tableau[ligne + 1][colonne + 1] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne + compteur] == 1 || tableau[ligne + compteur][colonne + compteur] == 2 || tableau[ligne + compteur][colonne + compteur] == 3 || tableau[ligne + compteur][colonne + compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne + compteur] = 7;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();

}
}

void LosangeDiagonaleGaucheArriereJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne - 1] == 0  && tableau[ligne][colonne] == 7){
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne - 1] = 7;
    }
    else if(tableau[ligne + 1][colonne - 1] == 1 || tableau[ligne + 1][colonne - 1] == 2 || tableau[ligne + 1][colonne - 1] == 3 || tableau[ligne + 1][colonne - 1] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne - compteur] == 1 || tableau[ligne + compteur][colonne - compteur] == 2 || tableau[ligne + compteur][colonne - compteur] == 3 || tableau[ligne + compteur][colonne - compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne - compteur] = 7;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();
    }

}
void RondJ2(){

    int g;
    printf("Ou voulez vous jouer votre rond (4) ?\n 1.Tout droit en avant \n 2.Tout droit en arriere \n 3.a votre droite \n 4. a votre gauche\n 5.Sur la diagonale droite en avant \n 6.Sur la diagonale gauche en avant \n 7.Sur la diagonale droite en arriere \n 8.Sur la diagonale gauche en arriere \n");
    scanf("%d",&g);
    switch(g){

    case 1: RondToutDroitAvantJ2();
    break;

    case 2 : RondToutDroitArriereJ2();
    break;

    case 3 :RondaDroiteJ2();
    break;

    case 4 :RondaGaucheJ2();
    break;

    case 5 : RondDiagonaleDroiteAvantJ2();
    break;

    case 6 : RondDiagonaleGaucheAvantJ2();
    break;

    case 7 : RondDiagonaleDroiteArriereJ2();
    break;

    case 8 : RondDiagonaleGaucheArriereJ2();
    break;

    }
}
void RondToutDroitAvantJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);
    if (tableau[ligne - 1][colonne] == 0 && tableau[ligne][colonne] == 8 ){
        tableau[ligne][colonne] = 0;
        tableau[ligne -1][colonne] = 8;
    }
    else if(tableau[ligne - 1][colonne] == 1 || tableau[ligne - 1][colonne] == 2 || tableau[ligne - 1][colonne] == 3 || tableau[ligne - 1][colonne] == 4 )
        {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne] == 1 || tableau[ligne - compteur][colonne] == 2 || tableau[ligne - compteur][colonne] == 3 || tableau[ligne - compteur][colonne] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne] = 8;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();
    }

}
void RondToutDroitArriereJ2(){
    int compteur = 1;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne] == 0 && tableau[ligne][colonne] == 8)
        {
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne] = 8;
        }
    else if(tableau[ligne + 1][colonne] == 1 || tableau[ligne + 1][colonne] == 2 || tableau[ligne + 1][colonne] == 3 || tableau[ligne + 1][colonne] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne] == 1 || tableau[ligne + compteur][colonne] == 2 || tableau[ligne + compteur][colonne] == 3 || tableau[ligne + compteur][colonne] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne] = 8;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();
    }
}
void RondaDroiteJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);
    if (tableau[ligne][colonne + 1] == 0 && tableau[ligne][colonne] == 8){
        tableau[ligne][colonne] = 0;
        tableau[ligne][colonne + 1] = 8;
    }
    else if(tableau[ligne][colonne + 1] == 1 || tableau[ligne][colonne +  1] == 2 || tableau[ligne][colonne + 1] == 3 || tableau[ligne ][colonne + 1] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne][colonne + compteur] == 1 ||tableau[ligne][colonne + compteur] == 2 || tableau[ligne][colonne + compteur] == 3 || tableau[ligne][colonne + compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne][colonne + compteur] = 8;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici !");
        coupparcoupJ2();
    }
}

void RondaGaucheJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre carre\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre carre\n");
    scanf("%d",&colonne);

    if (tableau[ligne][colonne - 1] == 0 && tableau[ligne][colonne] == 8)
        {
        tableau[ligne][colonne] = 0;
        tableau[ligne][colonne - 1] = 8;
        }
    else if(tableau[ligne][colonne - 1] == 1 || tableau[ligne][colonne -  1] == 2 || tableau[ligne][colonne - 1] == 3 || tableau[ligne ][colonne - 1] == 4 )
        {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne][colonne - compteur] == 1 ||tableau[ligne][colonne - compteur] == 2 || tableau[ligne][colonne - compteur] == 3 || tableau[ligne][colonne - compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne][colonne - compteur] = 8;
    }

    else
    {
        printf("Vous ne pouvez pas jouer ici !");
        coupparcoupJ2();

    }
}
void RondDiagonaleDroiteAvantJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if (tableau[ligne - 1][colonne + 1] == 0 && tableau[ligne][colonne] == 8){
        tableau[ligne][colonne] = 0;
        tableau[ligne - 1][colonne + 1] = 8;
    }
    else if(tableau[ligne - 1][colonne + 1] == 1 || tableau[ligne - 1][colonne + 1] == 2 || tableau[ligne - 1][colonne + 1] == 3 || tableau[ligne - 1][colonne + 1] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne + compteur] == 1 || tableau[ligne - compteur][colonne + compteur] == 2 || tableau[ligne - compteur][colonne + compteur] == 3 || tableau[ligne - compteur][colonne + compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne + compteur] = 8;
    }
    else {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();
    }
}
void RondDiagonaleGaucheAvantJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if(tableau[ligne - 1][colonne - 1] == 0 && tableau[ligne][colonne] == 8){
        tableau[ligne][colonne] = 0;
        tableau[ligne - 1][colonne - 1] = 8;
    }
    else if(tableau[ligne - 1][colonne - 1] == 1 || tableau[ligne - 1][colonne - 1] == 2 || tableau[ligne - 1][colonne - 1] == 3 || tableau[ligne - 1][colonne - 1] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne - compteur][colonne - compteur] == 1 || tableau[ligne - compteur][colonne - compteur] == 2 || tableau[ligne - compteur][colonne - compteur] == 3 || tableau[ligne - compteur][colonne - compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne - compteur][colonne - compteur] = 8;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();
    }
}
void RondDiagonaleDroiteArriereJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne + 1] == 0 && tableau[ligne][colonne] == 8){
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne + 1] = 8;
    }
    else if(tableau[ligne + 1][colonne + 1] == 1 || tableau[ligne + 1][colonne + 1] == 2 || tableau[ligne + 1][colonne + 1] == 3 || tableau[ligne + 1][colonne + 1] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne + compteur] == 1 || tableau[ligne + compteur][colonne + compteur] == 2 || tableau[ligne + compteur][colonne + compteur] == 3 || tableau[ligne + compteur][colonne + compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne + compteur] = 8;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();

}
}
void RondDiagonaleGaucheArriereJ2(){
    int compteur = 1;
    int ligne;
    int colonne;
    printf("Saisissez la ligne de votre losange\n");
    scanf("%d",&ligne);
    printf("Saisissez la colonne de votre losange\n");
    scanf("%d",&colonne);
    if (tableau[ligne + 1][colonne - 1] == 0  && tableau[ligne][colonne] == 8){
        tableau[ligne][colonne] = 0;
        tableau[ligne + 1][colonne - 1] = 8;
    }
    else if(tableau[ligne + 1][colonne - 1] == 1 || tableau[ligne + 1][colonne - 1] == 2 || tableau[ligne + 1][colonne - 1] == 3 || tableau[ligne + 1][colonne - 1] == 4 )
    {
        tableau[ligne][colonne] = 0;
        while(tableau[ligne + compteur][colonne - compteur] == 1 || tableau[ligne + compteur][colonne - compteur] == 2 || tableau[ligne + compteur][colonne - compteur] == 3 || tableau[ligne + compteur][colonne - compteur] == 4)
            {
            compteur = compteur + 1;
            }
            tableau[ligne + compteur][colonne - compteur] = 8;
    }
    else
    {
        printf("Vous ne pouvez pas jouer ici ! \n");
        coupparcoupJ2();
    }

}
int victoireJ1()
{
    int compteur1,compteur2,compteur3,compteur4;
    for(int i=1;i<9;i++)
    {
        switch (tableau[9][i])
        {
        case 1:
            compteur1++;
            break;

        case 2:
            compteur2++;
            break;
        case 3:
            compteur3++;
            break;
        case 4:
            compteur4++;
            break;
        }
    if (compteur1 == 2 && compteur2 == 2 && compteur3 == 2 && compteur4 == 2){
        return 1;

    }
    else{
        return 0;
    }
}
}

int victoireJ2()
{
    int compteur1,compteur2,compteur3,compteur4;
    for(int i=1;i<9;i++)
    {
        switch (tableau[0][i])
        {
        case 1:
            compteur1++;
            break;

        case 2:
            compteur2++;
            break;
        case 3:
            compteur3++;
            break;
        case 4:
            compteur4++;
            break;
        }
    if (compteur1 == 2 && compteur2 == 2 && compteur3 == 2 && compteur4 == 2){
        return 1;
    }
    else{
        return 0;
    }


    }
}
int main()
{
    //int Grill [M][N];
    initGrille();
    int i = 0;
    int res = victoireJ1;
    int res2 = victoireJ2;

    afficheGrille();
    while(res!=1 || res2 != 1){
        coupparcoupJ1();
        afficheGrille();
        res = victoireJ1();
        coupparcoupJ2();
        afficheGrille();
        res2 = victoireJ2();
        if (res2==1){
            printf("Le joueur 2 a gagné");
            return 0;

        }
        else{
            coupparcoupJ1();
            afficheGrille();
        }

        if (res == 1){
            printf("Le Joueur 1 a gagné");
            return 0;
        }
        else{
            coupparcoupJ2();
            afficheGrille();
        }

    }
}

