// taiji.c ̫��ȭ��̫����
// by lsxk@hsbbs 2/06/2007
/*
	�򣭣��Լ�������ʱ,���Ĵ������������ɶԷ�����
	�ۣ����Լ�������ʱ,���ͶԷ���������
	���������жԷ�ʱ,�öԷ�����æ��
	���������жԷ�ʱ,�ڶ�ʱ���ڶԷ��޷�ʹ�������ڹ�
	�ɣ������жԷ�ʱ,���Է�æ��,���ػ�����
   �������Լ�������ʱ,�ڶ�ʱ���ڶԷ��޷�ʹ�������⹦
   �⣭�����жԷ�ʱ,�ػ��Է�
   �������Լ�������ʱ,ʹ�Է���ʱ�����޷�����
*/
//�ʵ��µ�������ֵ����ҷ�ӳ̫��̬�ˡ���By Spiderii
inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

#define TAIJI                "/kungfu/skill/yinyun-ziqi/taiji"

void taiji_check(object, object, string, int);

string perform_name(){ return WHT"̫��"NOR; }
string *taiji_sn = ({"��","��","��","��","��","��","��","��",});

int perform(object me, object target)
{
        if( !target ) target = offensive_target(me);

         if( !objectp(target)|| !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("��̫����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

   if(userp(me) && me->query("quest/tjq/taiji")!="pass")
       return notify_fail("����δ��̫ͨ������,������ʹ�á�̫������˾��������!\n");

	if( userp(me)
        &&( me->query_skill_mapped("parry") != "taiji-quan" ))
                return notify_fail("��̫������������̫��ȭ�����мܵ�����²���ʹ�á�\n");
        if( userp(me) && ( me->query_skill_mapped("force") != "yinyun-ziqi"
        || me->query_skill_prepared("cuff") != "taiji-quan") )
                return notify_fail("����ڹ���ȭ�����ԣ��������ܷ��ӳ���̫���������ơ�\n");  
        if( me->query_skill("taiji-quan", 1) < 350 )
                return notify_fail("���̫��ȭ�����⻹��������ʹ�����⾫��ġ�̫������\n");
        if( me->query_skill("yinyun-ziqi", 1) < 350 )
                return notify_fail("����������Ļ������������޷�ʹ����̫����!\n");
        if( me->query_skill("taoism", 1) < 200 )
                return notify_fail("��Ե�ѧ�ķ�����⻹������ʹ���⾫���̫����̫����Ω�ֻ��߻���ħ��\n");
        if( (int)me->query("neili", 1) < 2000 )
                return notify_fail("��̫�����˿�һ�ھ�տ����������֧������Ŀǰ������ʵ������ʹ���þ��У�\n"); 

        if( (int)me->query("max_neili", 1) < 8000 )
                return notify_fail("��̫�����˿�һ�ھ�տ����������֧������Ŀǰ��������Ϊʵ���������ף�\n"); 
//         if( (int)me->query("max_jingli", 1) < 4000 )  
// ������max_jingli ����eff_jingli
  if( (int)me->query("eff_jingli", 1) < 4000 )  
                return notify_fail("��̫�����������ļ���ľ������˵���ʤ�ľ���,��Ŀǰ�ľ�����Ϊʵ��̫���ˣ�\n"); 
        if( (int)me->query("jingli", 1) < 1500 )
                return notify_fail("��Ŀǰ�ľ���̫����,ʹ������̫�������У�\n");

	if( me->query_temp("tjq/taiji"))
                return notify_fail("������ʹ�á�̫����!\n");

        if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n"); 

        return (int)call_other( this_object(), "main", me, target);
}

int main(object me, object target)
{
        int i,num,j;
        string msg, taiji_set;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target)
        || me->query("neili") < 2000 || me->query("jingli") < 1500 || me->query_temp("weapon"))
                return 0;

       i = (int)me->query_skill("taiji-quan",1) / 20; 
	j = 3 + ((int)me->query_skill("taiji-quan",1)-350)/30;
	if (j>8) j = 8;

	taiji_set = me->query("env/taiji");

         msg = HBMAG+HIW "\n$N��������۾�����ʽ�Ѳ�������֮��������ÿһ�У�ÿһʽ�������λ����������ջأ����ް����ǣ�"+
                "\n$N����̫���ھ���Ҫ֮�����ӵ����쾡�£���ʽ��Ȼһ�壬��Ȼ��á�̫������Ҫ��\n"NOR;
        message_vision(msg, me, target);
me->add_temp("apply/defense",me->query_skill("taiji-quan")/2 );
if(me->query_skill("taiji-quan",1)<450 )
   me->start_perform(1,"��̫����");

	if (!me->query("env/taiji")){
		for (num=0;num<j;num++){
		   if (!me->query("env/taiji"))
			me->set("env/taiji",taiji_sn[random(sizeof(taiji_sn))]+"|");
		   else
                   me->set("env/taiji",me->query("env/taiji")+taiji_sn[random(sizeof(taiji_sn))]+"|");
		}
		taiji_set = "none";
	}
   me->set_temp("tjq/taiji",j); 
   me->add_temp("apply/attack", i);
   me->add_temp("apply/armor", i);
   me->add_temp("apply/dodge", i);
        taiji_check(me,target,taiji_set,i);
 target->set_temp("must_be_hit",1);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 3);
 target->delete_temp("must_be_hit");
        return 1;
}

void taiji_check(object me, object target, string taiji_set, int i)
{
	if (!me) return;
	if (!me->is_fighting()
	 || me->query_skill_mapped("cuff")!="taiji-quan"
	 || me->query_skill_mapped("force")!="yinyun-ziqi"
	 || me->query_skill_mapped("parry")!="taiji-quan"
	 || !me->query_temp("tjq/taiji")
	 || (int)me->query("neili",1) < 2000
	 || (int)me->query("jingli",1) < 1500
	 || me->is_ghost()
	 || (me->query_temp("tjq/taiji") && !me->query("env/taiji") )) {
 		me->delete_temp("tjq/taiji");
           me->add_temp("apply/attack", -i);
           me->add_temp("apply/armor", -i);
           me->add_temp("apply/dodge", -i);
                message_vision(WHT"\n$N��̫������ʹ�꣬���鵤������չ����ˣ�\n"NOR, me);
me->add_temp("apply/defense", - me->query_skill("taiji-quan")/2 );
		if (taiji_set!="none") me->set("env/taiji",taiji_set);
		else me->delete("env/taiji");
	}
   else{
//       remove_call_out("taiji_check");
       call_out("taiji_check",1,me,target,taiji_set,i);
   }
   return;
}

int help(object me)
{
	write(WHT"\n̫����"WHT"̫��"WHT"����"NOR"\n");
	write(@HELP
    ̫���ߣ�������ǧ��֮�䣬�Է���ʤ�����������֮�Σ������Ϊ�������
    ׼�����糵�֣�ƫ�����棬˫�����͡�����������򶮾����ɶ������׼���
    ����Ȼ�������վã����ܻ�Ȼ��ͨ�ɡ�
    �ˡ�̫��������̫��ȭ�����������ľ�����������ļ�������һ�����
    ��!�����õ÷�,�ֵ��������ܵ�!
    ָ��:  perform taiji

    Ҫ��������� 8000 ���ϣ�
          ����� 4000 ���ϣ�
          ��ǰ���� 2000 ���ϣ�
          ��ǰ���� 1500 ���ϣ�
          ̫��ȭ�ȼ� 350 ���ϣ�
          �������ȼ� 350 ���ϣ�
          ��ѧ�ķ��ȼ� 200 ���ϣ�
          ����̫��ȭΪ�м������ޱ�����
          ʹ��ǰ�밴�ո�ʽset taiji ����1|����2|����3|....�趨˳��
          ��ѡ�������£�
          ���ۣ����������ɣ������⣬����
HELP
	);
	return 1;
}
