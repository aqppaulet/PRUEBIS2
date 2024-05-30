#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H


#include <iostream>

#include "BufferPool.h"
#include "Page.h"

class BufferManager {
private:
    BufferPool bpool;
    int numFrames;

public:
    // Constructor
    BufferManager(int numFrames);

    // Métodos
    void loadPageFromDisk(int pageID);
    void savePageToDisk(int pageID);
    void updatePage(int pageID, const Page& newPageData);
    void deletePage(int pageID);
};

#endif // BUFFERMANAGER_H

