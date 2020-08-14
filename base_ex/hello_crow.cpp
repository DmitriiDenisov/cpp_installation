#include "crow.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/hi")
    ([]() {
        return "Hello world!";
    });

    app.port(18080).run();
}
