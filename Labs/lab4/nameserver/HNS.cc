#include "HNS.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


HNS::HNS(int size) {
    hosts.resize(size);
}




void HNS::insert(const HostName &name, const IPAddress &address) {


    if (size+1 > hosts.size() / 2) {
        std::vector<std::vector<std::pair<HostName, IPAddress>>> newHosts;
        newHosts.resize(2 * hosts.size());
        for (auto vector : hosts) {
            for (auto pair : vector) {
                newHosts[hash_code(pair.first) % newHosts.size()].push_back(pair);
            }
        }
        hosts = newHosts;
    }
    std::pair <HostName, IPAddress> p(name, address);
    int index = hash_code(name) % hosts.size();
    hosts[index].push_back(p);


}

    bool HNS::remove(const HostName& name) {


        int index = hash_code(name) % hosts.size();
        auto& vector = hosts[index];
        auto begin = vector.begin();
        auto end = vector.end();

        auto it = std::find_if(begin, end, [name](std::pair<HostName, IPAddress> p) {
            return p.first == name; });

        if (it != end) {

            vector.erase(it);
            size--;
            return true;
        } else {
            return false;
        }


}

IPAddress HNS::lookup(const HostName& name) const {

    int index = hash_code(name) % hosts.size();
    auto vector = hosts[index];
    auto begin = vector.begin();
    auto end = vector.end();
    auto it = std::find_if(begin, end, [name](std::pair<HostName, IPAddress> p) {
        return p.first == name; });

    if (it != end) {
        cout << name;
        return vector[std::distance(begin, it)].second;
    } else {
        return NON_EXISTING_ADDRESS;
    }

}//
// Created by Anton on 2/10/2018.
//

