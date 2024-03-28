#!/bin/bash

compiled="./a.out"

# for every deck
for ((i = 1; i <= 10; i++)); do
    deck="decks/deck$i"
    echo "Running $compiled with $deck as entry..."
    $compiled < $deck
    echo "--------------------------------------"
done
