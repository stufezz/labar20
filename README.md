Эта программа реализует поиск всех путей в неориентированном графе с использованием обхода в глубину (DFS). Программа считывает граф в виде матрицы смежности из файла, начиная обход из указанной вершины (корня). Все пути, найденные из корневой вершины до возможных конечных вершин, записываются в выходной файл. Ввод данных:

Граф представляется в виде матрицы смежности, которая считывается из входного файла. Корневая вершина задаётся после матрицы. Алгоритм:

Используется обход в глубину (DFS), чтобы найти все возможные пути из корневой вершины. Рекурсивно посещаются все непосещённые соседние вершины. Вывод данных:

Найденные пути записываются в выходной файл в виде последовательностей вершин.