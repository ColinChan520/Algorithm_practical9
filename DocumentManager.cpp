#include "DocumentManager.h"

void DocumentManager :: addDocument(string name, int id, int license_limit){
    Document insertion;
    insertion.name = name;
    insertion.license_limit = license_limit;
    documentDict.insert({id, insertion});
    nameIdDict.insert({name, id});
}

void DocumentManager :: addPatron(int patronID){
    patronInfo.push_back(patronID);
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
    if(find(patronInfo.begin(), patronInfo.end(), patronID) != patronInfo.end()){
        Document targetDoc;
        targetDoc = documentDict.at(docid);
        if(targetDoc.license_limit > 0){
            targetDoc.license_limit --;
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
        if(find(patronInfo.begin(), patronInfo.end(), patronID) != patronInfo.end()){
        Document targetDoc;
        targetDoc = documentDict.at(docid);
            targetDoc.license_limit ++;
            return;
        }
    else{
        return;
    }
}