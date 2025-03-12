#include <iostream>
using namespace std;

double add(int a, int b)
{
    return a + b;
}

double subtract(int a, int b)
{
    return a - b;
}

double multiply(int a, int b)
{
    return a * b;
}

double division(int a, int b)
{
    return static_cast<double>(a) / b;
}//Funcion usada para realizar la division de modo que no se operen los enetros y se pierda el valor decimal


void performOperation(double (*callback)(int, int), int x, int y)
{
    cout << "The result of the operation is: " << callback(x, y) << endl;
}

int main(int argc, char *argv[])
{
    int j=0;
    int num1 = std::atoi(argv[1]); // Desgloce de valores insertados en consola para su manipulación
    int num2 = std::atoi(argv[3]);
    char opc = *argv[2];
    cout << "Operación: " << opc << "\n"; 
    if (opc == '+'){
        j = 0;
    }
    else if (opc == '-')
    {
         j = 1;
    }
    else if (opc == '*')
    {
         j = 2;
    }
    else if (opc == '/')
    {
        if (num2 == 0){
            cout << "Ingrese divisor distinto de 0 \n";
            return 1;
        }
        else {
            j = 3;
        }
    }

    double (*operations[])(int, int) = {add, subtract, multiply, division};
        cout << "Operation " << j + 1 << ": ";
        performOperation(operations[j], num1, num2); 
        //Funcion que opera un vector puntero hacia otro puntero, para alojar todas las posibles operaciones en una unica función
    return 0;
}
