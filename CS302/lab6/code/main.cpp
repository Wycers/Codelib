#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define PROCESS_NAME_LEN 32   // 进程名最大长度
#define MIN_SLICE 10          // 内碎片最大大小
#define DEFAULT_MEM_SIZE 1024 // 总内存大小
#define DEFAULT_MEM_START 0   // 内存开始分配时的起始地址

const int K = floor(log(DEFAULT_MEM_SIZE) / log(2));

int mem_size = DEFAULT_MEM_SIZE;
static int global_pid = 0;

struct free_block { // 空闲数据块
    int size;
    int start_addr;
    struct free_block *next;
};

struct allocated_block { // 已分配的数据块
    int pid;
    int size;
    int start_addr;
    int *data;
    allocated_block *next;
};

free_block *free_block_head;                     // 空闲数据块首指针
allocated_block *allocated_block_head = nullptr; // 分配块首指针

allocated_block *find_process(int id); // 寻找pid为id的分配块
free_block *init_free_block(int size); // 空闲块初始化
void display_menu();                   //显示选项菜单
void set_mem_size(int arg);            // 设置内存大小

void rearrange();                 // 对块进行重新分配
void swap(int *p, int *q);        //交换地址
int dispose(allocated_block *ab); //释放分配块结构体
void display_mem_usage();         //显示内存情况
int create_new_process(int size); //创建新的进程
void kill_process(int pid);       //杀死对应进程并释放其空间与结构体

class Allocator {
public:
    virtual void free_status();

    virtual void used_status();

    virtual int free_mem(allocated_block *ab);

    virtual int allocate_mem(allocated_block *ab) = 0; //为制定块分配内存
};

void insert_allocate_block(allocated_block *target) {
    if (allocated_block_head == nullptr) {
        target->next = nullptr;
        allocated_block_head = target;
    } else {
        target->next = allocated_block_head;
        allocated_block_head = target;
    }
}

void remove_allocate_block(allocated_block *target) {
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

void insert_free_block(free_block *&head, free_block *target) {
    if (head == nullptr) {
        target->next = nullptr;
        head = target;
    } else {
        target->next = head;
        head = target;
    }
}

void remove_free_block(free_block *&head, free_block *target) {
    if (head == target) {
        head = target->next;
    } else {
        for (free_block *now = head; now->next != nullptr; now = now->next) {
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

int Allocator::free_mem(allocated_block *ab) { // 释放分配块
    // 1. 查找前部有无空闲分区
    free_block *front = find_front_free_block(ab->start_addr);
    // 2. 查找后部有无空闲分区
    free_block *back = find_back_free_block(ab->start_addr + ab->size);
    if (front != nullptr) {
        front->size += ab->size;
        if (back != nullptr) {
            front->size += back->size;
            remove_free_block(free_block_head, back);
        }
        return 1;
    }
    if (front == nullptr && back != nullptr) {
        back->start_addr = ab->start_addr;
        back->size += ab->size;
        return 1;
    }
    // 开辟一个空内存
    auto *newFree = new free_block();
    newFree->size = ab->size;
    newFree->start_addr = ab->start_addr;
    newFree->next = nullptr;
    // 插入空内存
    insert_free_block(free_block_head, newFree);
    return 1;
}

void Allocator::free_status() {
    printf("%20s %20s\n", "start_addr", "size");
    int cnt = 0;
    for (free_block *now = free_block_head; now != nullptr; now = now->next) {
        cnt++;
        printf("%20d %20d\n", now->start_addr, now->size);
    }
    if (!cnt)
        puts("No Free Memory");
    else
        printf("Totaly %d free blocks\n", cnt);
}

void Allocator::used_status() {
    printf("%10s %10s %20s\n", "PID", "start_addr", "size");
    int cnt = 0;
    for (allocated_block *now = allocated_block_head; now != nullptr; now = now->next) {
        cnt++;
        printf("%10d %10d %20d\n", now->pid, now->start_addr, now->size);
    }
    if (!cnt)
        puts("No allocated block");
    else
        printf("Totaly %d allocated blocks\n", cnt);
}

class FirstFitAllocator : public Allocator {
    int allocate_mem(allocated_block *ab) override {
        int need = ab->size;
        free_block *ptr = nullptr;
        for (free_block *now = free_block_head; now != nullptr; now = now->next) {
            if (now->size < need)
                continue;
            ptr = now;
            break;
        }
        if (ptr == nullptr) {
            return -1;
        }

        if (ptr->size == need) {
            remove_free_block(free_block_head, ptr);
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
        int need = ab->size;
        free_block *ptr = nullptr;
        // find the largest free block
        for (free_block *now = free_block_head; now != nullptr; now = now->next) {
            if (now->size < need)
                continue;
            if (ptr == nullptr || now->size > ptr->size) {
                ptr = now;
            }
        }
        if (ptr == nullptr) {
            return -1;
        }

        if (ptr->size == need) {
            remove_free_block(free_block_head, ptr);
        } else {
            ptr->size -= need;
            ab->start_addr = ptr->start_addr;
            ptr->start_addr += need;
        }
        insert_allocate_block(ab);
        return 0;
    }
};

class BestFitAllocator : public Allocator {
    int allocate_mem(allocated_block *ab) override {
        int need = ab->size, mn = 0x7fffffff;
        free_block *ptr = nullptr;
        // find the smallest but large enough free block
        for (free_block *now = free_block_head; now != nullptr; now = now->next) {
            if (now->size < need)
                continue;
            if (ptr == nullptr || ptr->size > now->size) {
                ptr = now;
            }
        }
        if (ptr == nullptr) {
            return -1;
        }

        if (ptr->size == need) {
            remove_free_block(free_block_head, ptr);
        } else {
            ptr->size -= need;
            ab->start_addr = ptr->start_addr;
            ptr->start_addr += need;
        }
        insert_allocate_block(ab);
        return 0;
    }
};

class BuddySystemAllocator : public Allocator {
    free_block **mem = new free_block *[K + 1];

public:
    BuddySystemAllocator() {
        mem[K] = new free_block;
        mem[K]->size = mem_size;
        mem[K]->start_addr = 0;
    }

    void free_status() override {
        printf("%20s %20s\n", "start_addr", "size");
        int cnt = 0;
        for (int k = 0; k <= K; ++k) {
            for (free_block *now = mem[k]; now != nullptr; now = now->next) {
                cnt++;
                printf("%20d %20d\n", now->start_addr, now->size);
            }
        }
        if (!cnt)
            puts("No Free Memory");
        else
            printf("Totaly %d free blocks\n", cnt);
    }

    free_block *request(int k) {
        if (k == K + 1) {
            return nullptr;
        }
        if (mem[k] == nullptr) {
            free_block *ptr = request(k + 1);
            if (ptr == nullptr) {
                return nullptr;
            }
            auto first = new free_block, second = new free_block;
            first->size = second->size = (ptr->size >> 1);

            first->start_addr = ptr->start_addr;
            second->start_addr = first->start_addr + first->size;

            first->next = second;
            second->next = mem[k];
            mem[k] = first;

            remove_free_block(mem[k + 1], ptr);
        }
        return mem[k];
    }

    static int cal_k(int size) {
        int k = 0;
        for (k = 0; k <= K && (1 << k) < size; ++k);
        return k;
    }

    int allocate_mem(allocated_block *ab) override {
        int k = cal_k(ab->size);
        if (k > K) {
            return -1;
        }

        free_block *ptr = request(k);
        if (ptr == nullptr) {
            return -1;
        }

        ab->start_addr = ptr->start_addr;
        remove_free_block(mem[k], ptr);
        insert_allocate_block(ab);
        return 0;
    }

    void release(int k, free_block *target) {
        if (k == K) {
            insert_free_block(mem[k], target);
            return;
        }
        bool flag = false;
        for (free_block *now = mem[k]; now != nullptr; now = now->next) {
            if ((now->start_addr >> (k + 1)) == (target->start_addr >> (k + 1))) {
                target->start_addr = min(target->start_addr, now->start_addr);
                target->size <<= 1;
                remove_free_block(mem[k], now);
                release(k + 1, target);
                flag = true;
                break;
            }
        }
        if (flag)
            return;
        insert_free_block(mem[k], target);
    }

    int free_mem(allocated_block *ab) override {
        int k = cal_k(ab->size);
        auto released = new free_block;
        released->start_addr = ab->start_addr;
        released->size = (1 << k);
        release(k, released);
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
        } else if (opt == 233) {
            puts("Bye....");
            return 0;
        } else {
            puts("Wrong argument!");
        }
    }
}

free_block *init_free_block(int size) { //初始化空闲块，这里的mem_size表示允许的最大虚拟内存大小
    auto *p = new free_block;
    p->size = size;
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

int create_new_process(int size) { //创建新进程
    if (alc == nullptr) {
        puts("Set memory allocation algorithm first!");
        return -1;
    }

    // Write your code here
    auto *newBlock = new allocated_block();

    newBlock->pid = ++global_pid;
    newBlock->size = size;
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
    puts("*********************Free Memory*********************");
    alc->free_status();
    puts("");
    puts("*******************Used Memory*********************");
    alc->used_status();
    puts("");
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
