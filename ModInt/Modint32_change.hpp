#pragma once

#include "../Template/Template.hpp"
struct mintc {
    int x;
    using Type = int;
    static Type mod;
    mintc() : x(0) {}
    mintc(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    mintc &operator+=(const mintc &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }
    mintc &operator-=(const mintc &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    mintc &operator*=(const mintc &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    mintc &operator/=(const mintc &p) {
        *this *= p.inverse();
        return *this;
    }
    mintc operator-() const { return mintc(-x); }
    mintc operator+(const mintc &p) const { return mintc(*this) += p; }
    mintc operator-(const mintc &p) const { return mintc(*this) -= p; }
    mintc operator*(const mintc &p) const { return mintc(*this) *= p; }
    mintc operator/(const mintc &p) const { return mintc(*this) /= p; }
    bool operator==(const mintc &p) const { return x == p.x; }
    bool operator!=(const mintc &p) const { return x != p.x; }
    mintc inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return mintc(u);
    }
    friend ostream &operator<<(ostream &os, const mintc &p) {
        return os << p.x;
    }
    friend istream &operator>>(istream &is, mintc &a) {
        int64_t t;
        is >> t;
        a = mintc(t);
        return (is);
    }
    int get() const { return x; }
    static int get_mod() { return mod; }
    static void set_mod(int md) {
        assert(0 < md && md <= (1LL << 30) - 1);
        mod = md;
    }
};

typename mintc::Type mintc::mod;