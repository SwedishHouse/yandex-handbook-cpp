#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <sstream>  // Для std::istringstream
#include <list>
#include <utility>
#include <unordered_map>
#include <iterator>
#include <cassert>
#include <set>
#include <map>
#include <unordered_map>
#include <stdexcept>
#include <cassert>
#include <stack>
#include <string_view>
#include <numeric>


namespace Basics
{
	class FirstSteps
	{
	public:
		void a(void);
		void b(int a, int b);

	};

	class DataTypes
	{
	public:
		double a(double);
		unsigned long long int b(unsigned long long int);
	};

	class BranchesAndCycles
	{

	private:
		bool is_a_leap_year(int year);

	public:
		std::string a(int, int, int, int);
		std::string b(int, int, int);
		std::string c(int);
		int d(int, int);
		void e(int, int);
		int f(int);
		double g(int);

	};

	class VectorsAndStrings
	{
	public:
		std::string a(const std::string&);
		std::string b(const std::string&);
		std::vector<unsigned int> c(const std::vector<unsigned int>&);
		std::vector<std::string> d(std::vector<std::string>&);
		const std::string e(const std::string&);
		std::string f(size_t, size_t, size_t, const std::vector<std::vector<unsigned int>>&);
	};

	class Functions
	{
	public:
		//Функция возвращает пару из индексов максимального элемента в матрице.
		// Если максимальных элементов несколько, то возвращает наименьшую такую пару.
		std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix);

		//Напишите функцию для вычисления наибольшего общего префикса строк, переданных в векторе words:
		std::string CommonPrefix(const std::vector<std::string>& words);

		//Функция должна вернуть вектор строк, полученный разбиением строки str на части по указанному символу-разделителю delimiter.
		// Если разделитель встретился в начале или в конце строки str, то в начале (соответственно, в конце) вектора с результатом должна быть пустая строка.
		// Если два разделителя встретились рядом, то пустая строка между ними тоже должна попасть в ответ.
		// Для пустой строки надо вернуть вектор, содержащий одну пустую строку.
		//Например, Split("What_is_your_name?", '_') должна вернуть вектор из строк What, is, your и name ? .
		std::vector<std::string> Split(const std::string& str, char delimiter);

		//Функция должна вернуть строку, полученную склейкой элементов вектора через указанный разделитель. 
		// Например, Join({"What", "is", "your", "name?"}, '_') должна вернуть строку "What_is_your_name?".
		std::string Join(const std::vector<std::string>& tokens, char delimiter);

		// Напишите функцию, которая возвращает транспонированную матрицу:
		std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix);

		//Вам даны координаты точек на плоскости.
		// Выведите эти точки в порядке возрастания расстояний до начала координат.
		//Формат ввода
		// Сначала задано количество точек n.Затем идет последовательность из n строк, 
		// каждая из которых содержит два целых числа — координаты точки.
		// Величина	n не превосходит 100. Координаты точек по модулю не превосходят 1000.
		void F(std::vector<std::pair<int, int>>& coords);
	};
};

// Задачи из главы 3. Стандартная библиотека C++
namespace HandbookSTL
{
	// https://education.yandex.ru/handbook/cpp/article/sequence-containers
	class SequenceContainers
	{
	public:
		// Шаблонный Print
		// функция Print, которая умеет печатать в поток std::cout элементы 
		// переданного контейнера через указанную строку - разделитель
		template<typename T>
		inline void Print(const T& data,
			const std::string delimiter)
		{
			auto iter = data.cbegin();

			std::cout << *iter;
			iter++;
			while (iter != data.cend())
			{
				std::cout << delimiter;
				std::cout << *iter;
				iter++;
			}
			std::cout << std::endl;
		};

		// Проверка работ
		std::vector<std::string> B(const std::vector <std::pair<std::string,
			std::string>> &students, const std::vector<int>& numbers);
		// Вагоны
		void MakeTrain();
		// Ctrl+X, Ctrl+V
		std::list<std::string> CtrlXV(const std::vector<std::string> &text, 
			const std::vector<std::string> &commands);
		// Ctrl+X, Ctrl+V - 2
		static std::list<std::string> CtrlXV2(const std::vector<std::string>& text,
			const std::vector<std::string>& commands);
	};

	// https://education.yandex.ru/handbook/cpp/article/associative-containers
	class AssociationContainers
	{
	public:
		// На вход подаётся последовательность целых чисел. 
		// Для каждого числа выведите в отдельной строке слово YES,
		// если это число ранее встречалось в последовательности,
		// и NO, если не встречалось.
		std::vector<std::string> A(const std::vector<int>& arr);

		// Вам даны слова. Выведите в алфавитном порядке список общих букв всех слов.
		std::string B(const std::vector<std::string>& words);

		//Дан список всех файлов в некоторой файловой системе.
		// Необходимо вывести все непустые директории этой файловой системы в лексикографическом порядке.
		std::set<std::string> C(const std::vector<std::string> &pathes);

		// Профессор написал научную книгу и составил для неё предметный указатель.
		// Это список ключевых слов, для каждого из которых указана страница, на которой это слово встречается.
		// Теперь профессор хочет для каждой страницы выписать в алфавитном порядке все ключевые слова, 
		// которые на эту страницу попали (если такие вообще есть). 
		// Помогите профессору решить эту задачу.
		std::map<int, std::set<std::string>> D(const std::vector< std::pair<int, std::string>>& input);

		// Будем называть символьной n - граммой последовательность из n последовательно идущих символов в одном слове в тексте.
		// Для данного числа n подсчитайте суммарное количество каждой n - граммы в тексте.
		std::vector<std::pair<std::string, int>> E(const std::vector<std::string> &words, const int gramm_length);

	};

	class Algorithms
	{
	public:
		template <typename T>
		void Duplicate(std::vector<T>& v) {
			const size_t size = v.size();
			v.reserve(2 * size);
			auto start = v.cbegin();
			auto end = start + size;
			for (auto it = start; it != end; ++it) {
				v.push_back(*it);
			}
		};

		template <typename Iter>
		Iter Unique(Iter first, Iter last)
		{
			auto it1 = first, it2 = first;
			while (it2 != last)
			{
				if (it1 != it2)
					*it1 = std::move(*it2);
				
				++it1;

				const auto& value = *it2;
				while (it2 != last && *it2 == value)
					++it2;
 			}
			return it1;
		};

		// Реализуйте функцию SetDifference, которая принимает на вход два отсортированных по возрастанию диапазона
		template <typename InIter1, typename InIter2, typename OutIter>
		OutIter SetDifference(InIter1 first1, InIter1 last1,
			InIter2 first2, InIter2 last2,
			OutIter out)
		{
			while (first1 != last1)
			{
				if (first2 == last2)
				{
					*out = *first1;
					out++;
					first1++;
					continue;
				}
				
				if (*first1 < *first2)
				{
					// Данное значение точно есть в первом множестве
					*out = *first1;
					out++;
					first1++;	
					continue;
				}

				if (*first2 < *first1)
				{
					// Значения из второго множества точно нет в первом
					first2++;
					continue;
				}

				if (*first1 == *first2)				
				{
					// Данную пару не рассматриваем для записи
					first1++;
					first2++;
				}
			}
			return out;
		}

		// D: Приближённый двоичный поиск
		// В первой строке входных данных содержатся натуральные числа n и k,
		// не превосходящие 100000. Во второй строке задаются n целых чисел первого массива,
		// отсортированного по неубыванию, а в третьей строке – k целых чисел второго массива.
		// Каждое число в обоих массивах по модулю не превосходит 2⋅10^9. Второй массив,
		// в отличие от первого, не отсортирован.

		template <typename InIter>
		int D(InIter start, InIter end, int number)
		{
			// Защита от неправильный данных
			if (start == end)
				throw std::logic_error("Start equal end iterator!");

			auto it = std::lower_bound(start, end, number);

			if (it == end)
			{
				--it;
				return *it;
			}

			const int value_right = *it;

			while (it != end && it != start && *it == value_right)
				it--;

			const int value_left = *it;

			// Проверяем дистанцию до результатов
			if (value_right - number < number - value_left)
				return value_right;
			else
				return value_left;
		}
	};

	class Adapters
	{
	public:
		// На вход подаётся скобочная последовательность — строка, которая состоит из скобок ()[]{}.
		// Вам нужно определить, является ли она правильной. 
		// В правильной скобочной последовательности каждой открывающей скобке соответствует закрывающая и 
		// пары скобок корректно вложены друг в друга.
		std::string A(const std::string line);

		std::vector<int> B(const std::vector<int> &values, size_t k);

		std::string C(const std::string line);

		//Вам надо написать функцию NextToken для выделения очередного токена в строке.
		//Токеном считается последовательность символов до указанного символа-разделителя (или до конца строки).
		bool NextToken(std::string_view& sv, const char del, std::string_view &out);
		
		// Выведите k самых частотных слов текста и их частоты.
		std::vector<std::pair<int, std::string>> E(const std::vector<std::string>& lines, const int k);
		
	};

};

// Задачи из главы 4. Идиомы C++
namespace HandbookIdioms
{
	// Задачи из раздела https://education.yandex.ru/handbook/cpp/article/classes
	// Note: для некоторых задач надо написать классы с одинаковыми именами
	// Для простоты тестирования оберну их в отдельное простанство имен
	namespace TaskA
	{
		// Задача А
		// Вам надо написать класс Date для хранения даты григорианского календаря. 
		// Используйте три переменных типа int для хранения дня, месяца и года.
		// В вашем классе должен быть следующий публичный интерфейс:
		// Конструктор, принимающий на вход три числа : день, месяц и год.
		// В случае некорректной даты должна создаваться дата 1 января 1970 года
		// Константные функции GetDay, GetMonth и GetYear.
		// Бинарные операторы + и - , где вторым аргументом является целое число — количество дней.
		// Эти операторы должны вернуть новую дату, отстоящую от заданной на указанное число дней.
		// Бинарный оператор - , вычисляющий разность между двумя датами и возвращающий int – количество дней.
		// Считайте, что все обрабатываемые даты будут лежать в пределах от 1 января 1970 года до 31 декабря 2099 года.
		// Сдайте в систему только код класса Date без функции main.
		class Date
		{
		public:
			// Перечисление месяцев
			typedef enum : int
			{
				JANUARY = 1,
				FEBRARY,
				MARCH,
				APRIL,
				MAY,
				JUNE,
				JULY,
				AUGUST,
				SEPTEMBER,
				OCTOBER,
				NOVEMBER,
				DECEMBER
			} months_e;

			// Конструктор по умолчанию
			Date()
			{
				set_from_days(this->DAY_MIN);
			};

			// Конструктор с параметрами
			Date(int day, int month, int year) : Date()
			{
				// Проверяем полученные значения на попадания в диапазон
				if (!is_coorect_date(year, month, day))
					return;

				// Дополнительная проверка для високосного года
				if (day == this->FEBRARY && day > get_days_in_february(year))
					return;

				// Обновим значения
				this->day = day;
				this->month = month;
				this->year = year;
			}


			// Public getters
			int GetDay() const { return day; };
			int GetMonth() const { return static_cast<int>(month); };
			int GetYear() const { return year; };

			// Operators
			Date operator+ (int days) const
			{
				Date res(*this);

				res.set_from_days(res.get_days_count() + days);

				return res;
			}

			Date operator - (int k) const {
				Date result(*this);
				result.set_from_days(result.get_days_count() - k);
				return result;
			}

			int operator - (const Date& other) const {
				return get_days_count() - other.get_days_count();
			}

			// Public constants
			static const int YEAR_MIN = 1970;
			static const int YEAR_MAX = 2099;
			static const int DAY_MIN = 1;
			static const int DAY_FEBRUARY_USUAL = 28;
			static const int DAY_FEBRUARY_LEAP = DAY_FEBRUARY_USUAL + 1;
			static const int DAY_MAX = 31;
			static const int DAYS_IN_YEAR_WITHOUT_FEB = 337;

		private:
			// Переменная для хранения текущего года
			int year;
			// Текущий месяц
			int month;
			// Текущий день
			int day;

			// Определяет, високосный ли год
			bool is_a_leap_year(int year) const
			{
				if (year % 400 == 0)
					return true;
				else if (year % 100 == 0)
					return false;
				else if (year % 4 == 0)
					return true;
				else
					return false;
			}

			// Ставит дату по количеству дней
			void set_from_days(int in_days)
			{
				// Установим значения года и месяца по умолчанию
				this->year = this->YEAR_MIN;
				this->month = JANUARY;

				// Обрабатываем случай превышения входного количества дней 
				// по сравнению в количеством дней в году
				while (in_days > days_in_a_year(this->GetYear()))
				{
					// Уменьшим входное количество дней
					in_days -= days_in_a_year(this->GetYear());
					// Инкремент года
					this->year++;
				}

				// Обрабатываем случай превышения входного количества дней 
				// по сравнению в количеством дней в месяце
				while (in_days > days_passed_to_month(this->GetYear(), this->GetMonth() + 1))
				{
					// Инкремент месяца
					this->month++;
				}

				// Обновим количество дней
				this->day = in_days - days_passed_to_month(this->GetYear(), this->GetMonth());
			}

			// Проверка, корректная ли дата
			bool is_coorect_date(int year, int month, int day) const
			{
				return	year >= this->YEAR_MIN && year <= this->YEAR_MAX &&
					month >= JANUARY && month <= DECEMBER &&
					day >= this->DAY_MIN && day <= this->DAY_MAX;
			}

			// Опредлеяпет коилчество дней в феврале
			int get_days_in_february(int year) const
			{
				if (is_a_leap_year(year))
					return this->DAY_FEBRUARY_LEAP;

				return this->DAY_FEBRUARY_USUAL;
			}

			// Определяет количество дней в месяце
			int get_days_in_month(int year, int m) const
			{
				switch (m)
				{
				case FEBRARY:
					return get_days_in_february(year);

				case JANUARY:
				case MARCH:
				case MAY:
				case JULY:
				case AUGUST:
				case OCTOBER:
				case DECEMBER:
					return 31;

				default:
					return 30;
				}
			}

			// Определим количество дней с начала года в целых месяцах
			int days_passed_to_month(int year, int month) const
			{
				int days = 0;
				for (int i = JANUARY; i < month; ++i)
				{
					// Прибавляем количество дней месяца 
					days += get_days_in_month(year, i);
				}

				// Возвращаем результат
				return days;
			}

			// Определяет количество дней в году
			int days_in_a_year(int year) const
			{
				return DAYS_IN_YEAR_WITHOUT_FEB + get_days_in_february(year);
			}

			// Определяем количество дней с начальной даты
			int get_days_count() const
			{
				int result = 0;

				for (int i = this->YEAR_MIN; i < GetYear(); ++i)
				{
					result += days_in_a_year(i);
				}

				return this->day + result + days_passed_to_month(GetYear(), GetMonth());
			}

		}; // End Class Date

	}; // End namespace Task A

	namespace TaskB
	{
		// Задача B
		/*
		Вам надо переделать реализацию класса Date из предыдущей задачи,
		сохранив публичный интерфейс неизменным. Теперь для хранения даты
		используйте одну переменную типа int — количество дней,
		прошедших с некоторого начала отсчёта.
		Считайте, что все обрабатываемые даты будут лежать в пределах
		от 1 января 1970 года до 31 декабря 2099 года.
		Сдайте в систему только код класса Date без функции main.
		*/
		class Date
		{
		public:
			// Перечисление месяцев
			typedef enum : int
			{
				JANUARY = 1,
				FEBRARY,
				MARCH,
				APRIL,
				MAY,
				JUNE,
				JULY,
				AUGUST,
				SEPTEMBER,
				OCTOBER,
				NOVEMBER,
				DECEMBER
			} months_e;

			// Конструктор по умолчанию
			Date(void) : days(1) {}

			// Конструктор с параметрами
			Date(int day, int month, int year) : days(0)
			{
				// Проверяем полученные значения на попадания в диапазон
				if (!is_coorect_date(year, month, day))
				{
					day = 1;
					month = this->JANUARY;
					year = this->YEAR_MIN;
				}

				// Проитерируем по годам
				for (int i = this->YEAR_MIN; i < year; i++)
				{
					// Заполняем количетсвом дней в годах
					this->days += days_in_a_year(i);
				}

				// Проитерируем по месяцам
				for (int i = this->JANUARY; i < month; i++)
				{
					// Заполняем количетсвом дней в годах
					this->days += get_days_in_month(year, i);
				}

				// Добавим количество дней
				this->days += day;
			}


			// Public getters
			int GetDay() const 
			{ 
				int days = this->days;

				int year = this->GetYear();

				for (int i = this->YEAR_MIN; i < year; i++)
				{
					days -= days_in_a_year(i);
				}

				return days -= days_passed_to_month(year, this->GetMonth());
			};

			int GetMonth() const 
			{ 
				int days = this->days;

				int year = this->GetYear();

				for (int i = this->YEAR_MIN; i < year; i++)
				{
					days -= days_in_a_year(i);
				}

				for (int i = this->JANUARY; i < this->DECEMBER; i++)
				{
					const int in_m = days_passed_to_month(year, i + 1);
					if (days <= in_m)
						return i;
				}

				return this->DECEMBER;
			};

			int GetYear() const 
			{ 
				int days_count = this->days;

				for (int i = this->YEAR_MIN; i <= this->YEAR_MAX; i++)
				{
					const int in_a_year = this->days_in_a_year(i);

					if (days_count <= in_a_year)
						return i;

					days_count -= in_a_year;
				}

				return this->YEAR_MAX + 1;
			};

			// Operators
			Date operator+ (int days) const
			{
				Date res;

				res.days = this->days + days;

				if (is_coorect_date(res.GetYear(), res.GetMonth(), res.GetDay()))
					return res;

				return Date();
			}

			Date operator - (int k) const {
				Date res;

				res.days = this->days - k;

				if (is_coorect_date(res.GetYear(), res.GetMonth(), res.GetDay()))
					return res;

				return Date();
			}

			int operator - (const Date& other) const {
				return this->days - other.days;
			}

			// Public constants
			static const int YEAR_MIN = 1970;
			static const int YEAR_MAX = 2099;
			static const int DAY_MIN = 1;
			static const int DAY_FEBRUARY_USUAL = 28;
			static const int DAY_FEBRUARY_LEAP = DAY_FEBRUARY_USUAL + 1;
			static const int DAY_MAX = 31;
			static const int DAYS_IN_YEAR_WITHOUT_FEB = 337;

		private:
			// Количество дней с начала минимальной даты
			int days;

			// Определяет, високосный ли год
			bool is_a_leap_year(int year) const
			{
				if (year % 400 == 0)
					return true;
				else if (year % 100 == 0)
					return false;
				else if (year % 4 == 0)
					return true;
				else
					return false;
			}

			// Проверка корректности кода 
			bool is_coorect_date(int year, int month, int day) const
			{
				// Проверка, попадаем ли в диапазон лет
				if (year < this->YEAR_MIN || year > this->YEAR_MAX)
					return false;

				// Проверка, попадаем ли в диапазон месяцев
				if (month < JANUARY || month > DECEMBER)
					return false;

				// Проверка на нулевое количество дней
				if (day < this->DAY_MIN)
					return false;

				// Проверим, сколько дней в предлагаемом месяце
				const int days_in_month = get_days_in_month(year, month);

				return day <= days_in_month;
			}

			// Опредлеяпет коилчество дней в феврале
			int get_days_in_february(int year) const
			{
				if (is_a_leap_year(year))
					return this->DAY_FEBRUARY_LEAP;

				return this->DAY_FEBRUARY_USUAL;
			}

			// Определяет количество дней в месяце
			int get_days_in_month(int year, int m) const
			{
				switch (m)
				{
				case FEBRARY:
					return get_days_in_february(year);

				case JANUARY:
				case MARCH:
				case MAY:
				case JULY:
				case AUGUST:
				case OCTOBER:
				case DECEMBER:
					return 31;

				default:
					return 30;
				}
			}

			// Определим количество дней с начала года в целых месяцах
			int days_passed_to_month(int year, int month) const
			{
				int days = 0;
				for (int i = JANUARY; i < month; ++i)
				{
					// Прибавляем количество дней месяца 
					days += get_days_in_month(year, i);
				}

				// Возвращаем результат
				return days;
			}

			// Определяет количество дней в году
			int days_in_a_year(int year) const
			{
				return DAYS_IN_YEAR_WITHOUT_FEB + get_days_in_february(year);
			}

		}; // End Class Date
	} // End namespace for Task B

	// Задача C: Rational
	// https://new.contest.yandex.ru/contests/42158/problems?id=40119%2F2022_10_30%2FLJjNoDCHJX
	// Напишите класс Rational(рациональное число).
	// Конструктор класса должен получать на вход два числа типа int(числитель и знаменатель).
	// Считайте, что по умолчанию числитель равен 0, а знаменатель — 1.
	// Переопределите бинарные операторы сложения, вычитания, умножения и 
	// деления(работающие в том числе и с аргументами типа int), 
	// унарные плюс и минус.
	// Предусмотрите функции - члены Numerator и Denominator для получения числителя и 
	// знаменателя несократимого представления этой дроби(знаменатель должен быть положительным).
	// Переопределите также операторы +=, -=, *= и /= .Не забудьте определить операторы == и != .
	// Используйте функцию std::gcd стандартной библиотеки.
	class Rational
	{
	private:
		int denominator;
		int numerator;

		void Reduce(void)
		{
			if (numerator == 0)
				return;

			const int gcd = std::gcd<int64_t>(numerator, denominator);

			numerator /= gcd;
			denominator /= gcd;
		}

	public:
		Rational() : numerator(0), denominator(1) {}

		Rational(int num, int den) :numerator(0), denominator(1)
		{
			if (den == 0)
				return;

			// Обработаем знаки входных чисел
			if (den < 0)
			{
				num = -num;
				den = -den;
			}

			numerator = num;
			denominator = den;

			Reduce();
		}

		// Свойства геттеры
		int Numerator(void) { return numerator; }
		int Denominator(void) { return denominator; }

		// Операторы сложения
		Rational operator + (int val)
		{
			return Rational();
		}

		Rational operator + (Rational val)
		{
			return Rational();
		}

		// Сложение с присвоением

		Rational operator += (int val)
		{
			return *this;
		}

		Rational operator += (Rational val)
		{
			return *this;
		}

		// Операторы вычитания
		Rational operator - (int val)
		{
			return Rational();
		}

		Rational operator - (Rational val)
		{
			return Rational();
		}

		// Вычитание с присвоением
		Rational operator -= (int val)
		{
			return *this;
		}

		Rational operator -= (Rational val)
		{
			return *this;
		}

		// Операторы умножения
		Rational operator * (int val)
		{
			return Rational();
		}

		Rational operator * (Rational val)
		{
			return Rational();
		}

		// Умножение с присвоением
		Rational operator *= (int val)
		{
			return *this;
		}

		Rational operator *= (Rational val)
		{
			return *this;
		}

		// Операторы деления
		Rational operator / (int val)
		{
			return Rational();
		}

		Rational operator / (Rational val)
		{
			return Rational();
		}

		// Деление с присвоением
		Rational operator /= (int val)
		{
			return *this;
		}

		Rational operator /= (Rational val)
		{
			return *this;
		}

		// Унарные операторы

		Rational operator+()
		{
			return Rational(*this);
		}

		Rational operator-()
		{
			Rational res = Rational(*this);
			res.numerator = -res.numerator;
			return res;
		}

		// Операторы сравнения
		bool operator==(Rational other)
		{
			return	this->Numerator() == other.Numerator() && 
					this->Denominator() == other.Denominator();
		}

		bool operator!=(Rational other)
		{
			return !(*this != other);
		}

	};
	

};
