//
// Created by Anton on 2/4/2018.
//

#ifndef LAB4_VNS_H
#define LAB4_VNS_H

#include <vector>
#include "nameserverinterface.h"

using namespace std;


class VNS: NameServerInterface {
public:
    VNS();
    virtual void insert(const HostName&, const IPAddress&) override ;
    virtual bool remove(const HostName&) override ;
    virtual IPAddress lookup(const HostName&) const override ;


private:
    vector<pair<HostName , IPAddress >> hosts;



};






#endif //LAB4_VNS_H
