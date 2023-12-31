// TP-Ejercicio8-PP3-Sacca-Cruz

#ifndef TP_EJERCICIO8_PP3_CELULARES_H
#define TP_EJERCICIO8_PP3_CELULARES_H
#include "mensajes.h"

class Celular {
protected:
    float bateria;
    std::string modelo;
    std::string mensajeRecibido;
    int mensajesRecibidos;

public:
    Celular(const std::string& modelo) : bateria(100), modelo(modelo), mensajesRecibidos(0) {}

    virtual void realizarLlamada(int duracion) {
        if (estaApagado()) {
            std::cout << "\nNo se puede hacer una llamada. El celular " << getModelo() << " esta apagado.\n" << std::endl;
            return;
        }

        bateria -= 0.1 * duracion;
        std::cout << "\nLlamada con " << getModelo() << " por " << duracion << " minutos.\n" << std::endl;
    }

    void recibirMensaje(const MensajeTexto &mensaje) {
        bateria -= 1.0;
        mensajeRecibido = mensaje.getTexto();
        mensajesRecibidos++;
    }

    bool tieneMensaje() const {
        return !mensajeRecibido.empty();
    }

    const std::string& getMensajeRecibido() const {
        return mensajeRecibido;
    }

    int getMensajesRecibidos() const {
        return mensajesRecibidos;
    }

    void recargar() {
        bateria = 100;
        std::cout << "\nCelular " << modelo << " recargado. Bateria al 100%\n" << std::endl;
    }

    bool estaApagado() const {
        return bateria <= 0;
    }

    float getBateria() const {
        return bateria;
    }

    const std::string& getModelo() const {
        return modelo;
    }
};

class SamsungS21 : public Celular {
public:
    SamsungS21() : Celular("Samsung S21") {}

    void realizarLlamada(int duracion) override {
        if (estaApagado()) {
            std::cout << "\nNo se puede hacer una llamada. El celular " << getModelo() << " esta apagado.\n" << std::endl;
            return;
        }

        bateria -= 0.05 * duracion; // Descarga más lenta para el SamsungS21
        std::cout << "\nLlamada con " << getModelo() << " por " << duracion << " minutos.\n" << std::endl;
    }
};

class iPhone : public Celular {
public:
    iPhone(const std::string& modelo) : Celular(modelo) {}

    void realizarLlamada(int duracion) override {
        if (estaApagado()) {
            std::cout << "\nNo se puede hacer una llamada. El celular " << getModelo() << " esta apagado.\n" << std::endl;
            return;
        }

        bateria -= 0.1 * duracion;
        std::cout << "\nLlamada con " << getModelo() << " por " << duracion << " minutos.\n" << std::endl;
    }
};

class CompaniaTelefonica {
private:
    float costoLlamada;
    float costoMensaje;

public:
    CompaniaTelefonica(float costoLlamada, float costoMensaje) : costoLlamada(costoLlamada), costoMensaje(costoMensaje) {}

    float calcularCostoLlamada(int duracion) const {
        return costoLlamada * duracion;
    }

    float getCostoMensaje() const {
        return costoMensaje;
    }
};

class Movistar : public CompaniaTelefonica {
public:
    Movistar() : CompaniaTelefonica(60, 0.12) {}
};

class Claro : public CompaniaTelefonica {
public:
    Claro() : CompaniaTelefonica(50, 0.12) {}
};

class Personal : public CompaniaTelefonica {
public:
    Personal() : CompaniaTelefonica(70, 0.15) {}
};

#endif //TP_EJERCICIO8_PP3_CELULARES_H
