/* 
 * File:   AnalisisSemantico.cpp
 * Author: zeck
 * 
 * Created on May 3, 2013, 11:30 PM
 */

#include <qstring.h>

#include "AnalisisSemantico.h"
#include "TablaSimbolos.h"
#include "moduloErrores.h"
#include "FuncionesString.h"

AnalisisSemantico::AnalisisSemantico() {
}

AnalisisSemantico::AnalisisSemantico(const AnalisisSemantico& orig) {
}

AnalisisSemantico::~AnalisisSemantico() {
}

void AnalisisSemantico::InicializarDatos(moduloErrores * p_moduloErrores, TablaSimbolos * p_tablaSimbolos, QList<QString> * p_listaLineas,
        QList<QList<QString>*> * p_listaDeListasDePalabras) {
    this->_moduloNotificacionErrores = p_moduloErrores;
    this->_tablaDeSimbolos = p_tablaSimbolos;
    this->_listaLineas = p_listaLineas;
    this->_listaDeListasDePalabras = p_listaDeListasDePalabras;
    this->_indiceLineaAEliminar = 0;
    this->_indiceLineaActual = 0;
    this->_listaLineasAEliminar = (int*) calloc(_listaLineas->length() + 1, sizeof (int));
}

void AnalisisSemantico::ComenzarAnalisis() {
    _moduloNotificacionErrores->AgregarMasErroresRegistro();

}

void AnalisisSemantico::RedireccionarLineas(QString p_formaInicio, QString p_formaFinal, int p_destinoSi) {
    int m_largoLineas = this->_listaLineas->length();
    QString m_palabraActual;
    int mPila = 0;
    while (this->_indiceLineaAEliminar < m_largoLineas) {
        m_palabraActual = this->_listaDeListasDePalabras->at(_indiceLineaAEliminar)->at(0);
        if (m_palabraActual == "si") {
            //   ValorarLineas(-1, EvaluarCondicionExpresion(mLineaConPalabrasSeparadasSemanticas));
        } else {
            if (m_palabraActual == "mientras") {
                //   ValorarLineas(EvaluarCondicionExpresion(mLineaConPalabrasSeparadasSemanticas), -1);
            } else {
                this->_listaLineasAEliminar[this->_indiceLineaAEliminar] = 1;
                this->_indiceLineaAEliminar++;
            }
        }
        if (m_palabraActual == p_formaFinal && _listaLineasAEliminar[this->_indiceLineaAEliminar - 1] == 1) {
            mPila++;
        } else {
            if (m_palabraActual.at(0) == p_formaFinal.at(0)) {
                if (m_palabraActual == p_formaInicio) {
                    if (mPila == 0) {
                        break;
                    } else {
                        mPila--;
                    }
                }
            } else {
                if (m_palabraActual.at(0) == 's') {
                    if (m_palabraActual == "sino" && p_destinoSi == 1 && mPila == 0) {
                        _indiceLineaAEliminar--;
                        _listaLineasAEliminar[_indiceLineaAEliminar] = 0;
                        _listaLineasAEliminar[_indiceLineaAEliminar - 1] = 0;
                        //  EliminarLineas("si", "fin-si");
                        break;
                    }
                }
            }
        }
        this->_indiceLineaActual++;
    }
}

int AnalisisSemantico::EvaluarCondicionExpresion(QList<QString> * p_listaListaDePalabras, QString pListaPalabras) {
    int mCondicionSeCumple = -1;
    QString mExpresion = pListaPalabras.trimmed();
    mExpresion.remove(QChar(' '), Qt::CaseInsensitive);
    if (p_listaListaDePalabras->at(0) == "si") {
        mExpresion = mExpresion.section("", 3, mExpresion.length() - 8).trimmed();
    } else {
        if (p_listaListaDePalabras->at(0) == "mientras") {
            mExpresion = mExpresion.section("", 9, mExpresion.length() - 4).trimmed();
        } else {
            mExpresion = "";
        }
    }
    if (mExpresion != "" && !BuscarVariables(mExpresion)) {
        mCondicionSeCumple = EvaluarExpresionSinVariable(mExpresion);
        if (mCondicionSeCumple == 1) {
            if (p_listaListaDePalabras->at(0) == "si") {
                this->_moduloNotificacionErrores->RegistrarErrorSemanticoSimpreVerdad(pListaPalabras, mExpresion);
            }
        } else {
            if (mCondicionSeCumple == 0) {
                this->_moduloNotificacionErrores->RegistrarErrorSemanticoNoSeUsa(pListaPalabras, mExpresion);
            } else {
                if (p_listaListaDePalabras->at(0) == "mientras") {
                    this->_moduloNotificacionErrores->RegistrarErrorSemanticoNoSeUsa(pListaPalabras, mExpresion);
                }
            }
        }
    }
    return mCondicionSeCumple;
}

int AnalisisSemantico::BuscarVariables(QString pExpresion) {
    int mExisteAlgunaVariable = 0;
    FuncionesString mManejoString;
    QString mVariable;
    for (int i = 0; i < pExpresion.length(); i++) {
        if (mManejoString.VerificarEsCaracter(pExpresion.at(i).toAscii())) {
            mVariable.append(pExpresion.at(i));
        } else {
            if (mVariable.length() > 0) {
                mExisteAlgunaVariable = 1;
                break;
            }
        }
        i++;
    }
    return mExisteAlgunaVariable;
}

int AnalisisSemantico::EvaluarExpresionSinVariable(QString pLinea) {
    FuncionesString mManejoFunciones;
    int mAbreParentesis = 0;
    int mNumeroAnterior = 0, mNumeroResultante = 0;
    int mOperadorSuma = 0; // si es 1 es una suma y si es 2 es una resta
    int mNumeroIzquierdo = 0;
    QString mOperadorRacional;
    QString mNumeroAnalizado;
    int mIndiceInferior = -1, mIndiceSuperior = -1;
    for (int i = 0; i < pLinea.length(); i++) {
        if (pLinea.at(i) == '(') {
            if (mAbreParentesis == 0) {
                mIndiceInferior = i;
            }
            mAbreParentesis++;
        } else {
            if (pLinea.at(i) == ')') {
                mAbreParentesis--;
                if (mAbreParentesis == 0) {
                    mIndiceSuperior = i;
                    mNumeroAnterior = EvaluarExpresionSinVariable(pLinea.section("", mIndiceInferior + 2, mIndiceSuperior - 1));
                }
            }
            if (mAbreParentesis == 0) {
                if (mIndiceInferior != -1 && mIndiceSuperior != -1) {
                    mIndiceInferior = -1;
                    mIndiceSuperior = -1;
                }
                if (mManejoFunciones.VerificacionEsNumero(pLinea.at(i).toAscii())) {
                    mNumeroAnalizado.append(pLinea.at(i));
                }
                if (mOperadorSuma != 0) {
                    if (mNumeroAnalizado.length() > 0) {
                        mNumeroAnterior = mNumeroAnalizado.toInt();
                        mNumeroAnalizado.clear();
                    }
                    if (mOperadorSuma == 1) {
                        mNumeroResultante += mNumeroAnterior;
                        mNumeroAnterior = 0;
                    } else {
                        mNumeroResultante -= mNumeroAnterior;
                        mNumeroAnterior = 0;
                    }
                } else {
                    if (mNumeroResultante == 0) {
                        mNumeroResultante = mNumeroAnalizado.toInt();
                        mNumeroAnalizado.clear();
                        mNumeroAnterior = mNumeroResultante;
                    }
                }
                mOperadorSuma = 0;
                if (pLinea.at(i) == '+') {
                    mOperadorSuma = 1;
                } else {
                    if (pLinea.at(i) == '-') {
                        mOperadorSuma = 2;
                    } else {
                        if (mManejoFunciones.VerificacionOperadoresRacionales(pLinea.at(i).toAscii())) {
                            mOperadorRacional.append(pLinea.at(i));
                            if (mOperadorRacional.length() >= 2) {
                                mNumeroIzquierdo = mNumeroResultante;
                                mNumeroResultante = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    if (mOperadorRacional.length() >= 2) {
        if (EvaluarOperadorRacional((char*) mOperadorRacional.toStdString().c_str(), mNumeroIzquierdo, mNumeroAnterior)) {
            return 1;
        } else {
            return 0;
        }
    }
    return mNumeroResultante;
}

bool AnalisisSemantico::EvaluarOperadorRacional(char * pOperadorRacional, int pNumeroIzq, int pNumeroDer) {
    if (strcmp(pOperadorRacional, "==") == 0) {
        return (pNumeroIzq == pNumeroDer);
    } else if (strcmp(pOperadorRacional, "!=") == 0) {
        return (pNumeroIzq != pNumeroDer);
    } else if (strcmp(pOperadorRacional, "<") == 0) {
        return (pNumeroIzq < pNumeroDer);
    } else if (strcmp(pOperadorRacional, ">") == 0) {
        return (pNumeroIzq > pNumeroDer);
    } else if (strcmp(pOperadorRacional, "<=") == 0) {
        return (pNumeroIzq <= pNumeroDer);
    } else if (strcmp(pOperadorRacional, ">=") == 0) {
        return (pNumeroIzq >= pNumeroDer);
    } else {
        printf("ERROR EN EL ANALISIS SEMANTICO");
        return -1;
    }
}

void AnalisisSemantico::ValorarLineas(int pDestinoMientras, int pDestinoIf) {
    if (pDestinoIf == 0 || pDestinoMientras == 0) {
        if (pDestinoIf == 0) {
            EliminarLineas("si", "fin-si");
        } else {
            EliminarLineas("mientras", "fin-mientras");
        }
    } else {
        if (pDestinoIf == 1) {
            this->_listaLineasAEliminar[this->_indiceLineaAEliminar] = 0;
            this->_indiceLineaAEliminar++;
            RedireccionarLineas("si", "fin-si", pDestinoIf);
            this->_listaLineasAEliminar[this->_indiceLineaAEliminar - 1] = 0;
        } else {
            this->_listaLineasAEliminar[this->_indiceLineaAEliminar] = 1;
            this->_indiceLineaAEliminar++;
        }
    }
}

void AnalisisSemantico::EliminarLineas(QString pFormaIncio, QString pFormaFinal) {
    int mPila = 0;
    QString m_primeraPalabra;
    while (_indiceLineaAEliminar < _listaLineas->length()) {
        this->_listaLineasAEliminar[this->_indiceLineaAEliminar] = 0;
        this->_indiceLineaAEliminar++;
        m_primeraPalabra = this->_listaDeListasDePalabras->at(this->_indiceLineaAEliminar)->at(0);
        if (m_primeraPalabra == pFormaIncio) {
            mPila++;
        } else {
            if (m_primeraPalabra.at(0) == pFormaFinal.at(0)) {
                if (m_primeraPalabra == pFormaFinal) {
                    if (mPila == 0) {
                        this->_listaLineasAEliminar[this->_indiceLineaAEliminar] = 0;
                        this->_indiceLineaAEliminar++;
                        break;
                    } else {
                        mPila--;
                    }
                }
            }
            if (m_primeraPalabra.at(0) == 's') {
                if (mPila == 0 && m_primeraPalabra == "sino" && pFormaIncio == "si") {
                    this->_listaLineasAEliminar[this->_indiceLineaAEliminar] = 0;
                    this->_indiceLineaAEliminar++;
                    int mTemporal = this->_indiceLineaAEliminar;
                    RedireccionarLineas("si", "fin-si", 0);
                    this->_listaLineasAEliminar[mTemporal] = 0;
                    this->_listaLineasAEliminar[this->_indiceLineaAEliminar - 1] = 0;
                    break;
                }
            }

        }
        this->_indiceLineaActual++;
    }
}