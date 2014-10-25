create table customer(
    custkey char(4),
    nationkey char(4),
    mktsegment char(16),
    acctbal int,
    primary key (custkey)
);

create table orders(
    orderkey char(4),
    clerk varchar(4),
    custfk char(4),
    primary key (orderkey),
    foreign key (custfk) references customer(custkey)
);
