/* 
 * File:   Card.h
 * Author: nick2
 *
 * Created on November 21, 2019, 11:46 AM
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;


template <class T>
class Card {
    
private:
    T *suit;
    T *val;
    int nSuit;
    int nCards;
    
    struct Link{
        string data;
        Link *linkptr;
    };
public:
    Card();
    ~Card();
    char getVal(int);
    char getSuit(int);
    
    char returnVal(int a);
    char returnSuit(int a);
    void prntDeck();
};

#endif /* CARD_H */

template <class T>
Card<T>::~Card(){

    delete[] suit;
    delete[] val;
    suit=NULL;
    val=NULL;
}

//Suits=4 for the total suits
//nCards=13 for each suit has 13 cards

template <class T>
Card<T>::Card() {
    nSuit=52;
    nCards=52;
    Card *temp;
    suit= new T[nSuit];
    val = new T[nCards];
    
    
    int count(0);
    
    for(int z=0; z<4;z++){
        for(int i=0;i<13;i++){//This for loop creates the suit
            val[count]=temp->getVal(i);
            suit[count]=temp->getSuit(z);
            count++;
        }
    }
    
    
}

template <class T>
char Card<T>::getSuit(int n){
    switch (n){
        case 0: return'H';
        case 1: return'S';
        case 2: return'D';
        case 3: return'C';
        default: return'N'; //N = NULL
    }
}

template <class T>
char Card<T>::getVal(int n){
    switch (n){
        case 0:return('A');
        case 1:return('K');
        case 2:return('Q');
        case 3:return('J');
        case 4:return('T');
        case 5:return('9');
        case 6:return('8');
        case 7:return('7');
        case 8:return('6');
        case 9:return('5');
        case 10:return('4');
        case 11:return('3');
        case 12:return('2');
        default: return('N'); //N = NULL
    }
}


template <class T>
void Card<T>::prntDeck(){

    
    for(int i=0; i<52; i++){
      //  cout<<i<<":"<<suit[i]<<val[i]<<endl;
    }   
}

