//
// Created by chris on 2019-03-27.
//

#ifndef INFOMAP_BIPARTITE_PAIR_H
#define INFOMAP_BIPARTITE_PAIR_H

#include <utility>
#include <ostream>

std::pair<double, double> operator-(const std::pair<double, double> p);
std::pair<double, double> operator+(const std::pair<double, double> p1, const std::pair<double, double> p2);
std::pair<double, double> operator-(const std::pair<double, double> p1, const std::pair<double, double> p2);
std::pair<double, double> operator/(const std::pair<double, double> p1, const std::pair<double, double> p2);
std::pair<double, double>& operator/=(std::pair<double, double>& self, const double d);
std::pair<double, double>& operator+=(std::pair<double, double>& self, const std::pair<double, double> other);
std::pair<double, double>& operator-=(std::pair<double, double>& self, const std::pair<double, double> other);
std::pair<double, double>& operator*=(std::pair<double, double>& self, const std::pair<double, double> other);
std::ostream& operator<<(std::ostream& out, const std::pair<double, double>& data);
std::pair<double, double> op(const std::pair<double, double> p);
std::pair<double, double> zeroLeft(const std::pair<double, double> p);
std::pair<double, double> zeroRight(const std::pair<double, double> p);

#endif //INFOMAP_BIPARTITE_PAIR_H
