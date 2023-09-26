//
// Created by pabli on 26/9/2023.
//

#ifndef TP_EJERCICIO8_PP3_CELULARES_H
#define TP_EJERCICIO8_PP3_CELULARES_H



class MensajeTexto {
private:
    std::string texto;
    float costo;

public:
    MensajeTexto(const std::string& texto, float costo) : texto(texto), costo(costo) {}

    const std::string& getTexto() const {
        return texto;
    }

    float getCosto() const {
        return costo;
    }
};


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
            std::cout << "No se puede hacer una llamada. El celular " << getModelo() << " está apagado." << std::endl;
            return;
        }

        bateria -= 0.1 * duracion;
        std::cout << "Llamada con " << getModelo() << " por " << duracion << " minutos." << std::endl;
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
        std::cout << "Celular " << modelo << " recargado. Batería al 100%" << std::endl;
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
            std::cout << "No se puede hacer una llamada. El celular " << getModelo() << " está apagado." << std::endl;
            return;
        }

        bateria -= 0.05 * duracion; // Descarga más lenta para el SamsungS21
        std::cout << "Llamada con " << getModelo() << " por " << duracion << " minutos." << std::endl;
    }
};

class iPhone : public Celular {
public:
    iPhone(const std::string& modelo) : Celular(modelo) {}

    void realizarLlamada(int duracion) override {
        if (estaApagado()) {
            std::cout << "No se puede hacer una llamada. El celular " << getModelo() << " está apagado." << std::endl;
            return;
        }

        bateria -= 0.1 * duracion;
        std::cout << "Llamada con " << getModelo() << " por " << duracion << " minutos." << std::endl;
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
