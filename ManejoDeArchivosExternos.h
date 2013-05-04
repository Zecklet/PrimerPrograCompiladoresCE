/* 
 * File:   ManejoDeArchivosExternos.h
 * Author: zeck
 *
 * Created on April 30, 2013, 10:39 PM
 */

#ifndef MANEJODEARCHIVOSEXTERNOS_H
#define	MANEJODEARCHIVOSEXTERNOS_H

#include "QString"
#include "QList"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <wctype.h>

class ManejoDeArchivosExternos {
public:
    ManejoDeArchivosExternos();
    ManejoDeArchivosExternos(const ManejoDeArchivosExternos& orig);
    virtual ~ManejoDeArchivosExternos();
    void AbrirArchivo(QString p_rutaArchivo);
    void CrearArchivo(QString p_nombre);
    QList<QString> * ObtenerTodaLineaArchivo();
    void EscribirLinea(QString p_lineaAEscribir);
    QString LeerLinea();
    void AnadirTexto(QString p_nombre);
    void EscribirPalabraCantidadVeces(int pNumeroDeVeces, QString pPalabra);
    int PosicionFinal();
    void CerrarArchivoLectura();
    void CerrarArchivoEscritura();


private:
    FILE * cArchivoLectura;
    FILE * cArchivoEscritura;
    size_t * cBufferLectura;
    size_t * cBufferEscritura;

};

#endif	/* MANEJODEARCHIVOSEXTERNOS_H */

