//
// Created by Anton on 2/10/2018.
//

//
// Created by Anton on 2/10/2018.
//

#include "UMNS.h"
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
UMNS::UMNS() {

}




void UMNS::insert(const HostName &name, const IPAddress &address) {
    pair<HostName, IPAddress> p(name, address);
    hosts.insert(p);
}
bool UMNS::remove(const HostName& name) {

    auto it = hosts.find(name);
    if(it != hosts.end()) {
        hosts.erase(it);
        return true;
    }
    return false;
}

IPAddress UMNS::lookup(const HostName& name) const {

    auto it = hosts.find(name);
    if(it != hosts.end()) {
        return it->second;
    } else {
        return NON_EXISTING_ADDRESS;
    }

}

