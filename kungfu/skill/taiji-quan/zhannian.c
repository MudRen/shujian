// zhannian.c ̫��ȭ��մ������
// by snowman@SJ 23/03/2000

inherit F_SSERVER;
#include <ansi.h>
#include <combat_msg.h>

#define TAIJI                "/kungfu/skill/yinyun-ziqi/taiji"

int is_pfm() {       return 1;}
string perform_name(){ return HIR"մ��"NOR; }

int perform(object me, object target)
{ 
	object ob;
        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("��մ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( userp(me) 
        &&( me->query_skill_mapped("parry") != "taiji-quan"
        && me->query_skill_mapped("parry") != "taiji-jian") )
                return notify_fail("��մ������������̫��ȭ��̫���������мܵ�����²���ʹ�á�\n");
        if( userp(me) && ( me->query_skill_mapped("force") != "yinyun-ziqi"
        || me->query_skill_prepared("cuff") != "taiji-quan") )
                return notify_fail("����ڹ���ȭ�����ԣ��������ܷ��ӳ���մ���������ơ�\n");  
        if( !me->query_temp("tj/̫��") && me->query_skill("taiji-quan", 1) < 300 )
                return notify_fail("̫��ȭ��Ҫ���ڶ�����Ӧ���������棬��û�����á�̫�������������ʹ�á�մ������\n");
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������������ǿ��ʹ�á�մ�����Ƿ��Ӳ������������ģ�\n");                   
        if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n");     
        if( target->is_busy())
                return notify_fail("�Է����Թ˲�Ͼ�أ��㲻æʹ�á�ճ���־���\n");
        if( objectp(ob = me->query_temp("tjq/zhannian")) ) {
                if( ob->is_fighting(me) || me->is_fighting(ob))
                	return notify_fail("���Ѿ���ճ��ճ������ˡ�\n");
                else me->delete_temp("tjq/zhannian");
        }
        return (int)call_other( this_object(), "main", me, target);
}

int main(object me, object target)
{
        int damage = 1;
        string msg, force, str;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) 
        || me->query("neili") < 300 || me->query("jingli") < 100 || me->query_temp("weapon"))
                return 0;     
                
        if(intp(me->query_temp("tjq/"+target->query("id")) > 2))
                me->add_temp("tjq/"+target->query("id"), -2);
        else me->delete_temp("tjq/"+target->query("id"));
        
        str = (string)me->query("env/���Ͼ�"); 
        if(str != "�귭" && str != "����" && str != "����" && str != "����" && str != "����" && str != "����")
                str = "��";
                
        msg = CYN"\n$Nʹ��̫��ȭ��"RED"��մ����"CYN"����$n��";
        
        if(me->query_skill_mapped("force") != "yinyun-ziqi"
        || me->query_skill("yinyun-ziqi", 1) < 100){
                msg += "��һ�ӣ���Ҫ�ס$n��\n"NOR;
                str = "��";
        }        
        
        else msg += "һ��һʽ�ڽڹᴮ���糤����ӣ�\n"NOR;
        
  	if(TAIJI->check_force(target) == str )
                damage = 2;
       
        me->start_perform(2, "��մ����");
        if(!stringp(force = to_chinese(target->query_skill_mapped("force"))))
                force = "�ڹ�";
        
        if(wizardp(me) && (string)me->query("env/combat")=="verbose")
                tell_object(me, "Str = "+str+"��Force = "+force+"��Damage = "+damage+"\n");
        
        if( random(me->query("combat_exp")) * damage > target->query("combat_exp")/2 ){
        	msg += CYN"������ճ��һ��"RED"��ճ��"CYN"��$n���ϣ�����$p��ô���ѣ������Ѳ���"HIW"��"+str+"����"CYN"�İ�Χ��һ��ԲȦ����\n"+"һ��ԲȦ����Ȧ��СȦ��ƽȦ����Ȧ����Ȧ��бȦ��һ����̫��ԲȦ���������಻�ϣ����ϲ�����\n"NOR;
		tell_object(target, HIR"��һ���ӱ�"+me->name()+"�ס����Ҳ���ǣ���Ҳ���ǣ����˸���æ���ң�\n"NOR);
	       target->receive_wound("jing", me->query_int(1)* 2+ me->query_con(1)*2 , me);
                me->start_perform(2, "��մ����");
                me->set_temp("tjq/zhannian", target);
                me->start_busy(1);
                if(!target->is_busy()) target->start_busy(3);
		me->add("neili", -250);
		me->add("jingli", -100);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), me->query_int()/2);      
        }
        
        else{
                msg += HIY"��$p�����ϵ���˳��$PҲ������ԲȦ���ѳ��ˡ�մ�����İ�Χ��\n"NOR;
		me->add("neili", -100);
		me->add("jingli", -50);
                me->start_busy(random(2));
        }

        message_vision(msg, me, target);
        return 1;
}

void remove_effect(object me)
{
	object ob;
	if( !me ) return;
	if( !objectp(ob = me->query_temp("tjq/zhannian")) ) return;
	
        me->delete_temp("tjq/zhannian");
        ob->delete_temp("lost_attack");
        if( me->is_fighting() )
        	message_vision(HIC"\n$N΢΢һЦ���ھ���ת����մ�����չ����ˡ�\n"NOR, me);
}

int help(object me)
{
	write(WHT"\n̫����մ������"NOR"\n");
	write(@HELP
	̫���ߣ�������ǧ��֮�䣬�Է���ʤ�����������֮�Σ������Ϊ�������
	׼�����糵�֣�ƫ�����棬˫�����͡�����������򶮾����ɶ������׼���
	����Ȼ�������վã����ܻ�Ȼ��ͨ�ɡ�
	մ����̫������������������ж��ߣ���ж�ֹ��Ŀ�����ڡ����С���
	
	Ҫ��	���� 500 ���ϣ�      
		���� 100 ���ϣ�      
		����̫��ȭ�������ޱ�����
HELP
	);
	return 1;
}
