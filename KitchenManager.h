//
//  KitchenManager.h
//  Kitchen Order Management
//
//  Created by Jovhems Jean-Baptiste on 11/7/25.
//

#ifndef KITCHEN_MANAGER_H
#define KITCHEN_MANAGER_H

#include <queue>
#include <stack>
#include "Order.h"

class KitchenManager {
public:
    KitchenManager();

    // Menu actions
    void addNewOrder(const std::string& description, OrderType type);
    void startPreparingNextOrder();
    void markOrderAsComplete();
    void servePickupOrder();
    void viewPrepQueue() const;
    void viewCompletedStack() const;

private:
    // Data structures
    std::queue<Order> prepQueue;       // FIFO
    std::stack<Order> completedOrders; // LIFO
    std::unique_ptr<Order> currentOrder; // actively prepared order (nullptr if none)
    int nextOrderID;                   // auto-incrementing ID

    // Helpers
    void printHeader(const std::string& title) const;
};

#endif // KITCHEN_MANAGER_H
