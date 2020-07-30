# ft_printf
School project to recode the C library function - printf().

Introduction
Regardless of the programming language considered, the printf function,(or its equivalents) is always highly useful. The main reason is the ease of its formatting, and the support of diverse types in variable numbers. Some variations even propose to be able to write the resulting string of characters either in a file descriptor or in a particular stream. Some also propose to recall this string without printing it. In short, undeniably, printf is a vital function. In this project, we ask you to recode it and add it to your libft so that you can use it in all your future projects, such as ft_ls...

Objectives
The versatility of the printf function in C represents a great exercise in programming for us. This project is of moderate difficulty. It will enable you to discover variadic functions in C in a particularly relevant context as well as learn about a great example of a basic “dispatcher” in C via the use of an array of function’s pointers. The key to a successful ft_printf is a well-structured and good extensible code. This is because as time goes by, you will be more and more tempted to continue to extend your ft_printf, making your life easier for your future projects. So take your time to code properly while keeping in mind that you will have to read again your code in a few weeks or a few months to extend its functionality according to your needs. It would be a shame not to being able to do it because your can’t read your own work. What do you think?

The function passed the evaluations and tests with a score of 98/100. The few points lost were due to a crash that occured on one instance when using a long double variable. I still haven't fixed that issue, so when using this function, the user should keep this in mind.

Supported conversions are:
- c, s, p, d, i, o, u, x, X, f and b (for binary).

With the flags:
- hh, h, l, ll, L, #, 0, -, +, space.

The function also handles field-width and precision modifiers.
