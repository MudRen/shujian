// caoyuan4.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "���ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ��治��
�ߣ�������ƥ�����������ǵĺ����⡣
LONG);

        set("exits", ([
            "south" : __DIR__"caoyuan5",
            "west" : __DIR__"caoyuan5",
            "east" : __DIR__"caoyuan5",
            "north" : __DIR__"caoyuan5",
        ]));

        set("outdoors", "��ԭ");
        set("coor/x",-300);
  set("coor/y",110);
   set("coor/z",0);
   setup();
}
