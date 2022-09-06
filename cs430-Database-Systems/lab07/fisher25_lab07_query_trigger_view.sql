select * from Library order by lib_name;
select * from Located_at order by ISBN;
select Title, one.total_copies, one.lib_name from Book inner join Located_at one inner join Located_at two where one.ISBN = Book.ISBN and one.ISBN = two.ISBN and one.lib_name != two.lib_name order by Title;
select lib_name, count(lib_name) from Located_at group by lib_name;

delimiter |

create trigger add_author after insert on Author
	for each row begin
	insert into database_audit (date_time, action) values (NOW(), "INSERT AUTHOR");
	end;|
create trigger add_book after insert on Located_at
	for each row begin
	insert into database_audit (date_time, action) values (NOW(), "INSERT BOOK INTO LIBRARY");
	end;|
create trigger delete_book after delete on Located_at
	for each row begin
	insert into database_audit (date_time, action) values (NOW(), "DELETE BOOK FROM LIBRARY");
	end;|
create trigger update_quantity after update on Located_at
	for each row begin
	insert into database_audit (date_time, action) values (NOW(), "UPDATING QUANTITY OF BOOKS");
	end;|

delimiter ;

create sql security invoker view library_records as 
	select Title, lib_name, group_concat(Written_by.Author_ID) as Authors from 
	Located_at natural join Book natural join Written_by group by Title, lib_name;

select r.Title, r.Authors, l.shelf, r.lib_name from library_records r natural join Located_at l natural join Book b order by Title;

