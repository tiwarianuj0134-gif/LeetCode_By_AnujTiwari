SELECT
    t.request_at AS Day,
    ROUND(
        AVG(
            CASE
                WHEN t.status IN (
                    'cancelled_by_client',
                    'cancelled_by_driver'
                ) THEN 1.0
                ELSE 0.0
            END
        ),
        2
    ) AS `Cancellation Rate`
FROM Trips AS t
JOIN Users AS c
    ON t.client_id = c.users_id
JOIN Users AS d
    ON t.driver_id = d.users_id
WHERE
    t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
    AND c.banned = 'No'
    AND d.banned = 'No'
GROUP BY t.request_at;
