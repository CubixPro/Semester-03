#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define bool int
#define true 1
#define false 0
#define T int
#define perror printf
#define max(a, b) ((a)>(b))?(a):(b)
typedef struct nt {
    T info;
    struct nt *left, *right;
} bintree;
bintree *t, *cur;
bintree *init_t() { return NULL; }
int empty_t(bintree *t) { return (t == NULL) ;}
bintree *makeroot(T n) {
    bintree *t;
    if((t = malloc(sizeof(bintree))) == NULL)
        perror("malloc error");

    else {

        t -> info = n;
        t -> left =NULL;
        t -> right = NULL;

    }
    return t;

}
void addleft ( bintree *t , T n ) {

    t -> left = makeroot ( n );

}

void addright ( bintree *t, T n ) {

t -> right = makeroot ( n );

}
int height ( bintree *t ) {
    if ( empty_t (t) )
    return 0;

        else

        return(1 + max(height(t -> left), height ( t -> right)));

}
bool equal_tree(bintree* t1, bintree* t2){
    if(empty_t(t1) == true && empty_t(t2) == true){
        return true;
    }
    else if(empty_t(t1) || empty_t(t2))
        return false;
    else if(t1->info == t2->info){
        return equal_tree(t1->left, t2->left)&&equal_tree(t1->right, t2->right);
    }
    else 
        return false;
}

bintree* copytree(bintree* t){
    bintree* new;
    if(!empty_t(t)){
        new = makeroot(t->info);
        new->left = copytree(t->left);
        new->right = copytree(t->right);
    }
    else{
        return NULL;
    }
    return new;

}

int main(){
    bintree* t = makeroot(5);
    addleft(t, 6);
    addright(t, 7);
    bintree* t2 = makeroot(5);
    addleft(t2, 6);
    addright(t2, 7);
    bintree* t3 = copytree(t);
    printf("%d", equal_tree(t3, t2));
    
}