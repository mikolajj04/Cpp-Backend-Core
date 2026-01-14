/**
 * @file SnakeList.h
 * @brief Header file containing the Doubly Linked List implementation for the Snake game.
 */
#pragma once
#include <memory>
#include <iostream>
#include <conio.h>
#include <Windows.h>

 /**
  * @struct Node
  * @brief Represents a single segment of the snake's body.
  */
struct Node {
    int x, y;                        ///< Coordinates of the segment.
    std::unique_ptr<Node> next;      ///< Smart pointer to the next segment (forward ownership).
    Node* prev;                      ///< Raw pointer to the previous segment (bidirectional link).

    Node(int _x, int _y);
};

/**
 * @class SnakeList
 * @brief Doubly linked list for managing snake segments.
 * Implements the Rule of Five and custom sorting/searching.
 */
class SnakeList {
    std::unique_ptr<Node> head;      ///< Head of the snake (front of the list).
    Node* tail;                      ///< Tail of the snake (end of the list).

public:
    SnakeList();

    /**
     * @brief Adds a new segment to the front of the snake.
     * @param x X coordinate.
     * @param y Y coordinate.
     */
    void push_front(int x, int y);

    /** @brief Removes the last segment (tail) of the snake. */
    void pop_back();

    /**
     * @brief Checks if a snake segment exists at given coordinates.
     * @return true if collision detected.
     */
    bool isSnakeAt(int x, int y) const;

    // Rule of Five implementations
    SnakeList(const SnakeList& other);
    SnakeList(SnakeList&& other) noexcept;
    SnakeList& operator=(const SnakeList& other);
    SnakeList& operator=(SnakeList&& other) noexcept;

    /** @brief Sorts segments by X coordinate using Bubble Sort. */
    void sortContent();
};



