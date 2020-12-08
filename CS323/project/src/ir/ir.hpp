#include <vector>
#include <string>
#include <iostream>

class IR
{
public:
    std::vector<std::string> args;

    IR(std::vector<std::string> args)
    {
        this->args = args;
    }

    virtual std::string str()
    {
        return "nope";
    };
};

class IR_LABEL : public IR
{
public:
    IR_LABEL(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "LABEL " + args[0] + " :";
    }
};

class IR_FUNCTION : public IR
{
public:
    IR_FUNCTION(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "FUNCTION " + args[0] + " :";
    }
};
class IR_ASSIGN : public IR
{
public:
    IR_ASSIGN(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := " + args[1];
    }
};
class IR_ADD : public IR
{
public:
    IR_ADD(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := " + args[1] + " + " + args[2];
    }
};
class IR_SUB : public IR
{
public:
    IR_SUB(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := " + args[1] + " - " + args[2];
    }
};
class IR_MUL : public IR
{
public:
    IR_MUL(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := " + args[1] + " * " + args[2];
    }
};
class IR_DIV : public IR
{
public:
    IR_DIV(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := " + args[1] + " / " + args[2];
    }
};
class IR_REF : public IR
{
public:
    IR_REF(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := &" + args[1];
    }
};
class IR_RDEREF : public IR
{
public:
    IR_RDEREF(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := *" + args[1];
    }
};
class IR_LDEREF : public IR
{
public:
    IR_LDEREF(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "*" + args[0] + " := " + args[1];
    }
};
class IR_GOTO : public IR
{
public:
    IR_GOTO(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "GOTO " + args[0];
    }
};
class IR_IF : public IR
{
public:
    IR_IF(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "IF " + args[0] + " " + args[1] + " " + args[2] + " GOTO " + args[3];
    }
};
class IR_RET : public IR
{
public:
    IR_RET(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "RET " + args[0];
    }
};
class IR_DEC : public IR
{
public:
    IR_DEC(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "DEC " + args[0] + " " + args[1];
    }
};
class IR_PARAM : public IR
{
public:
    IR_PARAM(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "PARAM " + args[0];
    }
};
class IR_ARG : public IR
{
public:
    IR_ARG(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "ARG " + args[0];
    }
};
class IR_CALL : public IR
{
public:
    IR_CALL(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := " + "CALL " + args[1];
    }
};
class IR_READ : public IR
{
public:
    IR_READ(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "READ " + args[0];
    }
};
class IR_WRITE : public IR
{
public:
    IR_WRITE(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "WRITE " + args[0];
    }
};
