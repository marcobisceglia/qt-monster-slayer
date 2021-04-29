#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <string>
#include <cstdlib> // for random numbers
#include "logic/game.h"

using namespace std;

class Backend: public QObject{
    Q_OBJECT
    Q_PROPERTY(int playerBar READ playerBar WRITE setPlayerBar NOTIFY playerBarChanged) // this makes counter available as a QML property
    Q_PROPERTY(int monsterBar READ monsterBar WRITE setMonsterBar NOTIFY monsterBarChanged) // this makes counter available as a QML property
    Q_PROPERTY(bool gameOver READ gameOver WRITE setGameOver NOTIFY gameOverChanged) // this makes game status available as a QML property
    Q_PROPERTY(bool healEnabled READ healEnabled WRITE setHealEnabled NOTIFY healEnabledChanged) // this makes heal available as a QML property
    Q_PROPERTY(QString winner READ winner WRITE setWinner NOTIFY winnerChanged) // this makes winner available as a QML property

private:
    Game *game;
    int m_playerBar;
    int m_monsterBar;
    bool m_gameOver;
    bool m_healEnabled;
    QString m_winner;

public:
    // constructor, this object has no parents
    explicit Backend(QObject* parent = 0);

    // getters
    int playerBar() const;
    int monsterBar() const;
    bool gameOver() const;
    bool healEnabled() const;
    QString winner() const;

    // setters
    void setPlayerBar(int value);
    void setMonsterBar(int value);
    void setGameOver(bool value);
    void setHealEnabled(bool value);
    void setWinner(QString value);

    // setter for all
    void setAllValues();

// FROM QML -> C++: slots are public methods available in QML
public slots:
    void attack();
    void heal();
    void playAgain();

// FROM C++ -> QML
signals:
    void playerBarChanged();
    void monsterBarChanged();
    void gameOverChanged();
    void healEnabledChanged();
    void winnerChanged();
};

#endif // BACKEND_H
