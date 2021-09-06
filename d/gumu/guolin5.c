// guolin5.c By River 98/09

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"����"NOR);
	set("long",@LONG
ת��ɽ��������һ��Ƭ���֡������ߴ�ïʢ��֦Ҷ���ܣ������ʹ�������
���ˡ�����Ҷ��ɳɳ���죬������Ⱥ�������ҡ���裬����������㡣����
��������ž��������䡣��ǰ����һ�ù����Ϲ��Ÿ��䳲(fengchao)��
LONG );

	set("outdoors","��Ĺ");

       	set("exits" ,([
		"east" : __DIR__"guoyuan",
       	]));

	set("item_desc", ([
		"fengchao" : "���߽����߹۲죬ֻ���䳲��Χ�������æµ�Ĳ��ۡ�\n"
	]));

	setup();
}

void init()
{
	add_action("do_tong","tong");
}

int do_tong(string arg)
{
	object me = this_player();
	object name1=me->query("id");
	object target,ob;
	int i , j = 0;
	mapping fam;        
        
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ�ɴ��ˣ���Ҫ���ڹ�Ĺ�����ˡ�\n");
	if ( arg =="fengchao"){
		if ( me->query_temp("gm_job1"))
			return notify_fail("���Ѿ��ɺ����ˣ�����ȥҩ���Ƴ���佬�ˡ�\n");
		if ( me->query_condition("gumu_job" ) > 0 )
			return notify_fail("��ͱ�˰��췢�ַ䳲��ʲô��û���ˡ�\n");
		if ( me->query("jing") < 15 || me->query("qi") < 20 )
			return notify_fail("��ֻ����˫������������ȥ��Ϣһ�ᡣ\n");         
		if ( !wizardp(me) && me->query("combat_exp") > 35000 )
			return notify_fail("���书�Ѿ����ߣ��ɷ��۵��¾���С������ȥ���ɡ�\n");
		if ( me->query_temp("gm_fengmi") < 10 + random(5)){
			i = me->query("combat_exp")/100000*18;
			j = me->query_temp("gm_bee");
			if ( j > 2 || random(10) > i || me->query("combat_exp") < 10000 ){
				write("������ͱ�ŷ䳲�������ڳ���һ����ۡ�\n");
				me->add_busy(1);
				me->receive_damage("jing",5+random(5));
				me->receive_damage("qi",5+random(10));
				me->add_temp("gm_fengmi", 1);
			}
			else {
				message_vision(HIY"\nͻȻ��Χ����һ����..��...��������$N����һ����ԭ����$N��������䡣\n\n"NOR,me);
				target=new(__DIR__"npc/bee2");
				target->set_temp("gm/caimi",name1);
				target->move(environment(me));
				me->add_temp("gm_bee", 1);
				me->add_busy(2);
			}
			return 1;
		}
		me->apply_condition("gumu_job", random(6)+ 4);
		tell_object(me,HIR"���Ѿ��ɳ��㹻�ķ��ۣ�����ȥ�Ƴ���佬�ˡ�\n"NOR);
		me->delete_temp("gm_fengmi");
		me->delete_temp("gm_bee");
		me->set_temp("gm_job1", 1);
		ob=new(__DIR__"obj/fengmi");
		ob->set_temp("gm/make", name1);
		ob->move(me); 
		return 1;
	}
	return notify_fail("�����ͱ�˼��£����ʲôҲû�з�����\n");
}
