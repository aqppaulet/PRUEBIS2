#include <iostream>

#include "include/BufferManager.h"
#include "include/Page.h"

/* Erick Malcoaccha*/
int main() {
  BufferManager BfManger;

  while (true) {
    int instruction;
    cout << "================================================================"
         << endl;
    cout << "1. Load page " << endl;
    cout << "2. UpdatePage " << endl;
    cout << "3. Kill Process " << endl;
    cout << "4. Save page " << endl;
    cout << "5. Exit" << endl;
    cout << "================================================================"
         << endl;
    cin >> instruction;

    if (instruction == 5) {
      break;
    } else if (instruction == 1) {
      cout << "En que modo desea cargar" << endl;
      cout << "(L) Lectura" << endl;
      cout << "(W) Escritura" << endl;
      char mode;
      cout << "Mode: ";
      cin >> mode;
      // BfManger.loadPageFromDisk("bloque1");
    } else if (instruction == 2) {
      // BfManger.updatePage();
    } else if (instruction == 3) {
      cout << "Indica el proceso que deseas terminar" << endl;
      int pageid;
      cout << "Page ID: ";
      cin >> pageid;
    } else if (instruction == 4) {
      cout << "Indica la pagina que deseas guardar" << endl;
      /* Aqui deberia retornarme un error si la pagina tiene procesos sin
       * terminar*/
      int pageid;
      cout << "Page ID: ";
      cin >> pageid;
    }
  }
  return 0;
}