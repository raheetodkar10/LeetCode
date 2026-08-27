# Write your MySQL query statement below
SELECT w1.id
FROM Weather w1
JOIN Weather w2
ON DATEDIFF(w1.recordDate, w2.recordDate) = 1   #w1 date is exactly 1 day after w2 date . So: w1 = today   w2 = yesterday
WHERE w1.temperature>w2.temperature;

#as pn lihu shakto:
#SELECT w1.id
#FROM Weather w1, Weather w2
#WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1
#AND w1.temperature > w2.temperature;