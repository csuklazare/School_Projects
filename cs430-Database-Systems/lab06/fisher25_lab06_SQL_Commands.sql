select 'LOADING Authors' as 'INFO';
source Author.dump;
select 'LOADING Books' as 'INFO';
source Book.dump;
select 'LOADING Members' as 'INFO';
source Members.dump;
select 'LOADING Phone numbers' as 'INFO';
source Phone.dump;
select 'LOADING Publishers' as 'INFO';
source Publisher.dump;
select 'LOADING Publisher phone numbers' as 'INFO';
source Publisher_phone_nums.dump;
select 'LOADING Written_by' as 'INFO';
source Written_by.dump;
select 'LOADING Authors phone numbers' as 'INFO';
source Author_Phone_nums.dump;
select 'LOADING Borrowed_by' as 'INFO';
source Borrowed_by.dump;
select 'LOADING Published_by' as 'INFO';
source Published_by.dump;


select * from Book order by ISBN;
select * from Member order by l_name, f_name;
select * from Author order by l_name, f_name;
select * from Publisher order by Pub_name;
select * from Phone order by PNumber;
select * from Author_phone_nums;
select * from Borrowed_by;
select * from Published_by;
select * from Publisher_Phone_nums;
select * from Written_by;
select f_name, l_name from Member where l_name like "B%";
select * from Book inner join Published_by inner join Publisher where Book.ISBN = Published_by.ISBN and Published_by.PubID = Publisher.PubID and Pub_name = "Coyote Publishing" order by title;
select f_name, l_name, Member.MemberID, Title from Member inner join Borrowed_by inner join Book where Member.MemberID = Borrowed_by.MemberID and Borrowed_by.ISBN = Book.ISBN and Checkin_date IS null;
select f_name, l_name, Author.Author_ID, Title from Author inner join Written_by inner join Book where Author.Author_ID = Written_by.Author_ID and Written_by.ISBN = Book.ISBN;
select f_name, l_Name, a.Author_ID, one.PNumber from Author a inner join Author_phone_nums one inner join Author_phone_nums two where a.Author_ID = one.Author_ID and one.PNumber =  two.PNumber and one.Author_ID != two.Author_ID; 

