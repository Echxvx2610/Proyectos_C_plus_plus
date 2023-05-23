#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define USER "ADMIN"
#define PASSW 2610

/*
//definicion de usuario ADMIN
const string USER = "ADMIN";
const int PASSW = 0123;
*/

struct User {
    string username_n;
    string password_n;
};

vector<User> users;

void createUser() {
    string username_n, password_n;
    cout <<"\n\t[ BIENVENIDO A TU BANCA VIRTUAL ]"<<endl;
    cout << "Ingrese el nombre de usuario: ";
    cin >> username_n;
    cout << "Ingrese la contraseña: ";
    cin >> password_n;
    users.push_back({username_n, password_n});
    cout << "Usuario creado exitosamente." << endl;
}

void login() {
    float saldo_disponible = 100, ingresoDinero=0, montoRetirar=0, saldoActual=0;
    int opcion, respuesta;
    int a = 1; //variable para controlar el bucle while de login
    int b = 1; //variable para controlar el bucle while de banca
    string username_n, password_n;
    while(a==1){
    cout <<"\t\t\tBienvenido a tu Banca Virtual"<<endl;
    cout <<"\t\t\t-----------------------------"<<endl;
    cout <<"Por favor Inicie sesion...\n"<<endl;
    cout << "Ingrese el nombre de usuario: ";
    cin >> username_n;
    cout << "Ingrese la contraseña: ";
    cin >> password_n;
    int password_i = stoi(password_n); // convertimos el tipo de dato de password_n de string a int,para poder evaludar en el sig.if
    //int PASSW_i = stoi(PASSW);//convertimos el tipo de dato de PASSW de string a int,para poder evaludar en el sig.if
    bool found =false;
    for (int i = 0; i < users.size(); i++) {
        if ((users[i].username_n == username_n && users[i].password_n == password_n)||(USER == username_n  && PASSW == password_i)){
            found = true;
            a = 0;
            cout <<"\n\t[ BIENVENIDO A TU BANCA VIRTUAL ]"<<endl;
            while(b==1){
                cout << endl;
                cout << "[1] Consulta de saldo" << endl;
                cout << "[2] Ingresar dinero" << endl;
                cout << "[3] Retirar dinero" << endl;
                cout << "[4] Salir"<<endl;
			    cout << endl;
                cout << "Seleccione una opcion: ";
			    cin >> opcion;
			    switch(opcion){
			        case 1:
			        cout << endl;
                    cout << "\t-- [1] CONSULTA DE SALDO [1] --" << endl; cout << endl;
                    cout << "Saldo Actual: $" << saldo_disponible << endl; cout << endl;
                    cout << "Desea realizar otra operacion?" << endl; cout << endl;
                    cout << "[1] Si" << endl;
                    cout << "[0] No\n" << endl;
                    cout << "Opcion: ";
           	        cin >> respuesta;
                    //bucle para continuar o cerrar bucle while banca virtual
                    //aplicacion de operador ternario
                    if (respuesta == 1){
                        b=1;
                    }
                    else{
                        exit(0);
                    }
                    break;
			        case 2:
			        cout << endl;
                    cout << "\t-- [2] INGRESO DE DINERO [2] --" << endl; cout << endl;
                    cout << "Ingrese el monto: $ ";cin >> ingresoDinero;
        	        saldo_disponible = saldo_disponible + ingresoDinero;
                    cout << "El dinero fue ingresado correctamente." << endl;
                    cout << "Saldo actual: $" << saldo_disponible << endl; cout << endl;
                    cout << "Desea realizar otra operacion?" << endl;
                    cout << "[1] Si" << endl;
                    cout << "[0] No" << endl;
                    cout << "Opcion: ";
                    cin >> respuesta;
                    //bucle para continuar o cerrar bucle while banca virtual
                    //aplicacion de operador ternario
                    if (respuesta == 1){
                        b=1;
                    }
                    break;
                    case 3:
                    cout << endl;
                    cout << "\t-- [3] RETIRO DE DINERO [3] --" << endl; cout << endl;
                    cout << "Ingrese el monto a retirar: $"; cin >> montoRetirar; cout << endl;
                    if(montoRetirar > saldo_disponible)
                        {
                        cout << "[ERROR] No tiene esa cantidad de dinero." << endl; cout << endl;
                        cout << "Desea realizar otra operacion?" << endl;
                        cout << "[1] Si" <<endl;
                        cout << "[0] No" <<endl;
                        cout << "Opcion: ";
            	           cin >> respuesta;
                        //bucle para continuar o cerrar bucle while banca virtual
                        //aplicacion de operador ternario
                        if (respuesta == 1){
                        b=1;
                        }
                        else{
                            a = 1;
                        }
                        }
                    else{
                        cout << "El retiro se ha realizado con exito." << endl;
                        saldoActual = saldo_disponible - montoRetirar;
                        saldo_disponible = saldoActual;
                        cout << "Saldo actual: $" << saldoActual << endl; cout << endl;
                        cout << "Desea realizar otra operacion?" << endl;
            	           cout << "[1] Si" <<endl;
            	           cout << "[0] No" <<endl;
            	           cout << "Opcion: ";
            	           cin >> respuesta;
                        //bucle para continuar o cerrar bucle while banca virtual
                        if (respuesta == 1){
                            b=1;
                            }
                        }
                    break;
                    case 4:
                    cout << "Que tenga un buen dia!"<<endl;
                    exit(0);
                    break;
			        default:
			        cout << "[ERROR] la Opcion ["<<opcion<<"] es incorrecta!";
			    }
            }
        }
    }
    if (!found) {
        cout << "Usuario o contraseña incorrectos.\n" << endl;
        cout << "Desea intentarlo de nuevo?" << endl; cout << endl;
        cout << "[1] Si" << endl;
        cout << "[2] No" << endl;
        cout << "[3] Craer Usuario"<<endl;
        cout << "Opcion: ";
        cin >> respuesta;
        //bucle para continuar o cerrar bucle while banca virtual
        if (respuesta == 1){
               a=1;
            }
        else if(respuesta == 3){
            createUser();
            a=1;
        }
        else{
            cout << "Que tenga un buen dia!"<<endl;
            break;
        }
    }
  }
}

int main() {
    int option;
    while (true) {
        cout << "1. Crear usuario" << endl;
        cout << "2. Iniciar sesión" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> option;
        if (option == 1) {
            createUser();
        } else if (option == 2) {
            login();
        } else if (option == 3) {
            cout << "Que tenga un buen dia!"<<endl;
            exit(0);
            break;
        } else {
            cout << "Opción inválida. Intente de nuevo." << endl;
        }
    }
    return 0;
}
