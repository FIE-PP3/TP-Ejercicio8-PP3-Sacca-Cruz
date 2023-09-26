#include <iostream>
#include <string>
#include "helper.h"

// Función para mostrar el estado de las personas y celulares
void mostrar(const Persona& juliana, const Persona& catalina, const Persona& juan, const Persona& ernesto) {
    std::cout << "Bateria del " << juliana.getCelular()->getModelo() << " de Juliana: " << juliana.getCelular()->getBateria() << "%" << std::endl;
    std::cout << "Bateria del " << catalina.getCelular()->getModelo()  << catalina.getCelular()->getBateria() << "%" << std::endl;
    std::cout << "Bateria del " << juan.getCelular()->getModelo()  << juan.getCelular()->getBateria() << "%" << std::endl;
    std::cout << "Bateria del " << ernesto.getCelular()->getModelo()  << ernesto.getCelular()->getBateria() << "%" << std::endl;
    std::cout << "Costo total de llamadas de Juliana: $" << juliana.getTotalCostoLlamadas() << std::endl;
    std::cout << "Costo total de llamadas de Catalina: $" << catalina.getTotalCostoLlamadas() << std::endl;
    std::cout << "Costo total de llamadas de Juan: $" << juan.getTotalCostoLlamadas() << std::endl;
    std::cout << "Costo total de llamadas de Ernesto: $" << ernesto.getTotalCostoLlamadas() << std::endl;
    std::cout << "Mensajes recibidos por Juliana: " << juliana.getMensajesRecibidos() << std::endl;
    std::cout << "Mensajes recibidos por Catalina: " << catalina.getMensajesRecibidos() << std::endl;
    std::cout << "Mensajes recibidos por Juan: " << juan.getMensajesRecibidos() << std::endl;
    std::cout << "Mensajes recibidos por Ernesto: " << ernesto.getMensajesRecibidos() << std::endl;
}
int main() {
    SamsungS21 s21;
    iPhone iphoneCatalina("iPhone de Catalina: ");
    iPhone iphoneJuan("iPhone de Juan: ");
    iPhone iphoneErnesto("iPhone de Ernesto: ");
    Movistar movistar;
    Personal personal;
    Claro claro;

    Persona juliana(&s21, &personal);
    Persona catalina(&iphoneCatalina, &movistar);
    Persona juan(&iphoneJuan, &personal);
    Persona ernesto(&iphoneErnesto, &claro);
    while (true) {

        mostrar(juliana, catalina, juan, ernesto);
        if (juan.recibioMensaje("hola juan")) {
            std::cout << "Juan recibio el mensaje: 'hola juan'" << std::endl;
        }

        if (ernesto.recibioMensajeCon("este mensaje")) {
            std::cout << "Ernesto recibio un mensaje que comienza con 'este mensaje'" << std::endl;
        }
        std::string eleccion;
        std::cout << "\nElige una accion (llamar / mensaje / recargar / salir): ";
        std::cin >> eleccion;

        if (eleccion == "salir") {
            break;
        } else if (eleccion == "llamar") {
            std::string emisor, receptor;
            int duracion;
            std::cout << "Ingresa el nombre del emisor de la llamada (Juliana, Catalina, Juan, Ernesto): ";
            std::cin >> emisor;
            std::cout << "Ingresa el nombre del receptor de la llamada (Juliana, Catalina, Juan, Ernesto): ";
            std::cin >> receptor;
            std::cout << "Elige la duracion de la llamada: ";
            std::cin >> duracion;

            if (emisor == "Juliana") {
                if (receptor == "Catalina") {
                    juliana.llamar(catalina, duracion);
                } else if (receptor == "Juan") {
                    juliana.llamar(juan, duracion);
                } else if (receptor == "Ernesto") {
                    juliana.llamar(ernesto, duracion);
                }
            } else if (emisor == "Catalina") {
                if (receptor == "Juliana") {
                    catalina.llamar(juliana, duracion);
                } else if (receptor == "Juan") {
                    catalina.llamar(juan, duracion);
                } else if (receptor == "Ernesto") {
                    catalina.llamar(ernesto, duracion);
                }
            } else if (emisor == "Juan") {
                if (receptor == "Juliana") {
                    juan.llamar(juliana, duracion);
                } else if (receptor == "Catalina") {
                    juan.llamar(catalina, duracion);
                } else if (receptor == "Ernesto") {
                    juan.llamar(ernesto, duracion);
                }
            } else if (emisor == "Ernesto") {
                if (receptor == "Juliana") {
                    ernesto.llamar(juliana, duracion);
                } else if (receptor == "Catalina") {
                    ernesto.llamar(catalina, duracion);
                } else if (receptor == "Juan") {
                    ernesto.llamar(juan, duracion);
                }
            }
        } else if (eleccion == "mensaje") {
            std::string emisor, receptor, texto;
            std::cout << "Ingresa el nombre del remitente del mensaje (Juliana, Catalina, Juan, Ernesto): ";
            std::cin >> emisor;
            std::cout << "Ingresa el nombre del destinatario del mensaje (Juliana, Catalina, Juan, Ernesto): ";
            std::cin >> receptor;
            std::cout << "Ingresa el texto del mensaje: ";
            std::cin.ignore();
            std::getline(std::cin, texto);

            if (emisor == "Juliana") {
                if (receptor == "Catalina") {
                    juliana.enviarMensaje(catalina, texto);
                } else if (receptor == "Juan") {
                    juliana.enviarMensaje(juan, texto);
                } else if (receptor == "Ernesto") {
                    juliana.enviarMensaje(ernesto, texto);
                }
            } else if (emisor == "Catalina") {
                if (receptor == "Juliana") {
                    catalina.enviarMensaje(juliana, texto);
                } else if (receptor == "Juan") {
                    catalina.enviarMensaje(juan, texto);
                } else if (receptor == "Ernesto") {
                    catalina.enviarMensaje(ernesto, texto);
                }
            } else if (emisor == "Juan") {
                if (receptor == "Juliana") {
                    juan.enviarMensaje(juliana, texto);
                } else if (receptor == "Catalina") {
                    juan.enviarMensaje(catalina, texto);
                } else if (receptor == "Ernesto") {
                    juan.enviarMensaje(ernesto, texto);
                }
            } else if (emisor == "Ernesto") {
                if (receptor == "Juliana") {
                    ernesto.enviarMensaje(juliana, texto);
                } else if (receptor == "Catalina") {
                    ernesto.enviarMensaje(catalina, texto);
                } else if (receptor == "Juan") {
                    ernesto.enviarMensaje(juan, texto);
                }
            }
        } else if (eleccion == "recargar") {
            std::string persona;
            std::cout << "Elige la persona a la que se va a recargar el telefono (Juliana, Catalina, Juan, Ernesto): ";
            std::cin >> persona;

            if (persona == "Juliana") {
                juliana.recargarCelular();
            } else if (persona == "Catalina") {
                catalina.recargarCelular();
            } else if (persona == "Juan") {
                juan.recargarCelular();
            } else if (persona == "Ernesto") {
                ernesto.recargarCelular();
            }
        }
        limpiarpantalla();

    }

    return 0;
}
