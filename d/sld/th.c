// th.c
// ����
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
����һ�ŷ��Ŷ�ʮ��ֻˮ�ף����涼װ������ˮ��
long);
	set("exits",([
	    "north" : __DIR__"ht",
           "south" : __DIR__"dt",
           "east" : __DIR__"cf",          
]));
	set("coor/x",520);
  set("coor/y",450);
   set("coor/z",90);
   setup();
}
	    	
