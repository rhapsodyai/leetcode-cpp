# Write your MySQL query statement below

/*
1179. Reformat Department Table
Easy
SQL Schema

Table: Department

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| revenue       | int     |
| month         | varchar |
+---------------+---------+
(id, month) is the primary key of this table.
The table has information about the revenue of each department per month.
The month has values in ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"].

 

Write an SQL query to reformat the table such that there is a department id column and a revenue column for each month.

The query result format is in the following example:

Department table:
+------+---------+-------+
| id   | revenue | month |
+------+---------+-------+
| 1    | 8000    | Jan   |
| 2    | 9000    | Jan   |
| 3    | 10000   | Feb   |
| 1    | 7000    | Feb   |
| 1    | 6000    | Mar   |
+------+---------+-------+

Result table:
+------+-------------+-------------+-------------+-----+-------------+
| id   | Jan_Revenue | Feb_Revenue | Mar_Revenue | ... | Dec_Revenue |
+------+-------------+-------------+-------------+-----+-------------+
| 1    | 8000        | 7000        | 6000        | ... | null        |
| 2    | 9000        | null        | null        | ... | null        |
| 3    | null        | 10000       | null        | ... | null        |
+------+-------------+-------------+-------------+-----+-------------+

Note that the result table has 13 columns (1 for the department id + 12 for the months).
*/


/*
Success
Details
Runtime: 2345 ms, faster than 5.03% of MySQL online submissions for Reformat Department Table.
Memory Usage: 0B, less than 100.00% of MySQL online submissions for Reformat Department Table.
*/
SELECT D.id,
D1.revenue AS 'Jan_Revenue',
D2.revenue AS 'Feb_Revenue',
D3.revenue AS 'Mar_Revenue',
D4.revenue AS 'Apr_Revenue',
D5.revenue AS 'May_Revenue',
D6.revenue AS 'Jun_Revenue',
D7.revenue AS 'Jul_Revenue',
D8.revenue AS 'Aug_Revenue',
D9.revenue AS 'Sep_Revenue',
D10.revenue AS 'Oct_Revenue',
D11.revenue AS 'Nov_Revenue',
D12.revenue AS 'Dec_Revenue'
FROM (SELECT DISTINCT id FROM Department) D
LEFT JOIN Department D1 ON D.id = D1.id AND D1.month = 'Jan'
LEFT JOIN Department D2 ON D.id = D2.id AND D2.month = 'Feb'
LEFT JOIN Department D3 ON D.id = D3.id AND D3.month = 'Mar'
LEFT JOIN Department D4 ON D.id = D4.id AND D4.month = 'Apr'
LEFT JOIN Department D5 ON D.id = D5.id AND D5.month = 'May'
LEFT JOIN Department D6 ON D.id = D6.id AND D6.month = 'Jun'
LEFT JOIN Department D7 ON D.id = D7.id AND D7.month = 'Jul'
LEFT JOIN Department D8 ON D.id = D8.id AND D8.month = 'Aug'
LEFT JOIN Department D9 ON D.id = D9.id AND D9.month = 'Sep'
LEFT JOIN Department D10 ON D.id = D10.id AND D10.month = 'Oct'
LEFT JOIN Department D11 ON D.id = D11.id AND D11.month = 'Nov'
LEFT JOIN Department D12 ON D.id = D12.id AND D12.month = 'Dec';