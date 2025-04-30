# Write your MySQL query statement below
select visits.customer_id,COUNT(*) as count_no_trans
from visits
left join transactions
on visits.visit_id = transactions.visit_id
where transactions.visit_id is null
group by
 customer_id;