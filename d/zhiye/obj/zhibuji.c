// zhibuji.c
// by augx@sj  10/9/2001

// Modified by mxzhao 2004/03/06 caijian => zhizao

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"֯����"NOR, ({ "zhibu ji" , "ji" }));
	set_weight(1000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIW"����һ������æµ��ͣ��֯������\n"NOR+"�������������֯(bianzhi)��bianzhi ����\n");
		set("value", 3000);
		set("no_get", 1);
	}
	setup();
}

void init()
{
	add_action("do_bianzhi","bianzhi");
}

int do_bianzhi(string arg)
{
	object me = this_player() ,obj,obj2,weapon;
	int delay,level,time;

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
	if (me->is_fight()) return notify_fail("����æ���أ�\n");
	if (!arg) return notify_fail("��Ҫ��֯ʲô��\n");
	if (!objectp(obj = present(arg, me)))
		return notify_fail("������������������\n");
	obj = present(obj->query("id"), me);
	if (!objectp(obj2 = present(obj->query("id")+" 2", me)))
		return notify_fail("�����������"+obj->query("name")+"����֯��\n");
	if( !(int)obj->query("buliao") || !(int)obj->query("level")
	 || !(int)obj2->query("buliao") || !(int)obj2->query("level"))
		return notify_fail("������ֻ���ò�������֯��\n");
	if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="fang suo" )
		return notify_fail("�����װ�������������֯��\n");
	if ( !weapon->query("worker_tool"))
		return notify_fail("�����װ�������������֯��\n");
	if ( !wizardp(me) && (time()<(int)me->query("worker/bianzhi")) )
		return notify_fail("��ոձ�֯��ϣ��о��������ۣ�\n");

	time = time()- me->query("pk_time");
	if ( time < 432000)
		return notify_fail("��Ŀǰ��״̬�޷���֯��\n");

	level = (int)me->query_skill("bianzhi",1);
	if ( level<1 ) return notify_fail("������Ͳ����֯�\n");

	switch( (int)obj->query_level() ) {
		case 1: break;
		case 2: if(level<40)  return notify_fail("��ı�֯���ܲ�����\n"); break;
		case 3: if(level<80)  return notify_fail("��ı�֯���ܲ�����\n"); break;
		case 4: if(level<120) return notify_fail("��ı�֯���ܲ�����\n"); break;
		case 5: if(level<170) return notify_fail("��ı�֯���ܲ�����\n"); break;
		case 6: if(level<220) return notify_fail("��ı�֯���ܲ�����\n"); break;
		case 7: if(level<270) return notify_fail("��ı�֯���ܲ�����\n"); break;
		case 8: if(level<330) return notify_fail("��ı�֯���ܲ�����\n"); break;
		case 9: if(level<390) return notify_fail("��ı�֯���ܲ�����\n"); break;
	}

	message_vision(HIW"$N��"+obj->query("name")+HIW"�ŵ���֯���ϣ�Ȼ�󿪶���֯������ʼ��֯......\n"NOR, me);
	delay = 6 + random(12);
	if(wizardp(me) && (int)me->query("env/test")) delay = 3;
	me->start_busy(delay+1);
	call_out("datie_finish",delay*2-1,me,obj);
	destruct(obj2);
	return 1;
}

void datie_finish(object me,object obj)
{
	string str;
	object tools;
	int level, buliao, i=1,improve;

	if(!objectp(me) || !userp(me) || !objectp(obj)) return;
	me->start_busy(-1);
	me->interrupt_me();
	tools = me->query_temp("weapon");
	level = (int)me->query_skill("bianzhi",1);
	if(level>390) level = 390 + (level-390)*11;
	buliao = (int)obj->query_level();

	message_vision(HIW"���������ı�֯��$N����ͣ���˱�֯����\n"NOR, me);
	if ( objectp(tools) && tools->query("id")=="fang suo" )
		tools->use();

	switch(buliao) {
		case 1: i = 40;  break;
		case 2: i = 80;  break;
		case 3: i = 120; break;
		case 4: i = 170; break;
		case 5: i = 220; break;
		case 6: i = 270; break;
		case 7: i = 330; break;
		case 8: i = 390; break;
		case 9: i = 500; break;
		case 10: i = level; break;
	}
	i = 100 - (level - i)/2;
	if(i>200) i = 200;
	if(i< 10) i = 10;
	if ( me->query_temp("user_type") != "worker")
		improve = me->query_int(1)*i/100;
	else
		improve = me->query_int()*i/100;

	switch(buliao) {
		case 1: i = 40;  if(level>100) level=100; break;
		case 2: i = 80;  if(level>150) level=150; break;
		case 3: i = 120; if(level>200) level=200; break;
		case 4: i = 170; if(level>300) level=300; break;
		case 5: i = 220; if(level>400) level=400; break;
		case 6: i = 300; if(level>500) level=500; break;
		case 7: i = 450; if(level>500) level=500; break;
		case 8: i = 600; if(level>500) level=500; break;
		case 9: i = 850; if(level>500) level=500; break;
		case 10: i = level; break;
	}
	if( random(level+i) > i ) {
		if (buliao!=10) {
			me->improve_skill("bianzhi", improve*8);
		}
		else {
			i = (300 + level/2) * 11/10;
			i = i*2/3 + random(i*2/3);
			me->improve_skill("bianzhi", i);
			me->add_temp("worker/job3_bianzhi",i);
		}
		if ( environment(me)->query("no_zhiye")
		 || me->query_temp("user_type") == "worker") {
			me->add("combat_exp", random(improve)/5*4);
			me->add("potential", random(improve/2));
		}
		obj->change_state();
		message_vision(HIC"$N�ӱ�֯��������һƥ"+obj->query("name")+"��\n"NOR, me);
	}
	else {
		me->improve_skill("bianzhi", improve*2);
		if ( environment(me)->query("no_zhiye")
		 || me->query_temp("user_type") == "worker") {
			me->add("combat_exp", random(improve/2));
			me->add("potential", random(improve/5));
		}
		obj->change_state();
		message_vision(HIC"����$N��֯���"+obj->query("name")+HIC"��һ���±�֯���Ͷϵ��ˡ�\n"NOR, me);
		destruct(obj);
	}
	if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
		me->set("potential" , me->query("max_pot", 1) );
	me->set("worker/bianzhi",time()+6+random(12));
	str = WORKER_D->worker_title(me, "zhizao");
	// change to temp title by Lklv
	me->set_temp("title", str);
}
