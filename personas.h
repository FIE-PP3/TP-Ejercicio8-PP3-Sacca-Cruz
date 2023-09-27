//
// Created by pabli on 26/9/2023.
//

#ifndef TP_EJERCICIO8_PP3_PERSONAS_H
#define TP_EJERCICIO8_PP3_PERSONAS_H

#include "celular.h"
#include "mensajes.h"

class Persona {
private:
    Celular* celular;
    CompaniaTelefonica* compania;
    float totalCostoLlamadas;
    int mensajesRecibidos;

public:
    Persona(Celular* c, CompaniaTelefonica* ct) : celular(c), compania(ct), totalCostoLlamadas(0), mensajesRecibidos(0) {}

    ~Persona() {
        delete celular;
        delete compania;
    }

    void llamar(Persona& p, int duracion) {
        if (estaCelularApagado()) {
            std::cout << "\nNo puedes hacer una llamada. Tu celular esta apagado.\n" << std::endl;
            return;
        }

        if (p.estaCelularApagado()) {
            std::cout << "\nNo puedes llamar a " << p.getCelular()->getModelo() << ". Su celular está apagado.\n" << std::endl;
            return;
        }

        celular->realizarLlamada(duracion);
        totalCostoLlamadas += compania->calcularCostoLlamada(duracion);
    }

    void enviarMensaje(Persona& p, const std::string& texto) {
        if (estaCelularApagado()) {
            std::cout << "\nNo podes enviar un mensaje. Tu celular esta apagado.\n" << std::endl;
            return;
        }

        if (p.estaCelularApagado()) {
            std::cout << "\nNo podes enviar un mensaje a " << p.getCelular()->getModelo() << ". Su celular esta apagado.\n" << std::endl;
            return;
        }

        p.getCelular()->recibirMensaje(MensajeTexto(texto, compania->getCostoMensaje()));
        totalCostoLlamadas += compania->getCostoMensaje();
        p.mensajesRecibidos++;
    }

    void recargarCelular() {
        celular->recargar();
    }

    bool estaCelularApagado() const {
        return celular->estaApagado();
    }

    float getTotalCostoLlamadas() const {
        return totalCostoLlamadas;
    }

    int getMensajesRecibidos() const {
        return mensajesRecibidos;
    }

    Celular* getCelular() const {
        return celular;
    }
    bool recibioMensaje(const std::string& texto) const {
        return celular->tieneMensaje() && celular->getMensajeRecibido() == texto;
    }

    bool recibioMensajeCon(const std::string& textoInicio) const {
        return celular->tieneMensaje() && celular->getMensajeRecibido().find(textoInicio) == 0;
    }
};



#endif //TP_EJERCICIO8_PP3_PERSONAS_H
