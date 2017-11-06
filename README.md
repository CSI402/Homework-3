# Homework-3

A. Purpose. Search about “indexing” in Google and you will get results related to FamilySearch
services or even investment articles. This assignment has nothing to do with either of these.
Instead, our focus here will be on indexing files. A google search on “indexing files” return results
related to improving file search performance in Windows among others. Indexing is an essential
preprocessing step for searching. During indexing data is collected, parsed, and stored to facilitate
fast and accurate information retrieval. Index design incorporates interdisciplinary concepts from
linguistics, cognitive psychology, mathematics, informatics, and computer science. Indexing has
become increasingly important for web searches due to the large number of documents that are
available on the Web.
The purpose of an index is to optimize speed and performance in finding relevant data for
a search query. Without an index, a search engine would have to scan every document, which
would require considerable time and computing power. As an example, while an index of 10, 000
documents can be queried within milliseconds, a sequential scan of every word in 10, 000 documents,
each consisting of 1, 000 words on average could take hours. The additional storage required to
store the index, as well as the considerable increase in the time required for an update to take
place, are traded off for the time saved during information retrieval.
Your task in this assignment is to develop an indexing program, called indexer. Given a set
of files, your program should parse the files and create an inverted index, which will map each
term found in the files to the subset of files that contain that term. In your indexer, you will also
maintain the frequency with which each term appears in each file. See the examples below for
details. The inverted index should be maintained in sorted order by word. See the example below
for details.
For simplicity, we will define terms as any sequence of consecutive alphanumeric characters (a-z,
A-Z, 0-9). All other characters are to be treated as separators. Examples of terms according to
the previous definition include ‘‘a’’, ‘‘aba’’, ‘‘c123’’, ‘‘1’’, ‘‘454’’. If a file contains
“This is an//$example12”, your program should tokenize this text as follows: ‘‘this’’, ‘‘is’’,
‘‘an’’, ‘‘example12’’. See the example below for details.
The purpose of this assignment is to familiarize yourself with (i) C programming, (ii) splitting a
program into multiple files (including header files), (iii) using make and makefile, (iv) file operations,
(v) directory operations, (vi) defining and using data structures, and (vi) observing the performance
of these structures for search. Notice that objectives (i)-(v) are the same as in Programming
Assignments 1 and 2. The necessary information about splitting a program into multiple files
(including header files), using make and makefile, file and directory operations, links, and necessary
1
data structures for this assignment have already been presented in class.
