DED_FLAGS="-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE -D_EJC"
FILES="main_matrix.cpp matrix_print.cpp matrix_sum.cpp write_matrix_from_file.cpp matrix_ladder.cpp"
OUT_PROG="matrix.exe"

echo -e "\033[35m\033[40m"   # фиолетовый на чёрном
echo "Files: "
echo -e "\033[0m"   #белый на чёрном фоне
echo ${FILES}        

echo -e "\033[31m\033[40m"   #красный на чёрном фоне
echo "Flags: "
echo -e "\033[0m"   #белый на чёрном фоне
echo ${DED_FLAGS}

echo -e "\033[36m\033[40m"   #голубой на чёрном фоне
echo "Compilation start"
echo -e "\033[0m"   #белый на чёрном фоне
g++ ${FILES} -o ${OUT_PROG} ${DED_FLAGS}   

echo -e "\033[32m\033[40m"   #зеленый на чёрном фоне
echo "Compilation complite"
echo -e "\033[0m"   #белый на чёрном фоне