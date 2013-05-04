/* 
 * File:   AnalisisSintactico.h
 * Author: zeck
 *
 * Created on April 30, 2013, 10:26 PM
 */

#ifndef ANALISISSINTACTICO_H
#define	ANALISISSINTACTICO_H

#include "QList"
#include "TablaSimbolos.h"

class TablaSimbolos;
class moduloErrores;

class AnalisisSintactico {
public:
    AnalisisSintactico();
    AnalisisSintactico(const AnalisisSintactico& orig);
    virtual ~AnalisisSintactico();
    void ComenzarAnalisis();

private:
    moduloErrores * _moduloNotificacionErrores;
    TablaSimbolos * _tablaDeSimbolos;
    QList<QString> * _listaLineas;
    QList<QList<QString>*> * _listaDeListasDePalabras;
    int _posicionLineaActual;
    int _estoyEnTipoVariable; //1:estoy en variable, 2:estoy en etiqueta
    bool _estoyEnExpresion;
    void ProduccionPrograma();
    void ProduccionListaVariables();
    void ProduccionTerminalID(QString p_ID);
    void ProduccionListaDeclaraciones(int p_inicio, int p_final);
    void ProduccionDeclaracionSaltoEtiqueta(int p_indiceLista);
    void ProduccionDeclaracionEtiqueta(int p_indiceLista);
    void ProduccionDeclaracionFunciones(int p_indiceLista);
    void ProduccionDeclaracionLucesPublicas(int p_indiceLista);
    void ProduccionDeclaracionSemaforo(int p_indiceLista);
    void ProduccionDeclaracionAuto(int p_indiceLista);
    void ProduccionDeclaracionPuenteElevadizo(int p_indiceLista);
    void ProduccionDeclaracionEstudiante(int p_indiceLista);
    void ProduccionDeclaracionTermino(QString p_expresion);
    void ProduccionDeclaracionSeleccion(int p_inicio, int p_final);
    void ProduccionDeclaracionExpresion(QString p_expresion);
    void ProduccionDeclaracionIteracion(int p_inicio, int p_final);
    bool ProduccionDeclaracionTerminalOperadorRacional(const char * pOperador);
    void ProduccionDeclaracionExpesionSuma(QString p_expresion);
    bool ProduccionDeclaracionTerminalOperadorSuma(const char * pOperador);
    void ProduccionDeclaracionAsignacion(int p_indiceLinea);
    bool EsUnaProduccionFuncion(QString p_palabra);
    bool RevisarParentesis(const char * pExpresion);
    bool TerminalNUM(char * pLinea);
    void EscribirOutputSintactico();
    
    moduloErrores * ObtenerModuloErrores();
    TablaSimbolos * ObtenerTablaDeSimbolos();
    QList<QString> * ObtenerListaLineas();
    QList<QList<QString>*> * ObtenerListaListasPalabras();
};

#endif	/* ANALISISSINTACTICO_H */

