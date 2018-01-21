//
// Created by Anton on 1/20/2018.
//

#ifndef EDAF50_CODING_H
#define EDAF50_CODING_H



/* For any character c, encode(c) is a character different from c */
unsigned char encode(unsigned char c);
/* For any character c, decode(encode(c)) == c */
unsigned char decode(unsigned char c);


#endif //EDAF50_CODING_H
