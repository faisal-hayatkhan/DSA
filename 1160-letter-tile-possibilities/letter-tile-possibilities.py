class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        count = Counter(tiles)

        def rec(count):
            total = 0
            for ch in count:
                if count[ch] > 0:
                    total += 1
                    count[ch] -= 1
                    total += rec(count)
                    count[ch] += 1 
            return total

        return rec(count)
