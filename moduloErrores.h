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

class moduloErrores {
public:
    moduloErrores();
    moduloErrores(const moduloErrores& orig);
    virtual ~moduloErrores();
    void CrearNuevoRegistroErrores();
    void AgregarMasErroresRegistro();

    void RegistrarErrorSemanticoSimpreVerdad(QString p_linea, QString p_expresion);
    void RegistrarErrorSemanticoNoSeUsa(QString p_linea, QString p_expresion);
    void RegistrarErrorSintacticoHaySinoSinSi(QString p_nombreVariable);
    void RegistrarErrorSintacticoNoHayIncioSi(QString p_nombreVariable);
    void RegistrarErrorSintacticoNoHayIncioMientras(QString p_nombreVariable);
    void RegistrarErrorSintacticoNoHayFinMientras(QString p_nombreVariable);
    void RegistrarErrorSintacticoNoHayFinSi(QString p_nombreVariable);
    void RegistrarErrorSintacticoNoHayHaga(QString p_nombreVariable);
    void RegistrarErrorSintacticoNoHayEntonces(QString p_nombreVariable);
    void RegistrarErrorSintacticoParentesisVacio(QString p_nombreVariable);
    void RegistrarErrorSintacticoSobranParentesis(QString p_nombreVariable);
    void RegistrarErrorSintacticoOperadorSuma(QString p_nombreVariable, QString p_expresion);
    void RegistrarErrorSintacticoOperadorRacional(QString p_nombreVariable, QString p_expresion);
    void RegistrarErrorSintacticoVariableNoDeclarada(QString p_nombreVariable, QString p_expresion);
    void RegistrarErrorSintacticoVariableNoValida(QString p_nombreVariable, QString p_expresion);
    void RegistrarErrorSintacticoAccionInvalida(QString p_nombreVariable);
    void RegistrarTerminarEscritura();
private:
    ManejoDeArchivosExternos * _archivoErrores;
    int _numeroErrores;
};

#endif	/* MODULOERRORES_H */

