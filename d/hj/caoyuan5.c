// caoyuan5.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "���ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ��治��
�ߣ�������ƥ�����������ǵĺ����⡣
LONG);
        set("exits", ([
            "west" : __DIR__"road1",
            "south" : __DIR__"caoyuan4",
            "east" : __DIR__"caoyuan4",
            "north" : __DIR__"caoyuan4",
        ]));
        set("objects", ([
                    __DIR__"npc/hasake" : 1,
                    __DIR__"npc/yang" : 1
        ]));
        set("outdoors", "��ԭ");
        set("coor/x",-300);
  set("coor/y",120);
   set("coor/z",0);
   setup();
}
