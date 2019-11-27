#include "tictactoewidget.h"

TicTacToeWidget::TicTacToeWidget(QWidget *parent) : QWidget(parent)
{
    m_currentPlayer = Player::Invalid;
    for (int column = 0 ; column < 3 ; ++column) {
        for (int row = 0 ; row < 3 ; ++ row) {
            QPushButton * button = new QPushButton(" ");
            gridLayout->addWidget(button , row , column);
            m_board.append(button);
            mapper->setMapping(button , m_board.count() - 1);
            connect(button , SIGNAL(clicked()) , mapper , SLOT(map()));
        }
    }
    connect(mapper , SIGNAL(mapper(int)) , this , SLOT(handleButtonClicked(int)));
}

void TicTacToeWidget::handleButtonClicked(int index)
{
    if(m_currentPlayer == Player::Invalid)return;
    if(index < 0 || index >= m_board.size())return;
    QPushButton * button = m_board[index];
    if(button ->text() != " ")return;
    button->setText(currentPlayer() == Player::player1 ? "X" : "O");
    Player winner = checkWinCondition();
    if(winner == Player::Invalid){
        setCurrentPlayer(currentPlayer() == Player::player1 ? Player::player2 : Player::player1);
        return;
    }else{
        emit gameOver(winner);
    }
}
