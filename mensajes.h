// TP-Ejercicio8-PP3-Sacca-Cruz

#ifndef TP_EJERCICIO8_PP3_MENSAJES_H
#define TP_EJERCICIO8_PP3_MENSAJES_H

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



#endif //TP_EJERCICIO8_PP3_MENSAJES_H
