# StringSet-Class

## Problem Definition:

Document Similarity

Document similarity measures are very important in the field of information
retrieval and search engines. They are measures that tell us how similar to documents are in terms of
their word content. They can be used to find similar documents or to find how close a document is to a
query on a search engine. There are many of such measures. In this problem, you will develop:

- Define a class called StringSet that will store a set of C++ strings. Use an array or a vector to
store the strings. Create a constructor that takes a file name and loads the words in it (ignoring
punctuation and turning text to lower case). Write another constructor that takes a string and loads it
and breaks it to tokens. Write member functions to add a string to the set, remove a string from the
set, clear the entire set, return the number of strings in the set, and output all strings in the set.
Overload the + operator to return the union of two StringSet objects. Overload the * operator
so that it returns the intersection of two StringSet objects. Write a program to test all functions.

- Add a member function that computes the similarity between the current StringSet and an input
parameter of type StringSet. Similarity is measured by binary cosine coefficient. The
coefficient is a value between 0 and 1, where 1 indicates that the query (or document) is very
similar to the document and 0 indicates that the query has no keywords in common with the
document. This approach treats each document as a set of words. For example, given the following
sample document:

“Chocolate ice cream, chocolate milk, and chocolate bars are delicious.”

This document would be parsed into keywords where case is ignored and punctuation discarded and
turned into the set containing the words {chocolate, ice, cream, milk, and, bars, are, delicious}. An
identical process is performed on the query to turn it into a set of strings. Once we have a query Q
represented as a set of words and a document D represented as a set of words (each word counts
once even if repeated in document multiple times), the similarity between Q and D is computed by:

Sim = The size of set of common words / (sqrt size of D * sqrt size of Q)

Write a program to test the classes and run sample queries on sample documents
