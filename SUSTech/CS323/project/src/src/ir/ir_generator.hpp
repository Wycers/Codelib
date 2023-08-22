

#include <utility>

#include "semantic_analysis.hpp"

using std::to_string;
using std::string;

IRList &operator+=(IRList &a, const IRList b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

IRList &operator+=(IRList &a, IR *b) {
    a.push_back(b);
    return a;
}


struct Manager {

    int cnt = 0;
    unordered_map<SymbolTableEntry *, std::string> mp;
    unordered_map<SymbolTableEntry *, bool> refMp;

    void clear() {
        mp.clear();
        refMp.clear();
        cnt = 0;
    }

    Manager() {
        clear();
    }

    void setRef(SymbolTableEntry *entry) {
        refMp[entry] = true;
    }

    bool isRef(SymbolTableEntry *entry) {
        if (refMp.find(entry) != refMp.end()) {
            return true;
        }
        return false;
    }

    std::string get_v(SymbolTableEntry *entry) {
        auto itr = mp.find(entry);
        if (itr != mp.end()) {
            return itr->second;
        }
        string res = "v_" + to_string(++cnt) + "_" + entry->name();
        mp[entry] = res;
        return res;
    }

    std::string get_t(std::string name) {
        string res = "t_" + to_string(++cnt) + "_" + name;
        return res;
    }

    string new_label(string name) {
        string res = "lb_" + to_string(++cnt) + "_" + name;
        return res;
    }
} MGR;


IRList Program::generate() {
    SYMBOL_TABLE.clear();

    auto irs = IRList();
    if (extDefList != nullptr) {
        irs += extDefList->generate();
    }
    return irs;
}

IRList ExtDefList::generate() {
    auto irs = IRList();
    if (extDef != nullptr) {
        irs += extDef->generate();
    }
    if (extDefList != nullptr) {
        irs += extDefList->generate();
    }
    return irs;
}

IRList ExtDef::generate() {
    auto irs = IRList();
    Type *type = specifier->type;
    if (node->type == NodeType::Declare) {
        if (extDecList) {
            irs += extDecList->generate();
        }
        auto fields = extDecList->fields;
        for (auto field : fields) {
            SYMBOL_TABLE.insert(new SymbolTableEntry(field, field->lineno));
        }
    }
    if (node->type == NodeType::StructDef) {
        if (type->category == Category::STRUCT) {
            SYMBOL_TABLE.insert(new SymbolTableEntry(type, node->lineno));
        }
    }
    if (this->node->type == NodeType::FuncDef) {
        Func *func = funDec->func;
        SYMBOL_TABLE.insert(new SymbolTableEntry(func, node->lineno));
        if (funDec) {
            irs += funDec->generate();
        }
        if (compSt) {
            irs += compSt->generate();
        }
    }
    return irs;
}


IRList ExtDecList::generate() {
    auto irs = IRList();

    return irs;
}

IRList FunDec::generate() {
    auto irs = IRList();
    irs.push_back(new FUNCTION_IR({name}));
    return irs;
}

IRList CompSt::generate() {
    auto irs = IRList();
    SYMBOL_TABLE.scope_push(ret_type);
//    SYMBOL_TABLE.print();
    for (auto param : params) {
        auto entry = new SymbolTableEntry(param, node->lineno);
        irs.push_back(new PARAM_IR({MGR.get_v(entry)}));
        if (entry->field->type->category != Category::PRIMITIVE) {
            MGR.setRef(entry);
        }
        SYMBOL_TABLE.insert(entry);
    }
    if (defList) {
        irs += defList->generate();
    }
    if (stmtList) {
        irs += stmtList->generate();
    }

    SYMBOL_TABLE.scope_pop();
    return irs;
}

IRList VarDec::generate() {
    auto irs = IRList();

    if (node->type == NodeType::VarDec) {
        // TODO: But seems nothing to do
    }

    if (node->type == NodeType::VarDecArray) {
        auto entry = SYMBOL_TABLE.find(field->name);
        irs += new DEC_IR({MGR.get_v(entry), to_string(spaceOf(type->array))});
    }

    return irs;
}

IRList Dec::generate() {
    auto irs = IRList();

    irs += varDec->generate();
    if (node->type == NodeType::DecWithAssign) {
        irs += exp->generate(MGR.get_v(SYMBOL_TABLE.find(field->name)));
// TODO
    }

    return irs;
}

IRList DecList::generate() {
    auto irs = IRList();

    irs += dec->generate();

    if (node->type == NodeType::VarDecListMultiple) {
        irs += nextDecList->generate();
    }
    return irs;
}


IRList Def::generate() {
    auto irs = IRList();

    irs += decList->generate();

    return irs;
}


IRList DefList::generate() {
    auto irs = IRList();

    if (node && node->type == NodeType::DefList) {

        // fields from def->fields;
        for (auto field: fields) {
            auto entry = new SymbolTableEntry(field, field->lineno);
            SYMBOL_TABLE.insert(entry);
        }

        if (def) {
            irs += def->generate();
        }
        if (nextDefList) {
            irs += nextDefList->generate();
        }
    }


    return irs;
}

IRList StmtList::generate() {
    auto irs = IRList();

    if (stmt != nullptr) {
        irs += stmt->generate();
    }
    if (nextStmtList != nullptr) {
        irs += nextStmtList->generate();
    }

    return irs;
}

IRList Stmt::generate() {
    auto irs = IRList();

    auto c = node->children;
    if (node->type == NodeType::StmtExp) {
        irs += exp->generate(MGR.get_t(""));
    }
    if (node->type == NodeType::StmtCompSt) {
        irs += compSt->generate();
    }
    if (node->type == NodeType::StmtReturn) {
        string tmp = MGR.get_t("ret");
        irs += exp->generate(tmp);
        irs.push_back(new RET_IR({tmp}));
    }
    if (node->type == NodeType::StmtIf) {
        string lb_t = MGR.new_label("");
        string lb_f = MGR.new_label("");

        irs += exp->generate("", {lb_t, lb_f});
        irs += new LABEL_IR({lb_t});
        irs += stmt1->generate();
        irs += new LABEL_IR({lb_f});
    }
    if (node->type == NodeType::StmtIfElse) {
        string lb_t = MGR.new_label("");
        string lb_f = MGR.new_label("");
        string lb = MGR.new_label("");

        irs += exp->generate("", {lb_t, lb_f});
        irs += new LABEL_IR({lb_t});

        irs += stmt1->generate();
        irs += new GOTO_IR({lb});
        irs += new LABEL_IR({lb_f});

        irs += stmt2->generate();
        irs += new LABEL_IR({lb});
    }
    if (node->type == NodeType::StmtWhile) {
        string lb1 = MGR.new_label("");
        string lb2 = MGR.new_label("");
        string lb3 = MGR.new_label("");

        irs += new LABEL_IR({lb1});
        irs += exp->generate("", {lb2, lb3});
        irs += new LABEL_IR({lb2});
        irs += stmt1->generate();
        irs += new GOTO_IR({lb1});
        irs += new LABEL_IR({lb3});
    }
    return irs;
}


IRList Args::generate() {
    auto irs = IRList();

    string name = MGR.get_t("args");
    tags.push_back(name);
    irs += exp->generate(name);

    if (nextArgs) {
        irs += nextArgs->generate();
        tags.insert(tags.end(), nextArgs->tags.begin(), nextArgs->tags.end());
    }

    return irs;
}


IRList Exp::generate(string place, pair<string, string> lbs) {
    auto irs = IRList();

    auto c = node->children;

    string lb_t = lbs.first, lb_f = lbs.second;

    if (node->type == NodeType::ExpAssign) {
        string src = MGR.get_t("src");
        irs += exp2->generate(src);


        if (exp1->node->type == NodeType::ExpId) {
            // dst is variable
            exp1->generate(place);
            irs += new ASSIGN_IR({exp1->tag_name, src});
            irs += new ASSIGN_IR({place, exp1->tag_name});
        } else {
            // dst is address
            string dst = MGR.get_t("dst");
            irs += exp1->generate(dst);
            string tmp_name = MGR.get_t("");
            irs += new LDEREF_IR({"addr_" + dst, src});
            irs += new RDEREF_IR({tmp_name, "addr_" + dst});
            irs += new ASSIGN_IR({place, tmp_name});
        }
    }
    if (node->type == NodeType::ExpAnd) {
        string lb = MGR.new_label("");

        irs += exp1->generate("", {lb, lb_f});
        irs += new LABEL_IR({lb});
        irs += exp2->generate("", {lb_t, lb_f});
    }
    if (node->type == NodeType::ExpOr) {
        string lb = MGR.new_label("");

        irs += exp1->generate("", {lb_t, lb});
        irs += new LABEL_IR({lb});
        irs += exp2->generate("", {lb_t, lb_f});
    }
    if (node->type == NodeType::ExpLT ||
        node->type == NodeType::ExpGT ||
        node->type == NodeType::ExpLE ||
        node->type == NodeType::ExpGE ||
        node->type == NodeType::ExpEQ ||
        node->type == NodeType::ExpNE) {
        exp1 = new Exp(c[0]);
        exp2 = new Exp(c[2]);

        string t1 = MGR.get_t("");
        string t2 = MGR.get_t("");

        irs += exp1->generate(t1);
        irs += exp2->generate(t2);

        irs += new IF_IR({t1, string(c[1]->text), t2, lb_t});
        irs += new GOTO_IR({lb_f});
    }
    if (node->type == NodeType::ExpPlus ||
        node->type == NodeType::ExpMinus ||
        node->type == NodeType::ExpMul ||
        node->type == NodeType::ExpDiv) {

        exp1 = new Exp(c[0]);
        exp2 = new Exp(c[2]);
        auto expr1 = exp1->expression, expr2 = exp2->expression;

        string t1 = MGR.get_t("");
        string t2 = MGR.get_t("");

        irs += exp1->generate(t1);
        irs += exp2->generate(t2);

        if (node->type == NodeType::ExpPlus) {
            irs += new ADD_IR({place, t1, t2});
        }
        if (node->type == NodeType::ExpMinus) {
            irs += new SUB_IR({place, t1, t2});
        }
        if (node->type == NodeType::ExpMul) {
            irs += new MUL_IR({place, t1, t2});
        }
        if (node->type == NodeType::ExpDiv) {
            irs += new DIV_IR({place, t1, t2});
        }
    }
    if (node->type == NodeType::ExpNegative) {
        string tp = MGR.get_t("");
        irs += exp1->generate(tp);
        irs += new SUB_IR({place, "#0", tp});
    }
    if (node->type == NodeType::ExpNot) {
        exp1->generate(place, {lb_f, lb_t});
    }
    if (node->type == NodeType::ExpBracketWrapped) {
        irs += exp1->generate(place);
    }
    if (node->type == NodeType::ExpArgsFuncCall ||
        node->type == NodeType::ExpFuncCall) {
        std::string func_name = idOf(c[0]);
        if (func_name == "read") {
            irs += new READ_IR({place});
        } else if (func_name == "write") {
            irs += args->generate();
            for (int i = 0; i < args->tags.size(); ++i) {
                irs += new WRITE_IR({args->tags[i]});
            }
        } else {
            if (args) {
                irs += args->generate();

                int len = args->tags.size();

                for (int i = len - 1; i >= 0; --i) {
                    auto field = args->fields[i];
                    auto tag = args->tags[i];

                    if (field->type->category == Category::PRIMITIVE) {
                        irs.push_back(new ARG_IR({tag}));
                    } else {
                        irs.push_back(new ARG_IR({"addr_" + tag}));
                    }
                }
            }
            irs += new CALL_IR({place, func_name});
        }
    }

    if (node->type == NodeType::ExpArrayIndex) {
// 存放数组地址
        string arrName = MGR.get_t("arr");
        irs += exp1->generate(arrName);

// 存放数组下标
        string idxName = MGR.get_t("idx");
        irs += exp2->generate(idxName);

        int space = spaceOf(exp1->expression->field->type->array->type);

// 计算地址
        string spaceName = MGR.get_t("size");
        irs += new MUL_IR({spaceName, idxName, "#" + std::to_string(space)});
        irs += new ADD_IR({"addr_" + place, "addr_" + arrName, spaceName});
        irs += new RDEREF_IR({place, "addr_" + place});
    }
    if (node->type == NodeType::ExpFieldAccess) {
        string structName = MGR.get_t("struct");
        irs += exp1->generate(structName);

        std::string field_name = idOf(c[2]);

        string fieldName = MGR.get_t(field_name);
        Field *s = exp1->expression->field;
        auto fields = s->type->structure->fields;

        int space = 0;
        for (auto field: fields) {
            if (field->name == field_name) {
                irs += new ADD_IR({"addr_" + place, "addr_" + structName, "#" + to_string(space)});
                irs += new RDEREF_IR({place, "addr_" + place});
                break;
            }
            space += spaceOf(field->type);
        }
    }
    if (node->type == NodeType::ExpId) {
        std::string var_name = idOf(c[0]);
        auto var_entry = SYMBOL_TABLE.find(var_name, EntryType::FIELD);
        tag_name = MGR.get_v(var_entry);
        if (MGR.isRef(var_entry)) {
            irs.push_back(new ASSIGN_IR({"addr_" + place, tag_name}));
        } else {
            irs.push_back(new REF_IR({"addr_" + place, tag_name}));
        }
        irs.push_back(new ASSIGN_IR({place, tag_name}));
    }
    if (node->type == NodeType::ExpInt) {
        irs.push_back(new ASSIGN_IR({std::move(place), "#" + std::string(c[0]->text)}));
    }
    if (node->type == NodeType::ExpChar) {
//        expression = new Expression{
//                new Field{new Type(Primitive::CHAR),
//                          node->lineno},
//                false};
    }
    if (node->type == NodeType::ExpFloat) {
//        expression = new Expression{
//                new Field{new Type(Primitive::FLOAT),
//                          node->lineno},
//                false};
    }
    return irs;
}
