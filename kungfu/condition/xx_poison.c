#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
int resist = me->query_skill("poison",1);

if( !living(me) ) message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
else {
tell_object(me, HIB "��Ȼһ��̹ǵ��溮Ϯ�������е������ƶ������ˣ�\n" NOR );
message("vision", me->name() + "������ͻȻ�������Σ����ظ�������������\n",
environment(me), me);
}
me->add_busy(2); 
me->receive_wound("qi", 300 - resist - random(me->query_con()), "���޶�����Ѫ����");
me->receive_wound("jing", 180 - random(me->query_con()), "���޶�����Ѫ����");

if (duration < random(3)) return 0;
	
if (random(duration) > 150 || !living(me)) {
if(random(me->query_kar()) < 2) {
me->set_temp("last_damage_from", "���޶���");
me->die();
return 0;
}
}
me->apply_condition("xx_poison", duration - 1);

return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}

