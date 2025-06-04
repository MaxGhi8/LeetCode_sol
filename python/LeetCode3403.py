class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends == 1:
            return word

        max_len = len(word) - numFriends + 1
        maxSubword = ""

        # Check all the word with the maximum len
        for i in range(numFriends):
            w = word[i : i + max_len]
            if w > maxSubword:
                maxSubword = w

        # Check words with not maximum len that are at the end of the string
        for i in range(1, max_len):
            w = word[-i:]
            if w > maxSubword:
                maxSubword = w

        return maxSubword
