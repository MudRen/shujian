// hook.c

#include <ansi.h>
#include <weapon.h>

inherit HOOK;
inherit F_UNIQUE;

int exercising(object me);
int halt_exercise(object me);

void create()
{
    set_name(HIW"����"NOR, ({ "hanyu gou", "gou", "hanyu", "hook" }));
	set_weight(18000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
set("long", "����һ����ǧ�꺮�����ƵĿ�߻��ֹ������������޴�����涾�⣬��������(liaoshang)�ı��\n");
		set("value", 300000);
		set("material", "yade");
		set("poisoned", "cold_poison");
                set("poison_number", 1000);
		set("unique", 1);
                set("rigidity", 4);
                set("sharpness", 2);
                set("weapon_prop/parry", 5);
                set("treasure",1);
                set("wield_neili", 500);
                set("wield_maxneili", 2500);
                set("wield_str", 25);
		set("wield_msg", HIW"$N������չ�������$n"HIW"�������У��ӳ�һ��ѩ�׵Ĺ⻪��\n"NOR);
		set("unwield_msg", "$Nת����ȥ���÷�����$n�������ñ��ڱ��ϡ�\n");
	}
	init_hook(120);
	setup();
}

void init()
{
        add_action("do_heal", "liaoshang");
}

int do_heal()
{
	mapping msg;
	string force;
	object me = this_player();
	
        if(me->query("family/family_name") != "������")
                return notify_fail("������޵��ӣ�����ʹ�ú������ˡ�\n");

        if( me->is_busy() )
                return notify_fail("����æ���ء�\n");
        
        if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");
		
        if ((int)me->query_skill("force") < 260)
                return notify_fail("����ڹ���Ϊ���������޷��������ú��񹳡�\n");
                
        if( (int)me->query("max_neili") < 3000 )
                return notify_fail("���������Ϊ�������޷��������ú��񹳡�\n");
                
        if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
                return notify_fail("�����ڲ�û�����˰���\n");
                
	if(!stringp(force = me->query_skill_mapped("force")) || me->query_skill(force, 1) < 160)
		return notify_fail("��������ڹ�������֧�������ú��񹳣�\n");
	
	if((int)me->query("neili") < 50 )
                return notify_fail("������������ˡ�\n");
	
	message_vision(HIY"$N��˫��ƽ���ں����ϣ�ֻ�����񹳽����ų�һ˿��͵Ĺ�â......\n"NOR,me);
	msg = SKILL_D(force)->exercise_msg(me);
      	if (!msg || undefinedp(msg["heal_msg"]))
           	message_vision(HIW"$N��ϥ���£���ʼ�˹����ˡ�\n"NOR,me);
      	else 	message_vision(msg["heal_msg"],me);

	me->set_temp("pending/qi_heal", 1);
      	me->set_temp("period", 1);
      	me->start_busy((: exercising :), (:halt_exercise:));
        return 1;
}

int exercising(object me)
{
	int period = (int)me->query_temp("period");
        int skill;
	int eff = me->query("eff_qi");
	int max = me->query("max_qi");
        string force;
        
        if(!living(me) || !(force = me->query_skill_mapped("force"))){
        	me->delete_temp("pending/qi_heal");
        	me->delete_temp("period");
       	        return 0;
        }
        
	if(me->query("family/family_name") == "������")
		skill = 180;
	else skill = 120;
        skill = (skill+random(skill))/4;
        skill += me->query_skill(force)/5;
        skill += random(me->query_con());
        
        if(me->query("jing") < 1 || me->query("jingli") < 1){
        	me->delete_temp("pending/qi_heal");
        	me->delete_temp("period");
        	me->unconcious();
        	return 0;
                }
        
        if( eff >= max ){
        	write("���ã���о��Լ��ں��񹳵İ����£����ϵ������Ѿ�ȫ���ˡ�\n");
                message_vision(HIW"$N����ȥ��ɫ����������һ���������˷��ں����ϵ�˫�ƣ�һ��Ҳû���ܹ��˵����ӡ�\n"NOR,me);
        	me->delete_temp("pending/qi_heal");
        	me->delete_temp("period");
        	return 0;
        	}
        if( (int)me->query("neili") < 50 ){
        	write("�������˹����ˣ�ȴ�����Լ���ʣ�����������ˡ�\n");
        	if(eff < max)
        	     write(HIY"�����һ����վ����������ϧ���ƻ�û����ȫ�ָ���\n"NOR);
        	message_vision(HIY"$N�˹���ϣ����������˷��ں����ϵ�˫�ƣ���ɫ������������ࡣ\n"NOR,me);
        	me->delete_temp("pending/qi_heal");
        	me->delete_temp("period");
        	return 0;
        	}
        me->receive_curing("qi", skill);
        me->receive_damage("neili", 50);
	switch(period) {
        case 5:
                write(YEL"�㲻ͣ�ش߶���Ϣ�����Ըо�������ֻ��������Ϣ�ڰ������ˡ�\n"NOR);
                break;
        case 20:
                message_vision(YEL"$N��������һ��������ɫ�������ö��ˡ�\n"NOR,me);
                break;
        case 40:
                write(YEL"�����Ϣ������ת��ǣ���ź��񹳵���Ϣͨ����ȫ��������\n"NOR);
                break;
        case 80:
                write(YEL"���񹳵���Ϣ���������ֻ���ת����е�ȫ����̹���ˡ�\n"NOR);
                me->improve_skill("force", 5+random(5));
                break;
        case 110:
        case 120:
        case 140:
                write(YEL"�����ģ���ȫ��������ں��񹳵İ�������Ѹ�ٵػָ��ţ�\n"NOR);
                me->improve_skill("force", 5);
                break;
        case 160:
        case 190:
                write(YEL"��ȫ�����޴󰭣�������ͣ���������񹳵���Ϣ��\n\n"NOR);
                me->improve_skill("force", 1);
                break;
        }
        period++;
        me->set_temp("period", period);
        return 1; 
}

int halt_exercise(object me)
{
	me->delete_temp("pending/qi_heal");
        me->delete_temp("period");
	me->receive_damage("jing", 50);
	me->receive_damage("jingli", 50);
	tell_object(me, "����ͷһ������æ������Ϣ��Ӳ���������񹳵���Ϣ������ȥ��\n");
	message_vision("$Nüͷһ�壬��˫���ջأ����ź���վ��������\n", me);    
        me->start_busy(1+random(5));
	return 1;
}

