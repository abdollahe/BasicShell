//
// Created by Abdollah Ebadi on 2018-12-24.
//

#ifndef BASICSHELL_READER_H
#define BASICSHELL_READER_H


class Reader {

private:
    int BUFFER_SIZE = 1024 ;

public:
    Reader() ;
    Reader(int bufferSize) ;

    char* read_line() ;

};


#endif //BASICSHELL_READER_H
