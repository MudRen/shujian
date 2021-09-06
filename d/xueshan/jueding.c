 //      jueding.c ��������

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short",HIW"����"NOR);
        set("long",@LONG 
�����Ǵ�ѩɽ���壬�˼������������޶�������Ӱ������ž���Ω�ŷ�����
������ɽ������絶��͸�Ǳ�����ƽ����ֻ����һС��͵ñ�������
LONG);

        set("exits", ([
                "down" : __DIR__"shanpo",
        ]));

        set("hua", 1);

        setup();
}

void init()
{
        mixed *local;
    
	local = localtime(time() * 60);
	add_action("do_get","cai");
	add_action("do_look", "look");
	if ( (local[2] < 11 || local[2] > 13) && !wizardp(this_player())) {
		message_vision(HIW"������ѩ����ͷ�������˹���������$N�������ۡ�\n"+
			"ͻȻ��ɽ�±�����һ����ѩ��$N��������������ͷ�ϣ�\n"NOR,this_player());
		message_vision(HIR"\n$N���²��ȣ�˳��ɽ�µ�����ȥ��\n"NOR,this_player());
		this_player()->move(__DIR__"xuegu");
		this_player()->unconcious();
	}
}

int do_look(string arg)
{
	object me;
	me = this_player();
	if (query("hua") < 1){
	set("long", @LONG
�����Ǵ�ѩɽ���壬�˼������������޶�������Ӱ������ž���Ω�ŷ�����
������ɽ������絶��͸�Ǳ�����ƽ����ֻ����һС��͵ñ�������
LONG
);
	me->look(arg);
	}
	else {
		if (!arg) {
		set("long", @LONG
�����Ǵ�ѩɽ���壬�˼������������޶�������Ӱ������ž���Ω�ŷ�����
������ɽ������絶��͸�Ǳ�����ƽ����ֻ����һС��͵ñ�����������ϲ��
����һ�����������ظ�ԭ�ϼ��亱���Ĳغ컨��hua����
LONG
		);
		me->look(arg);
		}
		else if(arg == "hua") {
			write("һ�����������ظ�ԭ�ϼ��亱���Ĳغ컨��������Բ�(cai)������\n");
			me->set_temp("drug/hua", 1);
			return 1;
		}
	}                
}

int do_get(string arg)
{
	int i;
        object me, ob, *inv;

        me = this_player();
        inv = deep_inventory(me);
        i = sizeof(inv);

        if(!me->query_temp("drug/hua")) return 0;
        if (!arg) return notify_fail("��Ҫ��ʲô��\n");
        if ( arg != "hua") return notify_fail("��Ҫ��ʲô��\n");

        while (i--)
        if( inv[i]->query("drug"))
		return notify_fail("���������в���ҩ����غ컨�����������˰ɡ�\n"); 

	ob = new(MEDICINE_D("neili/zanghonghua"));
	ob->set("owner",me->query("id"));
	log_file("quest/neili",sprintf("%-18s��ѩɽ�������õ�%s��\n",
		me->name(1)+"("+capitalize(me->query("id"))+")",ob->name()), me);
	ob->move(me);
	add("hua", -1);
	me->delete_temp("drug/hua");
	message_vision("$NС������ز���һ��"HIR"�غ컨"NOR"��\n",me);
	return 1;
}

void reset()
{
	set("hua", 1);
}

int clean_up()
{
	return 0;
}
