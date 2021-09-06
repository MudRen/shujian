// NPC: quan.c ȫ����
// Modify By Looklove 2000/10/18
// Lklv 2001.9.28 update for open ���Ƿֶ�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "begger.h";

void create()
{
	set_name("ȫ����", ({"quan guanqing", "quan" }));
	set("title", YEL"ؤ����Ƿֶ����"NOR);
	set("gb/bags",8);
	set("nickname", "ʮ�����");
	set("gender", "����");
	set("age", 35);
	set("long", "���ǰ˴��������ƹܴ��Ƿֶ棬Ϊ�����Ƕ�ı���书��ǿ��\n");
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 25);
	set("int", 35);
	set("con", 20);
	set("dex", 25);

	set("qi", 1300);
	set("max_qi", 1300);
	set("jing", 900);
	set("max_jing", 900);
	set("eff_jingli", 1100);
	set("neili", 1600);
	set("max_neili", 1600);
	set("jiali", 20);

	set("combat_exp", 600000);

	set_skill("force", 130); // �����ڹ�
	set_skill("huntian-qigong", 130); // ��������
	set_skill("strike", 130); // ����ȭ��
	set_skill("dodge", 130); // ��������
        set_skill("xiaoyaoyou", 120); // ǧ������
	set_skill("parry", 120); // �����м�
        set_skill("lianhua-zhang", 130);
        set_skill("blade", 140);
        set_skill("liuhe-daofa", 140);
        set_skill("begging", 140);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-daofa");
	map_skill("strike", "lianhua-zhang");
	map_skill("parry", "lianhua-zhang");
	prepare_skill("strike", "lianhua-zhang");

	create_family("ؤ��", 19, "�˴�����");
	set("chat_chance", 2);
        set("chat_msg", ({
		"ȫ�������һ��������ׯ��С�Ӳ�֪����ȥ�ˣ��ɵ�С���飬��ô���˻�û������\n",
		"ȫ���屳��˫��������ȥ���ƺ�����ʲô����ͷ��\n",
		"ȫ������������ض��Լ�˵�������滹������������һ�����⣡��\n",
	}) );

	set("inquiry", ([
		"ؤ��" : "����ؤ�������µ�һ��\n",
		"�Ƿ�" : "�ٺ٣���������Ƿ��ˡ�\n",
		"����ׯ" : "�ٺ١����ٺ١���\n",
		"С����" : "�ٺ٣�����׼�����ˡ������������ܡ���\n",
		"���" : "�ٺ١����ٺ١���\n",
		"������" : "�ٺ١����ٺ١���\n",
		"����" : "�ٺ١����ٺ١���\n",
		"����" : "�ٺ١����ҡ����ٺ١���\n",
		"rumors" : "��˵��������ɽ�����׶�����\n",
	]));
	setup();
	carry_object(__DIR__"obj/gb_budai8")->wear();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
        carry_object(BINGQI_D("blade"))->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_int() <=20	) {
		command("say Ҫ����ұ��빻����" +
		RANK_D->query_respect(ob) +
		"������̫�ͣ��ҿɲ���Ҫ��������\n");
		return;
	}
        if ((int)ob->query("gb/bags") >= 2
        && ob->query("family/family_name") != "ؤ��" ) {
                command("say ���������㣬�����ǰ������ϡ�");
                return;
        }
        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
        command("recruit " + ob->query("id"));

	if (!ob->query("gb/bags")) ob->set("gb/bags", 1);
        ob->set("title",sprintf("ؤ����Ƿֶ�%s������",
                chinese_number(ob->query("gb/bags"))) );
        ob->set("gb/fenduo","���Ƿֶ�");
	ob->set("class","beggar");
}
