//
//  Order.h
//  Kitchen Order Management
//
//  Created by Jovhems Jean-Baptiste on 11/7/25.
//

#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>

// Enum for clarity in order types and statuses
enum class OrderType { DineIn, Takeout };
enum class OrderStatus { Pending, Preparing, Ready, Served };

struct Order {
    int orderId{};
    std::string description;
    OrderType type{OrderType::DineIn};
    OrderStatus status{OrderStatus::Pending};

    Order() = default;
    Order(int id, std::string desc, OrderType t, OrderStatus s = OrderStatus::Pending)
        : orderId(id), description(std::move(desc)), type(t), status(s) {}
};

// Small helpers to print enums nicely
std::string to_string(OrderType t);
std::string to_string(OrderStatus s);

// Pretty single-line view for lists
std::ostream& operator<<(std::ostream& os, const Order& o);

#endif // ORDER_H
