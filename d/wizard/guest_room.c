// �����

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"�����"NOR);
        set("long", @LONG
�����ǹ���Ա�Ļ���ң��������Ӵ���ҵĵط������ڴ��������������
����¥����һ����Ϣ�ң�����Աƽ��������������Ϣ��һ����ҵ���������
��ȥ�ˡ�����ĳ���ͨ�����ݳ�����
    ������̨��ˮ������(drink),��������û���ṩ���ġ�
LONG);

        set("item_desc", ([
                "up": "�������ǰһƬ������ʲôҲ���������\n",
        ]));

        set("exits", ([
                "up": __DIR__"wizard_room",
		"southeast": "/d/city/chmiao",
//              "enter": "/d/wizard/fairy_room",
        ]));
        set("no_fight", 1);
	set("sleep_room", 1);
	set("no_sleep_room", 1);

	set("objects", ([
                "/d/city/npc/wizard" : 1,
                "/clone/misc/goldbox" : 1,
	]));

	set("incity",1);
	setup();
        call_other("/clone/board/towiz_b", "???");
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me))
                return notify_fail("�������ڲ��ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_he",({"he","drink"}) );
}

int do_he(string arg)
{
     object me = this_player();
	if (me->query("water") < me->query("str")*10+100){
         message_vision(HIC"$N����ˮ��������һ��ˮ�������̵ú���һ�ڣ��漴��һ���Ա���������ȥ�ˡ�\n"NOR, me);
         me->add("water", 50, me);
         return 1;
       }
       return notify_fail("���̫���ˣ����³�����\n");
}
