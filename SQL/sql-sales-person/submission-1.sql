-- Write your query below
WITH cte AS (
    SELECT 
        c.com_id, 
        c.name,
        o.sales_id,
        o.order_id
    FROM company c
    JOIN orders o
        ON c.com_id = o.com_id
    WHERE c.name = 'CRIMSON'
)
SELECT s.name
FROM sales_person s
LEFT JOIN cte 
    ON s.sales_id = cte.sales_id
WHERE cte.order_id is NULL