//
//  order.cpp
//  Kitchen Order Management
//
//  Created by Jovhems Jean-Baptiste on 11/7/25.
//

#include "Order.h"

std::string to_string(OrderType t) {
    switch (t) {
        case OrderType::DineIn:  return "Dine-In";
        case OrderType::Takeout: return "Takeout";
    }
    return "Unknown";
}

std::string to_string(OrderStatus s) {
    switch (s) {
        case OrderStatus::Pending:   return "Pending";
        case OrderStatus::Preparing: return "Preparing";
        case OrderStatus::Ready:     return "Ready";
        case OrderStatus::Served:    return "Served";
    }
    return "Unknown";
}

std::ostream& operator<<(std::ostream& os, const Order& o) {
    os << "[#" << o.orderId << "] "
       << to_string(o.type) << " | "
       << to_string(o.status) << " | "
       << o.description;
    return os;
}
