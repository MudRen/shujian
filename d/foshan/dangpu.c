//Room: dangpu.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�ƹ���ǽ��������һ�Ÿ߸ߵĹ�̨����̨�������ŵ��̵ĳ�����
�����Ƿ����Ͽ��ģ�ʮ��������û�˸������졣����������������ڹ�̨
�ϡ���̨�ϰ���һ������(paizi)��
LONG
	);
	set("exits", ([
            "north" : __DIR__"dongjie3",
]));
	set("no_fight", 1);
        set("no_sleep_room",1);
        set("no_clean_up", 0);
  

	set("item_desc", ([
	    "paizi" : "��ƽ����\n",
]));
	set("objects", ([
            __DIR__"npc/yu-chaofeng" : 1,
]));

	set("coor/x",30);
  set("coor/y",-540);
   set("coor/z",0);
   setup();
}

