/* 
 * File:   FuncionesString.h
 * Author: zeck
 *
 * Created on April 30, 2013, 11:07 PM
 */

#ifndef FUNCIONESSTRING_H
#define	FUNCIONESSTRING_H

class FuncionesString {
public:
    FuncionesString();
    FuncionesString(const FuncionesString& orig);
    virtual ~FuncionesString();
    QList<QString> * SepararLineaEnListaPalabras(QString p_linea); 
    QList<QList<QString>*>* SepararListaPalabrasEnListaDeListasDePalabras(QList<QString> * p_listaPalabras);
    int HeuristicoIfSino(QList<QList<QString>*> * pListaLineas, int pLineaMenor, int pLineaMayor);
    bool VerificacionOperadoresRacionales(char p_caracter);
    bool VerificacionEsNumero(char pCaracter);
    bool VerificarEsCaracter(char pCaracter);
private:

};

#endif	/* FUNCIONESSTRING_H */

