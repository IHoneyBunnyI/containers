#!/bin/zsh

clear
clang++ -Wall -Wextra -Werror main.cpp -o vector
if grep "ft::vector" ./main.cpp > /dev/null
then
	./vector > ft_output
	sed -i '' "s/ft::vector/std::vector/g" ./main.cpp
	clang++ -Wall -Wextra -Werror main.cpp -o vector
	./vector > std_output
else
	./vector > std_output
	sed -i '' "s/std::vector/ft::vector/g" ./main.cpp
	clang++ -Wall -Wextra -Werror main.cpp -o vector
	./vector > ft_output
fi
if diff -E ft_output std_output
then
	echo "\033[32mDiff 0 OK!\033[0m"
	rm std_output
	rm ft_output
else
	echo "\033[31mDiff != 0 ERROR\033[0m"
fi
rm vector
if [ 'clear' = "$1" ]
then
	rm ft_output
	rm std_output
	echo "\033[38;5;412mDelete output files\033[0m"
fi
