//
// Created by Anton on 2/10/2018.
//

#ifndef LAB4_MNS_H
#define LAB4_MNS_H

#include <vector>
#include <map>
#include "nameserverinterface.h"

using namespace std;


class MNS: public NameServerInterface {
public:
    MNS();
    virtual void insert(const HostName& name, const IPAddress& address) override ;
    virtual bool remove(const HostName& name) override ;
    virtual IPAddress lookup(const HostName& name) const override ;


private:
        std::map<HostName , IPAddress > hosts;

};
#endif //LAB4_MNS_H
