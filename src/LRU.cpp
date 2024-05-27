#include "../include/LRU.h"

#include <algorithm>

/*En esta funcion vemos la página ya está en la lista  LRU
si aes asi la mandamos al final*/
void LRU::pin(int pageID) {
  auto it = find(lru.begin(), lru.end(), pageID);
  if (it != lru.end()) {
    lru.erase(it);
  }
  lru.push_back(pageID);
}

void LRU::unPin() {
  /* Si hay páginas en la lista, eliminamos la más antigua
  En este caso la primera
  */
  if (!lru.empty()) {
    lru.erase(lru.begin());
  }
}

int LRU::getLRUforDelete() {
  if (!lru.empty()) {
    return lru.front();  // Retornamos el ID de la página menos recientemente
                         // utilizada para nuestr caso la primera
  }
  return -1;  // Si no hay páginas en la lista, retornamos un valor negativo
              // para indicar que no hay ninguna página para eliminar
}
