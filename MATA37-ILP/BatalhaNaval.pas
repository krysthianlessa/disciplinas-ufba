program BatalhaNaval;

uses crt;

type
  armazenamento = record
    embarcacao: string[1];
    posatingidas: integer;
  end;
  
  embarcacoes = array [1..7] of armazenamento;
  matrizint = array [0..9,0..9] of integer;
  matrizstr = array [0..9,0..9] of string;
  
  procedure tabulcomposi (var nome: string; tabuleiro: matrizstr);
  
  var
  i, j: integer;
  
  begin
  writeln (nome);
  writeln ('# 0 1 2 3 4 5 6 7 8 9');
  for i:= 0 to 9 do
    begin
      write (i,' ');
      for j:= 0 to 9 do
        write (tabuleiro[i,j],' ');
      writeln;
    end;
  writeln;
  end;  

  procedure batalhanaval;

  begin
    writeln ('======================================================================');
    writeln ('BATALHA NAVAL':35);
    writeln ('======================================================================');
    writeln;
  end;

  procedure portaviao(var mat: matrizint);

  var
  dir: char;
  coord: string[3];
  c1, c2, erro: integer;
  
  begin
    writeln ('*Porta-Aviao*');
    write ('Direcao: ');
    readln (dir);
    write ('Coordenadas: ');
    readln (coord);
    val(coord[1], c1, erro);
    val(coord[3], c2, erro);
    writeln;

    if ((dir = 'h') and (c2 > 4)) or ((dir = 'v') and (c1 > 4)) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;          
      until ((dir = 'h') and (c2 <= 4)) or ((dir = 'v') and (c1 <= 4));
    end;
    if ((dir = 'h') and ((mat[c1,c2]<>9) or (mat[c1,c2+1]<>9) or (mat[c1,c2+2]<>9) or (mat[c1,c2+3]<>9) or (mat[c1,c2+4]<>9) or (mat[c1,c2+5]<>9))) or 
       ((dir = 'v') and ((mat[c1,c2]<>9) or (mat[c1+1,c2]<>9) or (mat[c1+2,c2]<>9) or (mat[c1+3,c2]<>9) or (mat[c1+4,c2]<>9) or (mat[c1+5,c2]<>9))) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;
      until ((dir = 'h') and ((mat[c1,c2]=9) and (mat[c1,c2+1]=9) and (mat[c1,c2+2]=9) and (mat[c1,c2+3]=9) and (mat[c1,c2+4]=9) and (mat[c1,c2+5]=9))) or 
            ((dir = 'v') and ((mat[c1,c2]=9) and (mat[c1+1,c2]=9) and (mat[c1+2,c2]=9) and (mat[c1+3,c2]=9) and (mat[c1+4,c2]=9) and (mat[c1+5,c2]=9)));
    end;
    if dir = 'h' then
    begin
      mat[c1,c2]:=1;
      mat[c1,c2+1]:=1;
      mat[c1,c2+2]:=1;
      mat[c1,c2+3]:=1;
      mat[c1,c2+4]:=1;
      mat[c1,c2+5]:=1;  
    end;
    if dir = 'v' then
    begin
      mat[c1,c2]:=1;
      mat[c1+1,c2]:=1;
      mat[c1+2,c2]:=1;
      mat[c1+3,c2]:=1;
      mat[c1+4,c2]:=1;
      mat[c1+5,c2]:=1;
    end;
  end;

    procedure encouracado(var mat: matrizint);

  var
  dir: char;
  coord: string[3];
  c1, c2, erro: integer;
  
  begin
    writeln ('*Encouracado*');
    write ('Direcao: ');
    readln (dir);
    write ('Coordenadas: ');
    readln (coord);
    val(coord[1], c1, erro);
    val(coord[3], c2, erro);
    writeln;

    if ((dir = 'h') and (c2 > 5)) or ((dir = 'v') and (c1 > 5)) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;          
      until ((dir = 'h') and (c2 <= 5)) or ((dir = 'v') and (c1 <= 5));
    end;
    if ((dir = 'h') and ((mat[c1,c2]<>9) or (mat[c1,c2+1]<>9) or (mat[c1,c2+2]<>9) or (mat[c1,c2+3]<>9) or (mat[c1,c2+4]<>9))) or 
       ((dir = 'v') and ((mat[c1,c2]<>9) or (mat[c1+1,c2]<>9) or (mat[c1+2,c2]<>9) or (mat[c1+3,c2]<>9) or (mat[c1+4,c2]<>9))) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;
      until ((dir = 'h') and ((mat[c1,c2]=9) and (mat[c1,c2+1]=9) and (mat[c1,c2+2]=9) and (mat[c1,c2+3]=9) and (mat[c1,c2+4]=9))) or 
            ((dir = 'v') and ((mat[c1,c2]=9) and (mat[c1+1,c2]=9) and (mat[c1+2,c2]=9) and (mat[c1+3,c2]=9) and (mat[c1+4,c2]=9)));
    end;
    if dir = 'h' then
    begin
      mat[c1,c2]:=2;
      mat[c1,c2+1]:=2;
      mat[c1,c2+2]:=2;
      mat[c1,c2+3]:=2;
      mat[c1,c2+4]:=2;
    end;
    if dir = 'v' then
    begin
      mat[c1,c2]:=2;
      mat[c1+1,c2]:=2;
      mat[c1+2,c2]:=2;
      mat[c1+3,c2]:=2;
      mat[c1+4,c2]:=2;
    end;
  end;

  procedure navio(var mat: matrizint);

  var
  dir: char;
  coord: string[3];
  c1, c2, erro: integer;
  
  begin
    writeln ('*Navio*');
    write ('Direcao: ');
    readln (dir);
    write ('Coordenadas: ');
    readln (coord);
    val(coord[1], c1, erro);
    val(coord[3], c2, erro);
    writeln;

    if ((dir = 'h') and (c2 > 6)) or ((dir = 'v') and (c1 > 6)) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;          
      until ((dir = 'h') and (c2 <= 6)) or ((dir = 'v') and (c1 <= 6));
    end;
    if ((dir = 'h') and ((mat[c1,c2]<>9) or (mat[c1,c2+1]<>9) or (mat[c1,c2+2]<>9) or (mat[c1,c2+3]<>9))) or 
       ((dir = 'v') and ((mat[c1,c2]<>9) or (mat[c1+1,c2]<>9) or (mat[c1+2,c2]<>9) or (mat[c1+3,c2]<>9))) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;
      until ((dir = 'h') and ((mat[c1,c2]=9) and (mat[c1,c2+1]=9) and (mat[c1,c2+2]=9) and (mat[c1,c2+3]=9))) or 
            ((dir = 'v') and ((mat[c1,c2]=9) and (mat[c1+1,c2]=9) and (mat[c1+2,c2]=9) and (mat[c1+3,c2]=9)));
    end;
    if dir = 'h' then
    begin
      mat[c1,c2]:=3;
      mat[c1,c2+1]:=3;
      mat[c1,c2+2]:=3;
      mat[c1,c2+3]:=3;
    end;
    if dir = 'v' then
    begin
      mat[c1,c2]:=3;
      mat[c1+1,c2]:=3;
      mat[c1+2,c2]:=3;
      mat[c1+3,c2]:=3;
    end;
  end;

  procedure rebocador1(var mat: matrizint);

  var
  dir: char;
  coord: string[3];
  c1, c2, erro: integer;
  
  begin
    writeln ('*Rebocador*');
    write ('Direcao: ');
    readln (dir);
    write ('Coordenadas: ');
    readln (coord);
    val(coord[1], c1, erro);
    val(coord[3], c2, erro);
    writeln;
 
    if ((dir = 'h') and (c2 > 7)) or ((dir = 'v') and (c1 > 7)) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;          
      until ((dir = 'h') and (c2 <= 7)) or ((dir = 'v') and (c1 <= 7));
    end;
    if ((dir = 'h') and ((mat[c1,c2]<>9) or (mat[c1,c2+1]<>9) or (mat[c1,c2+2]<>9))) or 
       ((dir = 'v') and ((mat[c1,c2]<>9) or (mat[c1+1,c2]<>9) or (mat[c1+2,c2]<>9))) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;
      until ((dir = 'h') and ((mat[c1,c2]=9) and (mat[c1,c2+1]=9) and (mat[c1,c2+2]=9))) or 
            ((dir = 'v') and ((mat[c1,c2]=9) and (mat[c1+1,c2]=9) and (mat[c1+2,c2]=9)));
    end;
    if dir = 'h' then
    begin
      mat[c1,c2]:=4;
      mat[c1,c2+1]:=4;
      mat[c1,c2+2]:=4;
    end;
    if dir = 'v' then
    begin
      mat[c1,c2]:=4;
      mat[c1+1,c2]:=4;
      mat[c1+2,c2]:=4;
    end;
  end;
  
  procedure rebocador2(var mat: matrizint);

  var
  dir: char;
  coord: string[3];
  c1, c2, erro: integer;
  
  begin
    writeln ('*Rebocador*'); 
    write ('Direcao: ');
    readln (dir);
    write ('Coordenadas: ');
    readln (coord);
    val(coord[1], c1, erro);
    val(coord[3], c2, erro);
    writeln;

    if ((dir = 'h') and (c2 > 7)) or ((dir = 'v') and (c1 > 7)) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;          
      until ((dir = 'h') and (c2 <= 7)) or ((dir = 'v') and (c1 <= 7));
    end;
    if ((dir = 'h') and ((mat[c1,c2]<>9) or (mat[c1,c2+1]<>9) or (mat[c1,c2+2]<>9))) or 
       ((dir = 'v') and ((mat[c1,c2]<>9) or (mat[c1+1,c2]<>9) or (mat[c1+2,c2]<>9))) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;
      until ((dir = 'h') and ((mat[c1,c2]=9) and (mat[c1,c2+1]=9) and (mat[c1,c2+2]=9))) or 
            ((dir = 'v') and ((mat[c1,c2]=9) and (mat[c1+1,c2]=9) and (mat[c1+2,c2]=9)));
    end;
    if dir = 'h' then
    begin
      mat[c1,c2]:=5;
      mat[c1,c2+1]:=5;
      mat[c1,c2+2]:=5;
    end;
    if dir = 'v' then
    begin
      mat[c1,c2]:=5;
      mat[c1+1,c2]:=5;
      mat[c1+2,c2]:=5;
    end;
  end;

  procedure submarino1(var mat: matrizint);

  var
  dir: char;
  coord: string[3];
  c1, c2, erro: integer;
  
  begin
    writeln ('*Submarino*');
    write ('Direcao: ');
    readln (dir);
    write ('Coordenadas: ');
    readln (coord);
    val(coord[1], c1, erro);
    val(coord[3], c2, erro);
    writeln;

    if ((dir = 'h') and (c2 = 9)) or ((dir = 'v') and (c1 = 9)) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;          
      until ((dir = 'h') and (c2 <> 9)) or ((dir = 'v') and (c1 <> 9));
    end;
    if ((dir = 'h') and ((mat[c1,c2]<>9) or (mat[c1,c2+1]<>9))) or 
       ((dir = 'v') and ((mat[c1,c2]<>9) or (mat[c1+1,c2]<>9))) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;
      until ((dir = 'h') and ((mat[c1,c2]=9) and (mat[c1,c2+1]=9))) or 
            ((dir = 'v') and ((mat[c1,c2]=9) and (mat[c1+1,c2]=9)));
    end;
    if dir = 'h' then
    begin
      mat[c1,c2]:=6;
      mat[c1,c2+1]:=6;
    end;
    if dir = 'v' then
    begin
      mat[c1,c2]:=6;
      mat[c1+1,c2]:=6;
    end;
  end;

  procedure submarino2(var mat: matrizint);

  var
  dir: char;
  coord: string[3];
  c1, c2, erro: integer;
  
  begin
    writeln ('*Submarino*');
    write ('Direcao: ');
    readln (dir);
    write ('Coordenadas: ');
    readln (coord);
    val(coord[1], c1, erro);
    val(coord[3], c2, erro);
    writeln;
 
    if ((dir = 'h') and (c2 = 9)) or ((dir = 'v') and (c1 = 9)) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;          
      until ((dir = 'h') and (c2 <> 9)) or ((dir = 'v') and (c1 <> 9));
    end;
    if ((dir = 'h') and ((mat[c1,c2]<>9) or (mat[c1,c2+1]<>9))) or 
       ((dir = 'v') and ((mat[c1,c2]<>9) or (mat[c1+1,c2]<>9))) then
    begin
      repeat
        writeln ('Posicao Invalida');
        writeln;
        write ('Direcao: ');
        readln (dir);
        write ('Coordenadas: ');
        readln (coord);
        val(coord[1], c1, erro);
        val(coord[3], c2, erro);
        writeln;
      until ((dir = 'h') and ((mat[c1,c2]=9) and (mat[c1,c2+1]=9))) or 
            ((dir = 'v') and ((mat[c1,c2]=9) and (mat[c1+1,c2]=9)));
    end;
    if dir = 'h' then
    begin
      mat[c1,c2]:=7;
      mat[c1,c2+1]:=7;
    end;
    if dir = 'v' then
    begin
      mat[c1,c2]:=7;
      mat[c1+1,c2]:=7;
    end;
  end;

  procedure alteramatstr(var matstr: matrizstr; matint: matrizint);

  var
  i, j: integer;

  begin
    for i:= 0 to 9 do
    begin
      for j:= 0 to 9 do
      begin
        if (matint[i,j] = 9) then
          matstr[i,j]:= 'x';
        if (matint[i,j] = 1) then
          matstr[i,j]:= 'P';
        if (matint[i,j] = 2) then
          matstr[i,j]:= 'E';
        if (matint[i,j] = 3) then
          matstr[i,j]:= 'N';
        if (matint[i,j] = 4) then
          matstr[i,j]:= 'R';
        if (matint[i,j] = 5) then
          matstr[i,j]:= 'R';
        if (matint[i,j] = 6) then
          matstr[i,j]:= 'S';
        if (matint[i,j] = 7) then
          matstr[i,j]:= 'S';
      end;
    end;
  end;
  
  procedure tabuleiro(var jog1, jog2: string; matj1, matj2: matrizint; tabj1, tabj2: matrizstr);
  
  var
  i, j: integer;
  
  begin
    writeln (jog1);
    gotoxy(24,5);
    writeln (jog2);
    writeln ('# 0 1 2 3 4 5 6 7 8 9  # 0 1 2 3 4 5 6 7 8 9');
    for i:= 0 to 9 do
    begin
      write (i,' ');
      for j:= 0 to 9 do
      begin  
        if (matj1[i,j]<0) then
          write (tabj1[i,j],' ')
        else 
          write ('  ');
      end;
      write (' ',i,' ');
      for j:= 0 to 9 do
      begin
        if (matj2[i,j]<0) then
          write (tabj2[i,j],' ')
        else
          write ('  ');
      end;
      writeln;
    end;    
  end;
  

var
 mat_jg1: matrizint;
 mat_jg2: matrizint;
 tabuljg1: matrizstr;
 tabuljg2: matrizstr;
 nomej1, nomej2: string[10];
 i, j: integer;
 embarcjog1: embarcacoes;
 embarcjog2: embarcacoes;
 coord: string[3];
 c1, c2, erro: integer;
 acertos: integer;
 sorteio: integer;
begin
  for i:= 1 to 7 do
  begin
    embarcjog1[i].posatingidas:= 0;
    embarcjog2[i].posatingidas:= 0;
  end;
  
  for i:= 0 to 9 do
    for j:= 0 to 9 do
    begin
      mat_jg1[i,j]:= 9;
      mat_jg2[i,j]:= 9;
    end;
       
  batalhanaval;
  write ('Nome do jogador 1: ');
  readln (nomej1);
  write ('Nome do jogador 2: ');
  readln (nomej2);
  writeln;
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg1, mat_jg1);
  tabulcomposi(nomej1,tabuljg1);
  writeln;
  writeln (nomej1,' posicione suas embarcacoes:');
  writeln;
  portaviao(mat_jg1);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg1, mat_jg1);
  tabulcomposi(nomej1,tabuljg1);
  encouracado(mat_jg1);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg1, mat_jg1);
  tabulcomposi(nomej1,tabuljg1);
  navio(mat_jg1);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg1, mat_jg1);
  tabulcomposi(nomej1,tabuljg1);
  rebocador1(mat_jg1);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg1, mat_jg1);
  tabulcomposi(nomej1,tabuljg1);
  rebocador2(mat_jg1);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg1, mat_jg1);
  tabulcomposi(nomej1,tabuljg1);
  submarino1(mat_jg1);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg1, mat_jg1);
  tabulcomposi(nomej1,tabuljg1);
  submarino2(mat_jg1);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg1, mat_jg1);
  tabulcomposi(nomej1,tabuljg1);
  readln;
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg2, mat_jg2);
  tabulcomposi(nomej2,tabuljg2);
  writeln;
  writeln (nomej2,' posicione suas embarcacoes:');
  writeln;
  portaviao(mat_jg2);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg2, mat_jg2);
  tabulcomposi(nomej2,tabuljg2);
  encouracado(mat_jg2);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg2, mat_jg2);
  tabulcomposi(nomej2,tabuljg2);
  navio(mat_jg2);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg2, mat_jg2);
  tabulcomposi(nomej2,tabuljg2);
  rebocador1(mat_jg2);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg2, mat_jg2);
  tabulcomposi(nomej2,tabuljg2);
  rebocador2(mat_jg2);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg2, mat_jg2);
  tabulcomposi(nomej2,tabuljg2);
  submarino1(mat_jg2);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg2, mat_jg2);
  tabulcomposi(nomej2,tabuljg2);
  submarino2(mat_jg2);
  clrscr;
  batalhanaval;
  alteramatstr(tabuljg2, mat_jg2);
  tabulcomposi(nomej2,tabuljg2);
  readln;
  Randomize;
  sorteio:= Random(2);
  if (sorteio = 0) then
  begin
  while ((embarcjog1[1].posatingidas)<6) or ((embarcjog1[2].posatingidas)<5) or ((embarcjog1[3].posatingidas)<4) or ((embarcjog1[4].posatingidas)<3) or ((embarcjog1[5].posatingidas)<3) or ((embarcjog1[6].posatingidas)<2) or ((embarcjog1[7].posatingidas)<2) and
        ((embarcjog2[1].posatingidas)<6) or ((embarcjog2[2].posatingidas)<5) or ((embarcjog2[3].posatingidas)<4) or ((embarcjog2[4].posatingidas)<3) or ((embarcjog2[5].posatingidas)<3) or ((embarcjog2[6].posatingidas)<2) or ((embarcjog2[7].posatingidas)<2) do
  begin
    acertos:= 0;
    repeat
      clrscr;
      batalhanaval;
      tabuleiro(nomej1, nomej2, mat_jg1, mat_jg2, tabuljg1, tabuljg2);
      writeln;
      writeln ('Vez de ', nomej1);
      writeln;
      write ('coordenadas: ');  
      readln (coord);
      val(coord[1], c1, erro);
      val(coord[3], c2, erro);
      mat_jg2[c1,c2]:= ((mat_jg2[c1,c2])*(-1));
      if ((mat_jg2[c1,c2])<>(-9)) then
        acertos:= acertos+1;
      if ((mat_jg2[c1,c2])=(-1)) then
      begin
        embarcjog2[1].posatingidas:= (embarcjog2[1].posatingidas)+(1);
        if ((embarcjog2[1].posatingidas)>5) then
        begin  
          writeln ('Um Porta-Aviao foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg2[c1,c2])=(-2)) then
      begin
        embarcjog2[2].posatingidas:= (embarcjog2[2].posatingidas)+(1);
        if ((embarcjog2[2].posatingidas)>4) then
        begin  
          writeln ('Um Encouracado foi destruido!');
          readln;
        end;
      end;  
      if ((mat_jg2[c1,c2])=(-3)) then
      begin
        embarcjog2[3].posatingidas:= (embarcjog2[3].posatingidas)+(1);
        if ((embarcjog2[3].posatingidas)>3) then
        begin  
          writeln ('Um Navio foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg2[c1,c2])=(-4)) then
      begin
        embarcjog2[4].posatingidas:= (embarcjog2[4].posatingidas)+(1);
        if ((embarcjog2[4].posatingidas)>2) then
        begin  
          writeln ('Um Rebocador foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg2[c1,c2])=(-5)) then
      begin
        embarcjog2[5].posatingidas:= (embarcjog2[5].posatingidas)+(1);
        if ((embarcjog2[5].posatingidas)>2) then
        begin  
          writeln ('Um rebocador foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg2[c1,c2])=(-6)) then
      begin
        embarcjog2[6].posatingidas:= (embarcjog2[6].posatingidas)+(1);
        if ((embarcjog2[6].posatingidas)>1) then
        begin  
          writeln ('Um Submarino foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg2[c1,c2])=(-7)) then
      begin
        embarcjog2[7].posatingidas:= (embarcjog2[7].posatingidas)+(1);
        if ((embarcjog2[7].posatingidas)>1) then
        begin  
          writeln ('Um Submarino foi destruido!');
          readln;
        end;
      end;
    until ((mat_jg2[c1,c2]) = (-9)) or (acertos = 3) or (((embarcjog2[1].posatingidas)>5) and ((embarcjog2[2].posatingidas)>4) and ((embarcjog2[3].posatingidas)>3) and ((embarcjog2[4].posatingidas)>2) and ((embarcjog2[5].posatingidas)>2) and ((embarcjog2[6].posatingidas)>1) and ((embarcjog2[7].posatingidas)>1));
    acertos:= 0;
    repeat
      clrscr;
      batalhanaval;
      tabuleiro(nomej1, nomej2, mat_jg1, mat_jg2, tabuljg1, tabuljg2);
      writeln;
      writeln ('Vez de ', nomej2);
      writeln;
      write ('coordenadas: ');
      readln (coord);
      val(coord[1], c1, erro);
      val(coord[3], c2, erro);
      mat_jg1[c1,c2]:= ((mat_jg1[c1,c2])*(-1));
      if ((mat_jg1[c1,c2])<>(-9)) then
        acertos:= acertos+1;
      if ((mat_jg1[c1,c2])=(-1)) then
      begin
        embarcjog1[1].posatingidas:= (embarcjog1[1].posatingidas)+(1);
        if ((embarcjog1[1].posatingidas)>5) then
        begin  
          writeln ('Um Porta-Aviao foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg1[c1,c2])=(-2)) then
      begin
        embarcjog1[2].posatingidas:= (embarcjog1[2].posatingidas)+(1);
        if ((embarcjog1[2].posatingidas)>4) then
        begin  
          writeln ('Um Encouracado foi destruido!');
          readln;
        end;
      end;  
      if ((mat_jg1[c1,c2])=(-3)) then
      begin
        embarcjog1[3].posatingidas:= (embarcjog1[3].posatingidas)+(1);
        if ((embarcjog1[3].posatingidas)>3) then
        begin  
          writeln ('Um Navio foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg1[c1,c2])=(-4)) then
      begin
        embarcjog1[4].posatingidas:= (embarcjog1[4].posatingidas)+(1);
        if ((embarcjog1[4].posatingidas)>2) then
        begin  
          writeln ('Um Rebocador foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg1[c1,c2])=(-5)) then
      begin
        embarcjog1[5].posatingidas:= (embarcjog1[5].posatingidas)+(1);
        if ((embarcjog1[5].posatingidas)>2) then
        begin  
          writeln ('Um Rebocador foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg1[c1,c2])=(-6)) then
      begin
        embarcjog1[6].posatingidas:= (embarcjog1[6].posatingidas)+(1);
        if ((embarcjog1[6].posatingidas)>1) then
        begin  
          writeln ('Um Submarino foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg1[c1,c2])=(-7)) then
      begin
        embarcjog1[7].posatingidas:= (embarcjog1[7].posatingidas)+(1);
        if ((embarcjog1[7].posatingidas)>1) then
        begin  
          writeln ('Um Submarino foi destruido!');
          readln;
        end;
      end;
    until ((mat_jg1[c1,c2]) = (-9)) or (acertos = 3) or (((embarcjog1[1].posatingidas)>5) and ((embarcjog1[2].posatingidas)>4) and ((embarcjog1[3].posatingidas)>3) and ((embarcjog1[4].posatingidas)>2) and ((embarcjog1[5].posatingidas)>2) and ((embarcjog1[6].posatingidas)>1) and ((embarcjog1[7].posatingidas)>1));
  end;
  end;
  if (sorteio = 1) then
  begin
  while ((embarcjog1[1].posatingidas)<6) or ((embarcjog1[2].posatingidas)<5) or ((embarcjog1[3].posatingidas)<4) or ((embarcjog1[4].posatingidas)<3) or ((embarcjog1[5].posatingidas)<3) or ((embarcjog1[6].posatingidas)<2) or ((embarcjog1[7].posatingidas)<2) and
        ((embarcjog2[1].posatingidas)<6) or ((embarcjog2[2].posatingidas)<5) or ((embarcjog2[3].posatingidas)<4) or ((embarcjog2[4].posatingidas)<3) or ((embarcjog2[5].posatingidas)<3) or ((embarcjog2[6].posatingidas)<2) or ((embarcjog2[7].posatingidas)<2) do
  begin
  acertos:= 0;
    repeat
      clrscr;
      batalhanaval;
      tabuleiro(nomej1, nomej2, mat_jg1, mat_jg2, tabuljg1, tabuljg2);
      writeln;
      writeln ('Vez de ', nomej2);
      writeln;
      write ('coordenadas: ');
      readln (coord);
      val(coord[1], c1, erro);
      val(coord[3], c2, erro);
      mat_jg1[c1,c2]:= ((mat_jg1[c1,c2])*(-1));
      if ((mat_jg1[c1,c2])<>(-9)) then
        acertos:= acertos+1;
      if ((mat_jg1[c1,c2])=(-1)) then
      begin
        embarcjog1[1].posatingidas:= (embarcjog1[1].posatingidas)+(1);
        if ((embarcjog1[1].posatingidas)>5) then
        begin  
          writeln ('Um Porta-Aviao foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg1[c1,c2])=(-2)) then
      begin
        embarcjog1[2].posatingidas:= (embarcjog1[2].posatingidas)+(1);
        if ((embarcjog1[2].posatingidas)>4) then
        begin  
          writeln ('Um Encouracado foi destruido!');
          readln;
        end;
      end;  
      if ((mat_jg1[c1,c2])=(-3)) then
      begin
        embarcjog1[3].posatingidas:= (embarcjog1[3].posatingidas)+(1);
        if ((embarcjog1[3].posatingidas)>3) then
        begin  
          writeln ('Um Navio foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg1[c1,c2])=(-4)) then
      begin
        embarcjog1[4].posatingidas:= (embarcjog1[4].posatingidas)+(1);
        if ((embarcjog1[4].posatingidas)>2) then
        begin  
          writeln ('Um Rebocador foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg1[c1,c2])=(-5)) then
      begin
        embarcjog1[5].posatingidas:= (embarcjog1[5].posatingidas)+(1);
        if ((embarcjog1[5].posatingidas)>2) then
        begin  
          writeln ('Um Rebocador foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg1[c1,c2])=(-6)) then
      begin
        embarcjog1[6].posatingidas:= (embarcjog1[6].posatingidas)+(1);
        if ((embarcjog1[6].posatingidas)>1) then
        begin  
          writeln ('Um Submarino foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg1[c1,c2])=(-7)) then
      begin
        embarcjog1[7].posatingidas:= (embarcjog1[7].posatingidas)+(1);
        if ((embarcjog1[7].posatingidas)>1) then
        begin  
          writeln ('Um Submarino foi destruido!');
          readln;
        end;
      end;
    until ((mat_jg1[c1,c2]) = (-9)) or (acertos = 3) or (((embarcjog1[1].posatingidas)>5) and ((embarcjog1[2].posatingidas)>4) and ((embarcjog1[3].posatingidas)>3) and ((embarcjog1[4].posatingidas)>2) and ((embarcjog1[5].posatingidas)>2) and ((embarcjog1[6].posatingidas)>1) and ((embarcjog1[7].posatingidas)>1));
    acertos:= 0;
    repeat
      clrscr;
      batalhanaval;
      tabuleiro(nomej1, nomej2, mat_jg1, mat_jg2, tabuljg1, tabuljg2);
      writeln;
      writeln ('Vez de ', nomej1);
      writeln;
      write ('coordenadas: ');  
      readln (coord);
      val(coord[1], c1, erro);
      val(coord[3], c2, erro);
      mat_jg2[c1,c2]:= ((mat_jg2[c1,c2])*(-1));
      if ((mat_jg2[c1,c2])<>(-9)) then
        acertos:= acertos+1;
      if ((mat_jg2[c1,c2])=(-1)) then
      begin
        embarcjog2[1].posatingidas:= (embarcjog2[1].posatingidas)+(1);
        if ((embarcjog2[1].posatingidas)>5) then
        begin  
          writeln ('Um Porta-Aviao foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg2[c1,c2])=(-2)) then
      begin
        embarcjog2[2].posatingidas:= (embarcjog2[2].posatingidas)+(1);
        if ((embarcjog2[2].posatingidas)>4) then
        begin  
          writeln ('Um Encouracado foi destruido!');
          readln;
        end;
      end;  
      if ((mat_jg2[c1,c2])=(-3)) then
      begin
        embarcjog2[3].posatingidas:= (embarcjog2[3].posatingidas)+(1);
        if ((embarcjog2[3].posatingidas)>3) then
        begin  
          writeln ('Um Navio foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg2[c1,c2])=(-4)) then
      begin
        embarcjog2[4].posatingidas:= (embarcjog2[4].posatingidas)+(1);
        if ((embarcjog2[4].posatingidas)>2) then
        begin  
          writeln ('Um Rebocador foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg2[c1,c2])=(-5)) then
      begin
        embarcjog2[5].posatingidas:= (embarcjog2[5].posatingidas)+(1);
        if ((embarcjog2[5].posatingidas)>2) then
        begin  
          writeln ('Um rebocador foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg2[c1,c2])=(-6)) then
      begin
        embarcjog2[6].posatingidas:= (embarcjog2[6].posatingidas)+(1);
        if ((embarcjog2[6].posatingidas)>1) then
        begin  
          writeln ('Um Submarino foi destruido!');
          readln;
        end;
      end;
      if ((mat_jg2[c1,c2])=(-7)) then
      begin
        embarcjog2[7].posatingidas:= (embarcjog2[7].posatingidas)+(1);
        if ((embarcjog2[7].posatingidas)>1) then
        begin  
          writeln ('Um Submarino foi destruido!');
          readln;
        end;
      end;
    until ((mat_jg2[c1,c2]) = (-9)) or (acertos = 3) or (((embarcjog2[1].posatingidas)>5) and ((embarcjog2[2].posatingidas)>4) and ((embarcjog2[3].posatingidas)>3) and ((embarcjog2[4].posatingidas)>2) and ((embarcjog2[5].posatingidas)>2) and ((embarcjog2[6].posatingidas)>1) and ((embarcjog2[7].posatingidas)>1)); 
  end;
  end;
  if ((embarcjog1[1].posatingidas)>5) and ((embarcjog1[2].posatingidas)>4) and ((embarcjog1[3].posatingidas)>3) and ((embarcjog1[4].posatingidas)>2) and ((embarcjog1[5].posatingidas)>2) and ((embarcjog1[6].posatingidas)>1) and ((embarcjog1[7].posatingidas)>1) then
    writeln ('O vencedor e ', nomej2)
  else
    writeln ('O vencedor e ', nomej1);
  readln; 
end.
