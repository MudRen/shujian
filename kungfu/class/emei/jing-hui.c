// /kungfu/class/emei/jing-hui.c
// Update by Lklv 2001.10.18

#include "nigu.h"
#include "xue_dacheng.h"
int ask_force();
int ask_fofa();
int ask_linji();
inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("����ʦ̫", ({"jinghui shitai", "jinghui", "shitai"}));
	set("long",
		"����һλ���������ʦ̫����ǵ����ϴ��źͰ���΢Ц��\n"
	);

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("unique", 1);
	set("class", "bonze");

	set("age", 35);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 35);
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 100);

	set("inquiry",([
          "����" : (: ask_force :),
          "��˷�" : (: ask_fofa :),
          "�ټ�ʮ��ׯ" : (: ask_linji :),
          "���"  : (: ask_for_join :),
          "����"  : (: ask_for_join :),
         ]) );

	set_skill("dacheng-fofa", 120);
	set_skill("linji-zhuang", 120);
	set_skill("yanxing-daofa", 120);
	set_skill("literate", 120);
	set_skill("blade", 120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("force", 120);
	set_skill("anying-fuxiang", 120);

	map_skill("force", "linji-zhuang");
	map_skill("blade", "yanxing-daofa");
	map_skill("parry", "yanxing-daofa");
	map_skill("dodge", "anying-fuxiang");


	create_family("������", 4, "����");

	setup();
	carry_object("/d/emei/obj/blade")->wield();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();
}
