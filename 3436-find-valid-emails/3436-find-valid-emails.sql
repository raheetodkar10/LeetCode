# Write your MySQL query statement below
SELECT user_id, email
FROM Users
WHERE email REGEXP '^[A-Za-z0-9_]+@[A-Za-z]+[.]com$'  #REGEXP: checks character patterns and restrictions ,  LIKE: checks text patterns.
ORDER BY user_id ASC;

#^ -> Start of email , [A-Za-z0-9_]+ ->	Username: letters, digits, underscores  , [.] -> Actual dot , com -> Must end with com , $ -> End of email