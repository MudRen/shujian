// caoyuan7.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "���ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ��治��
�ߣ�������ƥ�����������ǵĺ����⡣
LONG);

        set("exits", ([
            "east" : __DIR__"caoyuan",
            "west" : __DIR__"caoyuan9",
            "south" : __DIR__"caoyuan8",
            "north" : __DIR__"room-su",
        ]));

        set("outdoors", "��ԭ");
        set("coor/x",-340);
  set("coor/y",70);
   set("coor/z",0);
   setup();
}
