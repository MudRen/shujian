// xx job.
// by snowman@SJ 02/04/99.
// ʹ�� TASK_D��

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT"����̵�"NOR, ({ "duandi", "di",}));
	set("weight", 100);
	if(clonep()) set_default_object(__FILE__);
	else{
		set("unit", "ֻ");
          	set("long", WHT"����Ѷ̵ó��棬ֻ�����ߴ�������ͨ���ף���Ө�ɰ���\n" NOR);
	  	set("value", 50000); 
          	set("no_get", 1);
          	set("di_number", 0);
          	set("no_drop", 1);
	}
	setup();
}

void init()
{
        add_action("mark_success", "sign");
        add_action("set_task", "blow");
        add_action("report_task", "report");
}

int set_task(string arg)
{
	object me, where; 
	mapping quest;
	me = this_player();  
	where = environment(me);

	if( !arg ) return 0;
	if( !this_object()->id(arg)) return 0;

	if( me->is_busy() || me->is_fighting()) 
		return notify_fail("����æ���ء�\n");    

	if(this_object()->query("xx_user") != getuid(me)) 
		return notify_fail("����ֻ���˵ĵ��Ӵ���\n");    

	if(!(where)->query("outdoors")) 
		return notify_fail("�������ﴵ���ӣ�������ô���ܴ���Զ�أ�\n");

	if(me->query_temp("quest/family") == "ؤ��")
		return notify_fail("������������л��ӣ����ӵ����ؤ�������˵��\n");

	if(me->query_temp("quest/id")) 
		return notify_fail("����������ִ�������С�\n");  

	if(me->query("job_name") == "���ɷ���")
		return notify_fail("���Ҫ�������ȵȵȰɡ�\n");

	if(me->query_condition("job_busy")) 
		return notify_fail("���Ҫ�������ȵȵȰɡ�\n");           

	if(me->query_condition("wait_xx_task")) 
		return notify_fail("�ϴθ����ˣ������͵ȵȰɡ�\n");      

	tell_room(environment(me),HIY + me->name()+"����һֻ"+this_object()->query("name")+HIY"�ŵ��ڱߣ�����һ��������һ�ɳ���������������������ＤԽ��\n"+
					"���������з�����������ȴʮ��������ȫ���ֵ���\n"NOR, ({ me }));
	tell_object(me,HIY"������"+this_object()->query("name")+HIY"�ŵ��ڱߣ����ᴵ��������\n"NOR);

	if((where)->query("outdoors") != "����") 
		return notify_fail("�˵غ����޺�����̫Զ���Ÿ����������������\n");

	if(random(2)==1) {
		if(!mapp(quest = TASK_D->get_quest(me, 0, "ɱ", "������"))) 
		quest = TASK_D->get_quest(me, 0, "��", "������");
	}
	else quest = TASK_D->get_quest(me, 0, "��", "������");
   	   
	if ( quest) {
		me->set_temp("quest", quest);
		me->add_busy(2);
		me->apply_condition("job_busy", 30+random(20));
		call_out("report", 3, me);
		return 1;
	}
	else {
		tell_object(me,"�����ڻ�û�н��յ��κ�����\n");
		return 1;
	}
}

int report(object me)
{
	if(!me) return 0;

	if(!me->query_temp("quest/id")) 
		return notify_fail("�����ڻ�û�н��յ��κ�����\n");
   
	message_vision(HIW"\nֻ������з���һֻ��ɫ�Ÿ룬����$N�ļ�ͷ��\n\n"NOR, me);
	tell_object(me, "�㽫���ŴӰ׸����Ͻ��£����һ�ۣ�����д����\n\t\t�����������˼��������Ҫ");
	if(me->query_temp("quest/type") == "ɱ") 
		tell_object(me,"ɱ���� "+me->query_temp("quest/name")+"("+me->query_temp("quest/id")+") ����\n\n");
	else
		tell_object(me,"�õ��� "+me->query_temp("quest/name")+"("+me->query_temp("quest/id")+") ����\n\n");
	tell_object(me,"Ŀǰ�������ͨ���鿴����(report)���˽⡣\n");
	return 1;       
}

int report_task()
{
	object me = this_player();

	if(me->is_busy() || me->is_fighting()) 
		return notify_fail("����æ���ء�\n");
	if (!me->query_temp("quest/time") || !me->query_temp("quest/id")) 
		return notify_fail("�����ڻ�û�н��յ��κ�����\n");

	tell_object(me, "��Ŀǰ������Ŀ���ǣ�\n\n");

	if(me->query_temp("quest/type") == "ɱ"){
		tell_object(me,"\t�ҵ�����������"+me->query_temp("quest/place")+"һ����"+
		"\t\t�� "+me->query_temp("quest/name")+"("+me->query_temp("quest/id")+") ����\n\n"+
		"ɱ��������ʬ��������(sign corpse)���������ɵı�־��\n");
	}
	else
		tell_object(me,"\t�ҵ��� "+me->query_temp("quest/name")+"("+me->query_temp("quest/id")+") ������(xian)�����ɡ�\n\n");

	tell_object(me, "�������"+TASK_D->get_time(me->query_temp("quest/time"))+"֮ǰ�������\n\n");
	return 1;
}

int mark_success(string arg)
{
	object me, target;
	string last;
	me = this_player();        
  
	if(!arg) return notify_fail("��Ҫ��ʲô��\n");
	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("�Ҳ������������\n");
	if( me->is_busy() || me->is_fighting()) 
		return notify_fail("����æ���ء�\n");    
	switch (TASK_D->is_target(target, me)){
		case 0:  return 0;
		case -1: tell_object(me, "Ү��������ȥɱ������\n");	return 0;
		case -2: tell_object(me,"��������ɱ�����ˣ�\n");	return 0;
		case -3: tell_object(me,"���ˣ�ʱ���Ѿ����ˣ�\n");
			last = me->query_temp("quest/last_id");
			me->delete_temp("quest");
			me->set_temp("quest/last_id", last);
			me->apply_condition("job_busy", 40); 
			return 0;
		case -4: tell_object(me,"Ŷ�����˺�NPCͬ����������ù��\n");	return 0;
		default: break;
	}
	if(me->query_temp("quest/family") != "������") 
		return notify_fail("�ٺ٣��������ǰɣ������Ҫ�ȵ�û����ʦ��ʱ����С�\n");
	if(me->query("family/family_name") == "������"){
		message_vision(HIR"\n$N����һ������зɳ�һ��"BLU"��ӡӡ"HIR"�Ļ𻨣��������죬����$n"HIR"�������ȼ��\n\n"NOR, me, target);
		target->set("name", HIB"�ս���ʬ��"NOR);
		target->set("long", HIB"һ�߱����ĵ��ս���ʬ�壬�������磬��״�ɲ���\n"NOR);		
	}
	else {
		message_vision("$N����һ������ī����$n��������д���ˡ����ޡ����֡�\n", me, target);
		target->set("long", target->query("long")+"\n��������д�˴��� "HIB"����"NOR" ���֡�\n");
	}
	call_out("done", 1, me);   
	me->start_busy(1);
	return 1;
}

void done(object me)
{
	if(!me) return;
	tell_object(me, "�ã�������ɣ�����������һ��ɸ봫���ͻ����޺���\n");
	TASK_D->give_reward(me, me->query_temp("quest"), -1);
	//TASK_D->give_reward(me, me->query_temp("quest"), -1, "������" ,"����");
	me->add("job_time/����", 1);

	me->set("job_name","���ɷ���");
	log_file("job/fenyou",sprintf("%-18s ������JOB���þ��� %d��Ǳ�� %d��Ŀǰ���飺%d��\n",
		me->query("name")+"("+getuid(me)+")", me->query_temp("quest/exp_reward"),
		me->query_temp("quest/pot_reward"), me->query("combat_exp")),me);
	me->clear_condition("job_busy");
	return;
}
