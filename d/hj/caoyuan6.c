// caoyuan6.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "���ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ��治��
�ߣ�������ƥ�����������ǵĺ����⡣
LONG);

        set("exits", ([
           "southwest" : __DIR__"road2",
            "northwest" : __DIR__"room-ji",
            "east" : __DIR__"caoyuan",
            "south" : __DIR__"caoyuan",
        ]));

        set("outdoors", "��ԭ");
        set("coor/x",-290);
  set("coor/y",130);
   set("coor/z",0);
   setup();
}
