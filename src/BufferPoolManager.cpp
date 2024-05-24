#include "../include/BufferPoolManager.h"

BufferPoolManager::BufferPoolManager() { this->numFramesTotal = 3; }

void BufferPoolManager::loadPageFromDisk(string blockPath) {
  Page tempPage;

  tempPage.setFrameID(1);

  tempPage.setContent("Megatron       5345453   Cybertron");
  tempPage.setContent("OptimusPrime   3334454   Cybertron");
  // tempPage.setContent("Bomboldi       9999999   Cybertron");
  // tempPage.setContent("Ultron         5465464   Primal   ");
  bf.setPage(tempPage, 1);

  cout << "\nPagina cargada Correctamente\n" << endl;
}

void BufferPoolManager::updatePage() {
  cout << "===================================" << endl;
  cout << "Que deseas realizar?" << endl;
  cout << "1. Añadir registro" << endl;
  cout << "2. Eliminar registro" << endl;
  cout << "3. Mostrar Pagina modificada" << endl;
  int option;
  cin >> option;

  // en addRecord estamos supomniendo que vamos a ingresar para la pagina 1
  if (option == 1) {
    bf.addRecord(1);
  } else if (option == 3) {
    bf.printPage(1);
  }
}