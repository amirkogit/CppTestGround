#include <QCoreApplication>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Test application\n";

    return a.exec();
}
