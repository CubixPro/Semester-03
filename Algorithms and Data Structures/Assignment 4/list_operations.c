#include"list.h"
#include<stdio.h>

node* print_list_rev(node* n){
    node* nptr = null;
    while(n != null){
        node* target ;
        init_l(&target);
        target->element = n->element;
        insert_front(target, &nptr);
        n = n->next;
    }
    display(nptr);
    return nptr;
}


node* merge(node* l1, node* l2){
    //sorted in ascending order
    node* newptr = null;
    while(!empty_l(l1) && !empty_l(l2)){
        node* nl1 = l1;
        node* nl2 = l2;
        if(nl1->element <= nl2->element){
            delete_front(&l1);
            insert_after(nl1, newptr);
            newptr = newptr->next;
        } 
        else 
        {
            delete_front(&l2);
            insert_after(nl2, newptr);
            newptr = newptr->next;
        }
        display(newptr);
    }
    if(!empty_l(l1)){
        insert_after(l1, newptr);
    }
    else if(!empty_l(l2))
    {
        insert_after(l2, newptr);
    }
    
    display(newptr);
    return newptr;
}

node* create_list(){
    node* nptr = null;
    int n;
    scanf("%d", &n);
    while(n-- != 0){
        int x;
        scanf("%d", &x);
        node* np;
        init_l(&np);
        np->element = x;
        insert_front(np, &nptr);
    }
    return nptr;
}

int main(){
    node* n;
    init_l(&n);
    node* n2;
    init_l(&n2);
    n2->element = 5;
    n->element = 4;
    insert_after(n2, n);
    display(n);
    print_list_rev(n);
    node *l1 = create_list();
    node *l2 = create_list();
    display(l1);
    display(l2);
    display(merge(l1, l2));
}