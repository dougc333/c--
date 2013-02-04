CS107-Assign1
=============
https://courseware.stanford.edu/pg/assignments/view/332571/assignment-1-string-fragment-reassembly

Greedy match and merge
The program operates in a series of rounds. In each round, it searches the collection to find the pair of fragments with the maximal overlap match and merges those two fragments. This match/merge operation decreases the total number of fragments by one. The program repeats the match/merge operation until only one fragment remains.

Matching a pair of fragments means finding a position to align the two for the maximal overlapping match. In each round, you find the pair of fragments in the collection with longest such overlap and merge them.

Consider a collection with fragments s1-s4 shown below (extra spaces were inserted between letters for clarity) :
s1:   a l l   i s   w e l l
s2:   e l l   t h a t   e n
s3:   h a t   e n d
s4:   t   e n d s   w e l l
On the first round, the longest overlap found is a 6-character overlap between s2 and s3 when aligned as below:
     e l l   t h a t   e n
               h a t   e n d 
The fragments s2 and s3 would be removed and replaced with their merged result s5:
s5:  e l l   t h a t   e n d 
The new, merged fragment is a candidate for future rounds; the two fragments it was composed from are no longer considered. On the next round, the longest overlap is 5 characters between s5 and s4 aligned as below:
     e l l   t h a t   e n d
                   t   e n d s   w e l l
The fragments s5 and s4 would be removed and replaced with their merged result s6:
s6:  e l l   t h a t   e n d s   w e l l
The last round merges s1 and s6 in their maximal overlap alignment of 3 characters:
      a l l   i s   w e l l
                      e l l   t h a t   e n d s   w e l l
The one remaining fragment is the final result:
      a l l   i s   w e l l   t h a t   e n d s   w e l l
A match is also possible when one fragment is completely contained within another. Consider:
s1:    s   w e l l   t  h  a
s2:    e l l
The entire fragment s2 is contained within s1. When these two fragments are merged, the result is simply s1.

Your program can break ties arbitrarily. If several pairs have the same maximal length overlap, choose whichever pair you like to merge. If there are two equally maximal alignments for a pair (e.g. abxy and xyab can merge to either abxyab or xyabxy), you can choose either. If two fragments have no overlap, their merge is simply the concatenation of the two strings, which can be done in either order. Because of differences in how ties are broken, some inputs can have more than one possible correct reconstruction. However, most fragment collections have such extensive redundancy that there is exactly one correct reassembled result.
 
Note that all characters in the overlap must match exactly in sequence. Unlike DNA strands which have "noisy" data in which gaps and mutations must be accommodated for, the sequences in our simplified process are always "clean" and must match perfectly to be merged.
 
A little computer science theory
Optimal reassembly is an example of the shortest common superstring problem, a classic problem in theoretical computer science. Given a set of strings S, find the shortest string that contains all the strings in S as substrings. The solution for shortest superstring is NP-hard, which means it is believed that no polynomial (i.e. "efficient") solution exists. Our approach is a greedy strategy because it finds a local maximum, the longest overlap, and assumes making this locally optimal choice will eventually lead to the globally optimal result. It might, but it might not. Our approach will find a common superstring, but it is not guaranteed to be the shortest. We are not asking you to guarantee an optimal result -- that is a more difficult problem and its solution would run much more slowly. 

Implementation details
Usage. The program takes one required argument, the filename containing the fragments. If no filename is given or the file cannot be opened, you should give a helpful and appropriate error message and exit. If the file is valid, the program reassembles the fragments using the greedy maximal match/merge and prints the final merged result.
Fragment file format. An input file follows this format:
#fragment 1##fragment 2#...#fragment N#
Each fragment is wrapped in a starting and ending # marker. A fragment can contain any character other than #, including spaces and newlines. A fragment must contain at least one character and at most 1000 characters. A file contains at most 20,000 fragments.
Malformed inputs. A robust program behaves reasonably even in the presence of incorrect inputs  Specific invalid files we may test on include an input with a malformed fragment (i.e. doesn't fit the required format #chars#) or a fragment longer than the 1000-character maximum. You should detect these situations, report the problem to the user with a clear, specific, and informative message, and exit.  We will not test on files that are malformed with respect the number of fragments (i.e. you may ignore the possibility of a completely empty file containing no fragments or a very long file containing more than 20,000 fragments).
String-handling. Fragments should be represented using C-strings. Each C-string should be appropriately sized for its contents (not sized to some arbitrary maximum).
Output conformance. The expected output is the correctly reassembled result with no other additional printing. Use our sanity check tool to verify that your output is conformant to our specification. Your error messages for the robustness cases are not required to exactly match the sample solution, but whatever wording you choose should be equally clear and appropriate.  All feedback should be "actionable" -- communicate the necessary what/where/how specifics so the user can take action to resolve the error.
Testing. We provide some fragment files and a sample executable that can be used to compare for expected output. You will want to create additional test inputs, especially small ones that allow you to focus on specific behaviors. Using custom tests with sanity check will be valuable.
Memory.  We expect your program to run cleanly under the valgrind tool with no memory errors nor leaks reported. See the CS107 guide to valgrind if you missed this in lab1. Running your program under valgrind is as simple as:
	valgrind --tool=memcheck --leak-check=full program-to-execute args
Efficiency. We have modest expectations about efficiency. It is expected that each round will re-examine all N^2 pairings to find the maximal overlap, which slows down on large fragment files. You are not asked to devise anything clever to avoid this. Our sample solution takes the straightforward approach and can be used as a benchmark of what constitutes reasonable performance.  If you run noticeably more slowly, then you have a design/algorithmic weakness to address. 
Design/style/readability. From CS106, you should be well-versed in good coding practice and we expect your solutions to show thoughtful design and attention to readability. You know the drill: decompose into manageable functions, comment where appropriate, factor common code to avoid duplication, no global variables, strive for readability in all ways, and so on. See Nick Parlante's stolen prose on landmarks in coding quality.
Don't miss our companion page of advice and hints specific to this assignment!
