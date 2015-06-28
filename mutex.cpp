



/*

most threaded programs need to share some data between threads. there may be trouble if two threads try to access shared data at the same time, because one thread may be

in the midst of modifying some data invariant while another acts on the data as if it were consistent.this section is all about protecting the program from that sort of trouble


consider , for example , a thread that writes new data to an element in an array, and then updates a max_index variable to indicate that the array element is valid. Now consider

another thread, running simultaneously on another processor. that steps through the array performing some computation on each valid element. if the second thread "sees"

the new value of max_index before it sees the new value of the array element, the computation would be incorrect. this may seem irrational,but memory systems that work this way

can be substantially faster than memory systems that guarantee predictable ordering of memory accesses. A mutex is one general solution to this sort of problem. if each thread

locks a mutex around the section of code that is using shared data, only one thread will be able to enter the section at a time

A mutex is represented in your program by a variable of type pthread_mutex_t. you should never make a copy of a mutex, because the result of using a copied mutex is undefined
you can , however, freely copy a pointer to a mutex so that various functions and threads can use it for synchronization









it is a good idea to associate a mutex clearly with the data it protects,if possible, by keeping the definition of the mutex and data together,

you can destroy a mutex as soon as you are sure no threads are blocked on the mutex

it is safe to destroy a mutex when you know that no threads can be blocked on the mutex, and no additional threads will try to lock the mutex. the best
way to known this is usually within a thread that has just unlocked the mutex,








*/












