// fen.c ��
// by iceland
// modefied by emnil@sj 2/3/2k
 
#include <ansi.h>
 
inherit F_SSERVER;
 
string perform_name(){ return HIR"���־�"NOR; }

int perform(object me)
{
        string msg;
        object target,*inv;
        int hskill, lskill, ap, dp,i;
        int neili_wound, qi_wound=0 ,stradd,armor,fail;

        target = me->select_opponent();
        hskill = me->query_skill("huoyan-dao",1);
        lskill = me->query_skill("longxiang-boruo",1);

        if( !userp(me) && userp(target) )
                return notify_fail("���١�ֻ�����ʹ�á�\n");

        if( !(me->is_fighting() ))
                return notify_fail("���١�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("��ֻ�ܿ������á��١��ľ�����\n");

        if( hskill < 120)
                return notify_fail("��ġ����浶���ȼ�����, ����ʹ�����١��ľ�����\n");

        if( lskill < 120)
                return notify_fail("��ġ��������������������, ����ʹ�����١��ľ�����\n");

        if( me->query("neili") < 1200 )
                return notify_fail("������������þ������������١��ˣ�\n");

        if( me->query("jingli") < 300 )
                return notify_fail("��ľ��������þ������������١��ˣ�\n");

        if( me->query("max_neili") < 2000 )
                return notify_fail("����������������ܴ߶������������١�������\n");

        if( me->query_skill_mapped("strike") != "huoyan-dao"
         || me->query_skill_prepared("strike") != "huoyan-dao")
                return notify_fail("�����ʹ�á����浶��������ʹ�����١��ľ�����\n");

        if( me->query_skill_mapped("force") != "longxiang-boruo")
                return notify_fail("��������ʹ�õ��ڹ�ͬ���������������ִ�������ʹ�����١��ľ�����\n");
 
        msg = HIR "\n$N������ס$n��˫�ƾ�������������ͻȻ�������˫���Ƴ���\n������������˲�佫$n���ڻ��С�\n"NOR;

        message_vision(msg, me, target);
   
        if(me->query_temp("xs/fail")
         && me->query_temp("xs/failed") == target->query("id"))
            fail = me->query_temp("xs/fail");
        else {
            fail = 0;
            me->set_temp("xs/fail",0);
            me->delete_temp("xs/failed");
        }
        ap = me->query_skill("strike") + me->query_skill("force")/6;
        dp = target->query_skill("dodge")+ target->query_skill("parry")/6;

        if( dp < 1 )
                dp = 1;

        if((random(ap) > dp/2)
         || ap/2 > dp
         || fail >= 4 ){
           msg = HIR "\n$n��������ë�������Ż�Ƥ��ͷ�����յ�֨֨���죬�����ڵأ���ס�����ſޣ�\n"NOR;
           if(me->query_temp("xs/longxiang")){
              stradd = lskill/20*3;
              msg += MAG"$N��������֮��������$n������ʹ$n���ϼ��ˣ�\n"NOR;
              target->add_temp("hyd/fen_count",1);
           }               
           else 
              stradd = 0;
              if(lskill >=140 )
                neili_wound = (me->query_str()+ stradd)*3 + (hskill+lskill)/2;
              else 
                neili_wound = (me->query_str()+ stradd)*2 + (hskill+lskill)/2;

              neili_wound = neili_wound*3/4 + random(neili_wound/2);
                
              qi_wound = neili_wound * (4 + ((int)target->query_temp("hyd/fen_count",1) )*3/2);

               if (hskill>350)
                  qi_wound *= 2;

              if(neili_wound > target->query("neili"))
                neili_wound = target->query("neili");

              armor = 0;
              inv = all_inventory(target);
              if(sizeof(inv)){
                  for (i=0;i<sizeof(inv);i++) {
                    if(inv[i]->query("armor_prop/armor") > 0) {
                       armor = 1;
                       if (inv[i]->query("armor_prop/armor") > 150 
                        && inv[i]->query("equipped")){
                           qi_wound=qi_wound/5*4;
                           neili_wound=neili_wound/5*4;
                       }
                       if( !inv[i]->query("unique") ){ 
                           msg+=HIG"\n$n���ϵ�"+inv[i]->query("name")+HIG"�����浶���٣���ƬƬ�Ʋ���Ʈ�䡣\n"NOR;
                           destruct(inv[i]);
                       }
                    }
                 }
              } 
              if(armor) {
                   qi_wound=qi_wound*3/4;
                   neili_wound=neili_wound*3/4;            
              }
              if(neili_wound > 1000) neili_wound = 1000 + (neili_wound -1000)/100;
              target->add("neili", -neili_wound);
                if(qi_wound > 2200) qi_wound = 2200 + (qi_wound-2200)/ 100;
              target->receive_damage("qi", qi_wound);
              if(wizardp(me) && me->query("env/test"))
              tell_object(me,sprintf("qi:%d , neili:%d \n",qi_wound,neili_wound));
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ qi_wound+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+qi_wound+ WHT"���˺���\n"NOR); ;
              target->receive_wound("qi", random (qi_wound /2)  );
              target->apply_condition("hyd_condition", (me->query_skill("huoyan-dao")/20)
                    + 1 + target->query_condition("hyd_condition"));
              me->add("neili",-300-random(200));
              me->add("jingli",-100);
              if(me->query("neili") < 0)
              me->set("neili",0);
              me->start_busy(random(2)+1);
              target->start_busy(1);
              me->set_temp("xs/fail",0);
              me->start_perform(4,"���١�");
        }
        else {
              msg = HIC "\n$n��ææ�ӻ���Ծ���͵�һ����ͷ�����Ǳ��Ʒ�����������˼��ٸ������ŵ���ɫ�԰�\n"NOR;
              me->add("neili",-150);
              me->start_busy(random(3)+1);
              me->start_perform(3,"���١�");
              me->add_temp("xs/fail",1);
              me->set_temp("xs/failed", target->query("id"));
        }
        message_vision(msg, me, target);
        if(qi_wound > 0){
                msg = COMBAT_D->damage_msg(qi_wound,"����");
                msg = replace_string( msg, "$l", "�ؿ�" );
                msg = replace_string( msg, "$w", "����" );
                message_vision(msg,me,target);
                COMBAT_D->report_status(target, 0);     
        }
        return 1;
}
