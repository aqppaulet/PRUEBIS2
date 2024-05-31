#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H


#include <iostream>

#include "BufferPool.h"

class BufferManager {
private:
    BufferPool bpool;
    int numFrames;

public:
    // Constructor
    BufferManager(int numFrames);

    // Métodos
    void loadPageFromDisk(string blockPath, int pageID, char _mode);
    void killProcess(int pageID);
    void savePageToDisk(int pageID);
    void updatePage(int pageID);
    void deletePage(int pageID);
};

#endif // BUFFERMANAGER_H

