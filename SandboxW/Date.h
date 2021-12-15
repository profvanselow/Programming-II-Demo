#ifndef DATE_H
#define DATE_H

class Date {
 private:
  int m_year;
  int m_month;
  int m_day;

 public:
  Date(int year, int month, int day);

  void SetDate(int year, int month, int day) noexcept;

  int const getYear() noexcept { return m_year; }
  int const getMonth() noexcept { return m_month; }
  int const getDay() noexcept { return m_day; }
};

#endif