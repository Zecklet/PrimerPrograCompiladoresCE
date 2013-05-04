/* 
 * File:   ManejoXML.cpp
 * Author: zeck
 * 
 * Created on May 4, 2013, 2:20 PM
 */

#include "ManejoXML.h"
#include "QtXml/qdom.h"
#include "ManejoDeArchivosExternos.h"
#include "qdebug.h"
#include "QFile"
#include "QTextStream"

ManejoXML::ManejoXML() {

}

ManejoXML::ManejoXML(const ManejoXML& orig) {
}

ManejoXML::~ManejoXML() {
}

void ManejoXML::CrearNuevoArchivoXML(QString n_nodoRaiz) {
    _documentoPadre = new QDomDocument();
    _raiz = _documentoPadre->createElement(n_nodoRaiz);
    _documentoPadre->appendChild(_raiz);
    _nodoActual = _raiz;
}

void ManejoXML::CrearNuevoElemento(QString n_nuevoElemento) {
    QDomElement m_elementoTemporal = _documentoPadre->createElement(n_nuevoElemento);
    _nodoActual.appendChild(m_elementoTemporal);
    _nodoActual = m_elementoTemporal;
}

void ManejoXML::CrearNodoTexto(QString n_nodoTexto) {
    QDomText m_textoTemporal = _documentoPadre->createTextNode(n_nodoTexto);
    _nodoActual.appendChild(m_textoTemporal);
}

void ManejoXML::DevolverseAPadre() {
    _nodoActual = _nodoActual.parentNode().toElement();
}

void ManejoXML::GuardarDocumento(QString p_nombreArchivo) {
    QFile outFile(p_nombreArchivo);
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug("Failed to open file for writing.");
    }
    QTextStream stream(&outFile);
    stream << _documentoPadre->toString();
    
    outFile.close();
}

void ManejoXML::CrearAtributos(QString n_nombre,QString n_valorAtributo){
    _nodoActual.setAttribute(n_nombre,n_valorAtributo);
}