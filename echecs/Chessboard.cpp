#include <vector>
#include <iostream>
#include "headers/Chessboard.h"
#include "headers/Pawn.h"
#include "headers/Empty.h"
#include "headers/Rook.h"
#include "headers/Knight.h"
#include "headers/Bishop.h"
#include "headers/Queen.h"
#include "headers/King.h"

using namespace std;

ChessBoard::ChessBoard() {

    myChessBoard.resize(8,vector<shared_ptr<Piece>>(8));

    for (unsigned i(0); i < 8;++i) {
        for(unsigned j(0); j < 8; ++j)
        {
            // cases vides
            myChessBoard[i][j] = shared_ptr<Piece>(new Empty(pairCoord(i,j)));
        }
    }
    for (unsigned i(0); i < 8;++i)
    {
        // pions blancs
        myChessBoard[6][i] = shared_ptr<Piece>(new Pawn(white,pairCoord(6,i)));
        // pions noirs
        myChessBoard[1][i] = shared_ptr<Piece>(new Pawn(black,pairCoord(1,i)));

    }

    // tours blancs
    myChessBoard[7][0] = shared_ptr<Piece>(new Rook(white,pairCoord(7,0)));
    myChessBoard[7][7] = shared_ptr<Piece>(new Rook(white,pairCoord(7,7)));
    // tours noirs
    myChessBoard[0][0] = shared_ptr<Piece>(new Rook(black,pairCoord(7,0)));
    myChessBoard[0][7] = shared_ptr<Piece>(new Rook(black,pairCoord(7,7)));

    // cavaliers blancs
    myChessBoard[7][1] = shared_ptr<Piece>(new Knight(white,pairCoord(7,1)));
    myChessBoard[7][6] = shared_ptr<Piece>(new Knight(white,pairCoord(7,6)));
    // cavaliers noirs
    myChessBoard[0][1] = shared_ptr<Piece>(new Knight(black,pairCoord(7,1)));
    myChessBoard[0][6] = shared_ptr<Piece>(new Knight(black,pairCoord(7,6)));

    // fous blancs
    myChessBoard[7][2] = shared_ptr<Piece>(new Bishop(white,pairCoord(7,2)));
    myChessBoard[7][5] = shared_ptr<Piece>(new Bishop(white,pairCoord(7,5)));
    // fous noirs
    myChessBoard[0][2] = shared_ptr<Piece>(new Bishop(black,pairCoord(7,2)));
    myChessBoard[0][5] = shared_ptr<Piece>(new Bishop(black,pairCoord(7,5)));

    //Reine blanche
    myChessBoard[7][3] = shared_ptr<Piece>(new Queen(white,pairCoord(7,3)));
    //Reine noire
    myChessBoard[0][3] = shared_ptr<Piece>(new Queen(black,pairCoord(0,3)));

    //Roi Blanc
    myChessBoard[7][4] = shared_ptr<Piece>(new King(white,pairCoord(7,4)));

    //Roi noir
    myChessBoard[0][4] = shared_ptr<Piece>(new King(black,pairCoord(0,4)));

}//ChessBoard ()

void ChessBoard::show() const
{

    cout << " a b c d e f g h"<< endl;
    for (unsigned i(0); i < 8; ++i)
    {
        for (unsigned j(0); j < 8; ++j)
        {
            if ( j == 0)
                cout << '|';
            cout << myChessBoard[i][j]->getCarac() << '|';
            if ( j == 7)
                cout << i+1;
        }
        cout << endl;
    }
}//show()

void ChessBoard::move(const pairCoord & coordMove,const pairCoord & coordPiece)
{
    //Si la case est vide
    if(this->myChessBoard[coordMove.first][coordMove.second]->getName() == "Empty")
    {
        //On effectue un swap entre la pièce vide et la pièce vide
        shared_ptr<Piece> tmp = this->myChessBoard[coordMove.first][coordMove.second];
        this->myChessBoard[coordMove.first][coordMove.second] = this->myChessBoard[coordPiece.first][coordPiece.second];
        this->myChessBoard[coordPiece.first][coordPiece.second] = tmp;
        //On set les coordonées à leur nouvelle coordonée
        this->myChessBoard[coordMove.first][coordMove.second]->setCoord(coordMove);
        this->myChessBoard[coordPiece.first][coordPiece.second]->setCoord(coordPiece);
    }
    else //Si on "mange" une pièce adverse
    {
        unsigned indiceColorOpponent;
        this->myChessBoard[coordMove.first][coordMove.second]->getColor() == white ? indiceColorOpponent = 0 : indiceColorOpponent = 1;
        //On la place dans lal iste des pièces mortes
        this->myDeadPiece[indiceColorOpponent].push_back(myChessBoard[coordMove.first][coordMove.second]);
        //On remplace la piece mangé par la pièce bougé
        this->myChessBoard[coordMove.first][coordMove.second] = this->myChessBoard[coordPiece.first][coordPiece.second];
        //On actualise ses coordonées
        this->myChessBoard[coordMove.first][coordMove.second]->setCoord(coordMove);
        //On créer un objet vide à son ancienne place
        this->myChessBoard[coordPiece.first][coordPiece.second] = shared_ptr<Piece>(new Empty(coordPiece));
    }
}//move()


Matrix ChessBoard::getChessboard() const {return myChessBoard;}



