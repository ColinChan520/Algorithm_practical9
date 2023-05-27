#include "DocumentManager.h"

void DocumentManager :: addDocument(string name, int id, int license_limit){
    Document insertion;
    insertion.name = name;
    insertion.license_limit = license_limit;
    insertion.borrowedNum = 0;
    documentDict.insert({id, insertion});
    nameIdDict.insert({name, id});
}

void DocumentManager :: addPatron(int patronID){
    patronInfo.insert(patronID);
}

int DocumentManager :: search(string name){
    unordered_map<string, int> :: const_iterator got = nameIdDict.find (name);
    if(got == nameIdDict.end()){
        return 0;
    }
    else{
        return got->second;
    }
}

bool DocumentManager :: borrowDocument(int docid, int patronID){
    if(patronInfo.count(patronID)){
        Document targetDoc = documentDict.at(docid);
        if(targetDoc.license_limit > targetDoc.borrowedNum){
            targetDoc.borrowedNum ++;
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void DocumentManager :: returnDocument(int docid, int patronID){
        if(patronInfo.count(patronID)){
        Document targetDoc;
        targetDoc = documentDict.at(docid);
        if(targetDoc.borrowedNum > 0){
            targetDoc.borrowedNum --;
            return;
        }
        else{
            return;
        }
            
        }
    else{
        return;
    }
}