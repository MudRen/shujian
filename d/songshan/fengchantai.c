//Room fengchantai.c ����̨

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"����̨"NOR);
	set("long", @LONG
����̨Ϊ����ʯ������ÿ���ʯ����ü���ƽ�������������ʵ�Ϊ�˼���
�븣����֪��ʹ�����񹤡�ʯ��ʼ���ɴ˾޹�������̨���ǿ���������ǧ�˵�
�㳡�������ڴˣ������������ܷ塢С�ܷ塢˫���塢���������������ڵ�
����ɽ��������������Ÿ�����³��δ�ˡ��ľ��䡣
LONG);
	set("exits", ([
	    "southdown" : __DIR__"peitian-fang",
	]));
	set("objects", ([
		CLASS_D("songshan") + "/zuo" : 1,
	      __DIR__"npc/ssdizi" : 3,
	]));
	set("outdoors", "��ɽ");
   	setup();
}

void init()
{
	object me = this_player();
	if ( me->query("songshan_points")){
		me->add("job_time/��ɽ", me->query("songshan_points"));
		me->delete("songshan_points");
	}
	add_action("do_enter","guan");
	add_action("do_qs","qi");
        add_action("do_jieti","jieti");
        add_action("do_decide","decide");
}

int do_enter(string arg)
{
	object me;

	me = this_player();
	if( !arg || arg=="" ) return 0;
	if( arg=="ri" ) {
		if (me->is_busy() || me->is_fighting())
			return notify_fail("����æ���ء�\n");
		if (me->query("family/family_name")=="��ɽ��") {
		       	message("vision",me->name()+"�������·�������շ����˹�ȥ��\n",environment(me),({me}) );
		       	me->move("/d/songshan/guanrifeng");
		       	message("vision",me->name() + "�ӷ���̨���˹�����\n",environment(me), ({me}) );
		       	return 1;
	   	}
     		return notify_fail("�Ǳ�̫���ô��㲻��ɹ����\n");
	}
}

int do_qs(string arg)
{
	object me,ob;
	int shen,exp,pot;
	me = this_player();
	ob = present("shi kuai",me);

	if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô��\n");

	if(!ob) return notify_fail("������Ҫʯ�ϣ���Ҫ��ʲô������\n");

	if(!me->query_temp("ss_qs/taked")) return notify_fail("�㻹ûȥ��ʯͷ�ذɣ�\n");

	if(arg=="shikuai") {
		shen = me->query("max_pot")/2 + random(200);
		exp = me->query("max_pot")/2+random(20);
		exp = me->add_exp_combat(exp,this_object(),"��ɽ��ʯ");
		pot = exp/5+random(exp/10);

		//me->add("combat_exp",exp);
		if (me->add("potential",pot) > me->query("max_pot"))
			me->set("potential", me->query("max_pot"));
		me->add("shen",-shen);

		me->improve_skill("hanbing-zhenqi",me->query("int"));
		me->add_condition("job_busy", 2+random(2));
		me->delete_temp("ss_qs");
		destruct(ob);
		message_vision("$N��һ��ʯͷ���ڷ���̨�����һ���ϡ�\n",me);
		me->add("job_time/��ɽ��ʯ",1);
		tell_object(me,HIW" ��õ��ˣ�\n" +
	    	chinese_number(exp) + "��ʵս����\n"+
	    	chinese_number(pot) + "��Ǳ�ܺ�\n"+
	    	chinese_number(shen)+ "����\n"NOR);
		return 1;
	}
	else return notify_fail("��Ҫ��ʲô��\n");
}
