/* 
 * File:   TablaSimbolos.h
 * Author: zeck
 *
 * Created on May 1, 2013, 1:38 AM
 */

#ifndef TABLASIMBOLOS_H
#define	TABLASIMBOLOS_H

#include "QList"

class TablaSimbolos {
public:
     QList<QString> * _tiposVariables;
     QList<QString> * _nombresVariables;
     QList<int> * _numeroDeUsos;
    TablaSimbolos();
    TablaSimbolos(const TablaSimbolos& orig);
    virtual ~TablaSimbolos();
    void AgregarVariable(QString p_tipoVariable,QString p_nombreVariable);
    int AgregarUsoVariable(QString p_nombreVariable);
    int IndiceVariable(QString p_nombreVariable);
    void ImprimirTablaSimbolos();
private:


};

#endif	/* TABLASIMBOLOS_H */

