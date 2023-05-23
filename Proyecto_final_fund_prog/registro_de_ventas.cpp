#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include<limits> // Para validacion de inputs
#include <ctime> // Trabajo con fecha del PC

using namespace std;
#define admin "admin"
#define pass "admin"

struct Producto{
    string nombre;
    float precio;
};
vector<Producto> productos;
struct Venta{
    string nombre = 0;
    int cantidad = 0;
};
vector<Venta> ventas;
struct User {
    string username_n;
    string password_n;
};
vector<User> users;

void registro_de_venta();
void inventario();
void proveedores();
void ventas_realizadas();


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
void registro_de_venta(){
    cout <<"\t\t\t..::Registro de venta::.."<<endl;
}
void inventario(){
    string nombre,precio;
    int option;
    cout <<"\t\t\t..::Inventario::..\n"<<endl;
    cout <<"\t\t1. Agregar producto"<<endl;
    cout <<"\t\t2. Ver productos"<<endl;
    cout <<"\t\t3. Eliminar producto"<<endl;
    cout <<"\t\t4. Salir"<<endl;
    cout <<"\t\tIngrese una opcion: ";cin>>option;
    switch (option){
        case 1:
            cin.ignore();
            cout << "\tNombre del producto: ";getline(cin,nombre);
            cin.ignore();
            cout<< "\tPrecio: $";getline(cin,precio);
            productos.push_back({nombre,stof(precio)});
            inventario();
            break;
        case 2:
            cout <<"---------------------------------------------"<<endl;
            cout <<"\t Producto             Precio "<<endl;
            cout <<"---------------------------------------------"<<endl;
            for(int i = 0; i < productos.size(); i++){
                cout <<"\t"<<productos[i].nombre<<"\t\t"<<productos[i].precio<<endl;
            }
            inventario();
            break;
        case 3:
            cout << "producto eliminado"<<endl;
            break;
        case 4:
            exit(0);
        default:
            cout << "Opcion invalida" << endl;
    }
}
void proveedores(){
    cout <<"\t\t\t..::Proveedores::.."<<endl;
}
void ventas_realizadas(){
    cout <<"\t\t\t..::Ventas realizadas::.."<<endl;
}
