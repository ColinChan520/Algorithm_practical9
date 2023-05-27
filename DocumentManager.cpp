#include "DocumentManager.h"

void DocumentManager ::addDocument(string name, int id, int license_limit) {
  Document insertion;
  insertion.name = name;
  insertion.license_limit = license_limit;
  insertion.borrowedNum = 0;
  documentDict.insert({id, insertion});
  nameIdDict.insert({name, id});
}

void DocumentManager ::addPatron(int patronID) { patronInfo.insert(patronID); }

int DocumentManager ::search(string name) {
  unordered_map<string, int>::const_iterator got = nameIdDict.find(name);
  if (got == nameIdDict.end()) {
    return 0;
  } else {
    return got->second;
  }
}

bool DocumentManager ::borrowDocument(int docid, int patronID) {
  if (patronInfo.count(patronID)) {
    Document targetDoc = documentDict.at(docid);
    if (targetDoc.license_limit > targetDoc.borrowedNum) {
      unordered_map<int, vector<int>>::const_iterator got =
          borrowDict.find(patronID);
      if (got == borrowDict.end()) {
        vector<int> tmp;
        tmp.push_back(docid);
        borrowDict.insert({patronID, tmp});
      } else {
        vector<int> borrowList = got->second;
        borrowList.push_back(docid);
      }
      targetDoc.borrowedNum++;
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

void DocumentManager ::returnDocument(int docid, int patronID) {
  if (patronInfo.count(patronID)) {
    vector<int> borrowList = borrowDict.at(patronID);
    if (borrowList.begin(), borrowList.end(), docid) {
      Document targetDoc = documentDict.at(docid);
      if (targetDoc.borrowedNum > 0) {
        targetDoc.borrowedNum--;
        return;
      } else {
        return;
      }
    } else {
      return;
    }

  } else {
    return;
  }
}