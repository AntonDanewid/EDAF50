//
// Created by Anton on 2/4/2018.
//

#ifndef LAB4_VNS_H
#define LAB4_VNS_H

#include <vector>
#include "nameserverinterface.h"

using namespace std;


class VNS: public NameServerInterface {
public:
    VNS();
    virtual void insert(const HostName& name, const IPAddress& address) override ;
    virtual bool remove(const HostName& name) override ;
    virtual IPAddress lookup(const HostName& name) const override ;


private:
    vector<pair<HostName , IPAddress >> hosts;

};






#endif //LAB4_VNS_H
