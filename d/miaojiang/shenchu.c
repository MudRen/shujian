// /u/dubei/miaojiang/mjqj

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIY+"�置�澳"+NOR);
        set("long", @LONG
������ɽ�������������ǳ����ġ����ܵ�ֲ�������������¶ˮ����
��һЩ��ҩ������������Щ�ط���
LONG                           
        );

        set("qnwu_count",1);
        
        set("exits", ([             
             "northup" : __DIR__"shulin",
        ]));

	set("outdoors", "�置");

        set("objects",([
                __DIR__"npc/guaimang" : 1,
        ]));

        setup();
}

void init()
{
        add_action("do_wa", ({"wa","dig"}));    
}
 
int do_wa(string arg)
{ 
	int i;
        object qnwu, me, *inv;

        me = this_player();
        inv = deep_inventory(me);
        i = sizeof(inv);

        if(!( present("xiao tiechan", this_player())))
		return notify_fail("��ҩ��������ȥ�ɣ�\n");

        if( !arg || arg != "qiannian shouwu" )
		return notify_fail("������ʲ�᣿\n");
        
        if((int)me->query("jingli") < 200) 
		return notify_fail("��̫���ˣ�\n");

        if(random(20)!= 3) {
		me->add("jingli",-120);
		return notify_fail("�����˰��죬û��ʲ�ᷢ�֡�\n"); 
        }

        while (i--)
        if( inv[i]->query("drug"))
		return notify_fail("�����˰��죬û��ʲ�ᷢ�֡�\n"); 
        
        if( query("qnwu_count") < 1 )
		return notify_fail("�����˰��죬���һ������\n");

        qnwu = unew(MEDICINE_D("neili/qnshouwu"));

        if(!clonep(qnwu)) return notify_fail ("�����˰��죬���һ������\n");
        if(clonep(qnwu) && qnwu->violate_unique()){
		destruct(qnwu);
		return notify_fail ("�����˰��죬���һ������\n");
        } 
	add("qnwu_count", -1);
	qnwu->set("owner", me->query("id"));
	qnwu->move(me);
	log_file("quest/neili",sprintf("%-18s���置�ڵ���%s��\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",qnwu->name()), me);
	me->add("jingli", -200);
	return 1;
}

int count = 1;

void reset()
{
	if (--count == 0) {
		count = 10;
		set("qnwu_count", 1); 
		::reset();
	}
}

int clean_up()
{
	return 0;
}
