/* 
 * File:   Queue.h
 * Author: nick2
 *
 * Created on November 21, 2019, 11:53 AM
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <deque>
#include <exception>


template <typename T>
class Queue {
    protected:
        std::deque<T> c;        //Container of elements

    public:
        // Empty queue pop()and front() In operation About exception

        class ReadEmptyQueue : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "read empty queue";
                }
        };

        // Of the elements Count
        typename std::deque<T>::size_type size() const {
            return c.size();
        }

        // The queue Is it empty?
        bool empty() const {
            return c.empty();
        }

        // In the queue element insertion
        void push (const T& elem) {
            c.push_back(elem);
        }

        // In the queue next Element Remove Value return
        T pop() {
            if (c.empty()) {
                throw ReadEmptyQueue();
            }

            T elem(c.front());
            c.pop_front();
            return elem;
        }

        // next Elemental Value Returns
        T& front() {
            if (c.empty()) {
                throw ReadEmptyQueue();
            }

            return c.front();
        }
};


#endif /* QUE_H */

