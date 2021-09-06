#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"ʦ������"NOR, ({ "shimen mixin","mixin","letter" }) );
        set("long",HIY"����һ��ʦ��ͨ���������������Ľ�������(diaocha)�鱨��\n"NOR);
        set("unit", "��");
        set("weight", 90);
        set("no_sell",1);
        set("value", 0);
}

void init()
{
	add_action("do_diaocha","diaocha");
        add_action("do_jiaoxun","jiaoxun");
}

int do_diaocha(string arg)
{
	object me=this_player() , ob,npc ;

	if (!arg) return notify_fail("��Ҫ����˭��\n");

	ob = present(arg, environment(me));

	if (!ob || !living(ob)) return notify_fail("��Ҫ����˭��\n");
	
	
	if ( userp(ob) || ob->query_temp("party_job_target")!= me->query("id") )
		return notify_fail("����˺�����Ҫ�����Ǹ��ɣ�\n");
        if (me->query_temp("party_job_start"))
                return notify_fail("���Ѿ�����������ˣ�������һ���ɣ�\n");
       if (me->query_temp("party_job_over"))
                return notify_fail("���Ѿ�����������ˣ�������һ���ɣ�\n");

	message_vision(HIY"$N"HIY"ԶԶ��$n��ȥ��ֻ��$n��ɫ��˸������\n"NOR,me, ob);
	message_vision(HIR"\nֻ��$N������ɫ����������˵��������ʵ��������....��\n"NOR, ob);
	message_vision(HIR"\n����δ�䣬������ܳ�����Ӱ�����ɷ�˵��$N��ȥ��\n"NOR, me,ob);
me->set_temp("party_job_start",1);
npc = new("/quest/party/guard");
npc->do_copy(me,0);
npc->move(environment(me));
npc->set("�߷�",ob);
npc->set_temp("target", me->query("id"));
me->kill_ob(npc);
npc->kill_ob(me);
	return 1;
}


int do_jiaoxun(string arg)
{
	object me=this_player() , ob,target ;
        int gx;  
	if(!arg ) return notify_fail("��Ҫ��ʲô��\n");

	
   
        if(me->is_busy() || me->is_fighting()) 
                 return notify_fail("����æ���ء�\n"); 

if(me->query_temp("party_job_start"))
         return notify_fail("���ȸϽ������������˵�ɡ�\n");

if(!me->query_temp("party_job_over"))
         return notify_fail("���������׾����ѵ�ˣ��㹻�ݵġ�\n");

 
 if (present(arg, environment(me))->query_temp("party_job_target") != me->query("id") )
return notify_fail("����˺�����Ҫ�����Ǹ��ɣ�\n");

 if(objectp(ob) && ob==present("jianxi", environment(me)))
       if(ob->query("�߷�") == me->query_temp("party_job_npc") )
        return notify_fail("��ϸ��û��ȥ�����ĳ���ô��\n");
		
message_vision(HIR"\n$N��ǰ�����ĳ��ؽ�ѵ��$n"HIR"һ����$n��������޵����ݡ�\n\n"NOR, me, present(arg, environment(me)));

  
//	me->set_temp("diaochaover",1); 
	me->start_busy(1);


TASKREWARD_D->get_reward(me,"ʦ�Ź���",1,0,0,random(2)+1,0,0,0,this_object());
gx = 1+random(2);
message_vision(HIY"$N���������еõ���"+CHINESE_D->chinese_number(gx)+"��ʦ�Ź��ס�\n"NOR, me);

me->delete_temp("party_job");
me->delete_temp("party_job_target");
me->delete_temp("party_job_over");
me->apply_condition("job_busy",2);
me->add("party_cont",gx);
me->set("job_name","ʦ�Ź���");

destruct(this_object());

	return 1;
}


	



