class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        count=0
        citations_length = len(citations)
        output = citations_length

        if citations_length is 0:
            return 0

        if citations_length is 1:
            if citations[0] is 0:
                return 0
            return 1

        for i in range(citations_length):
            for j in range(citations_length):
                if citations[j]>=output:
                    count+=1

            if count >= output:
                break
            output -= 1
            count=0

        return output
