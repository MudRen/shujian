// shishan1.c Сʯɽ
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", YEL"Сʯɽ"NOR);
	set("long", @LONG
����һ��Сɽʯ����֮�����ʯɽҪС���ˡ�ɽʯ��Χ���������滨������
�������д�����������㣬���ɲ�֪��֮���䴫����ɽ����¶��һ��СС��ʯ
��(dong)��������һ��ʯɽ��
LONG);
	set("outdoors","����");
        set("resource/water", 1);
	set("exits",([
		"west"  :  __DIR__"shishan",
	]));
        set("item_desc", ([
                "dong" : "����һ��ɽ�������治֪����Щʲô�Ź֡�\n",
        ]));
	setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me;
        me = this_player();
        if( arg=="dong") {
            message("vision",me->name()+"һ�������������˽�ȥ��\n",environment(me), ({me}) );
            me->move(__DIR__"xdong");
            message("vision",me->name()+"�Ӷ������˽�����\n",environment(me), ({me}) );
            return 1;
        }
}       
