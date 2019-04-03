//
// Created by chris on 2019-03-27.
//

#include "Pair.h"

std::pair<double, double> operator-(const std::pair<double, double> p)
{
    return std::make_pair(-p.first, -p.second);
}

std::pair<double, double> operator+(const std::pair<double, double> p1, const std::pair<double, double> p2)
{
    return std::make_pair(p1.first + p2.first, p1.second + p2.second);
}

std::pair<double, double> operator-(const std::pair<double, double> p1, const std::pair<double, double> p2)
{
    return std::make_pair(p1.first - p2.first, p1.second - p2.second);
}

std::pair<double, double> operator/(const std::pair<double, double> p1, const std::pair<double, double> p2)
{
    return std::make_pair(p1.first / p2.first, p1.second / p2.second);
}

std::pair<double, double>& operator/=(std::pair<double, double>& self, const double d)
{
    self.first  /= d;
    self.second /= d;
    return self;
}

std::pair<double, double>& operator+=(std::pair<double, double>& self, const std::pair<double, double> other)
{
    self.first  += other.first;
    self.second += other.second;
    return self;
}

std::pair<double, double>& operator-=(std::pair<double, double>& self, const std::pair<double, double> other)
{
    self.first  -= other.first;
    self.second -= other.second;
    return self;
}

std::pair<double, double>& operator*=(std::pair<double, double>& self, const std::pair<double, double> other)
{
    self.first  *= other.first;
    self.second *= other.second;
    return self;
}

std::ostream& operator<<(std::ostream& out, const std::pair<double, double>& data)
{
    return out << "(" << data.first << "," << data.second << ")";
}