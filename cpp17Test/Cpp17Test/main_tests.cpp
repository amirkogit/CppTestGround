//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

// System includes
#include <QtCore>
#include <QDebug>

int main( int argc, char* argv[] )
{
    QCoreApplication a(argc, argv);

    int result = Catch::Session().run( argc, argv );

    qDebug() << "End of test, result = " << result;

    return ( result < 0xff ? result : 0xff );
}
