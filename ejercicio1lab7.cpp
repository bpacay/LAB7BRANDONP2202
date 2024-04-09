#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int manipulacion_archivo(){
	ofstream ar_escr("c:archivo.txt"); // se abre el archivo modo escritura
	
	if(!ar_escr.is_open()){// verificamos si el archivo abrio correctamente
		cout<<"El archivo no existe o no se a podido abrir correctamente"<<endl; 
		return 1;
	}
	
	string name; // es mas eficiente usar string, que char
	int y_o;
	
	//ingresamos datos que queremos que tenga el archivo
	cout<<"ingrese su nombre:";
	getline(cin, name); //utlizamos getline para poder guardar cadenas de texto junto con espacios
	ar_escr<<"nombre de usuario: "<<name<<endl;

	cout<<"ingrese su edad:";
	cin>>y_o;
	ar_escr<<"edad de usuario: "<<y_o<<endl;
	
	ar_escr.close(); //cerramos el modo escritura
	
	ifstream ar_lec("c:archivo.txt"); // se abre el archivo modo lectura
	
	if(!ar_lec.is_open()){// verificamos si el archivo abrio correctamente
		cout<<"El archivo no existe o no se a podido abrir correctamente"<<endl; 
		return 1;
	}
	string linea;

    // Leer línea completa desde el archivo
    cout << "Contenido del archivo:" << endl;
    while (getline(ar_lec, linea)) {
        cout << linea <<endl;
    }
	
	ar_lec.close();//cerramos el modo lectura
	
	return 0;
}

class persona
// instancionamos una persono donde, una persona siempre sera una persona, sin importar su altura, su tes de piel, nombre o edad
{
private:
	//todos los parametros son los que puede definir a una persona tanto su nombre como su ocupacion, todos tiene un nombre y edad, y tambien existe diferentes ocupaciones tanto como trabajaor como desempleado
	string nombre;
	int edad;
	string ocupacion;	
	//para saber que datos provienen de una persona tenemos de abstraer la idea que tenemos de las personas, es decir diseccionar todo lo que podemos pensar que es una persona
public:
	persona(string n, int e, string o){
	nombre=n;
	edad=e;
	ocupacion=o;
	}
	
	void mostrar_datos(){
		cout<<"el nombre de la persona es: "<<nombre<<"\nla edad es: "<<edad<<"\nla ocupacion es: "<<ocupacion<<endl;
	}
	
	std::string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    std::string getOcupacion() const { return ocupacion; }
};

class Estudiante : public persona{
	private:
	int num_estudiante;
	string num_salon;
	
	public:
		Estudiante(int NE, string NS,const std::string& nombre, int edad, const std::string& ocupacion): persona(nombre,edad,ocupacion){
			num_estudiante = NE;
			num_salon = NS;
		}
		
		int getnum_estudiante() const { return num_estudiante; }
		
		void mostrar_estu(){
			cout<<"\nNumero de estudiante: "<<num_estudiante<<"\nNumero de salon: "<<num_salon<< "Nombre: " << getNombre() << ", Edad: " << getEdad()<< ", Ocupación: " << getOcupacion()<<endl;
		}
};

void ordenamientoBurbuja(std::vector<Estudiante>& estudiantes) {
    bool intercambio;
    do {
        intercambio = false;
        for (size_t i = 0; i < estudiantes.size() - 1; ++i) {
            if (estudiantes[i].getnum_estudiante() > estudiantes[i + 1].getnum_estudiante()) {
                std::swap(estudiantes[i], estudiantes[i + 1]);
                intercambio = true;
            }
        }
    } while (intercambio);
}


int main(){
	manipulacion_archivo();
	cout<<"\n\n";
    
	persona persona1("Juaquin",21,"Arquitectura");
	persona1.mostrar_datos();
	persona persona2("Enrique", 20, "Ingeniero en sistemas");
	persona2.mostrar_datos();
	
	std::vector<Estudiante> estudiantes = {
	Estudiante(3, "B102","Juaquin",21,"Arquitectura"),
	Estudiante(1, "C403","Enrique", 20, "Ingeniero en sistemas"),
	Estudiante(5,"B102","Luis", 19, "Arquitectura")
	};
	
	ordenamientoBurbuja(estudiantes);

    // Mostrar estudiantes ordenados
   /* std::cout << "Estudiantes ordenados por numero de estudiante:" << std::endl;
    for (const auto& estudiante : estudiantes) {
        estudiante.mostrar_estu();
    }*/
	
	return 0;
}
