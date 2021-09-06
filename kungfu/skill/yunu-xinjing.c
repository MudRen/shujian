// yunu-xinjing.c ��Ů�ľ�
// Modify By River 10/98

#include <ansi.h>
inherit FORCE;
#include "/kungfu/skill/eff_msg.h";


int valid_enable(string usage) { 
	  if (this_player()->query("family/family_name")=="��Ĺ��" || this_player()->query("cw_mp/��Ĺ��") )return usage == "force"; }

#include "force.h"

int valid_learn(object me)
{
		mapping fam  = me->query("family");
        int lvl = (int)me->query_skill("yunu-xinjing", 1);


	if ((!fam || fam["family_name"] != "��Ĺ��" )&& !me->query("cw_mp/��Ĺ��") )
			 	return notify_fail("�㲢�ǹ�Ĺ���ӣ����ϰ������Ů�ľ���\n");
	if ( me->query("gender") == "����") 
		return notify_fail("���޸����ԣ������������������������Ů�ľ��񹦡�\n");

        if ( lvl < 120)
                return notify_fail("�����ڻ�ֻ��ͨ�����������������Ů�ľ��񹦡�\n");

        if ((int)me->query_skill("yunu-xinjing", 1) > me->query_skill("force", 1) + 10
          && me->query_skill("yunu-xinjing", 1) >= 200 )
               return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        return valid_public(me);
}

int practice_skill(object me)
{
	if((int)me->query_skill("yunu-xinjing", 1) >= 200 ){
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200){
			me->improve_skill("yunu-xinjing", (int)me->query_int());
			me->add("neili", -100); 
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("�����ڵ���Ϊ�����������Ů�ľ��ˡ�\n");
	}
	else return notify_fail("�����ڵ���Ů�ľ���Ϊֻ����ѧ(learn)�������������ȡ�\n");

}

string exert_function_file(string func)
{
	return __DIR__"yunu-xinjing/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIB + me->name()+"��̬���ţ���̬����"NOR,
		"start_my_msg" : "���������һ�����������۾���������Ů�ľ�����Ϣ�������п�ʼ��ת��\n",
		"start_other_msg" : me->name()+"��̬ͻȻ��ʼ��������ޱȣ����������ֱ�������쳣��\n",
		"halt_msg" : "$N��Ϣһת��Ѹ��������ֹͣ����Ϣ����ת��\n",
		"end_my_msg" : "���������������뵤������۾������������һ������\n",
		"end_other_msg" : "ֻ��"+me->name()+"�����۾���������³���һ��������̬�ָ���Ȼ��\n"
	]);
}

int hit_ob(object me, object ob, int damage)
{
	object weapon;	
	if( me->query_int(1) > 40
	 && me->query_dex(1) > 40
	 && me->query_skill_mapped("hand") == "tianluo-diwang"
	 && me->query_skill_mapped("cuff") == "meinu-quanfa"
	 && me->query_skill("hand") > 300
	 && me->query_skill("cuff") > 300
	 && me->query("neili") > 500
	 && me->query("jingli") > 500
	 && me->query("family/family_name") == "��Ĺ��"
	 && me->query("env/��Ů�ľ�") == "�ں�"
	 && !me->query_temp("anran")
//	 &&!ob->is_busy()
//	 &&!ob->is_lost()
	 &&!random(2)
                     ){
		if (weapon=me->query_temp("weapon"))
			message_vision(HIC"$N�����е�"+weapon->query("name")+HIC"һ�գ�",me);
		else
			message_vision(HIC"$N��ʽһ�䣬",me);

		if(ob->query("class") != "bonze"
		 && ob->query("class") != "huanxi" 
		 && me->query("gender") != ob->query("gender")){
			message_vision(HIC"ʩչ����Ĺ�ɵմ���Ůȭ����\n", me);
			if (random(me->query_per()) > ob->query_per()/2){
				message_vision(HIR"$n����һ�ң���Щ��$N����Ҫ����һ����æ���ң�\n"NOR, me, ob);
				ob->add_busy(2+random(3));
				me->add("jingli",-50);
				me->add("neili",-100);
			}
			else
				message_vision(HIC"$n����һ�ң���æ������������\n"NOR, me, ob);
		}
		else {
			message_vision(HIC"ʩչ����Ĺ�ɵմ����޵����ƣ�\n", me);
			if (random(me->query_dex()) > ob->query_dex()/2){
				message_vision(HIR"$n�����ܴ죬�Թ˲�Ͼ���޷�׼ȷ����$N������\n"NOR, me, ob);
				ob->start_lost(2+random(3));
				me->add("neili",-50);
				me->add("jingli",-100);
			}
		else
			message_vision(HIC"$n�Կ��죬�ƽ���$N����Ϯ��\n"NOR, me, ob);
		}
	}
}

int ob_hit(object ob, object me, int damage)
{

string *pictures=({
"�ľ�����","�������","��������","�����ˮ","�ǻ��չ�","��������","��ʬ����", "ӹ������"
});


string *pictures2=({
HIM"һ��" HIR "��������ǡ�" HIM "ֱ����$n��$l"NOR,
HIM"צצ����$n��һ��" HIR "������������" HIM "����$n��$lץ��"NOR,
HIM"ʹ��" HIR "�����޵�����" HIM "��$n��$l����ȫ������צӰ֮��"NOR, 
HIM"ʹһ��" HIR "�������ơ�" HIM "����צ�ó�����צӰץ��$nȫ��"NOR,
HIM"����������һ��" HIR "��Ψ�Ҷ���" HIM "��צ������$n�������"NOR
   });


 string picture,picture2,msg;
 int p;
 picture = pictures[random(sizeof(pictures))];
 picture2 = pictures2[random(sizeof(pictures2))]; 

if(!environment(me)) return 0;
if(!me->query("quest/jiuyingm/pass")) return 0;

if(me->query_skill("jiuyin-shenfa",1)<=181 ) return 0;

if(!random(3) && me->query("env/����")
	&& (me->query("qi")-damage) <=  me->query("max_qi")*2/3 )
	   {  message_vision(HIY"$N�������㣬ͻȻʹ����"HIW"�����澭"HIY"�ϵĹ��򣬶������������һ����\n" NOR, me);
      	return -damage;
     	}


if(me->query_skill("anran-zhang",1)<=450 ) return 0;
    
if(random(3) 
	&& me->query("quest/gmsuper/pass") 
	&& (me->query("qi")-damage) <=  me->query("max_qi")*2/3){  
  
        message_vision(HIW"$N����������ݾ��������������ң���Ȼ֮�����Ķ�����û����ɵ��ĳ�һ�ơ�"+picture+"����\n"+
                          "�����Ʒ缤�����л��㱣�����ԼԼ��ɲʱ��Ȼ�����������������Ʋ��ɵ���\n"NOR,me);
                        
        message_vision("ֻ����$Nһ���ҽУ���������������ߵķ���һ�����˳�ȥ����\n"NOR,ob);
       ob->receive_damage("qi", damage/2);
       ob->receive_wound("qi", damage/4);
   
    p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
    
       msg = "( $n"+eff_status_msg(p)+" )\n";
       message_vision(msg, me, ob); 


       if(damage/2 >= ob->query("qi")) ob->unconcious();
                        
       return -damage;

}


if(me->query_skill("jiuyin-shenzhua",1)<=451 ) return 0;
	
  if(random(4) && me->query("quest/gmsuper/pass")){  
  
        message_vision(HIM"$N������Ů�ľ���һ�Ķ��ã��������ų�צ����"+picture2+"����\n"NOR,me,ob);
                        
        message_vision(HIM"����Դ�Թ�Ĺʯ�̵ľ�����ʽ��$n��ʽ���ϣ�����δ���������˸����ֲ�����\n"NOR,me,ob);
       ob->receive_damage("qi", damage/3);
       ob->receive_wound("qi", damage/6);
   
    p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
    
       msg = "( $n"+eff_status_msg(p)+" )\n";
       message_vision(msg, me, ob); 


       if(damage/3 >= ob->query("qi")) ob->unconcious();
                        
       return -damage;

}	
     return 0;

        
}

