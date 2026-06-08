program olymp1;
var h1,m1,h2,m2,k,a,b,c,d:integer;
begin
  readln(h1);
  readln(m1);
  readln(h2);
  readln(m2);
  k:=0;
  repeat
    a:=h1 div 10;
    b:=h1 mod 10;
    c:=m1 div 10;
    d:=m1 mod 10;
    if ((a=c)and(b=d))or((a=d)and(b=c))or((a+1=b)and(b+1=c)and(c+1=d)) then 
      k:=k+1;
    if m1<60 then
      m1:=m1+1
    else begin
      m1:=0;
      h1:=h1+1;
    end;
    if h1=24 then
      h1:=0;
  until (h1=h2)and(m1>m2);
  writeln(k);
end.