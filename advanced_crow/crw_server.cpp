#include "crow.h"
#include <iostream>
using namespace std;


// Just Function for generating random String
string generateRandomString(size_t length)
{
  const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const size_t charmapLength = strlen(charmap);
  auto generator = [&](){ return charmap[rand()%charmapLength]; };
  string result;
  result.reserve(length);
  generate_n(back_inserter(result), length, generator);
  return result;
}

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/ex_json")
    ([](const crow::request& req) {
        // Print all parameters
    std::cout << "Params:" << req.url_params << "\n\n";
    // Or you can print specific parameters
        //std::cout << req.url_params.get("foo") << "\n\n";
        // std::cout << req.url_params.get("pew") << "\n\n";

        // Return Json
        crow::json::wvalue x;
        x["success"] = 1;
        x["message"] = "Hello, World!";

        // get String
        if (req.url_params.get("foo") != nullptr){
            x["foo"] = req.url_params.get("foo");
        }

        // get integer:
        if (req.url_params.get("pew") != nullptr){
            x["pew_str"] = req.url_params.get("pew");
            x["pew_int_stoi"] = 3 + std::stoi(req.url_params.get("pew"));
            // cast to double and divide by 2:
            x["pew_double"] = atof(req.url_params.get("pew")) / 2;
        }

    // get double
    if (req.url_params.get("double_param") != nullptr){
	        x["double_param"] = atof( req.url_params.get("double_param") ) + 1;
    }

    // Get List from parameters
    auto array_strings = req.url_params.get_list("count");
    if (array_strings.size() > 0){
        // Convert array of Str to array of Int
        //int arrayOfIntegers[c];
        //for(int i = 0; i < c; i++) arrayOfIntegers[i] = std::stoi(array_strings[i]);
        x["list_str"] = array_strings;
    }



    // Return array
    x["arr1"][0] = 1;
    x["arr1"][1] = 3;
    x["arr1"][2] = 4;

    // You can even declare new parameter and assign not 0 element but 1
    x["arr2"][1] = 2;

        return crow::response(x);
    });

    CROW_ROUTE(app, "/ex_json_arr")([]() {
    crow::json::wvalue x;
    std::vector<int> ids = {1,2,3};
    std::vector<string> names = {"test1", "test2", "test3"};
    size_t i;

    for (i = 0; i < ids.size(); ++i) {
         x["arr_int"][i] = ids.at(i);
         // x[i]["name"] = names.at(i);
    }
    for (i = 0; i < ids.size(); ++i) {
         x["arr_str"][i] = generateRandomString(4);
         // x[i]["name"] = names.at(i);
    }
    x["name"] = "ABC";
    return crow::response(x);
});
	
    app.port(18080).run();
}
