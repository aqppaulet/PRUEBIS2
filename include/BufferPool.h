#pragma once

/* Sebastian Mendoza */

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class BufferPool {
   private:
    int numFrames;
    int capacity;
    vector<Frame> frames;
    unordered_map<int, int> page_table;

   public:
    BufferPool();                                  /* Constructor donde ira creando los frames vacios */
    vector<Frame>& getFrames();                    /* Sera para obtener el vector que contiene los frames */
    void setPage(Frame& frame, int frameID);       /* Cargar una pagina en un frame usando un frameID que nosostros le daremos */
    void printPage(int frameID);                   /* Mostrar el contenido de la pagina, pero hay que comprobar que este el frameid */
    void addRecord(int frameID, string record);    /* Usando la ubicacion del frame la agregamos un registro */
    void deleteRecord(int frameID, string record); /* Lo anterio pero para eliminar */
    bool pageIsDirty(int pageID);                  /* le decimos al frame que sea diry o comprobar para cambiar a void*/
    void freeFrame(int frameID);                   /* Liberar un frame */
    void printTableFrame();                        /*Imprimimos todos los frames*/
    void LRU();                                    /* El LRU */
};