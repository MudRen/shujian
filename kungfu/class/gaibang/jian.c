// NPC: jian.c ����
// Modify By Looklove 2000/10/18

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "begger.h";

void create()
{
	set_name("����", ({"jian zhanglao", "jian", "zhanglao"}));
	set("title", HIW"ؤ��Ŵ�����"NOR);
    	set("gb/bags",9);
	set("gender", "����");
    	set("age", 65);
	set("long", "����ؤ��������֮һ��\n");
	set("attitude", "peaceful");

	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 28);

	set("qi", 2800);
	set("max_qi", 2800);
	set("jing", 1600);
	set("max_jing", 1600);
	set("eff_jing", 2600);
	set("neili", 3800);
	set("max_neili", 3800);
	set("jiali", 30);

    	set("combat_exp", 550000);

	set_skill("force", 140); // �����ڹ�
	set_skill("huntian-qigong", 140); // ��������
	set_skill("hand", 140); // ����ȭ��
        set_skill("suohou-shou", 140);
	set_skill("dodge", 135); // ��������
        set_skill("xiaoyaoyou", 140); // ǧ������
	set_skill("parry", 140); // �����м�
        set_skill("stick", 100);
        set_skill("dagou-bang", 100);
	set_skill("begging", 100);

	map_skill("force", "huntian-qigong");
        map_skill("hand", "suohou-shou");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "suohou-shou");
	map_skill("stick", "dagou-bang");
	prepare_skill("hand", "suohou-shou");

	create_family("ؤ��", 18, "�Ŵ�����");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
	}));

	setup();
	carry_object(__DIR__"obj/gb_budai9")->wear();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
        carry_object(BINGQI_D("zhubang"))->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() <= 25	) {
		command("say �ҵĹ������ǿ��" +
		RANK_D->query_respect(ob) +
		"������̫�����ƺ����ʺϸ���ѧ�书��\n");
		return;
	}

        if (ob->query("family/family_name")
        && ob->query("family/family_name") != "ؤ��") {
                command("say �㻹��ȥ������ɿ����ɡ�");
                return;
	}
        if ((int)ob->query("gb/bags") >= 2
        && ob->query("family/family_name") != "ؤ��" ) {
                command("say ؤ����ݲ��������ֱ��������С�ˣ�");
                command("kill "+ob->query("id"));
                return;
        }

	if( ob->query_skill("huntian-qigong", 1) < 50){
		command("say "+RANK_D->query_respect(ob) +"�Ļ��������ǲ��ǻ�������");
		return;
	}
        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
        if (!ob->query("gb/bags")) ob->set("gb/bags", 1);
        command("recruit " + ob->query("id"));
        ob->set("title",sprintf("ؤ����ʷֶ�%s������",
                chinese_number(ob->query("gb/bags"))));
        ob->set("class","beggar");
}
