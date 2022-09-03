# Высота дерева

*Вычислить высоту данного дерева.*

**Формата входа.** 
Первая строка содержит натуральное число `n`. Вторая строка содержит `n` целых неотрицательных чисел <img src="https://render.githubusercontent.com/render/math?math=parent_0, ..., parent_n-1">. Для каждого <img src="https://render.githubusercontent.com/render/math?math=0 ≤ i ≤ n-1"> <img src="https://render.githubusercontent.com/render/math?math=parent_i"> - родитель `i`-й вершины; если <img src="https://render.githubusercontent.com/render/math?math=parent_i = -1">, то `i` - является корнем. Гарантируется, что корень ровно один. Гарантируется, что данная последовательность задаёт дерево.

**Формат выходаж.**
Высота дерева.

**Ограничения.**
<img src="https://render.githubusercontent.com/render/math?math=1 ≤ n ≤ 10^5">.