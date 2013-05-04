/*
 * File:   main.cpp
 * Author: alonso
 *
 * Created on 27 de abril de 2013, 19:45
 */

#include <QtGui/QApplication>
#include "LeerImagenes.h"
#include "ManejoDeArchivosExternos.h"
#include "FuncionesString.h"
#include "AnalisisSintactico.h"
#include "qdebug.h"
#include "AnalisisSemantico.h"
#include "moduloErrores.h"
#include "ManejoXML.h"

using namespace std;

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    QString xx = "hola mundo";
    QString y = xx.section("", 3, xx.length());
    qDebug() << y << "----------------";
    AnalisisSintactico x;
    x.ComenzarAnalisis();
    if (x.ObtenerModuloErrores()->ObtenerNumeroDeErrores() == 0) {
        AnalisisSemantico yy;
        yy.InicializarDatos(x.ObtenerModuloErrores(), x.ObtenerTablaDeSimbolos(), x.ObtenerListaLineas(), x.ObtenerListaListasPalabras());
        yy.ComenzarAnalisis();
    }
    else{
        qDebug()<<"Errores Sintacticos";
    }
    return 0;
}
