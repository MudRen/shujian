// ren.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_bijian();

void create()
{
	set_name("������", ({ "ren woxing", "ren","woxing" }));
	set("nickname",HIR"ħ�̽���"NOR);
	set("long", "ֻ����һ�ų��������ף���ɫѩ�ף����ް��Ѫɫ��üĿ���㣬
������ߣ�һͷ�ڷ���������һϮ������\n");
	set("gender", "����");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("no_get", 1);
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 20000);
	set("max_jing", 10000);
	set("eff_jingli",10000);
	set("neili", 80000);
	set("max_neili", 40000);
 	set("jiali", 200);
	set("combat_exp",7000000);
	set("score", 500000);

	set_skill("literate", 200);         // ����ʶ��
	set_skill("force",400);            // �����ڹ�
	set_skill("strike",400);           // ����ָ��
	set_skill("dodge",400);            // ��������
	set_skill("parry",400);            // �����м�
	set_skill("dagger",400);           // �����̷�
	set_skill("sword",400);            // ��������
	set_skill("blade",400);
	set_skill("club",400);
	set_skill("poison",180);
	set_skill("hand",400);
	set_skill("piaomiao-shenfa",400);  // �����
	set_skill("huanmo-longtianwu",400);  // ��ħ������
	set_skill("qixian-wuxingjian",400);// �������ν�
	set_skill("xixing-dafa",400);      // �����ķ�
	set_skill("wudang-quan",400);        // ̫�泤ȭ
	set_skill("damo-jian",400);        // ��Ħ����
	set_skill("taiji-jian",400);       // ̫������
	set_skill("huifeng-jian",400);     // �ط������
	set_skill("taishan-jianfa",400);    // ̩ɽ����
	set_skill("hengshan-jianfa",400);    // ��ɽ����
	set_skill("hengshan-jianfa",400);   // ��ɽ����
	set_skill("huashan-jianfa",400);    // ��ɽ����
	set_skill("songshan-jian",400);   // ��ɽ����
	set_skill("tianmo-jian",400);
	set_skill("tianmo-zhang",400);
	set_skill("tianmo-shou",400);
	set_skill("tianmo-dao",400);
	set_skill("tianmo-gun",400);
	set_skill("tianmo-jue",200);
    set_skill("tianmo-gong",400);
	map_skill("force", "xixing-dafa");
	map_skill("sword", "qixian-wuxingjian");
	map_skill("strike", "huanmo-longtianwu");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("parry", "qixian-wuxingjian");
	prepare_skill("strike", "huanmo-longtianwu");
	set("quest/xixing/pass",1);
	set("chat_chance_combat", 80);
	  set("chat_msg_combat", ({
                (: perform_action, "sword.guangling" :),
                (: perform_action, "sword.music" :),
                (: exert_function, "xixing" :),
	}));

        set("inquiry", ([
                "�Ƚ�" :  (: ask_bijian :),
                "����" :  (: ask_bijian :),
                "��ľ��" : "Ҫ�ú�ľ��Ϸ����ȿ�����Ľ�����\n",
		"�������" : "���������������̣��͵����Ĵ��ó��ϡ�",
		"���"     : "���������������̣��͵����Ĵ��ó��ϡ�",
	]) );

	create_family("�������", 7, "����");
 	setup();
	carry_object("/clone/armor/changpao")->wear();
	carry_object("/clone/weapon/sword")->wield();
}

int ask_bijian()
{
	object weapon, me = this_player(), ob = this_object();

        if (!objectp(weapon = ob->query_temp("weapon")))
	{
		weapon = new("/clone/weapon/sword");
		weapon -> move(ob);
		command("wield sword");
	}
	if(!me->query_temp("quest/xxdf/start"))
	{
		message_vision("$N����˵���������������Ұݼ�����ǰ�����������ָ�̡���\n$n��Ц�����������Ĺ���ô���ҽ������ң�����\n", me, ob );
		return 1;
	}
	else {
	message_vision("$N����˵���������������Ұݼ�����ǰ�����������ָ�̡���\n$nЦ���������ÿ������������Ҽ�į���ɶ�л��������\n", me, ob );
	message_vision("$N���������ҡ���\n$n���˵�ͷ��˵��������ֻ��������Ľ�����������Ĺ��У���˵����Ҳδ����ʤ�����㡣��\n\n", me, ob);
  command("Ц�����������ӽ������µ�һ�����ұȽ���������\n");
	command("enable sword damo-jian");
	say(HIR"\n�����д��һ�����������ɴ�Ħ����"NOR"��"HIR"��Ħ������"NOR"������\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n��һ�С�\n");
	command("enable sword taiji-jian");
	say(HIR"\n�����д��һ�������䵱̫������"NOR"��"HIG"��������"NOR"������\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n�ڶ��С�\n");
	command("enable sword huifeng-jian");
	say(HIR"\n�����д��һ�����������ɻط������"NOR"��"HIW"��ԭ�ٻ�"NOR"������\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n�����С�\n");
	command("enable sword songshan-jianfa");
	say(HIR"\n�����д��һ��������ɽ����ɽ����"NOR"��"HIM"��������"NOR"������\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n�����С�\n");
	command("enable sword taishan-jianfa");
	say(HIR"\n�����д��һ������̩ɽ��̩ɽ����"NOR"��"HIY"������"NOR"������\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n�����С�\n");
	command("enable sword huashan-jianfa");
	say(HIR"\n�����д��һ��������ɽ�ɻ�ɽ����"NOR"��"MAG"�����������ɽ�"NOR"������\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n�����С�\n");
	command("enable sword hengshan-jianfa");
	say(HIR"\n�����д��һ��������ɽ�ɺ�ɽ����"NOR"��"CYN"��ɽ����ط�ʮ��ʽ"NOR"������\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n�����С�\n");
	command("enable sword hengshan-jianfa");
	
	say(HIR"\n�����д��һ��������ɽ�ɺ�ɽ����"NOR"��"WHT"�������"NOR"������\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
  say(HBMAG"\nͻȻ�����з���һ���޺���Ķ���һ�����飬һ����ע�⡣��������\n\n"NOR);
	say("\n������̾�˿�����˵����������û�����С���\n");
	me->set_temp("renwoxing/bijian", 1);
	me->set("qi",-1);
	me->delete_temp("quest/xxdf/start");
	me->set_temp("quest/xxdf/startlass",1);
		return 1;
	         }
          }
         }
        }
       }
      }
     }
   }
  }
	return 1;
}

void attempt_apprentice(object ob)
{
	              mapping fam;
if ((int)ob->query("quest/xxdf/pass",1) < 1 || !ob->query("buyvip") || ob->query("relife/gifts/total")<=3 || ob->query_skill("qixian-wuxingjian",1) <= 300 || ob->query("expell"))
	{
		command("say ���ǲ�������ͽ�ġ�");
		return;
	}
/*
                if (!(fam = this_player()->query("family")) || fam["family_name"] !="�������"){
             command("thank "+ (string)ob->query("id"));
             command("say ���뱾�������������Ҳ�������Ϊͽ�ģ�");
             return 0;
        }
*/
	if ((int)ob->query_skill("xixing-dafa",1) < 200)
	{
		command("say �����Ǵ��ϣ�" + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�ö��µ㹦��");
		return;
	}
{
			command("say �ðɣ���Ȼ�������ͶԵ���Ϸ���������ˡ�");
                        command("�Ϸ��յ������ͽ����������С����ı�Ӧ����!");
			command("recruit " + ob->query("id"));
			message_vision(
HIG"\n$N�������ŵ�����������������һ��Ӣ���˵ã��ο��������֮�к͸�
��ͬ�ֻࣿ�����������Ϊͽ�������Գ���ɽ���Ե�����������������
��������һ���Ƚ�������ĺ���ʤ�ţ������������ֻ��������գ����
��ض�ô����������ү�ӳ��ú��Σ������µ���Ů���ף���Ҫɱ��һ��
��ɱ��һ�������˸�����ү��Υ������ʹ��֮������\n"NOR, ob);
ob->set("title",HIR"������̡��������״�����"NOR);
  }
}


void die()


{

	object me = query_temp("last_damage_from");


		if(me->query_temp("quest/wuzhao/over")&&!me->query("quest/pass/dugu-jiujian/wuzhao")){
			
message_vision(MAG"\n$N�Դ�ѧ�á����¾Ž�����������δ���������ǿ�У��Է���������޷����޷������϶,�书֮ǿ���ѵ��˳���������˼��ľ��硣\n"NOR,me,this_object());
	message_vision(MAG"$Nһ��$n�ļ����������¾Ž��������ְ��΢֮�������ӵ����쾡��,�Զ��¾Ž��ľ�΢������Ȼ����\n\n",me,this_object());
	me->add_temp("quest/wuzhao/over",1);		
	//������1�������1������˭������������������+1��
			
			}




	::die();


}

void unconcious()
{
	die();
}
            
