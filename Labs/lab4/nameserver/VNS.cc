//
// Created by Anton on 2/4/2018.
//

#include "VNS.h"
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
VNS::VNS() {

}




void VNS::insert(const HostName &name, const IPAddress &address) {
    pair<HostName, IPAddress> p(name, address);
    hosts.push_back(p);
}
bool VNS::remove(const HostName& name) {

    auto it=find_if( hosts.begin(), hosts.end(),
                     [&]( const std::pair<HostName,IPAddress>& a) { return a.first == name; } );
    if(it!=hosts.end()){
        hosts.erase(it);
        return true;
    }
    return false;
}

IPAddress VNS::lookup(const HostName& name) const {

    auto it=find_if( hosts.begin(), hosts.end(),
                     [&]( const std::pair<HostName,IPAddress>& a) { return a.first == name; } );
    if(it!=hosts.end()){
        return it->second;
    }else{
        return NON_EXISTING_ADDRESS;
    }
}

