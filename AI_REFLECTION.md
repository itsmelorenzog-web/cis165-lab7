# AI Reflection — Lab 7

I used ChatGPT to help prepare the C++ code, organize the README, and check whether both programs met the lab instructions. The programs were then compiled and tested using a C++17 compiler. I still need to make sure I understand the code before I submit it, since I am responsible for what I turn in.

One important decision in the BMI program was to compare the original BMI value instead of the rounded number. That matters because a value close to 25 could display as 25.00 even though it is technically above 25. I also kept the input checks before the BMI calculation so the program stops if the height is zero.

For the Color Mixer, I used `strcmp` rather than `==` because the assignment requires character arrays. Each pair of different colors needs to work in both orders. The program also checks the two inputs separately so that an invalid word in either place produces an error.

To check the work, the compiled BMI program returned 21.52 and Optimal weight for 150 pounds and 70 inches. The Color Mixer returned purple for both red/blue and blue/red, and showed an error when orange was entered.

I can now follow how `if`, `else if`, and `else` choose different outputs. I still need more practice writing longer `strcmp` conditions without help.
