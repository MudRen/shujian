// Room: dongjie2.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��ɽ����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣�ϱ��Ǵ����̣�����
������������Զ����������
LONG
	);
        set("outdoors","��ɽ");
	set("exits", ([
            "south" : __DIR__"ironsmith",
            "east" : __DIR__"dongjie3",
            "west" : __DIR__"dongjie",
            "north" : __DIR__"shaobing",
]));

        set("objects", ([
            __DIR__"npc/jiading" : 2,
]));

	set("no_clean_up", 0);
	set("coor/x",20);
  set("coor/y",-530);
   set("coor/z",0);
   setup();

}
