// tz.c
// ����
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
����һ���ܳ�������ʯ�����ɵ����ȣ��������ȵ����߷�����������
���ʻ������ȵ������һ���š�
long);
	set("exits",([
	    "east" : __DIR__"road2",
           "out"  : __DIR__"zl1",
]));
	set("coor/x",490);
  set("coor/y",430);
   set("coor/z",90);
   setup();
}
	    	
