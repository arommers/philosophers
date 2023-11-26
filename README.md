<img src="https://i.imgur.com/HG66CCx.png?raw=true" alt="CODAM" style="max-width: 50%;">

# ** README IS STILL A WORK IN PROGRESS **

# Philosophers

This project is a simulation of the classic dining philosophers problem. In this problem, a number of philosophers are seated at a dining table. Each philosopher thinks, eats and sleeps, but there are a limited number of forks placed between them.  
A philosopher must acquire both forks on their sides to eat. The object is to prevent any of the philosophers from starving before they are able to aquire two forks to eat.  

Our particular brand of philosophers happen to be very paradoxal. They are very smart and dumb at the same time. Able to ponder life's questions, but not able to eat with a singular fork is. This however, is unfortenately not their only shortcomming. These men and women have the metabolism teenage girls dream of. If they don't feed themselves within a set timespan, measured in miliseconds, they simply starve to death, due to their neighbors hogging the forks they so desperately need.

The challenge is to implement a solution that avoids [deadlocks](https://www.geeksforgeeks.org/introduction-of-deadlock-in-operating-system/) and ensures proper synchronization in access to the forks, so that our thinkers don't die on us.
This project offers a multithreaded solution to the dining philosophers problem by levaraging mutex locks.

---

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

---

### The program


<img src="https://i.imgur.com/5z3WCjy.png" alt="Visual">

<img src="https://i.imgur.com/1PIjqvW.png" alt="Visual">

Below is an example of a succesful run of the program with the arguments `99 185 60 60`

<img src="https://i.imgur.com/zBbc7Kz.gif" alt="Philos gif">

### Remarks
- I should have aligned the creation of the philosophers/threads.
  
  Currently the threads starts running their associated function `run_sim` at their inception.
  This theoretically means that the first thread could run their function multiple times before the last one is even created. Or worse even die and stop.
  To prevent this from happening the following two steps should have been implemented:

  First, a mutex lock is introduced to encapsulate the thread creation loop, ensuring a sequential and synchronized thread creation process. This involves locking the mutex, creating threads, and unlocking the mutex.

  Second, the same mutex lock is also introduced to the functions that each thread will execute `run_sim`. This guarantees that no thread starts executing its associated function until all threads have been created. The flow involves locking the mutex, executing the associated function, and 
  then unlocking the mutex. By implementing this approach, the risk of the first thread running multiple times before the last one is created or, worse, dying prematurely is mitigated, creating a more controlled and orderly multithreading environment.
- It would have been better for synchronization to use more mutex locks. One for each shared data value.

  Initially the program only employed a public and private mutex lock to limit access to shared data. This made it so that the amount of threads waiting for access would lead to congestion, resulting in a philosopher's untimely death.
  I circumvented this by separating the checks for the nr. of meals and the death status. Within the context of this assingment this divison sufficed. For improved flow and syncronization of our threads however, assigning each shared data a mutex lock would have been better.
  
---

### Sources
- [Subject file](https://cdn.intra.42.fr/pdf/pdf/68830/en.subject.pdf)
- [Code Vault](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
