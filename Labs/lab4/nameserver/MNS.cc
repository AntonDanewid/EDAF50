//
// Created by Anton on 2/10/2018.
//

#include "MNS.h"
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
MNS::MNS() {

}




void MNS::insert(const HostName &name, const IPAddress &address) {
    pair<HostName, IPAddress> p(name, address);
    hosts.insert(p);
}
bool MNS::remove(const HostName& name) {

    auto it = hosts.find(name);
    if(it != hosts.end()) {
        hosts.erase(it);
        return true;
    }
    return false;
}

IPAddress MNS::lookup(const HostName& name) const {

    auto it = hosts.find(name);
    if(it != hosts.end()) {
        return it->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }

}

