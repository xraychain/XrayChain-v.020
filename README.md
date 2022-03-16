What is Xray?
-------------

Xray is a decentralized blockchain project built on the UTXO blockchain architecture, with support for Ethereum Virtual Machine based smart contracts, and secured by a proof of stake consensus model. It achieves this through the revolutionary Account Abstraction Layer which allows the EVM to communicate with Xray's Bitcoin-like UTXO blockchain. 

Introducing the Xray Network. Here are the main features:

1. Compatibility with the Ethereum Virtual Machine, which allows for compatibility with most existing Solidity based smart contracts. No special solidity compiler is required to deploy your smart contract to Xray. 
2. A Proof of Stake consensus system which is optimized for Xray's contract model. Any user can stake and help to secure the network. There is no voting, master nodes, or minimum amount required to stake - only one xray is enough to start.  
3. Uses the UTXO transaction model and is compatible with Bitcoin, allowing for existing tooling and workflows to be used with Xray. This allows for the infamous SPV protocol to be used which is ideal for light wallets on mobile phones and IoT devices.
4. Delegated staking in even smart phones enabled on later life of the chain.



What is RayChain?
------------------

RayChain is our primary mainnet wallet. It implements a full node and is capable of storing, validating, and distributing all history of the Xray network. RayChain is the reference implementation for the Xray network. 

RayChain currently implements the following:

* Sending/Receiving XRAY coins
* Sending/Receiving XRC20 tokens on the Xray network
* Staking and creating blocks for the Xray network
* Creating and interacting with smart contracts (on authorized clients)
* Running a full node for distributing the blockchain to other users
* "Prune" mode, which minimizes disk usage
* Regtest mode, which enables developers to very quickly build their own private Xray network for Dapp testing (on authorized clients)
* Testnet mode, using the public Xray Testnet, with faucet available (on authorized clients)
* Compatibility with the Bitcoin Core set of RPC commands and APIs
* Full SegWit capability with p2sh-segwit (legacy) and bech32 (native) addresses

### Xray Smart Contract Limitations

*	EVM smart contracts cannot receive coins from or send coins to any address type other than pay-to-pubkeyhash (starts with X) addresses. This is due to a limitation in the EVM
*	Contracts are not allowed to create contracts with an initial endowment of coins. The contract must first be created, and then be sent coins in a separate transaction. Humans are also not allowed to create contracts with an initial endowment of coins.
*	Although all of the infrastructure is present, RayChain does not currently parse Solidity event data. You must parse this yourself using either searchlogs or -record-log-opcodes features.
*	It is not possible to send a contract coins without also executing the contract. This is also the case of Ethereum. This was promised in earlier discussions and technically does work, but due to lack of time for testing this feature was disabled. We hope to reenable this feature with release of the x86 virtual machine in 2020.
*	In Xray there can be multiple addresses used to create a proof-of-stake block. However, the EVM can only see the first output using the coinbase operation in Solidity (this address is also the one registered for the continuous staker rewards after 500 blocks).

----------

# Building RayChain

### Build on Ubuntu

This is a quick start script for compiling Xray on Ubuntu


    sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils git cmake libboost-all-dev libgmp3-dev
    sudo apt-get install software-properties-common
    sudo add-apt-repository ppa:bitcoin/bitcoin
    sudo apt-get update
    sudo apt-get install libdb4.8-dev libdb4.8++-dev

    # If you want to build the Qt GUI:
    sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler qrencode

    git clone https://github.com/raychainTR/xray --recursive
    cd xray

    # Note autogen will prompt to install some more dependencies if needed
    ./autogen.sh
    ./configure 
    make -j2
    
### Build on CentOS

Here is a brief description for compiling Xray on CentOS, for more details please refer to [the specific document](https://github.com/raychainTR/xray/blob/master/doc/build-unix.md)

    # Compiling boost manually
    sudo yum install python-devel bzip2-devel
    git clone https://github.com/boostorg/boost.git
    cd boost
    git checkout boost-1.66.0
    git submodule update --init --recursive
    ./bootstrap.sh --prefix=/usr --libdir=/usr/lib64
    ./b2 headers
    sudo ./b2 -j4 install
    
    # Installing Dependencies for Xray
    sudo yum install epel-release
    sudo yum install libtool libdb4-cxx-devel openssl-devel libevent-devel gmp-devel
    
    # If you want to build the Qt GUI:
    sudo yum install qt5-qttools-devel protobuf-devel qrencode-devel
    
    # Building Xray
    git clone --recursive https://github.com/raychainTR/xray.git
    cd xray
    ./autogen.sh
    ./configure
    make -j4

### Build on Mac OS

The commands in this guide should be executed in a Terminal application.
The built-in one is located in `/Applications/Utilities/Terminal.app`.

#### Preparation

Install the Mac OS command line tools:

`xcode-select --install`

When the popup appears, click `Install`.

Then install [Homebrew](https://brew.sh).

#### Dependencies

    brew install cmake automake berkeley-db4 libtool boost miniupnpc openssl pkg-config protobuf qt5 libevent imagemagick librsvg qrencode gmp

NOTE: Building with Qt4 is still supported, however, could result in a broken UI. Building with Qt5 is recommended.

#### Build RayChain

1. Clone the xray source code and cd into `xray`

        git clone --recursive https://github.com/raychainTR/xray.git
        cd xray

2.  Build xray-core:

    Configure and build the headless xray binaries as well as the GUI (if Qt is found).

    You can disable the GUI build by passing `--without-gui` to configure.

        ./autogen.sh
        ./configure
        make

3.  It is recommended to build and run the unit tests:

        make check

### Run

Then you can either run the command-line daemon using `src/xrayd` and `src/xray-cli`, or you can run the Qt GUI using `src/qt/xray-qt`

License
-------

Xray is GPLv3 licensed.
