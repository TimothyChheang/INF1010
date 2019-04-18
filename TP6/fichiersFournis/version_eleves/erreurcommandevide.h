#ifndef ERREURCOMMANDEVIDE_H
#define ERREURCOMMANDEVIDE_H

#include <QException>

class ErreurCommandeVide: public QException
{
public:
    ErreurCommandeVide(QString s) : s_(s){}
    virtual QString what() { return s_; }
private :
    QString s_;
};

#endif // ERREURCOMMANDEVIDE_H
