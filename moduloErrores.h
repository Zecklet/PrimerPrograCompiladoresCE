/* 
 * File:   moduloErrores.h
 * Author: zeck
 *
 * Created on May 1, 2013, 12:27 AM
 */

#ifndef MODULOERRORES_H
#define	MODULOERRORES_H

#include "QString"
#include "ManejoDeArchivosExternos.h"

class ManejoXML;

class moduloErrores {
public:
    moduloErrores();
    moduloErrores(const moduloErrores& orig);
    virtual ~moduloErrores();
    void CrearNuevoRegistroErroresSintactico();
    void CrearNuevoRegistroErroresSemantico();
    void RegistrarErrorSemanticoCarroApagado(int p_posicion, QString p_expresion);
    void RegistrarErrorSemanticoSimpreVerdad(int p_posicion, QString p_variable, QString p_expresion );
    void RegistrarErrorSemanticoNoSeUsa(int p_posicion, QString p_variable, QString p_expresion );
    void RegistrarErrorSintacticoHaySinoSinSi(int p_posicion,QString p_expresion);
    void RegistrarErrorSintacticoNoHayIncioSi(int p_posicion,QString p_expresion);
    void RegistrarErrorSintacticoNoHayIncioMientras(int p_posicion,QString p_expresion);
    void RegistrarErrorSintacticoNoHayFinMientras(int p_posicion,QString p_expresion);
    void RegistrarErrorSintacticoNoHayFinSi(int p_posicion,QString p_expresion);
    void RegistrarErrorSintacticoNoHayHaga(int p_posicion,QString p_expresion);
    void RegistrarErrorSintacticoNoHayEntonces(int p_posicion,QString p_expresion);
    void RegistrarErrorSintacticoParentesisVacio(int p_posicion,QString p_expresion);
    void RegistrarErrorSintacticoSobranParentesis(int p_posicion,QString p_expresion);
    void RegistrarErrorSintacticoOperadorSuma(int p_posicion, QString p_variable, QString p_expresion );
    void RegistrarErrorSintacticoOperadorRacional(int p_posicion, QString p_variable, QString p_expresion );
    void RegistrarErrorSintacticoVariableNoDeclarada(int p_posicion, QString p_variable, QString p_expresion );
    void RegistrarErrorSintacticoVariableNoValida(int p_posicion, QString p_variable, QString p_expresion );
    void RegistrarErrorSintacticoAccionInvalida(int p_posicion, QString p_expresion);
    void RegistrarErrorSintacticoTerminalPerdido(int p_posicion, QString p_expresion);
    void RegistrarErrorSintacticoExpresionVacia(int p_posicion, QString p_expresion);
    void RegistrarErrorSintacticoIgualdadVacia(int p_posicion, QString p_expresion);
    void RegistrarTerminarEscritura();
    

    int ObtenerNumeroDeErroresSemanticos();
    int ObtenerNumeroDeErroresSintacticos();
private:
    ManejoXML * _archivoXML;
    ManejoDeArchivosExternos * _archivoErrores;
    int _numeroErroresSintacticos;
    int _numeroErroresSemanticos;
};

#endif	/* MODULOERRORES_H */

