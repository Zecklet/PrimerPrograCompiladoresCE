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


#define kErrorLexicoCaracterDesconocido "Error Léxico #%d, En la línea #%d posición #%d la palabra '%s' no es una palabra permitida por lo que ha sido eliminada."
#define kErrorLexicoPalabraReservadaMayuscula "Error Léxico #%d, En la línea #%d posición #%d la palabra '%s' es una palabra reservada con letras mayúsculas, por lo que será cambiada a minúsla."

//Errores Sintacticos

#define kErrorSintacticoVariableNoValida "Error Sintáctico #%d, En la posición #%d, en la expresion '%s' la palabra '%s' no puede ser utilizada como variable."
#define kErrorSintacticoErrorOperadorRacional "Error Sintáctico #%d, En la posición #%d, el operador racional '%s', no es un operador válido."
#define kErrorSintacticoErrorOperadorSuma "Error Sintáctico #%d, En la posición #%d, la declaracion '%s' existe el operador de suma '%s' el cual no es un operador válido."
#define kErrorSintacticoErrorNoSeReconoceLaPalabra "Error Sintáctico #%d, En la posición #%d, no se reconoce la palabra '%s'."
#define kErrorSintacticoErrorParentesisVacio "Error Sintáctico #%d, En la posición #%d, en la expresion '%s' existe '()' el cual no es permitido."
#define kErrorSintacticoErrorSobraParentesis "Error Sintáctico #%d, En la posición #%d, en la expresion '%s' sobran paréntesis."
#define kErrorSintacticoErrorTerminalNoValido "Error Sintáctico #%d, En la posición #%d, en la expresion '%s' falta un terminal."
#define kErrorSintacticoErrorIgualdadVacia "Error Sintáctico #%d, En la posición #%d, en la expresion '%s' existe una igualdad inválida."
#define kErrorSintacticoErrorTerminalExpresionVacia "Error Sintáctico #%d, En la posición #%d, en siguiente declaracion '%s'no existe ninguna expresion."
#define kErrorSintacticoErrorLaVariableNoExiste "Error Sintáctico #%d, En la posición #%d, en la declaracion '%s' la variable '%s' no ha sido declarada."
#define kErrorSintacticoErrorNoDelimitador "Error Sintáctico #%d, En la posición #%d, se encuentra una declaración de '%s', pero se esperaba un delimitador '%s', luego de la expresion '%s'."
#define kErrorSintacticoErrorNoHayFin "Error Sintáctico #%d, En la posición #%d, se encuentra la declaración '%s', pero no hay ningún cierre '%s'."
#define kErrorSintacticoErrorNoHayIncio "Error Sintáctico #%d, En la posición #%d, se encuentra la declaración '%s', pero no hay ningún inicio de declaración '%s expresion %s'."
#define kErrorSintacticoErrorAccionInvalida "Error Sintáctico #%d, En la posición #%d, se encuentra la expresion '%s', la cual no tiene un significado lógico."
#define kErrorSemanticoErrorLaExpresionFalsa "Error Semántico #%d, En la posición #%d, se encuentra la declaración '%s', la cual contiene la expresión '%s'que siempre es falsa, por lo que se eliminará su contenido."
#define kErrorSemanticoErrorSiVerdadero "Error Semántico #%d, En la posición #%d, se encuentra la declaración '%s', la cual contiene la expresión '%s'que siempre es verdadera, eliminará la declaración y únicamente se dejará su contenido."
#define kErrorSemanticoErrorCarroApagado "Error Semántico #%d, En la posición #%d, se encuentra la declaración '%s' pero el auto puede estar apagado."


#define kTipoDeDatoVariable "Variable"
#define kTipoDeDatoEtiqueta "Etiqueta"
#define kTipoDeDatoNoDefinido "NoDefinido"

#endif	/* CONSTANTES_H */

