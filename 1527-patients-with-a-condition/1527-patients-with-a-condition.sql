# Write your MySQL query statement below
SELECT patient_id, patient_name, conditions 
FROM Patients
#GROUP BY conditions
WHERE conditions LIKE 'DIAB1%'   #'%diab1%' : contains diab1 anywhere    #'%DIAB1':DIAB1 must be at the end of the string.
OR conditions LIKE '% DIAB1%';   #down:

#'DIAB1%' matches DIAB1, DIAB1 ABC
#'% DIAB1%' matches ABC DIAB1, ABC DIAB1 XYZ
#SQL order is: SELECT  FROM  WHERE  GROUP BY  ORDER BY