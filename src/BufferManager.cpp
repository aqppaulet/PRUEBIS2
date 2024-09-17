#include "../include/BufferManager.h"

#include "../include/Frame.h"
#include "../include/Page.h"

// configura LRU (Least Recently Used) con el número total de frames.

BufferManager::BufferManager(int numFrames, char policy) {
    this->numFrames = numFrames;
    this->bpool = BufferPool(numFrames);
    this->policy = policy;
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
        if (mode) {
            bpool.getFrame(bpool.getFrameId(pageID)).setDirtyFlag(true);
        }else {bpool.getFrame(bpool.getFrameId(pageID)).setDirtyFlag(false);}
        bpool.modifyPinInExistingFrame(pageID, 'i');
        bpool.incrementHistory();
        bpool.printTableFrame();
        return;
    }

    if (policy == 'L') {
        bpool.LRU();
    } else if (policy == 'C') {
        bpool.Clock();
    } else {
        cout << "Politica de reemplazo no valida" << endl;
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

    bpool.setPageInFrame(idFree, pageID, tempFrame);
    bpool.incrementHistory();
    bpool.printTableFrame();
}

void BufferManager::killProcess(int pageID) {
    bpool.modifyPinInExistingFrame(pageID, 'k');
    // bpool.incrementHistory();
    bpool.printTableFrame();
}

void BufferManager::printTableFrame() {
    bpool.printTableFrame();
}
