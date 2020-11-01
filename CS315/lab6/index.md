# Lab6 for CS315

## Some info...

Author: 11711918 吴烨昌

## Tasks

### Part 1


1. Read the lab instructions above and finish all the tasks.

2. Answer the questions in the Introduction section, and justify your answers.
  Simple yes or no answer will not get any credits.


  1. What security features does Zephyr have?

    1. RO/NX memory protectons 
    2. Stack depth overfow preventon
    3. Stack bufer overfow detecton
    4. Kernel code considered trusted
    5. Userspace threads, not processes
    6. Kernel/user boundary stll being fully feshed out
    7. (Generally) Sing le applicaton
    8. Highly dependent on partcular SoC, confg , applicaton developer 

  2. Do applications share the same address space with the OS kernel?

     Yes, but it also supports to share same address space (for platforms without MMU/MPU and memory constrained devices,)

  3. Does Zephyr have defense mechanisms such as non-executable stack or Address Space Layout Randomization (ASLR)?

     I am not sure whether zephyr has non-executable stack or not but zephyr has implemented an identity page table that is helpful to support non-executable stack. There is no ASLR in Zephyr.

  4. Do textbook attacks (e.g., buffer overflow or heap spray) work on Zephyr?

     Yes, buffer overflow works.

3. Change the EIP register to the value 0xdeadbeef, and show me the screenshot
  of the EIP value when the application crashes.

  ![image-20201031220808903](image-20201031220808903.png)

### Part 2

