//xiaolu2.c by zly

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long",
"������һ����ɽ��С·������·����������������ߣ��Եúܻ���
����Χ�ĲݴԶ���һ�˸��ˡ�\n"
        );
        set("outdoors", "��ɽ");
        set("exits", ([
            "northup" : __DIR__"xiaolu3",
            "southdown" : __DIR__"xiaolu1",
        ]));

        set("coor/x",0);
  set("coor/y",-480);
   set("coor/z",10);
   setup();
}

