// /d/wudang/shanlu2.c  ɽ·

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",YEL"ɽ·"NOR);
        set("long", @LONG
������һ��ƫƧ��ɽ·�ϣ����ܹ�ľ�Դԣ�����滨��ݣ��˼�������·
��������Ѱ��ֻ�в�ҩ���˲Ÿҽ�����ɽ���㵽���Ҵ�Ѱ�ҳ�·���͵�һʹ��
���������������!
LONG                           
        );

        set("exits", ([
                "west" : __DIR__"langmei",
                "southeast" : __DIR__"houshan/hsxl5",
        ]));

        set("outdoors","�䵱");
        set("objects",([
               CLASS_D("wudang")+"/caiyao" : 1,
        ]));

        setup();
}

void init()
{
	add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
	object me = this_player();
	
	if (! arg || arg != "guanmu")
	    return notify_fail("��û������ʲô����\n");
	
	if ( me->is_busy() || me->is_fighting())
	    return notify_fail("����æ���ء�\n");
	
	message_vision("$Nһè������˹�ľ���С�\n",me);
	me->move(__DIR__"shanlu3");
	tell_room(environment(me),me->query("name") + "���������ӣ����˽�����\n",({ me }));
	return 1;
}
