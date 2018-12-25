//
// Created by Abdollah Ebadi on 2018-12-24.
//

#include "Reader.h"
#include <iostream>
#include <cstdio>


Reader::Reader() {

}

Reader::Reader(int bufferSize) {

    this->BUFFER_SIZE = bufferSize ;

}

char* Reader::read_line() {

    //Define a buffer to hold the string of characters
    char* buffer = new char[BUFFER_SIZE] ;
    int position = 0 ;

    while(1) {
       int c = getchar() ;

       if(c == EOF || c == '\n') {
           buffer[position] = '\n' ;
           return buffer ;
       }
       else {
           buffer[position] = c ;
           position++ ;
       }

    }

}
