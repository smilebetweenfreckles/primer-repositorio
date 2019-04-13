#ifndef PLATILLO_H
#define PLATILLO_H
#include <iostream>
using namespace std;

class Platillo{

    string descripcion;
    string nombre;
    float precio;
    int activo;
    int id;

public:

    Platillo();

    string getDescripcion() const;
    void setDescripcion(const string &value);
    string getNombre() const;
    void setNombre(const string &value);
    float getPrecio() const;
    void setPrecio(float value);
    int getActivo() const;
    void setActivo(int value);
    int getId() const;
    void setId(int value);

    friend ostream & operator <<(ostream & controlador, Platillo & p){
            controlador << "ID: " << p.getId()
                        << "|NOMBRE: " << p.getNombre()
                        << "|DESCRIPCION: " << p.getDescripcion()
                        << "|PRECIO: " << p.getPrecio()
                        << "|ACTIVO: " << p.getActivo() << endl;
            return controlador;
    }
};

#endif // PLATILLO_H
