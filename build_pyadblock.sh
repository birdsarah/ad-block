#/bin/sh
c++ -O3 -Wall -shared -std=c++11 \
     -fPIC `python3 -m pybind11 --includes` ad_block_client_py.cc -o pyadblock`python3-config --extension-suffix`   \
     build/Release/obj.target/ad-block/node_modules/hashset-cpp/hash_set.o \
     build/Release/obj.target/ad-block/node_modules/bloom-filter-cpp/BloomFilter.o \
     build/Release/obj.target/ad-block/node_modules/bloom-filter-cpp/hashFn.o \
     build/Release/obj.target/ad-block/ad_block_client.o  \
     build/Release/obj.target/ad-block/context_domain.o \
     build/Release/obj.target/ad-block/cosmetic_filter.o \
     build/Release/obj.target/ad-block/filter_list.o \
     build/Release/obj.target/ad-block/filter.o \
     build/Release/obj.target/ad-block/no_fingerprint_domain.o \
     build/Release/obj.target/ad-block/protocol.o
