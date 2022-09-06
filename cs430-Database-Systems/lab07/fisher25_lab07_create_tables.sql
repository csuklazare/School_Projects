delimiter ;

drop table if exists Borrowed_by,
					 Written_by,
					 Published_by,
					 Publisher_Phone_nums,
					 Author_phone_nums, 
					 Located_at,
					 Library,
				     Author,
					 Phone,
					 Publisher,
					 Book,
					 Member,
					 database_audit;

drop view if exists library_records;
drop trigger if exists add_author;
drop trigger if exists add_book;
drop trigger if exists delete_book;
drop trigger if exists update_quantity; 
create table Author (
    Author_ID int,
    f_name varchar(20),
    l_name varchar(20),
    primary key (Author_ID)
);
create table Phone (
    PNumber varchar(15),
    type char(1),
    primary key (PNumber)
);
create table Publisher (
    PubID int,
    Pub_name varchar(30),
    primary key (PubID)
);
create table Book (
    ISBN varchar(14),
    Title varchar(50),
    Year_Published date,
    primary key (ISBN)
);
create table Member (
    MemberID int,
    f_name varchar(20),
    l_name varchar(20),
	gender char(1),
    DOB date,
    primary key (MemberID)
);
create table Library (
	lib_name varchar(30),
	street varchar(30),
	city varchar(30),
	state char(2),
	primary key (lib_name)
);
create table Located_at (
	lib_name varchar(30),
	ISBN varchar(14),
	total_copies int,
	shelf int,
	floor int,
	copies_not_checked_out int,
	foreign key (lib_name) references Library (lib_name) on delete cascade,
	foreign key (ISBN) references Book (ISBN) on delete cascade
);
create table Borrowed_by (
    MemberID int,
    ISBN varchar(14),
    Checkout_date date,
    Checkin_date date,
    foreign key (MemberID) references Member (MemberID) on delete cascade,
    foreign key (ISBN) references Located_at (ISBN) on delete cascade
);
create table Written_by (
    ISBN varchar(14),
    Author_ID int,
    foreign key (ISBN) references Book (ISBN) on delete cascade,
    foreign key (Author_ID) references Author (Author_ID) on delete cascade,
    primary key (ISBN, Author_ID)
);
create table Published_by (
    ISBN varchar(14),
    PubID int,
    foreign key (ISBN) references Book (ISBN) on delete cascade,
    foreign key (PubID) references Publisher (PubID) on delete cascade,
    primary key (ISBN, PubID)
);
create table Publisher_Phone_nums ( 
	PubID int,
	PNumber varchar(15),
	foreign key (PubID) references Publisher (PubID) on delete cascade,
	foreign key (PNumber) references Phone (PNumber) on delete cascade,
	primary key (PubID, PNumber)
);
create table Author_phone_nums (
	Author_ID int,
	PNumber varchar(15),
	foreign key (Author_ID) references Author (Author_ID) ON DELETE CASCADE,
	foreign key (PNumber) references Phone (PNumber) ON DELETE CASCADE,
	primary key (Author_ID, PNumber)
);
create table database_audit (
	date_time datetime,
	action varchar(30),
	log_num int auto_increment,
	primary key (log_num)
);
