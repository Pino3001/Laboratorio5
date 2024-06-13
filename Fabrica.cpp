#include "Fabrica.h"
#include "CUsuario.h"

// Inicialización del puntero estático a instancia única
Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IUsuario* Fabrica::getIUsuarior() {
    return new CUsuario();  // Devuelve una instancia de Controlador que implementa IControlador
}
Fabrica::~Fabrica() {
    // Destructor
}