///kungfu/skill/haotian-zhang/lianhuan.c ����������
// Modified by action@SJ 2008/09/15
#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;
string perform_name(){ return HIR"����������"NOR; }

void remove_effect(object me, int improve);

int perform(object me, object target)
{
        int lv, i, hit,j;
        string weapon, htz_msg;

        if( !target ) target = offensive_target(me);

         if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("�����������ơ�ֻ����ս����ʹ�á�\n");
        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á����������ơ���\n");   
                
        if( (int)me->query_skill("haotian-zhang", 1) < 100 )
                return notify_fail("����������ƻ�������죬ʹ���������������ơ�������\n");
                
        if (me->query_skill_prepared("strike") != "haotian-zhang"
            || me->query_skill_mapped("strike") != "haotian-zhang")
                return notify_fail("�������޷�ʹ�á����������ơ����й�����\n");  

        if( (int)me->query_skill("xiantian-gong", 1) < 100 )
                return notify_fail("������칦�ȼ���������ʹ���������������ơ�������\n");
                
        if (me->query_skill_mapped("force") != "xiantian-gong")
                return notify_fail("����ڹ������޷�ʹ�á����������ơ���\n");               
		            
        if( me->query("max_neili") < 1000 )
                return notify_fail("����������̫����ʹ���������������ơ���\n"); 
                     
        if( (int)me->query("neili") < 800 )
                return notify_fail("����������̫����ʹ���������������ơ���\n");
      
        
        lv = me->query_skill("haotian-zhang",1);

if(!userp(me)) lv = lv / 2;

        hit = (lv/80);
        if(hit > 7) hit = 7;
        if(hit <2) hit = 2;

        me->add_temp("apply/attack",    lv/2);
        me->add_temp("apply/damage", lv /4);
        htz_msg = HIC"\n$NĬ�����칦���������";

        if(hit >= 1)htz_msg += "��"HIR"�����"HIC"��";
        if(hit >= 2)htz_msg += "����"HIG"������"HIC"��";
        if(hit >= 3)htz_msg += "����"HIY"������"HIC"��";
        if(hit >= 4)htz_msg += "����"HIB"��Ȩ��"HIC"��";
        if(hit >= 5)htz_msg += "����"HIM"�����"HIC"��";
        if(hit >= 6)htz_msg += "����"HIC"������"HIC"��";
        if(hit >= 7)htz_msg += "����"HIW"ҡ����"HIC"��";
        
        htz_msg += "�ǹ���й��"+chinese_number(hit)+"��΢΢һ����\n��������������������������������������ޱȣ�\n"NOR;

        message_vision(htz_msg, me, target);
        me->set_temp("htz_times",hit);
        me->set_temp("htz_effect",1);
        me->add_temp("htz/lianhuan", 3);
        me->set_temp("action_flag", member_array("strike", keys(me->query_skill_prepare())));

//����Ʒ�Ծ        
if( me->query("str",1)>=45 && userp(me)){
	                  me->set_temp("htzup",1);
	          if(!userp(target)) 	 target->set_temp("must_be_hit",1);
		          target->add_temp("apply/defense",-2000);
	   message_vision(HBBLU"\nֻ��$N�����������������Ƕ��⻪������Ͷ��֮�侹��˿���ǹ��˸���������Ǵ�����\n"NOR, me, target);
		}
		

if (me->query("quanzhen/force") =="pass" )  target->add_busy(2);
		
        for( i=0; i < hit; i++ )
        {
                me->add_temp("htz/lianhuan", 1);
          if (me->is_fighting(target))          COMBAT_D->do_attack(me, target, weapon, (lv<450)?1:3);
  
        }
        



       message_vision(HIC"\n��"+chinese_number(hit)+"�����������ƣ����������Ƕ���ת�켣���仯��������Ѳ⣡\n"NOR, me);


if(me->query_temp("htzup")) {
	   if(target) {


      message_vision(HBRED"\nֻ��$N����������������ҫ�������ǲ��ơ�֮���������ռ������λ������һ�ư���$n��\n"NOR, me, target);
                          target->start_busy(2);    

j = target->query("str");
if (j < 50) j =  target->query("con");
if (j < 50) j =  target->query("dex");
if (j < 50) j =  target->query("int");

           if( random(me->query("str",1)) > target->query("str",1)/2 
          && random(me->query("combat_exp",1)/10000) > target->query("combat_exp",1)/40000 
          && random(me->query("neili",1)/100 )> target->query("neili",1) /200 && j <50 )
{

     message_vision(HBMAG"�Ǿ�Ө������ǹ����һ��ը�ѿ�������Ȼȫ�Ǿ����������������۶��ɣ������罣���޼᲻�ݣ�\n$n⧲����������±����ض������ۿ��ǻ���ˣ�\n"NOR, me, target);
                          target->set("eff_qi",-1);
                          COMBAT_D->report_status(target);
                                                                                }
 else  message_vision(HBMAG"�Ǿ�Ө������ǹ����һ��ը�ѿ�������Ȼȫ�Ǿ����������������۶��ɣ������罣���޼᲻�ݣ�\n"+HIG+"$n֪���ǹ���죬��������׼���������ˣ����������ȴ�Ѿ������˲��ᡣ\n"NOR, me, target);
                          target->receive_damage("jingli", me->query_skill("haotian-zhang",1)*3+ random(me->query_skill("haotian-zhang",1))*3, me);
	           	  target->delete_temp("must_be_hit");
		          target->add_temp("apply/defense",2000);
                          
		            } 
		                      }

		     
        me->add("neili", -hit*20+20);
        me->add("jing", -hit*5);
        me->start_perform(3+random(2),"�����������ơ�");
        me->start_busy(1+random(2));
        me->delete_temp("htz/lianhuan");
        me->delete_temp("htz_times");
        
        me->delete_temp("htzup");
        
        me->add_temp("apply/attack",   - lv/2);
        me->add_temp("apply/damage", -lv /4);
        return 1;
}


int help(object me)
{
        write(HIR"\n��������֮�����������ơ���"NOR"\n");
        write(@HELP
       �����Ϊȫ�����������������ʽ�����ޱȣ������Ƕ��任�����°�����

        Ҫ��  ������� 3000 ���ϣ�      
                ��ǰ���� 1000  ���ϣ�  
                ����Ƶȼ� 100 ���ϣ�
                ���칦�ȼ� 100 ���ϣ�
                �����Ʒ�Ϊ����ƣ�
                �����м�Ϊ����ƣ�
                �ȼ�Խ������Խ��
                �����ޱ�����
                �������>=45���ж��⹥���ӳ�
                
HELP
        );
        return 1;
}


