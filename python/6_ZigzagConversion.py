"""
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
"""

class Solution(object):
    def convert(self, s, numRows):
        if numRows == 1 or numRows >= len(s):
            return s
        # This is a vague sentence for python beginers
        L = [''] * numRows
        # it can be replaced by the following:
        # L = []
        # for i in range(0, numRows):
        #     L.append('')
        # so if numRows = 3, L = ['', '', '']
        index, step = 0, 1

        for x in s:
            L[index] += x
            #@1 start #
            if index == 0:
                step = 1
            elif index == numRows -1:
                step = -1
            #@1 end  #
            # I like to explain the part above
            # take the str "PAYPALISHIRING" for example:
            # We start with variable index with the value 0, step with the value 1
            # Each row added with the next char
            # If we reach the bottommost row, we need to turn to the next above row, so we change the step value to -1
            # we keep the step value until we reach topmost row. DON'T CHANGE IT!
            # Again, if we reach the topmost row, we need to reset the step value to 1
            # What we need to remember is:
            # the zigzag pattern is just a pictorial image for us to have a better understanding
            # What the trick of algorithm is actually add the next char of the given string to different rows.
            # Don't really think how to move the cursor in the matrix.
            # It's really misleading way you think of this. Even it works, it's not efficient.
            index += step

        return ''.join(L)