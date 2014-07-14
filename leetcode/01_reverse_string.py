import string
class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        s = s.strip()
        totalLen = len(s)
        if totalLen == 0:
            return ""
        words = [""]
        wId = 0
        id = 0
        while id < totalLen:
            if s[id] == ' ':
                if len(words[wId]) != 0:
                    words.append("")
                    wId += 1
                id += 1
                continue
            else:
                words[wId] += s[id]
                id += 1
        if len(words[wId]) != 0:
            wId += 1
        if wId == 0:
            return ""

        wId -= 1
        result = words[wId]
        wId -= 1
        while wId >= 0:
            result += " " + words[wId]
            wId -= 1
        return result


solution = Solution()
s =  "the sky is blue"
result = solution.reverseWords(s)
print result

print len(solution.reverseWords(" "))
print solution.reverseWords("   a   b ")