#include "platillo.h"

Platillo::Platillo(){
    setDescripcion("_");
    setNombre("_");
    setPrecio(0.0);
    setId(0000);
    setActivo(1); //Seekg, Seekp, Teelg, Teelp
}

string Platillo::getNombre() const{
    return nombre;
}
void Platillo::setNombre(const string &value){
    nombre = value;
}

string Platillo::getDescripcion() const{
    return descripcion;
}
void Platillo::setDescripcion(const string &value){
    descripcion = value;
}

float Platillo::getPrecio() const{
    return precio;
}
void Platillo::setPrecio(float value){
    precio = value;
}

int Platillo::getActivo() const{
    return activo;
}
void Platillo::setActivo(int value){
    activo = value;
}

int Platillo::getId() const{
    return id;
}
void Platillo::setId(int value){
    id = value;
}

