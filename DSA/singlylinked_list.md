Linked list = dynamic array alternative.
Why? Because memory is unpredictable, and we need flexible size.
Tradeoff: fast insertion/removal, slow traversal.
Rule: always keep head, maybe tail for O(1) end inserts.
Visual: train cars. Each knows next. NULL = end.

