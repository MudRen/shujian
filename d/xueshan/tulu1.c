// Room: tulu1.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������·");
	set("long", @LONG
�����Ѿ������Ĵ������棬����ǰ�߾�Ҫ�����ˣ�����ȴ���Ҫ����
�࣬·��Խ��������ż���ڲݴ���¶��һ�Ѱ׹ǣ��ں��������Ŵ��۵İ�
�⣬���˴�Ŀ���ġ�
LONG
	);

	set("exits", ([
		"east" : "/d/chengdu/wroad2",
		"southwest" : "/d/group/entry/xstulu2",
	]));
        set("outdoors", "ѩɽ");
	setup();
}

void init()
{       
        object me = this_player();
        int lvl,lvl1,lvl2;
     
        lvl = me->query_skill("huanxi-chan", 1);
        lvl1 = me->query_skill("longxiang-boruo", 1);
        if (lvl > 200 && !me->query("cut/xs")){
                lvl2 = (lvl - 200)/ 4;
                me->set_skill("huanxi-chan", 200);
                me->set_skill("longxiang-boruo", lvl1 + lvl2);
                write(HIG "ϵͳ�ѽ�������ġ���ϲ����ת��Ϊ���������������\n" NOR);
                me->set("cut/xs", lvl2 * 4);
        }
}
