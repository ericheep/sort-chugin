import math
from random import randrange

# Reference implementation of a stepped quicksort algorithm
# right now we perform a full "partition" pass on a span, so it's not quite
# as small as we might like.
#
# I think that can be achieved by doing the following:
# 1. add `finished` flag to spans and store intermediate values for `i` and `j`
# 2. take the `finished` flag into consideration in the sort's `step` method and
#    re-append an in-progress span
# 3. update the intermediate `i` and `j` slots on the span during the `sort_across_span` step
#
# Other improvements:
# * an obvious one is to parameterize the comparison function.


class QSortSpan():
    def __init__(self, lower, upper):
        self.lower = lower
        self.upper = upper
        self.mid_point = self.lower + math.floor(self.size() / 2)

    def size(self):
        return self.upper - self.lower

    
class QSort():
    """Stepped quicksort algorithm implementation"""
    
    def __init__(self, lst):
        """Store the list, store the quicksort partition recursion as a tree data structure"""
        self.original_list = list(lst)
        self.reset()

    def reset(self):
        self.list = list(self.original_list)
        self.process_stack = [QSortSpan(0, len(self.original_list) - 1)]

    def step(self):
        """Perform one step of quicksort, where a step is a swapping operation"""
        span = self.process_stack.pop()
        if span.size() > 1:            
            spans = self.sort_across_span(span)            
            for span in spans:
                self.process_stack.append(span)
        return list(self.list)
 
    def sort(self):
        """Fully sort a list using quicksort"""
        while len(self.process_stack) > 0:
            self.step()
        return list(self.list)

    def sort_across_span(self, span):
        """The classic index-based quick sort sort loop we all know and love"""
        pivot = self.list[randrange(span.lower, span.upper)]
        i = span.lower
        j = span.upper
        while i <= j:
            # this whole thing is an obscured ordering
            while self.list[i] < pivot:
                i += 1
            # now, the value i "points to" is greater than pivot

            while self.list[j] > pivot:
                j -= 1
            # now, the value j "points to" is less than the pivot

            # so, list[j] < pivot < list[i]
            # therefore, if i <= j, their respective values are
            # not ordered correction and we should swap
            if i <= j:
                self.swap(i, j)
                i += 1
                j -= 1
        return (QSortSpan(span.lower, j), QSortSpan(i, span.upper))

    def swap(self, i, j):
        tmp = self.list[i]
        self.list[i] = self.list[j]
        self.list[j] = tmp
