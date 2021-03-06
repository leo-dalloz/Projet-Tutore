#include "MessageBox.h"

MessageBox::MessageBox(std::string Name,std::string Text)
{
    this->init();

    this->setWindowTitle(QString::fromStdString(Name));
    this->setText(QString::fromStdString(Text));
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet(
                "background-color: rgba(101,33,33,1);"
                "font-size:24px;"
                "color:white;"
                );

    QIcon iconMainWindow (":/Ressources/Pieces/PawnBlack.png"); //useless avec la frame disparu
    this->setWindowIcon(iconMainWindow);
    this->setWindowTitle("Message");

    this->exec();
}
