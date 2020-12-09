# Lem-in

  There is an ant farm which has enter and exit. There are several ants at the start position which have to be transferred to the exit. Also there are intermidiate rooms between start and end positions. The distance between rooms are the same. The challenge is to find a system of paths through the rooms to move all the ants efficiently considering following restrictions:
  

- Each room can only be occupied by one ant except the start and end rooms.
- Ants have to avoid traffic jams as well as walking all over their fellow ants.
- At each turn each ant can be moved only once and the room at the receiving end must be empty.
- The algorithm must be quick and effective even in case of 4000+ rooms the search must be less than 3 seconds.

# Algorithm

  In order to fulfill the conditions above the system of found paths have to be disjoint.The modified version of BFS (breadth for search) has been used to find system of that paths.
  Each time when new path is being searched the previous rooms of found paths duplicates (splits in two). The splitted rooms interact by special rules. The modification helps to detect joint paths and then remove links between rooms to make them disjoint.
  Hashmap data structure has been created for convenient way to keep data and track every ant.
  
 # Input data
 
  The data goes from the standard output in the following format:
  
  - first line is the number of ants
  - the start room or end room marks as ##start and ##end accordingly
  - there are also could be comments at any place which start with '#'
  - name of room with coordinates
  - links between rooms
  
  ```
  20
  ##start
  startRoom 0 0
  #Intermidiate rooms
  1 0 1
  2 0 2
  3 0 3
  ##end
  endRoom 1 1
  #Links between rooms
  startRoom-1
  1-2
  1-3
  3-endRoom
  ```
 
# Usage

```
make
./lem-in < maps/[name_of_map]
```

# Run with visualisation

```
make
make vis - show features of the visualizer
./lem-in -v output < maps/[name_of_map] > output
```

<p align="left"><img src="giphy.gif"></p>
  
