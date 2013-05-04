/* 
 * File:   LeerImagenes.h
 * Author: alonso
 *
 * Created on 27 de abril de 2013, 21:15
 */

#ifndef LEERIMAGENES_H
#define	LEERIMAGENES_H
#include <stdio.h>
#include <iostream>
#include <Qt/qimage.h>
#include <QString>
#include <fstream>

using namespace std;

class LeerImagenes {
public:
    LeerImagenes(string cadena);
    LeerImagenes(const LeerImagenes& orig);
    virtual ~LeerImagenes();
    string convertInt(int num);
    bool setImagenLec(string nombre);
    bool setImagenRef(string nombre);
    void Interpretar();
    void AnalizaNum(int num);
    int buscaLESCO();
private:
    string path;
    string pathREF;
    ofstream ArchivoSal;
    QImage imagenLec;
    QImage imagenRef;
};

#endif	/* LEERIMAGENES_H */

