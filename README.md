# Sortings
Sorting algorithm for strings

150 symbols and 10000 strings.

Flat profile:

Each sample counts as 0.01 seconds.

% time  | cumulative seconds | self seconds  |  calls | self s/call | total s/call | name  
--------- | --------- | --------- | --------- | --------- | --------- | ---------
 50.14   |  0.01  |  0.01  |     1   |10.03  | 10.03 |bubble
 50.14   |  0.02  |  0.01  |     1   |10.03  | 10.03 |mergesort
  0.00   |  0.02  |  0.00  |508818   | 0.00  |  0.00 |swap
  0.00   |  0.02  |  0.00  |     1   | 0.00  |  0.00 |insert
  0.00   |  0.02  |  0.00  |     1   | 0.00  |  0.00 |qsorting


Call graph (explanation follows)
granularity: each sample hit covers 2 byte(s) for 49.86% of 0.02 seconds

index | % time  |  self | children  |  called   |  name 
--------- | --------- | --------- | --------- | --------- | -----------
[1]|    100.0|   0.00 |  0.02   |          |  main [1]
   |         |  0.01  | 0.00    |  1/1     |     mergesort [3]
   |         |  0.01  | 0.00    |  1/1     |     bubble [2]
   |         |  0.00  | 0.00    |  1/1     |     qsorting [6]
   |         |  0.00  | 0.00    |  1/1     |     insert [5]
   |         |  0.01  | 0.00    |  1/1     |     main [1]
[2]|    50.0 |  0.01  | 0.00    |  1       | bubble [2]
   |         |  0.00  | 0.00  |249060/508818|      swap [4]
   |         |        |         |1022        |     mergesort [3]
   |         |  0.01  | 0.00    |  1/1      |    main [1]
[3]|    50.0 |  0.01  | 0.00    |  1+1022   |mergesort [3]
   |         |        |         |1022       |     mergesort [3]
   |         |  0.00  | 0.00   |10698/508818|     qsorting [6]
   |         |  0.00  | 0.00  |249060/508818|     insert [5]
   |         |  0.00  | 0.00  |249060/508818|     bubble [2]
[4]|     0.0 |  0.00  | 0.00  |508818       | swap [4]
   |         |  0.00  | 0.00     |  1/1     |     main [1]
[5]|     0.0 |  0.00  | 0.00     |  1       | insert [5]
   |         |  0.00  | 0.00  |249060/508818|     swap [4]
   |         |        |        |  999       |     qsorting [6]
   |         |  0.00  | 0.00    |   1/1     |     main [1]
[6]|     0.0 |  0.00  | 0.00     |  1+999   | qsorting [6]
   |         |  0.00  | 0.00  | 10698/508818|     swap [4]
   |         |        |       |  999        |    qsorting [6]
   
   [2] bubble
   [3] mergesort               
   [4] swap
   [5] insert                  
   [6] qsorting

