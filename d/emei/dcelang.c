// dcelang.c
// ������

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@long
�����Ƕ��һ����ֶ��ȡ���������ͨ��ի�ã�����ͨ���㳡��
long);
       set("exits",([
          "south" : __DIR__"huazanganzt",
          "west" : __DIR__"huazangangc",
]));
	setup();
}	 
