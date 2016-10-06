# CurveSim
Reservation Table Simulator for Non-linear pipeline

## Author
* **Suvojit Manna** - [Github ID](https://github.com/shin-migami)

## Getting Started
Is compiled and tested on  
* g++ (Raspbian 4.9.2-10) 4.9.2
* g++ (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609
* Microsoft (R) C/C++ Optimizing Compiler Version 18.00.21005.1 for x86
  Copyright (C) Microsoft Corporation.  All rights reserved.

## Installing
To compile go to directory 
```
make
```

## Using the Simulator
```
./curvesim <no-of-stages> <no-of-timeslot>
```
OR
```
./curvesim
```

Insert Stages of Pipeline in Binary format(0 for no checks, 1 for checks)  
Use Menu options to use features.  
```
Enter Options : 
1 - Print Reservation Table
2 - Print all Permissible Latency
3 - Print all Forbidden Latency
4 - Print Initial Collision Vector
5 - Print State Initiation Diagram
6 - Print all Simple Cycles
7 - Print all Greedy Cycles
8 - Print Minimum Average Latency
9 - Print Pipeline Throughput
0 - Exit
```

## Contributors
<table>
  <tr>
    <td align=center><img width=100 src=https://avatars2.githubusercontent.com/u/10397574?v=3><br>Suvojit Manna(<a href=https://github.com/shin-migami>@shin-migami</a>)</td>
    <td align=center><img width=100 src=https://avatars1.githubusercontent.com/u/4593736?v=3><br>Yunchih Chen (<a href=https://github.com/yunchih>@yunchih</a>)</td>
    <td align=center><img width=100 src=https://avatars0.githubusercontent.com/u/7666511?v=3><br>Andrey Starodubtsev (<a href=https://github.com/andrey-starodubtsev>@andrey-starodubtsev</a>)</td>
    <td align=center><img width=100 src=https://avatars2.githubusercontent.com/u/8580742?v=><br>T K Sourabh (<a href=https://github.com/sourabhtk37>@sourabhtk37</a>)</td>
  </tr>
</table>
