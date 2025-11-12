//
//  kitchenmanager.cpp
//  Kitchen Order Management
//
//  Created by Jovhems Jean-Baptiste on 11/7/25.
//

#include "KitchenManager.h"
#include <iostream>
#include <iomanip>

KitchenManager::KitchenManager() : nextOrderID(1), currentOrder(nullptr) {}

void KitchenManager::printHeader(const std::string& title) const {
    std::cout << "\n==== " << title << " ====\n";
}

void KitchenManager::addNewOrder(const std::string& description, OrderType type) {
    Order o(nextOrderID++, description, type, OrderStatus::Pending);
    prepQueue.push(o);
    std::cout << "Added " << o << "\n";
}

void KitchenManager::startPreparingNextOrder() {
    if (currentOrder) {
        std::cout << "Already preparing order #" << currentOrder->orderId
                  << " (" << to_string(currentOrder->status) << ").\n";
        return;
    }
    if (prepQueue.empty()) {
        std::cout << "No orders in the prep queue.\n";
        return;
    }
    Order next = prepQueue.front();
    prepQueue.pop();
    next.status = OrderStatus::Preparing;
    currentOrder = std::make_unique<Order>(next);
    std::cout << "Started preparing " << *currentOrder << "\n";
}

void KitchenManager::markOrderAsComplete() {
    if (!currentOrder) {
        std::cout << "No order is currently being prepared.\n";
        return;
    }
    currentOrder->status = OrderStatus::Ready;
    completedOrders.push(*currentOrder); // push a copy to the stack
    std::cout << "Marked READY and moved to completed stack: " << *currentOrder << "\n";
    currentOrder.reset(); // no active order now
}

void KitchenManager::servePickupOrder() {
    if (completedOrders.empty()) {
        std::cout << "No completed orders to serve.\n";
        return;
    }
    Order top = completedOrders.top();
    completedOrders.pop();
    // Mark as served for display
    top.status = OrderStatus::Served;

    std::cout << "Served/Picked Up: " << top << "\n";
}

void KitchenManager::viewPrepQueue() const {
    printHeader("Prep Queue (FIFO)");
    if (prepQueue.empty()) {
        std::cout << "(empty)\n";
    } else {
        // Copy to traverse non-destructively
        std::queue<Order> copy = prepQueue;
        int pos = 1;
        while (!copy.empty()) {
            const Order& o = copy.front();
            std::cout << pos << ". " << o << "\n";
            copy.pop();
            ++pos;
        }
    }

    if (currentOrder) {
        std::cout << "\nCurrently Preparing: " << *currentOrder << "\n";
    } else {
        std::cout << "\nCurrently Preparing: (none)\n";
    }
}

void KitchenManager::viewCompletedStack() const {
    printHeader("Completed Orders Stack (LIFO)");
    if (completedOrders.empty()) {
        std::cout << "(empty)\n";
        return;
    }
    std::stack<Order> copy = completedOrders;
    std::cout << "Top ->\n";
    int idx = 1;
    while (!copy.empty()) {
        const Order& o = copy.top();
        std::cout << idx << ". " << o << "\n";
        copy.pop();
        ++idx;
    }
}
