/* 
 * File:   TablaSimbolos.cpp
 * Author: zeck
 * 
 * Created on May 1, 2013, 1:38 AM
 */

#include <qstring.h>
#include "qlist.h"
#include "TablaSimbolos.h"
#include "stdio.h"


TablaSimbolos::TablaSimbolos() {
    this->_nombresVariables = new QList<QString>;
    this->_tiposVariables = new QList<QString>;
    this->_numeroDeUsos = new QList<int>;
}

TablaSimbolos::TablaSimbolos(const TablaSimbolos& orig) {
}

TablaSimbolos::~TablaSimbolos() {
}

void TablaSimbolos::AgregarVariable(QString p_tipoVariable, QString p_nombreVariable) {
    this->_nombresVariables->append(p_nombreVariable);
    this->_tiposVariables->append(p_tipoVariable);
    this->_numeroDeUsos->append(0);
    
}
int TablaSimbolos::AgregarUsoVariable(QString p_nombreVariable){
    int m_indice = IndiceVariable(p_nombreVariable);
    if(m_indice!=-1){
        this->_numeroDeUsos->replace(m_indice,this->_numeroDeUsos->at(m_indice)+1);
        return 1;
    }
    return 0;
}

int TablaSimbolos::IndiceVariable(QString p_nombreVariable){
    int m_indiceResultado = -1;
    for(int i = 0; i<this->_nombresVariables->length();i++){
        if(p_nombreVariable == this->_nombresVariables->at(i)){
            m_indiceResultado = i;
            break;
        }
    }
    return m_indiceResultado;
}

void TablaSimbolos::ImprimirTablaSimbolos(){
    int i = 0;
    printf("IMPRIMIENDO TABLA DE SIMBOLOS\n");
    printf("---------------------------------------\n");
    printf("TIPODATO -- NOMBRE -- CANTIDADDEUSO\n");
    printf("---------------------------------------\n");
    for (i; i < _nombresVariables->length(); i++) {

        printf("%s -- %s -- %d\n", _tiposVariables->at(i).toStdString().c_str(), _nombresVariables->at(i).toStdString().c_str(), _numeroDeUsos->at(i));
    }
    printf("---------------------------------------\n");
}
int TablaSimbolos::ObtenerNumeroUsos(QString p_nombreVariable){
    return _numeroDeUsos->at(this->IndiceVariable(p_nombreVariable));
}