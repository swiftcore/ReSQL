select o.clerk
from customer c, orders o
where c.acctbal > 1000 and o.custfk = c.custkey

with Candidates as (
     select distinct o.orderkey, o.clerk
     from customer c , orders o
     where c.acctbal > 1000 and o.custfk = c.custkey
),
Filter as (
    select o.orderkey
    from Candidates Cand
       join orders o on Cand.orderkey = o.orderkey
       left outer join customer c on o.custfk = c.custkey
       where c.custkey is null or c.acctbal <= 1000
    union all 
       select orderkey
       from Candidates Cand
       group by orderkey
       having count(*) > 1
)
select distinct clerk
from Candidates Cand
where not exists ( select * from Filter F
    where Cand.orderkey = F.orderkey);


select nationkey, sum(acctbal)
from customer
where mktsegment='building'
group by nationkey

qG:
select nationkey
from customer
where mktsegment='building'
group by nationkey

with Candidates as(
    select custkey,nationkey
    from customer
    where mktsegment='building'
),
Filter as(
    select custkey
    from customer
    where mktsegment!='building'
),
QGCons as (
    select nationkey
    from Candidates c
    where not exists ( select * from Filter f where c.custkey=f.custkey)
    group by nationkey
),
UnFilteredCandidates as (
    select custkey,nationkey,
           min(acctbal) as minBal,
	   max(acctbal) as maxBal
    from customer c
    where mktsegment='building'
    and not exists (select * from Filter where c.custkey=Filter.custkey)
    group by custkey,nationkey
),
FilteredCandidates as (
    select custkey,nationkey,
        case when min(acctbal) > 0 then 0 else min(acctbal) end as minBal,
        case when max(acctbal) > 0 then max(acctbal) else 0 end as maxBal
    from customer c
    where mktsegment='building'
        and exists ( select * from Filter where Filter.custkey=c.custkey)
	and exists ( select * from QGCons where QGCons.nationkey=c.nationkey)
    group by custkey,nationkey
),
UnionCandidates as (
    select * from FilteredCandidates
    union all
    select * from UnFilteredCandidates
)
select nationkey,sum(minbal),sum(maxBal)
 from UnionCandidates
group by nationkey
