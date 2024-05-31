#ifndef FRAME_H
#define FRAME_H

#include "Page.h"

class Frame {
   private:
    int frameID;
    bool dirty_flag;
    int pinCount;
    Page page;

   public:
    // Constructor
    Frame(int id, bool dirty, int pin, Page pg);

    // Getters
    int getFrameID() const;
    bool isDirty() const;
    int getPinCount() const;
    Page getPage() const;

    // Setters
    void setFrameID(int id);
    void setDirtyFlag(bool dirty);
    void setPinCount(int pin);
    void setPage(Page pg);
};

#endif  // FRAME_H
