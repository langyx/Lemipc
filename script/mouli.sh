# for ((i = 0; i < 2; i += 1))
# do
#     ./lemipc `pwd` 2 &
# done

# for ((i = 0; i < 2; i += 1))
# do
#     ./lemipc `pwd` 3 &
# done
./lemipc `pwd` 1 2> process_1 &
./lemipc `pwd` 1 2> process_2 &
./lemipc `pwd` 2 2> process_3 &
./lemipc `pwd` 2 2> process_4 &
