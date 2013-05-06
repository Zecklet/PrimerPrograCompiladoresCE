/* 
 * File:   AnalisisSintactico.cpp
 * Author: zeck
 * 
 * Created on April 30, 2013, 10:26 PM
 */

#include <qstring.h>

#include "AnalisisSintactico.h"
#include "ManejoDeArchivosExternos.h"
#include "FuncionesString.h"
#include "qdebug.h"
#include "Constantes.h"
#include "moduloErrores.h"
#include "TablaSimbolos.h"

AnalisisSintactico::AnalisisSintactico() {
}

AnalisisSintactico::AnalisisSintactico(const AnalisisSintactico& orig) {
}

AnalisisSintactico::~AnalisisSintactico() {
}

void AnalisisSintactico::ComenzarAnalisis() {
    
    _tablaDeSimbolos = new TablaSimbolos();
    _moduloNotificacionErrores = new moduloErrores();
    _moduloNotificacionErrores->CrearNuevoRegistroErrores();
    _posicionLineaActual = 0;
    ManejoDeArchivosExternos m_archivoCodigoFuente;
    FuncionesString m_manejoString;
    m_archivoCodigoFuente.AbrirArchivo("/home/zeck/Desktop/PruebaProgra.txt");
    _listaLineas = m_archivoCodigoFuente.ObtenerTodaLineaArchivo();
    _listaDeListasDePalabras = m_manejoString.SepararListaPalabrasEnListaDeListasDePalabras(_listaLineas);
    SacarIndicesPosiciones();
    ProduccionPrograma();
    _moduloNotificacionErrores->RegistrarTerminarEscritura();
    _tablaDeSimbolos->ImprimirTablaSimbolos();
    EscribirOutputSintactico();
}

void AnalisisSintactico::ProduccionPrograma() {
    ProduccionListaVariables();
    ProduccionListaDeclaraciones(_posicionLineaActual, _listaLineas->length() - 1);
}

void AnalisisSintactico::ProduccionListaVariables() {
    int m_indiceUltimoDeclarar = 0;
    for (int i = 0; i < _listaLineas->length(); i++) {
        if (_listaLineas->at(i).trimmed().length()>1 && _listaDeListasDePalabras->at(i)->at(0) != "declarar") {
            m_indiceUltimoDeclarar = i;
            break;
        }
    }
    _estoyEnTipoVariable = 1;
    for (int j = 0; j < m_indiceUltimoDeclarar; j++) {
        if(_listaLineas->at(j).trimmed().length()>1){
                ProduccionTerminalID(_listaDeListasDePalabras->at(j)->at(1));
        }
        
    }
    _estoyEnTipoVariable = 0;
    _posicionLineaActual = m_indiceUltimoDeclarar;
}

void AnalisisSintactico::ProduccionTerminalID(QString p_ID) {
    int mPalabraValida = 1;
    for (int i = 0; i < p_ID.length(); i++) {
        if (!(p_ID.at(i).toAscii() <= kAsciiCaracterMinuscilaMayor && p_ID.at(i).toAscii() >= kAsciiCaracterMinusculaMenor)) {
            mPalabraValida = 0;
            break;
        }
        i++;
    }
    if (mPalabraValida == 1) {
        if ((_tablaDeSimbolos->AgregarUsoVariable(p_ID)) == 0) {
            if (_estoyEnTipoVariable == 1) {
                _tablaDeSimbolos->AgregarVariable(kTipoDeDatoVariable, p_ID);
            } else {
                if (_estoyEnTipoVariable == 2) {
                    _tablaDeSimbolos->AgregarVariable(kTipoDeDatoEtiqueta, p_ID);
                } else {
                    if (_estoyEnTipoVariable == 3) {
                        _moduloNotificacionErrores->RegistrarErrorSintacticoVariableNoDeclarada(p_ID, _listaLineas->at(_posicionLineaActual).trimmed());
                    }
                }
            }
        }
    } else {
        _moduloNotificacionErrores->RegistrarErrorSintacticoVariableNoValida(p_ID, _listaLineas->at(_posicionLineaActual).trimmed());
    }
}

void AnalisisSintactico::ProduccionListaDeclaraciones(int p_inicio, int p_final) {
    _posicionLineaActual = p_inicio;
    int mNumeroDeCiclos = 0, mPilaFinales = 0;
    QString mPrimeraPalabra = _listaDeListasDePalabras->at(p_inicio)->at(0);
    if (mPrimeraPalabra == "si") {
        while (1) {
            mNumeroDeCiclos++;
            if (p_inicio + mNumeroDeCiclos > p_final) {
                mPilaFinales = 1;
                break;
            }
            mPrimeraPalabra = _listaDeListasDePalabras->at(p_inicio + mNumeroDeCiclos)->at(0);
            if (mPrimeraPalabra == "si") {
                mPilaFinales++;
            } else {
                if (mPrimeraPalabra == "fin-si") {
                    if (mPilaFinales == 0) {
                        break;
                    } else {
                        mPilaFinales--;
                    }
                }
            }
        }
        if (mPilaFinales) {
            _moduloNotificacionErrores->RegistrarErrorSintacticoNoHayFinSi(_listaLineas->at(p_inicio).trimmed());
        } else {
            ProduccionDeclaracionSeleccion(p_inicio, p_inicio + mNumeroDeCiclos);
        }
    } else {
        if (mPrimeraPalabra == "mientras") {
            while (1) {
                mNumeroDeCiclos++;
                if (_posicionLineaActual + mNumeroDeCiclos > p_final) {
                    mPilaFinales = 1;
                    break;
                }
                mPrimeraPalabra = _listaDeListasDePalabras->at(p_inicio + mNumeroDeCiclos)->at(0);
                if (mPrimeraPalabra == "mientras") {
                    mPilaFinales++;
                } else {
                    if (mPrimeraPalabra == "fin-mientras") {
                        if (mPilaFinales == 0) {
                            break;
                        } else {
                            mPilaFinales--;
                        }
                    }
                }
            }
            if (mPilaFinales) {
                _moduloNotificacionErrores->RegistrarErrorSintacticoNoHayFinMientras(_listaLineas->at(p_inicio).trimmed());
            } else {
                ProduccionDeclaracionIteracion(p_inicio, p_inicio + mNumeroDeCiclos);
            }
        } else {
            if (EsUnaProduccionFuncion(mPrimeraPalabra)) {
                ProduccionDeclaracionFunciones(p_inicio);
            } else {
                if (mPrimeraPalabra == "ir") {
                    ProduccionDeclaracionSaltoEtiqueta(p_inicio);
                } else {
                    if (mPrimeraPalabra == "etiqueta") {
                        ProduccionDeclaracionEtiqueta(p_inicio);
                    } else {
                        if (mPrimeraPalabra == "fin-si") {
                            _moduloNotificacionErrores->RegistrarErrorSintacticoNoHayIncioSi(_listaLineas->at(p_inicio).trimmed());
                        } else {
                            if (mPrimeraPalabra == "fin-mientras") {
                                _moduloNotificacionErrores->RegistrarErrorSintacticoNoHayIncioMientras(_listaLineas->at(p_inicio).trimmed());
                            } else {
                                if (mPrimeraPalabra == "sino") {
                                    _moduloNotificacionErrores->RegistrarErrorSintacticoHaySinoSinSi(_listaLineas->at(p_inicio).trimmed());
                                } else {
                                    ProduccionDeclaracionAsignacion(p_inicio);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (mNumeroDeCiclos != 0) {
        p_inicio += mNumeroDeCiclos + 1;
    } else {
        p_inicio++;
    }
    if (p_final >= p_inicio) {
        ProduccionListaDeclaraciones(p_inicio, p_final);
    }
}

void AnalisisSintactico::ProduccionDeclaracionAsignacion(int p_indiceLinea) {
    int j = 0, mExisteIgual = 0;
    QString pPalabra;
    QString m_expresion = _listaLineas->at(p_indiceLinea).trimmed();
    m_expresion.remove(QChar(' '), Qt::CaseInsensitive);
    for (int i = 0; i < m_expresion.length(); i++) {
        if (m_expresion.at(i) == '=' && mExisteIgual == 0) {
            mExisteIgual = 1;
            _estoyEnTipoVariable = 3;
            ProduccionTerminalID(pPalabra);
            _estoyEnTipoVariable = 0;
            pPalabra.clear();
        } else {
            pPalabra.append(m_expresion.at(i));
        }
    }
    if (!mExisteIgual) {
        qDebug()<<"holla";
        _moduloNotificacionErrores->RegistrarErrorSintacticoAccionInvalida(_listaPosiciones[_posicionLineaActual],_lineasSinEspacios->at(_posicionLineaActual));
    } else {
        ProduccionDeclaracionExpresion(pPalabra);
    }
}

/*
 * E: QString con la palabra a revisar
 * S: true: si es un palabra reservada, false: si no los es
 * D: Funcion que compara la palabra con las palbras reservadas de la produccion funcion
 */
bool AnalisisSintactico::EsUnaProduccionFuncion(QString p_palabra) {
    if (p_palabra == "encenderfaros" || p_palabra == "apagarfaros" || p_palabra == "intervalo" || p_palabra == "mover"
            || p_palabra == "encender" || p_palabra == "apagar" || p_palabra == "abrir" || p_palabra == "cerrar"
            || p_palabra == "emitir") {
        return true;
    } else {
        return false;
    }
}

void AnalisisSintactico::ProduccionDeclaracionSaltoEtiqueta(int p_indiceLista) {
    qDebug() << "linea" << _listaLineas->at(p_indiceLista);
    _estoyEnTipoVariable = 3;
    ProduccionTerminalID(_listaDeListasDePalabras->at(p_indiceLista)->at(1));
    _estoyEnTipoVariable = 0;
}

void AnalisisSintactico::ProduccionDeclaracionEtiqueta(int p_indiceLista) {
    qDebug() << "linea" << _listaLineas->at(p_indiceLista);
    _estoyEnTipoVariable = 2;
    ProduccionTerminalID(_listaDeListasDePalabras->at(p_indiceLista)->at(1));
    _estoyEnTipoVariable = 0;
}

void AnalisisSintactico::ProduccionDeclaracionFunciones(int p_indiceLista) {
    QString m_primeraPalabra;
    m_primeraPalabra = _listaDeListasDePalabras->at(p_indiceLista)->at(0);
    //qDebug() << m_primeraPalabra << ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,";
    if (m_primeraPalabra == "encenderfaros" || m_primeraPalabra == "apagarfaros") {
        ProduccionDeclaracionLucesPublicas(p_indiceLista);
    } else {
        if (m_primeraPalabra == "intervalo") {
            ProduccionDeclaracionSemaforo(p_indiceLista);
        } else {
            if (m_primeraPalabra == "mover" || m_primeraPalabra == "encender" || m_primeraPalabra == "apagar") {
                ProduccionDeclaracionAuto(p_indiceLista);
            } else {
                if (m_primeraPalabra == "abrir" || m_primeraPalabra == "cerrar") {
                    ProduccionDeclaracionPuenteElevadizo(p_indiceLista);
                } else {
                    if (m_primeraPalabra == "emitir") {
                        ProduccionDeclaracionEstudiante(p_indiceLista);
                    }
                }
            }
        }
    }
}

void AnalisisSintactico::ProduccionDeclaracionLucesPublicas(int p_indiceLista) {
    QString m_termino = _listaLineas->at(p_indiceLista).section("", _listaDeListasDePalabras->at(p_indiceLista)->at(0).length() + 1, _listaLineas->at(p_indiceLista).length());
    //   qDebug() << m_termino.trimmed() << "hhhhohoooooooooooo-------------------------------------------------------------------";
    ProduccionDeclaracionTermino(m_termino.trimmed().remove(QChar(' '), Qt::CaseInsensitive).trimmed());
}

void AnalisisSintactico::ProduccionDeclaracionSemaforo(int p_indiceLista) {
    QString m_termino = _listaLineas->at(p_indiceLista).section("", _listaDeListasDePalabras->at(p_indiceLista)->at(0).length() + 1, _listaLineas->at(p_indiceLista).length());
    ProduccionDeclaracionTermino(m_termino.trimmed().remove(QChar(' '), Qt::CaseInsensitive).trimmed());
}

void AnalisisSintactico::ProduccionDeclaracionAuto(int p_indiceLista) {
    QString m_primeraPalabra = _listaDeListasDePalabras->at(p_indiceLista)->at(0);
    if (m_primeraPalabra == "mover") {
        QString m_termino = _listaLineas->at(p_indiceLista).section("", _listaDeListasDePalabras->at(p_indiceLista)->at(0).length() + 1, _listaLineas->at(p_indiceLista).length());
        ProduccionDeclaracionTermino(m_termino.trimmed().remove(QChar(' '), Qt::CaseInsensitive).trimmed());
    }
    
    if ((m_primeraPalabra == "encender" || m_primeraPalabra == "apagar") && _listaDeListasDePalabras->at(p_indiceLista)->length()>2){
        _moduloNotificacionErrores->RegistrarErrorSintacticoAccionInvalida(_listaPosiciones[_posicionLineaActual],_lineasSinEspacios->at(p_indiceLista));
    }
}

void AnalisisSintactico::ProduccionDeclaracionPuenteElevadizo(int p_indiceLista) {
    if (_listaDeListasDePalabras->at(p_indiceLista)->length() > 2) {
        _moduloNotificacionErrores->RegistrarErrorSintacticoAccionInvalida(_listaPosiciones[p_indiceLista],_lineasSinEspacios->at(p_indiceLista));
    }
}

void AnalisisSintactico::ProduccionDeclaracionEstudiante(int p_indiceLista) {
    QString m_primeraPalabra = _listaDeListasDePalabras->at(p_indiceLista)->at(1);
    if (!(m_primeraPalabra == "encender" || m_primeraPalabra == "apagar")) {
        _moduloNotificacionErrores->RegistrarErrorSintacticoVariableNoValida(m_primeraPalabra, _listaLineas->at(_posicionLineaActual).trimmed());
    } else {
        if (_listaDeListasDePalabras->at(p_indiceLista)->length() > 3) {
            _moduloNotificacionErrores->RegistrarErrorSintacticoAccionInvalida(_listaPosiciones[p_indiceLista],_lineasSinEspacios->at(p_indiceLista));
        }
    }
}

void AnalisisSintactico::ProduccionDeclaracionTermino(QString p_expresion) {
    if (RevisarParentesis(p_expresion.toStdString().c_str())) {
        if (p_expresion.at(0) == '(' && p_expresion.at(p_expresion.length() - 1) == ')') {
            ProduccionDeclaracionExpresion(p_expresion.section("", 2, p_expresion.length() - 1)); // probar que sirva
        } else {
            if (TerminalNUM((char*) p_expresion.toStdString().c_str())) {
                return;
            } else {
                _estoyEnTipoVariable = 3;
                ProduccionTerminalID(p_expresion);
                _estoyEnTipoVariable = 0;
            }
        }
    }
}

void AnalisisSintactico::ProduccionDeclaracionExpresion(QString p_expresion) {
    FuncionesString m_manejoString;
    int mAbreParentesis = 0;
    QString mPalabra;
    QString mOperadoRelacional;
    int i = 0, mExisteIgualdad = 0;
    for (i; i < p_expresion.length(); i++) {
        //    qDebug() << "ppppppppppppppppppp" << p_expresion << p_expresion.at(i) << mAbreParentesis << mPalabra << "qqqqqqqqqqqqqqqqqqqqqq";
        if (m_manejoString.VerificacionOperadoresRacionales(p_expresion.at(i).toAscii()) && mAbreParentesis == 0) {
            mExisteIgualdad = 1;
            mOperadoRelacional.append(p_expresion.at(i));
        } else {
            if (mExisteIgualdad) {
                ProduccionDeclaracionExpesionSuma(mPalabra);
                mExisteIgualdad = 0;
                if (!ProduccionDeclaracionTerminalOperadorRacional(mOperadoRelacional.toStdString().c_str())) {
                    _moduloNotificacionErrores->RegistrarErrorSintacticoOperadorRacional(mOperadoRelacional, _listaLineas->at(_posicionLineaActual).trimmed());
                }
                //       qDebug() << "igualdad izquierda" << mPalabra;
                mPalabra.clear();
            }
            if (p_expresion.at(i) == '(') {
                mAbreParentesis++;
            } else {
                if (p_expresion.at(i) == ')') {
                    mAbreParentesis--;
                }
            }

            mPalabra.append(p_expresion.at(i));
        }
    }
    // qDebug() << "igualdad Derecha" << mPalabra;
    ProduccionDeclaracionExpesionSuma(mPalabra);
}

void AnalisisSintactico::ProduccionDeclaracionExpesionSuma(QString p_expresion) {
    int mAbreParentesis = 0;
    QString mOperadorSuma;
    int i = 0, mOperadorEncontrado = 0;
    if (p_expresion.length() > 0) {
        i = p_expresion.length() - 1;
        for (i; i >= 0; i--) {
            // qDebug() << "oooooooooooooooooooo" << p_expresion << p_expresion.at(i) << mAbreParentesis << "oooooooooooooooooooo";
            if ((p_expresion.at(i) == '+' || p_expresion.at(i) == '-') && mAbreParentesis == 0) {
                mOperadorEncontrado++;
                mOperadorSuma.append(p_expresion.at(i));
            } else {
                if (mOperadorEncontrado > 0) {
                    break;
                }
                if (p_expresion.at(i) == '(') {
                    mAbreParentesis++;
                } else {
                    if (p_expresion.at(i) == ')') {
                        mAbreParentesis--;
                    }
                }

            }
        }
        if (mOperadorEncontrado == 0) {
            ProduccionDeclaracionTermino(p_expresion);
        } else {
            //   qDebug() << "EXPRESION DEL LADO IZQUIERDO" << p_expresion.section("", 0, i + 1) << i;
            ProduccionDeclaracionExpesionSuma(p_expresion.section("", 0, i + 1));
            if (!ProduccionDeclaracionTerminalOperadorSuma(mOperadorSuma.toStdString().c_str())) {
                _moduloNotificacionErrores->RegistrarErrorSintacticoOperadorSuma(mOperadorSuma, _listaLineas->at(_posicionLineaActual).trimmed());
            }
            // qDebug() << "EXPRESION DEL LADO DERECHO" << p_expresion.section("", i + 3, p_expresion.length());
            ProduccionDeclaracionTermino(p_expresion.section("", i + 3, p_expresion.length()));
        }
    } else {
        printf("Error la expresion no existe");
    }
}

bool AnalisisSintactico::ProduccionDeclaracionTerminalOperadorRacional(const char * pOperador) {
    int mResultado = true;
    if (strlen(pOperador) == 1) {
        if (!(pOperador[0] == '<' || pOperador[0] == '>')) {
            mResultado = false;
        }
    } else {
        if (strlen(pOperador) == 2) {
            if (!(strcasecmp(pOperador, "<=") == 0 || strcasecmp(pOperador, ">=") == 0 || strcasecmp(pOperador, "==") == 0 ||
                    strcasecmp(pOperador, "!=") == 0)) {
                mResultado = false;
            }
        } else {
            mResultado = false;
        }
    }
    return mResultado;
}

bool AnalisisSintactico::ProduccionDeclaracionTerminalOperadorSuma(const char * pOperador) {
    int mResultado = true;
    if (strlen(pOperador) == 1) {
        if (!(pOperador[0] == '+' || pOperador[0] == '-')) {
            mResultado = false;
        }
    } else {
        mResultado = false;
    }
    return mResultado;
}

void AnalisisSintactico::ProduccionDeclaracionSeleccion(int p_inicio, int p_final) {
    QString mExpresion;
    FuncionesString m_manejoString;
    _posicionLineaActual = p_inicio;
    int mExisteSINO = 0;
    mExpresion = _listaLineas->at(p_inicio).trimmed();
    mExpresion.remove(QChar(' '), Qt::CaseInsensitive);
    mExpresion = mExpresion.section("", 3, mExpresion.length() - 8).trimmed();
    mExisteSINO = m_manejoString.HeuristicoIfSino(_listaDeListasDePalabras, p_inicio, p_final);
    //    qDebug() << "la expresion en si:" << mExpresion << "posicion del sino" << mExisteSINO;
    if (_listaDeListasDePalabras->at(p_inicio)->at(_listaDeListasDePalabras->at(p_inicio)->length() - 2) == "entonces") {
        _estoyEnExpresion = true;
        ProduccionDeclaracionExpresion(mExpresion);
        _estoyEnExpresion = false;
    } else {
        _moduloNotificacionErrores->RegistrarErrorSintacticoNoHayEntonces(mExpresion);
    }
    if (mExisteSINO == -1) {
        ProduccionListaDeclaraciones(p_inicio + 1, p_final - 1);
    } else {
        ProduccionListaDeclaraciones(p_inicio + 1, mExisteSINO - 1);
        ProduccionListaDeclaraciones(mExisteSINO + 1, p_final - 1);
    }
}

void AnalisisSintactico::ProduccionDeclaracionIteracion(int p_inicio, int p_final) {
    QString mExpresion;
    _posicionLineaActual = p_inicio;
    mExpresion = _listaLineas->at(p_inicio).trimmed();
    mExpresion.remove(QChar(' '), Qt::CaseInsensitive);
    mExpresion = mExpresion.section("", 9, mExpresion.length() - 4).trimmed();
    //    qDebug() << "la expresion en mientras:" << mExpresion;
    if (_listaDeListasDePalabras->at(p_inicio)->at(_listaDeListasDePalabras->at(p_inicio)->length() - 2) == "haga") {
        _estoyEnExpresion = true;
        ProduccionDeclaracionExpresion(mExpresion);
        _estoyEnExpresion = false;
    } else {
        _moduloNotificacionErrores->RegistrarErrorSintacticoNoHayHaga(_listaLineas->at(_posicionLineaActual).trimmed());
    }
    ProduccionListaDeclaraciones(p_inicio + 1, p_final - 1);
}

bool AnalisisSintactico::RevisarParentesis(const char * pExpresion) {
    bool mResultado = true;
    int mAbreParentesis = 0, mNumeroLetrasEnMedio = 0;
    for (unsigned int i = 0; i < strlen(pExpresion); i++) {
        if (pExpresion[i] == '(') {
            mNumeroLetrasEnMedio = 0;
            mAbreParentesis++;
        } else {
            if (pExpresion[i] == ')') {
                mAbreParentesis--;
                if (mNumeroLetrasEnMedio == 0) {
                    _moduloNotificacionErrores->RegistrarErrorSintacticoParentesisVacio(_listaLineas->at(_posicionLineaActual).trimmed());
                    mResultado = false;
                }
                mNumeroLetrasEnMedio = 1;
            } else {
                mNumeroLetrasEnMedio++;
            }
        }
    }
    if (mAbreParentesis != 0) {
        _moduloNotificacionErrores->RegistrarErrorSintacticoSobranParentesis(_listaLineas->at(_posicionLineaActual).trimmed());
        mResultado = false;
    }
    return mResultado;
}

bool AnalisisSintactico::TerminalNUM(char * pLinea) {
    FuncionesString m_manejoString;
    unsigned int i = 0, mResultado = 1;
    for (i; i < strlen(pLinea); i++) {
        if (!(m_manejoString.VerificacionEsNumero(pLinea[i]))) {
            mResultado = 0;
        }
    }

    return mResultado;
}

void AnalisisSintactico::EscribirOutputSintactico() {
    ManejoDeArchivosExternos m_escritorSalida;
    QString mCaracterSiguiente;
    m_escritorSalida.CrearArchivo("OutputAnalisisSintactico.txt");
    for (unsigned int i = 0; i < _listaLineas->length(); i++) {
        if (_listaDeListasDePalabras->at(i)->at(0) == "mientras") {
            mCaracterSiguiente.append("{ \n");
        } else {
            if (_listaDeListasDePalabras->at(i)->at(0) == "fin-mientras") {
                mCaracterSiguiente.append("} \n");
                m_escritorSalida.EscribirLinea(mCaracterSiguiente);
                mCaracterSiguiente.clear();
            } else {
                if (_listaDeListasDePalabras->at(i)->at(0) == "si") {
                    mCaracterSiguiente.append("{ \n");
                } else {
                    if (_listaDeListasDePalabras->at(i)->at(0) == "sino") {
                        mCaracterSiguiente.append("} \n");
                        m_escritorSalida.EscribirLinea(mCaracterSiguiente);
                        mCaracterSiguiente.clear();
                        mCaracterSiguiente.append("{ \n");
                    } else {
                        if (_listaDeListasDePalabras->at(i)->at(0) == "fin-si") {
                            mCaracterSiguiente.append("} \n");
                            m_escritorSalida.EscribirLinea(mCaracterSiguiente);
                            mCaracterSiguiente.clear();
                        }
                    }
                }
            }
        }
        m_escritorSalida.EscribirLinea(_listaLineas->at(i));
        m_escritorSalida.EscribirLinea(mCaracterSiguiente);
        mCaracterSiguiente.clear();

    }
    m_escritorSalida.CerrarArchivoEscritura();
}

moduloErrores * AnalisisSintactico::ObtenerModuloErrores() {
    return this->_moduloNotificacionErrores;
}

TablaSimbolos * AnalisisSintactico::ObtenerTablaDeSimbolos() {
    return this->_tablaDeSimbolos;
}

QList<QString> * AnalisisSintactico::ObtenerListaLineas() {
    return this->_listaLineas;
}

QList<QList<QString>*> * AnalisisSintactico::ObtenerListaListasPalabras() {
    return this->_listaDeListasDePalabras;
}

void AnalisisSintactico::SacarIndicesPosiciones() {
    _listaPosiciones = (int*) calloc(_listaLineas->length() + 1, sizeof (int));
    _lineasSinEspacios = new QList<QString>();
    QString m_temporal;
    m_temporal = _listaLineas->at(0).trimmed();
    m_temporal.remove(QChar(' '), Qt::CaseInsensitive);
    _listaPosiciones[0] =0;
    int m_largo = _listaLineas->length();
    for (int i = 1; i <= m_largo; i++) {
        m_temporal = _listaLineas->at(i-1).trimmed();
        m_temporal.remove(QChar(' '), Qt::CaseInsensitive);
        _listaPosiciones[i] = m_temporal.length() + _listaPosiciones[i-1];
        _lineasSinEspacios->append(m_temporal);
        qDebug()<<m_temporal;
    }
}