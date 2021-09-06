// kedian.c

#include <ansi.h>
inherit ROOM;
#include "hmy_def.c"

void create()
{
        set("short", HIY"ƽ���͵�"NOR);
        set("long", @LONG       
�������ƽ���͵꣬�ϰ������ǳ���¡������οͶ�ѡ��������š���
С����������æ������ת���Ӵ�����ǻ�����Ŀ��ˡ��������˽�������С����
æӭ��ǰȥ����ջ�����ǽ�Ϲ���һ����Ŀ������(paizi)��
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("no_fight",1);

        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹ����������\n",
        ]));

        set("objects", ([
         __DIR__"npc/xiaoer" : 1,
        ]));

        set("exits", ([
                "northwest" : __DIR__"cj3",
                "north" : __DIR__"kefang",
                "up" : __DIR__"kedian2",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        object obj;

        if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("��ô�ţ����ס����\n");

        if ( dir == "west" ) {
                if(me->query_temp("rent_paid"))
                	return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");

                if (me->query_temp("hostage/job_1")==1 && !me->query_temp("hostage/passed_x")) {
                        tell_object(me,YEL"\n����Ҫ����ֻ���ó��ֱ˶˴����������죬���˴�������õ����������ˣ��õ����������ˣ���\n"NOR);
                        tell_object(me,YEL"�㼱æ�ߵ��͵����֮��ֻ����ʮ���������ϣ��߾ٻ�ѣ�ӵ��һ����Ŀ�������߼��۶�����\n"NOR);
                        tell_object(me,CYN"\n�㶨����ȥ�������߾���ͯ���ۣ��㼱æ����ǰȥ��β����С�\n"NOR);
                        tell_object(me,YEL"\n��һ�ᣬ���������������һ���ص���\n"NOR);
                        tell_room(this_object(),me->name() + "����ææ�뿪�ˡ�\n", ({me}));
                	
			obj = find_object("/d/hmy/npc/tong.c");
	                if (!obj)
        	                new(__HMY__"npc/tong")->move(__HMY__"midao6");
			else
				obj->move(__HMY__"midao6");
                	me->move(__HMY__"midao0");
                	return 1;
                }
        }

        return ::valid_leave(me, dir);
}
