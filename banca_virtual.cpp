/*  
                        -----   PROYECTO BANCA VIRTUAL -----
CONTENIDO DEL CODIGO:
- CONSULTA DE SALDO                                 [DONE]
- INGRESO DE DINERO                                 [DONE]
- RETIRO DE DINERO                                  [DONE]
- BASE DE DATOS DE USUARIOS                         [IN PROCESS]
- TRANSFERENCIAS BANCARIAS ENTRE USUARIOS           [OPEN]
- CONSULTA DE MOVIMIENTOS                           [OPEN]

CONDICIONES AGREGADAS:
- NO PERMITE RETIROS DE MAS DE $9000 DIARIOS                        [IN PROCESS]
- REALIZAR INFINIDAD DE OPERACIONES EN VEZ DE 1 POR EJECUCION.      [DONE]

*/

#include <iostream>
using namespace std;


#define USER "ADMIN"
#define PASSW "0123"

//bloque de funciones

//Funcion para generacion de usuarios,no borrar se integrara base de datos
/*int usuarios(){
    int a=1;
    string usuario,password;
    
    while(a==1){
        cout <<"\t\t\tBienvenido a tu Banca Virtual"<<endl;
        cout <<"\t\t\t-----------------------------"<<endl;
        cout <<"Por favor favor Inicie sesion...";
        cout << "Usuario: ";cin >> usuario;
        cout << "Nip: ";cin >> password;
        if (usuario == USER and password == PASSW){
        cout <<"\n\tBienvenido al sistema"<<endl;
        a = 0;
        }
        else{cout <<"\n\tEl usuario y/o password son incorrectos"<<endl;
            cout<<"Desea volver a intentarlo? [1]Si,[2]No: ";
            cin>>a;
            if (a == 1){
                a = 1;}
        else{
            a =0;
        }
    }
} 
}
*/

int main() 
{
    float saldo_disponible = 100, ingresoDinero=0, montoRetirar=0, saldoActual=0;
    int opcion, respuesta;
    int a = 1; //variable para controlar el bucle while de login
    int b = 1; //variable para controlar el bucle while de banca
    string usuario,password;
    while (a==1){
    cout <<"\t\t\tBienvenido a tu Banca Virtual"<<endl;
    cout <<"\t\t\t-----------------------------"<<endl;
    cout <<"Por favor favor Inicie sesion...\n"<<endl;
    cout << "Usuario: ";cin >> usuario;
    cout << "Nip: ";cin >> password;
    if (usuario == USER and password == PASSW){
    a = 0;  //cerramos bucle while de login..
    cout << "\n\t[ BIENVENIDO A TU BANCA VIRTUAL ]" << endl;
    while(b==1){
    		cout << endl;
            cout << "[1] Consulta de saldo" << endl;
            cout << "[2] Ingresar dinero" << endl;
            cout << "[3] Retirar dinero" << endl;
            cout << "[4] Salir" << endl;
            //cout << "[5] Autenticar usuario"<<endl;
			cout << endl;
            cout << "Seleccione una opcion: ";
			cin >> opcion;
    
    switch(opcion)
        {
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
            respuesta == 1 ? b = 1 : cout << "Que tenga buen dia!";
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
            respuesta == 1 ? b = 1 : cout << "Que tenga buen dia!";
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
                respuesta == 1 ? b = 1 : cout << "Que tenga buen dia!";
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
                respuesta == 1 ? b = 1 : cout << "Que tenga buen dia!";
            }
        break;
        case 4:
            b = 0;
            cout << "Que tenga buen dia!";
            break;
        default:
            cout << "[ERROR] La opcion ["<<opcion<<"] es incorrecta";
            }
    }
    }
        else{cout <<"El usuario y/o password son incorrectos"<<endl;
        cout<<"Desea volver a intentarlo? [1]Si, [2]No: \n";
        cin>>a;
        if (a == 1){
            a = 1;}
        else{
            a =0;
        }
    }
}
    return 0;
}
