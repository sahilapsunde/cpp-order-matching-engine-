# Low-Latency Order Matching Engine (C++)
High-performance order matching engine in C++ targeting sub-millisecond latency,
inspired by HFT system design.
## Features- Price-Time Priority matching (FIFO within price level)- Lock-free data structures for concurrent order book access- Multithreaded order processing- Priority queues + hash maps for O(log n) order management- Support for Market, Limit, and Cancel orders
## Tech Stack
C++17 · STL · Multithreading · Lock-Free Data Structures · Priority Queue · Hash Map
## Build & Run
```bash
git clone https://github.com/sahilapsunde/cpp-order-matching-engine.git
cd cpp-order-matching-engine
mkdir build && cd build
cmake ..
make
./order_matching_engine
