// caoyuan3.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "��ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ��治��
�ߣ�������ƥ�����������ǵĺ����⡣���߿��Կ�����������������ȥ����
ɳĮ�ˡ�
LONG);
        set("exits", ([
            "eastdown" : __DIR__"caoyuan",
            "northwest" : __DIR__"shop",
            "west" : __DIR__"pmchang",
            "north" : "/d/xueshan/caohai1",
            "south" : __DIR__"caoyuan1",
            "northup" : __DIR__"road1",
        ]));

        set("outdoors", "��ԭ");
        setup();
}
