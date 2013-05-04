/* 
 * File:   LeerImagenes.cpp
 * Author: alonso
 * 
 * Created on 27 de abril de 2013, 21:15
 */

#include <arpa/nameser_compat.h>

#include "LeerImagenes.h"


LeerImagenes::~LeerImagenes() {
}

LeerImagenes::LeerImagenes(string cadena) {
    this->path=cadena+"/";
    this->pathREF="/home/alonso/Escritorio/imagenes/";
    this->ArchivoSal.open("/home/alonso/Escritorio/probando.txt",ifstream::trunc);
}

string LeerImagenes::convertInt(int num)
{
    if (num == 0)
        return "0";
    string temp="";
    string returnvalue="";
    while (num>0)
    {
        temp+=num%10+48;
        num/=10;
    }
    for (int i=0;i<temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

bool LeerImagenes::setImagenLec(string nombre){
    QString qstr = QString::fromStdString(path+nombre);
    return imagenLec.load(qstr);
}
bool LeerImagenes::setImagenRef(string nombre){
    QString qstr = QString::fromStdString(nombre);
    return imagenRef.load(qstr);
}

void LeerImagenes::Interpretar(){
    int contador=0;
    string caso="00";
    while(setImagenLec(caso+convertInt(contador)+".JPG")!=false){
        contador++;
        int caracter=buscaLESCO();
        AnalizaNum(caracter);
        if(contador>=10){
            caso="0";}
        if(contador>=100){
            caso="";   }                
    }
    ArchivoSal.close();
    cout<<"termine"<<endl;
}

void LeerImagenes::AnalizaNum(int num){    
    int control=96;
    char insert;
    if(num<=9 && num!=2){       
        if(num==0){
            ArchivoSal<<"o";
        }
        else{
            ArchivoSal<<num;
        }       
    }
    if(num==2){          
            ArchivoSal<<"v";
        }
    if(num>=10 && num<=35){
        num-=9;
        control+=num;
        insert=(char)control;
        ArchivoSal<<insert;
    }
    if(num>35 && num<=49){
        if(num==36){
                ArchivoSal<<"ch";}
        if(num==37){
                ArchivoSal<<"ll";}
        if(num==38){
                ArchivoSal<<"ñ";}
        if(num==39){
                ArchivoSal<<"!=";}
        if(num==40){
                ArchivoSal<<"=";}
        if(num==41){
                ArchivoSal<<"+";}
        if(num==42){
                ArchivoSal<<">=";}
        if(num==43){
                ArchivoSal<<">";}
        if(num==44){
                ArchivoSal<<"<=";}
        if(num==45){
                ArchivoSal<<"<";}
        if(num==46){
                ArchivoSal<<"-";}
        if(num==47){
                ArchivoSal<<"(";}
        if(num==48){
                ArchivoSal<<")";}
        if(num==49){
                ArchivoSal<<";";}
    }

}
int LeerImagenes::buscaLESCO(){
    int contador=0;
    while(contador<50){
        setImagenRef(pathREF+convertInt(contador)+".JPG");     
        if((imagenLec.operator ==(imagenRef))==true){
            break;           
        }else{
            contador++;
        }
    }
    if(contador<50){
        return contador;
    }else{
        return 100;
    }
}



