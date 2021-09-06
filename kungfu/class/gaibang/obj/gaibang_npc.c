// gaibang_npc.c, recruiting gb_dizi and promoting system
// Modify by looklove 2000/8/25
#include <ansi.h>

// npc list for gb 1-3 dai promotion
mixed names = ({
        ({
        "���¾�", "ɳ��", "�ۺ����","ţƤ�ƴ�","����","ָ��","��","����",
        }),
        ({
        "��վ�","����ȭ��","̫��ʮ����","��Ƥ","���ᱸ����","��Ƥ","���",
        }),
        ({
        "�鲼��","������","Χ��","����Ƥ","��Կ��","��¨","�廨��",
        }),
        ({
        "���޺�","������Ҫ","ͼ��","����ɢ","����������","Ԣ���",
        }),
       ({
        "�ڹ��ķ�","ϴ�辭","ǧ��ѩ��","����","���޶���","����",
      }),
});

void killing_object(object who);

string ask_me()
{
        mapping fam, my_fam;
        object applicant, me;
        int begging_level,position,exp,htlvl;
        string target;

        applicant = this_player();
        me = this_object();
        my_fam  = me->query("family");

// check if this player is gb dizi and meet the requirements for promotion
        if ( !mapp(fam = applicant->query("family"))
        || fam["family_name"] != "ؤ��" )
                return RANK_D->query_respect(applicant) +
                "���Ǳ�����ӣ����д��ʣ� \n";
        position = (int)applicant->query("gb/bags");          // num of bags
        if ( applicant->query_temp("sd_find_target") )
                return RANK_D->query_respect(applicant) +
                "��ȥ���������񣬺�����������\n";
        begging_level = (int)applicant->query_skill("begging",1);
        if ( begging_level < 30 )
                return RANK_D->query_respect(applicant) +
              "�ڰ���������ǳ������������\n";
        if ( ( begging_level < 60 ) && ( position == 2 ) )
                return RANK_D->query_respect(applicant) +
                "Ҫ�����ͣ�\n";
        if ( ( begging_level < 80 ) && ( position == 3 ) )
                return RANK_D->query_respect(applicant) +
                "Ҫ���Ŭ�������ڰ��г���ͷ�ء�\n";
        if (( begging_level<100 )&&(position==4))
                return RANK_D->query_respect(applicant) +
                "���ǲ���������\n";
           exp=(int)applicant->query("combat_exp",1);
           htlvl=(int)applicant->query_skill("huntian-qigong",1);
            if (((exp<150000)||(htlvl<80))&&(position==5))
            return RANK_D->query_respect(applicant) +
                "�����书�����Ƿ���ں����ˣ�\n";
        if (position>5)
         return RANK_D->query_respect(applicant)+"�Ѿ���ѹȺ���ˣ��Һ����ȥ�ɡ�\n";
// the following will random choose a target and assign to this player
        if(applicant->set_temp("sd_find_target"))
          return "������ȥ��\n";
        target = names[position-1][random(sizeof(names[position-1]))];
        applicant->set_temp("sd_find_target", target);
        applicant->set_temp("assigned_by", me->query("name"));
        return "�ðɣ�����Ҫ�����������Ū��ɼ�������\n" +
        "��ȥ��" + target +"����������\n";
}
int promotion_checking(object who, object ob)
{
        object me = this_object();
        int bag,exp;
// check if accept corpse from player
        if ( who->query("family/family_name") != "ؤ��" )
                return 0;
        if ( ob->query("name") != (string)who->query_temp("sd_find_target")) {
                command("say �ⶫ����Ҫ��û�á�");
                return 0;
        }
/*        if ( !who->query_temp("sd_find_target") ) {
                command("say �ð����������������������");
                return 0;
        }*/
        if ( who->query_temp("assigned_by") != me->query("name") ) {
                command("say �����ģ�����ȥ����������Ķ����ɡ�");
                return 0;
        }

// all right, now it's time to check if the corpse is correct ;
// there is still a bug here, since i can't check if corpse is
// npc's corpse or a player who has the same name as that npc,
// although it's illegal.
/*      if ( ob->query("victim_name")
        != who->query_temp("sd_find_target") ) {
                command("say �ٺ١���������ɱ�����ˡ�");
                return 0;
        }*/
        if (userp(ob)) {
                command("say " + RANK_D->query_rude(who) +
                        "����Ȼ����ƭ���������������ѣ�");
                call_out("killing_object",1,who);
                return 0;
        }
        bag=(int)who->query("gb/bags",1);
        exp=(bag*bag*1000);
        who->add("gb/bags",1);
// benifits from ����, 10 maxneili + 1 begging,sttealing level
        who->add("max_neili",10);
        who->set_skill("begging",(int)who->query_skill("begging",1) + 1);
        who->set_skill("stealing",(int)who->query_skill("stealing",1) + 1);
        who->add("combat_exp",exp);
command("applaud " + who->query("id"));
        command("say �ɵúã��ӽ��쿪ʼ�������ؤ��" +
                chinese_number(who->query("gb/bags")) +
                "�����ӣ��úøɣ�\n");
        who->set("title",sprintf("ؤ��%s������",
                chinese_number(who->query("gb/bags"))) );
        who->delete_temp("assigned_by");
        who->delete_temp("sd_find_target");
        return 1;
}


void killing_object(object who)
{
        object me = this_object();
        me->kill_ob(who);
        who->unconcious();
}


void gb_apprentice(object ob)
{
        string prev_family_name;

        if ( (int)ob->query("gb/bags") >= 2
        && (prev_family_name = ob->query("family/family_name")) != "ؤ��" ) {
                command("say ؤ����ݲ��������ֱ��������С�ˣ�");
                return;
        }

        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
        command("recruit " + ob->query("id"));
        if ( prev_family_name != "ؤ��")
                ob->set("gb/bags", 1);
        ob->set("title",sprintf("ؤ��%s������",
                chinese_number(ob->query("gb/bags"))) );
}

