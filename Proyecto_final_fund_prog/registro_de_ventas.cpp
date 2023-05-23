#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include<limits> // Para validacion de inputs
#include <ctime> // Trabajo con fecha del PC

using namespace std;
//establecer un administrador
#define admin "admin"
#define pass "admin"

/*  
                        -----   PROYECTO BANCA VIRTUAL -----
CONTENIDO DEL CODIGO:
- LOGIN                                             [IN PROCESS]
- CREAR USUARIOS                                    [IN PROCESS]
- FUNCION INVENTARIO                                [IN PROCESS]
- FUNCION REGISTRO DE VENTA                         [IN PROCESS]
- FUNCION VISTA DE VENTAS                           [IN PROCESS]
- FUNCION PROOVEDORES                               [MAYBE]

CONDICIONES AGREGADAS:
-CONDICION GENERAL DE REGRESO                       [IN PROCESS]

ISSUE
- ........
...

*/




//Estructura Producto
struct Producto{
    string nombre;
    float precio;
    int cantidad;
};
vector<Producto> productos;
//Estructura Venta
struct Venta{
    string nombre;
    int precio;
    int cantidad
};
vector<Venta> ventas;
//Estructura User
struct User {
    string username_n;
    string password_n;
};
vector<User> users;

//Marco de funciones
void registro_de_venta();
void inventario();
void proveedores();
void ventas_realizadas();

//funcion creacion de usuarios
void createUser() {
    string username_n,password_n;
    users.push_back({admin,pass});
    //pedir contraseña de admin para poder generar ususarios...
    cout<<"\n\t\t======================================================================\n"<<endl;
    cout <<"\t\t!!!!*****Acceso Restringido || Solo administradores ||*****!!!!"<<endl;
	cout<<"\t\t======================================================================\n\n"<<endl;
    cout <<"\tPor favor autentifiquese o solicite ayuda de un administrador.."<<endl;
    cout << "\tUsuario: ";cin >> username_n;
    cout <<"\tContraseña: ";cin>>password_n;
    if (users[0].username_n == username_n && users[0].password_n == password_n){
        cout << "\tBienvenido "<<username_n<<endl<<endl;
        cout << "\t****// Crear usuario //****"<<endl;
        cout << "\tIngrese el nombre de usuario: ";cin >> username_n;
        cout << "\tIngrese la contraseña: ";cin >> password_n;
        users.push_back({username_n, password_n});
        cout << "\tUsuario creado exitosamente." << endl;
        cout <<"\tPorfavor autentifiquese de nuevo!.."<<endl;
        system("cls");
    }
}

//funcion de login
void login() {
    string username_n, password_n;
    users.push_back({admin,pass});
    cout<<"\n\t\t======================================================================\n"<<endl;
    cout<<"\t\t\t\t*****// Registro de venta (Nombre local) //*****"<<endl;
	cout<<"\t\t======================================================================\n\n"<<endl;

    cout<<"\t\tBienvenido!,porfavor inicie sesion"<<endl;
    cout <<"\t\tIngrese el nombre de usuario: ";
    cin >> username_n;
    cout <<"\t\tIngrese la contraseña: ";
    cin >> password_n;
    bool found = false;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].username_n == username_n && users[i].password_n == password_n) {
            found = true;
            int option;
            cout << "\n\t\t\t..::Bienvenido " << username_n << "!::.. \n";
            cout << "\t\t1. Registrar venta"<<endl;
            cout << "\t\t2. Inventario"<<endl;
            cout << "\t\t3. Comprar a provedores"<<endl;
            cout << "\t\t4. Ventas realizadas"<<endl;
            cout << "\t\t5. Salir"<<endl;
            cout << "\t\tIngrese una opcion: ";cin >> option;
            switch (option) {
                case 1:
                    system("cls");
                    registro_de_venta();
                    break;
                case 2:
                    system("cls");
                    inventario();
                    break;
                case 3:
                    system("cls");
                    proveedores();
                    break;
                case 4:
                    system("cls");
                    ventas_realizadas();
                    break;
                case 5:
                    exit(0);
                default:
                    cout << "Opcion invalida" << endl;
            }
        }
    }
    if (!found) {
        cout << "\n\t\t****!!!! Error !!!!****"<<endl;
        cout << "\t\tUsuario o contraseña incorrectos." << endl;
        cout << "\t\tRevisa tu usuario y contraseña, o solicita una cuenta\n"<<endl;
    }
}
//funcion principal
int main() {
    int option;
    while (true) {
        cout<<"\n\t\t======================================================================\n"<<endl;
        cout<<"\t\t\t *****// Registro de venta (Nombre local) //*****"<<endl;
	    cout<<"\t\t======================================================================\n\n"<<endl;
        cout << "\t1. Crear usuario" << endl;
        cout << "\t2. Iniciar sesión" << endl;
        cout << "\t3. Salir" << endl;
        cout << "\tIngrese una opción:  ";;
        cin >> option;
        if (option == 1) {
            cout <<'\n';
            system("cls");
            createUser();
        } else if (option == 2) {
            system("cls");
            login();
        } else if (option == 3) {
            break;
        } else {
            cout << "Opción inválida. Intente de nuevo." << endl;
        }
    }
    return 0;
}
//funcion registro_de_venta
void registro_de_venta(){
    cout <<"\t\t\t..::Registro de venta::.."<<endl;
}
//funcion inventario
void inventario(){
    string nombre,precio,cantidad;
    int option,a,b,c,d;
    cout <<"\t\t\t..::Inventario::..\n"<<endl;
    cout <<"\t\t1. Agregar producto"<<endl;
    cout <<"\t\t2. Ver productos"<<endl;
    cout <<"\t\t3. Eliminar producto"<<endl;
    cout <<"\t\t4. Regresar"<<endl;
    cout <<"\t\t5. Salir"<<endl;
    cout <<"\t\tIngrese una opcion: ";cin>>option;
    switch (option){
        case 1:
        //posiblemente agregar un while para introduccir varios articulos o productos
            cin.ignore();
            cout << "\tNombre del producto: ";getline(cin,nombre);
            cin.ignore();
            cout<< "\tPrecio: $";getline(cin,precio);
            cin.ignore();
            cout << "\tStock:";getline(cin,cantidad);
            productos.push_back({nombre,stof(precio),stof(cantidad)});
            inventario();
            break;
        case 2:
            cout <<"---------------------------------------------"<<endl;
            cout <<"\t Producto     Precio(Pesos)       Stock"<<endl;
            cout <<"---------------------------------------------"<<endl;
            for(int i = 0; i < productos.size(); i++){
                cout <<"\t"<<productos[i].nombre<<"\t\t"<<"$"<<productos[i].precio<<"\t\t"<<productos[i].cantidad<<endl;
                cout<<"\n";
            }
            cout <<"\t\t1. Regresar.."<<endl;
            cout<<"\t\t2. Salir.."<<endl;
            cout <<"\t\tIngrese una Opcion: ";cin>>b;
            if(b==1){
                inventario();
            }
            else{
                exit(0);
            }
            break;
        case 3:
            productos.pop_back();
            cout << "\n\t\tProducto eliminado con exito!!\n"<<endl;
            cout <<"\t\t1. Regresar.."<<endl;
            cout<<"\t\t2. Salir.."<<endl;
            cout <<"\t\tIngrese una Opcion: ";cin>>c;
            if(c==1){
                inventario();
            }
            else{
                exit(0);
            }
            break;
        case 4:
            exit(0);//agregar condicion para Regresar
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Opcion invalida" << endl;
    }
}
void proveedores(){
    cout <<"\t\t\t..::Proveedores::.."<<endl;
    cout <<"\t\t Proximamente......"<<endl;
}
void ventas_realizadas(){
    cout <<"\t\t\t..::Ventas realizadas::.."<<endl;
}


/*

#include <iostream>
#include <vector>

struct Venta {
    std::string producto;
    float precio;
    int cantidad;
};

void agregarVenta(std::vector<Venta>& ventas) {
    Venta venta;
    std::cout << "Ingrese el nombre del producto: ";
    std::cin >> venta.producto;
    std::cout << "Ingrese el precio del producto: ";
    std::cin >> venta.precio;
    std::cout << "Ingrese la cantidad vendida: ";
    std::cin >> venta.cantidad;
    
    ventas.push_back(venta);
    std::cout << "Venta registrada correctamente.\n";
}

void mostrarVentas(const std::vector<Venta>& ventas) {
    if (ventas.empty()) {
        std::cout << "No hay ventas registradas.\n";
    } else {
        std::cout << "Registro de ventas:\n";
        for (const auto& venta : ventas) {
            std::cout << "Producto: " << venta.producto << "\n";
            std::cout << "Precio: $" << venta.precio << "\n";
            std::cout << "Cantidad: " << venta.cantidad << "\n";
            std::cout << "Total: $" << venta.precio * venta.cantidad << "\n";
            std::cout << "------------------------\n";
        }
    }
}

int main() {
    std::vector<Venta> ventas;
    int opcion;

    do {
        std::cout << "----- Registro de Ventas -----\n";
        std::cout << "1. Agregar venta\n";
        std::cout << "2. Mostrar ventas\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        
        switch (opcion) {
            case 1:
                agregarVenta(ventas);
                break;
            case 2:
                mostrarVentas(ventas);
                break;
            case 3:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción inválida. Por favor, intente nuevamente.\n";
                break;
        }
        
        std::cout << "\n";
    } while (opcion != 3);

    return 0;
}



*/
