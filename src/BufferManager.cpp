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

void BufferManager::loadPageFromDisk(string blockPath, int pageID, char _mode) {

  bool mode = _mode == 'W' ? true : false;
  if (bpool.isPageLoaded(pageID)) {
    cout << "La pagina ya esta cargada" << endl;
    bpool.getFrame(bpool.getFrameId(pageID)).setDirtyFlag(true);
    bpool.modifyPinInExistingFrame(pageID, 'i');
    bpool.printTableFrame();
    return;
  }


  Page tempPage;
  tempPage.setName(blockPath);
  tempPage.setPageId(pageID);

  int idFree = bpool.findFreeFrame();
  Frame tempFrame(idFree);
  tempFrame.setDirtyFlag(mode);
  tempFrame.setPage(tempPage);
  tempFrame.incrementPinCount();

  bpool.setPageInFrame(idFree, pageID,tempFrame);

  bpool.printTableFrame();
}

void BufferManager::killProcess(int pageID) {
  bpool.modifyPinInExistingFrame(pageID, 'k');
  bpool.printTableFrame();
}


/*
  Permite al usuario interactuar con el buffer pool para agregar registros o mostrar una página específica.

*/
/*void BufferManager::updatePage() {
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
}*/