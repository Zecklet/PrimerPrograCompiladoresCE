/* 
 * File:   Constantes.h
 * Author: zeck
 *
 * Created on March 26, 2013, 7:41 AM
 */

#ifndef CONSTANTES_H
#define	CONSTANTES_H

#define kAsciiCaracterMayusculaMayor 90 
#define kAsciiCaracterMayusculaMenor 65
#define kAsciiCaracterMinuscilaMayor 122
#define kAsciiCaracterMinusculaMenor 97
#define kAsciiNumeroMayor 57
#define kAsciiNumeroMenor 48
#define kAsciiDesigualdadMayor 62
#define kAsciiDesigualdadMenor 60
#define kAsciiEspacio 32
#define kAsciiAdmiracion 33
#define kAsciiSuma 43
#define kAsciiResta 45
#define kAsciiParentesisAbre 40
#define kAsciiParentesisCierra 41


#define kErrorLexicoCaracterDesconocido "Error Léxico #%d, En la línea #%d posición #%d la palabra '%s' no es una palabra permitida por lo que ha sido eliminada.\n"
#define kErrorLexicoPalabraReservadaMayuscula "Error Léxico #%d, En la línea #%d posición #%d la palabra '%s' es una palabra reservada con letras mayúsculas, por lo que será cambiada a minúsla.\n"

//Errores Sintacticos

#define kErrorSintacticoVariableNoValida "Error Sintáctico #%d, En la línea #%d, la palabra '%s' no puede ser utilizada como variable.\n"
#define kErrorSintacticoNoSeReconoceLaPalbra "Error Sintáctico #%d, En la línea #%d, la palabra '%s' no es reconocida, se esperaba 'NEWLINE'.\n"
#define kErrorSintacticoErrorOperadorRacional "Error Sintáctico #%d, En la línea #%d, el operador racional '%s', no es un operador válido.\n"
#define kErrorSintacticoErrorOperadorSuma "Error Sintáctico #%d, En la línea #%d, el operador de suma '%s' no es un operador válido.\n"
#define kErrorSintacticoErrorNoHayNEWLINE "Error Sintáctico #%d, En la línea #%d, no se encontro un separador de linea NEWLINE.\n"
#define kErrorSintacticoErrorNoSeReconoceLaPalabra "Error Sintáctico #%d, En la línea #%d, no se reconoce la palabra '%s'.\n"
#define kErrorSintacticoErrorParentesisVacio "Error Sintáctico #%d, En la línea #%d, en la expresion '%s' existe '()' el cual no es permitido.\n"
#define kErrorSintacticoErrorSobraParentesis "Error Sintáctico #%d, En la línea #%d, en la expresion '%s' sobran paréntesis.\n"
#define kErrorSintacticoErrorTerminalNoValido "Error Sintáctico #%d, En la línea #%d, se esperaba un salto de línea pero se encontro '%s'.\n"
#define kErrorSintacticoErrorLaVariableNoExiste "Error Sintáctico #%d, En la línea #%d, la variable '%s' no ha sido declarada.\n"
#define kErrorSintacticoErrorNoDelimitador "Error Sintáctico #%d, En la línea #%d, se encuentra una declaración de '%s', pero se esperaba un delimitador '%s', luego de la expresion '%s'.\n"
#define kErrorSintacticoErrorNoHayFin "Error Sintáctico #%d, En la línea #%d, se encuentra la declaración '%s', pero no hay ningún cierre '%s'.\n"
#define kErrorSintacticoErrorNoHayIncio "Error Sintáctico #%d, En la línea #%d, se encuentra la declaración '%s', pero no hay ningún inicio de declaración '%s expresion %s'.\n"
#define kErrorSemanticoErrorLaExpresionFalsa "Error Semántico #%d, En la línea #%d, se encuentra la declaración '%s', la cual contiene la expresión '%s'que siempre es falsa, por lo que se eliminará su contenido.\n"
#define kErrorSemanticoErrorSiVerdadero "Error Semántico #%d, En la línea #%d, se encuentra la declaración '%s', la cual contiene la expresión '%s'que siempre es verdadera, eliminará la declaración y únicamente se dejará su contenido.\n"


#define kTipoDeDatoVariable "Variable"
#define kTipoDeDatoEtiqueta "Etiqueta"
#define kTipoDeDatoNoDefinido "NoDefinido"

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CONSTANTES_H */

