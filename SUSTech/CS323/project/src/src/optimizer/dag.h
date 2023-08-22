//
// Created by Wycer on 2020/12/25.
//

#pragma once


#include <unordered_map>
#include <ir.hpp>

struct DagNode {
    std::string name, info;
    std::vector<DagNode *> children;
    IR *ir;

    int id;
    bool live = true;

    DagNode();
};

struct DAG {
    int cnt = 0;

    std::vector<DagNode *> nodes;

    std::unordered_map<std::string, DagNode *> mp;

    DAG(IRList irs);

    void optimize();

    IRList restore();

    void addNode(std::string name, DagNode *node);

    DagNode *getNode(std::string name);

    void print(std::string filename);

    DagNode *ao1(IR *ir, DagNode *cnodes[2]);
    DagNode *ao2(IR *ir, DagNode *cnodes[2]);
};


