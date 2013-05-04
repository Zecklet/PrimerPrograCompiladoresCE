/* 
 * File:   moduloErrores.cpp
 * Author: zeck
 * 
 * Created on May 1, 2013, 12:27 AM
 */

#include <qstring.h>

#include "moduloErrores.h"
#include "ManejoXML.h"
#include "Constantes.h"

moduloErrores::moduloErrores() {
    this->_numeroErrores = 0;
}

moduloErrores::moduloErrores(const moduloErrores& orig) {
}

moduloErrores::~moduloErrores() {
}

void moduloErrores::RegistrarErrorSemanticoCarroApagado() {
    QString m_error = "ErrorSimpreVerdad: Se intento mover el auto, pero se encuentra apagado";
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSemanticoSimpreVerdad(QString p_linea, QString p_expresion) {
    QString m_error = "ErrorSimpreVerdad: ";
    m_error.append(p_expresion);
    m_error.append(":");
    m_error.append(p_linea);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSemanticoNoSeUsa(QString p_linea, QString p_expresion) {
    QString m_error = "ErrorNoSeUsa: ";
    m_error.append(p_expresion);
    m_error.append(":");
    m_error.append(p_linea);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
}

void moduloErrores::RegistrarErrorSintacticoHaySinoSinSi(QString p_nombreVariable) {
    QString m_error = "ErrorHaySinoSinSi: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoNoHayIncioSi(QString p_nombreVariable) {
    QString m_error = "ErrorNoHayInicioSi: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoNoHayIncioMientras(QString p_nombreVariable) {
    QString m_error = "ErrorNoHayIncioMientras: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoNoHayFinMientras(QString p_nombreVariable) {
    QString m_error = "ErrorNoHayFinMientras: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoNoHayFinSi(QString p_nombreVariable) {
    QString m_error = "ErrorNoHayFinSi: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoNoHayHaga(QString p_nombreVariable) {
    QString m_error = "ErrorNoHayHaga: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoNoHayEntonces(QString p_nombreVariable) {
    QString m_error = "ErrorNoHayEntonces: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoParentesisVacio(QString p_nombreVariable) {
    QString m_error = "ErrorParentesisVacio: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoSobranParentesis(QString p_nombreVariable) {
    QString m_error = "ErrorSobranParentesis: ";
    m_error.append(p_nombreVariable);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoOperadorSuma(QString p_nombreVariable, QString p_expresion) {
    QString m_error = "ErrorOperadorSuma: ";
    m_error.append(p_nombreVariable);
    m_error.append(":");
    m_error.append(p_expresion);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoOperadorRacional(QString p_nombreVariable, QString p_expresion) {
    QString m_error = "ErrorOperadorRacional: ";
    
    m_error.append(p_nombreVariable);
    m_error.append(":");
    m_error.append(p_expresion);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoVariableNoDeclarada(QString p_nombreVariable, QString p_expresion) {
    QString m_error = "variableNoDeclarada: ";
    m_error.append(p_nombreVariable);
    m_error.append(":");
    m_error.append(p_expresion);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoVariableNoValida(QString p_nombreVariable, QString p_expresion) {
    QString m_error = "variableNoValida: ";
    m_error.append(p_nombreVariable);
    m_error.append(":");
    m_error.append(p_expresion);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    this->_numeroErrores++;
}

void moduloErrores::RegistrarErrorSintacticoAccionInvalida(int p_posicion,QString p_expresion) {
    this->_numeroErrores++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorAccionInvalida,_numeroErrores,p_posicion,p_expresion.toStdString().c_str());
    QString m_error = "AccionInvalida: ";
    m_error.append(p_expresion);
    m_error.append('\n');
    _archivoErrores->EscribirLinea(m_error);
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearNodoTexto(m_textoError);
    _archivoXML->DevolverseAPadre();
    
}

void moduloErrores::CrearNuevoRegistroErrores() {
    _archivoErrores = new ManejoDeArchivosExternos;
    _archivoErrores->CrearArchivo("MóduloErrores.txt");
    _archivoXML = new ManejoXML();
    _archivoXML->CrearNuevoArchivoXML("ModuloErrores");
    
}

void moduloErrores::AgregarMasErroresRegistro() {
    _archivoErrores = new ManejoDeArchivosExternos;
    _archivoErrores->AnadirTexto("MóduloErrores.txt");
}

void moduloErrores::RegistrarTerminarEscritura() {
    _archivoErrores->CerrarArchivoEscritura();
    _archivoXML->GuardarDocumento("MóduloErrores.xml");
}

int moduloErrores::ObtenerNumeroDeErrores() {
    return this->_numeroErrores;
}