// caoyuan8.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "���ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ��治��
�ߣ�������ƥ�����������ǵĺ����⡣
LONG);

        set("exits", ([
            "south" : __DIR__"caoyuan9",
            "east" : __DIR__"caoyuan",
            "west" : __DIR__"caoyuan7",
            "north" : __DIR__"room-che",
        ]));

        set("outdoors", "��ԭ");
        set("coor/x",-340);
  set("coor/y",60);
   set("coor/z",0);
   setup();
}
