# Write your MySQL query statement below
SELECT p.product_name , SUM(o.unit) AS unit   #SUM(o.unit): total of id 1 is: 60 + 70 = 130. So the product should be included.
FROM Products p
JOIN Orders o
ON p.product_id = o.product_id
WHERE order_date >= '2020-02-01' AND order_date < '2020-03-01'
GROUP BY p.product_id, p.product_name
HAVING SUM(o.unit) >= 100;