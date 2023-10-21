<img src="https://i.imgur.com/HG66CCx.png?raw=true" alt="CODAM" style="max-width: 50%;">

# Philosophers

This project is a simulation of the classic dining philosophers problem. In this problem, a number of philosophers are seated at a dining table. Each philosopher thinks and eats, but there are a limited number of forks placed between them.  
A philosopher must acquire both forks on their sides to eat. The object is to prevent any of the philosophers to starver before they aquire two forks to eat.  

Our particular brand of philosophers are very

The challenge is to implement a solution that avoids [deadlocks](https://www.geeksforgeeks.org/introduction-of-deadlock-in-operating-system/) and ensures proper synchronization in access to the forks.
This project provides a multithreaded solution to the dining philosophers problem by levaraging mutex locks.

### Key Concepts
- Multithreading and concurrency
- Mutex locks(mutual exclusion)
- Dataraces
- Deadlocks
- Resource allocation (forks)

---

<img src="https://i.imgur.com/1PIjqvW.png" alt="Visual">

Below is an example of a succesful run of the program with the arguments `99 185 60 60`

<img src="https://i.imgur.com/zBbc7Kz.gif" alt="Philos gif">

### Remarks

---

### Sources
