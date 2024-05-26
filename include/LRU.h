#ifndef LRU_H
#define LRU_H

class LRU {
 private:
  int miss;
  int hit;

 public:
  void push();
  void pop();
  void swap();
  void update();
};

#endif