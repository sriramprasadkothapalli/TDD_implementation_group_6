#include "mathlib.hpp"

namespace mathlib {
template <typename T>
T clamp(T value, T min_v, T max_v) {
  return (value < min_v) ? min_v : (value > max_v) ? max_v : value;
}
template double clamp<double>(double value, double min_v, double max_v);
template int clamp<int>(int value, int min_v, int max_v);

template <typename T>
int sign(T val) {
  return ((val > 0) - (val < 0));
}
template int sign(int val);

constexpr float horner_impl(float xa, const float *p, size_t count, float t) {
  return count == 0 ? p[count] + xa * t
                    : horner_impl(xa, p, count - 1, p[count] + xa * t);
}

template <size_t N>
constexpr float horner(float x, float a, const float (&p)[N]) {
  return horner_impl(x - a, p, N - 2, p[N - 1]);
}

float calcAlphaEMA(float f_n) {
  // Taylor coefficients of
  // α(fₙ) = cos(2πfₙ) - 1 + √( cos(2πfₙ)² - 4 cos(2πfₙ) + 3 )
  // at fₙ = 0.25
  constexpr static float coeff[]{
      +7.3205080756887730e-01, +9.7201214975728490e-01, -3.7988125051760377e+00,
      +9.5168450173968860e+00, -2.0829320344443730e+01, +3.0074306603814595e+01,
      -1.6446172139457754e+01, -8.0756002564633450e+01, +3.2420501524111750e+02,
      -6.5601870948443250e+02,
  };
  return horner(f_n, 0.25, coeff);
}
}  // namespace mathlib
