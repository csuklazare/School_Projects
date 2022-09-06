select * from Borrowed_by;
select l_name, f_name, MemberID, group_concat(Title) as Book_Titles, lib_name from Member natural join Borrowed_by natural join Located_at natural join Book where checkin_date is NULL group by Title;
