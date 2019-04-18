#ifndef ERREURFICHIERINTROUVABLE_H
#define ERREURFICHIERINTROUVABLE_H

#include <QString>
#include <QException>

using namespace std;

class ErreurFichierIntrouvable: public QException
{
public:
    ErreurFichierIntrouvable(QString s) : s_(s){}
    virtual QString what() { return s_; }
private :
    QString s_;
};
#endif // ERREURFICHIERINTROUVABLE_H
