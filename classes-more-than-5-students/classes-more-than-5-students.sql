# Write your MySQL query statement below
select class from 
(select class , count(distinct student) as cnt from courses group by class) as temp where cnt>=5;