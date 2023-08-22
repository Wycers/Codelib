//
// Created by Wycer on 2020/12/24.
//

#pragma once

#include <vector>
#include <unordered_map>
#include "dag.h"

struct Block {
    int idx;
    int head;

    IRList irs;

    DAG *dag;

    Block(IRList irs);

    IRList optimize();

    std::string str();
};

struct Edge {
    int to;
    int next;
};

struct CFG {
    std::vector<Block *> blocks;
    std::vector<Edge *> edges;
    std::unordered_map<std::string, Block *> label_map;
    std::string name;

    CFG(IRList irs);

    void clear();

    Block *addBlock(IRList irs);

    Edge *addEdge(Block *a, Block *b);

    void print(std::string filename);

    std::string str();

    IRList optimize();
};
