#include "../include/Page.h"

#include <iostream>

Page::Page()
    : pageCapacity(120),
      frameID(-1),
      dirty_flag(false),
      pinCount(0),
      lastUsedTime(0),
      content() {}

void Page::activateDirty() { dirty_flag = true; }

void Page::incrementPinCount() { ++pinCount; }

void Page::decrementPinCount() {
  if (pinCount > 0) {
    --pinCount;
  }
}

int Page::getPinCount() const { return pinCount; }

bool Page::isDirty() const { return dirty_flag; }

int Page::getLastUsedTime() const { return lastUsedTime; }

void Page::updateLastUsedTime(int currentTime) { lastUsedTime = currentTime; }

const vector<string>& Page::getContent() const { return content; }

void Page::setContent(string record) {
  if (this->pageCapacity < record.length()) {
    cout << "= ===================================" << endl;
    cout << "Error: La capcidad excedio su limite" << endl;
    cout << "= ===================================" << endl;
    return;
  }
  content.push_back(record);
  this->pageCapacity -= record.length();
}

void Page::setPageCapacity(int capacity) { pageCapacity = capacity; }

void Page::setFrameID(int id) { frameID = id; }

void Page::setDirtyFlag(bool dirty) { dirty_flag = dirty; }

void Page::setPinCount(int count) { pinCount = count; }

void Page::setLastUsedTime(int time) { lastUsedTime = time; }
