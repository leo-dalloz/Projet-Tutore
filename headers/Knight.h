#ifndef KNIGHT_H
#define KNIGHT_H


#include <iostream>
#include "Piece.h"

class Knight : public Piece
{
private:
public:
    Knight() {}
    Knight(const Color & color,const pairCoord & coord);
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix);
};

#endif // KNIGHT_H