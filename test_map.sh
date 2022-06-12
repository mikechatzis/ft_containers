#bin/zsh

echo -e "$(tput setaf 10)\nMY TIMES$(tput setaf 4)"

time ./map > map_a.comp; echo "$(tput setaf 10)\nSTL TIMES$(tput setaf 4)"; time ./stl_map > map_b.comp
echo "\n$(tput setaf 10)DIFFERENCES$(tput setaf 6)\n"
diff map_a.comp map_b.comp
