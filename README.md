# CIS 165 Lab 7: BMI and Color Mixer

## Program plans

### BMI (`bmi.cpp`)
- **Inputs:** Weight in pounds and height in inches, both `double`.
- **Variables:** `weight`, `height`, and the calculated `bmi`.
- **Validation:** Check that both numbers are greater than zero. Print an error and stop otherwise.
- **Calculation:** `bmi = weight * 703.0 / (height * height)`.
- **Output:** BMI to two decimal places and one category: Underweight if below 18.5, Optimal weight from 18.5 through 25.0, or Overweight above 25.0.
- **Test plan:** Try each category, a zero height, a negative weight, and an extra negative-height case.

### Color Mixer (`color_mixer.cpp`)
- **Inputs:** Two lowercase primary-color words in bounded `char` arrays.
- **Variables/constants:** `first_color`, `second_color`, `mixed_color`, `first_valid`, `second_valid`, and `COLOR_SIZE`.
- **Validation:** Use `strcmp` to make sure each word is `red`, `blue`, or `yellow`. If either is invalid, print an error.
- **Comparisons:** Same colors stay the same; red + blue makes purple, red + yellow makes orange, and blue + yellow makes green, in either order.
- **Output:** A labeled mixed color or an error.
- **Test plan:** Try all mixtures, a reversed order, a matching pair, invalid colors in either position, and an extra reversed mixture.

## Compile and run

I used a C++17 command-line compiler to compile and run both programs separately. In the directory containing the four files, run:

```bash
g++ -std=c++17 -Wall -Wextra bmi.cpp -o bmi
./bmi
```

Then run:

```bash
g++ -std=c++17 -Wall -Wextra color_mixer.cpp -o color_mixer
./color_mixer
```

Both final programs compiled successfully with these flags and produced the results shown below.

## Test records

I predicted the expected outputs from the assignment rules and compared them to the actual program output after compiling. In the actual-result column, the displayed result is shown without repeating the input prompts.

| Program/test | Inputs | Expected result | Actual result | Match or correction |
| --- | --- | --- | --- | --- |
| BMI 1 | 100, 70 | 14.35 — Underweight | 14.35 — Underweight | Match |
| BMI 2 | 150, 70 | 21.52 — Optimal weight | 21.52 — Optimal weight | Match |
| BMI 3 | 200, 70 | 28.69 — Overweight | 28.69 — Overweight | Match |
| BMI 4 | 150, 0 | Error: weight and height must be positive. | Error: weight and height must be positive. | Match |
| BMI 5 | -150, 70 | Error: weight and height must be positive. | Error: weight and height must be positive. | Match |
| BMI extra | 150, -70 | Error: weight and height must be positive. | Error: weight and height must be positive. | Match — checks negative height |
| Color Mixer 1 | red, blue | purple | purple | Match |
| Color Mixer 2 | red, yellow | orange | orange | Match |
| Color Mixer 3 | blue, yellow | green | green | Match |
| Color Mixer 4 | blue, red | purple | purple | Match |
| Color Mixer 5 | red, red | red | red | Match |
| Color Mixer 6 | orange, blue | Error: enter red, blue, or yellow. | Error: enter red, blue, or yellow. | Match |
| Color Mixer 7 | red, orange | Error: enter red, blue, or yellow. | Error: enter red, blue, or yellow. | Match |
| Color Mixer extra | yellow, blue | green | green | Match — checks the reversed order of blue and yellow |

I also tried `yellow, red` (orange), `blue, blue` (blue), `yellow, yellow` (yellow), and `green, green` (invalid-input error), and all matched their expected results. After the additional checks, I compiled both final files again successfully.

Exactly 18.5 and exactly 25.0 are in the **Optimal weight** category because the lab says that both endpoints are included. The program's `else if (bmi <= 25.0)` only runs after `bmi < 18.5` has failed, so that branch includes 18.5 through 25.0 without any gaps.

## Code explanations

1. **BMI formula:** The formula multiplies pounds by 703 and divides by height in inches squared. `height * height` squares the height. In C++, `^` is not used for squaring.
2. **Boundary conditions:** I check `bmi < 18.5` first, then `bmi <= 25.0`, and then use `else` for everything higher. Order matters because the second branch assumes the first check was false. Both 18.5 and 25.0 go into Optimal weight.
3. **Input validation:** If the weight or height is zero or negative, the values are not usable for this calculation. The program catches them before doing the division, including preventing division by zero.
4. **Rounding:** I compare the original `bmi` value so that a number near 18.5 or 25.0 is classified correctly. `setprecision(2)` changes the way it prints, not the value used for comparison.
5. **`strcmp`:** `strcmp` returns zero when two pieces of text are equal. Using `==` with character arrays would compare their addresses, not the text stored inside them.
6. **Mixing and repeated colors:** Each different-color condition checks both possible orders using `||`. The first mixing branch checks whether the two colors match, and returns the original color when they do.
7. **Invalid colors:** I check each input against all three valid words. If either check fails, the program prints an error and stops before mixing.
8. **Constants and result variables:** `COLOR_SIZE` makes it easy to change the array limit in one place. `bmi` and `mixed_color` keep the results separate from the display statements, making the logic easier to follow and test.

## Files

- `bmi.cpp` — BMI calculator and classifier
- `color_mixer.cpp` — primary-color mixer using arrays and `strcmp`
- `README.md` — plans, tests, explanations, and instructions
- `AI_REFLECTION.md` — explanation of AI assistance, verification, and learning
