#ifndef NETWORKADAPTERS_H
#define NETWORKADAPTERS_H

#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#pragma comment(lib, "IPHLPAPI.lib")

#define WORKING_BUFFER_SIZE 15000
#define MAX_TRIES 3

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

struct NetworkInterface {
    double IfIndex;
    double IfType;
    const char* Name;
    double Length;
    char* DnsSuffix;
    char* Description;
    char* FriendlyName;
    char* PhysicalAddress;
    double Flags;
    double Mtu;
    double OperStatus;
    double TransmitLinkSpeed;
    double ReceiveLinkSpeed;
    double Ipv4Enabled;
    double Ipv6Enabled;
    double Ipv6IfIndex;
    double DdnsEnabled;
    double RegisterAdapterSuffix;
    double ReceiveOnly;
    double NoMulticast;
    double Ipv6OtherStatefulConfig;
    double NetbiosOverTcpipEnabled;
    double Ipv6ManagedAddressConfigurationSupported;
};

struct IfEntry {
    double dwOutOctets;
    double dwInOctets;
    double dwInDiscards;
    double dwInErrors;
    double dwOutDiscards;
    double dwOutErrors;
    double dwSpeed;
    double dwLastChange;
    double dwInNUcastPkts;
    double dwInUcastPkts;
    double dwOutNUcastPkts;
    double dwOutUcastPkts;
    double dwOutQLen;
    double dwInUnknownProtos;
};

class NetworkAdapters {
    public:
        NetworkAdapters();
        std::vector<NetworkInterface> GetInterfaces();
        IfEntry GetIf(IF_INDEX Index);

    private:
        PIP_ADAPTER_ADDRESSES pAddresses;
        DWORD dwRetVal;
        char* toChar(PWCHAR field);
        bool Initialize();
};

#endif // NETWORKADAPTERS_H
