#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define PROCESS_NAME_LEN 32         // 进程名最大长度
#define MIN_SLICE 10                // 内碎片最大大小
#define DEFAULT_MEM_SIZE 1024       // 总内存大小
#define DEFAULT_MEM_START 0         // 内存开始分配时的起始地址

int mem_size = DEFAULT_MEM_SIZE;
static int pid = 0;

struct free_block {                 // 空闲数据块
    int size;
    int start_addr;
    struct free_block *next;
};

struct allocated_block {            // 已分配的数据块
    int pid;
    int size;
    int start_addr;
    int *data;
    allocated_block *next;
};

free_block *free_block_head;        // 空闲数据块首指针
allocated_block *allocated_block_head = nullptr;    // 分配块首指针



allocated_block *find_process(int id);              // 寻找pid为id的分配块
free_block *init_free_block(int mem_size);          // 空闲块初始化
void display_menu(); //显示选项菜单
void set_mem_size(int arg); // 设置内存大小

void rearrange(); // 对块进行重新分配
void swap(int *p, int *q); //交换地址
int dispose(allocated_block *ab); //释放分配块结构体
void display_mem_usage(); //显示内存情况
int create_new_process(int mem_size);               //创建新的进程
void kill_process(int pid); //杀死对应进程并释放其空间与结构体

class Allocator {
public:
    virtual int free_mem(allocated_block *ab);
    virtual int allocate_mem(allocated_block *ab) = 0;  //为制定块分配内存
};


void insert_allocate_block(allocated_block* target) {
    if (allocated_block_head == nullptr) {
        target->next = nullptr;
        allocated_block_head = target;
    } else {
        target->next = allocated_block_head;
        allocated_block_head = target;
    }
}
void remove_allocate_block(allocated_block* target) {
    if (allocated_block_head == target) {
        allocated_block_head = allocated_block_head->next;
    } else {
        for (allocated_block *now = allocated_block_head; now->next != nullptr; now = now->next) {
            if (now->next == target) {
                now->next = target->next;
                break;
            }
        }
    }
    delete target;
}
void insert_free_block(free_block* target) {
    if (free_block_head == nullptr) {
        free_block_head = target;
    } else {
        target->next = free_block_head;
        free_block_head = target;
    }
}
void remove_free_block(free_block* target) {
    if (free_block_head == target) {
        free_block_head = free_block_head->next;
    } else {
        for (free_block *now = free_block_head; now->next != nullptr; now = now->next) {
            if (now->next == target) {
                now->next = target->next;
                break;
            }
        }
    }
    delete target;
}

free_block *find_back_free_block(int start_addr) {
    for (free_block *now = free_block_head; now != nullptr; now = now->next) {
        if (now->start_addr == start_addr)
            return now;
    }
    return nullptr;
}
free_block *find_front_free_block(int end_addr) {
    for (free_block *now = free_block_head; now != nullptr; now = now->next) {
        if (now->start_addr + now->size == end_addr)
            return now;
    }
    return nullptr;
}

int Allocator::free_mem(allocated_block *ab) {         // 释放分配块
    // 1. 查找前部有无空闲分区
    free_block* front = find_front_free_block(ab->start_addr);
    // 2. 查找后部有无空闲分区
    free_block* back = find_back_free_block(ab->start_addr + ab->size);
    if (front != nullptr) {
        front->size += ab->size;
        if (back != nullptr) {
            front->size += back->size;
            remove_free_block(back);
        }
        return 1;
    }
    if (front == nullptr && back != nullptr) {
        back->start_addr = ab->start_addr;
        back->size += ab->size;
        return 1;
    }
    // 开辟一个空内存
    free_block *newFree = new free_block();
    newFree->size = ab->size;
    newFree->start_addr = ab->start_addr;
    newFree->next = nullptr;
    // 插入空内存
    insert_free_block(newFree);
    return 1;
}

class FirstFitAllocator : public Allocator {
    int allocate_mem(allocated_block *ab) override {
        int need = ab->size;
        free_block *ptr = nullptr;
        for (free_block *now = free_block_head; now != nullptr; now = now->next) {
            if (now->size >= need) {
                ptr = now;
                break;
            }
        }
        if (ptr == nullptr) {
            return -1;
        }

        if (ptr->size == need) {
            remove_free_block(ptr);
        } else {
            ptr->size -= need;
            ab->start_addr = ptr->start_addr;
            ptr->start_addr += need;
        }
        insert_allocate_block(ab);
        return 0;
    }
};

class WorstFitAllocator : public Allocator {
    int allocate_mem(allocated_block *ab) override {

    }
};

class BestFitAllocator : public Allocator {
    int allocate_mem(allocated_block *ab) override {

    }
};

class BuddySystemAllocator : public Allocator {
    int free_mem(allocated_block *ab) override {

    }

    int allocate_mem(allocated_block *ab) override {

    }
};


Allocator *alc;

//主函数
int main() {
    int opt, arg;
    free_block_head = init_free_block(mem_size); //初始化一个可以使用的内存块，类似与操作系统可用的总存储空间
    for (;;) {
        display_menu();
        scanf("%d", &opt);
        if (opt < 5) {
            scanf("%d", &arg);
        }
        if (opt == 1) {
            set_mem_size(arg);
        } else if (opt == 2) {
            if (arg == 1) {
                alc = new BestFitAllocator();
            } else if (arg == 2) {
                alc = new WorstFitAllocator();
            } else if (arg == 3) {
                alc = new FirstFitAllocator();
            } else if (arg == 4) {
                alc = new BuddySystemAllocator();
            } else {
                puts("Wrong argument!");
            }
        } else if (opt == 3) {
            create_new_process(arg);
        } else if (opt == 4) {
            kill_process(arg);
        } else if (opt == 5) {
            display_mem_usage();
        } else if (opt == 5) {
            puts("Bye....");
            return 0;
        } else {
            puts("Wrong argument!");
        }
    }
}


free_block *init_free_block(int mem_size) { //初始化空闲块，这里的mem_size表示允许的最大虚拟内存大小
    free_block *p = new free_block;
    p->size = mem_size;
    p->start_addr = DEFAULT_MEM_START;
    p->next = nullptr;
    return p;
}

void display_menu() {
    puts("\n\n******************menu*******************");
    printf("1) Set memory size (default = %d)\n", DEFAULT_MEM_SIZE);
    printf("2) Set memory allocation algorithm\n 1: Best Fit\n 2: Worst Fit\n 3: First Fit\n 4: Buddy System\n");
    printf("3) Create a new process\n");
    printf("4) Kill a process\n");
    printf("5) Display memory usage\n");
    printf("233) Exit\n");
}

void set_mem_size(int arg) { //更改最大内存大小
    if (allocated_block_head == nullptr) {
        free_block_head->size = arg;
    } else {
        puts("Invalid operation");
    }
}

int allocate_mem(allocated_block *ab) { //为块分配内存，真正的操作系统会在这里进行置换等操作
    return alc->allocate_mem(ab);
}

int create_new_process(int mem_size) { //创建新进程
    if (alc == nullptr) {
        puts("Set memory allocation algorithm first!");
        return -1;
    }

    // Write your code here
    allocated_block *newBlock = new allocated_block();

    newBlock->pid = ++pid;
    newBlock->size = mem_size;
    newBlock->next = nullptr;

    allocate_mem(newBlock);
}

void swap(int *p, int *q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void rearrange() { //将块按照地址大小进行排序
    free_block *tmp, *tmpx;
    puts("Rearrange begins...");
    puts("Rearrange by address...");
    tmp = free_block_head;
    while (tmp != nullptr) {
        tmpx = tmp->next;
        while (tmpx != nullptr) {
            if (tmpx->start_addr < tmp->start_addr) {
                swap(&tmp->start_addr, &tmpx->start_addr);
                swap(&tmp->size, &tmpx->size);
            }
            tmpx = tmpx->next;
        }
        tmp = tmp->next;
    }
    usleep(500);
    puts("Rearrange Done.");
}


int free_mem(allocated_block *ab) { //释放某一块的内存
    return alc->free_mem(ab);
}

int dispose(allocated_block *ab) { //释放结构体所占的内存
    remove_allocate_block(ab);
}

void display_mem_usage() {
    free_block *fb = free_block_head;
    allocated_block *ab = allocated_block_head;
    puts("*********************Free Memory*********************");
    printf("%20s %20s\n", "start_addr", "size");
    int cnt = 0;
    while (fb != nullptr) {
        cnt++;
        printf("%20d %20d\n", fb->start_addr, fb->size);
        fb = fb->next;
    }
    if (!cnt) puts("No Free Memory");
    else printf("Totaly %d free blocks\n", cnt);
    puts("");
    puts("*******************Used Memory*********************");
    printf("%10s %10s %20s\n", "PID", "start_addr", "size");
    cnt = 0;
    while (ab != nullptr) {
        cnt++;
        printf("%10d %10d %20d\n", ab->pid, ab->start_addr, ab->size);
        ab = ab->next;
    }
    if (!cnt) puts("No allocated block");
    else printf("Totaly %d allocated blocks\n", cnt);
}


allocated_block *find_process(int id) { //循环遍历分配块链表，寻找pid=id的进程所对应的块
    for (allocated_block *now = allocated_block_head; now != nullptr; now = now->next) {
        if (now->pid == id)
            return now;
    }
    return nullptr;
}

void kill_process(int pid) { //杀死某个进程
    if (alc == nullptr) {
        puts("Set memory allocation algorithm first!");
        return;
    }

    allocated_block *ab = find_process(pid);
    if (ab != nullptr) {
        free_mem(ab);
        dispose(ab);
    }
}



