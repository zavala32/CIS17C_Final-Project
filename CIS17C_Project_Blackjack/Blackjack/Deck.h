/* 
 * File:   Deck.h
 * Author: nick2
 *
 * Created on November 21, 2019, 11:55 AM
 */

#include <iostream>
using namespace std;

#ifndef DECK_H
#define DECK_H

template <class T>
class Deck{
    
private:    
    struct Link{
    T info;
    Link *next;
    Link *prev;
    };Link *start;
    
    
    
public:
    void create_list(T value);
    void add_begin(T value);
    void add_after(T value, int position);
    void delete_element(T value);
    void search_element(T value);
    void display_dlist();
    void count();
    void reverse();
    Link *returnStart(){
        Link *x=start;
        return (x);
    };
    
    Deck()
    {
        start=NULL;  
    }
};


#endif /* DECK_H */

//Creates the start of the linked list
template<class T>
void Deck<T>::create_list(T value){
    Link *x, *temp;
    temp=new(Link); 
    temp->info=value;
    temp->next=NULL;
    if(start==NULL){
        temp->prev=NULL;
        start=temp;
    }else{
        x=start;
        while (x->next !=NULL)
            x=x->next;
        x->next=temp;
        temp->prev=x;
    }
}
 

//Inserts an element at the very front
template<class T>
void Deck<T>::add_begin(T value){
    if(start == NULL){
        cout<<"First Create the list."<<endl;
        return;
    }
    Link *temp;
    temp=new Link;
    temp->prev=NULL;
    temp->info=value;
    temp->next=start;
    start->prev=temp;
    start=temp;
    cout<<"Element Added"<<endl;
}
 

// Inserts an element after a given element
template<class T>
void Deck<T>::add_after(T value, int pos){
    if(start == NULL){
        cout<<"First Create the list."<<endl;
        return;
    }
    Link *temp, *x;
    int i;
    x=start;
    for (i = 0;i < pos - 1;i++){
        x=x->next;
        if(x==NULL){
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        }
    }
    temp=new(Link);
    temp->info=value;
    if (x->next==NULL){
        x->next=temp;
        temp->next=NULL;
        temp->prev=x;      
    }else{
        temp->next=x->next;
        temp->next->prev=temp;
        x->next=temp;
        temp->prev=x;
    }
    cout<<"Element Inserted"<<endl;
}
 


//Deletes an element from the doubly linked list
template<class T>
void Deck<T>::delete_element(T value){
    Link *temp, *x;
     /*first element deletion*/
    if(start->info==value){
        temp=start;
        start=start->next;  
        start->prev=NULL;
        cout<<"Element Deleted"<<endl;
        free(temp);
        return;
    }
    x=start;
    while(x->next->next != NULL){   
        /*Element deleted in between*/
        if(x->next->info==value){
            temp=x->next;
            x->next=temp->next;
            temp->next->prev=x;
            cout<<"Element Deleted"<<endl;
            free(temp);
            return;
        }
        x=x->next;
    }
     /*last element deleted*/
    if(x->next->info==value){ 	
        temp=x->next;
        free(temp);
        x->next=NULL;
        cout<<"Element Deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
}
 
//Displays the entire list
template<class T>
void Deck<T>::display_dlist(){
    Link *x;
    if(start==NULL){
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    x=start;
    cout<<"The Doubly Link List is :"<<endl;
    while (x !=NULL){
        cout<<x->info<<" <-> "<<endl;
        x=x->next;
    }
    cout<<"NULL"<<endl;
}
 

//Counts the total number of elements in the list
template<class T>
void Deck<T>::count(){ 	
    Link *x=start;
    int cnt=0;
    while(x !=NULL){
        x=x->next;
        cnt++;
    }
    cout<<"Number of elements are: "<<cnt<<endl;
}
 

//Prints the list in reverse
template<class T>
void Deck<T>::reverse(){
    Link *x1, *x2;
    x1=start;
    x2=x1->next;
    x1->next=NULL;
    x1->prev=x2;
    while(x2 !=NULL){
        x2->prev=x2->next;
        x2->next=x1;
        x1=x2;
        x2=x2->prev; 
    }
    start=x1;
    cout<<"List Backwards"<<endl; 
}

