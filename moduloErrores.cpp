/* 
 * File:   moduloErrores.cpp
 * Author: zeck
 * 
 * Created on May 1, 2013, 12:27 AM
 */

#include <qstring.h>

#include "moduloErrores.h"

moduloErrores::moduloErrores() {

}

moduloErrores::moduloErrores(const moduloErrores& orig) {
}

moduloErrores::~moduloErrores() {
}

void moduloErrores::RegistrarErrorSemanticoSimpreVerdad(QString p_nombreVariable) {
    QString m_error = "ErrorSimpreVerdad: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSemanticoNoSeUsa(QString p_nombreVariable) {
    QString m_error = "ErrorNoSeUsa: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoHaySinoSinSi(QString p_nombreVariable) {
    QString m_error = "ErrorHaySinoSinSi: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoNoHayIncioSi(QString p_nombreVariable) {
    QString m_error = "ErrorNoHayInicioSi: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoNoHayIncioMientras(QString p_nombreVariable) {
    QString m_error = "ErrorNoHayIncioMientras: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoNoHayFinMientras(QString p_nombreVariable) {
    QString m_error = "ErrorNoHayFinMientras: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoNoHayFinSi(QString p_nombreVariable) {
    QString m_error = "ErrorNoHayFinSi: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoNoHayHaga(QString p_nombreVariable) {
    QString m_error = "ErrorNoHayHaga: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoNoHayEntonces(QString p_nombreVariable) {
    QString m_error = "ErrorNoHayEntonces: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoParentesisVacio(QString p_nombreVariable) {
    QString m_error = "ErrorParentesisVacio: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoSobranParentesis(QString p_nombreVariable) {
    QString m_error = "ErrorSobranParentesis: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoOperadorSuma(QString p_nombreVariable, QString p_expresion) {
    QString m_error = "ErrorOperadorSuma: ";
    m_error.append(p_nombreVariable);
    m_error.append(":");
    m_error.append(p_expresion);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoOperadorRacional(QString p_nombreVariable, QString p_expresion) {
    QString m_error = "ErrorOperadorRacional: ";
    m_error.append(p_nombreVariable);
    m_error.append(":");
    m_error.append(p_expresion);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoVariableNoDeclarada(QString p_nombreVariable, QString p_expresion) {
    QString m_error = "variableNoDeclarada: ";
    m_error.append(p_nombreVariable);
    m_error.append(":");
    m_error.append(p_expresion);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoVariableNoValida(QString p_nombreVariable, QString p_expresion) {
    QString m_error = "variableNoValida: ";
    m_error.append(p_nombreVariable);
    m_error.append(":");
    m_error.append(p_expresion);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}
void moduloErrores::RegistrarErrorSintacticoAccionInvalida(QString p_nombreVariable) {
    QString m_error = "AccionInvalida: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}
void moduloErrores::CrearNuevoRegistroErrores() {
    _archivoErrores = new ManejoDeArchivosExternos;
    _archivoErrores->CrearArchivo("MóduloErrores.txt");
}

void moduloErrores::AgregarMasErroresRegistro() {
    _archivoErrores = new ManejoDeArchivosExternos;
    _archivoErrores->AnadirTexto("MóduloErrores.txt");
}

void moduloErrores::RegistrarTerminarEscritura() {
    _archivoErrores->CerrarArchivoEscritura();
}