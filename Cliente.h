#pragma once
#include "Persona.h"
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
using namespace std;

class Cliente : public Persona
{
	//atributos
private: string nit;

	   //constructor
public:
	Cliente() {
	}

	Cliente(string nom, string ape, string dire, int tel,string fn, string n) : Persona(nom, ape, dire, tel,fn) {
		nit = n;
	}

	//metodos
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dire) { direccion = dire; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_nacimiento(string fn) { fecha_nacimiento = fn; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
string getFecha_nacimiento() { return fecha_nacimiento; }


	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string te = to_string(telefono);
			string insert = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento)VALUES('" + nit + "','" + nombres + "','"+ apellidos + "','"+direccion + "','"+ te + "','" + fecha_nacimiento + "'); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso...." << endl;

			}

			else {
				cout << "Error en El ingreso ..." << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conex();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "------------------CLientes----------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "-" << fila[1] << "-" << fila[2] << "-" << fila[3] << "-" << fila[4] << "-" << fila[5] << "-" << fila[6] << endl;
				}

			}

			else {
				cout << "Error en El ingreso ..." << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conex();
	}
};

