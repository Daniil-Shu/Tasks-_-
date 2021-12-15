#include <iostream>

using namespace std;

void output(double value, const string& message);

void ouputWalletMessage(const string& message);

double converter(const int choice, double value, const int wallet);

enum class currency
{
	Rubles,
	Dollars,
	Euro,
	Krone,
	Yuan
};

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите сумму: ";
	double value;
	cin >> value;
	if (value < 0)
	{
		cout << "Сумма не может быть отрицательной.";
		return 0;
	}

	ouputWalletMessage("Введите номер для выбора валюты введенной суммы:\n");
	int choiсe;
	cin >> choiсe;

	ouputWalletMessage("Введите номер валюты в которую хотите конвертировать:\n");
	int wallet;
	cin >> wallet;

	const auto chosen = static_cast<currency>(wallet);
	switch (chosen) {
	case currency::Rubles:
	{

		output(converter(choiсe, value, wallet), "Ваша сумма по курсу рубля: ");
		break;
	}
	case currency::Dollars:
	{
		output(converter(choiсe, value, wallet), "Ваша сумма по курсу доллара: ");
		break;
	}
	case currency::Euro:
	{
		output(converter(choiсe, value, wallet), "Ваша сумма по курсу евро: ");
		break;
	}
	case currency::Krone:
	{
		output(converter(choiсe, value, wallet), "Ваша сумма по курсу кроны: ");
		break;
	}
	case currency::Yuan:
	{
		output(converter(choiсe, value, wallet), "Ваша сумма по курсу юаня: ");
		break;
	}
	default:
	{
		cout << "Некоректный ввод.";
		return 0;
	}
	}

}

void output(double value, const string& message)
{
	cout << message << value;
}

void ouputWalletMessage(const string& message)
{
	cout << message
		<< static_cast<int>(currency::Rubles) << " - для выбора рубля\n"
		<< static_cast<int>(currency::Dollars) << " - для выбора доллара\n"
		<< static_cast<int>(currency::Euro) << " - для выбора евро\n"
		<< static_cast<int>(currency::Krone) << " - для выбора кроны\n"
		<< static_cast<int>(currency::Yuan) << " - для выбора юаня\n";
}

double converter(const int choice, double value, const int wallet)
{
	const double convRubIntoEuro = 0.012, convRubIntoDoll = 0.014, convRubIntoKrone = 0.30, convRubIntoYuan = 0.086;
	const double convDollIntoRub = 73.80, convDollIntoEuro = 0.89, convDollIntoKrone = 22.47, convDollIntoYuan = 6.37;
	const double convEuroIntoRub = 83.10, convEuroIntoDoll = 1.13, convEuroIntoKrone = 25.30, convEuroIntoYuan = 7.17;
	const double convKroneIntoRub = 3.29, convKroneIntoDoll = 0.044, convKroneIntoEuro = 0.040, convKroneIntoYuan = 0.96;
	const double convYuanIntoRub = 11.60, convYuanIntoDoll = 0.16, convYuanIntoEuro = 0.14, convYuanIntoKrone = 3.53;
	if (choice == wallet)
		return value;
	else
	{
		const auto chosen = static_cast<currency>(choice);
		switch (chosen) {
		case currency::Rubles:
		{
			if (wallet == static_cast<int>(currency::Dollars))
				return value *= convRubIntoDoll;
			else if (wallet == static_cast<int>(currency::Euro))
				return value *= convRubIntoEuro;
			else if (wallet == static_cast<int>(currency::Krone))
				return value *= convRubIntoKrone;
			else
				return value *= convRubIntoYuan;
		}
		case currency::Dollars:
		{
			if (wallet == static_cast<int>(currency::Rubles))
				return value *= convDollIntoRub;
			else if (wallet == static_cast<int>(currency::Euro))
				return value *= convDollIntoEuro;
			else if (wallet == static_cast<int>(currency::Krone))
				return value *= convDollIntoKrone;
			else
				return value *= convDollIntoYuan;
		}
		case currency::Euro:
		{
			if (wallet == static_cast<int>(currency::Rubles))
				return value *= convEuroIntoRub;
			else if (wallet == static_cast<int>(currency::Dollars))
				return value *= convEuroIntoDoll;
			else if (wallet == static_cast<int>(currency::Krone))
				return value *= convEuroIntoKrone;
			else
				return value *= convEuroIntoYuan;
			break;
		}
		case currency::Krone:
		{
			if (wallet == static_cast<int>(currency::Rubles))
				return value *= convKroneIntoRub;
			else if (wallet == static_cast<int>(currency::Dollars))
				return value *= convKroneIntoDoll;
			else if (wallet == static_cast<int>(currency::Euro))
				return value *= convKroneIntoEuro;
			else
				return value *= convKroneIntoYuan;
			break;
		}
		case currency::Yuan:
		{
			if (wallet == static_cast<int>(currency::Rubles))
				return value *= convYuanIntoRub;
			else if (wallet == static_cast<int>(currency::Dollars))
				return value *= convYuanIntoDoll;
			else if (wallet == static_cast<int>(currency::Euro))
				return value *= convYuanIntoEuro;
			else
				return value *= convYuanIntoKrone;
			break;
		}
		}
	}

}