#bin/zsh

clear
echo "$(tput setaf 2)$(tput bold)Welcome to the ft_containers test script\n\nTo test the project, please choose from \
'vector', 'map', 'stack', 'utils' (precede with view_ to view test info), 'performance', or 'help'\
\nType 'view_stl' to view test expected output while using the STL containers
\n"

echo "$(tput setaf 3)$(tput bold)Do you want the test output to be printed to the terminal? (y/n): $(tput setaf 0)$(tput sgr0)\c"
read OUT

	while :
	do
	if [ "$OUT" = "y" ] || [ "$OUT" = "n" ]; then
		echo "$(tput setaf 3)$(tput bold)Please insert command: $(tput setaf 0)$(tput sgr0)\c"
		read SWITCH

		case $SWITCH in
			view_map)
				clear
				make -s map
				echo "\n$(tput setaf 10)MAP TEST OUTPUT$(tput setaf 6)\n" | tee test_log > /dev/null
				./map | tee -a test_log > /dev/null
				echo "$(tput setaf 0)$(tput sgr0)\c" | tee -a test_log > /dev/null
				make -s fclean
			;;
			view_vector)
				clear
				make -s vector
				echo "\n$(tput setaf 10)VECTOR TEST OUTPUT$(tput setaf 6)\n" | tee test_log > /dev/null
				./vector | tee -a test_log > /dev/null
				echo "$(tput setaf 0)$(tput sgr0)\c" | tee -a test_log > /dev/null
				make -s fclean
			;;
			view_stack)
				clear
				make -s stack
				echo "\n$(tput setaf 10)STACK TEST OUTPUT$(tput setaf 6)\n" | tee test_log > /dev/null
				./stack | tee -a test_log > /dev/null
				echo "$(tput setaf 0)$(tput sgr0)\c" | tee -a test_log > /dev/null
				make -s fclean
			;;
			view_stl)
				clear
				make -s stack
				make -s vector
				make -s map
				echo "\n$(tput setaf 10)VECTOR TEST OUTPUT$(tput setaf 5)\n" | tee test_log > /dev/null
				./stl_vector | tee -a test_log > /dev/null
				echo "\n$(tput setaf 10)MAP TEST OUTPUT$(tput setaf 3)\n" | tee -a test_log > /dev/null
				./stl_map | tee -a test_log > /dev/null
				echo "\n$(tput setaf 10)STACK TEST OUTPUT$(tput setaf 4)\n" | tee -a test_log > /dev/null
				./stl_stack | tee -a test_log > /dev/null
				echo "$(tput setaf 0)$(tput sgr0)\c" | tee -a test_log > /dev/null
				make -s fclean
			;;
			map)
				clear
				make -s map
				leaks --atExit -- ./map > map_a.comp; ./stl_map > map_b.comp
				echo "\n$(tput setaf 10)DIFFERENCES$(tput setaf 6)\n" | tee test_log > /dev/null
				diff map_a.comp map_b.comp | tee -a test_log > /dev/null
				echo "$(tput setaf 0)$(tput sgr0)" | tee -a test_log > /dev/null
				make -s fclean
			;;
			vector)
				clear
				make -s vector
				leaks --atExit -- ./vector > vector_a.comp; ./stl_vector > vector_b.comp
				echo "\n$(tput setaf 10)DIFFERENCES$(tput setaf 6)\n" | tee test_log > /dev/null
				diff vector_a.comp vector_b.comp | tee -a test_log > /dev/null
				echo "$(tput setaf 0)$(tput sgr0)" | tee -a test_log > /dev/null
				make -s fclean
			;;
			utils)
				clear
				make -s utils
				echo $(tput setaf 10) | tee test_log > /dev/null
				./utils | tee -a test_log > /dev/null
				echo "$(tput setaf 0)$(tput sgr0)\c" | tee -a test_log > /dev/null
				make -s fclean
			;;
			stack)
				clear
				make -s stack
				leaks --atExit -- ./stack > stack_a.comp; ./stl_stack > stack_b.comp
				echo "\n$(tput setaf 10)DIFFERENCES$(tput setaf 6)\n"| tee test_log > /dev/null
				diff stack_a.comp stack_b.comp| tee -a test_log > /dev/null
				echo "$(tput setaf 0)$(tput sgr0)"| tee -a test_log > /dev/null
				make -s fclean
			;;
			performance)
				clear
				g++ -o stl main.cpp ; g++ -o mine main2.cpp
				echo  "$(tput setaf 10)\nMY TIMES$(tput setaf 4)"
				time ./mine 21
				echo "$(tput setaf 10)\nSTL TIMES$(tput setaf 4)"
				time ./stl 21
				echo "\n$(tput setaf 0)$(tput sgr0)"
				rm -rf mine stl
				make -s fclean
			;;
			help)
				echo "$(tput setaf 4)$(tput bold)'map', 'vector' & 'stack':\
				\n$(tput sgr0)    Executes one binary using the format 'ft::container' and another using 'std::container' and diffs them.\
				\n    Precede each command with 'view_'(wthout leaving a space), to display the tests' output\n"
				echo "$(tput setaf 4)$(tput bold)'view_stl':\
				\n$(tput sgr0)    Display test outputs, using the STL containers.\n"
				echo "$(tput setaf 4)$(tput bold)'utils':\
				\n$(tput sgr0)    Display tests on lexicographical_compare and iterator_traits. Enable_if is used in vector\n"
				echo "$(tput bold)$(tput setaf 4)'performance':\n$(tput sgr0)    Runs the school's provided main twice, with ft:: and std:: namespace respectively, and displays execution times for comparison\n"
				echo "$(tput bold)$(tput setaf 4)'rm':\n$(tput sgr0)    Deletes the 'test_log' file$(tput setaf 0)\n"
				echo "$(tput bold)$(tput setaf 4)'help':\n$(tput sgr0)    Displays this help message$(tput setaf 0)\n"
				echo "$(tput bold)$(tput setaf 4)'end':\n$(tput sgr0)    Exits the script$(tput setaf 0)\n"
				echo "$(tput setaf 6)Files required: 'vector.hpp' 'map.hpp' 'stack.hpp' 'utils.hpp'$(tput setaf 0)\n"
			;;
			end) 
				break
			;;
			rm)
				if test -f test_log; then
				rm -rf test_log
				fi
			;;
			*)
				echo "$(tput setaf 4)$(tput bold)Choose from 'vector', 'map', 'stack', 'utils', or 'performance'\n$(tput setaf 0)$(tput sgr0)"
			
		esac
		if [ "$OUT" = "y" ]; then
			if test -f test_log; then
				cat test_log
				rm -rf test_log
			fi
		fi
	elif [ "$OUT" = "end" ]; then
		exit
	else
		echo "$(tput setaf 3)$(tput bold)Please type 'y', for yes, or 'n', for no. Type 'end' to exit: $(tput setaf 0)$(tput sgr0)\c"
		read OUT
	fi
	done

	if test -f test_log; then
		echo "$(tput setaf 3)Check 'test_log for the results"
	fi
