# Winni
![version](https://img.shields.io/badge/dynamic/json.svg?url=https://raw.githubusercontent.com/SlimIO/Winni/master/package.json&query=$.version&label=Version)
![N-API](https://img.shields.io/badge/N--API-v3-green.svg)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://github.com/SlimIO/Config/commit-activity)
[![mit](https://img.shields.io/github/license/Naereen/StrapDown.js.svg)](https://github.com/SlimIO/Queue/blob/master/LICENSE)
![dep](https://img.shields.io/david/SlimIO/Winni.svg)
![size](https://img.shields.io/bundlephobia/min/@slimio/winni.svg)
[![Known Vulnerabilities](https://snyk.io/test/github/SlimIO/Winni/badge.svg?targetFile=package.json)](https://snyk.io/test/github/SlimIO/Winni?targetFile=package.json)
[![Build Status](https://travis-ci.com/SlimIO/Winni.svg?branch=master)](https://travis-ci.com/SlimIO/Winni)

SlimIO Windows Network Interfaces which expose low-level Microsoft APIs on Network Interfaces, Adapter Addresses and IF_ROW.

This binding expose the following methods/struct:
- [GetAdaptersAddresses](https://docs.microsoft.com/en-us/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)
- [IP_ADAPTER_ADDRESSES](https://docs.microsoft.com/en-us/windows/desktop/api/iptypes/ns-iptypes-_ip_adapter_addresses_lh)
- [GetIfEntry2](https://docs.microsoft.com/en-us/windows/desktop/api/netioapi/nf-netioapi-getifentry2)
- [GetIfTable2](https://docs.microsoft.com/en-us/windows/desktop/api/netioapi/nf-netioapi-getiftable2)
- [MIB_IFROW](https://docs.microsoft.com/en-us/previous-versions/windows/desktop/api/ifmib/ns-ifmib-_mib_ifrow)
- [GetNumberOfInterfaces](https://docs.microsoft.com/en-us/windows/desktop/api/iphlpapi/nf-iphlpapi-getnumberofinterfaces)

## Requirements
- [Node.js](https://nodejs.org/en/) v12 or higher

## Getting Started

This package is available in the Node Package Repository and can be easily installed with [npm](https://docs.npmjs.com/getting-started/what-is-npm) or [yarn](https://yarnpkg.com).

```bash
$ npm i @slimio/winni
# or
$ yarn add @slimio/winni
```

## Usage example
Retrieve Adapter Addresses and for each of them retrieve the ifRow with the ifIndex of the interface!

```js
const { getAdaptersAddresses, getIfEntry } = require("@slimio/winni");

async function main() {
    const networkInterfaces = await getAdaptersAddresses();
    for (const iNet of networkInterfaces) {
        console.log(`Interface name: ${iNet.name}`);
        const ifRow = await getIfEntry(iNet.ifIndex);
        console.log(JSON.stringify(ifRow, null, 4));
    }
}
main().catch(console.error);
```

## API

<details><summary>getAdaptersAddresses(): Promise< NetworkInterface[] ></summary>
<br />

Retrieves the addresses associated with the adapters on the local computer.

```ts
export interface NetworkInterface {
    name: string;
    ifIndex: number;
    ifType: number;
    length: number;
    physicalAddress: string;
    zoneIndices: number[];
    dnsSuffix: string;
    description: string;
    friendlyName: string;
    flags: number;
    mtu: number;
    operStatus: number;
    transmitLinkSpeed: number;
    receiveLinkSpeed: number;
    ipv4Enabled: boolean;
    ipv6Enabled: boolean;
    ipv6IfIndex: number;
    dnsEnabled: boolean;
    registerAdapterSuffix: number;
    receiveOnly: boolean;
    noMulticast: boolean;
    ipv6OtherStatefulConfig: boolean;
    netbiosOverTcpipEnabled: boolean;
    ipv6ManagedAddressConfigurationSupported: boolean;
    networkGuid: string;
    connectionType: number;
    tunnelType: number;
    dhcpv6ClientDuid: string;
    ipv4Metric: number;
    ipv6Metric: number;
    dnServer: string[];
    anycast: string[];
    unicast: string[];
    multicast: string[];
}
```
</details>

<details><summary>getIfEntry(IfIndex: number): Promise< IfEntry ></summary>
<br />

Retrieves information for the specified interface on the local computer.

```ts
export interface IfEntry {
    physicalAddress: string;
    interfaceLuid: number;
    interfaceIndex: number;
    interfaceGuid: string;
    alias: string;
    description: string;
    mtu: number;
    type: number;
    tunnelType: number;
    mediaType: number;
    accessType: number;
    physicalMediumType: number;
    directionType: number;
    operStatus: number;
    adminStatus: number;
    mediaConnectState: number;
    networkGuid: string;
    connectionType: number;
    transmitLinkSpeed: number;
    receiveLinkSpeed: number;
    inOctets: number;
    inUcastPkts: number;
    inNUcastPkts: number;
    inDiscards: number;
    inErrors: number;
    inUnknownProtos: number;
    inUcastOctets: number;
    inMulticastOctets: number;
    inBroadcastOctets: number;
    outOctets: number;
    outUcastPkts: number;
    outNUcastPkts: number;
    outDiscards: number;
    outErrors: number;
    outUcastOctets: number;
    outMulticastOctets: number;
    outBroadcastOctets: number;
    outQLen: number;
}
```
</details>

<details><summary>getIfTable(): Promise< IfEntry[] ></summary>
<br />

Retrieves the MIB-II interfaces table (which contain all ifRow of all interfaces).
</details>

<details><summary>getNumberOfInterfaces(): Promise< number ></summary>
<br />

Retrieves the number of interfaces on the local computer.
</details>

## Contribution Guidelines
To contribute to the project, please read the [code of conduct](https://github.com/SlimIO/Governance/blob/master/COC_POLICY.md) and the guide for [N-API compilation](https://github.com/SlimIO/Governance/blob/master/docs/native_addons.md).

## Dependencies

|Name|Refactoring|Security Risk|Usage|
|---|---|---|---|
|[node-addon-api](https://github.com/nodejs/node-addon-api)|⚠️Major|Low|Node.js C++ addon api|
|[node-gyp-build](https://github.com/prebuild/node-gyp-build)|⚠️Major|Low|Node-gyp builder|

## License
MIT
