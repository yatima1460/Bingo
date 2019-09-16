# BingoGame


# F.A.Q.

- Why use `int` instead of `unsigned int` for credits?
    - I prefer to have a simple clean code and avoid having conversions between different value types
    - It's better to check if an `int` becomes negative and `throw` an exception the instant it happens instead of disallowing negative values using an `unsigned int`, worst case scenario is the `unsigned int` behind the scenes underflowing because of implicit conversions.
