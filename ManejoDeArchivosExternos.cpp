/* 
 * File:   ManejoDeArchivosExternos.cpp
 * Author: zeck
 * 
 * Created on April 30, 2013, 10:39 PM
 */

#include "ManejoDeArchivosExternos.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <wctype.h>
#include <qdebug.h>

ManejoDeArchivosExternos::ManejoDeArchivosExternos() {
}

ManejoDeArchivosExternos::ManejoDeArchivosExternos(const ManejoDeArchivosExternos& orig) {
}

ManejoDeArchivosExternos::~ManejoDeArchivosExternos() {
}

void ManejoDeArchivosExternos::AbrirArchivo(QString p_rutaArchivo) {
    cArchivoLectura = fopen(p_rutaArchivo.toStdString().c_str(), "r");
    cBufferLectura = (size_t *) malloc(sizeof (size_t));
}

QList<QString> * ManejoDeArchivosExternos::ObtenerTodaLineaArchivo() {
    char * mLineaActual = NULL;
    int m_esFin = 0;
    QList<QString> * m_listaResultante = new QList<QString>();
    while(1){
        m_esFin = getline(&mLineaActual, cBufferLectura, cArchivoLectura);
        if(m_esFin==-1){
            break;
        }
        m_listaResultante->append(mLineaActual);
    }
    return m_listaResultante;
}

void ManejoDeArchivosExternos::CrearArchivo(QString p_nombre){
    cArchivoEscritura = fopen(p_nombre.toStdString().c_str(), "w");
    cBufferEscritura = (size_t *) malloc(sizeof (size_t));
}
void ManejoDeArchivosExternos::AnadirTexto(QString p_nombre){
    cArchivoEscritura = fopen(p_nombre.toStdString().c_str(), "a");
    cBufferEscritura = (size_t *) malloc(sizeof (size_t));
}

void ManejoDeArchivosExternos::CerrarArchivoLectura(){
    fclose(cArchivoLectura);
    free(cBufferLectura);
}
int ManejoDeArchivosExternos::PosicionFinal(){
    return feof(cArchivoLectura);
}
QString ManejoDeArchivosExternos::LeerLinea(){
    char * mLineaActual = NULL;
    getline(&mLineaActual, cBufferLectura, cArchivoLectura);
    return QString::fromStdString(mLineaActual);;
}
void ManejoDeArchivosExternos::EscribirLinea(QString pLineaAEscribir){
     fputs( pLineaAEscribir.toStdString().c_str(), cArchivoEscritura );
}
void ManejoDeArchivosExternos::EscribirPalabraCantidadVeces(int pNumeroDeVeces,QString p_palabra){
    int i = 0;
    for(i;i<pNumeroDeVeces;i++){
        EscribirLinea(p_palabra.toStdString().c_str());
    }
}
void ManejoDeArchivosExternos::CerrarArchivoEscritura(){
    
    fclose(cArchivoEscritura);
    free(cBufferEscritura);
}
