// road1.c
// ·1
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
����һ���ܳ�������ʯ�����ɵ����ȣ��������ȵ����߷�����������
���ʻ������ȵ������һ���š�
long);
	set("exits",([
	    "east" : __DIR__"slj",
           "west"  : __DIR__"road2",
           "south" : __DIR__"ws",
]));
	//set("outdoors", "������");
        set("coor/x",510);
  set("coor/y",430);
   set("coor/z",90);
   setup();
}
	    	
