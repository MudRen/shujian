// xcelang.c
// ������

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@long
�����Ƕ��һ����ֶ��ȡ���������ͨ������������ͨ���㳡��
long);
       set("exits",([
          "south" : __DIR__"huazangancf",
          "east" : __DIR__"huazangangc",
]));
	setup();
}	 
