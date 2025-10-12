from typing import List
import heapq

class Solution:
    def candy(self, ratings: List[int]) -> int:
     
        n = len(ratings)
        if n == 0:
            return 0
        if n == 1:
            return 1
        
        # Criar heap com (rating, índice)
        heap = []
        for i, rating in enumerate(ratings):
            heapq.heappush(heap, (rating, i))
        
        candies = [1] * n
        
        # Processar crianças em ordem crescente de rating
        while heap:
            rating, idx = heapq.heappop(heap)
            
            # Verificar vizinho da esquerda
            if idx > 0 and ratings[idx-1] > ratings[idx]:
                if candies[idx-1] <= candies[idx]:
                    candies[idx-1] = candies[idx] + 1
            
            # Verificar vizinho da direita
            if idx < n-1 and ratings[idx+1] > ratings[idx]:
                if candies[idx+1] <= candies[idx]:
                    candies[idx+1] = candies[idx] + 1
        
        return sum(candies)
