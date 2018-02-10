//
// Created by Anton on 2/10/2018.
//

#ifndef LAB4_HMS_H
#define LAB4_HMS_H



#include "nameserverinterface.h"
#include <vector>
using namespace std;


class HNS: public NameServerInterface {
public:
    HNS(int);
    virtual void insert(const HostName& name, const IPAddress& address) override ;
    virtual bool remove(const HostName& name) override ;
    virtual IPAddress lookup(const HostName& name) const override ;


private:
    std::vector<std::vector<std::pair<HostName, IPAddress>>> hosts;
    std::hash<HostName> hash_code;
    unsigned int size;

};


#endif //LAB4_HMS_H
