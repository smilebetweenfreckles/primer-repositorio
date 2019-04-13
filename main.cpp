#include <iostream>
#include <fstream>
#include "platillo.h"
using namespace std;

void imprimir(int);
Platillo asignar(string, string, float, int, int);

int main(){
    string menu = "7";
    while (menu != "0") {

        cout << "-----------Menu de platillos----------" << endl;
        cout << "-----------1.-Agregar platillo--------" << endl; //Create
        cout << "-----------2.-Imprimir platillo-------" << endl; //Show
        cout << "-----------3.-Buscar platillo---------" << endl; //Search
        cout << "-----------4.-Modificar platillo------" << endl; //Modify
        cout << "-----------5.-Inhabilitar platillo----" << endl; //Logic Delete
        cout << "-----------6.-Habilitar platillo------" << endl; //Logic Update
        cout << "-----------7.-Eliminar platillo-------" << endl; //Delete
        cout << "-----------0.-Salir-------------------" << endl;
        cout << "------------------------------------: ";

        cin >> menu;

        if(menu == "1"){

            Platillo temp;
            string name, description, precio, linea, cont;
            int contInt, codigo;
            float precioFloat;
            ofstream escribir;
            ifstream leer;

            system("cls"); //SAMU (Sistema de Atención Médica Urgente)

            leer.open("archivo.txt",ios::in);

            if(!leer.is_open()){
                cout << "****************************" << endl;
                cout << "*Error, el archivo no abrió*" << endl;
                cout << "****************************" << endl;
                codigo =  0;
            }else{
                while(!leer.eof()){

                    getline(leer,cont,',');
                    getline(leer,linea);
                    contInt = atoi(cont.c_str());

                    if(leer.eof()){
                        break;
                    }
                    codigo = contInt;
                    //cout << "cod: " << codigo << endl;
                }
                codigo += 1;
            }

            leer.close();
            //system("cls");

            escribir.open("archivo.txt",ios::app);

            cout << "[AGREGAR PLATILLO]" << endl;

            cout << "Nombre del platillo: ";
            cin.ignore();
            getline(cin, name);

            cout << "Descripcion del platillo: ";
            getline(cin, description);

            cout << "Precio del platillo: ";
            getline(cin,precio);
            precioFloat = atof(precio.c_str());

            temp = asignar(name, description, precioFloat, codigo, 1);

            if(!escribir.is_open()){
                cout << "****************************" << endl;
                cout << "*Error, el archivo no abrió*" << endl;
                cout << "****************************" << endl;
            }else{
                escribir << temp.getId() << "," << temp.getNombre() << "," << temp.getDescripcion() << "," << temp.getPrecio() << "," << temp.getActivo() << endl;
            }
            escribir.close();
            system("cls");


        }else if(menu == "2"){
            system("cls");
            imprimir(1);
            system("pause");
            system("cls");
        }else if(menu == "3"){

            string name, description, precio, line, activo, cont, codigo;
            int activoInt, contInt;
            float precioFloat;
            ifstream leer;
            Platillo temp;

            system("cls");

            leer.open("archivo.txt",ios::in);

            cout << "  [BUSCAR PLATILLO]" << endl;
            cout << "______________________" << endl;
            cout << "Codigo del platillo: ";
            cin >> codigo;

            while(true){

                getline(leer,cont,',');

                if(leer.eof()){
                    break;
                }

                contInt = atoi(cont.c_str());

                if(cont == codigo){

                    getline(leer,name,',');

                    getline(leer,description,',');

                    getline(leer,precio,',');
                    precioFloat = atof(precio.c_str());

                    getline(leer,activo);
                    activoInt = atoi(activo.c_str());

                    temp = asignar(name, description, precioFloat, contInt, activoInt);

                    if(activoInt == 1){
                        cout << "____________________________________________________________________________________________" << endl;
                        cout << temp;
                        cout << "--------------------------------------------------------------------------------------------" << endl;
                    }else{
                        cout << "El platillo con codigo [" << contInt << "] esta inhabilitado" << endl;
                    }
                    break;
                }else{
                    getline(leer,line);
                }
            }

            leer.close();
            system("pause");
            system("cls");

        }else if(menu == "4"){

            string name, description, precio, codigo, line, activo, cont;
            int activoInt, contInt;
            float precioFloat;
            ofstream temporal;
            ifstream leer;
            Platillo temp;

            system("cls");

            leer.open("archivo.txt",ios::in);
            temporal.open("temporal.txt", ios::app);

            imprimir(1);
            cout << "[MODIFICAR PLATILLO]" << endl;
            cout << "____________________" << endl;
            cout << "Codigo del platillo: ";
            cin >> codigo;

            while(true){

                getline(leer,cont,',');
                contInt = atoi(cont.c_str());

                if(leer.eof()){
                    break;
                }

                if(cont == codigo){
                    getline(leer,name,',');
                    getline(leer,description,',');
                    getline(leer,precio,',');
                    precioFloat = atof(precio.c_str());
                    getline(leer,activo);
                    activoInt = atoi(activo.c_str());

                    temp = asignar(name, description, precioFloat, contInt, activoInt);

                    if(activoInt == 1){

                        cout << "____________________________________________________________________________________________" << endl;
                        cout << temp;
                        cout << "--------------------------------------------------------------------------------------------" << endl;

                        cout << "Nuevo nombre: ";
                        cin.ignore();
                        getline(cin,name);

                        cout << "Nueva Descripcion: ";
                        getline(cin,description);

                        cout << "Nuevo Precio: ";
                        getline(cin,precio);
                        precioFloat = atof(precio.c_str());

                        temp = asignar(name, description, precioFloat, contInt, 1);

                        temporal << temp.getId() << "," << temp.getNombre() << "," << temp.getDescripcion() << "," << temp.getPrecio() << ","  << temp.getActivo() << endl;
                        cout << "Platillo editado" << endl;
                        cout << "________________" << endl;
                        cout << temp;
                    }else{
                        cout << "El platillo con codigo [" << temp.getId() << "] esta inhabilitado" << endl;
                        temporal << temp.getId() << "," << temp.getNombre() << "," << temp.getDescripcion() << "," << temp.getPrecio() << ","  << temp.getActivo() << endl;
                    }
                }else{
                    getline(leer,line);
                    temporal << cont << "," << line << endl;
                    if(leer.eof()){
                        break;
                    }
                }
            }
            leer.close();
            temporal.close();

            remove("archivo.txt");
            rename("temporal.txt","archivo.txt");

            system("pause");
            system("cls");

        }else if(menu == "5"){

            string name, description, precio, codigo, linea, cont, activo;
            ofstream temporal;
            ifstream leer;
            Platillo temp;
            float precioFloat;
            int contInt;

            leer.open("archivo.txt",ios::in);
            temporal.open("temporal.txt",ios::app);

            system("cls");

            cout << "[INHABILITAR PLATILLO]" << endl;
            cout << "Codigo del platillo: ";
            cin >> codigo;

            while(true){
                getline(leer,cont,',');

                if(leer.eof()){
                    break;
                }

                contInt = atoi(cont.c_str());

                if(cont == codigo){

                    getline(leer,name,',');
                    getline(leer,description,',');
                    getline(leer,precio,',');
                    precioFloat = atof(precio.c_str());
                    getline(leer,activo);

                    temp = asignar(name, description, precioFloat, contInt, 0);

                    if(activo == "0"){
                        cout << "El platillo : " << temp.getNombre() << " ya estaba inhabilitado" << endl;
                        temporal << temp.getId() << "," << temp.getNombre() << "," << temp.getDescripcion() << "," << temp.getPrecio() << "," << temp.getActivo() << endl;
                    }else{
                        temporal << temp.getId() << "," << temp.getNombre() << "," << temp.getDescripcion() << "," << temp.getPrecio() << "," << temp.getActivo() << endl;
                        cout << "Platillo: " << temp.getNombre() << " inhabilitado" << endl;
                    }
                }else{
                    getline(leer,linea);
                    temporal << cont << "," << linea << endl;
                    if(leer.eof()){
                        break;
                    }
                }

            }

            leer.close();
            temporal.close();

            remove("archivo.txt");
            rename("temporal.txt","archivo.txt");

            system("pause");
            system("cls");

        }else if(menu == "6"){

            string name, description, precio, codigo, linea, cont, activo;
            ofstream temporal;
            ifstream leer;
            Platillo temp;
            float precioFloat;
            int contInt;

            leer.open("archivo.txt",ios::in);
            temporal.open("temporal.txt",ios::app);

            system("cls");

            if(!leer.is_open()){
                cout << "Error" << endl;
            }else{
                cout << "*************PLATILLOS INHABILITADOS*********" << endl;
                imprimir(0);
            }
            cout << "[HABILITAR PLATILLO]" << endl;
            cout << "Codigo del platillo: ";
            cin >> codigo;

            while(true){
                getline(leer,cont,',');

                if(leer.eof()){
                    break;
                }

                contInt = atoi(cont.c_str());

                if(cont == codigo){

                    getline(leer,name,',');
                    getline(leer,description,',');
                    getline(leer,precio,',');
                    precioFloat = atof(precio.c_str());
                    getline(leer,activo);

                    temp = asignar(name, description, precioFloat, contInt, 1);

                    if(activo == "1"){
                        cout << "El platillo: " << temp.getNombre() << " ya estaba habilitado" << endl;
                        temporal << temp.getId() << "," << temp.getNombre() << "," << temp.getDescripcion() << "," << temp.getPrecio() << "," << temp.getActivo() << endl;
                    }else{
                        temporal << temp.getId() << "," << temp.getNombre() << "," << temp.getDescripcion() << "," << temp.getPrecio() << "," << temp.getActivo() << endl;
                        cout << "Platillo: " << temp.getNombre() << " habilitado" << endl;
                    }
                }else{
                    getline(leer,linea);
                    temporal << cont << "," << linea << endl;
                    if(leer.eof()){
                        break;
                    }
                }

            }

            leer.close();
            temporal.close();

            remove("archivo.txt");
            rename("temporal.txt","archivo.txt");

            system("pause");
            system("cls");

        }else if(menu == "7"){

            string name, description, precio, linea, codigo, cont, activo;
            int contInt, activoInt;
            float precioFloat;
            ofstream temporal;
            ifstream leer;
            Platillo temp;

            leer.open("archivo.txt",ios::in);
            temporal.open("temporal.txt",ios::app);

            system("cls");

            cout << "[ELIMINAR PLATILLO]" << endl;
            cout << "Codigo del platillo: ";
            cin >> codigo;

            while(true){
                getline(leer,cont,',');

                if(leer.eof()){
                    break;
                }

                contInt = atoi(cont.c_str());

                if(cont == codigo){

                    getline(leer,name,',');
                    getline(leer,description,',');
                    getline(leer,precio,',');
                    precioFloat = atof(precio.c_str());
                    getline(leer,activo);
                    activoInt = atoi(activo.c_str());

                    temp = asignar(name, description, precioFloat, contInt, activoInt);

                    if(activoInt == 0){
                        cout << "El platillo con codigo [" << temp.getId() << "] esta inhabilitado" << endl;
                        temporal << temp.getId() << "," << temp.getNombre() << "," << temp.getDescripcion() << "," << temp.getPrecio() << "," << temp.getActivo() << endl;
                    }else{
                        cout << temp.getNombre() << " eliminado" << endl;
                    }
                }else{
                    getline(leer,linea);
                    temporal << cont << "," << linea << endl;

                    if(leer.eof()){
                        break;
                    }
                }
            }

            leer.close();
            temporal.close();

            remove("archivo.txt");
            rename("temporal.txt","archivo.txt");

            system("pause");
            system("cls");

        }else if(menu == "0"){
            system("cls");
            cout << "Adios" << endl;
            system("pause");
        }else{
            system("cls");
            cout << "Esa no es una opcion" << endl;
            system("pause");
            system("cls");
        }
    }
    return 0;
}
Platillo asignar(string name, string description, float precio, int id, int activo ){
    Platillo temp;

    temp.setNombre(name);
    temp.setDescripcion(description);
    temp.setPrecio(precio);
    temp.setId(id);
    temp.setActivo(activo);

    return temp;
}
void imprimir(int habilitados){

    string name,description,precio,cont,activo;
    int contInt,activoInt;
    float precioFloat;
    ifstream leer;
    Platillo temp;

    leer.open("archivo.txt",ios::in);

    cout << "[MOSTRAR PLATILLOS]" << endl;
    cout << "___________________" << endl;
    if(!leer.is_open()){
        cout << "****************************" << endl;
        cout << "*Error, el archivo no abrió*" << endl;
        cout << "****************************" << endl;
    }else{
        while(true){

            getline(leer,cont,',');
            contInt = atoi(cont.c_str());

            getline(leer,name,',');

            getline(leer,description,',');

            getline(leer,precio,',');
            precioFloat = atof(precio.c_str());

            getline(leer,activo);
            activoInt = atoi(activo.c_str());

            temp = asignar(name,description,precioFloat,contInt,activoInt);

            if(leer.eof()){
                cout << "____________________________________________________________________________________________" << endl;
                break;
            }
            if(activoInt == habilitados){
                cout << "____________________________________________________________________________________________" << endl;
                cout << temp;
            }
        }
    }
    leer.close();
}
