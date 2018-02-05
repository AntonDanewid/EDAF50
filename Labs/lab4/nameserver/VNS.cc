//
// Created by Anton on 2/4/2018.
//

#include "VNS.h"

using namespace std;
VNS::VNS() {

}




void VNS::insert(const HostName &, const IPAddress &) {
    pair<HostName, IPAddress> p(HostName, IPAddress);
    //hosts.push_back(p);
}
bool VNS::remove(const HostName&) {
    return false;
}

IPAddress VNS::lookup(const HostName&) const {
    return NULL;
}

