/* 
 * File:   FuncionesString.cpp
 * Author: zeck
 * 
 * Created on April 30, 2013, 11:07 PM
 */

#include <qlist.h>
#include <qstring.h>
#include "qdebug.h"
#include "FuncionesString.h"
#include "Constantes.h"

FuncionesString::FuncionesString() {
}

FuncionesString::FuncionesString(const FuncionesString& orig) {
}

FuncionesString::~FuncionesString() {
}

QList<QString> * FuncionesString::SepararLineaEnListaPalabras(QString p_linea) {
    QList<QString> * m_listaResultante = new QList<QString>();
    QString mPalabraLeida;
    int i = 0;
    for (i; i < p_linea.length(); i++) {
        if ((p_linea.at(i).toAscii() == ' ' || p_linea.at(i).toAscii() == '\n') && mPalabraLeida.length() > 0) {
            m_listaResultante->append(mPalabraLeida);
            mPalabraLeida.clear();
        } else {
            if (p_linea.at(i).toAscii() != ' ') {
                mPalabraLeida.append(p_linea.at(i));
            }
        }
    }
    mPalabraLeida.append('\n');
    m_listaResultante->append(mPalabraLeida);
    return m_listaResultante;
}

QList<QList<QString>*>* FuncionesString::SepararListaPalabrasEnListaDeListasDePalabras(QList<QString> * p_listaPalabras) {
    QList<QString> * m_lineaPalbras;
    QList<QList<QString>*>* m_listaDeListasDePalabras = new QList<QList<QString>*>();
    for (int i = 0; i < p_listaPalabras->length(); i++) {
        m_lineaPalbras = SepararLineaEnListaPalabras(p_listaPalabras->at(i));
        m_listaDeListasDePalabras->append(m_lineaPalbras);
    }
    return m_listaDeListasDePalabras;
}

int FuncionesString::HeuristicoIfSino(QList<QList<QString>*> * pListaLineas, int pLineaMenor, int pLineaMayor) {
    int mNumeroSi = 0, i = pLineaMenor + 1, mIndiceSiNo = -1;
    QString m_primeraPalabra;
    for (i; i < pLineaMayor; i++) {
        m_primeraPalabra = pListaLineas->at(i)->at(0);
        if (m_primeraPalabra == "si") {
            mNumeroSi++;
        } else {
            if (m_primeraPalabra == "fin-si") {
                mNumeroSi--;
            } else {
                if (m_primeraPalabra == "sino") {
                    if (mNumeroSi == 0) {
                        mIndiceSiNo = i;
                        break;
                    }
                }
            }
        }
    }
    return mIndiceSiNo;
}

bool FuncionesString::VerificacionOperadoresRacionales(char p_caracter){
    bool mResultado = false;
    if ((p_caracter <= kAsciiDesigualdadMayor && p_caracter >= kAsciiDesigualdadMenor)) {
        mResultado = true;
    } else {
        if (p_caracter == kAsciiAdmiracion) {

            mResultado = true;
        }
    }
    return mResultado;
}
bool FuncionesString::VerificacionEsNumero(char pCaracter) {
    if (pCaracter >= kAsciiNumeroMenor && pCaracter <= kAsciiNumeroMayor) {
        return true;
    } else {
        return false;
    }
}