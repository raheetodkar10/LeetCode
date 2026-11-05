# Write your MySQL query statement below
SELECT product_id, product_name, description
FROM products
WHERE REGEXP_LIKE(
    description,     #Check the text inside the description column and find whether it contains a valid serial number
    '(^|[^A-Za-z0-9])SN[0-9]{4}-[0-9]{4}([^A-Za-z0-9]|$)',
    'c'
)
ORDER BY product_id ASC;

# ^ -> Start of string 
# [^A-Za-z0-9] -> Any character except letters and digits 
# SN -> Exact uppercase SN 
# [0-9]{4} -> Exactly 4 digits 
# - -> hyphen is present between the two groups of four digits 
# [0-9]{4} -> Exactly 4 digits 
# ([^A-Za-z0-9]|$) -> Followed by a non-alphanumeric character or end of string 
# 'c' -> Case-sensitive matching 