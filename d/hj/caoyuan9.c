// caoyuan9.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "���ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ��治��
�ߣ�������ƥ�����������ǵĺ����⡣
LONG);
        set("exits", ([
            "south" : __DIR__"caoyuan",
            "west" : __DIR__"caoyuan7",
            "east" : __DIR__"caoyuan8",
            "north" : __DIR__"caoyuan",
        ]));
        set("objects", ([
                    __DIR__"npc/hasake" : 1,
                    __DIR__"npc/yang" : 2
        ]));
        set("outdoors", "��ԭ");
        set("coor/x",-300);
  set("coor/y",90);
   set("coor/z",0);
   setup();
}
