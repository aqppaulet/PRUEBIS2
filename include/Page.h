#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <vector>

using namespace std;

class Page {
 private:
  int frameID;
  bool dirty_flag;
  int pinCount;
  int lastUsedTime;
  vector<string> content;

 public:
  Page();

  int pageCapacity;

  void activateDirty();
  void incrementPinCount();
  void decrementPinCount();

  int getPinCount() const;
  bool isDirty() const;
  int getLastUsedTime() const;
  void updateLastUsedTime(int currentTime);
  void setContent(string record);
  const vector<string>& getContent() const;

  void setPageCapacity(int capacity);
  void setFrameID(int id);
  void setDirtyFlag(bool dirty);
  void setPinCount(int count);
  void setLastUsedTime(int time);
};

#endif  // PAGE_H
