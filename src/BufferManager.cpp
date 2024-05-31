#include "../include/BufferManager.h"
#include "../include/Frame.h"
#include "../include/Page.h"



//configura LRU (Least Recently Used) con el número total de frames.

BufferManager::BufferManager(int numFrames) {
  this->numFrames = numFrames;
}

/*

Carga una página desde el disco al buffer pool.
Si todos los frames están ocupados, selecciona un frame para reemplazar usando el algoritmo LRU
guarda la página reemplazada en el disco y luego carga la nueva página en ese frame.
*/

void BufferManager::loadPageFromDisk(string blockPath, int pageID) {
  Frame tempFrame;
  Page tempPage;


  // Si es -2 es porque todos los frames ya estan ocupados
  if (newId == -2) {
    newId = LRU_replace.getLRUforDelete();
    LRU_replace.deletePageIDfromLRU();

    savePageToDisk(newId);

    LRU_replace.addPageIDtoLRU(newId);

  } else {
    LRU_replace.addPageIDtoLRU(newId);
  }

  tempPage.setFrameID(newId);

  // tempPage.setContent("Bomboldi       9999999   Cybertron");
  // tempPage.setContent("Ultron         5465464   Primal   ");

  bf.setPage(tempPage, newId);
  LRU_replace.printLRU();
}


/*
  Permite al usuario interactuar con el buffer pool para agregar registros o mostrar una página específica.

*/
void BufferManager::updatePage() {
  cout << "===================================" << endl;
  cout << "Que deseas realizar?" << endl;
  cout << "1. Añadir registro" << endl;
  cout << "2. Eliminar registro" << endl;
  cout << "3. Mostrar Pagina modificada" << endl;
  int option;
  cin >> option;

  // en addRecord estamos supomniendo que vamos a ingresar para la pagina 1
  if (option == 1) {
    cout << "[A que pagina quieres agregar el registro] => ";
    cin >> option;
    bf.addRecord(option);
  } else if (option == 3) {
    cout << "[Que pagina quieres mostrar] => ";
    cin >> option;
    bf.printPage(option);
  }
}

void BufferManager::savePageToDisk(int pageId) {
  Page newfreeFrame;
  if (bf.pageIsDirty(pageId) == true) {
    cout << "Saving page in the DISK" << endl;
    bf.setPage(newfreeFrame, pageId);
  } else {
    bf.setPage(newfreeFrame, pageId);
  }
}