// trees1.c
// ������1
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
����������ö��ָ��д󣬴ִ����֦��������ཻ����һ����ס��
���⣬������ï�ܵ��Ӳݣ���������಻֪����Ұ����ɢ��������ܺ���
�������������Ϻ��Ӳ�����������ڷ���˻˻��������
long);
	set("exits",([
	    "northeast" : __DIR__"treee1",
          "northwest" : __DIR__"treew1",
          "north" : __DIR__"trees2",
          "south" : __DIR__"dukou",
]));
set("objects",([
__DIR__"npc/dushe" : 2,
]));
	set("outdoors", "������");
       set("canfindsnake",1);
        set("coor/x",490);
  set("coor/y",390);
   set("coor/z",0);
   setup();
}
	    	
