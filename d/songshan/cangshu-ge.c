// Room: /u/swl/songshan/csshi.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��ɽ�ɵĲ��������Ϸ�������ɽ�����书�鼮���ķ���������
ɽ�����ڶ࣬����ʱҲ�ṩ��Ӧ��
LONG);
	set("exits", ([
            "south" : __DIR__"yushu-lou",
        ]));
	set("coor/x",20);
  set("coor/y",350);
   set("coor/z",120);
   setup();
}
