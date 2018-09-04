# winni
Windows Network Interfaces - Node.JS low-level binding

## Requirement

- Windows build tools
- Node-gyp

Take a look at: https://www.npmjs.com/package/windows-build-tools

## Starter guide

To setup the project on your computer

```bash
$ npm install
$ node-gyp configure
$ node-gyp build
```

## TODO

- Prepare npm package (export with bindings).
- Add prebuilt (prebuildify)
- All missing fields (still have to convert SOCKET_ADDRESS)
- Add AsyncWorker for all methods and return Promise Object!
