// wuchou-4.c �ĳ�
// by iceland

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�ĳ�", ({"si chou","sichou","chou","si"}));
	set("long",
"���ǲر�����е����ģ����򲻸ߣ��������˲��١�\n"
"���Ǵ����´���͵ĵ��ӡ�\n"
	);

        set("title", HIY "�����µ�ʮ�Ĵ�����" NOR);
	set("gender", "����");
	set("attitude", "heroism");
	set("class", "huanxi");

	set("age", 26);
	set("shen_type", -1);
	set("str", 20);
	set("int", 15);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 300);
	set("eff_jing", 200);
	set("max_jing",200);
	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 10);
	set("combat_exp", 10500);
	set("score", 5000);
	set("unique", 1);

	set_skill("force", 25);
	set_skill("longxiang-boruo", 25);
	set_skill("dodge", 25);
	set_skill("yuxue-dunxing", 25);
	set_skill("staff", 25);
	set_skill("wushang-dali", 25);
	set_skill("parry", 25);
	set_skill("huanxi-chan", 25);
	set_skill("literate", 20);

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("staff", "wushang-dali");
	map_skill("parry", "wushang-dali");

	create_family("������", 14, "����");
        set("chat_msg", ({
"�ĳ�����е�������ͷûʲô�����ˣ�ȥɽ��·������Ʊ�ɡ���\n",
        }) );

	setup();

        carry_object(ARMOR_D("pijia"))->wear();
        carry_object(BINGQI_D("jingangzuan"))->wield();

        add_money("silver",10); 
}