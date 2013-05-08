/* 
 * File:   ManejoXML.h
 * Author: zeck
 *
 * Created on May 4, 2013, 2:20 PM
 */

#ifndef MANEJOXML_H
#define	MANEJOXML_H

#include "QString"
#include "qdom.h"

class QDomDocument;
class QDomElement;
class ManejoXML {
public:
    ManejoXML();
    ManejoXML(const ManejoXML& orig);
    virtual ~ManejoXML();
    void CrearNuevoArchivoXML(QString n_nodoRaiz);
    void ColocarContendio(QString p_nombreArchivo);
    void CrearNuevoElemento(QString n_nuevoElemento);
    void CrearNodoTexto(QString n_nodoTexto);
    void DevolverseAPadre();
    void GuardarDocumento(QString p_nombreArchivo);
    void CrearAtributos(QString n_nombre,QString n_valorAtributo);
private:
    QDomDocument *_documentoPadre;
    QDomElement _raiz;
    QDomElement _nodoActual;
};

#endif	/* MANEJOXML_H */

