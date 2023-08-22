#include <iostream>


#include "src/semantic_analysis/semantic_analysis.hpp"
#include "src/ir/ir_generator.hpp"
#include "syntax.tab.c"
#include "optimizer.hpp"
#include <fstream>

int main(int argc, char **argv) {
    char *filename = argv[1];

    FILE *fin = NULL;
    extern FILE *yyin;
    fin = fopen(filename, "r");

    if (fin == NULL) {
        printf("cannot open reading file.\n");
        return -1;
    }
    yyin = fin;
    /* yydebug = 1; */
    yyparse();
    fclose(fin);

    auto program = semantic_analysis(root_node);

    if (has_error()) {
        print_errors();
        return -1;
    }

    auto irs = program->generate();

    auto qwq = std::string(filename);
    auto qwqq = qwq.substr(0, qwq.length() - 4);

    std::ofstream out;
    auto opt_irs = optimize(irs);
    out.open(qwqq + ".ir");
    for (auto ir: opt_irs) {
        out << ir->str() << endl;
    }
    out.close();
    return 0;

}

