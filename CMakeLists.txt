cmake_minimum_required(VERSION 3.8)
project(LeetCode)

set(CMAKE_CXX_STANDARD 17)
include_directories(.)

set(SOURCE_FILES
        1.TwoSum/1.cc
        1.TwoSum/main.cc
        100.SameTree/main.cc
        10001.BinaryTree/solution.cc
        101.SymmetricTree/main.cc
        102.BinaryTreeLevelOrderTraversal/main.cc
        105.ConstructBinaryTreeFromPreorderAndInorderTraversal/main.cc
        106.ConstructBtFromInorderAndPostorderTraverse/1.cc
        106.ConstructBtFromInorderAndPostorderTraverse/build_tree.cc
        109.ConvertSortedArrayToBst/1.cc
        109.ConvertSortedArrayToBst/2.cc
        109.ConvertSortedArrayToBst/csab.cc
        11.ContainerWithMostWater/main.cc
        110.BalancedBinaryTree/main.cc
        111.MinimumDepthofBinaryTree/1.cc
        111.MinimumDepthofBinaryTree/main.cc
        114.FlatenTree/1.cc
        114.FlatenTree/flatten_tree.cc
        116.PopulatingNextRightPointersinEachNode/1.cc
        116.PopulatingNextRightPointersinEachNode/main.cc
        117.PopulatingNextRightPointersinEachNodeII/1.cc
        117.PopulatingNextRightPointersinEachNodeII/main.cc
        121.BestTimeToBuyAndSellStock/max_profit.cc
        121.BestTimeToBuyAndSellStock/solution.cc
        122.BestTimeToBuyAndSellStockII/max_profit.cc
        122.BestTimeToBuyAndSellStockII/solution.cc
        123.BestTimeToBuyAndSellStockIII/main.cc
        124.BinaryTreeMaximumPathSum/main.cc
        126.WordLadderII/1.cc
        126.WordLadderII/2.cc
        126.WordLadderII/3.cc
        126.WordLadderII/4.cc
        126.WordLadderII/WordLadderII.cc
        127/main.cc
        127.WordLadder/main.cc
        128.LongestConsecutiveSequence/lcs.cc
        130.SurroundedRegions/main.cc
        133.CloneGraph/1.cc
        133.CloneGraph/CloneGraphs.cc
        138.CopyListwithRandomPointer/main.cc
        139.WordBreak/1.cc
        139.WordBreak/WordBreak.cc
        144.BinaryTreePreorderTraversal/solution.cc
        144.BinaryTreePreorderTraversal/stack.cc
        145.BinaryTreePostorderTraversal/main.cc
        145.BinaryTreePostorderTraversal/solution.cc
        145.BinaryTreePostorderTraversal/stack.cc
        15.3sum/main.cc
        154.FindMinimuminRotatedSortedArrayII/main.cc
        16.3SumClosest/main.cc
        167.TwoSumII-InputArrayIsSorted/main.cc
        169.MajorityElement/main.cc
        173.BinarySearchTreeIterator/main.cc
        18.4Sum/main.cc
        188.BestTimeToBuyAndSellStockIV/main.cc
        189.RotateArray/main.cc
        199.BinaryTreeRightSideView/main.cc
        200.NumberOfIslands/main.cc
        20001.MergeSort/main.cc
        20002.HeapSort/main.cc
        20003.QuickSort/main.cc
        20004.RadixSort/main.cc
        20005.BucketSort/main.cc
        20006.ShellSort/main.cc
        20007.CombSort/main.cc
        20008.CountSort/main.cc
        20009.CycleSort/main.cc
        20009.CycleSort/test.cc
        207.CourseSchedule/1.cc
        207.CourseSchedule/2.cc
        207.CourseSchedule/main.cc
        210.CourseScheduleII/1.cc
        210.CourseScheduleII/main.cc
        217.ContainsDuplicate/main.cc
        219.ContainsDuplicateII/main.cc
        219.ContainsDuplicateII/solution.cc
        219.ContainsDuplicateII/ss.cc
        222.CountCompleteTreeNodes/main.cc
        226.InvertBinaryTree/1.cc
        226.InvertBinaryTree/2.cc
        226.InvertBinaryTree/main.cc
        230.KthSmallestElementInBst/solution.cc
        235.LowestCommonAncestorofaBinarySearchTree/main.cc
        257.BinaryTreePaths/1.cc
        257.BinaryTreePaths/main.cc
        279.PerfectSquares/main.cc
        283.MoveZeroes/268.MissingNumber/main.cc
        283.MoveZeroes/main.cc
        297.SerializeandDeserializeBinaryTree/1.cc
        297.SerializeandDeserializeBinaryTree/main.cc
        3.LongestSubstringWithoutRepeatingCharacters/main.cc
        301.RemoveInvalidParentheses/1.cc
        301.RemoveInvalidParentheses/2.cc
        301.RemoveInvalidParentheses/main.cc
        307.RangeSumQuery-Mutable/1.cc
        307.RangeSumQuery-Mutable/main.cc
        309.BestTimeToBuyAndSellStockWithCooldown/main.cc
        31.NextPermutation/NextPermutation.cc
        31.NextPermutation/solution.cc
        310.MinimumHeightTrees/main.cc
        312.BurstBall/main.cc
        316.RemoveDuplicateLetters/main.cc
        316.RemoveDuplicateLetters/solution.cc
        316.RemoveDuplicateLetters/test.cc
        32.LongestValidParentheses/1.cc
        32.LongestValidParentheses/main.cc
        321.CreateMaximumNumber/main.cc
        329.LongestIncreasingPathinaMatrix/1.cc
        329.LongestIncreasingPathinaMatrix/main.cc
        330.PatchingArray/main.cc
        337.HouseRobberIII/main.cc
        352.DataStreamAsDisjointIntervals/main.cc
        376.WiggleSubsequence/dp.cc
        376.WiggleSubsequence/main.cc
        381.InsertDeleteGetRandom-DuplicatesAllowed/main.cc
        392.IsSubsequence/best_solution.cc
        392.IsSubsequence/main.cc
        394.DecodeString/main.cc
        3Sum/3sum.cc
        4.MedianOfSortedArrays/main.cc
        402.RemoveKDigits/main.cc
        404.SumofLeftLeaves/main.cc
        406.QueueReconstructionByHeight/main.cc
        406.QueueReconstructionByHeight/solution.cc
        407.TrappingRainWaterII/1.cc
        407.TrappingRainWaterII/2.cc
        407.TrappingRainWaterII/main.cc
        41.FirstMissingPositive/FirstMissingPositive.cc
        41.FirstMissingPositive/main.cc
        41.FirstMissingPositive/solution.cc
        410.SplitArrayLargestSum/main.cc
        410.SplitArrayLargestSum/solution.cc
        414.ThirdMaximumNumber/main.cc
        414.ThirdMaximumNumber/set.cc
        417.PacificAtlanticWaterFlow/main.cc
        42.TrappingRainWater/1.cc
        42.TrappingRainWater/main.cc
        435.Non-overlappingIntervals/main.cc
        437.PathSumIII/1.cc
        437.PathSumIII/main.cc
        44.WildcardMatching/it.cc
        44.WildcardMatching/main.cc
        44.WildcardMatching/solution.cc
        448.FindAllNumbersDisappearedInAnArray/main.cc
        448.FindAllNumbersDisappearedInAnArray/solution.cc
        449.SerializeandDeserializeBST/1.cc
        449.SerializeandDeserializeBST/main.cc
        45.JumpGameII/main.cc
        450.DeleteNodeinABST/1.cc
        450.DeleteNodeinABST/main.cc
        452.MinimumNumberOfArrowsToBurstBalloons/main.cc
        455.AssignCookies/main.cc
        46.Permutations/p.cc
        46.Permutations/Permutation.cc
        46.Permutations/solution.cc
        464.CanIWin/main.cc
        47.PermutationsII/solution.cc
        472.ConcatenatedWords/1.cc
        472.ConcatenatedWords/main.cc
        473.MatchstickstoSquare/main.cc
        485.MaxConsecutiveOnes/main.cc
        488.ZumaGame/1.cc
        488.ZumaGame/dfs.cc
        488.ZumaGame/main.cc
        488.ZumaGame/test.cc
        491.IncreasingSubsequences/1.cc
        491.IncreasingSubsequences/2.cc
        491.IncreasingSubsequences/main.cc
        4Sum/four_sum.cc
        501.FindModeInBinarySearchTree/main.cc
        507.PerfectNumber/main.cc
        508.MostFrequentSubtreeSum/1.cc
        508.MostFrequentSubtreeSum/main.cc
        513.FindBottomLeftTreeValue/1.cc
        513.FindBottomLeftTreeValue/main.cc
        514.FreedomTrail/1.cc
        514.FreedomTrail/2.cc
        514.FreedomTrail/3.cc
        514.FreedomTrail/dp.cc
        514.FreedomTrail/main.cc
        514.FreedomTrail/solution.cc
        515.FindLargestValueInEachTreeRow/1.cc
        515.FindLargestValueInEachTreeRow/main.cc
        529.Minesweeper/main.cc
        531.LonelyPixelI/main.cc
        532.K-diffPairsInAnArray/main.cc
        533.LonelyPixelII/main.cc
        536.ConstructBinaryTreefromString/main.cc
        538.ConvertBSTtoGreaterTree/main.cc
        539.MinimumTimeDifference/main.cc
        541.ReverseStringII/main.cc
        542.01Matrix/main.cc
        543.DiameterofBinaryTree/main.cc
        544.OutputContestMatches/1.cc
        544.OutputContestMatches/main.cc
        545.BoundaryofBinaryTree/main.cc
        546.RemoveBoxes/main.cc
        55.JumpGame/main.cc
        601.HumanTrafficofStadium/434.number-of-segments-in-a-string.cpp
        632.SmallestRange/main.cc
        653.TwoSumIV/653.two-sum-iv-input-is-a-bst.cpp
        668.KthSmallestNumberInMultiplicationTable/main.cpp
        691.StickersToSpellWord/691.stickers-to-spell-word.cpp
        691.StickersToSpellWord/main.cc
        719.FindKthSmallestPairDistance/main.cpp
        75.SortColors/s.cc
        75.SortColors/solution.cc
        75.SortColors/sort_colors.cc
        76.MinimumWindowSubstring/main.cc
        78.Subsets/solution.cc
        78.Subsets/ss.cc
        78.Subsets/subsets.cc
        90.SubsetsII/solution.cc
        94.BinaryTreeInorderTraversal/solution.cc
        94.BinaryTreeInorderTraversal/stack.cc
        95.UniqueBinarySearchTreesII/main.cc
        96.UniqueBinarySearchTrees/main.cc
        98.ValidateBinarySearchTree/1.cc
        98.ValidateBinarySearchTree/main.cc
        99.RecoverBinarySearchTree/1.cc
        99.RecoverBinarySearchTree/2.cc
        99.RecoverBinarySearchTree/recursive.cc
        99.RecoverBinarySearchTree/solution.cc
        AddBinary/add_binary.cc
        Amazon/DiameterOfBinaryTree/main.cc
        Amazon/PalindromePartition/main.cc
        atoi/atoi.cc
        Candy/Candy.cc
        CloneGraphs/CloneGraphs.cc
        39.CombinationSum/combsum.cc
        40.CombinationSumII/combsum2.cc
        77.Combination/combine.cc
        ConstructBtFromInorderAndPostorderTraverse/build_tree.cc
        ContainerWithMostWater/container.cc
        Contest.2017.03.05/k-diff/main.cc
        ConvertSortedArrayToBst/csab.cc
        CountAndSay/count_and_say.cc
        CountAndSay/ss.cc
        CountingBits/CountingBits.cc
        Daily/20161206.LeftViewTree/main.cc
        Daily/20161208.StringChain/main.cc
        Daily/Include/tree.cc
        91.DecodeWay/decode_way.cc
        115.DistinceSubsequence/ds.cc
        72.EditDistance/edit_distance.cc
        EvaluateReversePolishNotation/evalRPN.cc
        FindKthOfTwoSortedArray/FindKthOfTwoSortedArray.cc
        FindShortestSubarrayContainingAllElements/main.cc
        FlatenTree/flatten_tree.cc
        GasStation/GasStation.cc
        geeksforgeeks/Count1sInSortedBinaryArray/main.cc
        geeksforgeeks/DoubledLinkedListMergeSort/main.cc
        geeksforgeeks/DoubleLinkedListQuickSort/main.cc
        geeksforgeeks/IterativeQuickSort/main.cc
        geeksforgeeks/KClosestElements/main.cc
        geeksforgeeks/MinUnsortedSubarray/main.cc
        geeksforgeeks/NearlySorted/main.cc
        geeksforgeeks/SearchInAlmostSortedArray/main.cc
        geeksforgeeks/SingleLinkedListQuickSort/main.cc
        GrayCode/gray_code.cc
        84.Histogram/histogram.cc
        IntergerToRoman/int_to_roman.cc
        97.InterleavingString/ils.cc
        LengthOfLastWord/length_of_last_word.cc
        LongestCommonPrefix/lcp.cc
        LongestIncreaseSequeue/solution.cc
        LongestIncreaseSequeue/test.cc
        LongestPalindromicSubstring/longest.cc
        LongestSubStringWithoutRepeat/longest.cc
        LongestValidPatheses/longest.cc
        LRUCache/LRUCache.cc
        MaximalRectangle/maximal_rectangle.cc
        MaximumProductSubarray/MaximumProductSubarray.cc
        MaximumSubarray/MaximumSubarray.cc
        MaxPointsOnALine/MaxPointsOnALine.cc
        MedianOfTwoSortedArray/MedianOfTwoSortedArray.cc
        MergeSortArray/MergeSortArray.cc
        64.MinimumPathSum/MinimumPathSum.cc
        MinimumStringWindow/min_str_window.cc
        MinimumStringWindow/msw.cc
        MinPathSum/min_path_sum.cc
        Multiply/multiply.cc
        51.NQueens/nqueens.cc
        131.Palindrome/Palindrome.cc
        PalindromeII/Palindrome.cc
        ParenthesesOrder/ParenthesesOrder.cc
        PascalTriangle/pascal_triangle.cc
        PascalTriangleII/pascal_triangle.cc
        PerfectSquares/PerfectSquares.cc
        PermutationSequence/PermutationSequence.cc
        10.RegularExpressionMatching/re.cc
        RemoveDupFromSortedArray/remove_dup.cc
        RemoveDupFromSortedList/remove_dup.cc
        RemoveDupFromSortedListII/remove_dup2.cc
        ReorderList/ReorderList.cc
        93.RestoreIpAddress/restore_ip_addr.cc
        7.ReverseInteger/ReverseInterger.cc
        ReverseNodesInKGroups/reverse.cc
        ReverseWord/ReverseWord.cc
        ReverseWords/ReverseWords.cc
        87.ScrambleString/ass.cc
        87.ScrambleString/ScrambleString.cc
        87.ScrambleString/solution.cc
        Search2DMatrix/Search2DMatrix.cc
        SearchInRotatedSortedArray/search.cc
        Set/set.cc
        SetMatrixZeros/set_matrix_zeros.cc
        71.SimplifyPath/simplify_path.cc
        SingleNumberII/SingleNumberII.cc
        SpiralMatrix/spiral_matrix.cc
        69.sqrt/sqrt.cc
        SubAndConcat/subconcat.cc
        subsetII/subsetII.cc
        37.sudoku/sudoku.cc
        super2048/super2048.cc
        SurroundedRegions/SurroundedRegions.cc
        TextJustification/text_just.cc
        ThreeSumClosest/three_sum_closest.cc
        TrapWater/trap_water.cc
        Triangle/triangle.cc
        65.ValidNumber/valid_number.cc
        44.WildcardMatch/wildcard.cc
        WordBreak/WordBreak.cc
        WordBreakII/WordBreakII.cc
        WordLadder/WordLadder.cc
        WordLadderII/WordLadderII.cc
        79.WordSearch/word_search.cc
        5347.MinimumCost/main.cc
        ZigZag/zz.cc)


add_executable(0.demo 0.demo/main.cc 147.InsertionSortList/solution.cc)

add_executable(329.solution 329.LongestIncreasingPathinaMatrix/2.cpp)
add_executable(373.solution 373.FindKPairsWithSmallestSums/solution.cpp)
add_executable(373.main 373.FindKPairsWithSmallestSums/main.cpp)
add_executable(410.main.1 410.SplitArrayLargestSum/main.1.cc)
add_executable(435.main.1 435.Non-overlappingIntervals/main.1.cc)
add_executable(452.main.1 452.MinimumNumberOfArrowsToBurstBalloons/main.1.cc)

add_executable(502.main 502.IPO/main.cc)
add_executable(502.main.1 502.IPO/main.1.cc)
add_executable(517.main  517.SuperWashingMachines/main.cc)
add_executable(632.main.1 632.SmallestRange/main.1.cc )
add_executable(668.main.1 668.KthSmallestNumberInMultiplicationTable/main.1.cc )
add_executable(678.main 678.ValidParenthesisString/main.cc )
add_executable(679.main 679.24Game/main.cc )
add_executable(679.main.1 679.24Game/main.1.cc )
add_executable(679.main.2 679.24Game/main.2.cc )

add_executable(689.main 689.MaximumSumOf3Non-OverlappingSubarrays/main.cpp)
add_executable(689.main.1 689.MaximumSumOf3Non-OverlappingSubarrays/1.cc)

add_executable(715.solution 715.RangeModule/main.cpp)
add_executable(726.main 726.NumberOfAtoms/main.cpp)
add_executable(726.1 726.NumberOfAtoms/1.cpp 726.NumberOfAtoms/1.cpp)
add_executable(726.main.2 726.NumberOfAtoms/2.cc)
add_executable(726.main.3 726.NumberOfAtoms/3.cc)
add_executable(726.main.4 726.NumberOfAtoms/4.cc)

add_executable(719.main 719.FindKthSmallestPairDistance/main.cpp )
add_executable(732.main 732.MyCalendarIII/main.cc)
add_executable(736.main 736.ParseLispExpression/main.cc )
add_executable(736.main.1 736.ParseLispExpression/main.1.cc )
add_executable(743.main 743.NetworkDelayTime/main.cc )
add_executable(742.main 742.ClosestLeafInABinaryTree/main.cc )
add_executable(749.main 749.ContainVirus/main.cc )
add_executable(753.main 753.CrackingTheSafe/main.cc )
add_executable(757.main 757.SetIntersectionSizeAtLeastTwo/main.cc )
add_executable(759.main 759.EmployeeFreeTime/main.cc )
add_executable(761.main 761.SpecialBinaryString/main.cc )
add_executable(765.main 765.CouplesHoldingHands/main.cc )

add_executable(geeksforgeeks geeksforgeeks/SearchingAndSorting/2/CombSort.cc)
add_executable(lrucache LRUCache/solution.cc)
add_executable(460.main 460.LFUCache/main.cc)
add_executable(768.main 768.MaxChunksToMakeSortedII/main.cc)
add_executable(769.main 769.MaxChunksToMakeSorted/main.cc)
add_executable(25.main 25.ReverseNodesInk-Group/main.cc)
add_executable(25.solution 25.ReverseNodesInk-Group/solution.cc)
add_executable(131.palindrome 131.Palindrome/Palindrome.cc)
add_executable(131.palindrome.dp 131.Palindrome/dp.cc)
add_executable(131.palindrome.dpdfs 131.Palindrome/dp+dfs.cc)
add_executable(62.solution 62.UniquePaths/solution.cc)
add_executable(62.solution.dp 62.UniquePaths/dp.cc)
add_executable(51.solution.dfs 51.NQueens/dfs.cc)
add_executable(1519 WeeklyContest198/1519.cc)

add_executable(1023.CamelcaseMatching.main 1023.CamelcaseMatching/main.cc)
add_executable(438.FindAllAnagramsInAString.main 438.FindAllAnagramsInAString/main.cc)
add_executable(dbg_test util/dbg_test.cc)
