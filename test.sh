#bin/zsh

while :
do
  read SWITCH

case $SWITCH in
	map)
		clear
		make -s map
		echo  "$(tput setaf 10)\nMY TIMES$(tput setaf 4)"
		time leaks --atExit -- ./map > map_a.comp; echo "$(tput setaf 10)\nSTL TIMES$(tput setaf 4)"; time leaks --atExit -- ./stl_map > map_b.comp
		echo "\n$(tput setaf 10)DIFFERENCES$(tput setaf 6)\n"
		diff map_a.comp map_b.comp
		make -s fclean
	;;
	vector)
		clear
		make -s vector
		echo "$(tput setaf 10)\nMY TIMES$(tput setaf 4)"
		time ./vector > /dev/null; echo "$(tput setaf 10)\n\nSTL TIMES$(tput setaf 4)"; time ./stl_vector > /dev/null
		echo "\n$(tput setaf 10)Leaks$(tput setaf 6)\n"
		leaks --atExit -- ./vector
		make -s fclean
	;;
	utils)
		clear
		make -s utils
		echo $(tput setaf 3)
		# echo "$(tput setaf 10)\nMY TIMES$(tput setaf 4)"
		# time ./vector > /dev/null; echo "$(tput setaf 10)\n\nSTL TIMES$(tput setaf 4)"; time ./stl_vector > /dev/null
		leaks --atExit -- ./utils
		# echo "\n$(tput setaf 10)DIFFERENCES$(tput setaf 6)\n"
		# diff vector_a.comp vector_b.comp
		make -s fclean
	;;
	stack)
		clear
		make -s stack
		echo  "$(tput setaf 10)\nMY TIMES$(tput setaf 4)"
		time leaks --atExit -- ./stack > stack_a.comp; echo "$(tput setaf 10)\nSTL TIMES$(tput setaf 4)"; time leaks --atExit -- ./stl_stack > stack_b.comp
		echo "\n$(tput setaf 10)DIFFERENCES$(tput setaf 6)\n"
		diff stack_a.comp stack_b.comp
		make -s fclean
	;;
	performance)
		clear
		g++ -o stl main.cpp ; g++ -o mine main2.cpp
		echo  "$(tput setaf 10)\nMY TIMES$(tput setaf 4)"
		time ./mine 21
		echo "$(tput setaf 10)\nSTL TIMES$(tput setaf 4)";
		time ./stl 21
		rm -rf mine stl
		make -s fclean
	;;
	end) 
		break

esac
done