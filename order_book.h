#pragma once
#include <map>
#include <queue>
#include <unordered_map>
#include <mutex>
#include <string>
#include <functional>
#include <iostream>
enum class OrderSide { BUY, SELL };
enum class OrderType { MARKET, LIMIT, CANCEL };
struct Order {
    long long id;
    OrderSide side;
    OrderType type;
    double price;
    int quantity;
    long long timestamp;
    bool operator>(const Order& other) const {
        if (price == other.price) return timestamp > other.timestamp;
        return price > other.price;
    }
};
struct Trade {
    long long buy_order_id;
    long long sell_order_id;
    double price;
};
    int quantity;
class OrderBook {
public:
    OrderBook();
    void addOrder(Order order);
    void cancelOrder(long long order_id);
    std::vector<Trade> match();
    void printBook() const;
private:
    // Buy orders: highest price first (max-heap)
    std::priority_queue<Order, std::vector<Order>,
        std::function<bool(const Order&, const Order&)>> buy_orders_;
    // Sell orders: lowest price first (min-heap)
    std::priority_queue<Order, std::vector<Order>,
        std::function<bool(const Order&, const Order&)>> sell_orders_;
    std::unordered_map<long long, Order> active_orders_;
    mutable std::mutex mtx_;
};
