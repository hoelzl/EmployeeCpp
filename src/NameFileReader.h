//
// Created by tc on 2019-06-05.
//

#ifndef EMPLOYEE_NAMEFILEREADER_H
#define EMPLOYEE_NAMEFILEREADER_H

#include "NameReader.h"

class NameFileReader : public NameReader
{
public:
    explicit NameFileReader(const char* data_file_name);

    NameData readName(int id) const override;

private:
    const char* data_file_name_;
};

#endif // EMPLOYEE_NAMEFILEREADER_H
