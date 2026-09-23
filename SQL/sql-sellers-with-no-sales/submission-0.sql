-- Write your query below
SELECT s.seller_name
FROM seller s
LEFT JOIN orders o
ON s.seller_id = o.seller_id
AND EXTRACT(Year from o.sale_date) = 2020
WHERE o.order_id IS NULL
ORDER BY seller_name