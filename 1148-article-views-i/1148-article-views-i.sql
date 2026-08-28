# Write your MySQL query statement below
select distinct author_id as id  #An author can view their own article multiple times. We need to show their ID only once, so distinct
from Views
where author_id=viewer_id  #Only give me rows where the author and viewer are the same person
order by id;