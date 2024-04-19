#include <iostream>
#include <cstdlib> // Necesario para la funciÃ³n system()
#include <fstream> // Para trabajar con archivos de texto
#include <iomanip> // Para std::setw()
#include <map> // Para almacenar usuarios
#include <cmath> // Para funciones matemÃ¡ticas
#include <bitset> // Para trabajar con nÃºmeros binarios
#include <limits>
#include <string>

// Codigos ANSI para colores
const std::string blue = "\x1B[34m";
const std::string magenta = "\x1B[35m";
const std::string green = "\x1B[32m";
const std::string yellow = "\x1B[33m";
const std::string cyan = "\x1B[36m";
const std::string reset = "\x1B[0m";
// CÃ³digos ANSI para colores
const std::string light_blue = "\033[1;34m";
const std::string reset_color = "\033[0m";

struct Usuario {
    std::string contrasena;
    std::string nombre; // Agregar el miembro nombre
};

bool AutenticarUsuario(const std::map<std::string, Usuario>& usuarios, const std::string& nombreUsuario, const std::string& contrasena) {
    std::map<std::string, Usuario>::const_iterator it = usuarios.find(nombreUsuario);
    if (it != usuarios.end() && it->second.contrasena == contrasena) {
        return true;
    }
    return false;
}

Usuario CrearUsuario() {
    Usuario nuevoUsuario;
    std::cout << "Creacion de nuevo usuario\n";
    std::cout << "Ingrese su nombre de usuario: ";
    std::cin >> nuevoUsuario.nombre; // Solicitar el nombre de usuario
    std::cout << "Ingrese su contrasena: ";
    std::cin >> nuevoUsuario.contrasena;
    return nuevoUsuario;
}

void ApagarComputadora() {
    char ch;
    std::cout << "Deseas apagar o reiniciar tu computadora?\n";
    std::cout << "1. Apagar\n";
    std::cout << "2. Reiniciar\n";
    std::cout << "Selecciona una opcion (1/2): ";
    std::cin >> ch;
    if (ch == '1') {
        // Apagar la computadora en Windows
        system("shutdown /s /t 0");
    } else if (ch == '2') {
        // Reiniciar la computadora en Windows
        system("shutdown /r /t 0");
    } else {
        std::cout << "Opcion no valida.\n";
    }
}

void CrearArchivoTexto() {
    std::string inputText;
    std::cout << "Ingresa el texto para guardar en el archivo: ";
    std::cin.ignore(); // Ignorar el salto de linea anterior
    std::getline(std::cin, inputText);

    std::ofstream textFile("mi_texto.txt");
    if (textFile.is_open()) {
        textFile << inputText;
        textFile.close();
        std::cout << yellow << "Texto guardado en mi_texto.txt" << reset << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
    }
}

void MostrarMenuCalculadora() {
     std::cout << blue << std::setw(25) << std::setfill('-') << "-" << reset << std::endl;
    std::cout << magenta << std::setw(25) << std::setfill(' ') << "Calculadora" << reset << std::endl;
    std::cout << blue << std::setw(25) << std::setfill('-') << "-" << reset << std::endl;
    std::cout << "1. " << yellow << "Suma\n";
    std::cout << "2. " << yellow << "Resta\n";
    std::cout << "3. " << yellow << "Multiplicacion\n";
    std::cout << "4. " << yellow << "Division\n";
    std::cout << "5. " << cyan << "Potencia\n";
    std::cout << "6. " << cyan << "Raiz cuadrada\n";
    std::cout << "7. " << cyan << "Logaritmo natural\n";
    std::cout << "8. " << cyan << "Logaritmo base 10\n\n";
    std::cout << "9. " << green << "Regresar al menu principal\n";
}

void Calculadora() {
     double num1, num2;
    int opcion;

    do {
        MostrarMenuCalculadora();
        std::cout << "Selecciona una opcion (1-9): ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout <<cyan << "Ingrese el primer numero: ";
                std::cin >> num1;
                std::cout << "Ingrese el segundo numero: ";
                std::cin >> num2;
                std::cout << "La suma es: " << blue << num1 + num2 << reset << std::endl;
                break;
            case 2:
                std::cout <<green<< "Ingrese el primer numero: ";
                std::cin >> num1;
                std::cout << "Ingrese el segundo numero: ";
                std::cin >> num2;
                std::cout << "La resta es: " << yellow << num1 - num2 << reset << std::endl;
                break;
            case 3:
                std::cout <<magenta<< "Ingrese el primer numero: ";
                std::cin >> num1;
                std::cout << "Ingrese el segundo numero: ";
                std::cin >> num2;
                std::cout << "La multiplicacion es: " << green << num1 * num2 << reset << std::endl;
                break;
            case 4:
                std::cout <<blue<< "Ingrese el primer numero: ";
                std::cin >> num1;
                std::cout << "Ingrese el segundo numero: ";
                std::cin >> num2;
                if (num2 != 0) {
                    std::cout << "La division es: " << magenta << num1 / num2 << reset << std::endl;
                } else {
                    std::cout << "No es posible dividir entre 0." << std::endl;
                }
                break;
            case 5:
                std::cout <<yellow<< "Ingrese la base: ";
                std::cin >> num1;
                std::cout << "Ingrese el exponente: ";
                std::cin >> num2;
                std::cout << "El resultado de " << num1 << " elevado a " << num2 << " es: " << yellow << std::pow(num1, num2) << reset << std::endl;
                break;
            case 6:
                std::cout <<cyan<< "Ingrese el numero: ";
                std::cin >> num1;
                if (num1 >= 0) {
                    std::cout << "La raiz cuadrada es: " << yellow << std::sqrt(num1) << reset << std::endl;
                } else {
                    std::cout << "No se puede calcular la raiz cuadrada de un numero negativo." << std::endl;
                }
                break;
            case 7:
                std::cout <<blue<< "Ingrese el numero: ";
                std::cin >> num1;
                if (num1 > 0) {
                    std::cout << "El logaritmo natural es: " << yellow << std::log(num1) << reset << std::endl;
                } else {
                    std::cout << "No se puede calcular el logaritmo de un numero no positivo." << std::endl;
                }
                break;
            case 8:
                std::cout <<green<< "Ingrese el numero: ";
                std::cin >> num1;
                if (num1 > 0) {
                    std::cout << "El logaritmo base 10 es: " << yellow << std::log10(num1) << reset << std::endl;
                } else {
                    std::cout << "No se puede calcular el logaritmo de un numero no positivo." << std::endl;
                }
                break;
            case 9:
                std::cout << "Regresando al menu principal...\n";
                break;
            default:
                std::cout << "Opcion no valida. Intentalo de nuevo." << std::endl;
        }
    } while (opcion != 9);
}

void Acumulador() {
     float cantidad = 1;
    float acumulador;
    float opcion;

    do {
        std::cout << "La cantidad actual es: " << cantidad << "\n";
        std::cout << "Por favor, ingrese una cantidad (o ingrese 0 para salir): ";
        std::cin >> acumulador;

        if (acumulador == 0) {
            std::cout << "Saliendo del acumulador...\n";
            break; // Salir del bucle si se ingresa 0
        }

        cantidad += acumulador;

        std::cout << "Su nueva cantidad es: " << cantidad << "\n";

        // Mostrar el menu de opciones nuevamente
        std::cout << "\nDesea continuar acumulando o salir?\n";
        std::cout << "1. Continuar acumulando\n";
        std::cout << "0. Salir del acumulador\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

    } while (opcion != 0);
   
}

void DecimalABinario() {
     int decimal;
    std::string binario = "";

    std::cout << "Ingrese el numero decimal a convertir a binario: ";
    std::cin >> decimal;

    if (decimal == 0) {
        binario = "0";
    } else {
        while (decimal > 0) {
            binario = (decimal % 2 == 0 ? "0" : "1") + binario;
            decimal /= 2;
        }
    }

    std::cout << "El numero binario es: " << binario << std::endl;
}

void SumaBinaria() {
    std::string binario1, binario2;
    int decimal1, decimal2;

    std::cout << "Ingrese el primer numero binario: ";
    std::cin >> binario1;
    std::cout << "Ingrese el segundo numero binario: ";
    std::cin >> binario2;

    // Convertir binario a decimal
    decimal1 = std::bitset<8>(binario1).to_ulong();
    decimal2 = std::bitset<8>(binario2).to_ulong();

    int suma = decimal1 + decimal2;

    std::cout << "La suma binaria es: " << std::bitset<8>(suma) << std::endl;
}

void MostrarMensaje(const std::string& mensaje) {
    std::cout << mensaje << std::endl;
}

void JugarAcertijoDelRio() {
    char respuesta;
    bool continuar = true;

    while (continuar) {
        // Pregunta 1
        std::cout << "A quien debera llevar primero el hombre?" << std::endl;
        std::cout << "a) el maiz b) el zorro c) el pollo" << std::endl;
        std::cin >> respuesta;

        if (respuesta == 'a') {
            MostrarMensaje("No es posible ya que el zorro se comerÃ¡ al pollo.");
        } else if (respuesta == 'b') {
            MostrarMensaje("No es posible ya que el pollo se comerÃ¡ el maÃ­z.");
        } else if (respuesta == 'c') {
            MostrarMensaje("Correcto.");

            // Pregunta 2
            std::cout << "Ahora Â¿que debe hacer el humano?" << std::endl;
            std::cout << "a) traer el pollo de regreso y cruzar con el lobo" << std::endl;
            std::cout << "b) cruzar al lobo" << std::endl;
            std::cout << "c) cruzar con el maiz" << std::endl;
            std::cin >> respuesta;

            if (respuesta == 'a') {
                MostrarMensaje("Correcto.");

                // Pregunta 3
                std::cout << "Que debe cruzar el humano ahora?" << std::endl;
                std::cout << "a) cruzar con el maiz a donde esta el lobo" << std::endl;
                std::cout << "b) cruzar con el pollo nuevamente" << std::endl;
                std::cout << "c) regresar al lobo" << std::endl;
                std::cin >> respuesta;

                if (respuesta == 'a') {
                    MostrarMensaje("Correcto.");

                    // Pregunta 4
                    std::cout << "Ahora que debe hacer el humano?" << std::endl;
                    std::cout << "a) regresar al maiz" << std::endl;
                    std::cout << "b) volver por el pollo y cruzar con el por ultima vez" << std::endl;
                    std::cout << "c) regresar al pollo" << std::endl;
                    std::cin >> respuesta;

                    if (respuesta == 'a') {
                        MostrarMensaje("No es posible ya que el pollo se comera el maÃ­z.");
                    } else if (respuesta == 'b') {
                        MostrarMensaje("Correcto, terminaste el acertijo.");
                        MostrarMensaje("La solucion es la siguiente:");
                        MostrarMensaje("El hombre y el pollo cruzan el rio (el zorro y el maiz estan seguros juntos), deja el pollo al otro lado y cruza de vuelta.");
                        MostrarMensaje("Entonces toma el zorro al otro lado del rio, y como no puede dejarlo con el pollo, se trae el pollo de vuelta.");
                        MostrarMensaje("Igualmente, como el pollo y el maÃ­z no pueden quedar solos, deja al pollo y cruza con el maÃ­z adonde estÃ¡ el zorro.");
                        MostrarMensaje("Despues vuelve a por el pollo y cruza con Ã©l por Ãºltima vez.");
                        continuar = false; // Termina el acertijo
                    }
                } else if (respuesta == 'b') {
                    MostrarMensaje("No es posible ya que si llevas el pollo el lobo se lo puede comer.");
                } else if (respuesta == 'c') {
                    MostrarMensaje("No es posible ya que si regresas el lobo se puede comer al pollo.");
                }
            } else {
                MostrarMensaje("No es posible ya que el lobo se comerÃ¡ al pollo.");
            }
        } else {
            MostrarMensaje("OpciÃ³n incorrecta, vuelve a intentarlo.");
        }
    }
}

int main() {
    std::map<std::string, Usuario> usuarios;
    
    // Agregar usuario predeterminado
    usuarios["Legolas"] = {"12345", "Legolas"};

    // Autenticacion de usuario predeterminado
    std::cout << "\n\n\n\n=== Iniciar sesion ===" << std::endl;
    std::string nombreUsuario, contrasena;
    std::cout << "Ingrese su nombre de usuario: ";
    std::cin >> nombreUsuario;
    std::cout << "Ingrese su contrasena: ";
    std::cin >> contrasena;

    if (AutenticarUsuario(usuarios, nombreUsuario, contrasena)) {
        std::cout << "\n\n\n\nInicio de sesion exitoso como " << cyan << nombreUsuario << reset << ".\n";
    } else {
        std::cout << "\n\n\n\nUsuario o contrasena incorrectos. Saliendo del programa." << std::endl;
        return 1;
    }
    
    // Declarar Usuario fuera del switch
    Usuario nuevoUsuario;

    // Menu principal
    int opcion;
    do {
        std::cout << "\n\n\n\n=== Usuario: " << cyan << nombreUsuario << reset << " ===\n"; // Mostrar el nombre del usuario
        
        std::cout << "\nMenu de opciones:" << std::endl;
        std::cout << blue << "1. " << magenta << "Apagar o reiniciar la computadora" << reset << std::endl;
        std::cout << blue << "2. " << green << "Crear un archivo de texto" << reset << std::endl;
        std::cout << blue << "3. " << cyan << "Jugar al acertijo del rÃ­o" << reset << std::endl;
        std::cout << blue << "4. " << blue << "Calculadora" << reset << std::endl;
        std::cout << blue << "5. " << green << "Acumulador" << reset << std::endl;
        std::cout << blue << "6. " << magenta << "Convertir decimal a binario" << reset << std::endl;
        std::cout << blue << "7. " << green << "Suma binaria" << reset << std::endl;
        std::cout << blue << "8. " << green << "Cambiar usuario" << reset << std::endl;
        std::cout << blue << "9. " << magenta << "Crear usuario" << reset << std::endl;
        std::cout << blue << "10. " << cyan << "Cerrar sesion" << reset << std::endl;
        std::cout << "Selecciona una opcion (1-10): ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                ApagarComputadora();
                break;
            case 2:
                CrearArchivoTexto();
                break;
            case 3:
                JugarAcertijoDelRio();
                break;
            case 4:
                Calculadora();
                break;
            case 5:
                Acumulador();
                break;
            case 6:
                DecimalABinario();
                break;
            case 7:
                SumaBinaria();
                break;
            case 8:
                std::cout << "Cambiando usuario...\n";
                std::cout << "Ingrese su nombre de usuario: ";
                std::cin >> nombreUsuario;
                std::cout << "Ingrese su contrasena: ";
                std::cin >> contrasena;

                if (AutenticarUsuario(usuarios, nombreUsuario, contrasena)) {
                    std::cout << "\nInicio de sesion exitoso como " << cyan << nombreUsuario << reset << ".\n";
                } else {
                    std::cout << "\nUsuario o contrasena incorrectos. Regresando al menu principal." << std::endl;
                }
                break;
            case 9:
                nuevoUsuario = CrearUsuario();
                usuarios[nuevoUsuario.nombre] = nuevoUsuario;
                std::cout << "Usuario creado exitosamente.\n";
                break;
            case 10:
                system("cls"); // Limpiar la pantalla (para Windows)
            
                std::cout << light_blue << "  CCCCC   EEEEE   EEEEE   " << reset_color << "\n";
                std::cout << light_blue << " C       E       E        " << reset_color << "\n";
                std::cout << light_blue << " C       EEEE    EEEE   " << reset_color << "\n";
                std::cout << light_blue << " C       E       E        " << reset_color << "\n";
                std::cout << light_blue << "  CCCCC   EEEEE   EEEEE   " << reset_color << "\n";
                std::cout << "\n\n";
                std::cout <<"Gracias por usar CE&E\n\n\n\n\nCerrando sesion. Hasta luego!";
                return 0;
            default:
                std::cout << "Opcion no valida. Por favor, selecciona una opcion del 1 al 10.\n";
        }
    } while (opcion != 10);

    return 0;
}