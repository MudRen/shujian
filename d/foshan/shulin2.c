//shulin2.c by zly

inherit ROOM;

void create()
{
    set("short","����");
    set("long",
"������һƬ���֣�����Ĵ�����ס�����⣬�����Եú�����������
��������Ұ�޵Ľ������������뿪�����ˡ�\n");
    set("outdoors", "��ɽ");
    set("exits",([
        "east" : __DIR__"caomeidi",
]));

    set("objects" , ([
        __DIR__"npc/laohu" : random(2),
]));

    set("coor/x",-20);
  set("coor/y",-590);
   set("coor/z",0);
   setup();
}

