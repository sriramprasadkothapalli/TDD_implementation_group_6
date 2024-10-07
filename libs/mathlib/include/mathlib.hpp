#ifndef MATHLIB_H
#define MATHLIB_H
#include <cstddef>


namespace mathlib {
    constexpr double INF = 1e9;

    /**
     * @brief clamps a given value between a lower and an upper bound
     * @param value the value to be clamped
     * @param min_v lower bound
     * @param max_v upper bound
     * @return the clamped value
     */
    template<typename T>
    T clamp(T value, T min_v, T max_v);

    /**
     * @brief returns the sign of a value
     * @details implementation of a generic sign function
     * @param val value whoes sign is to checked
     * @return one of {-1, 0, 1}
     */
    template<typename T>
    int sign(T val);

    /**
    * @brief Horner's method implementation
    * @param xa
    * @param p
    * @param count
    * @param t
    */
    constexpr float horner_impl(float xa, const float *p, std::size_t count,
                                float t);
    /**
    * @brief Evaluate a polynomial using Horner's method
    * @param x
    * @param a
    * @param ref(p)
    *
    */
    template<std::size_t N>
    constexpr float horner(float x, float a, const float (&p)[N]);

    /**
    * @brief Compute the weight factor of an exponential moving average filter with the given cutoff frequency.
    * @param f_n
    * @details https://tttapa.github.io/Pages/Mathematics/Systems-and-Control-Theory/Digital-filters/Exponential%20Moving%20Average/Exponential-Moving-Average.html#cutoff-frequency for the formula.
    */
    float calcAlphaEMA(float f_n);
}

#endif

