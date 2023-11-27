<img src="https://i.imgur.com/HG66CCx.png?raw=true" alt="CODAM" style="max-width: 50%;">

# ** README IS STILL A WORK IN PROGRESS **

# Philosophers

This project is a simulation of the classic dining philosophers problem. In this problem, a number of philosophers are seated at a dining table. Each of them thinks, eats and sleeps, but there are a limited number of forks placed between them.  
To be able to eat a philosopher must acquire both forks on their sides. Our goal is to configure our program in such a way that none of the philosophers die from starving.  

Our particular brand of philosophers happen to be very paradoxal. They are very smart and dumb at the same time. Able to ponder life's questions, but not able to eat with a singular fork is. This however, is unfortunately not their only shortcomming. These men and women have the metabolism teenage girls dream of. If they don't feed themselves within a set timespan, measured in miliseconds, they simply starve to death, due to their neighbors hogging the forks they so desperately need.

The challenge is to implement a solution that avoids [deadlocks](https://www.geeksforgeeks.org/introduction-of-deadlock-in-operating-system/) and ensures proper synchronization in access to the forks, so that our thinkers don't die on us.
This project offers a multithreaded solution to the dining philosophers problem by levaraging mutex locks.

---

<div align=center>
  <img src="https://i.imgur.com/5z3WCjy.png" alt="Visual">
</div>

---

### Key Concepts
- [Multithreading](https://www.geeksforgeeks.org/multithreading-in-c/) and concurrency
- [Mutex locks](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)(mutual exclusion)
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

1. **Initialization:**
   - Parse command-line arguments to configure the simulation parameters.
   - Check the validity of input arguments.
   - Initialize data structures for philosophers (`t_philo`) and general simulation data (`t_data`).

2. **Philosopher Threads Creation:**
   - Create a thread for each philosopher using the `pthread_create` function.
   - The entry point for each philosopher thread is the `run_sim` function.
   - Philosopher threads execute a continuous loop in the `run_sim` function, performing routines and checking for death or completion conditions.

3. **Simulation Execution:**
   - If the number of philosophers is 1, run a special case (`solo_philo`) and exit successfully.
   - If there are multiple philosophers, start the simulation using the `simulate` function.
   - Inside `simulate`, create an array of threads (`pthread_t`) for the philosophers.
   - Use the `run_threads` function to create philosopher threads and a monitoring thread (`monitor`).
   - Wait for all philosopher threads to finish using `pthread_join`.
   - Detach the monitoring thread using `pthread_detach`.

4. **Philosopher Routine:**
   - The core routine of each philosopher is defined in the `routine` function.
   - Philosopher threads continuously loop through taking forks, eating, and dropping forks.
   - The routine is periodically interrupted to check for death or completion conditions.

5. **Monitoring Thread:**
   - The monitoring thread is created using `pthread_create` and executes the `observe` function.
   - `observe` periodically checks for philosopher deaths using the `monitor_dead` function.
   - It also checks if all philosophers have completed their meals using the `monitor_done` function.
   - The monitoring thread sleeps for a duration equal to the maximum time a philosopher can survive without eating.

6. **Ending Conditions:**
   - The program terminates when all philosopher threads have completed their meals or if any philosopher dies.
   - Proper cleanup is performed using the `ft_clean` function, which destroys mutexes and frees allocated memory.

7. **Output:**
   - Informative messages are printed throughout the simulation, indicating when a philosopher starts eating, sleeping, thinking, or if they have passed away.
   - The program also prints a final message when all philosophers have completed their meals.

8. **Cleanup:**
   - Mutexes are destroyed, and allocated memory is freed to ensure proper cleanup.

---

<img src="https://i.imgur.com/1PIjqvW.png" alt="Visual">

Below is a visual example of a succesful run of the program with the arguments `99 185 60 60`
<div align=center>
  <img src="https://i.imgur.com/zBbc7Kz.gif" alt="Philos gif">
</div>

---

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
