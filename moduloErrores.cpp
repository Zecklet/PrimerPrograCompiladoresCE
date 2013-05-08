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
    this->_numeroErroresSintacticos = 0;
}

moduloErrores::moduloErrores(const moduloErrores& orig) {
}

moduloErrores::~moduloErrores() {
}

void moduloErrores::RegistrarErrorSemanticoCarroApagado(int p_posicion, QString p_expresion) {
    this->_numeroErroresSemanticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSemanticoErrorCarroApagado, _numeroErroresSemanticos, p_posicion, p_expresion.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSemanticoSimpreVerdad(int p_posicion, QString p_expresion, QString p_condicion) {
    this->_numeroErroresSemanticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSemanticoErrorSiVerdadero, _numeroErroresSemanticos, p_posicion, p_expresion.toStdString().c_str(), p_condicion.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSemanticoNoSeUsa(int p_posicion, QString p_expresion, QString p_condicion) {
    this->_numeroErroresSemanticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSemanticoErrorLaExpresionFalsa, _numeroErroresSemanticos, p_posicion, p_expresion.toStdString().c_str(), p_condicion.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoHaySinoSinSi(int p_posicion, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorNoHayIncio, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str(), "si", "entonces");
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();

}

void moduloErrores::RegistrarErrorSintacticoNoHayIncioSi(int p_posicion, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorNoHayIncio, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str(), "si", "entonces");
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoNoHayIncioMientras(int p_posicion, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorNoHayIncio, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str(), "mientras", "haga");
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoNoHayFinMientras(int p_posicion, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorNoHayFin, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str(), "fin-mientras");
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoNoHayFinSi(int p_posicion, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorNoHayFin, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str(), "fin-si");
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoNoHayHaga(int p_posicion, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorNoHayFin, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str(), "haga");
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoNoHayEntonces(int p_posicion, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorNoHayFin, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str(), "entonces");
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoParentesisVacio(int p_posicion, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorParentesisVacio, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoSobranParentesis(int p_posicion, QString p_expresion) {

    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorSobraParentesis, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoOperadorSuma(int p_posicion, QString p_variable, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorOperadorSuma, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str(), p_variable.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoOperadorRacional(int p_posicion, QString p_variable, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorOperadorSuma, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str(), p_variable.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoVariableNoDeclarada(int p_posicion, QString p_variable, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorLaVariableNoExiste, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str(), p_variable.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoVariableNoValida(int p_posicion, QString p_variable, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoVariableNoValida, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str(), p_variable.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();

}

void moduloErrores::RegistrarErrorSintacticoAccionInvalida(int p_posicion, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorAccionInvalida, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();

}

void moduloErrores::RegistrarErrorSintacticoTerminalPerdido(int p_posicion, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorTerminalNoValido, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoExpresionVacia(int p_posicion, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorTerminalExpresionVacia, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::RegistrarErrorSintacticoIgualdadVacia(int p_posicion, QString p_expresion) {
    this->_numeroErroresSintacticos++;
    QString m_textoError;
    m_textoError = m_textoError.sprintf(kErrorSintacticoErrorIgualdadVacia, _numeroErroresSintacticos, p_posicion, p_expresion.toStdString().c_str());
    _archivoXML->CrearNuevoElemento("E");
    _archivoXML->CrearAtributos("exp", p_expresion);
    _archivoXML->CrearAtributos("pos", QString::number(p_posicion));
    _archivoXML->CrearAtributos("text", m_textoError);
    _archivoXML->DevolverseAPadre();
}

void moduloErrores::CrearNuevoRegistroErroresSintactico() {
    _archivoXML = new ManejoXML();
    _archivoXML->CrearNuevoArchivoXML("ModuloErrores");
    _archivoXML->CrearNuevoElemento("Sintatico");
}

void moduloErrores::CrearNuevoRegistroErroresSemantico() {
    _archivoXML->ColocarContendio("MóduloErrores.xml");
    _archivoXML->CrearNuevoElemento("Semantico");
    _numeroErroresSemanticos = 0;
}

void moduloErrores::RegistrarTerminarEscritura() {
    _archivoXML->GuardarDocumento("MóduloErrores.xml");
}

int moduloErrores::ObtenerNumeroDeErroresSintacticos() {
    return this->_numeroErroresSintacticos;
}

int moduloErrores::ObtenerNumeroDeErroresSemanticos() {
    return this->_numeroErroresSemanticos;
}