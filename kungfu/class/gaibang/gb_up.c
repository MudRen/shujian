// gb_up.c, ؤ������ system
// Newcode by looklove 2000/8/25

#include <ansi.h>

// obj list 
mixed names = ({
        ({
        "���¾�", "ɳ��", "�ۺ����","ţƤ�ƴ�","����","ָ��","��","����",
        }),
        ({
        "��վ�","����ȭ��","̫��ʮ����","��Ƥ","���ᱸ����","����Ƥ","���",
        }),
        ({
        "�鲼��","������","Χ��","����Ƥ","��Կ��","��¨","�廨��",
        }),
        ({
        "���޺�","������Ҫ","ͼ��","����ɢ","����������","Ԣ���",
        }),
       	({
        "�ڹ��ķ�","ϴ�辭","ǧ��ѩ��","����","���޶���","Ħڭɮڮ��",
      	}),
});

string ask_me()
{
        object ob, me;
        int bg_lvl,bags,exp,htlvl;
        string target;

        me = this_player();
        ob = this_object();
	bags = (int)me->query("gb_bags");  // Ŀǰ����
	bg_lvl = (int)me->query_skill("begging",1); //�л������
	exp=(int)me->query("combat_exp",1); // ��ǰexp
	htlvl=(int)me->query_skill("huntian-qigong",1); //������������

        if ( me->query("family/family_name") != "ؤ��" )
                return RANK_D->query_respect(me)+"���Ǳ�����ӣ����д��ʣ� \n";
        
        if ( me->query_temp("sd_target"))
                return RANK_D->query_respect(me)+"�Ҳ�������ȥ��"+me->query_temp("sd_target")+"���𣿿�ȥ�ɡ�\n";
        
        if ( bg_lvl < 30 ) 
                return RANK_D->query_respect(me)+"�ڰ���������ǳ������������\n";
        
        if ( bg_lvl < 60 && bags == 2 )
                return RANK_D->query_respect(me)+"Ҫ�����ͣ�\n";
        
        if ( bg_lvl < 80 &&  bags == 3 )
                return RANK_D->query_respect(me)+"Ҫ���Ŭ�������ڰ��г���ͷ�ء�\n";
        
        if ( bg_lvl < 100 && bags == 4 )
                return RANK_D->query_respect(me)+"���ǲ���������\n";
           
        if (((exp<150000)||(htlvl<80))&&(bags==5))
            	return RANK_D->query_respect(me)+"�����书�����Ƿ���ں����ˣ�\n";
        
        if (bags>5)
        	return RANK_D->query_respect(me)+"�Ѿ���ѹȺ���ˣ��Һ����ȥ�ɡ�\n";

        if(me->set_temp("sd_target"))
          	return "������ȥ��\n";
	
	// the following will random choose a target and assign to this player        
        target = names[bags-1][random(sizeof(names[bags-1]))];
        me->set_temp("sd_target", target);
        me->set_temp("up_by", ob->query("name"));
        return "�ðɣ�����Ҫ�����������Ū��ɼ�������\n"+"��ȥ��" + target +"����������\n";
}

int promotion_checking(object who, object ob)
{
        object me = this_object();
        int bag,exp;
	
	// check if accept corpse from player
        if ( who->query("family/family_name") != "ؤ��" )
                return 0;
        if ( ob->query("name") != (string)who->query_temp("sd_target")) {
                command("say �ⶫ����Ҫ��û�á�");
                return 0;
        }
        if ( who->query_temp("up_by") != me->query("name")) {
                command("say �����ģ�����ȥ����������Ķ����ɡ�");
                return 0;
        }

	// all right, now it's time to check if the corpse is correct ;
	// there is still a bug here, since i can't check if corpse is 
	// obj's name or a player who has the same name as that obj, 
	// although it's illegal.
        
        if (userp(ob)) {
                command("say " + RANK_D->query_rude(who) + 
                        "����Ȼ����ƭ���������������ѣ�");
                //call_out("killing_object",1,who);
                return 0;
        }
        bag=(int)who->query("gb_bags",1);
        exp=(bag*bag*1000);
        who->add("gb_bags",1);  
        who->add("max_neili",10);
        who->set_skill("begging",(int)who->query_skill("begging",1) + 1);
        who->set_skill("stealing",(int)who->query_skill("stealing",1) + 1);
        who->add("combat_exp",exp);
	command("applaud " + who->query("id"));
        command("say �ɵúã��ӽ��쿪ʼ�������Ϊ" + 
                chinese_number(who->query("gb_bags")) +
                "�����ӣ��úøɣ�\n");
        who->set("title",sprintf("ؤ��%s%s������",
                who->query("gb/fenduo"),chinese_number(who->query("gb_bags"))) );
        who->delete_temp("up_by");
        who->delete_temp("sd_target");
        return 1;
}       
