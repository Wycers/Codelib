#include <iostream>
#include "UTF8string.hpp"

using namespace std;

static void func(UTF8string u) {
    // Function to make sure that nothing crashes
    cout << "Testing operator !: " << u << " -> " << !u << endl;
}

int main() {
    // 
    // Expected output:
    // ---------------
    // test contains: Mais où sont les neiges d'antan?
    // length in bytes of test: 33
    // number of characters (one 2-byte character): 32
    // position of "sont": 8
    // test2 before replacement: Всё хорошо́, что хорошо́ конча́ется
    // test2 after replacement: Всё просто, что просто конча́ется
    // test + test2: Mais où sont les neiges d'antan?Всё просто, что просто конча́ется
    // Appending !!! to test
    // Result: Mais où sont les neiges d'antan?!!!
    // Testing operator *: hip hip hip hurray
    // Testing operator !: Никола́й Васи́льевич Го́голь -> ьлоѓоГ чивеьл́исаВ й́алокиН
    //
    UTF8string test = UTF8string("Mais où sont les neiges d'antan?");
    UTF8string test2 = UTF8string("Всё хорошо́, что хорошо́ конча́ется");
    UTF8string test3("hip ");
    UTF8string test4("Никола́й Васи́льевич Го́голь");
    cout << "test contains: " << test << endl;
    cout << "length in bytes of test: " << test.bytes() << endl;
    cout << "number of characters (one 2-byte character): " << test.length() << endl;
    cout << "position of \"sont\": " << test.find("sont") << endl;
    cout << "test2 before replacement: " << test2 << endl;
    test2.replace("хорошо́", "просто");
    cout << "test2 after replacement: " << test2 << endl;
    cout << "test + test2: " << test + test2 << endl;
    cout << "Appending !!! to test" << endl;
    test += UTF8string("!!!");
    cout << "Result: " << test << endl;
    cout << "Testing operator *: " << test3 * 3 << "hurray" << endl;
    func(test4);
    return 0;
}
