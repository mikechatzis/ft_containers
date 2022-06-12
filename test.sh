#bin/zsh

while :
do
  read SWITCH

case $SWITCH in
	map)
		make -s map
		echo  "$(tput setaf 10)\nMY TIMES$(tput setaf 4)"
		time ./map > map_a.comp; echo "$(tput setaf 10)\nSTL TIMES$(tput setaf 4)"; time ./stl_map > map_b.comp
		echo "\n$(tput setaf 10)DIFFERENCES$(tput setaf 6)\n"
		diff map_a.comp map_b.comp
		make -s fclean
	;;
	vector)
		make -s vector
		echo "$(tput setaf 10)\nMY TIMES$(tput setaf 4)"
		time ./vector > /dev/null; echo "$(tput setaf 10)\n\nSTL TIMES$(tput setaf 4)"; time ./stl_vector > /dev/null
		./vector
		# echo "\n$(tput setaf 10)DIFFERENCES$(tput setaf 6)\n"
		# diff vector_a.comp vector_b.comp
		make -s fclean
	;;
	end) 
		break

esac
done