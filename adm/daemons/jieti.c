//by spiderii@ty ����NT���±���ת��ϵͳ���ر�˵������ϵͳ��������
#include <ansi.h>

string *jieti_msg = ({
        HIM "����ϥ���ڵ��ϣ�ƽ�ľ��������Ž���Ϣ������ѭ��ʮ�����죬����\n" NOR
        HIM "��ȫ��ͨ���裬�����������ķ�\n\n" NOR            
        HIR "            ��     ħ       ��      ��     ��     ��\n\n" NOR,
        
        HIW "��ʱֻ����һ������׹���������������ܲ���������ɫ���绮��\n" NOR 
        HIW "���գ���˿�����з��ģ�������ħ��������������������ֳ�����\n" NOR 
        HIW "�֣��ֱ���뵤����ٻ��У�ֻ�о�����Ͱٻ������˵̵�ˮ��һ\n" NOR 
        HIW "�㣬�����������ˮ�Ƶ���ǰ��ȥ���������������ľ���˲�䱻�ݻ١�\n" NOR,
        HIC "����˲�䱻�ٵľ�ʹ��Щʹ����ȥ�����崫��˺���ѷε�ʹ�࣬��\n" NOR 
        HIC "�����������ȫŤ���ˡ��������ʱ�䶼������������о����񾭹�\n" NOR 
        HIC "����������᳤һ�㡣\n" NOR ,
        HIM "��Ѩ��������������Ἧ������Ѩ�����ĵط����������������ںϣ�\n" NOR 
        HIM "�����γ�̫����״������������������������������������̫�����ᣬ\n" NOR 
        HIM "����̫��ͼ��ͻȻһ�����������Ҳ�����͵�����һ�£���֪����\n" NOR 
        HIM "������Ѩ�ɹ������������Ч����\n" NOR,
        HIY "������ʱ�����ܵ������·�ʲôǣ���ŷ��Ŀ�ʼ��������ӿ�룬\n" NOR 
        HIY "�Ծ��˵��ٶȷɿ�Ĵ�����Ѩ���ؿ�ʼ�޸��𻵵ľ�����˲���ھ���\n" NOR 
        HIY "��㱼���·�о��ص���ĸ�׵Ļ���㣬���̲�סϮ���ľ��⣬����\n" NOR 
        HIY "��˯����ȥ��������\n" NOR,
        HIG "�峿������������ɢ��������Ψ�д��һƬ�ž�����������\n" NOR,
        HIR "�㷢�����ڵ���������𾪣���Ȼ�����Ѿ����˽����ɣ�����ȴ����\n" NOR
        HIR "����Ϣ��ȡ֮��������֮���꣬����Ҳ���ؿ��˼���������ü������\n" NOR 
        HIR "��һС����ɫ̥�ǣ���ϸ�۲�Ļ����ᷢ�����̥����ͬһ�ѵ�����\n" NOR 
        HIR "����һ�㣬ɢ��������ɷ��֮���������������ӣ���������������\n" NOR 
        HIR "��Ƥһ�㣬ϡ�ﻩ���ĵ��²����ϻ���Ƥ��������Щ�����Ƥ�����\n" NOR 
        HIR "��������ǰ���ӵİ��ۡ�\n\n" NOR,
});

string get_jieti_place()
{
        string file;
        
        file = domain_file(base_name(this_object()));
        
        return file;
}

int do_jieti();
int do_decide(object); 
void jieti_player(object me);

int do_jieti()
{
        object me;
        string msg;
        
        me = this_player();

        if (me->query("combat_exp") < 20000000)
                return notify_fail("��ľ��黹������óȻ��ħ���壬���߻���ħ�ġ�\n");
/*
        if((int)me->query("combat_exp",1) - (int)me->query("relife/failed_exp",1) < 500000)
                return notify_fail("�㻹��Ҫ�ٶ���۵�ʵս���鷽����ת�����޻��ᣡ\n");

        if(time() - (int)me->query("relife/failed_time",1) < 86400)
                return notify_fail("��ճ��Թ�ת�����ޣ���������Ϣ��ɣ�\n");

        if (random((int)me->query("kar")+((int)me->query("combat_exp")/1000000)) < 20){
                me->add("relife/failed",1);
                me->set("relife/failed_time",time());
                me->set("relife/failed_exp",(int)me->query("combat_exp"));
                log_file("quest/zhuanshi_fail", sprintf(HIR"%s(%s) ��̩ɽ֮��ת������ʧ�ܡ������ܼ�ʧ��%d��!\n"NOR, me->name(1),me->query("id"), me->query("relife/failed")) );
                return notify_fail("�������룬�����Լ��ƺ���δ׼���ã������´���˵�ɡ�������\n");
        }
*/
        msg = HIY "��ħ������һ�ֺķѴ����ľ��顢�似�������л���ѧ����ķ�ʽ��ͨ����ħ\n" +
                  "���壬���Դ�������������ʣ��������������ʡ��������ޡ��������ޡ���\n" +
                  "���������Ǳ������õ��ܴ����ߣ���ս���е�ɱ����Ҳ����ļ�ǿ����\n" +
                  "�Ƿ�ȷ��(decide)�Լ���������ħ���壿\n" NOR;

        me->set_temp("attempt_jieti",1);
        tell_object(me, msg);
        add_action("do_decide","decide");
        return 1;
}

int do_decide(string arg)
{
        object me = this_player();
        
        if (!me->query_temp("attempt_jieti"))
                return notify_fail("�������ʲô��\n");
       if (arg != "jieti")
               return notify_fail("������ʲô����\n");
        tell_object(me, HIW "���Ŀ��˼�����ã������¶����ģ�������ħ���壡��\n\n" NOR);
        me->delete_temp("attempt_jieti");
        call_out("jieti_msg", 0, me, 0);
        return 1;
}

void jieti_player(object me)
{
        string *skl;
        mapping skill;
        int i, j;
                
        if (me->query("gender") == "����")
                me->set("gender", "����");   
                             
        me->delete("relife/failed");
        me->delete("relife/failed_time");
        me->delete("relife/failed_exp");

        me->set("shen", 0);
        me->set("mud_age", 0);
        me->set("age", 16); 
        me->set("relife/time", time());
        me->add("relife/times", 1);
        me->set("balance",5000000);
        me->set("SJ_Credit",500);       
        me->set("relife/combat_exp",(int)me->query("combat_exp",1));
        me->set("combat_exp", 1000000);
        me->set("potential", 10000);
        me->set("max_neili", 5000);
        me->set("max_qi", 2500);
        me->set("max_jing", 1500);
        me->set("max_jingli", 3000);
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("eff_qi"));
        me->set("eff_jing", me->query("max_jing"));
        me->set("jing", me->query("eff_jing"));
        me->set("eff_jingli", me->query("max_jingli"));
        
        me->delete("MKS");                   //ɱNPC��¼
        me->delete("PKS");                    //ɱPLAYER��¼
        me->delete("FKS");                    //����������¼
        me->delete("SJ_YuanBao");          //�Խ�Ԫ��
        me->delete("last_death");            //�ϴ�������¼      
        me->delete("family");                // ���ɼ�¼
        me->set("title", "��ͨ����");        // ���˳ƺ�
        me->delete("user_weapon_imbued");    //�������
        me->delete("no_pk");                 //ϴ�ֱ��
        me->delete("betrayer");              //��ʦ��¼
        me->delete("rules");                 //�����¼
        me->delete("death_count");           //����������¼
        me->delete("death_times");           //������Ч��¼
        me->delete("nickname");              //��ż�¼
        me->delete("quest");                 //quest��¼
        me->delete("double_attack");         //���һ���
        me->delete("job_time");              //�������
        me->delete("luohan_winner",1);          //�޺����¼
        me->delete("forging");                //�������ܼ�¼
        me->delete("worker");                 //������Ʒ��¼
        me->delete("xlz");                 //�����ƿ����л�
        me->delete("spec");                  //ɾ��ͨ����Ʒʹ�ü�¼
        me->delete("class");                  //���ұ��ɾ��
        me->delete("divorce");                //ɾ��������
        me->delete("marry");                  //ɾ��������
        me->delete("jiuyang");
        me->delete("job_last_gift");
//by spiderii@ty Ϊsl�ر�����
        me->delete("pass_xin");
        me->delete("passdu");

        me->delete("job_name");
        me->set("job_time/����",100);         //����score��ͨ����bug
       //by spdierii@ty ������������Ҳȫ������
        me->set("pur", 15 + random(15));
        me->set("per", 15 + random(15));
	 me->set("kar", 15 + random(15));

        skill = me->query_skills();
        skl = keys(skill);
        i = sizeof(skl);
           while (i--) 
              {
                   me->delete_skill(skl[i]);              
                 }
        
        if (me->is_ghost()) me->reincarnate();
        me->reset_action(); 
        
     //by spiderii@ty ��ϣ��������������츳���ܵ�������ϣ�����˶�һ����
     //Update by lsxk@hsbbs �޸�Ϊ��20M���4-6���츳��30M���7-10���츳��40M���12-15���츳��50M���17-20���츳
     //Update by lsxk@hsbbs �о��츳���е��٣��ʵ�����㡣   2008/3/18
      if((int)me->query("relife/combat_exp",1)> 50000000){
          me->set("relife/exp_ext",20);
          j = 30;
      }
      else if((int)me->query("relife/combat_exp",1)> 40000000){
          me->set("relife/exp_ext",15);
          j = 20 + random(6);
      }
      else if((int)me->query("relife/combat_exp",1)> 30000000){
          me->set("relife/exp_ext",10);
          j = 12 + random(6);
      }
      else{
          me->set("relife/exp_ext",5);
          j = 6 + random(5);
      }
      me->add("relife/gift/now",j);
      me->add("relife/gift/total",j);
      tell_object(me, CYN"����ת�����޵�ͬʱ�����"+ HIR + chinese_number(j) + CYN +"�㡸"+HIG+"�츳����"+CYN+"����\n"NOR);

}

void jieti_msg(object me, int stage, string place)
{
        string msg;

        if (stage == 5) me->revive();

        msg = HIR + jieti_msg[stage] + NOR;
        tell_object(me, HIY + msg + NOR);
        if (stage < sizeof(jieti_msg) - 1)
        {
                if (stage == 4) me->unconcious();

                stage++;
                call_out("jieti_msg", 1, me, stage, place);
        } else
        {
                jieti_player(me);
                CHANNEL_D->do_channel(this_object(), "rumor", HIC"��˵" + me->name(1) +
                                     "��̩ɽ֮�߳ɹ���ħ����,ת�������ˣ�\n"NOR);
                me->set("relife/zhuanshi",1);//Ҫskills�ı��
                log_file("quest/zhuanshi", sprintf(HIG"%s(%s) �ڶ���̩ɽ֮�߳ɹ�ת�����ޡ�����츳���ܵ�����%d��\n"NOR, me->name(1),me->query("id"), me->query("relife/gift/now")) );

        }      
        return;
}
