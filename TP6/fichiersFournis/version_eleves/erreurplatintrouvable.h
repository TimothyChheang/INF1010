#ifndef ERREURPLATINTROUVABLE_H
#define ERREURPLATINTROUVABLE_H

#include <QString>
#include <QException>

using namespace std;

class ErreurPlatIntrouvable: public QException
{
public:
    ErreurPlatIntrouvable(QString s) : s_(s){}
    virtual QString what() { return s_; }
private :
    QString s_;
};

#endif // ERREURPLATINTROUVABLE_H
