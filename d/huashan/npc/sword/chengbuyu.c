// NPC: /d/huashan/npc/cheng_by.c
// Date: Look 99/03/25
// Modify by Lklv 2001.10.18

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�ɲ���",({"cheng buyou", "cheng", "buyou" }));
        set("title","��ɽ�ɵ�ʮ�������ڴ����");
        set("nickname","������");
        set("long", "է����ȥֻ������һ��ƽ���İ��ӣ���Ŀ���׶���ˡ�\n");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("no_quest",1);

        set("max_qi",2500);
        set("qi", 2500);
        set("max_jing", 1400);
        set("jing",1400);
        set("eff_jingli", 1700);
        set("jingli", 1700);
        set("max_neili", 3500);
        set("neili", 3500);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("score", 30000);

        set_skill("cuff", 200);
        set_skill("zhengqi-jue",  200);
        set_skill("poyu-quan", 200);
        set_skill("sword",  200);
        set_skill("dodge",  200);
        set_skill("force",  200);
        set_skill("parry",  200);
        set_skill("huashan-qigong", 200);
        set_skill("huashan-jianfa",  200);
        set_skill("huashan-shenfa",  200);

        map_skill("dodge", "huashan-shenfa");
        map_skill("force","huashan-qigong");
        map_skill("sword","huashan-jianfa");
        map_skill("parry","huashan-jianfa");
        map_skill("strike","hunyuan-zhang");
        prepare_skill("cuff","poyu-quan");

        create_family("��ɽ��",13,"����");

        set("chat_chance_combat",40);
        set("chat_msg_combat", ({
		(: perform_action, "sword.feijian" :),
	}));
	setup();
	carry_object(BINGQI_D("sword/sword"))->wield();
	carry_object(ARMOR_D("armor/cloth"))->wear();
}
void attempt_apprentice(object ob)
{
        mapping fam;
        if (mapp(fam=ob->query("family")) && (string)fam["family_name"] != "��ɽ��"  && (int)ob->query("is/huashan")==1 ) {
                message_vision(CYN "$N���������ɽ�ɵ���ͽ��������ʲô ������\n"NOR, ob );
                command("slap "+ob->query("id"));
                return;
        }
                if(ob->query("quest/huashan")=="����"){
                command("heng");
                command("say �㲻�ǻ�ɽ���ڸ�ͽô����ô�������ǽ���������");
                return;
        }

 //       if (ob->query_skill("huashan-qigong",1) < 100 ) {
 //               command("say ��Ļ�ɽ������Ϊ̫�ץ�������ɡ�");
 //               return;
 //       }
        if ((int)ob->query("shen") <= 0) {
                command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob)+"�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ��Ҿ���������,���ҪΪ���ǻ�ɽ�ɽ�����������");
        command("recruit " + ob->query("id"));
        ob->set("title",HIW"��ɽ�ɽ����״�����"NOR);
        ob->set("quest/huashan","����");


}

/* void init()
{
        object me, ob;
        ::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob) && !environment(ob)->query("no_fight")){
		command("say �ҽ����ҽ��ڽ���,ֻ����������\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
*/