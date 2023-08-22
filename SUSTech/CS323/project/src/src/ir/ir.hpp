#pragma once

#include <vector>
#include <string>
#include <iostream>

enum IRType {
    IR_LABEL,
    IR_FUNCTION,
    IR_ASSIGN,
    IR_ADD,
    IR_SUB,
    IR_MUL,
    IR_DIV,
    IR_REF,
    IR_RDEREF,
    IR_LDEREF,
    IR_GOTO,
    IR_IF,
    IR_RET,
    IR_DEC,
    IR_PARAM,
    IR_ARG,
    IR_CALL,
    IR_READ,
    IR_WRITE
};


struct IR {
    std::vector<std::string> args;
    IRType irType;

    IR(std::vector<std::string> args, IRType type) {
        this->args = args;
        this->irType = type;
    }

    virtual std::string str() {
        return "nope";
    };
};

struct LABEL_IR : public IR {
    std::string dst;

    LABEL_IR(std::vector<std::string> args) : IR(args, IRType::IR_LABEL) {
        dst = args[0];
    }

    virtual std::string str() {
        return "LABEL " + dst + " :";
    }
};

struct FUNCTION_IR : public IR {
    std::string function_name;

    FUNCTION_IR(std::vector<std::string> args) : IR(args, IRType::IR_FUNCTION) {
        function_name = args[0];
    }

    virtual std::string str() {
        return "FUNCTION " + function_name + " :";
    }
};

struct ASSIGN_IR : public IR {
    ASSIGN_IR(std::vector<std::string> args) : IR(args, IRType::IR_ASSIGN) {}

    virtual std::string str() {
        return args[0] + " := " + args[1];
    }
};

struct ADD_IR : public IR {
    ADD_IR(std::vector<std::string> args) : IR(args, IRType::IR_ADD) {}

    virtual std::string str() {
        return args[0] + " := " + args[1] + " + " + args[2];
    }
};

struct SUB_IR : public IR {
    SUB_IR(std::vector<std::string> args) : IR(args, IRType::IR_SUB) {}

    virtual std::string str() {
        return args[0] + " := " + args[1] + " - " + args[2];
    }
};

struct MUL_IR : public IR {
    MUL_IR(std::vector<std::string> args) : IR(args, IRType::IR_MUL) {}

    virtual std::string str() {
        return args[0] + " := " + args[1] + " * " + args[2];
    }
};

struct DIV_IR : public IR {
    DIV_IR(std::vector<std::string> args) : IR(args, IRType::IR_DIV) {}

    virtual std::string str() {
        return args[0] + " := " + args[1] + " / " + args[2];
    }
};

struct REF_IR : public IR {
    REF_IR(std::vector<std::string> args) : IR(args, IRType::IR_REF) {}

    virtual std::string str() {
        return args[0] + " := &" + args[1];
    }
};

struct RDEREF_IR : public IR {
    RDEREF_IR(std::vector<std::string> args) : IR(args, IRType::IR_RDEREF) {}

    virtual std::string str() {
        return args[0] + " := *" + args[1];
    }
};

struct LDEREF_IR : public IR {
    LDEREF_IR(std::vector<std::string> args) : IR(args, IRType::IR_LDEREF) {}

    virtual std::string str() {
        return "*" + args[0] + " := " + args[1];
    }
};

struct GOTO_IR : public IR {
    std::string target;

    GOTO_IR(std::vector<std::string> args) : IR(args, IRType::IR_GOTO) {
        target = args[0];
    }

    virtual std::string str() {
        return "GOTO " + target;
    }
};

struct IF_IR : public IR {
    std::string target;

    IF_IR(std::vector<std::string> args) : IR(args, IRType::IR_IF) {
        target = args[3];
    }

    virtual std::string str() {
        return "IF " + args[0] + " " + args[1] + " " + args[2] + " GOTO " + target;
    }
};

struct RET_IR : public IR {
    RET_IR(std::vector<std::string> args) : IR(args, IRType::IR_RET) {}

    virtual std::string str() {
        return "RETURN " + args[0];
    }
};

struct DEC_IR : public IR {
    DEC_IR(std::vector<std::string> args) : IR(args, IRType::IR_DEC) {}

    virtual std::string str() {
        return "DEC " + args[0] + " " + args[1];
    }
};

struct PARAM_IR : public IR {
    PARAM_IR(std::vector<std::string> args) : IR(args, IRType::IR_PARAM) {}

    virtual std::string str() {
        return "PARAM " + args[0];
    }
};

struct ARG_IR : public IR {
    ARG_IR(std::vector<std::string> args) : IR(args, IRType::IR_ARG) {}

    virtual std::string str() {
        return "ARG " + args[0];
    }
};

struct CALL_IR : public IR {
    CALL_IR(std::vector<std::string> args) : IR(args, IRType::IR_CALL) {}

    virtual std::string str() {
        return args[0] + " := " + "CALL " + args[1];
    }
};

struct READ_IR : public IR {
    READ_IR(std::vector<std::string> args) : IR(args, IRType::IR_READ) {}

    virtual std::string str() {
        return "READ " + args[0];
    }
};

struct WRITE_IR : public IR {
    WRITE_IR(std::vector<std::string> args) : IR(args, IRType::IR_WRITE) {}

    virtual std::string str() {
        return "WRITE " + args[0];
    }
};


typedef std::vector<IR *> IRList;
