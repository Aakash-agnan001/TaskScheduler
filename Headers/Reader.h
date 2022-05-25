#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <jsoncpp/json/value.h.
#include <jsoncpp/json/json.h>


void reader() {
    ifstream file("../data.json");
    Json::Value = actualJson;
    Json::Reader = reader;

    reader.parse(reader, actualJson);
    cout << actualJson;
}

#endif