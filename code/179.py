from typing import List
import heapq

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        
        if not nums:
            return "0"
        
        str_nums = [str(num) for num in nums]
        
        class Heap:
            def __init__(self):
                self.heap = []
            
            def push(self, item):
                self.heap.append(item)
                self._heapify_up(len(self.heap) - 1)
            
            def pop(self):
                if not self.heap:
                    return None
                
                if len(self.heap) == 1:
                    return self.heap.pop()
                
                # Trocar primeiro com último
                self.heap[0], self.heap[-1] = self.heap[-1], self.heap[0]
                result = self.heap.pop()
                
                # Reorganizar heap
                self._heapify_down(0)
                return result
            
            def _heapify_up(self, index):
                parent = (index - 1) // 2
                if parent >= 0 and self._compare(self.heap[index], self.heap[parent]) > 0:
                    self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
                    self._heapify_up(parent)
            
            def _heapify_down(self, index):
                left = 2 * index + 1
                right = 2 * index + 2
                largest = index
                
                if left < len(self.heap) and self._compare(self.heap[left], self.heap[largest]) > 0:
                    largest = left
                
                if right < len(self.heap) and self._compare(self.heap[right], self.heap[largest]) > 0:
                    largest = right
                
                if largest != index:
                    self.heap[index], self.heap[largest] = self.heap[largest], self.heap[index]
                    self._heapify_down(largest)
            
            def _compare(self, a, b):
                if a + b > b + a:
                    return 1   # a tem prioridade maior
                elif a + b < b + a:
                    return -1  # b tem prioridade maior
                else:
                    return 0   # iguais
        
        heap = Heap()
        for num_str in str_nums:
            heap.push(num_str)
        
        # Extrair elementos na ordem correta
        result = []
        while heap.heap:
            result.append(heap.pop())
        
        # Juntar resultado
        final_result = ''.join(result)
        
        # Caso especial para zeros
        if final_result[0] == '0':
            return "0"
        
        return final_result