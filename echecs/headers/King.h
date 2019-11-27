/**
 * @author Leo
 * @brief  classe de la piece roi
 * @class Roi.h include "headers/.h"
 * @version 1.0
 * @date 27/11/19
 */

#ifndef KING_H
#define KING_H

#include <iostream>
#include "Piece.h"

class King : public Piece
{
private:
public:
    King() {}
    King(const Color & color,const pairCoord & coord);
//    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix){}
    virtual std::vector<pairCoord> legalMoves(const std::vector<std::vector<std::shared_ptr<Piece>>> & matrix,
                                              const std::vector<std::vector<pairCoord>> listMovesOpponent);
    bool find(const pairCoord & coordPiece,const std::vector<std::vector<pairCoord>> & listMovesOpponent);
};

#endif // KING_H