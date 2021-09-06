// wufu.c ���޸�
// Modify By River@sj 99.06
inherit NPC;
inherit F_MASTER;
string ask_xunluo();
void create()
{
        set_name("���޸�", ({ "yin wufu", "yin", "wufu" }));
        set("title","������ӥ�ֶ�����");
        set("age", 45);
	set("long","������ҵ����ˡ�\n");
	set("str", 23);
        set("int", 20);
        set("con", 23);
        set("dex", 23);
        set("per", 10);
        set("unique", 1);
        set("combat_exp", 350000);
        set("attitude", "peaceful");
        set_skill("dodge", 90);
        set_skill("blade", 90);
        set_skill("force", 90);
        set_skill("piaoyi-shenfa", 90);
        set_skill("shenghuo-shengong", 90);
        set_skill("yingzhua-shou", 90);
        set_skill("lieyan-dao", 90);
        set_skill("hand", 90);
        set_skill("parry", 90);
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("hand", "yingzhua-shou");
        map_skill("parry", "yingzhua-shou");
        map_skill("blade", "lieyan-dao");
        prepare_skill("hand","yingzhua-shou");
        set("inquiry", ([
                "��ӡ"  : (: ask_xunluo :),
        ]));
        set("xl", 9);
        set("xl2", "yinwufu");
        create_family("����", 38, "����");
        setup();
        carry_object("/d/mingjiao/obj/green-cloth")->wear();
}

void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping fam = ob->query("family");
        mapping my_fam = me->query("family");
        if (fam && (fam["family_name"] == "�䵱��" || fam["family_name"] == "������"
            || fam["family_name"] == "������" || fam["family_name"] == "ؤ��"
            || fam["family_name"] == "������" || fam["family_name"] == "��ɽ��")){
                command("say ���������������ɣ�����������ʲ��");
                return;
        }
        if(fam && fam["master_name"] == "���޼�"){
		command("haha");
		command("say "+RANK_D->query_respect(ob)+"���ǽ����״����ӣ�"+RANK_D->query_self(me)+"����������Ϊͽ��");
		return;
        }
	if (fam && fam["family_name"] == "����" && fam["generation"] <= my_fam["generation"]){
		command("shake");
		command("say "+RANK_D->query_respect(ob)+"������ʦ��"+RANK_D->query_respect(me)+"����������Ϊͽ��");
		return;
        }
        if ( ob->query("int") < 20 ){
		command("shake");
		command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
		return;
        }
        command("look " + ob->query("id"));
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title","������΢�ý���");
}

#include "xunluo.h";
