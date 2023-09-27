// TP-Ejercicio8-PP3-Sacca-Cruz

#ifndef TP_EJERCICIO8_PP3_LIMPIARPANTALLA_H
#define TP_EJERCICIO8_PP3_LIMPIARPANTALLA_H

void limpiarpantalla(); // Prototipo de la función para limpiar la pantalla

// Función para limpiar la pantalla
void limpiarpantalla() {
#if defined(_WIN32) // Windows
    system("cls");
#elif defined(__linux__) || defined(__APPLE__) // Linux o Mac
    system("clear");
#else
    std::cout << "Sistema operativo no reconocido. No se pudo limpiar la pantalla." << std::endl;
#endif
}

#endif //TP_EJERCICIO8_PP3_LIMPIARPANTALLA_H
