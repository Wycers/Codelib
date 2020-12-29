//
// Created by Wycer on 2020/12/25.
//

#include "dag.h"

#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#define INNER_DCE
#define INNER_CP
#define INNER_CSE
#define INNER_CE

using std::cout, std::endl;

IRList &operator+=(IRList &a, const IRList b);

IRList &operator+=(IRList &a, IR *b);

DagNode *bubble(DagNode *curNode) {
    while (curNode->ir && curNode->ir->irType == IRType::IR_ASSIGN) {
        curNode = curNode->children[0];
    }
    return curNode;
}

DAG::DAG(IRList irs) {
    nodes.clear();

    for (auto ir : irs) {
        auto curNode = new DagNode();
        switch (ir->irType) {
            case IRType::IR_DEC: {
                curNode->info = "DEC";
                curNode->ir = ir;

                auto node0 = getNode(ir->args[0]);
                curNode->children.push_back(node0);
                addNode(ir->args[0], curNode);
            }
                break;
            case IRType::IR_CALL: {
                curNode->info = "CALL";
                curNode->ir = ir;

//                auto node1 = getNode(ir->args[1]);
//                curNode->children.push_back(node1);
                addNode(ir->args[0], curNode);
            }
                break;
            case IRType::IR_ASSIGN: {

                curNode->info = "ASSIGN";
                curNode->ir = ir;

                auto node1 = getNode(ir->args[1]);
#ifdef INNER_CP
                node1 = bubble(node1);
#endif
                if (node1->name[0] == 't') {
                    node1->name = ir->args[0];
                    node1->ir->args[0] = ir->args[0];
                    mp[ir->args[0]] = node1;
                } else {
                    curNode->children.push_back(node1);
                    addNode(ir->args[0], curNode);
                }
            }
                break;
            case IRType::IR_REF: {
                curNode->info = "Address Of";
                curNode->ir = ir;

                auto node1 = getNode(ir->args[1]);
                curNode->children.push_back(node1);
                addNode(ir->args[0], curNode);
                break;
            }
            case IRType::IR_LDEREF: {
                curNode->info = "Set To";
                curNode->ir = ir;

                auto node1 = getNode(ir->args[1]);
                curNode->children.push_back(node1);
                addNode(ir->args[0], curNode);
                break;
            }
            case IRType::IR_RDEREF: {
                curNode->info = "Set from";
                curNode->ir = ir;

                auto node1 = getNode(ir->args[1]);
                curNode->children.push_back(node1);
                addNode(ir->args[0], curNode);
                break;
            }
            case IRType::IR_ADD:
            case IRType::IR_SUB:
            case IRType::IR_MUL:
            case IRType::IR_DIV: {
                DagNode *cnodes[2] = {getNode(ir->args[1]), getNode(ir->args[2])};
#ifdef INNER_CP
                cnodes[0] = bubble(cnodes[0]);
                cnodes[1] = bubble(cnodes[1]);
#endif
                curNode->children.push_back(cnodes[0]);
                curNode->children.push_back(cnodes[1]);
                curNode->ir = ir;
#ifdef INNER_CSE
                DagNode *target = nullptr;
                for (auto i = nodes.rbegin(); i != nodes.rend(); ++i) {
                    auto node = *i;
                    if (node->ir == nullptr || node->ir->irType != ir->irType)
                        continue;
                    if (node->children[0] == cnodes[0] && node->children[1] == cnodes[1]) {
                        target = node;
                        break;
                    }
                }
                if (target != nullptr) {
                    curNode->children.clear();
                    curNode->children.push_back(target->children[0]);
                    curNode->children.push_back(target->children[1]);
                }
#endif
#ifdef INNER_CE
                if (curNode->ir->irType != IRType::IR_ASSIGN) {
                    if (cnodes[0]->name[0] == '#' && cnodes[1]->name[0] == '#') {
                        int a = std::stoi(cnodes[0]->name.substr(1));
                        int b = std::stoi(cnodes[1]->name.substr(1));
                        int res = 0;
                        switch (curNode->ir->irType) {
                            case IRType::IR_ADD:
                                res = a + b;
                                break;
                            case IRType::IR_SUB:
                                res = a - b;
                                break;
                            case IRType::IR_MUL:
                                res = a * b;
                                break;
                            case IRType::IR_DIV:
                                res = a / b;
                                break;
                            default:
                                break;
                        }
                        auto nodeX = getNode("#" + std::to_string(res));
                        curNode->ir = new ASSIGN_IR({ir->args[0], nodeX->name});
                        curNode->children.clear();
                        curNode->children.push_back(nodeX);
                    } else if (cnodes[0]->name[0] != '#' && cnodes[1]->name[0] != '#') {
                        if (curNode->ir->irType == IRType::IR_SUB) {
                            if (curNode->ir->args[1] == curNode->ir->args[2]) {
                                auto nodeX = getNode("#0");
                                curNode->ir = new ASSIGN_IR({ir->args[0], nodeX->name});
                                curNode->children.clear();
                                curNode->children.push_back(nodeX);
                            }
                        }
                    } else {
                        DagNode *nodeX = ao1(ir, cnodes);
                        if (nodeX != nullptr) {
                            curNode->ir = new ASSIGN_IR({ir->args[0], nodeX->name});
                            curNode->children.clear();
                            curNode->children.push_back(nodeX);
                        } else {
                            nodeX = ao2(ir, cnodes);
                            if (nodeX != nullptr) {
                                curNode = nodeX;
                                curNode->name = ir->args[0];
                            }
                        }
                    }
                }
#endif
                addNode(ir->args[0], curNode);
            }
                break;
            case IRType::IR_RET: {
                curNode->info = "RET";
                curNode->ir = ir;

                auto node0 = getNode(ir->args[0]);
#ifdef INNER_CP
                node0 = bubble(node0);
#endif
                curNode->children.push_back(node0);
                addNode("RETURN", curNode);
            }
                break;
            case IRType::IR_READ: {
                curNode->ir = ir;
                curNode->info = "READ";
                addNode(ir->args[0], curNode);
            }
                break;
            case IRType::IR_ARG: {
                curNode->info = "ARG";
                curNode->ir = ir;
                auto node0 = getNode(ir->args[0]);
#ifdef INNER_CP
                node0 = bubble(node0);
#endif
                curNode->children.push_back(node0);
                addNode("ARG", curNode);
            }
                break;
            case IRType::IR_WRITE: {
                curNode->info = "WRITE";
                curNode->ir = ir;

                auto node0 = getNode(ir->args[0]);
#ifdef INNER_CP
                node0 = bubble(node0);
#endif
                curNode->children.push_back(node0);
                addNode("WRITE", curNode);
            }
                break;
            case IRType::IR_IF: {
                auto node1 = getNode(ir->args[0]);
                auto node2 = getNode(ir->args[2]);
#ifdef INNER_CP
                node1 = bubble(node1);
                node2 = bubble(node2);
#endif
                curNode->children.push_back(node1);
                curNode->children.push_back(node2);
                curNode->ir = ir;
                addNode("IF: " + ir->args[1], curNode);
            }
                break;
            case IRType::IR_FUNCTION:
            case IRType::IR_PARAM:
            case IRType::IR_LABEL:
            case IRType::IR_GOTO: {
                curNode->ir = ir;
                nodes.push_back(curNode);
            }
                break;
        }
    }
}

bool usedIn(IR *ir, std::string name) {
    switch (ir->irType) {
        case IRType::IR_ASSIGN:
            if (ir->args[1] == name)
                return true;
            break;
        case IRType::IR_ADD:
        case IRType::IR_SUB:
        case IRType::IR_MUL:
        case IRType::IR_DIV:
            if (ir->args[1] == name)
                return true;
            if (ir->args[2] == name)
                return true;
            break;
        case IRType::IR_RET:
        case IRType::IR_ARG:
        case IRType::IR_WRITE:
            if (ir->args[0] == name)
                return true;
            break;
        case IRType::IR_LDEREF:
            if (ir->args[0] == name)
                return true;
            if (ir->args[1] == name)
                return true;
            break;
        case IRType::IR_REF:
            if (ir->args[1] == name)
                return true;
            break;
        case IRType::IR_RDEREF:
            if (ir->args[1] == name)
                return true;
            break;
        case IRType::IR_IF:
            if (ir->args[0] == name)
                return true;
            if (ir->args[2] == name)
                return true;
            break;
        case IRType::IR_READ:
        case IRType::IR_CALL:
        case IRType::IR_LABEL:
        case IRType::IR_FUNCTION:
        case IRType::IR_GOTO:
        case IRType::IR_DEC:
        case IRType::IR_PARAM:
            break;
    }
    return false;
}

bool changedIn(IR *ir, std::string name) {
    switch (ir->irType) {
        case IRType::IR_ASSIGN:
            if (ir->args[0] == name)
                return true;
            break;
        case IRType::IR_ADD:
        case IRType::IR_SUB:
        case IRType::IR_MUL:
        case IRType::IR_DIV:
            if (ir->args[0] == name)
                return true;
            break;
        case IRType::IR_RDEREF:
        case IRType::IR_REF:
            if (ir->args[0] == name)
                return true;
            break;
            if (ir->args[0] == name)
                return true;
            break;
        case IRType::IR_RET:
        case IRType::IR_ARG:
        case IRType::IR_WRITE:
        case IRType::IR_LDEREF:
        case IRType::IR_IF:
        case IRType::IR_READ:
        case IRType::IR_CALL:
        case IRType::IR_LABEL:
        case IRType::IR_FUNCTION:
        case IRType::IR_GOTO:
        case IRType::IR_DEC:
        case IRType::IR_PARAM:
            break;
    }
    return false;
}

bool isCalculation(IR *ir) {
    switch (ir->irType) {
        case IR_ADD:
        case IR_SUB:
            return true;
        default:
            return false;
    }
}

std::pair<bool, int> extractNumber(std::string str) {
    if (str[0] != '#') {
        return std::make_pair(false, 0);
    }
    return std::make_pair(true, std::stoi(str.substr(1)));
}

std::pair<std::string, int> calculate(std::string x, std::string y, std::string z) {
    int sx = x[0] == '+' ? 1 : -1;
    int sy = y[0] == '+' ? 1 : -1;
    int sz = z[0] == '+' ? 1 : -1;
    auto tx = x.substr(1);
    auto ty = y.substr(1);
    auto tz = z.substr(1);
    auto xx = extractNumber(tx);
    auto yy = extractNumber(ty);
    auto zz = extractNumber(tz);

    if (xx.first && yy.first) {
        return std::make_pair(z, sx * xx.second + sy * yy.second);
    }
    if (yy.first && zz.first) {
        return std::make_pair(x, sy * yy.second + sz * zz.second);
    }
    if (zz.first && xx.first) {
        return std::make_pair(y, sx * xx.second + sz * zz.second);
    }
    return std::make_pair("#", 0);
}

IRList VerySimpleAndNaiveAlgebraicOptimization(IRList irs) {
    IRList res;
    res.clear();

    std::unordered_set<int> cleanTags;
    cleanTags.clear();

    for (int i = 0; i < irs.size(); ++i) {
        auto ir = irs[i];
        int chance = -1;
        if (!isCalculation(ir))
            continue;

        std::string target = ir->args[0];
        if (!usedIn(irs[i], target))
            continue;

        for (int j = i - 1; j >= 0; --j) {
            if (changedIn(irs[j], target)) {
                if (isCalculation(irs[j])) {
                    chance = j;
                }
                break;
            }
        }
        if (chance == -1)
            continue;

        std::string x = irs[chance]->args[1], y = irs[chance]->args[2];

        for (int j = chance + 1; j < i; ++j) {
            if (!usedIn(irs[j], target) && !changedIn(irs[j], x) && !changedIn(irs[j], y))
                continue;
            chance = -1;
            break;
        }
        if (chance == -1)
            continue;

        // just do it!
        auto tir = irs[chance];

        std::string z = "";
        int cursor = 0;

        if (ir->args[1] == target) {
            z = ir->args[cursor = 2];
        } else {
            z = ir->args[cursor = 1];
        }


        std::pair<std::string, int> ans = std::make_pair("#", 0);
        if (ir->irType == IR_ADD) {
            if (tir->irType == IR_ADD) {
                // (x + y) + z or z + (x + y)
                ans = calculate("+" + x, "+" + y, "+" + z);
            } else {
                // (x - y) + z or z + (x - y)
                ans = calculate("+" + x, "-" + y, "+" + z);
            }
        } else {
            if (tir->irType == IR_ADD) {
                if (cursor == 1) {
                    // z - (x + y)
                    ans = calculate("-" + x, "-" + y, "+" + z);
                } else {
                    // (x + y) - z
                    ans = calculate("+" + x, "+" + y, "-" + z);
                }
            } else {
                if (cursor == 1) {
                    // z - (x - y)
                    ans = calculate("-" + x, "+" + y, "+" + z);
                } else {
                    // (x - y) - z
                    ans = calculate("+" + x, "-" + y, "-" + z);
                }
            }
        }

        if (ans.first == "#") {
            continue;
        }

        cleanTags.insert(chance);
        if (ans.first[0] == '+') {
            irs[i] = new ADD_IR({target, "#" + std::to_string(ans.second), ans.first.substr(1)});
        } else {
            irs[i] = new SUB_IR({target, "#" + std::to_string(ans.second), ans.first.substr(1)});
        }
    }

    for (int i = 0; i < irs.size(); ++i) {
        if (cleanTags.find(i) != cleanTags.end())
            continue;
        res += irs[i];
    }

    return res;
}

IRList DAG::restore() {
    IRList irs;
    irs.clear();

    for (auto node : nodes) {
        if (node->live == false)
            continue;

        if (node->ir == nullptr) {
            continue;
        }

        irs += node->ir;
    }


    std::unordered_set<std::string> used;
    std::reverse(irs.begin(), irs.end());

    bool effect = false;
    while (effect) {
        effect = false;
        used.clear();

        for (auto ir : irs) {
            if (ir->irType == IRType::IR_IF) {
                used.insert(ir->args[0]);
                used.insert(ir->args[2]);
            }
        }

        for (auto iter = irs.begin(); iter != irs.end();) {
            auto ir = *iter;
            switch (ir->irType) {
                case IRType::IR_ASSIGN:
                    if (used.find(ir->args[0]) == used.end()) {
                        iter = irs.erase(iter);
                        effect = true;
                    } else {
                        used.erase(ir->args[0]);
                        used.insert(ir->args[1]);
                        ++iter;
                    }
                    break;
                case IRType::IR_ADD:
                case IRType::IR_SUB:
                case IRType::IR_MUL:
                case IRType::IR_DIV:
                    if (used.find(ir->args[0]) == used.end()) {
                        iter = irs.erase(iter);
                        effect = true;
                    } else {
                        used.erase(ir->args[0]);
                        used.insert(ir->args[1]);
                        used.insert(ir->args[2]);
                        ++iter;
                    }
                    break;
                case IRType::IR_RET:
                case IRType::IR_ARG:
                case IRType::IR_WRITE:
                    used.insert(ir->args[0]);
                    ++iter;
                    break;
                case IRType::IR_LDEREF:
                    used.insert(ir->args[0]);
                    used.insert(ir->args[1]);
                    ++iter;
                    break;
                case IRType::IR_REF:
                    if (used.find(ir->args[0]) == used.end()) {
                        iter = irs.erase(iter);
                        effect = true;
                    } else {
                        used.insert(ir->args[1]);
                        ++iter;
                    }
                    break;
                case IRType::IR_RDEREF:
                    if (used.find(ir->args[0]) == used.end()) {
                        iter = irs.erase(iter);
                        effect = true;
                    } else {
                        used.insert(ir->args[1]);
                        ++iter;
                    }
                    break;
                case IRType::IR_IF:
                    used.insert(ir->args[0]);
                    used.insert(ir->args[2]);
                    ++iter;
                    break;
                case IRType::IR_CALL:
                case IRType::IR_LABEL:
                case IRType::IR_FUNCTION:
                case IRType::IR_GOTO:
                case IRType::IR_DEC:
                case IRType::IR_PARAM:
                case IRType::IR_READ:
                    ++iter;
                    break;
            }
        }
    }


    std::reverse(irs.begin(), irs.end());

    return VerySimpleAndNaiveAlgebraicOptimization(irs);
}

void DAG::print(std::string filename) {
    std::ofstream out;
    out.open("/home/wycer/test_env/DAG_" + filename + ".gv");

    out << "digraph {" << endl;

    for (auto node : nodes) {
        for (auto child:node->children) {
            if (child->name[0] != '#')
                continue;
            out << std::to_string(child->id) << " [label=\" NUM:" << child->name.substr(1) << "\"]" << endl;
        }
    }
    for (auto node : nodes) {
        if (node->live == false)
            continue;

        out << std::to_string(node->id) << " [label=\" "
            << (node->name[0] == '#' ? node->name.substr(1) : node->name) << endl;
        if (node->ir != nullptr) {
            switch (node->ir->irType) {
                case IRType::IR_ADD:
                    node->info = "ADD";
                    break;
                case IRType::IR_SUB:
                    node->info = "SUB";
                    break;
                case IRType::IR_MUL:
                    node->info = "MUL";
                    break;
                case IRType::IR_DIV:
                    node->info = "DIV";
                    break;
                case IRType::IR_RET:
                    node->info = "RETURN";
                    break;
                case IRType::IR_ASSIGN:
                    node->info = "ASSIGN";
                    break;
                case IRType::IR_REF:
                    node->info = "Address Of";
                    break;
            }
        }
        out << node->info << endl;
        out << "\"]" << endl;

        for (auto child : node->children) {
            out << std::to_string(child->id) << " -> " << std::to_string(node->id) << endl;
        }

        out << endl;
    }

    out << "}" << endl;
}


void DAG::addNode(std::string name, DagNode *node) {
    mp[name] = node;
    node->name = name;
    node->id = ++cnt;


    switch (node->ir->irType) {
        case IRType::IR_IF:
            node->ir->args[0] = node->children[0]->name;
            node->ir->args[2] = node->children[1]->name;
            break;
        case IRType::IR_ADD:
        case IRType::IR_SUB:
        case IRType::IR_MUL:
        case IRType::IR_DIV:
            node->ir->args[0] = node->name;
            node->ir->args[1] = node->children[0]->name;
            node->ir->args[2] = node->children[1]->name;
            break;
        case IRType::IR_ASSIGN:
            node->ir->args[1] = node->children[0]->name;
            break;
        case IRType::IR_RET:
        case IRType::IR_WRITE:
        case IRType::IR_ARG:
            node->ir->args[0] = node->children[0]->name;
            break;
    }

    nodes.push_back(node);
}

DagNode *DAG::getNode(std::string name) {
    auto p = mp.find(name);
    if (p != mp.end()) {
        auto curNode = p->second;
        return curNode;
    }
    DagNode *node = new DagNode();

    node->name = name;
    node->id = ++cnt;
    node->info = name.substr(1);
    node->ir = nullptr;
    mp[name] = node;
    return node;
}

void DAG::optimize() {
#ifdef INNER_CE
    for (auto node : nodes) {
        if (node->live == false)
            continue;
        if (node->ir->irType == IRType::IR_ASSIGN) {
            cout << node->ir->str() << endl;
            if (node->ir->args[0] == node->ir->args[1]) {
                node->live = false;
            }
        }
    }
#endif
#ifdef INNER_DCE
    std::unordered_map<DagNode *, bool> out;
    bool effect = true;
    while (effect) {
        effect = false;
        out.clear();
        for (auto node: nodes) {
            if (node->live == false)
                continue;
            for (auto child : node->children) {
                out[child] = true;
            }
        }
        for (auto node : nodes) {
            if (node->live == false)
                continue;

            if (node->name.rfind("v_", 0) == 0) {
                continue;
            }

            switch (node->ir->irType) {
                case IRType::IR_ADD:
                case IRType::IR_SUB:
                case IRType::IR_MUL:
                case IRType::IR_DIV:
                case IRType::IR_ASSIGN:
                case IRType::IR_REF:
                    if (out.find(node) == out.end()) {
                        node->live = false;
                        effect = true;
                    }
                default:
                    continue;
            }

        }
    }
#endif
}

DagNode *DAG::ao1(IR *ir, DagNode **cnodes) {

    int cursor = -1, n = 0;
    if (cnodes[0]->name[0] == '#') {
        cursor = 0;
        n = std::stoi(cnodes[0]->name.substr(1));
    }
    if (cnodes[1]->name[0] == '#') {
        cursor = 1;
        n = std::stoi(cnodes[1]->name.substr(1));
    }

    if (cursor == -1)
        return nullptr;
    DagNode *nodeX = nullptr;
    int res = 0;
    switch (ir->irType) {
        case IRType::IR_ADD:
            if (n == 0) {
                nodeX = cnodes[cursor ^ 1];
            }
            break;
        case IRType::IR_SUB:
            if (n == 0 && cursor == 1) {
                nodeX = cnodes[cursor ^ 1];
            }
            break;
        case IRType::IR_MUL:
            if (n == 0) {
                nodeX = cnodes[cursor];
            }
            if (n == 1) {
                nodeX = cnodes[cursor ^ 1];
            }
            break;
        case IRType::IR_DIV:
            if (n == 0 && cursor == 0) {
                nodeX = cnodes[cursor];
            }
            if (n == 1 && cursor == 1) {
                nodeX = cnodes[cursor ^ 1];
            }
            break;
        default:
            break;
    }

    if (nodeX != nullptr) {
        return nodeX;
    }

    return nullptr;
}

DagNode *DAG::ao2(IR *ir, DagNode **cnodes) {

    int cursor = -1, n = 0;
    if (cnodes[0]->name[0] == '#') {
        cursor = 0;
        n = std::stoi(cnodes[0]->name.substr(1));
    }
    if (cnodes[1]->name[0] == '#') {
        cursor = 1;
        n = std::stoi(cnodes[1]->name.substr(1));
    }

    if (cursor == -1)
        return nullptr;
    DagNode *nodeX = nullptr;
    int res = 0;
    switch (ir->irType) {
        case IRType::IR_MUL:
            if (n == 2) {
                auto tmp = cnodes[cursor ^ 1];
                nodeX = new DagNode();
                nodeX->ir = new ADD_IR({"", tmp->name, tmp->name});
                nodeX->children.clear();
                nodeX->children.push_back(tmp);
                nodeX->children.push_back(tmp);
            }
            break;
        case IRType::IR_SUB:
        case IRType::IR_ADD:
        case IRType::IR_DIV:
        default:
            break;
    }

    if (nodeX != nullptr) {
        return nodeX;
    }

    DagNode *tmp = cnodes[cursor ^ 1];
    if (tmp->ir == nullptr)
        return nullptr;
    switch (tmp->ir->irType) {
        case IRType::IR_ADD:
        case IRType::IR_SUB:
        case IRType::IR_MUL:
        case IRType::IR_DIV:
            break;
        default:
            return nullptr;
    }

    int tp1 = (ir->irType == IRType::IR_ADD || ir->irType == IRType::IR_SUB) ? 1 : 0;
    int tp2 = (tmp->ir->irType == IRType::IR_ADD || tmp->ir->irType == IRType::IR_SUB) ? 1 : 0;

    if (tp1 != tp2)
        return nullptr;


    DagNode *tmp_cnodes[2] = {tmp->children[0], tmp->children[1]};
    int tmp_cursor = -1, m = 0;
    if (tmp_cnodes[0]->name[0] == '#') {
        tmp_cursor = 0;
        m = std::stoi(tmp_cnodes[0]->name.substr(1));
    }
    if (tmp_cnodes[1]->name[0] == '#') {
        tmp_cursor = 1;
        m = std::stoi(tmp_cnodes[1]->name.substr(1));
    }
    if (tmp_cursor == -1) {
        return nullptr;
    }

    auto b = tmp_cnodes[tmp_cursor ^ 1];
    if (b->name == ir->args[0]) {
        return nullptr;
    }
    if (b->name == tmp->name) {
        return nullptr;
    }

    IR *finalIr = nullptr;
    DagNode *node1 = nullptr, *node2 = nullptr;
    if (cursor == 0) {
        // n x (a x b)
        if (tmp_cursor == 0) {
            // n x (m x b)
            switch (ir->irType) {
                case IRType::IR_ADD:
                    // n + (m x b)
                    if (tmp->ir->irType == IRType::IR_ADD) {
                        // n + (m + b)
                        node1 = getNode("#" + std::to_string(n + m));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new ADD_IR({});
                    } else {
                        // n + (m - b)
                        node1 = getNode("#" + std::to_string(n + m));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new SUB_IR({});
                    }
                    break;
                case IRType::IR_SUB:
                    // n - (m x b)
                    if (tmp->ir->irType == IRType::IR_ADD) {
                        // n - (m + b)
                        node1 = getNode("#" + std::to_string(n - m));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new SUB_IR({});
                    } else {
                        // n - (m - b)
                        node1 = getNode("#" + std::to_string(n - m));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new ADD_IR({});
                    }
                    break;
                case IRType::IR_MUL:
                    // n * (m x b)

                    break;
                case IRType::IR_DIV:
                    // n / (m x b)
                    break;
            }
        } else {
            // n x (a x m)
            switch (ir->irType) {
                case IRType::IR_ADD:
                    // n + (a x m)
                    if (tmp->ir->irType == IRType::IR_ADD) {
                        // n + (a + m)
                        node1 = getNode("#" + std::to_string(n + m));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new ADD_IR({});
                    } else {
                        // n + (a - m)
                        node1 = getNode("#" + std::to_string(n - m));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new ADD_IR({});
                    }
                    break;
                case IRType::IR_SUB:
                    // n - (a x m)
                    if (tmp->ir->irType == IRType::IR_ADD) {
                        // n - (a + m)
                        node1 = getNode("#" + std::to_string(n + m));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new SUB_IR({});
                    } else {
                        // n - (a - m)
                        node1 = getNode("#" + std::to_string(n + m));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new SUB_IR({});
                    }
                    break;
                case IRType::IR_MUL:
                    // n x (a x m)
                    break;
                case IRType::IR_DIV:
                    // n x (a x m)
                    break;
            }
        }
    } else {
        // (a x b) x n
        if (tmp_cursor == 0) {
            // (m x b) x n
            switch (ir->irType) {
                case IRType::IR_ADD:
                    // (m x b) + n
                    if (tmp->ir->irType == IRType::IR_ADD) {
                        // (m + b) + n
                        node1 = tmp_cnodes[tmp_cursor ^ 1];
                        node2 = getNode("#" + std::to_string(m + n));
                        finalIr = new ADD_IR({});
                    } else {
                        // (m - b) + n
                        node1 = getNode("#" + std::to_string(m + n));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new SUB_IR({});
                    }
                    break;
                case IRType::IR_SUB:
                    // (m x b) - n
                    if (tmp->ir->irType == IRType::IR_ADD) {
                        // (m + b) - n
                        node1 = tmp_cnodes[tmp_cursor ^ 1];
                        node2 = getNode("#" + std::to_string(m - n));
                        finalIr = new ADD_IR({});
                    } else {
                        // (m - b) - n
                        node1 = getNode("#" + std::to_string(m - n));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new ADD_IR({});
                    }
                    break;
                case IRType::IR_MUL:
                    // (m x b) * n

                    break;
                case IRType::IR_DIV:
                    // (m x b) / n
                    break;
            }

        } else {
            // (a x m) x n
            switch (ir->irType) {
                case IRType::IR_ADD:
                    // (a x m) + n
                    if (tmp->ir->irType == IRType::IR_ADD) {
                        // (a + m) + n
                        node1 = getNode("#" + std::to_string(m + n));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new ADD_IR({});
                    } else {
                        // (a - m) + n
                        node1 = tmp_cnodes[tmp_cursor ^ 1];
                        node2 = getNode("#" + std::to_string(n - m));
                        finalIr = new ADD_IR({});
                    }
                    break;
                case IRType::IR_SUB:
                    // (a x m) - n
                    if (tmp->ir->irType == IRType::IR_ADD) {
                        // (a + m) - n
                        node1 = getNode("#" + std::to_string(m - n));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new ADD_IR({});
                    } else {
                        // (a - m) - n
                        node1 = tmp_cnodes[tmp_cursor ^ 1];
                        node2 = getNode("#" + std::to_string(n + m));
                        finalIr = new SUB_IR({});
                    }
                    break;
                case IRType::IR_MUL:
                    // (a x m) * n

                    break;
                case IRType::IR_DIV:
                    // (a x m) / n
                    break;
            }
        }
    }

    if (finalIr == nullptr) {
        return nullptr;
    }

    DagNode *fuck = new DagNode();
    fuck->ir = finalIr;
    fuck->ir->args = {"", node1->name, node2->name};
    fuck->children.clear();
    fuck->children.push_back(node1);
    fuck->children.push_back(node2);
    return fuck;
}

DagNode::DagNode() {
}
