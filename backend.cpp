#include "backend.h"

using namespace std;

Backend::Backend(QObject* parent): QObject(parent) {
    game = Game::getInstance(); // inizializzo il gioco
    m_playerBar = game->getPlayerHealth();
    m_monsterBar = game->getMonsterHealth();
    m_gameOver = game->gameOver();
    m_healEnabled = game->healEnabled();
    m_winner =  QString::fromStdString(game->getWinner());
}

// SLOTS

void Backend::attack(){
    game->attackMonster();
    setAllValues();
}

void Backend::heal(){
    game->heal();
    setAllValues();
}

void Backend::playAgain(){
    game->restart();
    setAllValues();
}

// GETTERS

int Backend::playerBar() const {
 return m_playerBar;
}

int Backend::monsterBar() const {
 return m_monsterBar;
}

bool Backend::gameOver() const {
 return m_gameOver;
}

bool Backend::healEnabled() const{
    return m_healEnabled;
}

QString Backend::winner() const{
    return m_winner;
}

// SETTERS

void Backend::setPlayerBar(int value) {
 if(m_playerBar != value) {
   m_playerBar = value;
   emit playerBarChanged(); // trigger signal of counter change
 }
}

void Backend::setMonsterBar(int value) {
 if(m_monsterBar != value) {
   m_monsterBar = value;
   emit monsterBarChanged(); // trigger signal of counter change
 }
}

void Backend::setGameOver(bool value) {
 if(m_gameOver != value) {
   m_gameOver = value;
   emit gameOverChanged(); // trigger signal of game changed
 }
}

void Backend::setHealEnabled(bool value) {
 if(m_healEnabled != value) {
   m_healEnabled = value;
   emit healEnabledChanged(); // trigger signal of game changed
 }
}

void Backend::setWinner(QString value) {
 if(m_winner != value) {
   m_winner = value;
   emit winnerChanged(); // trigger signal of game changed
 }
}

// SETTERS FOR ALL

void Backend::setAllValues(){
    setPlayerBar(game->getPlayerHealth());
    setMonsterBar(game->getMonsterHealth());
    setGameOver(game->gameOver());
    setHealEnabled(game->healEnabled());
    setWinner(QString::fromStdString(game->getWinner()));
}
