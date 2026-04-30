# Smart Travel Planner Using Dijkstra’s Algorithm (C)

##  Project Overview
This project is a Smart Travel Planner implemented in C that finds the shortest path between two locations using Dijkstra’s Algorithm. It helps users determine the most efficient route and minimum distance between cities.



##  Problem Statement
Finding the shortest path between multiple locations manually is difficult and time-consuming. When there are many routes, it becomes confusing to choose the best one. This project solves the problem using an efficient algorithm.



##  Solution
The system represents locations as nodes and distances as weighted edges using an adjacency matrix. It applies Dijkstra’s Algorithm to compute the shortest path between a selected source and destination.



##  Algorithm Used
**Dijkstra’s Algorithm (Greedy Algorithm)**  
- Selects the nearest unvisited node at each step  
- Updates distances efficiently  
- Finds shortest path in a weighted graph  


##  Features
- Displays available locations with index  
- Accepts user input (source and destination)  
- Calculates shortest path  
- Displays path clearly (using arrows)  
- Shows minimum distance  
- Handles invalid inputs  



##  Technologies Used
- C Programming  
- Graph (Adjacency Matrix)  
- Arrays and Functions  



##  How to Run the Project

### Step 1: Compile the code
```bash
gcc travel_planner.c -o travel
