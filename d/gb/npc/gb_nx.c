// gaibang_npc.c, recruiting gb_dizi and promoting system
#include <ansi.h>

mapping *names = ({
        ({
                (["name":                   "����",
                "award_exp" :              80,
                   "award_pot" :                          10]), 
                   (["name":                "����",
                "award_exp" :              60,
                   "award_pot" :                          10]),
                   (["name":                "�е���",
                "award_exp" :              100,
                   "award_pot" :                          20]), 
                  (["name":                "Ů����",
                "award_exp" :              90,
                   "award_pot" :                          20]), 
                  (["name":                "����ˮ",
                "award_exp" :              80,
                   "award_pot" :                          20]), 
                    (["name":                "����",
                "award_exp" :              120,
                   "award_pot" :                          25]), 
                    (["name":                "�����ɵ���",
                "award_exp" :              80,
                   "award_pot" :                          10]), 
                     (["name":                "����������",
                "award_exp" :              60,
                   "award_pot" :                          20]), 
                    (["name":                "����",
                "award_exp" :              80,
                   "award_pot" :                          20]), 
                     (["name":                "���ǿ�",
                "award_exp" :              60,
                   "award_pot" :                          20]), 
                   (["name":                "������",
                "award_exp" :              100,
                   "award_pot" :                          20]), 
                    (["name":                "����ͷ",
                "award_exp" :              120,
                   "award_pot" :                          30]),  
                  (["name":                  "�ɻ���",
                "award_exp" :              120,
                   "award_pot" :                          30]),  
        }),
        ({
                   (["name":                  "��ҩ����",
                "award_exp" :              80,
                   "award_pot" :                          20]),  
                 (["name":                  "������",
                "award_exp" :              100,
                   "award_pot" :                          20]), 
                 (["name":                  "�տն�",
                "award_exp" :              100,
                   "award_pot" :                          25]), 
                 (["name":                  "������",
                "award_exp" :              100,
                   "award_pot" :                          25]), 
                 (["name":                  "������",
                "award_exp" :              120,
                   "award_pot" :                          30]), 
                 (["name":                  "����",
                "award_exp" :              100,
                   "award_pot" :                          30]), 
                 (["name":                  "������",
                "award_exp" :              120,
                   "award_pot" :                          30]), 
                 (["name":                  "�������",
                "award_exp" :              150,
                   "award_pot" :                          40]), 
                 (["name":                  "������ʿ",
                "award_exp" :              60,
                   "award_pot" :                          10]), 
                 (["name":                  "������ʿ",
                "award_exp" :              100,
                   "award_pot" :                          10]), 
                 (["name":                  "����ɽ",
                "award_exp" :              100,
                   "award_pot" :                          20]), 
                 (["name":                  "����ɽ",
                "award_exp" :              110,
                   "award_pot" :                          20]), 
                 (["name":                  "�⾢��",
                "award_exp" :              110,
                   "award_pot" :                          20]),  
                 (["name":                  "����ɮ��",
                "award_exp" :              80,
                   "award_pot" :                          15]), 
                 (["name":                  "�⾢��",
                "award_exp" :              110,
                   "award_pot" :                          20]), 
                 (["name":                  "����",
                "award_exp" :              120,
                 "award_pot" :                          30]), 
                 (["name":                  "������ʦ",
                "award_exp" :              90,
                   "award_pot" :                          20]), 
                 (["name":                  "���",
                "award_exp" :              80,
                   "award_pot" :                          30]), 
                 (["name":                  "�ƹ���",
                "award_exp" :              120,
                   "award_pot" :                          15]), 
                 (["name":                  "��������",
                "award_exp" :              160,
                   "award_pot" :                          20]), 
                  }),
             ({
                 (["name":                  "������",
                "award_exp" :              150,
                   "award_pot" :                          30]), 
                 (["name":                  "�ױ�",
                "award_exp" :              120,
                   "award_pot" :                          20]), 
                 (["name":                  "���۽���",
                "award_exp" :              150,
                   "award_pot" :                          30]), 
                 (["name":                  "������",
                "award_exp" :              120,
                   "award_pot" :                          10]), 
                 (["name":                  "�ױ��ӳ�",
                "award_exp" :              150,
                   "award_pot" :                          10]), 
                 (["name":                  "��Ұ��",
                "award_exp" :              180,
                   "award_pot" :                          30]), 
                 (["name":                  "���������",
                "award_exp" :              260,
                   "award_pot" :                          50]), 
                 (["name":                  "�ɻ���",
                "award_exp" :              150,
                   "award_pot" :                          20]), 
                 (["name":                  "������",
                "award_exp" :              120,
                   "award_pot" :                          20]), 
                 (["name":                  "ɳͨ��",
                "award_exp" :              160,
                   "award_pot" :                          30]), 
                  (["name":                  "��ͨ��",
                "award_exp" :              120,
                   "award_pot" :                          30]), 
                  (["name":                  "���д���",
                "award_exp" :              100,
                   "award_pot" :                          20]), 
                 (["name":                  "Ǯ�ཡ",
                "award_exp" :              120,
                   "award_pot" :                          20]), 
                 (["name":                  "��ǫ",
                "award_exp" :              150,
                   "award_pot" :                          30]), 
                 (["name":                  "���Ŵ��",
                "award_exp" :              100,
                   "award_pot" :                          20]), 
                 (["name":                  "˵����",
                "award_exp" :              150,
                   "award_pot" :                          30]), 
                 (["name":                  "������",
                "award_exp" :              180,
                   "award_pot" :                          40]), 
                 (["name":                  "��Ө��",
                "award_exp" :              120,
                   "award_pot" :                          25]), 
                 (["name":                  "�ܵ�",
                "award_exp" :              100,
                   "award_pot" :                          25]), 
                 (["name":                  "ʷ��ǿ",
                "award_exp" :              120,
                   "award_pot" :                          25]), 
                 (["name":                  "ʷ����",
                "award_exp" :              120,
                   "award_pot" :                          23]), 
                 (["name":                  "������",
                "award_exp" :              150,
                   "award_pot"   :                         40]), 
                 (["name":                  "������",
                "award_exp" :              150,
                   "award_pot"   :                         20]), 
                 (["name":                  "������",
                "award_exp" :              150,
                   "award_pot"   :                         20]), 
                 (["name":                  "ʷ����",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                  "ʷ�Ͻ�",
                "award_exp" :              80,
                   "award_pot"   :                         40]), 
                 (["name":                  "��������",
                "award_exp" :              80,
                   "award_pot"   :                         40]), 
                 (["name":                  "���Ǵ�����",
                "award_exp" :              140,
                   "award_pot"   :                         40]), 
 
         }),
        ({
                  (["name":                  "ժ����",
                "award_exp" :              200,
                   "award_pot"   :                         90]), 
                  (["name":                  "�༪������",
                "award_exp" :              200,
                   "award_pot"   :                         90]), 
                 (["name":                  "��Ȼ��",
                "award_exp" :              160,
                   "award_pot"   :                         40]), 
                (["name":                  "ʤ������",
                "award_exp" :              160,
                   "award_pot"   :                         40]),
                 (["name":                  "������",
                "award_exp" :              200,
                   "award_pot"   :                         90]), 
                 (["name":                  "����ʦ̫",
                "award_exp" :              150,
                   "award_pot"   :                         20]), 
                 (["name":                  "����ʦ̫",
                "award_exp" :              180,
                   "award_pot"   :                         60]), 
                 (["name":                  "����ʦ̫",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                  "����ʦ̫",
                "award_exp" :              100,
                   "award_pot"   :                         50]), 
                 (["name":                  "����ʦ̫",
                "award_exp" :              180,
                   "award_pot"   :                         15]), 
                 (["name":                  "����ͬ",
                "award_exp" :              190,
                   "award_pot"   :                         80]), 
                 (["name":                  "�˰ٴ�",
                "award_exp" :              180,
                   "award_pot"   :                         50]), 
                 (["name":                  "�����",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                  "�粨��",
                "award_exp" :              120,
                   "award_pot"   :                         40]), 
                 (["name":                  "�·�ʩ",
                "award_exp" :              150,
                   "award_pot"   :                         40]), 
                 (["name":                  "�·���",
                "award_exp" :              150,
                   "award_pot"   :                         40]), 
                 (["name":                  "����ʦ̫",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                  "ʷ���",
                "award_exp" :              200,
                   "award_pot"   :                         120]), 
                 (["name":                  "����",
                "award_exp" :              120,
                   "award_pot"   :                         40]), 
                 (["name":                  "����",
                "award_exp" :              120,
                   "award_pot"   :                         35]), 
                 (["name":                  "��ʶ",
                "award_exp" :              160,
                   "award_pot"   :                         20]), 
                 (["name":                  "��˼",
                "award_exp" :              80,
                   "award_pot"   :                         40]), 
                 (["name":                  "����",
                "award_exp" :              110,
                   "award_pot"   :                         30]), 
                 (["name":                  "����",
                "award_exp" :              120,
                   "award_pot"   :                         40]), 
                 (["name":                  "����ʦ̫",
                "award_exp" :              100,
                   "award_pot"   :                         40]), 
                 (["name":                  "����ʦ̫",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                  "�μ�",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                   "���",
                "award_exp" :              180,
                   "award_pot"   :                         60]), 
                 (["name":                    "����",
                "award_exp" :              180,
                   "award_pot"   :                         50]), 
                 (["name":                    "����",
                "award_exp" :              180,
                   "award_pot"   :                         50]), 
                 (["name":                    "��֪",
                "award_exp" :              120,
                   "award_pot"   :                         30]), 
                 (["name":                    "��������",
                "award_exp" :              180,
                   "award_pot"   :                         80]), 
         }), 
        ({
                  (["name":                    "��������",
                "award_exp" :              100,
                   "award_pot"   :                         30]), 
                  (["name":                    "Ľ�ݸ�",
                "award_exp" :              160,
                   "award_pot"   :                         60]), 
                  (["name":                    "���ư�",
                "award_exp" :              200,
                   "award_pot"   :                         40]), 
                  (["name":                    "ɣ�������",
                "award_exp" :                         180,
                   "award_pot"   :                         60]), 
                  (["name":                    "���ƴ�����",
                "award_exp" :                         180,
                   "award_pot"   :                         50]), 
                  (["name":                    "�·���",
                "award_exp" :                        180,
                   "award_pot"   :                         50]), 
                  (["name":                    "�·���",
                "award_exp" :                        180,
                   "award_pot"   :                         50]), 
                  (["name":                    "��Ī��",
                "award_exp" :                       180,
                   "award_pot"   :                         50]), 
                  (["name":                    "���˿",
                "award_exp" :                       240,
                   "award_pot"   :                         80]), 
                  (["name":                    "������",
                "award_exp" :                      180,
                   "award_pot"   :                         50]), 
                  (["name":                    "Ѫ������",
                "award_exp" :                         260,
                   "award_pot"   :                         70]), 
                  (["name":                    "������ʦ",
                "award_exp" :                         180,
                   "award_pot"   :                         50]), 
                  (["name":                    "���ȴ�ʦ",
                "award_exp" :                       180,
                   "award_pot"   :                         50]), 
                  (["name":                    "������ʦ",
                "award_exp" :                       180,
                   "award_pot"   :                         50]), 
                  (["name":                    "лѷ",
                "award_exp" :                     270,
                   "award_pot"   :                         90]), 
                  (["name":                    "������",
                "award_exp" :              180,
                   "award_pot"   :                         40]), 
                  (["name":                    "����",
                "award_exp" :              180,
                   "award_pot"   :                         60]), 
                  (["name":                    "��ң",
                "award_exp" :              180,
                   "award_pot"   :                         60]), 
                  (["name":                    "ΤһЦ",
                "award_exp" :              180,
                   "award_pot"   :                         60]), 
                  (["name":                    "���Ѵ�ʦ",
                "award_exp" :              180,
                   "award_pot"   :                         60]), 
                  (["name":                    "���ʦ̫",
                "award_exp" :              180,
                   "award_pot"   :                         60]),  
                  (["name":                    "�����",
                "award_exp" :              200,
                   "award_pot"   :                         90]), 
            }), 
          ({
                  (["name":                    "������",
                "award_exp" :                       270,
                   "award_pot"   :                         100]), 
                  (["name":                    "����ʦ̫",
                "award_exp" :                        180,
                   "award_pot"   :                         60]), 
                  (["name":                       "������",
                "award_exp" :                        200,
                   "award_pot"   :                         80]), 
                  (["name":                    "Ľ�ݲ�",
                "award_exp" :                        180,
                   "award_pot"   :                         60]), 
                  (["name":                    "���ٳ���",
                "award_exp" :                         180,
                   "award_pot"   :                         80]), 
                  (["name":                    "�ɶ�",
                "award_exp" :                     180,
                   "award_pot"   :                         60]), 
                  (["name":                    "�ɽ�",
                "award_exp" :                    180,
                   "award_pot"   :                         60]), 
                  (["name":                    "����",
                "award_exp" :                     180,
                   "award_pot"   :                         60]), 
                  (["name":                    "����",
                "award_exp" :                    180,
                   "award_pot"   :                         50]), 
                  (["name":                    "���Ѵ�ʦ",
                "award_exp" :                     180,
                   "award_pot"   :                         40]), 
                  (["name":                    "���ȴ�ʦ",
                "award_exp" :                     180,
                   "award_pot"   :                         40]), 
 
           }), 
                   ({ 
                  (["name":                              "���ַ���",
                    "award_exp" :                                  180,
                  "award_pot"   :                         60]), 
                  (["name":                              "�Ħ��",
                    "award_exp" :                                  160,
                  "award_pot"   :                         60]), 
                  (["name":                              "����֮",
                    "award_exp" :                                  160,
                  "award_pot"   :                         50]), 
                  (["name":                              "������ɮ",
                    "award_exp" :                                  180,
                  "award_pot"   :                         60]), 
                  (["name":                              "���޼�",
                    "award_exp" :                                 180,
                  "award_pot"   :                         60]), 
                  (["name":                              "������",
                    "award_exp" :                                  260,
                  "award_pot"   :                         120]), 
                  (["name":                              "�����",
                    "award_exp" :                          200,
                  "award_pot"   :                         70]), 
                  (["name":                              "������",
                    "award_exp" :                                  320,
                  "award_pot"   :                         80]), 
                   (["name":                               "����",
                "award_exp" :                              180,
                   "award_pot"   :                         40]), 
                  (["name":                                      "�ɶ�",
                "award_exp" :                              180,
                   "award_pot"   :                         40]), 
                  (["name":                               "�ɽ�",
                "award_exp" :                              180,
                   "award_pot"   :                         40]), 
                   (["name":                               "����",
                "award_exp" :                              180,
                   "award_pot"   :                         40]), 
          }),
     });

void kill_ob(object me)
{     
      command("hehe");
      me->remove_killer(this_object());
}

string ask_job(string arg)
{
                    object applicant, me;
                    mapping target;
                                  int exp,position;

                    applicant = this_player();
                    me = this_object();
                                  
                   exp = (int)applicant->query("combat_exp",1);

                   if (!applicant->query("gb_pass"))
                    return "��û��ͨ���������ӵĿ��飬�ҿɲ������㡣"; 
                  if(exp>2000000)
                 return "�������ո�ǿ�����¿ɲ����ͷ����ϡ�";
                      if (interactive(applicant) && applicant->query_temp("promotion_target")
                && (int)applicant->query_condition("gb_mission"))  
                     return "����ȥɱ"+applicant->query_temp("promotion_target")+"������ȥ��";

                         if (interactive(applicant) && !applicant->query_temp("promotion_target")
                && (int)applicant->query_condition("gb_mission"))  
                     return "�̸���������㻹û�����ô���ܻ����ˣ�";   

           if (interactive(applicant) && applicant->query_temp("gb_job_exp") || applicant->query_temp("gb_job_pot")) 
                                      return "�������û��ɣ���ô���ܻ����ˡ�"; 

                    if (interactive(applicant)&&
                     (int)applicant->query_condition("xx_task"))
                  {
                  applicant->delete("gb_job");
                   tell_object(applicant,HIW"��Ӵ˲�����ؤ������ˡ�\n"NOR);
                    return "����͵͵Ϊ���Ϲ�Ч�����Ӵ����Ժ����ؤ����û��ϵ�ˣ�\n"; 
                    }
        if (interactive(applicant) &&
                (int)applicant->query_condition("guanfu_task"))
        return "���Ѿ�Ͷ���ٸ���ô���������������Ҫ�������ʲ�᣿\n";

    if (interactive(applicant) &&
        (int)applicant->query_condition("gb_busy"))  
         return "�����ҿ�û�и�������񣬵Ȼ������ɡ�\n";
       if (interactive(applicant) &&
             (int)applicant->query_condition("dali_songxi"))
            return "���Ѿ������������߾ͣ�����������Ѱʲô���ģ�\n";
    if(exp>=1100000)
         position=7;
     else if(exp>=850000)
          position=6;
     else if(exp>=640000)
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
        applicant->set_temp("promotion_target", target["name"]);
              applicant->set_temp("gb_job_exp", target["award_exp"]);
              applicant->set_temp("gb_job_pot", target["award_pot"]);
        applicant->set_temp("assigned_by", me->query("name"));  
        applicant->apply_condition("gb_mission",random(20)+30);
        return "�ðɣ������"+applicant->query_temp("promotion_target")+"��һֱ����ؤ�����ԣ���ǰȥ�跨�����˳�����";
}

int accept_object(object apper, object ob)
{
    //object me = this_object();
// check if accept corpse from player

        if ( !apper->query("gb_pass")) 
              return 0;
        if ( ob->query("id") != "corpse" ) {
                command("say �ⶫ����Ҫ��û�á�");
                return 0;
        }
        if ( !apper->query_temp("promotion_target") ) {
                command("say �ð��������������������");
                return 0;
        }

        if ( !apper->query_temp("gb_job_exp") ) {
                command("say �ð��������������������");
                return 0;
        }

        if ( !apper->query_temp("gb_job_pot") ) {
                command("say �ð��������������������");
                return 0;
        }

        if ( ob->query("victim_name") 
        != apper->query_temp("promotion_target") ) {
                command("say �ٺ١���������ɱ�����ˡ�");
                return 0;
        }
     if ( ob->query("victim_user") ) {         // is it player's corpse?
                command("say " + RANK_D->query_rude(apper) + 
                        "����Ȼ����ƭ�����ϣ��������ѣ�");
                call_out("killing_object",1,apper);
                return 0;
        }
        if ( ob->query("kill_by") != apper) {
                command("say ��������ƺ��������Լ���ɵİɣ�");
                command("chat "+ apper->name(1) +"���ף����˵��ô�죿");
                return 0;
        }
        if (interactive(apper) &&
                (int)apper->query_condition("xx_task")){
            command("chat "+ apper->name(1)+"͵͵Ϊ������Ч�������ڰ��������ؤ�\n");
            command("chat "+ apper->name(1)+"������ְ��࣬���˵ö���֮!!!\n");
            apper->delete("gb_pass");
            apper->delete("gb_job");
             return 1; 
         }

              
        apper->delete_temp("assigned_by");
        apper->delete_temp("promotion_target");
        apper->clear_condition("gb_mission");
        call_out("destroying", 1, ob);
        call_out("ok", 1, apper);
        return 1;
}

void ok(object apper)
{
        int job_time;
        if (!apper) return;
        command("thumb " + apper->query("id"));
        command("say ��Ϊؤ�������˹��ͣ����Ǿ����������ġ�");
 
              job_time=(int)apper->query("gb_job")/800;
                    if (job_time <1) job_time = 0;

            tell_room(environment(),
           		HIY "�ⳤ����"+ apper->name()
		+ "�Ķ��ߵ����ƺ��ڽ�����ʲ�ᣬһ���"+ apper->name() +"��ס��ͷ�����ϲɫ��\n"NOR, ({ apper }));
            write(HIY"�ⳤ�Ϸ��������������ָ������һЩ�书Ҫ�죬������һ�ὥ�����򣬸е��Լ���ѧ��Ϊ������ߡ�\n"NOR);
               apper->add("combat_exp", apper->query_temp("gb_job_exp"));
               apper->add("potential", apper->query_temp("gb_job_pot"));
                    apper->add("combat_exp",job_time);
             if(apper->query("potential") > apper->query("max_pot")) 
         apper->set("potential", apper->query("max_pot"));
           apper->add("gb_job",1); 
                   apper->delete_temp("gb_job_exp");
                   apper->delete_temp("gb_job_pot");
                  return;
 
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
string ask_fangqi()
{
            object me;
            int exp;

           me = this_player();
           exp = me->query("combat_exp",1);
           if(!me->query("gb_pass"))
           return "�����ؤ��Ӣ��,������Ϲ����ʲ��?";
           if(me->query_condition("gb_mission")<=1)
          return "��û��������,������Ϲ����ʲ��?";
          me->clear_condition("gb_mission");
          me->add("combat_exp",-10+random(15));
                if(exp>500000){
                   me->apply_condition("gb_busy",6+random(4));
         me->add("combat_exp",-30);
          me->add("gb_job",-2+random(2));
               }
            me->apply_condition("gb_busy",6+random(4));
                me->delete_temp("assigned_by");
           me->delete_temp("promotion_target");
                   me->delete_temp("gb_job_exp");
                   me->delete_temp("gb_job_pot");
          me->add("gb_job",-1);
        return "��Ȼ��ɲ���Ҳû��ϵ,��ȥ�̿�������,�Ժ�����Ϊؤ�����!";
}
void destroying(object obj)
{
        destruct(obj);
        return;
}
string ask_gonglao(object who)
{
            object me;
            int i;
             
                    me = this_player();

         i =(int)me->query("gb_job"); 

           if(!me->query("gb_job"))
           return "��ûΪ��ؤ������κ�����������ʲô������?"; 

               message_vision("$N�ͳ�һ�����ӷ��˷���ָ�������ī����$n˵���������湲�����������εĹ��ͣ�Ŀǰ�Ѽǹ�" + chinese_number(i) + "�Ρ�\n",who,me);
        return "��ؤ�������ͷ�����������Ŭ���ɣ����ֽ����Ͳ����뻳�С�";
}
