# Write your MySQL query statement below
SELECT id, movie, description, rating
FROM Cinema
WHERE id % 2 != 0 && description != 'boring'
ORDER BY rating DESC;  #fakt vrchi query lihili tr rating: 8.9 and then 9.1 yete, but we want ulta. So this statm