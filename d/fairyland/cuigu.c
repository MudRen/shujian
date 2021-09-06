// Room: /u/qingyun/jyzj/cuigu.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"���츣��"NOR);
	set("long", @LONG
���ö�����ͻȻ������ҫ�ۣ�������۶�һ������������������ǰ����
�����Ž��صĴ�ȣ��컨������������ӳ��ɽ����ؾ�Ȼ��������������һ
Ծ�������ŵأ��Ų���̤�ŵ�������ϸ�ݣ������ŵ��������Ļ��㣬��������
�������ݼ�أ���ǰ���ֵ����ʹ���֦������ôҲ�����뵽����������Ķ�Ѩ
֮�󣬾���������һ�����츣�ء�
LONG	);
	set("exits",([
                "north" :   __DIR__"shanlu5",
                "south" :   __DIR__"cuigu3",
		"eastup" : __DIR__"shanbi",
                "west" :  __DIR__"shanlu3",
	]));
	set("objects", ([
		__DIR__"obj/rock" : 1,
	]));

	set("outdoors", "���ش��");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_zuan", "zuan");
}

int do_zuan(string arg)
{
	object me = this_player();
        object *ob = deep_inventory(me);
        int i = sizeof(ob);
	if (arg == "dong"){
            while (i--)
            if(ob[i]->id("jiuyang zhenjing"))
                return notify_fail("��ת��һ�룬Я�������Ҫ����ѧ�ؼ���ȥ����Σ�գ�������ڴ˴���Ϊ��ȫ��\n");
	    message("vision", me->name() + "һ�����������ɽ����\n", environment(me), ({me}));
            write("��ǿ��һ����������խ��ɽ���д���������һ����ƽ̨�ϡ�\n");
            me->move(__DIR__"dapingtai");
            message("vision", me->name() + "��ɽ�������˳�����\n", environment(me), ({me}));
	    return 1;
	}
	return 0;
}
