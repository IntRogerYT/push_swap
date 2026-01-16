make re -s
echo "#########################################
#              TEST1: 100N              #
#########################################"
ARG1=$(python3 -c "import random; print(*(random.sample(range(-2147483648, 2147483647), 100)))")
MOVES1=$(./push_swap $ARG1 | wc -l)
RES1=$(./push_swap $ARG1 | ./checker_linux $ARG1)
echo "Moviments: $MOVES1"
echo "Checker: $RES1"
echo "#########################################
#              TEST1: 500N              #
#########################################"
ARG2=$(python3 -c "import random; print(*(random.sample(range(-2147483648, 2147483647), 500)))")
MOVES2=$(./push_swap $ARG2 | wc -l)
RES2=$(./push_swap $ARG2 | ./checker_linux $ARG2)
echo "Moviments: $MOVES2"
echo "Checker: $RES2"
make fclean -s
