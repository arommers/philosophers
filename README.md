<img src="https://i.imgur.com/HG66CCx.png?raw=true" alt="CODAM" style="max-width: 50%;">

# ** README IS STILL A WORK IN PROGRESS **

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

### Usage
To run Philosophers, follow these steps:

- Clone this repository or download the source files by clicking the green code button in the upper right corner.  
  Run git clone https://github.com/arommers/philosophers.git in your terminal to clone.
- Compile the program by running the command `make`
- Arguments:
  - <num_philosophers>: Number of philosophers (positive integer).
  - <starve_time>: Time until a philosopher starves (in milliseconds).
  - <eat_time>: Time it takes to eat (in milliseconds).
  - <sleep_time>: Time it takes to sleep (in milliseconds).
  - <min_meals> (Optional): Minimum number of meals for each philosopher.
  
  For example:

  ` ./philo 5 410 100 100` or ` ./philo 5 410 100 100 10`
- Stop the simulation with CTRL-C/SIGINT

<img src="https://i.imgur.com/1PIjqvW.png" alt="Visual">

Below is an example of a succesful run of the program with the arguments `99 185 60 60`

<img src="https://i.imgur.com/zBbc7Kz.gif" alt="Philos gif">

### Remarks
- I should have aligned the creation of the philosophers/threads. Currently the threads starts running their associated function `run_sim` at their inception.
  This theoretically means that the first thread could run their function multiple times before the last one is even created. Or worse even die and stop.
  To prevent this from happening the following two steps should have been implemented:

  First, a mutex lock is introduced to encapsulate the thread creation loop, ensuring a sequential and synchronized thread creation process. This involves locking the mutex, creating threads, and unlocking the mutex.

  Second, the same mutex lock is also introduced to the functions that each thread will execute `run_sim`. This guarantees that no thread starts executing its associated function until all threads have been created. The flow involves locking the mutex, executing the associated function, and 
  then     
  unlocking the mutex. By implementing this approach, the risk of the first thread running multiple times before the last one is created or, worse, dying prematurely is mitigated, creating a more controlled and orderly multithreading environment.
- It would have been better for synchronization to use more mutex locks. One for each shared data.

  
- more stuff that i could have done better.
---

### Sources
- [Subject file](https://cdn.intra.42.fr/pdf/pdf/68830/en.subject.pdf)
- [Code Vault](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
