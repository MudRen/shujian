// gaibang_npc.c, recruiting gb_dizi and promoting system

#include <ansi.h>

mixed names = ({
        ({
        "����", "����", "�е���","Ů����","����ˮ","����","����������",
        "����ͷ", "������", "����", "�ɻ���","���ǿ�","�����ɵ���",
        }),
        ({
         "����ɮ��","��ҩ����", "������ʦ","��Ʒ��ʦ","������ʦ","������ʦ",
         "��һ��ʦ","������","������","�Ų���","����ţ","�������","ׯ�","�⾢��",
         "������ʦ","����","�ɻ���","������ʿ","������","������ʿ","���","��ԫ",
         "�ƹ���","��Сɽ","����ɽ","����ɽ","�տն�","������",
         "��³��","����",
        }),
        ({
         "���Ŵ��","�ۺ�����","�۹�����","�۽�����","��ɫ����","�ױ�","������",
         "�ۿ�����","��������","��������","��Ȼ","��Ұ��","������","����",
         "������ʿ","���´��","������","�ױ��ӳ�","���д���","���۽���",
         "��������", "�ܵ�","˵����","��Ө��","����", "��ǫ","ʨ����", "������",
         "��ͨ��","ɳͨ��","�ɻ���","Ǯ�ཡ","��ͬ","������","ʷ����","ʷ�Ͻ�","ʷ��ǿ",
         "ʷ����","����ϼ","������","������","������",
         }),
        ({
          "����ͬ","�粨��","�˰ٴ�","�ι�","�κ�","����ʦ̫","����ʦ̫",
          "��һ��","�����","������","��Ȼ��","����ʦ̫","����ʦ̫","����ʦ̫",
          "����ʦ̫", "����ʦ̫","����ʦ̫","����ʦ̫","����ʦ̫","����ʦ̫",
          "����ʦ̫",
           "�μ�","�μ�","�ξ�","����","����","����","����","��ʶ","��˼","����",
          "����","����","����","����","��֪","��־","ժ����","ʷ���","������",
         }),
        ({
          "����ͤ","Ī����","����Ϫ","�����",
          "���Ѵ�ʦ","�����ʦ","������ʦ","���ȴ�ʦ","������ʦ","������","��Զ��","����Ϫ","�����",
          "�Ծ�ү","������","ΤһЦ","лѷ","����","��ң","Ľ�ݸ�","���˿","������","��Ī��",
        }),
     });

void kill_ob(object me)
{
      command("hehe");
      me->remove_killer(this_object());
 //       remove_killer(me);

}
string ask_job()
{
  object applicant, me;
  int exp,position;
  string target;
   applicant=this_player();
   me=this_object();
   if(!applicant->query("gb_pass"))
   return "��û��ͨ���������ӵĿ��飬�ҿɲ������㡣";
    exp=(int)applicant->query("combat_exp",1);
    if(exp>1500000)
      return "�������ո�ǿ�����¿ɲ����ͷ����ϡ�";
     if (interactive(applicant) && applicant->query_temp("promotion_target")
                && (int)applicant->query_condition("gb_mission"))
       return "����ȥɱ"+applicant->query_temp("promotion_target")+"������ȥ��";
     if (interactive(applicant) && !applicant->query_temp("promotion_target")
                && (int)applicant->query_condition("gb_mission"))
       return "�����������û��ɣ��ȵȻ�ɡ�";
    if (interactive(applicant)&&
       (int)applicant->query_condition("xx_task"))
   {
       // command("chat "+ applicant->name(1)+"͵͵Ϊ������Ч�������ڰ��������ؤ�");
     //   command("chat"+ applicant->name(1)+"������ְ��࣬���˵ö���֮!!!\n");
        applicant->delete("gb_job");
       tell_object(applicant,HIW"��Ӵ˲�����ؤ������ˡ�\n"NOR);
       return "�쵰������͵͵Ϊ���Ϲ�Ч������������\n";
      }
    if (interactive(applicant) &&
        (int)applicant->query_condition("gb_busy"))
         return "�����ҿ�û�и�������񣬵Ȼ������ɡ�\n";
    if(exp>=640000)
         position=5;
     else if(exp>=300000)
         position=4;
     else if(exp>=100000)
          position=3;
     else if(exp>=50000)
          position=2;
     else
          position=1;

        target = names[position-1][random(sizeof(names[position-1]))];
        applicant->set_temp("promotion_target", target);
        applicant->set_temp("assigned_by", me->query("name"));
        applicant->apply_condition("gb_mission",40);
    //   applicant->apply_condition("gb_busy",10);
        return "�ðɣ���ȥ��" + target +"�⹷����ɱ�ˣ�������ͷ�����ң�";
}

int accept_object(object who, object ob,object me)
{

// check if accept corpse from player

        if ( !who->query("gb_pass"))
              return 0;
        if ( ob->query("id") != "corpse" ) {
                command("say �ⶫ����Ҫ��û�á�");
                return 0;
        }
        if ( !who->query_temp("promotion_target") ) {
                command("say �ð��������������������");
                return 0;
        }

        if ( ob->query("victim_name")
        != who->query_temp("promotion_target") ) {
                command("say �ٺ١���������ɱ�����ˡ�");
                return 0;
        }
     if ( ob->query("victim_user") ) {         // is it player's corpse?
                command("say " + RANK_D->query_rude(who) +
                        "����Ȼ����ƭ�����ϣ��������ѣ�");
                call_out("killing_object",1,who);
                return 0;
        }
        if ( ob->query("kill_by") != who) {
                command("say ��������ƺ��������Լ���ɵİɣ�");
                command("chat "+ who->name(1) +"���ף����˵��ô�죿");
                return 0;
        }
        if (interactive(who) &&
                (int)who->query_condition("xx_task")){
            command("chat"+ who->name(1)+"͵͵Ϊ������Ч�������ڰ��������ؤ�\n");
            command("chat"+ who->name(1)+"������ְ��࣬���˵ö���֮!!!\n");
            who->delete("gb_pass");
            who->delete("gb_job");
             return 1;
         }
        call_out("destroying", 1, ob);
        call_out("ok", 1, who);
        return 1;
}

void ok(object who)
{
        int exp,pot,job_time;
        if (!who) return;
        job_time=(int)who->query("gb_job",1);
        command("thumb " + who->query("id"));
        command("say ��Ϊؤ�������˹��ͣ����Ǿ����������ġ�");

        if ((int)who->query("combat_exp")<300000){
                pot=10+random(who->query("max_pot")/4);
                exp=((1+random(3))*90+(int)(job_time/5));
                who->add("potential",pot);
                if (who->query("potential") > who->query("max_pot"))
                        who->set("potential", who->query("max_pot"));
                who->add("combat_exp",exp);
                who->add("gb_job",1);
                who->add("shen",exp*10);
                who->delete_temp("assigned_by");
                who->delete_temp("promotion_target");
                    who->clear_condition("gb_mission");
       tell_object(who,HIW"�㱻�����ˣ�\n" +
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       chinese_number(exp/2)+"������\n"+
                       "��Ϊؤ������"+job_time+"�ι�����\n"
                       NOR);
                return;
       }
            exp=(1+random(4))*105+(int)(job_time/5);
          pot=10+random(who->query("max_pot")/5*2);
         who->add("potential",pot);
         if (who->query("potential") > who->query("max_pot"))
             who->set("potential", who->query("max_pot"));
        who->add("combat_exp",exp);
        who->add("gb_job",2);
        who->add("shen",exp/2);
        who->delete_temp("assigned_by");
        who->delete_temp("promotion_target");
        who->clear_condition("gb_mission");
         tell_object(who,HIW"�㱻�����ˣ�\n" +
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                        chinese_number(exp/2)+"������\n"+
                      "��Ϊؤ�������"+job_time+"�ι�����\n"
            NOR);
}
void gb_apprentice(object ob)
{
        string prev_family_name;

        if ( (int)ob->query("gb_bags") >= 2
       && (prev_family_name = ob->query("family/family_name")) != "ؤ��" ) {
                command("say ؤ����ݲ��������ֱ��������С�ˣ�");
                return;
        }
        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
        command("recruit " + ob->query("id"));
        if ( prev_family_name != "ؤ��")
                ob->set("gb_bags", 1);
        ob->set("title",sprintf("ؤ��%s������",
                chinese_number(ob->query("gb_bags"))) );
}
void killing_object(object who)
{
        object me = this_object();
        me->kill_ob(who);
        who->unconcious();
}

void destroying(object obj)
{
        destruct(obj);
        return;
}
