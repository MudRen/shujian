// caoyuan1.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "��ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ��治��
�ߣ�������ƥ�����������ǵĺ����⡣���ߺ����߶��кö������������Կ�
��ɳĮ�ı�Ե��
LONG);

        set("exits", ([
            "eastdown" : __DIR__"caoyuan",
            "northwest" : __DIR__"shop",
            "west" : __DIR__"pmchang",
            "north" : "/d/xueshan/caoyuan/caohai1",
            "south" : __DIR__"caoyuan1",
            "northup" : __DIR__"road1",
        ]));

        set("outdoors", "��ԭ");
        set("coor/x",-310);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}

int valid_leave(object me, string dir)
{
       if( dir == "north" && !userp(me))
            return notify_fail("...\n");      
       return ::valid_leave(me, dir);
}
