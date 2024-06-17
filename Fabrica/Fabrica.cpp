#include "Fabrica.h"
#include "CUsuario.h"
#include "CRegistroMedico.h"

// Inicialización del puntero estático a instancia única
Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IUsuario* Fabrica::getIUsuario() {
    return new CUsuario();  // Devuelve una instancia de Controlador que implementa IControlador
}
IRegistroMedico* Fabrica::getIRegistroMedico(){
    return new CRegistroMedico();
}
Fabrica::~Fabrica() {
    // Destructor
}