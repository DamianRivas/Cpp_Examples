template <class T>
class Accum
{
private:
  T total;

public:
  Accum(T start) : total(start){};
  T operator+=(T const &t) { return total = total + t; }
  T getTotal() const { return total; }
};

template <>
class Accum<Person>
{
private:
  int total;

public:
  Accum(int start) : total(start){};
  int operator+=(Person const &t) { return total = total + t.getNumber(); }
  int getTotal() const { return total; }
};
