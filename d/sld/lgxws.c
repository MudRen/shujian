// lgxws.c
// ½����������
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
�˴���½�����򸾵����ң����������һ�Ŵ󴲣�һ�Ű���������ֻ�¹�
��һЩ������������������ʰ����Ϊ�ɾ�������Ů�������൱�ڿ�ġ�
long);
	set("exits",([
	    "south" : __DIR__"lgxroom",
]));
	set("coor/x",490);
  set("coor/y",420);
   set("coor/z",10);
   setup();
}
	    	
