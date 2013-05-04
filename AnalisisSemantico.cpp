/* 
 * File:   AnalisisSemantico.cpp
 * Author: zeck
 * 
 * Created on May 3, 2013, 11:30 PM
 */

#include "AnalisisSemantico.h"

AnalisisSemantico::AnalisisSemantico() {
}

AnalisisSemantico::AnalisisSemantico(const AnalisisSemantico& orig) {
}

AnalisisSemantico::~AnalisisSemantico() {
}

void AnalisisSemantico::InicializarDatos(moduloErrores * p_moduloErrores, moduloErrores * p_tablaSimbolos,QList<QString> * p_listaLineas,
    QList<QList<QString>*> * p_listaDeListasDePalabras){
    this->_moduloNotificacionErrores = p_moduloErrores;
    this->_tablaDeSimbolos = p_tablaSimbolos;
    this->_listaLineas = p_listaLineas;
    this->_listaDeListasDePalabras = p_listaDeListasDePalabras;
}

void AnalisisSemantico::ComenzarAnalisis(){
    
}