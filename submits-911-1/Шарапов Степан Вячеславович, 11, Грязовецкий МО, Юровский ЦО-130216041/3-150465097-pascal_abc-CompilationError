program reklamacheck;

uses math;

type
    interval = record
        l, r: int64;
    end;

var
    a: array of interval;
    pts: array of int64;
    N, i, j, m: longint;
    T: int64;
    x, startX, endX, L, R, sum, best: int64;

procedure qsort(l, r: longint);
var
    i, j: longint;
    m, t1, t2: int64;
    tmp: interval;
begin
    i := l;  j := r;
    m := a[(l+r) div 2].l;

    repeat
        while a[i].l < m do inc(i);
        while