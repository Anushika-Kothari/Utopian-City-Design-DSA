# 🌆 Utopian City Design Project

## 📜 Problem Statement

The City of Utopia aims to be a model of future urban development, where every aspect of city life is optimized for sustainability, efficiency, and the well-being of its citizens. The challenge was to create a city model that:

- Ensures **sustainable growth** by carefully planning infrastructure and public services.
- Balances the **economic, social, and environmental needs** of the city.
- Is **resilient** to future challenges, including climate change, economic disruptions, and social upheavals.
- Involves **stakeholders and experts** in its development to ensure it meets the needs of all citizens.

## 🛠️ Tools & Technologies

- **Programming Language**: C
- **Data Structures and Algorithms (DSA)**: Linked Lists, Sorting Algorithms, BFS, DFS, Prim’s Algorithm, etc.

## 🎯 Objective

**Optimize city infrastructure for efficiency and convenience.** The focus areas include:

- 🚑 **Ambulance routes**: Ensuring that emergency services can reach every part of the city quickly and efficiently.
- 🏘️ **Residential area placement**: Strategic location of residential zones to minimize travel time to work, schools, and amenities.
- 🏫 **Education system**: Designing the placement of schools to ensure they are accessible to all children.
- ♻️ **Waste management system**: Developing an efficient waste pickup and management strategy.
- 📺 **Utility placement**: Optimal placement of pipelines, cable connections, and other utilities.

## 📈 Functions Overview

| 📋 **Function Name** | 📝 **Description** | 🔧 **DS and Algorithm Used** | ⚙️ **Efficiency** |
|----------------------|--------------------|-----------------------------|-------------------|
| **print_citizen()** | Prints details of all the citizens. | Linked List | O(n) |
| **get_income()** | Prints top 10 citizens with the highest income. | Bubble Sort | O(n) |
| **add_citizen()** | Inserts a new citizen record. | Linked List Insertion | O(n) |
| **remove_citizen()** | Deletes an existing citizen record. | Linked List Deletion | O(n) |
| **get_population()** | Prints the total number of people residing in each house in increasing order. | Insertion Sort | O(n²) |
| **get_patients()** | Sorts the patients based on the level of emergency. | Quick Sort | O(n log n) |
| **get_family_tree()** | Prints the family tree from eldest to youngest. | Heap Sort | O(n log n) |
| **get_customer()** | Prints the first 5 customers who have checked in. | Merge Sort | O(n log n) |
| **bfs()** | Finds the optimal distance between nodes to reduce traffic congestion. | BFS | O(v + e) |
| **cable_connection()** | Prints TV cable connectivity around the city. | DFS | O(v) |
| **get_details()** | Prints details of the mentioned citizen. | Brute Force String Search | O(nm) |
| **true_caller()** | Fetches the details of the citizen the number belongs to. | KMP String Matching | O(n + m) |
| **waste_pickup()** | Gives the shortest path to travel through the city for waste collection. | Prim’s Algorithm | O(E log V) |

## 🏗️ Key Features

- **Transportation System**: Implementing algorithms like BFS and DFS to optimize routes for ambulances and cable connections, ensuring every citizen can access these services quickly.
- **Waste Management**: Using Prim's Algorithm to design the most efficient waste collection paths, minimizing both time and cost.
- **Citizen Management**: Efficient data handling for adding, removing, and printing citizen records using linked lists.
- **Emergency Services**: Prioritizing patients based on the level of emergency using Quick Sort to ensure the fastest response time.

## 🌍 Conclusion

This project illustrates the potential of **Data Structures and Algorithms** in designing a utopian city. By focusing on optimization and efficiency, we can build a city that not only meets the needs of its citizens today but is also resilient and adaptable to future challenges.
