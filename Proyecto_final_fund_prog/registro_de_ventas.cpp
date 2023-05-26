#include <iostream>
#include <string>   
#include <vector>   //trabajar con Vectores  
#include <stdio.h>
#include<limits>    // Para validacion de inputs
#include <iomanip> // Para setw() y left (tabla dinamica)
#include <ctime>   // Para trabajar con fechas y tiempos


/*  
            ----- PROYECTO FINAL FUNDAMENTOS PROG. -----
CONTENIDO DEL CODIGO:
- LOGIN                                             [SUCCESS]
- CREAR USUARIOS                                    [SUCCESS]
- FUNCION INVENTARIO                                [SUCCESS]
- FUNCION REGISTRO DE VENTA                         [IN PROCESS]
- FUNCION VISTA DE VENTAS                           [IN PROCESS]
- FUNCION PROOVEDORES                               [MAYBE LATER]

CONDICIONES AGREGADAS:
-CONDICION GENERAL DE REGRESO                       [SUCCESS]
-TABLA DINAMICA PARA PRODUTOS                       [SUCCESS]
-FECHA EN TABLA DINAMICA                            [SUCCESS]

ISSUE
- Registro de venta no descuenta Inventario

*/


//namespace's

using namespace std;

//Establecer un administrador
#define admin "admin" //cambiar usuario por dueño
#define pass "admin" //cambiar contraseña por contraseña dueño


//variables globales


//Estructura Producto
struct Producto{
    string nombre;
    float precio;
    int cantidadI;
};
vector<Producto> Inventario;

//Estructura Venta
struct RegistroVenta{
    string nombre;
    float precio;
    int cantidadV;
    float total;
};
vector<RegistroVenta> registrosVenta;

//Estructura User
struct User {
    string username_n;
    string password_n;
};
vector<User> users;

//Marco de funciones
void createUser();
void login();
void menu();
void registro_de_venta();
void inventario();
void proveedores();
void ventas_realizadas();
string obtenerFechaActual();


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
        switch(option){
            case 1:
                system("cls");
                createUser();
                break;
            case 2:
                system("cls");
                login();
                break;
            case 3:
                system("cls");
                break;
            default:
            system("cls");
            cout <<"\tOpción inválida. Intente de nuevo." << endl;
        }
    }
    return 0;
}


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
            cout << "\t\t1. Registro de venta"<<endl;
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

//funcion registro_de_venta
void registro_de_venta(){
    string nombre,precio,cantidadV;
    string username_n, password_n;
    int option,a,b,c,d;
    float total;
    // Establecer ancho fijo para cada columna
    const int ancho_fecha = 12;
    const int ancho_nombre = 20;
    const int ancho_precio = 10;
    const int ancho_stock = 10;
    const int ancho_total = 10;
    cout <<"\t\t\t..::Registro de Ventas::..\n"<<endl;
    cout <<"\t\t1. Registrar venta"<<endl;
    cout <<"\t\t2. Ver ventas realizadas"<<endl;
    cout <<"\t\t3. Eliminar venta"<<endl;
    cout <<"\t\t4. Regresar"<<endl;
    cout <<"\t\t5. Salir"<<endl;
    cout <<"\t\tIngrese una opcion: ";cin>>option;
    cout<<endl;
    switch(option){
        case 1:
            a = 1;
            while(a==1){
                cin.ignore();
                //falta bloque validar si existe el producto en inventario y que se tenga suficiente cantidad del mismo
                cout << "\t\tNombre del producto: ";getline(cin,nombre);
                cout<< "\t\tPrecio: $";getline(cin,precio);
                cout << "\t\tCantidad vendida:";getline(cin,cantidadV);
                total = stof(precio) * stof(cantidadV);
                registrosVenta.push_back({nombre,stof(precio),stoi(cantidadV),total});//stof: convertir string a float / stoi: convertir string a int
                cout <<"\n\t\t1. Ingresar otra venta.."<<endl;
                cout<<"\t\t2. Regresar.."<<endl;
                cout <<"\t\tIngrese una Opcion: ";cin>>a;
                cout <<endl;
                if(a==1){
                    a = 1;
                }
                else if(a==2){
                    registro_de_venta();
                }
            }
            break;
        case 2:
            // Imprimir la tabla
            cout <<"\t\t----------------------------------------------------------------"<<endl;
            std::cout<<"\t\t"<< std::left <<std::setw(ancho_fecha)<<" Fecha"<< std::setw(ancho_nombre) << "Nombre"<< std::setw(ancho_precio) << "Precio"<< std::setw(ancho_stock) << "Cantidad" <<std::setw(ancho_total)<<"Total"<<"\n";
            cout <<"\t\t----------------------------------------------------------------"<<endl;
            for (const auto& venta : registrosVenta) {
                std::cout <<"\t\t"<< std::left <<std::setw(ancho_fecha)<<obtenerFechaActual()<< std::setw(ancho_nombre) << venta.nombre<< std::setw(ancho_precio) << venta.precio<< std::setw(ancho_stock) << venta.cantidadV<<std::setw(ancho_total)<<venta.total<< "\n";
            }
            cout << endl;
            cout <<"\t\t1. Regresar.."<<endl;
            cout<<"\t\t2. Salir.."<<endl;
            cout <<"\t\tIngrese una Opcion: ";cin>>b;
            if(b==1){
                registro_de_venta();
            }
            else if(b==2){
                exit(0);
            }
            else{
                cout << "\t\t Opcion incorrecta!"<<endl;
            }
            break;
        case 3:
            cout <<"\n\t\t...:::Acceso para administrador,por favor identifiquese!!:::."<<endl;
            cout<<"\n\t\t======================================================================\n"<<endl;
            cout <<"\t\t!!!!*****Acceso Restringido || Solo administradores ||*****!!!!"<<endl;
	        cout<<"\t\t======================================================================\n\n"<<endl;
            cout <<"\tPor favor autentifiquese o solicite ayuda de un administrador.."<<endl;
            cout << "\tUsuario: ";cin >> username_n;
            cout <<"\tContraseña: ";cin>>password_n;
            if (users[0].username_n == username_n && users[0].password_n == password_n){
                cout << "\tBienvenid@ "<<username_n<<endl<<endl;
                registrosVenta.pop_back();
            }
            else{
                cout<<"\t Usuario incorrecto!"<<endl;
                registro_de_venta();
            }
            break;
        case 4:
            system("cls");
            menu();
            break;
        case 5:
            break;
        
        default:
        cout << "Opcion invalida" << endl;
    }
}

//funcion inventario
void inventario(){
    string nombre,precio,cantidadI;
    int option,a,b,c,d;
    // Establecer ancho fijo para cada columna
    const int ancho_fecha = 12;
    const int ancho_nombre = 20;
    const int ancho_precio = 10;
    const int ancho_stock = 10;
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
            a = 1;
            while(a==1){
                cin.ignore();
                cout << "\t\tNombre del producto: ";getline(cin,nombre);
                cout<< "\t\tPrecio: $";getline(cin,precio);
                cout << "\t\tStock:";getline(cin,cantidadI);
                Inventario.push_back({nombre,stof(precio),stoi(cantidadI)});//stof: convertir string a float / stoi: convertir string a int
                cout <<"\n\t\t1. Ingresar otro producto.."<<endl;
                cout<<"\t\t2. Regresar.."<<endl;
                cout <<"\t\tIngrese una Opcion: ";cin>>a;
                cout <<endl;
                if(a==1){
                    a = 1;
                }
                else if(a==2){
                    inventario();
                }
            }
            break;
        case 2:
            // Imprimir la tabla
            cout <<"\n\t\t----------------------------------------------------------------"<<endl;
            std::cout<<"\t\t"<< std::left <<std::setw(ancho_fecha)<<" Fecha"<< std::setw(ancho_nombre) << "Nombre"<< std::setw(ancho_precio) << "Precio"<< std::setw(ancho_stock) << "Stock" << "\n";
            cout <<"\t\t----------------------------------------------------------------"<<endl;
            for (const auto& productos : Inventario) {
                std::cout <<"\t\t"<< std::left <<std::setw(ancho_fecha)<<obtenerFechaActual()<< std::setw(ancho_nombre) << productos.nombre<< std::setw(ancho_precio) << productos.precio<< std::setw(ancho_stock) << productos.cantidadI << "\n";
            }
            cout << endl;
            cout <<"\t\t1. Regresar.."<<endl;
            cout<<"\t\t2. Salir.."<<endl;
            cout <<"\t\tIngrese una Opcion: ";cin>>b;
            if(b==1){
                inventario();
            }
            else if(b==2){
                exit(0);
            }
            else{
                cout << "\t\t Opcion incorrecta!"<<endl;
            }
            break;
        case 3:
            Inventario.pop_back();
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
            system("cls");
            menu();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Opcion invalida" << endl;
    }
}

//funcion proveedores
void proveedores(){
    cout <<"\t\t\t..::Proveedores::.."<<endl;
    cout <<"\t\t Proximamente......"<<endl;
}

//funcion ventas
void ventas_realizadas(){
    float total;
    int b;
    // Establecer ancho fijo para cada columna
    const int ancho_fecha = 12;
    const int ancho_nombre = 20;
    const int ancho_precio = 10;
    const int ancho_stock = 10;
    const int ancho_total = 10;
    
    cout <<"\t\t\t\t ..::Ventas realizadas::.."<<endl;
    // Imprimir la tabla
    cout <<"\t\t----------------------------------------------------------------"<<endl;
    std::cout<<"\t\t"<< std::left <<std::setw(ancho_fecha)<<" Fecha"<< std::setw(ancho_nombre) << "Nombre"<< std::setw(ancho_precio) << "Precio"<< std::setw(ancho_stock) << "Cantidad" <<std::setw(ancho_total)<<"Total"<<"\n";
    cout <<"\t\t----------------------------------------------------------------"<<endl;
    for (const auto& venta : registrosVenta) {
              std::cout <<"\t\t"<< std::left <<std::setw(ancho_fecha)<<obtenerFechaActual()<< std::setw(ancho_nombre) << venta.nombre<< std::setw(ancho_precio) << venta.precio<< std::setw(ancho_stock) << venta.cantidadV<<std::setw(ancho_total)<<venta.total<< "\n";
    }
    cout << endl;
    cout <<"\t\t1. Regresar.."<<endl;
    cout<<"\t\t2. Salir.."<<endl;
    cout <<"\t\tIngrese una Opcion: ";cin>>b;
    if(b==1){
        menu();
    }
    else if(b==2){
        exit(0);
    }
    else{
        cout << "\t\t Opcion incorrecta!"<<endl;
    }
}

string obtenerFechaActual() {
    std::time_t tiempoActual = std::time(nullptr);
    std::tm* fecha = std::localtime(&tiempoActual);
    char fechaActual[11];
    std::strftime(fechaActual, sizeof(fechaActual), "%d/%m/%Y", fecha);
    return fechaActual;
}

void menu(){
    int option;
    cout << "\n\t\t\t..::Menu principal::.. \n";
    cout << "\t\t1. Registro de venta"<<endl;
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


/*
Funcion revisa inventario y resta de stock!(revisar)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producto{
    string name;
    float precio;
    int stock;
};

vector<Producto> Inventario;

struct RegistroVenta{
    string name;
    float precio;
    int cantidadV;
};
vector<RegistroVenta> Venta;

int main(){
    string nombreProducto;
    int cantidadVendida;
    //ver estado de Inventario
    cout <<"Estado de Inventario:"<<endl;
    Inventario.push_back({"Camisa",100,10});
    Inventario.push_back({"Pantalo",200,10});
    for(auto producto:Inventario){
        cout<<producto.name<<","<<producto.precio<<","<<producto.stock<<endl;
    }
    cout <<'\n';
    
    cout <<"Registro de venta"<<endl;
    cout <<"Ingrese el nombre del producto: ";cin>>nombreProducto;
    cout <<"Ingrese la cantidad a vender: ";cin >>cantidadVendida;
    for(auto producto:Inventario){
        if(producto.name == nombreProducto){
            cout << "El producto se encuentra en stock!"<<endl;
            if(producto.stock >= cantidadVendida){
                double totalVenta = cantidadVendida * producto.precio;
                
                Venta.push_back({nombreProducto,producto.precio,cantidadVendida});
                //descontar la cantidad vendida del Inventario
                producto.stock -= cantidadVendida;
                cout <<"Se registro la venta correctamente. total de la venta: "<<totalVenta<<endl;
                cout << "Inventario despues de venta!:"<<endl;
                for(auto producto:Inventario){
                    cout<<producto.name<<","<<producto.precio<<","<<producto.stock<<endl;
                    }
                    cout <<'\n';
            } else{
                cout << "No hay suficiente cantidad en inventario." << endl;
            }break;
        }
        cout <<"El producto no se encuentra en el inventario!.."<<endl;
    }
    
    return 0;
}

***********************************************************************************
codigo para total de venta
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producto {
    string nombre;
    double precio;
    int cantidad;
};

struct RegistroVenta {
    string nombreProducto;
    int cantidadVendida;
    double precioVenta;
};

vector<Producto> inventario;
vector<RegistroVenta> registrosVentas;

void realizarVenta() {
    string nombreProducto;
    int cantidadVendida;

    cout << "Ingrese el nombre del producto: ";
    cin >> nombreProducto;

    cout << "Ingrese la cantidad vendida: ";
    cin >> cantidadVendida;

    // Buscar el producto en el inventario
    for (auto& producto : inventario) {
        if (producto.nombre == nombreProducto) {
            // Verificar si hay suficiente cantidad en inventario
            if (producto.cantidad >= cantidadVendida) {
                // Calcular el total de la venta
                double totalVenta = cantidadVendida * producto.precio;

                // Crear un objeto RegistroVenta y agregarlo al vector registrosVentas
                RegistroVenta registro;
                registro.nombreProducto = nombreProducto;
                registro.cantidadVendida = cantidadVendida;
                registro.precioVenta = totalVenta;
                registrosVentas.push_back(registro);

                // Descontar la cantidad vendida del inventario
                producto.cantidad -= cantidadVendida;

                cout << "Venta registrada correctamente. Total de la venta: " << totalVenta << endl;
            } else {
                cout << "No hay suficiente cantidad en inventario." << endl;
            }
            break;
        }
    }
}

void mostrarVentas() {
    // Código para mostrar las ventas registradas
    for (const auto& venta : registrosVentas) {
        cout << "Producto: " << venta.nombreProducto << endl;
        cout << "Cantidad vendida: " << venta.cantidadVendida << endl;
        cout << "Total de la venta: " << venta.precioVenta << endl;
        cout << endl;
    }
}

int main() {
    // ...

    realizarVenta();
    mostrarVentas();

    // ...
    


    return 0;
}
*****************************************************************************************
Comprobar que exista Producto y cantidad 
#include <iostream>
#include <vector>
#include <string>

// Estructura Producto
struct Producto {
    std::string nombre;
    double precio;
    int stock;
};

// Estructura RegistroVentas
struct RegistroVentas {
    std::string nombre;
    double precio;
    int cantidadVendida;
};

// Vectores globales
std::vector<Producto> Inventario;
std::vector<RegistroVentas> Registro;

// Función para registrar una venta
void registrarVenta(const std::string& nombreProducto, int cantidad) {
    // Buscar el producto en el inventario
    for (auto& producto : Inventario) {
        if (producto.nombre == nombreProducto) {
            // Verificar si hay suficiente stock
            if (producto.stock >= cantidad) {
                // Calcular el total de la venta
                double totalVenta = producto.precio * cantidad;
                std::cout << "Total de la venta: " << totalVenta << std::endl;

                // Registrar la venta en el vector Registro
                RegistroVentas venta;
                venta.nombre = nombreProducto;
                venta.precio = producto.precio;
                venta.cantidadVendida = cantidad;
                Registro.push_back(venta);

                // Actualizar el stock en el inventario
                producto.stock -= cantidad;
            } else {
                std::cout << "No hay suficiente stock para realizar la venta." << std::endl;
            }
            return;
        }
    }

    // Si el producto no se encuentra en el inventario
    std::cout << "El producto no está disponible en el inventario." << std::endl;
}

int main() {
    // Ejemplo de uso
    Producto producto1 = { "Producto 1", 10.0, 5 };
    Producto producto2 = { "Producto 2", 15.0, 10 };
    Inventario.push_back(producto1);
    Inventario.push_back(producto2);

    registrarVenta("Producto 1", 3);  // Registra una venta de 3 unidades del Producto 1
    registrarVenta("Producto 2", 12); // Intenta registrar una venta de 12 unidades del Producto 2 (no hay suficiente stock)

    return 0;
}


*/
