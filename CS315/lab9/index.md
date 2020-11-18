# Lab9 for CS315

## Some info...

Author: 11711918 吴烨昌

## Tasks

### Task 1: Modify a Dummy Read-Only File

Setup the target file:

![image-20201118145206669](C:\Users\Wycer\AppData\Roaming\Typora\typora-user-images\image-20201118145206669.png)

edit `cow_attack.c`:

![image-20201118165734369](C:\Users\Wycer\AppData\Roaming\Typora\typora-user-images\image-20201118165734369.png)

this program will mmap the target filel in vm, and rasie two threads, one will keep trying to read(seek) and write the vm of the read-only file, the other will keep trying to make os release corresponding vm.

There will be a time that in order, 

1. Read target  file (page cache)
2. Write target file 
3. OS makes a COW page (dirty and Read-Only)
4. Failed to follow_page, because `FOLL_WRITE` flag.
5. Page fault.
6. Drop `FOLL_WRITE` flag. (It's convinent for OS to avoid dead loop)
7. follow_page
8. if normal, follow_page will return a templory page.
9. if there is a madvise before follow_page, follow_page will return original page.
10. Write to the page will be written back to the file.

![image-20201118161818810](C:\Users\Wycer\AppData\Roaming\Typora\typora-user-images\image-20201118161818810.png)

### Task 2

![image-20201118165559990](C:\Users\Wycer\AppData\Roaming\Typora\typora-user-images\image-20201118165559990.png)

So there is only one string "1001". Replace "1001" with "0" in `/etc/passwd` will make charlie root.

![image-20201118172615369](C:\Users\Wycer\AppData\Roaming\Typora\typora-user-images\image-20201118172615369.png)

![image-20201118173016251](C:\Users\Wycer\AppData\Roaming\Typora\typora-user-images\image-20201118173016251.png)