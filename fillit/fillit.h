//
// Created by cristian on 12/24/16.
//

#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H
/*
**Tetrimino is a classic piece of Tetris composed of 4 blocks.
*/
typedef struct  s_piece
{
    char        letter;
    short       coord[4][2];
}               t_piece;

#endif //FILLIT_FILLIT_H
