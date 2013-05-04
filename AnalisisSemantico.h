/* 
 * File:   AnalisisSemantico.h
 * Author: zeck
 *
 * Created on May 3, 2013, 11:30 PM
 */

#ifndef ANALISISSEMANTICO_H
#define	ANALISISSEMANTICO_H

#include "QList"
#include "QString"

class moduloErrores;
class TablaSimbolos;
class AnalisisSemantico {
public:
    AnalisisSemantico();
    AnalisisSemantico(const AnalisisSemantico& orig);
    virtual ~AnalisisSemantico();
    void InicializarDatos(moduloErrores * p_moduloErrores, moduloErrores * p_tablaSimbolos, QList<QString> * p_listaLineas,
            QList<QList<QString>*> * p_listaDeListasDePalabras);
    void ComenzarAnalisis();
    moduloErrores * _moduloNotificacionErrores;
    TablaSimbolos * _tablaDeSimbolos;
    QList<QString> * _listaLineas;
    QList<QList<QString>*> * _listaDeListasDePalabras;
private:

};

#endif	/* ANALISISSEMANTICO_H */

