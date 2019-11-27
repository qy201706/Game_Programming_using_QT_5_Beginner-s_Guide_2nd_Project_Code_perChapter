#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>

class TicTacToeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TicTacToeWidget(QWidget *parent = nullptr);
    enum class Player{
        Invalid , player1 , player2 , Draw
    };
    Q_ENUM(Player)
    Player currentPlayer()const { return m_currentPlayer; }
    void setCurrentPlayer(Player p){
        if(m_currentPlayer == p){return;}
        m_currentPlayer = p;
        emit currentPlayerChanged(p);
    }
    Player checkWinCondition()                          //自制的游戏规则
    {

    }
    void initgame(){
        for(QPushButton * button : m_board)
            button->setText(" ");
        setCurrentPlayer(Player::player1);
    }

signals:
    void currentPlayerChanged(Player);
    void gameOver(Player);

public slots:

private:
    QVector<QPushButton *>m_board;                      //存储按钮对象
    QGridLayout *gridLayout = new QGridLayout(this);    //网格对象用于规范9个按钮
    QSignalMapper * mapper = new QSignalMapper(this);   //映射，使按钮标号对应数字
    Player m_currentPlayer;                             //代表玩家的变量

private slots:
    void handleButtonClicked(int index);
};


#endif // TICTACTOEWIDGET_H
