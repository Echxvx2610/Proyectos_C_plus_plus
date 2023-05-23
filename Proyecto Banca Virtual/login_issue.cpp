#include <iostream>
#include <string>
using namespace std;

#define USER "ADMIN"
#define PASSW 2223

int main() {
    string username_n,password_n;
    string users[] = {"Cristian","Oscar"};
    string passw[] = {"2610","5445"};
    
    cout << "nombre: ";cin >> username_n;
    cout << "password: ";cin >>password_n;
    int i = std::stoi(password_n);
    cout << "Tu usuario: "<<username_n <<"\n";
    cout << "Tu password: "<<i<<"\n";
    if((username_n == users[0] && password_n == passw[0])||(username_n == USER && i == PASSW)){
        cout << "Bienvenido!";
    }
    else{
        cout<<"Acceso denegado,intenta de nuevo....";
    }
    
    return 0;
}
