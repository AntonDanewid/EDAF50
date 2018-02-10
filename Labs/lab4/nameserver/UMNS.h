//
// Created by Anton on 2/10/2018.
//

#ifndef LAB4_UMNS_H
#define LAB4_UMNS_H

#include "nameserverinterface.h"
#include <unordered_map>
using namespace std;


class UMNS: public NameServerInterface {
public:
    UMNS();
    virtual void insert(const HostName& name, const IPAddress& address) override ;
    virtual bool remove(const HostName& name) override ;
    virtual IPAddress lookup(const HostName& name) const override ;


private:
    std::unordered_map<HostName , IPAddress > hosts;

};

#endif //LAB4_UMNS_H

