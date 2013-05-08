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
#include "TablaSimbolos.h"

class moduloErrores;
class TablaSimbolos;
class AnalisisSemantico {
public:
    AnalisisSemantico();
    AnalisisSemantico(const AnalisisSemantico& orig);
    virtual ~AnalisisSemantico();
    void InicializarDatos(moduloErrores * p_moduloErrores, TablaSimbolos * p_tablaSimbolos, QList<QString> * p_listaLineas,
            QList<QList<QString>*> * p_listaDeListasDePalabras,int * p_listaPosiciones);
    void ComenzarAnalisis();
private:
    moduloErrores * _moduloNotificacionErrores;
    TablaSimbolos * _tablaDeSimbolos;
    QList<QString> * _listaLineas;
    QList<QList<QString>*> * _listaDeListasDePalabras;
    int * _listaLineasAEliminar;
    int * _listaPosiciones;
    int _indiceLineaAEliminar;
    int _indiceLineaActual;
    bool _estadoCarro; //true: encendido, false: apagado
    void RedireccionarLineas(QString p_formaInicio, QString p_formaFinal, int p_destinoSi);
    int EvaluarCondicionExpresion(QList<QString> * p_listaListaDePalabras,QString pListaPalabras);
    int BuscarVariables(QString pExpresion);
    int EvaluarExpresionSinVariable(QString pLinea);
    bool EvaluarOperadorRacional(char * pOperadorRacional, int pNumeroIzq, int pNumeroDer);
    void ValorarLineas(int pDestinoMientras, int pDestinoIf);
    void EliminarLineas(QString pFormaIncio, QString pFormaFinal);
    void RevisarVariablesSinUso();
    void EscribirOutputSemantico();
};

#endif	/* ANALISISSEMANTICO_H */

