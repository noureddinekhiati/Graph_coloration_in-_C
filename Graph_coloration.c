#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct noeud {
    int sommet ;
    int succ[10];
    int couleur;
    int nbr_succ ;
};

typedef struct noeud graphe[30];

int nbr_sommet ;


void initialser(graphe g){
    int i ;
    for(i=0;i<nbr_sommet;i++) g[i].couleur = 0 ;
}

bool graphe_colore (graphe g){
    int i ; bool colore=true ;
    for(i=0;i<nbr_sommet;i++)
            if(g[i].couleur==0){
                colore = false ;
                break ;
                    }
    return colore ;

}
bool est_colore(struct noeud n){
    return n.couleur == 0 ;
}

void permuter (struct noeud *n1 , struct noeud *n2)
    {
    struct noeud *n ;
    n=n1 ;
    n1=n2 ;
    n2=n ;
    }

void tri (graphe g){
    int i,j;
    struct noeud n ;
    for(i=0;i<nbr_sommet-1;i++){
        for(j=i+1;j<nbr_sommet;j++){
            if(g[i].nbr_succ<g[j].nbr_succ){
                n=g[i];
                g[i]=g[j];
                g[j]=n ;
            }
        }
    }
}
void assisgner_couleur (struct noeud n,int couleur){
    if(n.couleur == 0) n.couleur = couleur ;
}
bool est_adjacent ( int succ){
    int i;
   bool adjacent = false ;
   for(i=1;i<=nbr_sommet;i++)
        if(succ==i) {adjacent = true ; break ;}
   return adjacent ;

}
bool rechercher (int t[],int val,int n){
    int i ;
    bool trouv = false ;
    for(i=0;i<n;i++){
        if(t[i]==val) { trouv=true ; break ; }
    }
    return trouv  ;
}
int pos_sommet(graphe g , int sommet){
    int i = 0,pos=-1;
    for(i=0;i<nbr_sommet ; i++){
        if(g[i].sommet==sommet) {pos=i ; break ; }
    }
    return pos ;
}
void colorer_sommet(graphe g){

    int i,j,couleur=1,pos ;
    initialser(g);
    g[0].couleur=couleur  ;
     i=0  ;
    while (i<nbr_sommet){

        for(j=1;j<=nbr_sommet;j++){
            if(rechercher(g[i].succ,j,g[i].nbr_succ)==false){
               pos = pos_sommet(g,j);
               if(est_colore(g[pos]))
                g[pos].couleur=couleur;
               }
        }
        i++ ;

        if(graphe_colore(g)) break ;
        if(est_colore(g[i])) {
                couleur++ ;
                g[i].couleur=couleur;}


    }
}

int main()
{
    printf("Veuillez vous introduire le nombre de sommets  : ");
    scanf("%d",&nbr_sommet);
    int i,j;
    graphe g ;
    for(i=0;i<nbr_sommet;i++) g[i].sommet = i+1 ;

    for(i=0;i<nbr_sommet;i++){
        printf("le nbre succ du %d sommet :",i+1) ;
        scanf("%d",&g[i].nbr_succ);
        for(j=0;j<g[i].nbr_succ;j++){printf("succ n° %d  = ",j+1) ;  scanf("%d",&g[i].succ[j]); }
    }
    printf("-------------------------------------------\n");

    tri(g);
    colorer_sommet(g);
    printf("\n-------------------------------------------\n");
    printf("Affichage du graphe  \n") ;
    for(i=0;i<nbr_sommet;i++){
        printf(" sommet  %d  sa couleur %d  \n",g[i].sommet,g[i].couleur);
    }
    system("PAUSE") ;

    return 0;
}
