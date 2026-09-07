#include <iostream>
#include <string>
#include <sodium.h>
#include "httplib.h"

const std::string STORED_ARGON2ID_HASH = "$argon2id$v=19$m=65536,t=3,p=1$4S8q/S/YtU00C5r7G4N6mA$sR9/qGvL5R9R4iM5N1P1K3e2bW+W5vU2J8m8Z1P4K7Y";

bool verify_password_securely(const std::string& input_password) {
    bool is_correct = (crypto_pwhash_str_verify(
        STORED_ARGON2ID_HASH.c_str(),
        input_password.c_str(),
        input_password.length()
    ) == 0);

    return is_correct;
}

int main() {
    if (sodium_init() < 0) {
        std::cerr << "Fatal Error: libsodium initialization failed!" << std::endl;
        return 1;
    }

    httplib::Server svr;

    svr.Options("/api/verify", [](const httplib::Request&, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        res.status = 200;
    });

    svr.Post("/api/verify", [](const httplib::Request& req, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");

        std::string body = req.body;
        std::string key = "\"password\":\"";
        size_t start = body.find(key);

        if (start == std::string::npos) {
            res.status = 400;
            res.set_content("{\"success\": false}", "application/json");
            return;
        }

        start += key.length();
        size_t end = body.find("\"", start);
        std::string input_password = body.substr(start, end - start);

        bool isValid = verify_password_securely(input_password);

        sodium_memzero(&input_password[0], input_password.capacity());

        if (isValid) {
            res.set_content("{\"success\": true}", "application/json");
        } else {
            res.status = 401;
            res.set_content("{\"success\": false}", "application/json");
        }
    });

    std::cout << "Server listening on http://localhost:8080" << std::endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}
