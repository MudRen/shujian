inherit ROOM;

void create()
{
    set("short","����");
    set("long",
"������һƬ���֣������������ˣ����ֳɳ��ܿ죬�Ѿ��γ���һƬ
�ܴ��������Եú�ï�ܡ��Ա�����һ��ľ��(pai)��\n");
    set("outdoors", "��ɽ");
    set("exits",([
        "north" : __DIR__"nanmen",
        "southwest" : __DIR__"caomeidi",
        "southeast" : __DIR__"shulin_dzd",
]));

    set("item_desc", ([
      "pai" : "С��Ұ�ޣ�\n",
]) );
    set("coor/x",0);
  set("coor/y",-580);
   set("coor/z",0);
   setup();
}

