// shishan.c ʯɽ
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIW"ʯɽ"NOR);
	set("long", @LONG
����һ��ɽʯ��ɽʯ��Χ�������滨�������������д�����������㣬��
�ɲ�֪��֮���䴫����ɽ����¶��һ��ʯ��(dong)��������ͨס��ɽ֮·����
�߰��ﴦ��һСʯɽ��������һƬƬ����׵Ĵ���֡�
LONG);
	set("outdoors","����");
	set("exits",([
		"west"  :  __DIR__"ysroad1",
		"east"  :  __DIR__"shishan1",
                "south" :  __DIR__"pingyan2",
                "north" :  __DIR__"cling",
	]));

        set("item_desc", ([
                "dong" : "����һ���ܴ���ܶ������治֪����Щʲô�Ź֡�\n",
        ]));
	setup();
}

void init()
{
        if(!this_player()->query_condition("cold_wind") && !wizardp(this_player()))
        this_player()->apply_condition("cold_wind", 1);
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me;
        me = this_player();
        if( arg=="dong" ) {
            message("vision",me->name()+"һ�������������˽�ȥ��\n",environment(me),({me}));
            me->move(__DIR__"xiongdong");
            message("vision",me->name()+"�Ӷ������˽�����\n",environment(me), ({me}));
            return 1;
        }
}       
