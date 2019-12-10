/* 
 * File:   Stack.h
 * Author: nick2
 *
 * Created on November 21, 2019, 11:53 AM
 */

#ifndef STACK_H
#define STACK_H

#include <deque>
#include <exception>

template <typename T>
class Stack {
    private:
        std::deque<T> c;
    public:
        // exception class for pop() and top() with empty stack 
        class ReadEmptyStack: public std::exception {
            public:
                virtual const char* what() const throw(){
                    return "read empty stack";
                }
        };

        //number of elements
        typename std::deque<T>::size_type size() const {
            return c.size();
        }

        // is stack empty?
        bool empty() const {
            return c.empty();
        }

        void push (const T& elem){
            c.push_back(elem);
        }

        // pop element out of the stack and return its value 
        T pop (){
            if (c.empty()){
                throw ReadEmptyStack();
            }
            T elem(c.back());
            c.pop_back();
            return elem;
        }

        //return value of next element 
        T& top (){
            if (c.empty()){
                throw ReadEmptyStack();
            }
            return c.back();
        }
    
};


#endif /* STACK_H */

