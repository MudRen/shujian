// road2.c
// ·2
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
����һ���ܳ�������ʯ�����ɵ����ȣ��������ȵ����߷�����������
���ʻ������ȵ������һ���š�
long);
	set("exits",([
	    "east" : __DIR__"road1",
           "west"  : __DIR__"tz",
           "north" : __DIR__"lgf",
]));
	//set("outdoors", "������");
        set("coor/x",500);
  set("coor/y",430);
   set("coor/z",90);
   setup();
}
	    	
