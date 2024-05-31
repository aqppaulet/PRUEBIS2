#include <iostream>
#include <string>
#include <vector>

#include "../include/BufferPool.h"
#include "../include/Frame.h"

using namespace std;

/* Temporal */
// *************************************************
Frame::Frame(int id, bool dirty, int pin, Page pg) {
    this->frameID = id;
    this->dirty_flag = dirty;
    this->pinCount = pin;
    this->page = pg;
}
// *************************************************
/* Temporal */

BufferPool::BufferPool() {
    this->numFrames = 6;
    this->capacity = 720;

    for (int i = 0; i < this->numFrames; i++) {
        Frame frame(i, false, 0, Page());
        this->frames.push_back(frame);
        page_table[i] = -1;
    }
}

vector<Frame>& BufferPool::getFrames() { return frames; }

void BufferPool::setPage(Frame& frame, int frameID) {
    if (frameID >= 0 && frameID < numFrames) {
        frames[frameID] = frame;
        page_table[frameID] = 1;
    } else {
        cout << "SetP: Frame ID fuera de rango" << endl;
        return;
    }
    cout << "\nPagina [" << frameID << "] cargada correctamente." << endl;
}

void BufferPool::printPage(int frameID) {
    if (frameID >= 0 && frameID < numFrames) {
        if (page_table[frameID] == 1) {
            Frame& frame = frames[frameID];
            cout << "Frame ID: " << frameID << endl;
            cout << "Dirty Flag: " << "(frame.isDirty() ? \" true \" : \" false \")" << endl;
            cout << "Pin Count: " << "frame.getPinCount()" << endl;
            cout << "Page Capacity: " << "frame.getPage().getPageCapacity()" << endl;
            cout << "Page Content: " << "frame.getPage().getPageContent() " << endl;
        } else {
            cout << "Frame ID: " << frameID << " no contiene una página." << endl;
        }
    } else {
        cout << "Frame ID fuera de rango." << endl;
    }
}

void BufferPool::addRecord(int frameID, string record) {
    if (frameID >= 0 && frameID < numFrames) {
        if (page_table[frameID] == 1) {
            Frame& frame = frames[frameID];
            // frame.getPage().addRecord(record);
            cout << "Registro agregado correctamente." << endl;
        } else {
            cout << "Frame ID: " << frameID << " no contiene una página." << endl;
        }
    } else {
        cout << "Frame ID fuera de rango." << endl;
    }
}

void BufferPool::deleteRecord(int frameID, string record) {
    if (frameID >= 0 && frameID < numFrames) {
        if (page_table[frameID] == 1) {
            Frame& frame = frames[frameID];
            // frame.getPage().deleteRecord(record);
            cout << "Registro eliminado correctamente." << endl;
        } else {
            cout << "Frame ID: " << frameID << " no contiene una página." << endl;
        }
    } else {
        cout << "Frame ID fuera de rango." << endl;
    }
}

void BufferPool::pageIsDirty(int pageID) {
    if (pageID >= 0 && pageID < numFrames) {
        if (page_table[pageID] == 1) {
            Frame& frame = frames[pageID];
            // return frame.isDirty();
            return;
        } else {
            cout << "Frame ID: " << pageID << " no contiene una página." << endl;
            return;
        }
    } else {
        cout << "Frame ID fuera de rango." << endl;
        return;
    }
}

void BufferPool::freeFrame(int frameID) {
    if (frameID >= 0 && frameID < numFrames) {
        if (page_table[frameID] == 1) {
            Frame& frame = frames[frameID];
            frame.setPinCount(0);
            page_table[frameID] = -1;
            cout << "Frame liberado correctamente." << endl;
        } else {
            cout << "Frame ID: " << frameID << " no contiene una página." << endl;
        }
    } else {
        cout << "Frame ID fuera de rango." << endl;
    }
}

void BufferPool::printTableFrame() {
    cout << "Frame Id \t Page Id \t Dirty Bit \t Pin Count" << endl;
    // for (int i = 0; i < numFrames; i++) {
    //     cout << "Frame ID: " << i << " | Estado: " << (page_table[i] == 1 ? "Ocupado" : "Libre") << endl;
    // }
}

void LRU() {
    cout << "LRU" << endl;
    /*
    En el unordered_map history, se guardará el frameID y el tiempo en el que fue accedido. Atraves de las veces que se llame en general con +1.
    Ahora se buscara cual frame tiene mas tiempo en estar. Luego se revisara si el pin count esta en cero y ahi recien se llamara la funcion freeFrame.
    */
}