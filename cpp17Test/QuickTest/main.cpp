#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <sstream>


using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Test application\n";

    vector<string> result {};
    return a.exec();
}
