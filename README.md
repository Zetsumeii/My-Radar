# My-Radar

By Théophile Combes.

This project aims to render a 2D visualization panel showing a simulatation of air traffic.
We have 2 entities, plane and tower. A plane has a start position, a destination, a velocity, and a spawn timer. A tower has a radius.
If two planes collide, they are destroyed. But if they collide inside the radius of the tower they are free to go.

# USAGE

./my_radar [FILENAME]

# FILENAME format:

A  [x-start] [y-start]  [x-end] [y-end]  [velocity]  [spawn]
6  [radius]

Watch entry.rdr
