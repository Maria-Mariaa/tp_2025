#include "Dictionary.h"
#include "utils.h"
#include <stdexcept>

void Dictionary::insert(const std::string& key, const std::string& translation) {
    if (key.empty() || isBlank(key)) {
        throw std::invalid_argument("Key cannot be empty or whitespace-only");
    }
    if (translation.empty() || isBlank(translation)) {
        throw std::invalid_argument("Translation cannot be empty or whitespace-only");
    }

    auto it = data.find(key);
    if (it != data.end()) {
        it->second.insert(translation); // ��������� �������
    } else {
        data[key] = {translation};      // ������ ����� ������
    }
}

std::set<std::string> Dictionary::search(const std::string& key) const {
    if (key.empty() || isBlank(key)) {
        throw std::invalid_argument("Key cannot be empty or whitespace-only");
    }

    auto it = data.find(key);
    if (it != data.end()) {
        return it->second; // ���������� ��� ��������
    }
    return {}; // ������ ��������� � ���� �� ������
}

bool Dictionary::remove(const std::string& key) {
    if (key.empty() || isBlank(key)) {
        throw std::invalid_argument("Key cannot be empty or whitespace-only");
    }

    if (data.erase(key) > 0) {
        return true;
    }
    return false; // ���� �� ������
}
