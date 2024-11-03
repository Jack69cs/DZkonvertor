#include <iostream>
#include <iomanip>

const double COMMISSION_RATE = 0.05; // 5% комиссия
const double USD_EXCHANGE_RATE = 0.013; // Курс доллара
const double EUR_EXCHANGE_RATE = 0.012; // Курс евро
const double CNY_EXCHANGE_RATE = 0.087; // Курс юаня
const double JPY_EXCHANGE_RATE = 1.45;   // Курс йены
const double FRT_EXCHANGE_RATE = 0.37;   // Курс фарита

void displayExchangeOptions() {
    std::cout << "Выберите валюту для обмена:\n";
    std::cout << "1. Доллар\n";
    std::cout << "2. Евро\n";
    std::cout << "3. Юань\n";
    std::cout << "4. Фарит\n";
    std::cout << "5. Йена\n";
}

double convertCurrency(double amount, int currencyChoice) {
    double exchangeRate = 0.0;

    switch (currencyChoice) {
    case 1:
        exchangeRate = USD_EXCHANGE_RATE;
        break;
    case 2:
        exchangeRate = EUR_EXCHANGE_RATE;
        break;
    case 3:
        exchangeRate = CNY_EXCHANGE_RATE;
        break;
    case 4:
        exchangeRate = FRT_EXCHANGE_RATE;
        break;
    case 5:
        exchangeRate = JPY_EXCHANGE_RATE;
        break;
    default:
        std::cout << "Неверный выбор валюты.\n";
        return 0.0;
    }

    double commission = amount * COMMISSION_RATE;
    double totalAmountAfterCommission = amount - commission;
    double convertedAmount = totalAmountAfterCommission * exchangeRate;

    std::cout << "Сумма комиссии: " << std::fixed << std::setprecision(2) << commission << " рублей\n";
    return convertedAmount;
}

int main() {
    setlocale(LC_ALL, "RU");
    double rubles;
    int currencyChoice;
    char repeat;

    do {
        std::cout << "Введите количество рублей для обмена: ";
        std::cin >> rubles;

        displayExchangeOptions();
        std::cout << "Введите номер валюты для обмена: ";
        std::cin >> currencyChoice;

        double result = convertCurrency(rubles, currencyChoice);
        if (result > 0) {
            std::cout << "Вы получили: " << std::fixed << std::setprecision(2) << result << " валюты.\n";
        }

        std::cout << "Хотите повторить операцию? (y/n): ";
        std::cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    std::cout << "Спасибо за использование конвертера валют!\n";
    return 0;
}
