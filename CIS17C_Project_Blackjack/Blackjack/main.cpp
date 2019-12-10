/* 
 * File:   main.cpp
 * Author: nick2
 *
 * Created on November 21, 2019, 11:44 AM
 */

#include <iostream>
#include <string>
#include <ctime>
#include <stack>
#include <map>
#include <iomanip>
#include <fstream>
#include <exception>
#include <fstream>

#include "Card.h"
#include "Deck.h"
#include "Stack.h"
#include "Queue.h"


using namespace std;

void randStack(Stack <int> &);
void randQue(Queue <int> &);
void ruleHelp(std::map<string,int> &,std::map<string,int>::iterator &);
int playGame(Card<char> &, Stack<int> &, Queue<int> &);
int calTotal(int);

/*
 * 
 */
int main(int argc, char** argv) {
    int x(0);
    srand (time(0));
    char answer;
    
    ofstream out;
    out.open("names.txt",ios::app);
    
    ifstream in;
    in.open("names.txt");
    
    std::map<string,int> mapValue;
    std::map<string,int>::iterator it;
    
    Card<char> game;    //The class holding th deck of cards
    Stack<int> order1;  //The class holding the Stack of random numbers
    Queue<int> q;       //The class holding the Queue of random numbers
    
    
    
    cout<<"Welcome to 21 enter H for help or type any thing else to start the game: ";
    cin>>answer;
    if(answer=='H'||answer=='h'){ruleHelp(mapValue,it);} //Display the rules using a map

     
    
    //Set a random order of numbers by using a Stack
    //Set a random order of numbers by using a Queue
    randStack(order1);
    randQue(q);
    
    
    cout<<endl;
    //Shuffled deck
    
    
    for(int i=0; i<52; i++){
        //cout<<game.returnSuit(order1.pop())<<game.returnVal(q.pop())<<endl;
        //cout<<order1.pop()<<" "<<q.pop()<<endl;
    } 
    
    
    
    
    //Outputs your name and whether you lost or won to a txt file
    string name;
    x=playGame(game,order1,q);
    cout<<endl<<endl;
    
    
    if(x==0){
        cout<<"Please enter your name"<<endl;
        cin>>name;
        out<<endl<<name<<".Lost";
    }
        if(x==1){
        cout<<"Please enter your name"<<endl;
        cin>>name;
        out<<endl<<name<<".Won";
    }
        if(x==2){
        cout<<"Please enter your name"<<endl;
        cin>>name;
        out<<endl<<name<<".Tied";
    }
    
    string names;
    
    
    int y(0);
    Deck<string> dk;
    //in>>names;
    
while(in>>names){
    dk.create_list(names);
    y++;
}


    dk.display_dlist();

    return 0;
}




//cout<<game.returnSuit(order1.pop())<<game.returnVal(q.pop())<<endl;


int calTotal(char n){
    
    if(n=='K'||n=='Q'||n=='J'||n=='T'){
        return(10);
    }
    if(n=='A'){return(1);}
    if(n=='2'){return(2);}
    if(n=='3'){return(3);}
    if(n=='4'){return(4);}
    if(n=='5'){return(5);}
    if(n=='6'){return(6);}
    if(n=='7'){return(7);}
    if(n=='8'){return(8);}
    if(n=='9'){return(9);}
    
}


int playGame(Card<char> &game, Stack<int> &stackSuit, Queue<int> &randDeck){
    int tempp,tempp2;
    int result(0);
    bool play=false;
    char answer;
    int suit(0),deck(0);
    int total(0),dTotal(0);
        //Deals the first two cards of the deck
    for(int i=0;i<2;i++){
            cout<<game.getSuit(stackSuit.pop()); //Print the first suit
            tempp=randDeck.pop(); //Print the first card
            
            cout<<game.getVal(tempp)<<" ";
            
            tempp2=calTotal(game.getVal(tempp));
            
            total+=tempp2; //Calculate player total
            suit++;
            deck++;
            
    }
    
    //Asks the user if they want another card
    cout<<" Total:"<<total<<" "<<" Do you want another card Y=yes,N=no: ";
    do{
        
        cin>>answer;
        //If the user says yes then deal another card
        if(answer=='y'||answer=='Y'){
                cout<<game.getSuit(stackSuit.pop()); //Print the random suit
                tempp=randDeck.pop(); //Print the random card
                
                cout<<game.getVal(tempp);
                
                tempp2=calTotal(game.getVal(tempp));
                total+=tempp2; //Calculate Players total
                cout<<" Total:"<<total<<" "<<" Do you want another card Y=yes,N=no: ";

                suit++; //move to the next random suit
                deck++; //move to the next random card
                
                
        }else{
            play=true;
        }
        //End the game if the end of the deck is reached
        if(suit==52){play=true;cout<<"No more cards New Game";} 
        if(deck>13){deck=0;} //Reset the counter
        
    }while(play!=true);
    
    //Calculate the dealer total
    tempp=0;
    tempp2=0;
    
    
    for(int i=0;i<2;i++){
        tempp=randDeck.pop();
        tempp2=calTotal(game.getVal(tempp));//Print the random card
        
        dTotal+=tempp2;
        suit++;
        deck++;
            
    }
    //Display the Dealers total
    cout<<"Dealer Total: "<<dTotal;
    
    //Decide who won
    cout<<endl;
    
    if(dTotal<=21&&total<=21){
        if(dTotal>total){
            cout<<"dealer won";
            result=0;
            
        }else if(dTotal<total){
            cout<<"you won";
            result=1;
        }else{
            cout<<"Its a tied";
            result=2;
        }
    }else{
        if(dTotal>21){
            cout<<"dealer won";
            result=0;
        }else if(21<total){
            cout<<"you won";
            result=1;
        }else {
            cout<<"no one wins";
            result=3;
        }
    }
    return result;
    
    
}






void ruleHelp(std::map<string,int> &mymap, std::map<string,int>::iterator &it){
    cout<<"Welcome to 21. The goal of the game is to get "
          "21 but not go over using the following cards "<<endl;
    
    mymap["Two"]=2;
    mymap["Three"]=3;
    mymap["Four"]=4;
    mymap["Five"]=5;
    mymap["Six"]=6;
    mymap["Seven"]=7;
    mymap["Eight"]=8;
    mymap["Nine"]=9;
    mymap["Ten"]=10;
    mymap["Jack"]=10;
    mymap["Queen"]=10;
    mymap["King"]=10;
    mymap["Ace"]=1;
    
    for (it=mymap.begin(); it!=mymap.end(); ++it){
        cout << it->first << " => " << it->second << '\n';
    }

    

}


void randQue(Queue <int>& order){
   
    //Fill an array with numbers from 0-51
    int numbers[52] = {};
    for(int i=0; i<52; i++){
        numbers[i]=i;
    }
    
    //Shuffle the array 7 times
    for(int z=0; z<7;z++){
        for (int i=51; i>0; --i){
            
          //get swap index
          int j=rand()%i;
          
          //swap p[i] with p[j]
          int temp=numbers[i];
          numbers[i]=numbers[j];
          numbers[j]=temp;
        }
    }
    
    //copy first n elements from p to arr
    for (int i=0; i<52; ++i){
      order.push(numbers[i]);
    }

}


void randStack(Stack <int>&order){
    
    //Fill an array with numbers from 0-51
    int numbers[52]={};
    for(int i=0; i<52; i++){
        numbers[i]=i;
    }
    
    //Shuffle the array 7 times
    for(int z=0; z<7;z++){
        for (int i=51; i>0; --i){
          //get swap index
          int j = rand()%i;
          //swap p[i] with p[j]
          int temp=numbers[i];
          numbers[i]=numbers[j];
          numbers[j]=temp;
        }
    }
    
    //copy first n elements from p to arr
    for (int i=0; i<52; ++i){
      order.push(numbers[i]);
    }

}

int *sortArry(int a[], int size){
    
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }

}

