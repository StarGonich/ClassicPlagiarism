#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>

using namespace std;

// Структура для хранения данных о транзакции
struct Transaction {
    int userId;
    int amount;
    string ip;
    string time; // Формат "HH:MM"
};

// Структура для профиля пользователя
struct UserProfile {
    int avgAmount;
    string typicalIp;
};

// Функция проверки, является ли транзакция подозрительной
bool isFraud(const Transaction& transaction, const UserProfile& profile) {
    // Проверка IP-адреса
    if (transaction.ip != profile.typicalIp) {
        return true;
    }

    // Проверка суммы (более чем в 3 раза превышает средний чек)
    if (transaction.amount > 3 * profile.avgAmount) {
        return true;
    }

    // Проверка времени (ночь — с 00:00 до 06:00)
    int hour = stoi(transaction.time.substr(0, 2));
    if (hour >= 0 && hour < 6) {
        return true;
    }

    return false; // Транзакция не подозрительная
}

int main() {
    // Пример входных данных (можно заменить на чтение из файла)
    vector<Transaction> transactions = {
        {1, 1000, "192.168.1.1", "08:00"},
        {1, 5000, "192.168.1.2", "03:00"},
        {2, 200, "10.0.0.1", "14:00"}
    };

    // Профили пользователей
    map<int, UserProfile> userProfiles = {
        {1, {800, "192.168.1.1"}},
        {2, {150, "10.0.0.1"}}
    };

    // Анализ транзакций
    for (const auto& transaction : transactions) {
        auto profileIt = userProfiles.find(transaction.userId);
        if (profileIt != userProfiles.end()) {
            if (isFraud(transaction, profileIt->second)) {
                cout << "Транзакция пользователя " << transaction.userId
                     << " (сумма: " << transaction.amount << ", IP: "
                     << transaction.ip << ", время: " << transaction.time
                     << ") — ФРОД" << endl;
            } else {
                cout << "Транзакция пользователя " << transaction.userId
                     << " (сумма: " << transaction.amount << ", IP: "
                     << transaction.ip << ", время: " << transaction.time
                     << ") — НЕ ФРОД" << endl;
            }
        } else {
            cout << "Профиль пользователя " << transaction.userId << " не найден!" << endl;
        }
    }

    return 0;
}
