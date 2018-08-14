#include <QCoreApplication>
#include <QDebug>

#include <set>
#include <string>
#include <iomanip>
#include <iostream>
#include <functional>
#include <optional>
#include <any>
#include <utility>
#include <variant>
#include <cassert>
#include <fstream>
#include <filesystem>
#include <string_view>

namespace StructuredBindings {
int run()
{
    std::cout << "Structured Bindings Demo\n";

    std::set<std::string> myset;
    if (auto [iter, success] = myset.insert("Hello"); success)
        std::cout << "insert is successful. The value is " << std::quoted(*iter) << '\n';
    else
        std::cout << "The value " << std::quoted(*iter) << " already exists in the set\n";

    std::cout << "\n";
    return 0;
}
}

namespace Optional {
// optional can be used as the return type of a factory that may fail
std::optional<std::string> create(bool b) {
    if (b)
        return "Godzilla";
    return {};
}

// std::nullopt can be used to create any (empty) std::optional
auto create2(bool b) {
    return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
}

// std::reference_wrapper may be used to return a reference
auto create_ref(bool b) {
    static std::string value = "Godzilla";
    return b ? std::optional<std::reference_wrapper<std::string>>{value}
             : std::nullopt;
}

int run()
{
    std::cout << "Optional Demo\n";

    std::cout << "create(false) returned "
              << create(false).value_or("empty") << '\n';

    // optional-returning factory functions are usable as conditions of while and if
    if (auto str = create2(true)) {
        std::cout << "create2(true) returned " << *str << '\n';
    }

    if (auto str = create_ref(true)) {
        // using get() to access the reference_wrapper's value
        std::cout << "create_ref(true) returned " << str->get() << '\n';
        str->get() = "Mothra";
        std::cout << "modifying it changed it to " << str->get() << '\n';
    }

    std::cout << "\n";
    return 0;
}
}

namespace Any {
int run()
{
    std::cout << "Any Demo\n";

    // simple example
    auto a = std::any(12);

    std::cout << std::any_cast<int>(a) << '\n';

    try {
        std::cout << std::any_cast<std::string>(a) << '\n';
    }
    catch(const std::bad_any_cast& e) {
        std::cout << e.what() << '\n';
    }

    // advanced example

    a = std::string("hello");

    auto& ra = std::any_cast<std::string&>(a); //< reference
    ra[1] = 'o';

    std::cout << "a: "
        << std::any_cast<const std::string&>(a) << '\n'; //< const reference

    auto b = std::any_cast<std::string&&>(std::move(a)); //< rvalue reference

    // Note: 'b' is a move-constructed std::string,
    // 'a' is left in valid but unspecified state

    std::cout << "a: " << *std::any_cast<std::string>(&a) //< pointer
        << "b: " << b << '\n';

    std::cout << "\n";
    return 0;
}
}

namespace Variant {
using namespace std::literals;

int run()
{
    std::cout << "Variant Demo\n";

    std::variant<int, float> v, w;
    v = 12; // v contains int
    int i = std::get<int>(v);
    w = std::get<int>(v);
    w = std::get<0>(v); // same effect as the previous line
    w = v; // same effect as the previous line

//  std::get<double>(v); // error: no double in [int, float]
//  std::get<3>(v);      // error: valid index values are 0 and 1

    try {
      std::get<float>(w); // w contains int, not float: will throw
    }
    catch (const std::bad_variant_access&) {}

    std::variant<std::string> x("abc"); // converting constructors work when unambiguous
    x = "def"; // converting assignment also works when unambiguous

    std::variant<std::string, bool> y("abc"); // casts to bool when passed a char const *
    assert(std::holds_alternative<bool>(y)); // succeeds
    y = "xyz"s;
    assert(std::holds_alternative<std::string>(y)); //succeeds

    std::cout << "\n";
    return 0;
}
}

namespace MonoState {
struct S
{
    S(int i) : i(i) {}
    int i;
};

int run()
{
    std::cout << "MonoState Demo\n";

    // Without the monostate type this declaration will fail.
    // This is because S is not default-constructible.

    std::variant<std::monostate, S> var;

    // var.index() is now 0 - the first element
    // std::get<S> will throw! We need to assign a value

    var = 12;

    std::cout << std::get<S>(var).i << '\n';

    std::cout << "\n";
    return 0;
}
}

namespace FileSystems {
namespace fs = std::filesystem;

int run()
{
    std::cout << "FileSystems Demo\n";

    fs::create_directories("sandbox/a/b");
    std::ofstream("sandbox/file1.txt");
    std::ofstream("sandbox/file2.txt");
    for(auto& p: fs::directory_iterator("sandbox"))
        std::cout << p << '\n';
    fs::remove_all("sandbox");

    std::cout << "\n";
    return 0;
}
}

namespace StringView {
int run()
{
    std::cout << "StringView Demo\n";

    std::string_view str_view("abcd");

    auto begin = str_view.begin();
    auto cbegin = str_view.cbegin();

    std::cout << *begin << '\n';
    std::cout << *cbegin << '\n';

    std::cout << std::boolalpha << (begin == cbegin) << '\n';
    std::cout << std::boolalpha << (*begin == *cbegin) << '\n';

    std::cout << "\n";
    return 0;
}
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "C++17 Features Test ...\n";

    StructuredBindings::run();
    Optional::run();
    Any::run();
    Variant::run();
    MonoState::run();
    FileSystems::run();
    StringView::run();

    qDebug() << "\nEnd of C++17 Features Test\n";

    return a.exec();
}
