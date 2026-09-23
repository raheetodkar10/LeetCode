# Write your MySQL query statement below
SELECT MAX(num) as num  #nusta MAX(num) lihila, tr O/P mde  MAX(num) will be title of table
FROM MyNumbers
WHERE num IN (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
);